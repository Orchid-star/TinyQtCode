#ifndef CQASA_H
#define CQASA_H

#include <QObject>
#include <QAbstractScrollArea>
#include <QScrollBar>
#include <QEvent>

class CQASA : public QAbstractScrollArea
{
    Q_OBJECT
public:
    CQASA(QWidget* p = 0);
    QScrollBar *psh, *psv; // psh, psv
    QWidget* pw1, *psub; //pw1, psub
    void js();
    void add(QWidget *p);
    bool viewportEvent(QEvent *e);
    void f1();
};

#endif // CQASA_H
