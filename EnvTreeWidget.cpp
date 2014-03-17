#include "EnvTreeWidget.h"
#include <QMenu>
#include <QAction>
#include <QDebug>
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
