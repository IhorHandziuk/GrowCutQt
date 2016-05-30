#include "myqlabel.h"

myqlabel::myqlabel(QWidget* parent) :
    QLabel(parent), pressed(false)
{

}

void myqlabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void myqlabel::mousePressEvent(QMouseEvent *ev)
{
    pressed = true;
    emit Mouse_Pressed();
}

void myqlabel::mouseReleaseEvent(QMouseEvent *ev)
{
     pressed = false;
     emit Mouse_Release();
}

void myqlabel::leaveEvent(QMouseEvent *ev)
{
    pressed = false;
}
