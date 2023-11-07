#include "ACES.h"
#include "ui_ACES.h"

ACES::ACES(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ACES)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&spotDiffGame);

}

ACES::~ACES()
{
    delete ui;
}


void ACES::on_spotDiffButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(&spotDiffGame);
}

