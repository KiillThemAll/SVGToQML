#ifndef PATH_H
#define PATH_H

#include <QStringList>
#include <QXmlStreamReader>
#include <QRegularExpression>

#include "helpfunc.h"

class Path
{

public:
    Path();

    QString d;
    QString id;
    QString fill;
    QString stroke;
    QString strokeLineJoin;
    QString transform;

    float startX;
    float startY;
    float scaleX;
    float scaleY;

    static Path* parse(QXmlStreamReader &xml);
    static void addItem(Path* p, QXmlStreamReader &xml);

    void setAttr(QString value, qint8 index);



};

#endif // PATH_H
