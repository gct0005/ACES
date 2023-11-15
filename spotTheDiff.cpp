#include "spotTheDiff.h"
#include "ui_spotTheDiff.h"
#include <QRandomGenerator>

SpotTheDiff::SpotTheDiff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotTheDiff)
{
    ui->setupUi(this);

    // Add images
    //imageArray.normalImg
    //ui->imageTile->setPixmap(QPixmap(":/images/balloons.jpg"));
    //ui->imageTile->setPixmap(imageArray.normalImg[0]);
    updateImageTile(imageArray.normalImg[0]);
    updateDiffTile(imageArray.diffImg[0]);
}

SpotTheDiff::~SpotTheDiff()
{
    delete ui;
}

// Updates image tile
void SpotTheDiff::updateImageTile(const QPixmap &pixmap)
{
    ui->imageTile->setPixmap(pixmap.scaled(IMAGE_WIDTH,IMAGE_HEIGHT));
}

// Updates differing image tile
void SpotTheDiff::updateDiffTile(const QPixmap &pixmap)
{
    ui->diffTile->setPixmap(pixmap.scaled(IMAGE_WIDTH,IMAGE_HEIGHT));
}

void SpotTheDiff::on_homeButton_clicked()
{
    emit homeClicked();
}


void SpotTheDiff::on_restartButton_clicked()
{
    int randomValue = QRandomGenerator::global()->bounded(10);
    updateImageTile(imageArray.normalImg[randomValue]);
    updateDiffTile(imageArray.diffImg[randomValue]);
}

