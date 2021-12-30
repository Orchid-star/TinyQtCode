#include "widget.h"
#include "cqasa.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    QWidget *pw=new QWidget;   		//容器，这将是滚动区域的子部件
    QLabel *pb=new QLabel;
    pb->setPixmap(QPixmap("D:/timg.jpg"));
    QPushButton *pb1=new QPushButton("AAA");
    QPushButton *pb2=new QPushButton("BBB");
    pb1->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    //布局容器中的内容
    QVBoxLayout *pv=new QVBoxLayout;
    QHBoxLayout *ph=new QHBoxLayout;
    ph->addWidget(pb1);
    ph->addWidget(pb2);
    pv->addWidget(pb);
    pv->addLayout(ph);
    pw->setLayout(pv);
    //设置容器pw的背景色为红色
    QPalette p1;
    p1.setColor(QPalette::Background,QColor(255,1,1));	//红色
    pw->setAutoFillBackground(1);
    pw->setPalette(p1);
    pw->resize(800,500);
    CQASA ps;  					//使用自定义的滚动区域
    ps.add(pw);  				//添加子部件
    ps.show();
    return app.exec();
}
