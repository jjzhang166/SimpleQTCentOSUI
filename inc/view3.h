#ifndef VIEW3_H
#define VIEW3_H

#include <QWidget>
#include <QResizeEvent>
#include <QVBoxLayout>
namespace Ui {
class view3;
}

class view3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit view3(QWidget *parent = 0);
    ~view3();
    int GetDefaultViewIndex();
private:
    Ui::view3 *ui;
};

#endif // VIEW3_H
