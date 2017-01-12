#include "view1.h"
#include "ui_view1.h"
#include <vector>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QDebug>
view1::view1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view1)
{
    ui->setupUi(this);

    InputDigitalAndChar(ui->lineEdit_1);
    InputDigitalAndChar(ui->lineEdit_5);
    InputDigitalOnly(ui->lineEdit_2);
    InputDigitalOnly(ui->lineEdit_3);
    InputDigitalOnly(ui->lineEdit_4);
    InputDigitalOnly(ui->lineEdit_6);
    InputDigitalOnly(ui->lineEdit_7);
    InputDigitalOnly(ui->lineEdit_8);
    InputDigitalOnly(ui->lineEdit_9);
    InputDigitalOnly(ui->lineEdit_10);
    InputDigitalOnly(ui->lineEdit_12);
    InputDigitalOnly(ui->lineEdit_13);
    InputDigitalOnly(ui->lineEdit_14);

    //set model for table view
    m_pTableModel = new QStandardItemModel(this);
    ui->tableView_2->setModel(m_pTableModel);
    ui->tableView_2->verticalHeader()->hide();
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableModel->setColumnCount(COLUMN_NUMBER);
    for(int index = 0; index < COLUMN_NUMBER; ++index)
    {
        QString strItem("Item");
        strItem += QString("%1").arg(index);
        m_pTableModel->setHeaderData(index,Qt::Horizontal,strItem);
    }

   connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(InsertData()));
   connect(ui->tableView_2,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(DeleteData(QModelIndex)));
}

void view1::InputDigitalOnly(QLineEdit* lineEdit)
{
    QRegExp regExp("[0-9]*$");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
}

void view1::InputDigitalAndChar(QLineEdit *lineEdit)
{
    QRegExp regExp("[0-9A-Za-z]*$");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
}

view1::~view1()
{
    delete ui;
}

void view1::InsertData()
{
    QStandardItem *item0 = new QStandardItem(ui->lineEdit_5->text());
    QStandardItem *item1 = new QStandardItem(ui->lineEdit_6->text());
    QStandardItem *item2 = new QStandardItem("Unknown");
    QStandardItem *item3 = new QStandardItem(ui->lineEdit_7->text());
    QStandardItem *item4 = new QStandardItem("Unknown");
    QStandardItem *item5 = new QStandardItem(ui->lineEdit_8->text());
    QStandardItem *item6 = new QStandardItem(ui->lineEdit_9->text());
    QStandardItem *item7 = new QStandardItem(ui->lineEdit_10->text());
    if(ui->radioButton_11->isChecked())
        item2->setText("radio11");
    else if(ui->radioButton_12->isChecked())
        item2->setText("radio12");
    if(ui->radioButton_21->isChecked())
        item4->setText("radio21");
    else if(ui->radioButton_22->isChecked())
        item4->setText("radio22");
    QList<QStandardItem*> itemList;
    itemList<<item0<<item1<<item2<<item3<<item4<<item5<<item6<<item7;
    m_pTableModel->appendRow(itemList);
}

void view1::DeleteData(QModelIndex modelIndex)
{
    if(modelIndex.isValid())
    {
        m_pTableModel->removeRow(modelIndex.row());
    }
}
