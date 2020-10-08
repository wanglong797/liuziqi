#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h"
#include"win.h"
#include"win1.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void change();
    void change1();
    void change2();
    void change3();
    void change4();
    void change5();
    void change6();
    QPushButton a1,b1,b2,b3;
    subwidget w;
    win r;
    win1 r1;
};

#endif // WIDGET_H
