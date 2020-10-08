#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void chong();
    void hui();
    void fan();
    void bai();
    int Win(int x,int y);
    QPushButton qiuhe;
    QPushButton huiqi;
    QPushButton fanhu;
    int fun1(int x,int y);
    int fun2(int x,int y);
    int fun3(int x,int y);
    int fun4(int x,int y);
    int fun11(int x,int y);
    int fun22(int x,int y);
    int fun33(int x,int y);
    int fun44(int x,int y);
    const int SiZE=21;
    int x2,y2;
    int yui=1;
    int sx,sy;
    int qi=9;
    int h3=2;
    int xx1=0,yy1=0;
    int movex,movey;
    int a[22][22];
    int width=10;
    int w1=30;
    int d=1;
    int c=0,v=1;
    int head=1;
signals:
    void win();
    void win1();
    void fanhui();

public slots:
};

#endif // SUBWIDGET_H
