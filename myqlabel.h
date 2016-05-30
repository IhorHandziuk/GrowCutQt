#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

class myqlabel : public QLabel
{
    Q_OBJECT
public:

    explicit myqlabel(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void leaveEvent(QMouseEvent* ev);

    int x, y;
    bool pressed;
signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Release();
public slots:
};

#endif // MYQLABEL_H
