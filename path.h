#ifndef PATH_H
#define PATH_H

#include "svgitem.h"
#include "helpfunc.h"

class Path : public SVGItem
{

public:
    Path() {}

    QString d;
    QString fill;
    QString stroke;
    QString strokeLineJoin;
    QString transform;

    void parse(QXmlStreamReader &xml) override;
    void addItem(QXmlStreamReader &xml) override;

    void setAttr(QString value, qint8 index) override;
};

#endif // PATH_H
