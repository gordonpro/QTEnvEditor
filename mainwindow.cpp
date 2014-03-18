#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "backup.h"
#include "EnvTreeWidget.h"
#include <QSettings>
#include <QDebug>
#include <QHBoxLayout>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // not sufficient enough in setupUi function.
    
    ui->tabWidget->setTabText(0, QStringLiteral("用户变量"));
    ui->tabWidget->setTabText(1, QStringLiteral("系统变量"));
    
    EnvTreeWidget *treew_SystemEnv = new EnvTreeWidget(ui->tab_SystemEnv);
    treew_SystemEnv->setObjectName("treew_SystemEnv");
    //  do not display header
    treew_SystemEnv->header()->close();
    QSize size = treew_SystemEnv->parentWidget()->size();
    treew_SystemEnv->resize(505, 296);
    createEnvTree(treew_SystemEnv, getSystemEnv());
    
    EnvTreeWidget *treew_UserEnv = new EnvTreeWidget(ui->tab_UserEnv);
    treew_UserEnv->setObjectName("treew_UserEnv");
    //  do not display header
    treew_UserEnv->header()->close();
    treew_UserEnv->resize( 505, 296);
    createEnvTree(treew_UserEnv, getUserEnv());
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

QHash<QString, QString> getSystemEnv(){
    QSettings setting("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 
                      QSettings::NativeFormat);
    QHash<QString, QString> settingMap;
    foreach (QString key, setting.allKeys()) {
        settingMap.insert(key, setting.value(key).toString());
    }
    return settingMap;
}

QHash<QString, QString> getUserEnv(){
    QSettings setting("HKEY_CURRENT_USER\\Environment", 
                      QSettings::NativeFormat);
    QHash<QString, QString> settingMap;
    foreach (QString key, setting.allKeys()) {
        settingMap.insert(key, setting.value(key).toString());
    }
    return settingMap;
}


void createEnvTree(EnvTreeWidget *tree, const QHash<QString, QString> & settingMap){
     QHashIterator<QString, QString> i(settingMap);
    while (i.hasNext()) {
        i.next();
//        qDebug() << i.key() << ": " << i.value();
        QStringList valueSeg = i.value().split(";");
        valueSeg.removeAll("");
        QTreeWidgetItem *envNameItem =new QTreeWidgetItem(tree);
        envNameItem->setText(0, i.key());
        foreach (QString value, valueSeg) {
            EnvTreeWidgetItem *valueItem =new EnvTreeWidgetItem(envNameItem);
            valueItem->setFlags(valueItem->flags()|Qt::ItemIsEditable);
            valueItem->setText(0, value);
        }
    }
}



void MainWindow::on_btn_Backup_clicked()
{
    writerToFile(createEnvJson());
    qDebug() << "备份文件完成";
    
}
