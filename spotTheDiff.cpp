#include "spotTheDiff.h"
#include "ui_spotTheDiff.h"

SpotTheDiff::SpotTheDiff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotTheDiff)
{
    ui->setupUi(this);
}

SpotTheDiff::~SpotTheDiff()
{
    delete ui;
}

void SpotTheDiff::drawPerimeterLines()
{

}

void SpotTheDiff::on_homeButton_clicked()
{
    emit homeClicked();
}
