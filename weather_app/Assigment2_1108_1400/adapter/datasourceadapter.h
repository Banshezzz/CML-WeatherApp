#ifndef DATASOURCEADAPTER_H
#define DATASOURCEADAPTER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QDir>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>

#include "model/city.h"
#include "model/wind.h"
#include "model/atmosphere.h"
#include "model/astronomy.h"

class DatasourceAdapter
{
public:
    DatasourceAdapter();

    const QString &dataSource() const;
    void setDataSource(const QString &newDatasource);
    QByteArray initDataSource();
    void convertFromJson(const QByteArray &file);
    void convertFromSQLite();
    void convertFromFile(const QByteArray &file);

    const QList<City> &citys() const;

private:
    QString m_dataSource;
    QList<City> m_citys;
};

#endif // DATASOURCEADAPTER_H
