#include "tab2sokect.h"
#include "ui_tab2sokect.h"

Tab2Sokect::Tab2Sokect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2Sokect)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    ui->pPBSendButton->setEnabled(false); // sendbutton 초기상태 - 비활성화
    connect(ui->pPBServerConnect, SIGNAL(clicked(bool)), this,SLOT(slotConnectToServer(bool)));

    connect(ui->pPBSendButton, SIGNAL(clicked()), this, SLOT(slotSocketSendData()));

    connect(pSocketClient,SIGNAL(sigSocketRecv(QString)), this, SLOT(slotSocketRecvUpdate(QString)));

    connect(ui->pPBReceiveClear, SIGNAL(clicked()), ui->pTERecvData, SLOT(clear()));
}

Tab2Sokect::~Tab2Sokect()
{
    delete ui;
}

void Tab2Sokect::slotConnectToServer(bool check)
{
    bool bok;
    if(check){
        pSocketClient->slotConnectToServer(bok);
        if(bok){
            ui->pPBServerConnect->setText("서버 해제");
            ui->pPBSendButton->setEnabled(true);
        }
    }
    else{
        pSocketClient->slotClosedByServer();
        ui->pPBServerConnect->setText("서버 연결");
        ui->pPBSendButton->setEnabled(false);
    }
}

void Tab2Sokect::slotSocketRecvUpdate(QString strRecvData)
{


    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    //qDebug() << strTime;

    strRecvData.chop(1); // erase '\n'
   // qDebug() << strRecvData;

    if((strRecvData.indexOf("LAMP") != -1) ||(strRecvData.indexOf("GAS") != -1))
    {
        emit sigTab3RecvData(strRecvData);
    }

    if(strRecvData.indexOf("SENSOR")!= -1)
    {
        emit sigTab4RecvData(strRecvData);
        emit sigTab5RecvData(strRecvData);
       // emit sigTab6RecvData(strRecvData);
    }

    strRecvData = strTime + " " + strRecvData;
    ui->pTERecvData->append(strRecvData);
    ui->pTERecvData->moveCursor(QTextCursor::End);
}

void Tab2Sokect::slotSocketSendData()
{
    QString strRecvId;
    QString strSendData;

    strRecvId = ui->pLERecvId->text();
    strSendData = ui->pLESendData->text();

    if(strRecvId.isEmpty())
        strSendData = "[ALLMSG]" + strSendData;
    else
        strSendData = "[" + strRecvId + "]" + strSendData;
    pSocketClient->slotSocketSendData(strSendData);

    ui->pLESendData->clear();

}



void Tab2Sokect::slotSocketSendData(QString strData)
{
    if(ui->pPBServerConnect->isChecked()){
        //qDebug() << strData;
        pSocketClient->slotSocketSendData(strData);
    }
    else
        QMessageBox::information(this, "socket","서버 연결 확인");
}
