//#include "widget.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
   QLabel* hello = new QLabel("Hello World!", 0); // 0: 최상위 위젯
    hello->show();
    return a.exec();
}
