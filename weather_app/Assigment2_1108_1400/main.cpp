#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QString>

#include "applicationsetting.h"
#include "adapter/datasourceadapter.h"
#include "model/citymodel.h"
#include "model/city.h"
#include "model/wind.h"
#include "model/atmosphere.h"
#include "model/astronomy.h"

void saveSetting(QGuiApplication &app);
void dummyData(CityModel &model);

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //for my old laptop only  =))))
    QQuickWindow::setSceneGraphBackend("software");

    QGuiApplication app(argc, argv);

    ApplicationSetting appSetting;

    app.setApplicationName("Weather Infomation");
    app.setOrganizationName("HCL Vietnam");
    app.setOrganizationDomain("hclvietnam.com");
    app.setApplicationVersion("1.0.0");

    //read xml file
    QDomDocument appXML;
    QFile xmlFile(":/application.xml");
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
    }
    appXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = appXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    QString data = "";

    while(node.isNull() == false)
    {
        if(node.tagName() == "DataSource"){
            while(!node.isNull()){
                QString name = node.attribute("name","name");

                data.append(name);
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }

    qDebug() << "D:/ main.cpp: dataSource value:" << data;
    DatasourceAdapter adapter;
    adapter.setDataSource(data);

    CityModel cityModel;
    cityModel.setAdapter(adapter);
    qDebug() << "D:/ main.cpp: model: rowCount(): " <<cityModel.rowCount();
//    dummyData(model);

    QQmlApplicationEngine engine;

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("cityModel",&cityModel);
//    rootContext->setContextProperty("jsonModelData",adapter.initDataSource());

    saveSetting(app);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

void saveSetting( QGuiApplication &app)
{
    QSettings setting;
    setting.beginGroup("Appication");
    setting.setValue("AppName",app.applicationName());
    setting.endGroup();
    setting.beginGroup("MainWindow");
    setting.setValue("geometry", app.primaryScreen()->geometry());
    setting.endGroup();
    setting.beginGroup("Organization");
    setting.setValue("Domain",app.organizationDomain());
    setting.setValue("Company",app.organizationName());
    setting.endGroup();
    setting.beginGroup("User");
    setting.setValue("CityFav","Ha Noi");
    setting.endGroup();
}

void dummyData(CityModel &model)
{
    Wind w1(67,40,"NW");
    Atmosphere atm1(80,0,1000,10000);
    Astronomy ast1("05:30","18:12");
    QString name = "Ha Noi copy";
    QString condition = "Clear";
    City city1(name,condition,w1,atm1,ast1);
    model.addItem(city1);

    City city2("Ho Chi Minh","Clear",w1,atm1,ast1);
    model.addItem(city2);
    City city3("New York","Clear",w1,atm1,ast1);
    model.addItem(city3);
}
