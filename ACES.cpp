#include "ACES.h"
#include "ui_ACES.h"

ACES::ACES(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ACES)
{
    ui->setupUi(this);
}

ACES::~ACES()
{
    delete ui;
}

