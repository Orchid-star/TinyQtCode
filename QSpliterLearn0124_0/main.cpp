// Code is from《Q5.10完全参考手册》 黄勇

#include "qsplitter.h"
#include "qpushbutton.h"
#include "QVBoxLayout"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QSplitter *ps = new QSplitter(Qt::Vertical);
    QPushButton *pb = new QPushButton("AAA");
    QPushButton *pb1 = new QPushButton("BBB");
    QPushButton *pb2 = new QPushButton("CCC");
    QPushButton *pb3 = new QPushButton("DDD");

    pb1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); //disable size policy
    pb->setMaximumSize(175, 55); //Max and Min do also work
    ps->addWidget(pb);
    ps->addWidget(pb1);
    ps->addWidget(pb2);
    ps->addWidget(pb3);
    //set border of splitter
    ps->setFrameShadow(QFrame::Sunken);
    ps->setFrameShape(QFrame::Box);
    ps->setLineWidth(5);
    //children can't be collapsible
    ps->setChildrenCollapsible(false);
    //adjust size dynamicly
    ps->setOpaqueResize(true);

    ps->setStretchFactor(0, 1);
    ps->setStretchFactor(1, 2);
    ps->setStretchFactor(2, 2);

    ps->setHandleWidth(5);

    ps->setStyleSheet("QSplitter::handle{background-color:blue}");
    QVBoxLayout *pv = new QVBoxLayout;
    pv->addWidget(ps);
    w.setLayout(pv);
    w.resize(180, 200);
    w.show();

    return a.exec();
}
