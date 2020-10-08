#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include<QPushButton>
class win : public QWidget
{
    Q_OBJECT
public:
    explicit win(QWidget *parent = nullptr);
    QPushButton g;


signals:

public slots:
};

#endif // WIN_H
