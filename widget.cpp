#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    money_ = 0;
    setControl();
}

widget::~widget()
{
    delete ui;
}
void widget::setControl()
{
    ui->lcdNumber->display(money_);
    ui->pbCoffee->setEnabled(money_ >= 100);
    ui->pbTea->setEnabled(money_ >= 150);
    ui->pbCola->setEnabled(money_ >= 200);
}
void widget::on_pb500_clicked()
{
    money_ += 500;
    setControl();
}

void widget::on_pb100_clicked()
{
    money_ += 100;
    setControl();
}

void widget::on_pb50_clicked()
{
    money_ += 50;
    setControl();
}

void widget::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}

void widget::on_pbCoffee_clicked()
{
    money_ -= 100;
    setControl();
}

void widget::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();
}

void widget::on_pbCola_clicked()
{
    money_ -= 200;
    setControl();
}

void widget::on_pbReset_clicked()
{
    int tmp[4];
    for(int i = 0; i<4; i++) tmp[i] = 0;

    int coin=0;
    coin = money_ / 500; tmp[0] = coin; money_ = money_ - 500*coin;
    coin = money_ / 100; tmp[1] = coin; money_ = money_ - 100*coin;
    coin = money_ / 50; tmp[2] = coin; money_ = money_ - 50*coin;
    coin = money_ / 10; tmp[3] = coin; money_ = money_ - 10*coin;

    QString msg = "500: ";
    msg.append(QString::number(tmp[0])+"\n");
    msg.append("100: ");
    msg.append(QString::number(tmp[1])+"\n");
    msg.append("50: ");
    msg.append(QString::number(tmp[2])+"\n");
    msg.append("10: ");
    msg.append(QString::number(tmp[3])+"\n");

    QMessageBox::information(this,"Return",msg,"OK");
    money_ = 0;
    setControl();
}
