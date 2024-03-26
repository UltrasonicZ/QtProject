#include "systemtray.h"

SystemTray::SystemTray(QWidget *parent)
    : QWidget(parent)
{
    m_systemTray = new QSystemTrayIcon(this);

    m_menu = new QMenu(this);
    m_showAbout = new QAction(m_menu);
    m_quit = new QAction(m_menu);

    m_showAbout->setText("About");
    m_quit->setText("Quit");

    m_menu->addAction(m_showAbout);
    m_menu->addAction(m_quit);

    connect(m_showAbout, &QAction::triggered, this, &SystemTray::showWindow);
    connect(m_quit, &QAction::triggered, this, &SystemTray::showMessage);

    m_systemTray->setContextMenu(m_menu);
    m_systemTray->setIcon(QIcon(":/image/AUTHico.ico"));
    m_systemTray->setToolTip("SystemTray Program");
    m_systemTray->show();
    connect(m_systemTray, &QSystemTrayIcon::activated, this, &SystemTray::activeTray);//点击托盘，执行相应的动作
    connect(m_systemTray, &QSystemTrayIcon::messageClicked, this, &SystemTray::showWindow);//点击消息框，显示主窗口
}

SystemTray::~SystemTray()
{

}

void SystemTray::activeTray(QSystemTrayIcon::ActivationReason reason)
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
        showMessage();
        break;
    }
}

void SystemTray::showMenu()
{
    m_menu->show();
}

void SystemTray::showWindow()
{
    this->show();
}

void SystemTray::showMessage()
{
    m_systemTray->showMessage("Information",//消息窗口标题
        "There is a new message!",//消息内容
        QSystemTrayIcon::MessageIcon::Information,//消息窗口图标
        5000);//消息窗口显示时长
}
void SystemTray::showAbout()
{

}

void SystemTray::quit()
{

}
