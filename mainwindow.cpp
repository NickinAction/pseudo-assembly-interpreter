#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QLabel>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeArea->setFixedWidth(600);

    processor = new Processor();


    for (int i = 0; i < processor->registers.size(); i++) {

        QLabel *label = new QLabel(this);
        labels.push_back(label);

        label->setText("Register " + QString::number(i) + ": ");
        label->setFixedWidth(300);

        ui->labelLayout->addWidget(label, 1, Qt::AlignHCenter);
    }

    connect(this->ui->execute_button, SIGNAL(clicked()), this, SLOT(execute()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execute() {

    QString labelText = ui->codeArea->toPlainText();

    QVector <QString> codeLines = readInput(labelText);

    for(int i = 0; i < codeLines.size(); i++) {
        processor->process_command(codeLines[i].toStdString());
    }

    displayState();
}

void MainWindow::displayState() {
    for (unsigned i = 0; i < processor->registers.size(); i++) {

        QString s = QString::fromStdString(processor->registers[i].toString());
        // qDebug() << s << endl;

        labels[i]->setText("Register " + QString::number(i) + ": " + s);
    }
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

