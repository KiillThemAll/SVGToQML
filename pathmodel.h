#ifndef PATHMODEL_H
#define PATHMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "path.h"

class PathModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum ParamRoles {
        d = Qt::UserRole + 1,
        fill,
        stroke,
        strokeLineJoin,
        transform,
        scaleX,
        scaleY
    };

    explicit PathModel(QList<Path> &paths, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Path> m_paths;
};

#endif // PATHMODEL_H
