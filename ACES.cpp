#include "ACES.h"
#include "ui_ACES.h"

ACES::ACES(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ACES)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(WIDTH, HEIGHT));;

    spotDiffGame = new SpotTheDiff(this);

    ui->stackedWidget->addWidget(spotDiffGame);
    connect(spotDiffGame, SIGNAL(homeClicked()), this, SLOT(moveHome()));
}

ACES::~ACES()
{
    delete spotDiffGame;
    delete ui;
}


void ACES::on_spotDiffButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // start game method call here

}

void ACES::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

