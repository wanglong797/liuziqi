#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{   resize(400,400);
    a1.setParent(this);
    a1.setText("本地对战");
    a1.move(160,100);
    b1.setParent(this);
    b2.setParent(this);
    b3.setParent(this);
    b1.setText("人人对战");
    b2.setText("人机对战");
    b3.setText("机机对战");
    b1.move(160,100);
    b2.move(160,200);
    b3.move(160,300);
    b1.hide();
    b2.hide();
    b3.hide();
    connect(&w,&subwidget::win1,this,&Widget::change3);
    connect(&w,&subwidget::win,this,&Widget::change2);
    connect(&a1,&QPushButton::clicked,this,&Widget::change1);
    connect(&b1,&QPushButton::clicked,this,&Widget::change);
    connect(&b2,&QPushButton::clicked,this,&Widget::change);
    connect(&b2,&QPushButton::released,this,&Widget::change4);
    connect(&w,&subwidget::fanhui,this,&Widget::change5);
    connect(&b3,&QPushButton::clicked,this,&Widget::change);
    connect(&b3,&QPushButton::released,this,&Widget::change6);
}
void Widget::change5()
{

    show();
    b1.hide();
    b2.hide();
    b3.hide();
    w.hide();
    a1.show();
    r.hide();
    r1.hide();

}
void Widget::change4()
{
    w.head=2;
}
void Widget::change1()
{
    a1.hide();
    b1.show();
    b2.show();
    b3.show();
}
void Widget::change2()
{
    r.show();
}
void Widget::change3()
{
    r1.show();
}
void Widget::change()
{
    w.show();
    hide();
}
void Widget::change6()
{
    w.head=3;

}
Widget::~Widget()
{

}
