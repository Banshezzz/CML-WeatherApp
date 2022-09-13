#include "citymodel.h"


CityModel::CityModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

void CityModel::addItem(const City &city)
{
    m_citys.append(city);
}

QVariantMap CityModel::get(int row) const
{
    QHash<int, QByteArray> names = roleNames();
    QHashIterator<int, QByteArray> i(names);
    QVariantMap res;
    QModelIndex idx = QAbstractListModel::index(row, 0);
    while(i.hasNext()) {
        i.next();
        QVariant data = idx.data(i.key());
        res[i.value()] = data;
    }
    qDebug() << res;
    return res;
}

int CityModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_citys.length();
}

QVariant CityModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    const City &item = m_citys[index.row()];

    switch(role){
    case NameRole:
        return item.name();
    case ConditionRole:
        return item.condition();
    case WindRole:
        return QVariant::fromValue<Wind>( item.wind() );
    case AtmosphereRole:
        return QVariant::fromValue<Atmosphere>( item.atmosphere() );
    case AstronomyRole:
        return QVariant::fromValue<Astronomy>( item.astronomy() );
    case SpeedRole:
        return item.speed();
    case ChillRole:
        return item.chill();
    case DirectionRole:
        return item.direction();
    case HumidityRole:
        return item.humidity();
    case PressureRole:
        return item.pressure();
    case RisingRole:
        return item.rising();
    case VisibilityRole:
        return item.visibility();
    case SunriseRole:
        return item.sunrise();
    case SunsetRole:
        return item.sunset();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> CityModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "countryName";
    roles[ConditionRole] = "condition";
    roles[WindRole] = "wind";
    roles[AtmosphereRole] = "atm";
    roles[AstronomyRole] = "astro";
    roles[SpeedRole] = "speed";
    roles[ChillRole] = "chill";
    roles[DirectionRole] = "direction";
    roles[HumidityRole] = "humidity";
    roles[PressureRole] = "pressure";
    roles[RisingRole] = "rising";
    roles[VisibilityRole] = "visibility";
    roles[SunriseRole] = "sunrise";
    roles[SunsetRole] = "sunset";


    return roles;
}

QModelIndex CityModel::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column, (void*)&m_citys[row])
                                         : QModelIndex();
}

const DatasourceAdapter &CityModel::adapter() const
{
    return m_adapter;
}

void CityModel::setAdapter(const DatasourceAdapter &newAdapter)
{
    m_adapter = newAdapter;
    beginResetModel();
    m_citys = newAdapter.citys();
    endResetModel();
}
