#ifndef MAINWIDGETS_H
#define MAINWIDGETS_H

#include <QMainWindow>
#include <tab2sokect.h>
#include <tab3controlpannel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidgets; }
QT_END_NAMESPACE

class MainWidgets : public QMainWindow
{
    Q_OBJECT

public:
    MainWidgets(QWidget *parent = nullptr);
    ~MainWidgets();

private:
    Ui::MainWidgets *ui;
    Tab2Sokect *pTab2Soket;
    Tab3ControlPannel * pTab3ControlPannel;
};
#endif // MAINWIDGETS_H
