#include "applicationsetting.h"


ApplicationSetting::ApplicationSetting()
{
    m_dataSource = "";
    QFile file;
    if(!file.exists(m_file))
    {
        qDebug() << "File isn't exists => create new xml file" ;
        createXmlDocument();
        writeToFile(m_document);
    }
    else {
        qDebug() << "File exists => read from xml file" ;
        readFromFile();
    }
}

const QString ApplicationSetting::m_file = ":/application.xml";

ApplicationSetting::ApplicationSetting(const QString &dataSource)
{
    setDataSource(dataSource);
}

ApplicationSetting::~ApplicationSetting()
{
    m_dataSource = NULL;
}

const QString &ApplicationSetting::dataSource() const
{
    return m_dataSource;
}

void ApplicationSetting::setDataSource(const QString &newDataSource)
{
    m_dataSource = newDataSource;
}

void ApplicationSetting::createXmlDocument() {
    QDomDocument document;
    QDomElement root = document.createElement("QtApplication");
    document.appendChild(root);

    QDomElement dataSourceNode = document.createElement("DataSource");
    //dummy testing set dataSource
    m_dataSource = "SQLLite";
    QDomText dataSourceValue = document.createTextNode(m_dataSource);
    dataSourceNode.appendChild(dataSourceValue);

    root.appendChild(dataSourceNode);
    m_document = document;

}

void ApplicationSetting::writeToFile(const QDomDocument &document)
{
    QFile settingFile (m_file);
    if(!settingFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Failed to open file for writing or already open" << Qt::endl;
        settingFile.close();
    } else {
        QTextStream stream(&settingFile);
        stream << document.toString();
        settingFile.close();
        qDebug() << "Finished write xml document to file" << Qt::endl;
    }
}

void ApplicationSetting::readFromFile()
{
    QFile settingFile (m_file);
    if(!settingFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file for read" << Qt::endl;
        settingFile.close();
    } else {
        if(!m_document.setContent(&settingFile))
        {
            qDebug() << "Failed to load xml file to xml document" << Qt::endl;
        }

        qDebug() << "Finished read xml file, set xml document content successful" << Qt::endl;
        settingFile.close();
        transToXmlDocument(m_document);
    }
}

void ApplicationSetting::transToXmlDocument(const QDomDocument &document)
{
    QDomElement root = document.firstChildElement();
    //    ListElement(root,"DataSource");

    QDomElement dataSourceNode = root.firstChildElement();
    QDomText dataSourceValue = dataSourceNode.firstChild().toText();
    setDataSource(dataSourceValue.data());
}

void ApplicationSetting::ListElement(QDomElement &root, QString &tag)
{
    QDomNodeList items = root.elementsByTagName(tag);
    qDebug() << "Total items setting in application: " << items.count() << Qt::endl;
}
