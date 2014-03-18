#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "EnvTreeWidget.h"
#include <QMainWindow>
#include <QHash>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btn_Backup_clicked();
    
private:
    Ui::MainWindow *ui;
};




QHash<QString, QString> getSystemEnv();
QHash<QString, QString> getUserEnv();
void createEnvTree(EnvTreeWidget *, const QHash<QString, QString> &);


#endif // MAINWINDOW_H
