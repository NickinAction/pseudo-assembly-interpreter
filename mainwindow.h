#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Processor.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();
    void execute();
    QVector <QString> readInput(QString labelText);
    void displayState();

private:
    QVector <QLabel*> labels;
    Ui::MainWindow *ui;
    Processor* processor;
};

#endif // MAINWINDOW_H
