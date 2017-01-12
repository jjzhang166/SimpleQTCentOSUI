#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define MAX_CHARACTER_EACH_LINE  1024

class view1;
class view2;
class view3;
class QStackedWidget;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetCentralWidget(QWidget* widget);

private:
    int GetDefaultViewIndex();

private slots:
    void DisplayView1();
    void DisplayView2();
    void DisplayView3();
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    view1          *m_v1;
    view2          *m_v2;
    view3          *m_v3;
};

#endif // MAINWINDOW_H
