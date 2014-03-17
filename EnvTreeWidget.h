#ifndef ENVTREEWIDGET_H
#define ENVTREEWIDGET_H

#include <QTreeWidget>

class EnvTreeWidget : public QTreeWidget
{
public:
    EnvTreeWidget(QWidget * parent = 0)
        :QTreeWidget(parent)
    {}
    ~EnvTreeWidget();
    void contextMenuEvent(QContextMenuEvent *);
};


class EnvTreeWidgetItem: public QTreeWidgetItem{
    
public:
    EnvTreeWidgetItem(QTreeWidgetItem * parent)
        :QTreeWidgetItem(parent)
    {}
    void setData(int column, int role, const QVariant &value);
    void emitDataChanged();
};

#endif // ENVTREEWIDGET_H
