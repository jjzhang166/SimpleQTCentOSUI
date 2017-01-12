#ifndef VIEW2_H
#define VIEW2_H

#include <QWidget>
#include <QModelIndex>
class QLineEdit;
class QStandardItemModel;
#define COLUMN_NUMBER 8
namespace Ui {
class view2;
}

class view2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit view2(QWidget *parent = 0);
    ~view2();

private slots:
    void InsertData();
    void DeleteData(QModelIndex modelIndex);

private:
    void InputDigitalOnly(QLineEdit* lineEdit); //only input for digital
    void InputDigitalAndChar(QLineEdit* lineEdit);  //input for digital and character
private:
    Ui::view2 *ui;
    QStandardItemModel* m_pTableModel;
};

#endif // VIEW2_H
