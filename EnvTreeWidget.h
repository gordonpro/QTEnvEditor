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


#endif // ENVTREEWIDGET_H
