#include "growcutwindow.h"
#include "ui_growcutwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "ImageConverter.h"
#include <string>
#include "myqlabel.h"

GrowCutWindow::GrowCutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrowCutWindow)
{
    ui->setupUi(this);
    connect(ui->pictureLabel, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
}

GrowCutWindow::~GrowCutWindow()
{
    delete ui;
}

void GrowCutWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open image"),
                "",
                "All (*.*)"
                );

    QPixmap pix(filename);

    int w = ui->pictureLabel->width();
    int h = ui->pictureLabel->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    QPixmap newpix = pix.scaled(w,h,Qt::KeepAspectRatio);

    ui->pictureLabel->setPixmap(newpix);

    img = newpix.toImage();
    Matrix<float3> imageMatrix = ImageConverter::getMatrix(img);
    automata.setField(imageMatrix);
}


void GrowCutWindow::on_runPushButton_clicked()
{
    automata.iterate();
    ImageConverter::saveImage(automata.getField(), img);
    QPixmap temp = QPixmap::fromImage(img);
    ui->pictureLabel->setPixmap(temp);
}


void GrowCutWindow::Mouse_current_pos()
{
    if (ui->pictureLabel->pressed)
    {
        if (ui->objectRadioButton->isChecked())
             automata.setCell(ui->pictureLabel->x , ui->pictureLabel->y , object, 0.9f);
        else automata.setCell(ui->pictureLabel->x , ui->pictureLabel->y , background, 0.9f);
    }
}


void GrowCutWindow::on_actionSave_triggered()
{
    img.save("picture.jpg");
}
