#include "cqasa.h"
#include <QDebug>

CQASA::CQASA(QWidget *p)
    :QAbstractScrollArea(p)
    ,psub(0)
{
    setViewportMargins(22,22,22,22);
    pw1 = new QWidget;
    psh = new QScrollBar;
    psv = new QScrollBar;

    qDebug() << pw1->parent();

    setVerticalScrollBar(psv);
    setHorizontalScrollBar(psh);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setViewport(pw1);

    qDebug() << pw1->parent();

    QPalette p1;
    p1.setColor(QPalette::Background, QColor(1,111,1)); //绿色
    pw1->setAutoFillBackground(1);
    pw1->setPalette(p1);

    QPalette p2;
    p2.setColor(QPalette::Background, QColor(1,1,111)); //蓝色
    setAutoFillBackground(1);
    setPalette(p2);

    psh->setStyleSheet("background-color:rgb(104,104,104);"); //红色
    connect(psh, &QScrollBar::actionTriggered, this, &CQASA::f1);
    connect(psv, &QScrollBar::actionTriggered, this, &CQASA::f1);
}

void CQASA::js()
{
    psv->setPageStep(viewport()->height());
    psh->setPageStep(viewport()->width());
    psv->setRange(0, psub->height() - viewport()->height());
    psh->setRange(0, psub->width() - viewport()->width());
}

void CQASA::add(QWidget *p)
{
    QWidget *pp=viewport();     	//获取视口部件
    p->setParent(pp);    		//把子部件的父部件重新设置为视口部件(即pw1)
    psub=p;
}

bool CQASA::viewportEvent(QEvent *e)
{
    if(psub !=0 && e->type()==QEvent::Resize){ 	//判断是否是QResizeEvent事件
        int hv = horizontalScrollBar()->value();
        int vv = verticalScrollBar()->value();
        //QRect r=psub->rect();
        //rect()不能获取子部件左上角的坐标，需使用geometry()函数。
        //以下代码处理恢复子部件位置时的情况。具体计算原理见图10-16。
        if(psub->height()+psub->geometry().y()<viewport()->height()){
            psub->move(psub->geometry().x(),-vv);
        }  //移动子部件位置
        if(psub->width()+psub->geometry().x()<viewport()->width()){
            psub->move(-hv,psub->geometry().y());
        }
        js();//设置滚动条的滚动范围，此步重要，否则不会显示滚动条。
    }

    return QAbstractScrollArea::viewportEvent(e);
    //viewportEvent结束

}

void CQASA::f1()
{
    psub->move(-psh->value(),-psv->value());
}
