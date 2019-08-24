#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QXmlStreamReader>
#include <QList>

#include "pathmodel.h"

int main(int argc, char *argv[])
{
    QFile* file = new QFile("Solar.svg");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QXmlStreamReader xml(file);

    QList<Path> PathItems;

    float scaleX = 0, scaleY = 0;

    while (!xml.atEnd() && !xml.hasError())
        {
            if (xml.readNext() == QXmlStreamReader::StartElement)
            {
                if (xml.name() == "svg")
                {
                    QXmlStreamAttributes attributes = xml.attributes();
                    if (attributes.hasAttribute("viewBox")){
                        QStringList nums;
                        getNumberFromQString(attributes.value("viewBox").toString(), nums);
                        scaleX = nums.at(2).toFloat();
                        scaleY = nums.at(3).toFloat();
                    }
                }

                if (xml.name() == "g")
                {
                    QXmlStreamAttributes attributes = xml.attributes();
                    if (attributes.hasAttribute("id")){
                        QString id = attributes.value("id").toString();
                        xml.readNext();
                        Path *p = nullptr;
                        while(xml.name() != "g")
                        {
                            if (xml.name() == "path" && xml.tokenType() == QXmlStreamReader::StartElement)
                            {
                                if (p == nullptr)
                                {
                                    p = Path::parse(xml);
                                    p->id = id;
                                    p->scaleX = scaleX;
                                    p->scaleY = scaleY;
                                }
                                else Path::addItem(p, xml);
                            }
                            xml.readNext();
                        }
                        if (p != nullptr) PathItems.append(*p);
                    }
                }

            }
        }

    PathModel pModel(PathItems);


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("pathModel", &pModel);

    engine.load(url);

    return app.exec();
}
