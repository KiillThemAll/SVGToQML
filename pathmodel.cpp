#include "pathmodel.h"

PathModel::PathModel(QList<Path> &paths, QObject *parent) : QAbstractListModel(parent)
{
    m_paths = paths;
}

int PathModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_paths.size();
}

QVariant PathModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_paths.size() || index.row() < 0)
        return QVariant();

    Path temp = m_paths.at(index.row());

    if (role == d)
        return temp.d;
    if (role == fill)
        return temp.fill;
    if (role == stroke)
        return temp.stroke;
    if (role == strokeLineJoin)
        return temp.strokeLineJoin;
    if (role == transform)
        return temp.transform;
    if (role == scaleX)
        return temp.scaleX;
    if (role == scaleY)
        return temp.scaleY;


    return QVariant();
}

bool PathModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Path temp = m_paths[index.row()];

    if (index.isValid())
    {
        temp.setAttr(value.toString(),role - (Qt::UserRole + 1));

        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags PathModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}


QHash<int, QByteArray> PathModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[d] = "d";
    roles[fill] = "fill";
    roles[stroke] = "stroke";
    roles[strokeLineJoin] = "strokeLineJoin";
    roles[transform] = "transform";
    roles[scaleX] = "scaleX";
    roles[scaleY] = "scaleY";
    return roles;
}
