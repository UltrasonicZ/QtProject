#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutwindow.h"
#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createActions();
    void createMenu();

protected:
    void activeTray(QSystemTrayIcon::ActivationReason reason);
    void showMenu();
    void showAbout();
    void quit();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    AboutWindow *abtWnd;

    QSystemTrayIcon *m_systemTray;
    QMenu *m_menu;
    QAction *m_showAbout;
    QAction *m_quit;
};
#endif // MAINWINDOW_H
