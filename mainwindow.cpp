#include "mainwindow.h"
//#include <QInputDialog>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300,500);
    this->setWindowTitle("Solve_Rt_Triangle");

//    QPushButton *btn = ui->setAngleBtn;

    connect(ui->setAngleBtn,&QPushButton::clicked,this,MainWindow::btn_setAngleBtn_pushed);

    setFonts();
    initLabels();

}

double MainWindow::angToRad(double angle)
{
    double b;
    b = angle * PI / 180;
    return b;
}

void MainWindow::initQstrings()
{
    angle_num_str.sprintf("%f",angle);
//    angle_tan_str
}

void MainWindow::initLabels()
{
    ui->angle_num->move(25,25);
    ui->angle_num->resize(100,50);
    ui->angle_num->setFont(ft_num);
    ui->angle_num->setText("Angle:");
    ui->angle_tan->move(25,75);
    ui->angle_tan->setText("tan:");
    ui->angle_tan->resize(100,50);
    ui->angle_tan->setFont(ft_num);
    ui->angle_cot->move(25,125);
    ui->angle_cot->setText("cot:");
    ui->angle_cot->resize(100,50);
    ui->angle_cot->setFont(ft_num);
    ui->angle_sin->move(25,175);
    ui->angle_sin->setText("sin:");
    ui->angle_sin->resize(100,50);
    ui->angle_sin->setFont(ft_num);
    ui->angle_cos->move(25,225);
    ui->angle_cos->setText("cos:");
    ui->angle_cos->resize(100,50);
    ui->angle_cos->setFont(ft_num);
    ui->angle_Val->move(120,25);
    ui->angle_Val->resize(105,50);
    ui->angle_Val->setFont(ft_num);
    ui->angle_Val->setText(angle_num_str.sprintf("%2f",angle));
    ui->tan_Val->move(100,75);
    ui->tan_Val->setText("?");
    ui->tan_Val->resize(125,50);
    ui->tan_Val->setFont(ft_num);
    ui->cot_Val->move(100,125);
    ui->cot_Val->setText("?");
    ui->cot_Val->resize(125,50);
    ui->cot_Val->setFont(ft_num);
    ui->sin_Val->move(100,175);
    ui->sin_Val->setText("?");
    ui->sin_Val->resize(125,50);
    ui->sin_Val->setFont(ft_num);
    ui->cos_Val->move(100,225);
    ui->cos_Val->setText("?");
    ui->cos_Val->resize(125,50);
    ui->cos_Val->setFont(ft_num);

    ui->setAngleBtn->move(230,40);
    ui->setAngleBtn->resize(50,25);
    ui->setAngleBtn->setText("change");
    ui->textBrowser->move(25,300);
    ui->textBrowser->resize(250,150);
}

void MainWindow::setFonts()
{
    ft_num.setBold(1);
    ft_num.setPointSize(20);
    ft_tan.setBold(1);
    ft_tan.setPointSize(20);
    ft_cot.setBold(1);
    ft_cot.setPointSize(20);
    ft_sin.setBold(1);
    ft_sin.setPointSize(20);
    ft_cos.setBold(1);
    ft_cos.setPointSize(20);


}

void MainWindow::setLabels()
{
    ui->angle_Val->setText(angle_num_str.sprintf("%f",angle));
    ui->tan_Val->setText(angle_tan_str.sprintf("%.4f",tan_out));
    ui->cot_Val->setText(angle_cot_str.sprintf("%.4f",cot_out));
    ui->sin_Val->setText(angle_sin_str.sprintf("%.4f",sin_out));
    ui->cos_Val->setText(angle_cos_str.sprintf("%.4f",cos_out));
}

void MainWindow::btn_setAngleBtn_pushed()
{
    bool bOk;
    angle = QInputDialog::getDouble(this,"InputAngle",
                                    "Please input the new angle",
                                    45.0,  //default
                                    0.0,   //min
                                    360.0, //max
                                    2,     //accurate
                                    &bOk
                                    );
    tan_out = tan(angToRad(angle));
    cot_out = 1/tan_out;
    sin_out = sin(angToRad(angle));
    cos_out = cos(angToRad(angle));

    setLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}
