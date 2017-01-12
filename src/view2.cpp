#include "view2.h"
#include "ui_view2.h"
#include <QLineEdit>
#include <QStandardItem>

view2::view2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view2)
{
    ui->setupUi(this);

    InputDigitalAndChar(ui->lineEdit_55);

    InputDigitalOnly(ui->lineEdit_56);
    InputDigitalOnly(ui->lineEdit_57);
    InputDigitalOnly(ui->lineEdit_58);
    InputDigitalOnly(ui->lineEdit_59);
    InputDigitalOnly(ui->lineEdit_60);
    InputDigitalOnly(ui->lineEdit_81);
    InputDigitalOnly(ui->lineEdit_82);
    InputDigitalOnly(ui->lineEdit_83);
    InputDigitalOnly(ui->lineEdit_85);

    //set model for table view
    m_pTableModel = new QStandardItemModel(this);
    ui->tableView_1->setModel(m_pTableModel);
    ui->tableView_1->verticalHeader()->hide();
    ui->tableView_1->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableModel->setColumnCount(COLUMN_NUMBER);
    for(int index = 0; index < COLUMN_NUMBER; ++index)
    {
        QString strItem("Item");
        strItem += QString("%1").arg(index);
        m_pTableModel->setHeaderData(index,Qt::Horizontal,strItem);
    }

   connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(InsertData()));
   connect(ui->tableView_1,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(DeleteData(QModelIndex)));
}

view2::~view2()
{
    delete ui;
}

void view2::InputDigitalOnly(QLineEdit* lineEdit)
{
    QRegExp regExp("[0-9]*$");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
}

void view2::InputDigitalAndChar(QLineEdit *lineEdit)
{
    QRegExp regExp("[0-9A-Za-z]*$");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
}
void view2::InsertData()
{
    QStandardItem *item0 = new QStandardItem(ui->lineEdit_55->text());
    QStandardItem *item1 = new QStandardItem(ui->lineEdit_56->text());
    QStandardItem *item2 = new QStandardItem("Unknown");
    QStandardItem *item3 = new QStandardItem(ui->lineEdit_57->text());
    QStandardItem *item4 = new QStandardItem("Unknown");
    QStandardItem *item5 = new QStandardItem(ui->lineEdit_58->text());
    QStandardItem *item6 = new QStandardItem(ui->lineEdit_59->text());
    QStandardItem *item7 = new QStandardItem(ui->lineEdit_60->text());
    if(ui->radioButton_31->isChecked())
        item2->setText("radio31");
    else if(ui->radioButton_32->isChecked())
        item2->setText("radio32");
    if(ui->radioButton_41->isChecked())
        item4->setText("radio41");
    else if(ui->radioButton_42->isChecked())
        item4->setText("radio42");
    QList<QStandardItem*> itemList;
    itemList<<item0<<item1<<item2<<item3<<item4<<item5<<item6<<item7;
    m_pTableModel->appendRow(itemList);
}

void view2::DeleteData(QModelIndex modelIndex)
{
    if(modelIndex.isValid())
    {
        m_pTableModel->removeRow(modelIndex.row());
    }
}
