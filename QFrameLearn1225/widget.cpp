#include "widget.h"
#include "ui_widget.h"
#include "qcombobox.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->m_btn_set->hide();
    on_m_btn_set_clicked();
    connect(ui->m_combo_shape, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::on_m_btn_set_clicked);
    connect(ui->m_combo_shadow, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::on_m_btn_set_clicked);
    connect(ui->m_spb_line_width, QOverload<int>::of(&QSpinBox::valueChanged), this, &Widget::on_m_btn_set_clicked);
    connect(ui->m_spb_midline_width, QOverload<int>::of(&QSpinBox::valueChanged), this, &Widget::on_m_btn_set_clicked);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_m_btn_set_clicked()
{
    QFrame::Shape shape = FrameShape[ui->m_combo_shape->currentIndex()];
    QFrame::Shadow shadow = FrameShadow[ui->m_combo_shadow->currentIndex()];
    int line_width = ui->m_spb_line_width->value();
    int midLine_width = ui->m_spb_midline_width->value();

    ui->frame->setFrameShape(shape);
    ui->frame->setFrameShadow(shadow);
    ui->frame->setLineWidth(line_width);
    ui->frame->setMidLineWidth(midLine_width);
}
