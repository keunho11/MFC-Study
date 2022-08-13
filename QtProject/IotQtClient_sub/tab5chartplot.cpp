#include "tab5chartplot.h"
#include "ui_tab5chartplot.h"

Tab5ChartPlot::Tab5ChartPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab5ChartPlot)
{
    ui->setupUi(this);


    pIlluLine = new QLineSeries(this);
    pIlluLine->setName("조도");
    pTempLine = new QLineSeries(this);
    pTempLine->setName("온도");
    pHumiLine = new QLineSeries(this);
    pHumiLine->setName("습도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    pIlluLine->setPen(pen);
    pen.setBrush(Qt::blue);
    pTempLine->setPen(pen);
    pen.setBrush(Qt::green);
    pHumiLine->setPen(pen); //set line style

    chart = new QChart();
    chart->addSeries(pIlluLine);
    chart->addSeries(pTempLine);
    chart->addSeries(pHumiLine);
    chart->createDefaultAxes(); //좌표값 추가
    chart->axes(Qt::Vertical).first()->setRange(0,100);
    //chart->axes(Qt::Horizontal).first()->setRange(0,20);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pChartHLayout->layout()->addWidget(chartView);

    axisX = new QDateTimeAxis;
    axisX->setFormat("h:mm");
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    firstDate.setDate(date);
    firstDate.setTime(time);
    chartView->chart()->setAxisX(axisX, pIlluLine);
    chartView->chart()->setAxisX(axisX, pTempLine);
    chartView->chart()->setAxisX(axisX, pHumiLine);

    QTime tempTime = time.addSecs(600);
    lastDate.setDate(date);
    lastDate.setTime(tempTime);
    axisX->setRange(firstDate,lastDate);



    //connect
    connect(ui->pPBClearButton, SIGNAL(clicked()), this, SLOT(chartPlotClear()));
    connect(ui->pPBAddButton, SIGNAL(clicked()), this, SLOT(chartPlotAdd()));
}

Tab5ChartPlot::~Tab5ChartPlot()
{
    delete ui;
}

void Tab5ChartPlot::chartPlotClear()
{
    pIlluLine->clear();
}

void Tab5ChartPlot::chartPlotAdd()
{
//    double x,y;
//    x = ui->pLExPosition->text().toDouble();
//    y = ui->pLEyPosition->text().toDouble();
    pIlluLine->append(ui->pLExPosition->text().toDouble(),ui->pLEyPosition->text().toDouble());
    ui->pLExPosition->clear();
    ui->pLEyPosition->clear();
}

void Tab5ChartPlot::slotTab5RecvData(QString recvData)
{
   // qDebug()  << recvData;
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

    recvData.replace("[", "@");
    recvData.replace("]", "@");
    QStringList qlist = recvData.split("@");

    pIlluLine->append(xValue.toMSecsSinceEpoch() ,qlist[3].toDouble());
    pTempLine->append(xValue.toMSecsSinceEpoch() ,qlist[4].toDouble());
    pHumiLine->append(xValue.toMSecsSinceEpoch() ,qlist[5].toDouble());
}
