#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include "Register.h"
#include "Processor.h"
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    processor = new Processor();

    connect(this->ui->execute_button, SIGNAL(clicked()), this, SLOT(execute()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execute() {
    string line;
    bool eof_reached;
    qDebug() << "execution started";
    do {
        //getline(cin, line);
        processor->process_command("mov r1, #5");
        //eof_reached = cin.eof();
        eof_reached = true;

    } while(!eof_reached);
}
