#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>

#define DEFAULT_COLOR 5
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mImage = new QImage(QApplication::desktop()->size(),
                        QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::white);
    mSize = DEFAULT_COLOR;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPainter;
    delete mImage;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(mImage->rect(),Qt::white);
    painter.drawImage(0,0,*mImage);
    e->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    xPress = e->pos().x();
    yPress = e->pos().y();
    mEnabled = true;
    mBegin = e->pos();

    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    xMove = e->pos().x();
    yMove = e->pos().y();
    if (!mEnabled){
    e->accept();
    return;
    }
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mEnd=e->pos();
    mPainter->setPen(pen);
    mPainter->drawLine(mBegin,mEnd);
    mBegin = mEnd;
    update();
    e->accept();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled = false;
    e->accept();
}

void MainWindow::on_actiontamaio_triggered()
{
   mSize = QInputDialog::getInt(this, "tamaño de lapiz","ingrese tamaño",5,1);
}

void MainWindow::on_actioncolor_triggered()
{
   mColor = QColorDialog::getColor(Qt::black, this, "color de lapiz");
}

void MainWindow::on_actionborrador_triggered()
{
   mColor = QColor(Qt::white);
   mSize = QInputDialog::getInt(this, "tamaño de borrador","ingrese tamaño de borrador",5,1);
}

void MainWindow::on_actionlimpiador_triggered()
{
    mImage = new QImage(QApplication::desktop()->size(),
                        QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    update();
}

void MainWindow::on_actioncirculo_2_triggered()
{
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mPainter->setPen(pen);
    mPainter->drawEllipse(xPress,yPress,xMove-xPress,yMove-yPress);
    update();
}

void MainWindow::on_actionbote_de_pintura_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "elija un color");
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(5000);
    mPainter->setPen(pen);
    mPainter->drawRect(1,1,1,1);
    update();
}

void MainWindow::on_actionlapiz_triggered()
{
    mColor = QColor(Qt::black);
    mSize = 5;
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
}

void MainWindow::on_actionrectangulo_2_triggered()
{
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mPainter->setPen(pen);
    mPainter->drawRect(xPress,yPress,xMove-xPress,yMove-yPress);
    update();
}

void MainWindow::on_actionlinea_2_triggered()
{
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mPainter->setPen(pen);
    mPainter->drawLine(xPress,yPress,xMove,yMove);
    update();
}

void MainWindow::on_actiontipo_de_objeto_triggered()
{

}

void MainWindow::on_actioncurva_2_triggered()
{
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mPainter->setPen(pen);
    mPainter->drawLine(xPress,yPress,xMove,yMove);
    update();
}
