#include "win.h"
#include<QPushButton>
win::win(QWidget *parent) : QWidget(parent)
{
     g.setParent(this);
     g.setText("black win");
     g.move(25,25);
     setWindowTitle("win");
     resize(50,50);
}
