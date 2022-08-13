#include "mainwidgets.h"
#include "ui_mainwidgets.h"

MainWidgets::MainWidgets(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWidgets)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(1); // tab2 부터 보임.

    pTab2Soket = new Tab2Sokect(ui->ptab2); // create ui?
    ui->ptab2->setLayout(pTab2Soket->layout()); // 방금 만든 ui의 레이아웃을 가져온다.

    pTab3ControlPannel = new Tab3ControlPannel(ui->ptab3); // tab3 객체를 만든다.
    ui->ptab3->setLayout(pTab3ControlPannel->layout());

    pTab4SensorDisplay = new Tab4SensorDisplay(ui->ptab4); // tab4 객체를 만든다.
    ui->ptab4->setLayout(pTab4SensorDisplay->layout());

    pTab5ChartPlot = new Tab5ChartPlot(ui->ptab5);
    ui->ptab5->setLayout(pTab5ChartPlot->layout());

    pTab6Database = new Tab6Database(ui->ptab6);
    ui->ptab6->setLayout(pTab6Database->layout());

    connect(pTab2Soket , SIGNAL(sigTab3RecvData(QString)), pTab3ControlPannel, SLOT(slotTab3RecvData(QString)));
    connect(pTab3ControlPannel, SIGNAL(sigSocketSendData(QString)), pTab2Soket, SLOT(slotSocketSendData(QString)));

    connect(pTab2Soket, SIGNAL(sigTab4RecvData(QString)), pTab4SensorDisplay, SLOT(slotTab4RecvData(QString)));    
    connect(pTab2Soket, SIGNAL(sigTab5RecvData(QString)), pTab5ChartPlot, SLOT(slotTab5RecvData(QString)));
    connect(pTab2Soket, SIGNAL(sigTab6RecvData(QString)), pTab6Database, SLOT(slotTab6RecvData(QString)));
}


MainWidgets::~MainWidgets()
{
    delete ui;
}

