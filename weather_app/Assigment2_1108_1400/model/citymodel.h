#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QVariantMap>

#include "model/city.h"
#include "adapter/datasourceadapter.h"

class CityModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CityModel(QObject *parent = nullptr);

    enum CityEnum {
        NameRole,
        ConditionRole,
        WindRole,
        AtmosphereRole,
        AstronomyRole,
        SpeedRole,
        ChillRole,
        DirectionRole,
        HumidityRole,
        PressureRole,
        RisingRole,
        VisibilityRole,
        SunriseRole,
        SunsetRole
    };
    const DatasourceAdapter &adapter() const;
    void setAdapter(const DatasourceAdapter &newAdapter);
    void addItem(const City &city);

    Q_INVOKABLE QVariantMap get(int row) const;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex() ) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<City> m_citys;
    DatasourceAdapter m_adapter;


    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
};

#endif // CITYMODEL_H
