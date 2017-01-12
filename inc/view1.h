#ifndef VIEW1_H
#define VIEW1_H

#include <QWidget>
#include <QModelIndex>
class QLineEdit;
class QStandardItemModel;

#define COLUMN_NUMBER 8

namespace Ui {
class view1;
}

class view1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit view1(QWidget *parent = 0);
    ~view1();

private slots:
    void InsertData();
    void DeleteData(QModelIndex modelIndex);

private:
    void InputDigitalOnly(QLineEdit* lineEdit); //only input for digital
    void InputDigitalAndChar(QLineEdit* lineEdit);  //input for digital and character
    
private:
    Ui::view1 *ui;
    QStandardItemModel* m_pTableModel;
};
#endif // VIEW1_H
