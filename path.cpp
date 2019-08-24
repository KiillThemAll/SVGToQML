#include "path.h"

Path::Path()
{
    startX = 0;
    startY = 0;
}

Path *Path::parse(QXmlStreamReader &xml)
{

    Path *p = new Path();

    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("d"))
        p->d = attributes.value("d").toString();
    if (attributes.hasAttribute("fill"))
        p->fill = attributes.value("fill").toString();
    if (attributes.hasAttribute("stroke"))
        p->stroke = attributes.value("stroke").toString();
    if (attributes.hasAttribute("stroke-linejoin"))
        p->strokeLineJoin = attributes.value("stroke-linejoin").toString();
    if (attributes.hasAttribute("transform")){
        QStringList nums;
        getNumberFromQString(attributes.value("transform").toString(), nums);
        p->startX = nums.at(0).toFloat();
        p->startY = nums.at(1).toFloat();
    }

    return p;
}

void Path::addItem(Path *p, QXmlStreamReader &xml)
{
    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("d"))
        p->d += attributes.value("d").toString();
}

void Path::setAttr(QString value, qint8 index)
{
    switch (index) {
    case 0:
        d = value;
        break;
    case 1:
        fill = value;
        break;
    case 2:
        stroke = value;
        break;
    case 3:
        strokeLineJoin = value;
        break;
    case 4:
        transform = value;
        break;
    default:
        break;
    }
}



