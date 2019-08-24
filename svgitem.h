#ifndef SVGITEM_H
#define SVGITEM_H

#include <QStringList>
#include <QXmlStreamReader>
#include <QRegularExpression>

class SVGItem
{
public:
    virtual ~SVGItem() {}

    QString id;

    float startX;
    float startY;
    float scaleX;
    float scaleY;

    virtual void parse(QXmlStreamReader &xml) = 0;
    virtual void addItem(QXmlStreamReader &xml) = 0;

    virtual void setAttr(QString value, qint8 index) = 0;
};



#endif // SVGITEM_H
