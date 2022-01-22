#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFrame fm;
    fm.resize(800, 600);
    fm.setFrameRect(QRect(50, 50, 500, 400));
    fm.setFrameShape(QFrame::Box);
    fm.setFrameShadow(QFrame::Sunken);
    fm.setLineWidth(10);

    fm.show();

    return a.exec();
}
