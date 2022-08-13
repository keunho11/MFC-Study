#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    connect(ui->pPBLamp, SIGNAL(clicked(bool)), this, SLOT(slotLampOnOff(bool)));
    connect(ui->pPBPlug, SIGNAL(clicked(bool)), this, SLOT(slotPlugOnOff(bool)));
}

Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}

void Tab3ControlPannel::slotLampOnOff(bool check)
{
    qDebug() << check;
    if(check)
    {
        ui->pPBLamp->setChecked(false);// 깅제로 off 유지
        emit sigSocketSendData("[19]LAMPON");
    }
    else
    {
        ui->pPBLamp->setChecked(true);
        emit sigSocketSendData("[19]LAMPOFF");
    }
}


void Tab3ControlPannel::slotPlugOnOff(bool check)
{
    if(check)
    {
        ui->pPBPlug->setChecked(false);// 강제로 off 유지
        emit sigSocketSendData("[19]GASON");
    }
    else
    {
        ui->pPBPlug->setChecked(true);
        emit sigSocketSendData("[19]GASOFF");
    }
}

void Tab3ControlPannel::slotTab3RecvData(QString recvData)
{
//    QMessageBox::information(this, "socket", strData);
    recvData.replace("[", "@");
    recvData.replace("]", "@");
    QStringList qlist = recvData.split("@");

    qDebug() << qlist[2];
    if(qlist[2] == "LAMPON")
    {
        ui->pPBLamp->setChecked(true);
    }
    else if(qlist[2] == "LAMPOFF")
    {
        ui->pPBLamp->setChecked(false);
    }
    else if(qlist[2] == "GASON")
    {
        ui->pPBPlug->setChecked(true);
    }
    else if(qlist[2] == "GASOFF")
    {
        ui->pPBPlug->setChecked(false);
    }
}
