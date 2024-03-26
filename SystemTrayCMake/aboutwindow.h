#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
namespace Ui {
class AboutWindow;
}

class AboutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_close_clicked();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
