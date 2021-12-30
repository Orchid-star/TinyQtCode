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
    QWidget *pw=new QWidget;   		//�������⽫�ǹ���������Ӳ���
    QLabel *pb=new QLabel;
    pb->setPixmap(QPixmap("D:/timg.jpg"));
    QPushButton *pb1=new QPushButton("AAA");
    QPushButton *pb2=new QPushButton("BBB");
    pb1->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    //���������е�����
    QVBoxLayout *pv=new QVBoxLayout;
    QHBoxLayout *ph=new QHBoxLayout;
    ph->addWidget(pb1);
    ph->addWidget(pb2);
    pv->addWidget(pb);
    pv->addLayout(ph);
    pw->setLayout(pv);
    //��������pw�ı���ɫΪ��ɫ
    QPalette p1;
    p1.setColor(QPalette::Background,QColor(255,1,1));	//��ɫ
    pw->setAutoFillBackground(1);
    pw->setPalette(p1);
    pw->resize(800,500);
    CQASA ps;  					//ʹ���Զ���Ĺ�������
    ps.add(pw);  				//����Ӳ���
    ps.show();
    return app.exec();
}
