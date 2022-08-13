#include <QDebug>
#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
//    bool ok;
    pQTcpSocket = new QTcpSocket(); // 라이브러리 제공 소켓

	connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
    connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer())); //서버 끊기면 시그널 생성
	connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
	connect(pQTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
//    slotConnectToServer(ok);
}


void SocketClient::slotConnectToServer(bool& ok){
    //서버 연결 요청
    QString strHostIp;
//	tcpSocket.connectToHost(QHostAddress::LocalHost, 5000);
    strHostIp = QInputDialog::getText(this,"HostIP","Input Server IP:",QLineEdit::Normal,SERVERIP,&ok);
    if(ok)
    {
        if(strHostIp.isEmpty())
            pQTcpSocket->connectToHost(SERVERIP, SERVERPOT);
        else
            pQTcpSocket->connectToHost(strHostIp, SERVERPOT);
    }
}
void SocketClient::slotConnectServer()
{
    QString Str = "["+LOGID+":"+LOGPW+"]";
    QByteArray byteStr = Str.toLocal8Bit();
    pQTcpSocket->write(byteStr);
}

void SocketClient::slotClosedByServer()
{
	pQTcpSocket->close();
}

void SocketClient::slotSocketReadData(){
//    QList<QString> qList;
    QString strRecvData;
    QByteArray qByteArray;

	if (pQTcpSocket->bytesAvailable() > BLOCK_SIZE)
		return;
    qByteArray = pQTcpSocket->read(BLOCK_SIZE);
    //String은 2byte이다. tcp/ip는 바이트 단위이기 때문에
    strRecvData = QString::fromUtf8(qByteArray);
//    qDebug() <<strRecvData;
    emit sigSocketRecv(strRecvData);
//    QMessageBox::information(this,"Socket Recv",strRecvData);
}

void SocketClient::slotSocketError()
{
	QString Str = pQTcpSocket->errorString();
    qDebug() << Str;
}


void SocketClient::slotSocketSendData(QString strSendData)
{	
    if(!strSendData.isEmpty()) {
        strSendData = strSendData+"\n";
        QByteArray bCmd = strSendData.toLocal8Bit();
//        qDebug() << bCmd;
        pQTcpSocket->write(bCmd);
    }
}

SocketClient::~SocketClient()
{
    pQTcpSocket->close();
}
