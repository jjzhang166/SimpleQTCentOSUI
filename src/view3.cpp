
#include "view3.h"
#include "ui_view3.h"
#include <QDebug>
class QResizeEvent;
view3::view3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view3)
{
    ui->setupUi(this);

}
view3::~view3()
{
    delete ui;
}

int view3::GetDefaultViewIndex()
{
    if(ui->radioButton->isChecked())    //display view1
        return 1;
    if(ui->radioButton_2->isChecked())  //display view2
        return 2;
}
