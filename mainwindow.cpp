#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_button_clicked()
{
    close();
}


void MainWindow::on_calc_button_clicked()
{
    float H = ui->Hlabel->text().toFloat();
    float w = ui->omega_edit->text().toFloat();
    float LRMe = ui->le_edit->text().toFloat();
    float lp = ui->pic_edit->text().toFloat();
    float q = ui->q_edit->text().toFloat();
    float delta = ui->delta_edit->text().toFloat();
    float Kf = ui->kf_edit->text().toFloat();
    float Kd = ui->kd_edit->text().toFloat();


    float B = H * tan(w*M_PI/180); ui->BEdit_7->setText(QString::number(B));
    float p = H + 6371; ui->pEdit_9->setText(QString::number(p));
    float T = 2 * M_PI * sqrt(pow(p,3))/sqrt(398600); ui->TEdit_10->setText(QString::number(T));
    float N = 86400 / T; ui->NEdit_12->setText(QString::number(N));
    float i = acos((398600*pow(p,2)*(2*M_PI-86400*0.7292115*pow(10,-4)))/(2*M_PI*2.634*pow(10,10)*N))*180/M_PI;ui->iEdit_13->setText(QString::number(i));
    float Dmin = 0.00000055 * H * 1000 * 1.1 / (2 * 0.3 * LRMe); ui->DminEdit_14->setText(QString::number(Dmin));
    float fekv = 0.734 * Dmin * lp * pow (10,-6)/0.00000055; ui->fekvEdit_11->setText(QString::number(fekv));
    float Dvz = Dmin * q; ui->DvzEdit_17->setText(QString::number(Dvz));
    float d = q * fekv - delta; ui->dEdit_18->setText(QString::number(d));
    float s2 = d * q / (1-q);ui->s2Edit_19->setText(QString::number(s2));
    float fgz = d + s2; ui->frzEdit_15->setText(QString::number(fgz));
    float fvz = (q*fekv*(-delta+q*fekv)) / (delta+fekv*(1-2*q)); ui->fvzEdit_16->setText(QString::number(fvz));
    float rvz = 2 * fvz; ui->rvzEdit_8->setText(QString::number(rvz));
    float rgz = 2 * fgz; ui->rgzEdit_20->setText(QString::number(rgz));
    float m = fekv / fgz; ui->mEdit_21->setText(QString::number(m));
    float d1 = fgz * tan(w*M_PI/180); ui->d1Edit_22->setText(QString::number(d1));
    float d2 = m * d1; ui->d2Edit_23->setText(QString::number(d2));
    float Ltk = fekv * Kf; ui->LtkEdit_24->setText(QString::number(Ltk));
    float Dtk = Dmin * Kd; ui->DtkEdit_25->setText(QString::number(Dtk));
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    int val = ui->verticalSlider->value();
    ui->Hlabel->setText(QString::number(val));
}

