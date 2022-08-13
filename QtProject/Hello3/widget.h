#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
  //  QLabel *hello;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
