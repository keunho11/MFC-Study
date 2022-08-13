#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private slots:
    void slotLampOnOff(bool);
    void slotPlugOnOff(bool);
    void slotTab3RecvData(QString);

signals:
    void sigSocketSendData(QString);


private:
    Ui::Tab3ControlPannel *ui;
};

#endif // TAB3CONTROLPANNEL_H
