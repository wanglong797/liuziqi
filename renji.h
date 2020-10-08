#ifndef RENJI_H
#define RENJI_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>

class renji : public QWidget
{
    Q_OBJECT
public:
    explicit renji(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent1(int a,int b);
    void mouseMoveEvent(QMouseEvent *e);
    void chong();
    void hui();
    int Win(int x,int y);
    QPushButton qiuhe;
    QPushButton huiqi;
    int fun1(int x,int y);
    int fun2(int x,int y);
    int fun3(int x,int y);
    int fun4(int x,int y);
    const int SiZE=21;
    int x2,y2;
    int sx,sy;
    int qi=9;
    int movex,movey;
    int a[21][21];
    int width=10;
    int w1=30;
    int d=1;
    int c=0,v=1;
signals:
    void win();
    void win1();


public slots:
};

#endif // RENJI_H
