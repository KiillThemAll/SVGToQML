#include "path.h"

void Path::parse(QXmlStreamReader &xml)
{
    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("d"))
        d = attributes.value("d").toString();
    if (attributes.hasAttribute("fill"))
        fill = attributes.value("fill").toString();
    if (attributes.hasAttribute("stroke"))
        stroke = attributes.value("stroke").toString();
    if (attributes.hasAttribute("stroke-linejoin"))
        strokeLineJoin = attributes.value("stroke-linejoin").toString();
    if (attributes.hasAttribute("transform")){
        QStringList nums;
        getNumberFromQString(attributes.value("transform").toString(), nums);
        startX = nums.at(0).toFloat();
        startY = nums.at(1).toFloat();
    }
}

void Path::addItem(QXmlStreamReader &xml)
{
    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("d"))
        d += attributes.value("d").toString();
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



