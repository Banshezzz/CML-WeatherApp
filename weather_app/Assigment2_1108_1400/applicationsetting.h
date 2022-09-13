#ifndef APPLICATIONSETTING_H
#define APPLICATIONSETTING_H

#include <QObject>
#include <QtXml/QDomDocument>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class ApplicationSetting
{

public:
    ApplicationSetting();
    ApplicationSetting(const QString &dataSource);
    ~ApplicationSetting();

    const QString &dataSource() const;
    void setDataSource(const QString &newDataSource);

    void createXmlDocument();
    void writeToFile(const QDomDocument &document);
    void readFromFile();
    void transToXmlDocument(const QDomDocument &document);
    void ListElement(QDomElement&,QString&);

protected:
    static const QString m_file;

private:
    QDomDocument m_document;
    QString m_dataSource;
};

#endif // APPLICATIONSETTING_H
