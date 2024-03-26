#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QtWidgets/QWidget>
#include <QSystemTrayIcon>
#include <QMenu>

class SystemTray : public QWidget
{
    Q_OBJECT

public:
    SystemTray(QWidget *parent = 0);
    ~SystemTray();

protected:
    void activeTray(QSystemTrayIcon::ActivationReason reason);
    void showWindow();//显示窗体
    void showMessage();//消息框
    void showMenu();//显示菜单

    void showAbout();
    void quit();

private:
    QSystemTrayIcon *m_systemTray;

    QMenu *m_menu;
    QAction *m_showAbout;
    QAction *m_quit;
};

#endif // SYSTEMTRAY_H
