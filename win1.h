#ifndef WIN1_H
#define WIN1_H

#include <QWidget>
#include<QPushButton>

class win1 : public QWidget
{
    Q_OBJECT
public:
    explicit win1(QWidget *parent = nullptr);
    QPushButton g1;
signals:

public slots:
};

#endif // WIN1_H
