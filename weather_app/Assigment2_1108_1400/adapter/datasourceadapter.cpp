#include "datasourceadapter.h"

DatasourceAdapter::DatasourceAdapter()
    : m_dataSource("")
{

}

const QString &DatasourceAdapter::dataSource() const
{
    return m_dataSource;
}

void DatasourceAdapter::setDataSource(const QString &newDatasource)
{
    m_dataSource = newDatasource;
    initDataSource();
}

QByteArray DatasourceAdapter::initDataSource()
{
    QByteArray ini;
    QFile File;
    QByteArray bytedata;
    //Json
    if(m_dataSource == "Json"){
        File.setFileName(":/data.json");
        File.open(QIODevice::ReadOnly | QIODevice::Text);
        bytedata = File.readAll();
        ini = bytedata;

        convertFromJson(bytedata);
    }
    //SQLLite
    else if(m_dataSource == "SQLite"){
        File.setFileName(":/database/data.sqlite");
        if(File.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "D:/Adapter.cpp: Able to open SQLite file";
        }
        convertFromSQLite();

        QByteArray bytedata = File.readAll();
        ini = bytedata;

    }
    //File
    else if(m_dataSource == "File"){
        QFile File(":/data.txt");
        File.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray bytedata = File.readAll();
        ini = bytedata;

        convertFromFile(bytedata);
    }
    return ini;
}
//convert a json file to qlist -> transfer to model
void DatasourceAdapter::convertFromJson(const QByteArray &file)
{
    QList<City> newCitys;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file);
    QJsonArray citys = jsonDoc.array();

    for(int i = 0; i < citys.size(); i++)
    {
        // each city is an object
        QJsonObject city = citys[i].toObject();

        //get value
        QString name = city["countryName"].toString();
        QString condition = city["condition"].toString();
        int speed = city["speed"].toInt();
        int chill = city["chill"].toInt();
        QString direction = city["direction"].toString();
        int humidity = city["humidity"].toInt();
        int pressure= city["pressure"].toInt();
        int rising = city["rising"].toInt();
        int visibility = city["visibility"].toInt();
        QString sunrise = city["direction"].toString();
        QString sunset = city["direction"].toString();

        //        auto wind = Wind(speed, chill, direction);
        //        auto atm = Atmosphere(humidity, pressure, rising, visibility );
        //        auto astro = Astronomy(sunrise, sunset);

        //        auto newCity = City(name, condition, wind, atm, astro);
        auto newCity = City(name, condition, speed, chill, direction, humidity, pressure, rising, visibility, sunrise, sunset);
        newCitys.append(newCity);
    }

    m_citys = newCitys;
}

void DatasourceAdapter::convertFromSQLite()
{  
    QList<City> newCitys;
    QDir dir;
    QString curPath = dir.absolutePath() + "/debug/database/";
    qDebug() << "D:/Adapter.cpp : current path: " << curPath;
    //    const QString path = "D:/Workspace/QTProject/build-Assigment2-Desktop_Qt_6_3_1_MinGW_64_bit-Debug/debug/database/data.sqlite";
    const QString path = curPath + "data.sqlite";
    qDebug() << "D:/Adapter.cpp : SQLite file path: " << path;
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE","sqliteConnection");
    m_db.setDatabaseName(path);
    m_db.open();
    try{
        if( QSqlDatabase::contains( "sqliteConnection" ) )
        {
            QSqlDatabase db = QSqlDatabase::database( "sqliteConnection" );
            //Do stuff...
            if(db.open())
            {
                qDebug() << "sql open";

                QSqlQuery q(db);

                if(q.exec("SELECT * FROM Citys"))
                {
                    qDebug() << "D:/ Query excuted successfull";
                    while(q.next())
                    {
                        QString name = q.value(1).toString();
                        QString condition = q.value(2).toString();
                        int speed = q.value(3).toInt();
                        int chill = q.value(4).toInt();
                        QString direction = q.value(5).toString();
                        int humidity    = q.value(6).toInt();
                        int pressure    = q.value(7).toInt();
                        int rising      = q.value(8).toInt();
                        int visibility  =    q.value(9).toInt();
                        QString sunrise =   q.value(10).toString();
                        QString sunset  =    q.value(11).toString();

                        //                        auto wind = Wind(speed, chill, direction);
                        //                        auto atm = Atmosphere(humidity, pressure, rising, visibility );
                        //                        auto astro = Astronomy(sunrise, sunset);

                        //                        auto newCity = City(name, condition, wind, atm, astro);
                        auto newCity = City(name, condition, speed, chill, direction, humidity, pressure, rising, visibility, sunrise, sunset);
                        newCitys.append(newCity);
                    }

                    m_citys = newCitys;
                }
                else {
                    qDebug() << "D:/ Query excute error: " << q.lastError() ;
                }
            }
            else {
                qDebug() << "in if - try error: " << db.lastError();
            }
        } else {
            qDebug() << "if error: " << m_db.lastError();
        }

        m_db.close();
        QSqlDatabase::removeDatabase("sqliteConnection");
    }
    catch(QSqlError e){
        qDebug() << "catch error: " << e.nativeErrorCode() << " - type:" << e.type();
    }



}

//Convert a text file (data.txt) with JSON format to QList -> transfer to model
void DatasourceAdapter::convertFromFile(const QByteArray &file)
{
    QList<City> newCitys;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file);
    QJsonArray citys = jsonDoc.array();

    for(int i = 0; i < citys.size(); i++)
    {
        // each city is an object
        QJsonObject city = citys[i].toObject();

        //get value
        QString name = city["countryName"].toString();
        QString condition = city["condition"].toString();
        int speed = city["speed"].toInt();
        int chill = city["chill"].toInt();
        QString direction = city["direction"].toString();
        int humidity = city["humidity"].toInt();
        int pressure= city["pressure"].toInt();
        int rising = city["rising"].toInt();
        int visibility = city["visibility"].toInt();
        QString sunrise = city["direction"].toString();
        QString sunset = city["direction"].toString();

        //        auto wind = Wind(speed, chill, direction);
        //        auto atm = Atmosphere(humidity, pressure, rising, visibility );
        //        auto astro = Astronomy(sunrise, sunset);

        //        auto newCity = City(name, condition, wind, atm, astro);
        auto newCity = City(name, condition, speed, chill, direction, humidity, pressure, rising, visibility, sunrise, sunset);
        newCitys.append(newCity);
    }

    m_citys = newCitys;
}

const QList<City> &DatasourceAdapter::citys() const
{
    return m_citys;
}
