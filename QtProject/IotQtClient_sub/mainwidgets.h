#ifndef MAINWIDGETS_H
#define MAINWIDGETS_H

#include <QMainWindow>
#include <tab2sokect.h>
#include <tab3controlpannel.h>
#include <tab4sensordisplay.h>
#include <tab5chartplot.h>
#include <tab6database.h>

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
    Tab4SensorDisplay * pTab4SensorDisplay;
    Tab5ChartPlot * pTab5ChartPlot;
    Tab6Database * pTab6Database;
};
#endif // MAINWIDGETS_H
