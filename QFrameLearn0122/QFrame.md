# QFrame

## 1 概述

QFrame类是带有边框的部件的基类，可以实现边框的不同效果。

Qt中一般把矩形部件的边界线叫做边框。

## 2 注意点

- **属性frameShape**

   ```c++
   //接口函数
   setFrameShape(QFrame::Shape);
   
   enum QFarme::Shape
   {
       QFrame::Noframe,
       QFrame::Box,
       QFrame::Panel,
       QFrame::StyledPanel,
       QFrame::HLine,
       QFrame::VLine,
       QFrame::WinPanel
   }
   ```

   QFrame::Noframe表示无边框，其余均表示有边框，区别在于样式以及Shadow属性作用效果的不同。QFrame大致可以理解为包含2个部分，分别是边框和内容。

   <img src="C:\Users\hww\AppData\Roaming\Typora\typora-user-images\image-20220122152547132.png" alt="image-20220122152547132" style="zoom:50%;" />

   - 设置QFrame::Box表示frameShadow设置的凸起或凹陷的效果是针对边框的
   - 设置QFrame::Pane表示frameShadow设置的凸起或凹陷的效果是针对内容的

- **属性frameShadow**

   ```c++
   setFrameShadow(QFrame::Shadow);
   
   enum QFrame::Shadow
   {
       QFrame::Plain,
       QFrame::Raised,
       QFrame::Sunken
   }
   ```

- **属性lineWidth**

   ```c++
   setLineWidth(int);
   ```

- **关于frameRect属性**

   QFrame首先是一个窗口，但是对于QFrame常说的边框，与这个窗口的边界并不是一个概念。QFrame本质上是在一个QWidget内部绘制了一块矩形区域，该区域的边界才是通常说的QFrame的边框。该区域通过接口setFrameRect(QRect)进行设置。只不过通常情况下该区域刚好覆盖整个QFrame，所以看起来QFrame的边框就在QFrame的边界



## 3 示例代码

```c++
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFrame fm;
    fm.resize(800, 600);
    fm.setFrameRect(QRect(50, 50, 500, 400));
    fm.setFrameShape(QFrame::Box); //凹陷或凸起效果针对边框
    fm.setFrameShadow(QFrame::Sunken);
    fm.setLineWidth(10);

    fm.show();

    return a.exec();
}
```

效果图：

<img src="C:\Users\hww\AppData\Roaming\Typora\typora-user-images\image-20220122152842473.png" alt="image-20220122152842473" style="zoom:50%;" />

