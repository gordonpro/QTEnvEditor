#include "backup.h"
#include <QSettings>
#include <QDebug>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qfile.h>
#include <qdir.h>
#include <QApplication>
#include <QDateTime>


QString createEnvJson(){
    QSettings systemEnvSetting("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 
                      QSettings::NativeFormat);

    QSettings userEnvSetting("HKEY_CURRENT_USER\\Environment", 
                      QSettings::NativeFormat);
    
    QJsonObject userEnvJson;
    
    foreach (QString key, userEnvSetting.allKeys()) {
        QString value = userEnvSetting.value(key).toString();
        QJsonValue v(value);
        userEnvJson.insert(key, v);
    }
    
    QJsonObject systemEnvJson;
    
    foreach (QString key, systemEnvSetting.allKeys()) {
        QString value = systemEnvSetting.value(key).toString();
        QJsonValue v(value);
        systemEnvJson.insert(key, v);
    }
    
    QJsonObject jsonEnv;
    QJsonValue v1(userEnvJson);
    QJsonValue v2(systemEnvJson);
    jsonEnv.insert("userEnv", v1);
    jsonEnv.insert("systemEnv", v2);

  
    QJsonDocument doc(jsonEnv);
    return QString(doc.toJson());
}

void writerToFile(QString data){
    // test dir
    QDir dir("user_data");
    if(!dir.exists()){
        if(!QDir().mkdir("user_data")){
            throw "directory make fail.";
        }
    }
    QString fileName = "env_bak"+QString::number(QDateTime::currentMSecsSinceEpoch())+".json";
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::ReadWrite)){
        qDebug() << "file open fail.";
        qApp->exit();
        return;
    }
    file.write(data.toUtf8());
    file.close();
}
