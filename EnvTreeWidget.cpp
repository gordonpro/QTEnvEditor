#include "EnvTreeWidget.h"
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QDateTime>
#include <QSettings>
#include <QContextMenuEvent>

EnvTreeWidget::~EnvTreeWidget(){
}

void EnvTreeWidget::contextMenuEvent(QContextMenuEvent *ev){
    QTreeWidgetItem *_currentItem = currentItem();
    if(_currentItem){
        QMenu menu(this);
        if(_currentItem->childCount() > 0){
            //  this is a title item
            menu.addAction(new QAction("删除这个环境变量", this));
            menu.addAction(new QAction("添加一条此变量", this));
        }else{
            menu.addAction(new QAction("删除", this));
        }
        menu.addAction(new QAction("Action 3", this));
        menu.exec(ev->globalPos());
    }
}

void EnvTreeWidgetItem::emitDataChanged(){
    qDebug() << "kasdjlkfasd";
}

void _changeUserEnv(QString name, QStringList values){
    QSettings setting("HKEY_CURRENT_USER\\Environment", 
                      QSettings::NativeFormat);
    QString newValue = values.join(";");
    setting.setValue(name, newValue);
}

void EnvTreeWidgetItem::setData(int column, int role, const QVariant &value){
    //  first super invocation
    QTreeWidgetItem::setData(column, role, value);
    
    if(Qt::EditRole == role){
        qDebug() << "EnvTreeWidgetItem::setData" << QDateTime::currentDateTime();
        //  to get environment name
        QTreeWidgetItem * p = parent();
        QString envName = p->data(0, Qt::DisplayRole).toString();
        QStringList values;
        if("treew_UserEnv" == treeWidget()->objectName()){
            int _childCount = p->childCount();
            for(int i=0; i<_childCount; i++){
               values << p->child(i)->data(0, Qt::DisplayRole).toString();
            }
            
            _changeUserEnv(envName, values);
        }
        
    }
}

