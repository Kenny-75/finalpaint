#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui { class MainWindow; }
class QPainter;
class QImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private slots:
    void on_actiontamaio_triggered();

    void on_actioncolor_triggered();

    void on_actionborrador_triggered();

    void on_actionlimpiador_triggered();

    void on_actioncirculo_2_triggered();

    void on_actionbote_de_pintura_triggered();

    void on_actionlapiz_triggered();

    void on_actionrectangulo_2_triggered();

    void on_actionlinea_2_triggered();

    void on_actiontipo_de_objeto_triggered();

    void on_actioncurva_2_triggered();

private:
    Ui::MainWindow *ui;
    QPainter *mPainter;
    QImage *mImage;
    QPoint mBegin;
    QPoint mEnd;
    QColor mColor;
    bool mEnabled;
    int mSize;
    int xMove;
    int yMove;
    int xPress;
    int yPress;
    //int xRelease;
    //int yRelease;
    //int pixActuel;
    //int xMax;
    //int yMax;

};
#endif // MAINWINDOW_H
