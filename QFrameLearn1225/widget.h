#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

const QFrame::Shape FrameShape[7] = {
    QFrame::NoFrame,
    QFrame::Box,
    QFrame::Panel,
    QFrame::StyledPanel,
    QFrame::HLine,
    QFrame::VLine,
    QFrame::WinPanel
};

const QFrame::Shadow FrameShadow[3] = {
    QFrame::Plain,
    QFrame::Raised,
    QFrame::Sunken
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_m_btn_set_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
