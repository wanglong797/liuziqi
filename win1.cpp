#include "win1.h"
#include<QPushButton>
win1::win1(QWidget *parent) : QWidget(parent)
{
    g1.setParent(this);
    g1.setText("white win");
    g1.move(25,25);
    setWindowTitle("win");
    resize(50,50);
}
