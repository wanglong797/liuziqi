#include "subwidget.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPen>
#include<QDebug>
#include<QBrush>
#include<stdlib.h>
#include<time.h>
subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("对战");
    setMouseTracking(true);
    qiuhe.setParent(this);
    qiuhe.setText("重新开始");
    qiuhe.resize(90,60);
    qiuhe.move(800,30);
    huiqi.setParent(this);
    huiqi.setText("悔棋");
    huiqi.resize(90,60);
    huiqi.move(800,290);
    fanhu.setParent(this);
    fanhu.setText("返回主菜单");
    fanhu.resize(90,60);
    fanhu.move(800,590);
    connect(&fanhu,QPushButton::clicked,this,subwidget::fan);
    connect(&qiuhe,QPushButton::clicked,this,subwidget::chong);
    connect(&huiqi,QPushButton::clicked,this,subwidget::hui);
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#B1720c"));
    this->setPalette(palette);
    for(int i=0;i<22;i++)
    {
        for(int j=0;j<22;j++)
            a[i][j]=0;
    }
    resize(1000,800);
}

void subwidget::fan(){
    chong();
    d=1;
     emit fanhui();
}
void subwidget::chong()
{
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++)
            a[i][j]=0;
        d=1;
    }
    update();
}

void subwidget::hui()
{
    a[x2][y2]=0;
    if(d==1)
        d=-1;
    else
        d=1;
}
void subwidget::paintEvent(QPaintEvent *event)
{   sx=12;sy=12;
    QPainter p;
    p.begin(this);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("#EEC085"));
    p.setBrush(brush);
    p.drawRect(sx-5,sy-5,sx+w1*(SiZE-1),sy+w1*(SiZE-1));
    for(int i=0;i<SiZE;i++)
    {
        p.drawLine(sx+w1*i,sy,sx+w1*i,sy+w1*(SiZE-1));
        p.drawLine(sx,sy+w1*i,sx+w1*(SiZE-1),sy+w1*i);
    }
    for(int i=0;i<SiZE;i++)
    {
        for(int j=0;j<SiZE;j++)
        {
            if(a[i][j]==1){
                brush.setColor(Qt::black);
                p.setBrush(brush);
                p.drawEllipse(QPoint(i*w1+sx,j*w1+sy),qi,qi);
            }
            if(a[i][j]==2){
                brush.setColor(Qt::white);
                p.setBrush(brush);
                p.drawEllipse(QPoint(i*w1+sx,j*w1+sy),qi,qi);
            }
        }
    }
    //pen.setColor(QColor(205,201,83));
    if (movex>=0&&movey>=0&&movex<=20&&movey<=20)
        {
            p.setPen(QPen(Qt::red,2,Qt::SolidLine));
            //根据行号列号计算出落子位置
            int centerx = movex*w1+sx;
            int centery = movey*w1+sy;
            p.drawLine(centerx-10,centery-10,centerx-5,centery-10);
            p.drawLine(centerx+5,centery-10,centerx+10,centery-10);
            p.drawLine(centerx-10,centery-10,centerx-10,centery-5);
            p.drawLine(centerx-10,centery+5,centerx-10,centery+10);
            p.drawLine(centerx-10,centery+10,centerx-5,centery+10);
            p.drawLine(centerx+10,centery+10,centerx+5,centery+10);
            p.drawLine(centerx+10,centery+10,centerx+10,centery+5);
            p.drawLine(centerx+10,centery-5,centerx+10,centery-10);
        }
    p.end();
}
void subwidget::mouseMoveEvent(QMouseEvent *e)
{
    float x=e->x();
    float y=e->y();
    if(x>=sx&&x<=sx+w1*SiZE&&y>=sy&&y<=sy+w1*SiZE){
        movex=(x-sx)/w1-int((x-sx)/w1)>0.5?(x-sx)/w1+1:(x-sx)/w1;
        movey=(y-sy)/w1-int((y-sy)/w1)>0.5?(y-sy)/w1+1:(y-sy)/w1;
    }
    update();
}

void subwidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(head==1){
    float x=event->x();int x1=-1,y1=-1,k=0;
    float y=event->y();
    if(x>=sx&&x<=sx+w1*SiZE&&y>=sy&&y<=sy+w1*SiZE){
        x1=(x-sx)/w1-int((x-sx)/w1)>0.5?(x-sx)/w1+1:(x-sx)/w1;
        y1=(y-sy)/w1-int((y-sy)/w1)>0.5?(y-sy)/w1+1:(y-sy)/w1;
    }
    if(subwidget::d==1&&a[x1][y1]==0){
        a[x1][y1]=1;
        k++;}
    if(subwidget::d==-1&&a[x1][y1]==0){
        a[x1][y1]=2;
        k++;}if(k==1){
    if(subwidget::d==1)
        subwidget::d=-1;
    else
        subwidget::d=1;}
    if(fun11(x1,y1)+fun22(x1,y1)+fun33(x1,y1)+fun44(x1,y1)>=2){
        if(a[x1][y1]==1)
            emit win1();
        else
            emit win();
    }
     x2=x1,y2=y1;

    if(Win(x1,y1)){
        if(a[x1][y1]==1)
       emit win();
        if(a[x1][y1]==2)
        emit win1();}
    update();
}
    if(head==2)
    {float x=event->x();int xx=-1,yy=-1;
        float y=event->y();
        if(x>=sx&&x<=sx+w1*SiZE&&y>=sy&&y<=sy+w1*SiZE){
            xx=(x-sx)/w1-int((x-sx)/w1)>0.5?(x-sx)/w1+1:(x-sx)/w1;
            yy=(y-sy)/w1-int((y-sy)/w1)>0.5?(y-sy)/w1+1:(y-sy)/w1;
        }
        a[xx][yy]=1;
        if(Win(xx,yy)&&a[xx][yy]==1){
            emit win();}
        int pN=0;
        int bN=0;
        int eN=0;
        int score[22][22];
        for(int i=1;i<22;i++)
            for(int y=1;y<22;y++)score[i][y]=0;

        for (int ro = 0; ro < 22; ro++)
                for (int co = 0; co < 22; co++)
                {
                    
                    if (ro > 0 && co > 0 &&
                        a[ro][co] == 0)
                    {
                       
                        for (int y = -1; y <= 1; y++)
                            for (int x = -1; x <= 1; x++)
                            {
                                pN = 0;
                                bN = 0;
                                eN = 0;


                                if (!(y == 0 && x == 0))
                                {

                                    for (int i = 1; i <= 5; i++)
                                    {
                                        if (ro + i * y > 0 && ro + i * y < 22 &&
                                            co + i * x > 0 && co + i * x < 22 &&
                                            a[ro + i * y][co + i * x] == 1)
                                        {
                                            pN++;
                                        }
                                        else if (ro + i * y > 0 && ro + i * y < 22 &&
                                                 co + i * x > 0 && co + i * x < 22 &&
                                                 a[ro + i * y][co + i * x] == 0)
                                        {
                                            eN++;
                                            break;
                                        }
                                        else
                                            break;
                                    }

                                    for (int i = 1; i <= 5; i++)
                                    {
                                        if (ro - i * y > 0 && ro - i * y < 22 &&
                                            co - i * x > 0 && co - i * x < 22 &&
                                            a[ro - i * y][co - i * x] == 1)
                                        {
                                            pN++;
                                        }
                                        else if (ro - i * y > 0 && ro - i * y < 22 &&
                                                 co - i * x > 0 && co - i * x < 22 &&
                                                 a[ro - i * y][co - i * x] == 0)
                                        {
                                            eN++;
                                            break;
                                        }
                                        else
                                            break;
                                    }

                                    if (pN == 1)
                                        score[ro][co] += 10;
                                    else if (pN == 2)
                                    {
                                        if (eN == 1)
                                           score[ro][co] += 30;
                                        else if (eN == 2)
                                            score[ro][co] += 40;
                                    }
                                    else if (pN == 3)
                                    {

                                        if (eN == 1)
                                            score[ro][co] += 60;
                                        else if (eN == 2)
                                            score[ro][co] += 110;
                                    }
                                    else if (pN == 4){
                                        if (eN == 1)
                                            score[ro][co] += 1000;
                                        else if (eN == 2)
                                            score[ro][co] += 2000;}
                                    else if(pN == 5)
                                        score[ro][co] += 100000;



                                    eN = 0;


                                    for (int i = 1; i <= 5; i++)
                                    {
                                        if (ro + i * y > 0 && ro + i * y < 22 &&
                                            co + i * x > 0 && co + i * x < 22 &&
                                            a[ro + i * y][co + i * x] == 1)
                                        {
                                            bN++;
                                        }
                                        else if (ro + i * y > 0 && ro + i * y < 22 &&
                                                 co + i * x > 0 && co + i * x < 22 &&
                                                 a[ro +i * y][co + i * x] == 0)
                                        {
                                            eN++;
                                            break;
                                        }
                                        else
                                            break;
                                    }

                                    for (int i = 1; i <= 5; i++)
                                    {
                                        if (ro - i * y > 0 && ro - i * y < 22 &&
                                            co - i * x > 0 && co - i * x < 22 &&
                                            a[ro - i * y][co - i * x] == 2)
                                        {
                                            bN++;
                                        }
                                        else if (ro - i * y > 0 && ro - i * y <22 &&
                                                 co - i * x > 0 && co - i * x < 22&&
                                                 a[ro - i * y][co - i * x] == 0)
                                        {
                                            eN++;
                                            break;
                                        }
                                        else
                                            break;
                                    }

                                    if (bN == 0)
                                        score[ro][co] += 5;
                                    else if (bN == 1)
                                        score[ro][co] += 10;
                                    else if (bN == 2)
                                    {
                                        if (eN == 1)
                                           score[ro][co] += 25;
                                        else if (eN == 2)
                                            score[ro][co] += 50;
                                    }
                                    else if (bN == 3)
                                    {
                                        if (eN == 1)
                                            score[ro][co] += 55;
                                        else if (eN == 2)
                                            score[ro][co] += 100;
                                    }
                                    else if (bN >= 4){
                                        if (eN == 1)
                                            score[ro][co] += 990;
                                        else if (eN == 2)
                                            score[ro][co] += 1990;
                                    }
                                    else if (bN >= 5)
                                           score[ro][co] += 1001000;
                                }
                            }

                    }
                }





        int maxs=0;

        for(int i=1;i<22;i++)
            for(int y=1;y<22;y++)
            {
                if(a[i][y]==0)
                {
                    if(score[i][y]>maxs){maxs=score[i][y];xx=i;yy=y;}
                }
            }
        a[xx][yy]=2;
        if(Win(xx,yy)&&a[xx][yy]==2){
            emit win1();}
        update();

    }
    if(head==3)
    {
        if(yui>0){
        srand((int)time(0));
        int h1=rand()%21,h2=rand()%21;
        a[h1][h2]=1;
        yui--;}

            bai();


            update();


        if(Win(xx1,yy1)&&a[xx1][yy1]==2){
            emit win1();}
        if(Win(xx1,yy1)&&a[xx1][yy1]==1){
            emit win();}
    }

}
void subwidget::bai()
{
    int pN=0;
    int bN=0;
    int eN=0;
    int score[22][22];
    for(int i=1;i<22;i++)
        for(int y=1;y<22;y++)score[i][y]=0;

    for (int ro = 0; ro < 22; ro++)
            for (int co = 0; co < 22; co++)
            {
                if (ro > 0 && co > 0 &&
                    a[ro][co] == 0)
                {

                    for (int y = -1; y <= 1; y++)
                        for (int x = -1; x <= 1; x++)
                        {

                            pN = 0;
                            bN = 0;
                            eN = 0;


                            if (!(y == 0 && x == 0))
                            {



                                for (int i = 1; i <= 5; i++)
                                {
                                    if (ro + i * y > 0 && ro + i * y < 22 &&
                                        co + i * x > 0 && co + i * x < 22 &&
                                        a[ro + i * y][co + i * x] == 1)
                                    {
                                        pN++;
                                    }
                                    else if (ro + i * y > 0 && ro + i * y < 22 &&
                                             co + i * x > 0 && co + i * x < 22 &&
                                             a[ro + i * y][co + i * x] == 0)
                                    {
                                        eN++;
                                        break;
                                    }
                                    else
                                        break;
                                }

                                for (int i = 1; i <= 5; i++)
                                {
                                    if (ro - i * y > 0 && ro - i * y < 22 &&
                                        co - i * x > 0 && co - i * x < 22 &&
                                        a[ro - i * y][co - i * x] == 1)
                                    {
                                        pN++;
                                    }
                                    else if (ro - i * y > 0 && ro - i * y < 22 &&
                                             co - i * x > 0 && co - i * x < 22 &&
                                             a[ro - i * y][co - i * x] == 0)
                                    {
                                        eN++;
                                        break;
                                    }
                                    else
                                        break;
                                }

                                if (pN == 1)
                                    score[ro][co] += 10;
                                else if (pN == 2)
                                {
                                    if (eN == 1)
                                       score[ro][co] += 30;
                                    else if (eN == 2)
                                        score[ro][co] += 40;
                                }
                                else if (pN == 3)
                                {

                                    if (eN == 1)
                                        score[ro][co] += 60;
                                    else if (eN == 2)
                                        score[ro][co] += 110;
                                }
                                else if (pN == 4){
                                    if (eN == 1)
                                        score[ro][co] += 1000;
                                    else if (eN == 2)
                                        score[ro][co] += 2000;}
                                else if(pN == 5)
                                    score[ro][co] += 100000;



                                eN = 0;


                                for (int i = 1; i <= 5; i++)
                                {
                                    if (ro + i * y > 0 && ro + i * y < 22 &&
                                        co + i * x > 0 && co + i * x < 22 &&
                                        a[ro + i * y][co + i * x] == 1)
                                    {
                                        bN++;
                                    }
                                    else if (ro + i * y > 0 && ro + i * y < 22 &&
                                             co + i * x > 0 && co + i * x < 22 &&
                                             a[ro +i * y][co + i * x] == 0)
                                    {
                                        eN++;
                                        break;
                                    }
                                    else
                                        break;
                                }

                                for (int i = 1; i <= 5; i++)
                                {
                                    if (ro - i * y > 0 && ro - i * y < 22 &&
                                        co - i * x > 0 && co - i * x < 22 &&
                                        a[ro - i * y][co - i * x] == 2)
                                    {
                                        bN++;
                                    }
                                    else if (ro - i * y > 0 && ro - i * y <22 &&
                                             co - i * x > 0 && co - i * x < 22&&
                                             a[ro - i * y][co - i * x] == 0)
                                    {
                                        eN++;
                                        break;
                                    }
                                    else
                                        break;
                                }

                                if (bN == 0)
                                    score[ro][co] += 5;
                                else if (bN == 1)
                                    score[ro][co] += 10;
                                else if (bN == 2)
                                {
                                    if (eN == 1)
                                       score[ro][co] += 25;
                                    else if (eN == 2)
                                        score[ro][co] += 50;
                                }
                                else if (bN == 3)
                                {
                                    if (eN == 1)
                                        score[ro][co] += 55;
                                    else if (eN == 2)
                                        score[ro][co] += 100;
                                }
                                else if (bN >= 4){
                                    if (eN == 1)
                                        score[ro][co] += 990;
                                    else if (eN == 2)
                                        score[ro][co] += 1990;
                                }
                                else if (bN >= 5)
                                       score[ro][co] += 1001000;
                            }
                        }

                }
            }





    int maxs=0;
    int xx,yy;
    for(int i=1;i<22;i++)
        for(int y=1;y<22;y++)
        {
            if(a[i][y]==0)
            {
                if(score[i][y]>maxs){maxs=score[i][y];xx=i;yy=y;}
            }
        }
    a[xx][yy]=h3;
    if(h3==1)
        h3=2;
    else if(h3==2)
        h3=1;
    xx1=xx;
    yy1=yy;
}
int subwidget::Win(int x,int y)
{
    return fun1(x,y)||fun2(x,y)||fun3(x,y)||fun4(x,y);
}

int subwidget::fun1(int x,int y)//左右
{
    int tmp=a[x][y];
    int i;
    int c1=0,c2=0;
    for(i=x+1;i>=0&&i<=20;i++)
    {
        if(a[i][y]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1;i>=0&&i<=20;i--)
    {
        if(a[i][y]==tmp)
            c2++;
        else
            break;
    }
    if(c1+c2>=5)
       return 1;
    else
       return 0;
}

int subwidget::fun2(int x,int y)//竖直
{
    int tmp=a[x][y];
    int i;
    int c1=0,c2=0;
    for(i=y+1;i>=0&&i<=20;i++)
    {
        if(a[x][i]==tmp)
            c1++;
        else
            break;
    }

    for(i=y-1;i>=0&&i<=20;i--)
    {
        if(a[x][i]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=5)
       return 1;
    else
       return 0;
}

int subwidget::fun3(int x,int y)//右斜
{
    int tmp=a[x][y];
    int i,j;
    int c1=0,c2=0;
    for(i=x+1,j=y+1;i>=0&&i<=20&&j>=0&&j<=20;i++,j++)
    {
        if(a[i][j]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1,j=y-1;i>=0&&i<=20&&j>=0&&j<=20;i--,j--)
    {
        if(a[i][j]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=5)
       return 1;
    else
       return 0;
}

int subwidget::fun4(int x,int y)//左斜
{
    int tmp=a[x][y];
    int i,j;
    int c1=0,c2=0;
    for(i=x+1,j=y-1;i>=0&&i<=20&&j>=0&&j<=20;i++,j--)
    {
        if(a[i][j]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1,j=y+1;i>=0&&i<=20&&j>=0&&j<=20;i--,j++)
    {
        if(a[i][j]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=5)
       return 1;
    else
       return 0;
}
int subwidget::fun11(int x,int y)//左右
{
    int tmp=a[x][y];
    int i;
    int c1=0,c2=0;
    for(i=x+1;i>=0&&i<=20;i++)
    {
        if(a[i][y]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1;i>=0&&i<=20;i--)
    {
        if(a[i][y]==tmp)
            c2++;
        else
            break;
    }
    if(c1+c2>=3)
       return 1;
    else
       return 0;
}

int subwidget::fun22(int x,int y)//竖直
{
    int tmp=a[x][y];
    int i;
    int c1=0,c2=0;
    for(i=y+1;i>=0&&i<=20;i++)
    {
        if(a[x][i]==tmp)
            c1++;
        else
            break;
    }

    for(i=y-1;i>=0&&i<=20;i--)
    {
        if(a[x][i]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=3)
       return 1;
    else
       return 0;
}

int subwidget::fun33(int x,int y)//右斜
{
    int tmp=a[x][y];
    int i,j;
    int c1=0,c2=0;
    for(i=x+1,j=y+1;i>=0&&i<=20&&j>=0&&j<=20;i++,j++)
    {
        if(a[i][j]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1,j=y-1;i>=0&&i<=20&&j>=0&&j<=20;i--,j--)
    {
        if(a[i][j]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=3)
       return 1;
    else
       return 0;
}

int subwidget::fun44(int x,int y)//左斜
{
    int tmp=a[x][y];
    int i,j;
    int c1=0,c2=0;
    for(i=x+1,j=y-1;i>=0&&i<=20&&j>=0&&j<=20;i++,j--)
    {
        if(a[i][j]==tmp)
            c1++;
        else
            break;
    }

    for(i=x-1,j=y+1;i>=0&&i<=20&&j>=0&&j<=20;i--,j++)
    {
        if(a[i][j]==tmp)
            c2++;
        else
            break;
    }

    if(c1+c2>=3)
       return 1;
    else
       return 0;
}
