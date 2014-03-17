#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "EnvTreeWidget.h"
#include <QMainWindow>
#include <QHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};




QHash<QString, QString> getSystemEnv();
QHash<QString, QString> getUserEnv();
void createEnvTree(EnvTreeWidget *, const QHash<QString, QString> &);


#endif // MAINWINDOW_H
