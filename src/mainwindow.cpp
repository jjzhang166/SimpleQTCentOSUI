#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view1.h"
#include "view2.h"
#include "view3.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <sstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_v1 = new view1(this);
    m_v2 = new view2(this);
    m_v3 = new view3(this);
    ui->setupUi(this);

    m_v1->hide();
    m_v2->hide();
    m_v3->hide();

    if(1 == GetDefaultViewIndex())
    {
        m_v1->show();
    }
    else if(2 == GetDefaultViewIndex())
    {
        m_v2->show();
    }

    this->removeToolBar(ui->mainToolBar);
    connect(ui->action_11,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->action_21,SIGNAL(triggered()),this,SLOT(DisplayView1()));
    connect(ui->action_22,SIGNAL(triggered()),this,SLOT(DisplayView2()));
    connect(ui->action_31,SIGNAL(triggered()),this,SLOT(DisplayView3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetCentralWidget(QWidget *widget)
{
    QWidget* curWidget = this->centralWidget();
    if(curWidget)
        curWidget->setParent(NULL);
    this->setCentralWidget(widget);
    widget->show();
}

int MainWindow::GetDefaultViewIndex()
{
    std::ifstream cfgFile("config.cfg");
    char tmp[MAX_CHARACTER_EACH_LINE];
    std::string strValue;

    if(!cfgFile.is_open())  //open file failed
        return -1;

    while(!cfgFile.eof())
    {
        cfgFile.getline(tmp,MAX_CHARACTER_EACH_LINE);
        std::string line(tmp);
        size_t pos = line.find('=');
        if(pos==std::string::npos)
            return -1;  //not found
        std::string tmpKey = line.substr(0,pos);
        if("Default view index" == tmpKey)  //view index key
        {
            strValue = line.substr(pos+1);
            if(strValue == std::string("1"))
                return 1;
            if(strValue == std::string("2"))
                return 2;
        }
    }
    return -1;  // others cases for failure
}

void MainWindow::DisplayView1()
{
    if(m_v1)
    {
        SetCentralWidget(m_v1);
    }
    m_v2->hide();
    m_v3->hide();
}

void MainWindow::DisplayView2()
{
     if(m_v2)
     {
        SetCentralWidget(m_v2);
     }
     m_v1->hide();
     m_v3->hide();
}

void MainWindow::DisplayView3()
{
    if(m_v3)
    {
        SetCentralWidget(m_v3);
    }
    m_v2->hide();
    m_v1->hide();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    std::ofstream out("config.cfg");
    if(out.is_open())
    {
        out << "Default view index="<<m_v3->GetDefaultViewIndex();
        out.close();
    }
}

