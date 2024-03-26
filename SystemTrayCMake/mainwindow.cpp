#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->MainWindow->set
    //init system tray
    m_systemTray = new QSystemTrayIcon(this);
    m_systemTray->setIcon(QIcon(":/image/AUTH.ico"));
    m_systemTray->setToolTip("可信认证仪");

    connect(m_systemTray, &QSystemTrayIcon::activated, this, &MainWindow::activeTray);//点击托盘，执行相应的动作
    createActions();
    createMenu();

    m_systemTray->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    m_showAbout = new QAction("关于", this);
    m_quit = new QAction("退出", this);
    connect(m_showAbout, &QAction::triggered, this, &MainWindow::showAbout);
    connect(m_quit, &QAction::triggered, this, &MainWindow::quit);
}

void MainWindow::createMenu()
{
    m_menu = new QMenu(this);
    m_menu->addAction(m_showAbout);
    m_menu->addAction(m_quit);

    m_systemTray->setContextMenu(m_menu);
}

void MainWindow::showMenu()
{
    m_menu->show();
}

void MainWindow::showAbout()
{
    abtWnd = new AboutWindow(this);
    abtWnd->show();
}

void MainWindow::quit()
{
    exit(0);
}

void MainWindow::activeTray(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Context:
        showMenu();
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    case QSystemTrayIcon::Trigger:
        //showMessage();
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(NULL, "About", "1.0.0.1");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_systemTray->isVisible())
    {
        hide();
        event->ignore();
    }
}
