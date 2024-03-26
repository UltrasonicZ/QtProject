#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

void AboutWindow::on_close_clicked()
{
    close();
    //reject();
}
