#include "tab4sensordisplay.h"
#include "ui_tab4sensordisplay.h"

Tab4SensorDisplay::Tab4SensorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4SensorDisplay)
{
    ui->setupUi(this);
}

Tab4SensorDisplay::~Tab4SensorDisplay()
{
    delete ui;
}

void Tab4SensorDisplay::slotTab4RecvData(QString recvData)
{
    recvData.replace("[", "@");
    recvData.replace("]", "@");
    QStringList qlist = recvData.split("@");


    ui->pTLLight->setText(qlist[3]);
    ui->pTLTemp->setText(qlist[4]);
    ui->pTLHum->setText(qlist[5]);
}
