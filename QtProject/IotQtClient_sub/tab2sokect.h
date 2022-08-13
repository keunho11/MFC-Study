#ifndef TAB2SOKECT_H
#define TAB2SOKECT_H

#include <QWidget>
#include <QTime>
#include <QDebug>

#include "socketclient.h"

namespace Ui {
class Tab2Sokect;
}

class Tab2Sokect : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2Sokect(QWidget *parent = nullptr);
    ~Tab2Sokect();

private:
    Ui::Tab2Sokect *ui; //기본으로 있었음
    SocketClient* pSocketClient;

private slots:
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);
    void slotSocketSendData();

    void slotSocketSendData(QString);
signals:
    void sigSocketRecv(QString);
    void sigTab3RecvData(QString);
    void sigTab4RecvData(QString);
    void sigTab5RecvData(QString);
    void sigTab6RecvData(QString);
};

#endif // TAB2SOKECT_H
