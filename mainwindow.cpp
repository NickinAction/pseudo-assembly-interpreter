#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QLabel>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeArea->setFixedWidth(600);

    processor = new Processor();

    connect(this->ui->execute_button, SIGNAL(clicked()), this, SLOT(execute()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execute() {

    QString labelText = ui->codeArea->toPlainText();

    QVector <QString> codeLines = readInput(labelText);
}

QVector <QString> MainWindow::readInput(QString labelText) {

    QVector <QString> returnVector;
    int firstCharacter = 0;

    for (int i = 0; i < labelText; i++) {
        if(labelText[i] == '\n') {
            QString line = labelText.mid(firstCharacter, i-firstCharacter);
            if(line != "") {
                returnVector.push_back(line);
            }
            firstCharacter = i+1;
        }
    }
    if(labelText.mid(firstCharacter) != "") {
        returnVector.push_back(labelText.mid(firstCharacter));
    }

    return returnVector;
}

