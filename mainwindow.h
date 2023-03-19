#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PI 3.1415926

#include <QMainWindow>
#include <QInputDialog>
#include <QPushButton>
#include <QString>
#include <QFont>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    //QFont
    QFont ft_num;
    QFont ft_tan;
    QFont ft_cot;
    QFont ft_sin;
    QFont ft_cos;
    QFont ft_num_btn;
    QFont ft_tan_btn;
    QFont ft_cot_btn;
    QFont ft_sin_btn;
    QFont ft_cos_btn;


    //变量
    double angle = 45;
    double tan_out;
    double cot_out;
    double sin_out;
    double cos_out;

    QString angle_num_str;
    QString angle_tan_str;
    QString angle_cot_str;
    QString angle_sin_str;
    QString angle_cos_str;


    //函数声明
    double angToRad(double angle);
    void initQstrings();
    void initLabels();
    void setFonts();
    void setLabels();

    //slots
//    void btn_setAngleBtn_pushed();

    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void btn_setAngleBtn_pushed();
};

#endif // MAINWINDOW_H
