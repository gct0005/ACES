#include "readyForm.h"
#include "ui_readyForm.h"

ReadyForm::ReadyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadyForm)
{
    ui->setupUi(this);
    ui->countdownFrame->hide();

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));

    // Set up countdown timer
    countdownTimer = new QTimer(this);
    connect(countdownTimer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
}

ReadyForm::~ReadyForm()
{
    delete ui;
}

void ReadyForm::onStartButtonClicked()
{
    qDebug() << "Start button clicked";
    ui->countdownFrame->show();     // Show the countdown timer

    countdownValue = 3;
    //countdownTimer->start(1000);    // 1 second interval
    countdownTimer->start(50); // faster for development
    ui->countdownLabel->setText(QString::number(countdownValue));
    qDebug() << "Countdown started";
}

void ReadyForm::updateCountdown()
{
    qDebug() << "Updating countdown";

    // Decrease the countdown value
    countdownValue--;

    // Update the countdown label
    ui->countdownLabel->setText(QString::number(countdownValue));

    // If countdown is done, switch to the game screen
    if (countdownValue < 0) {
        countdownTimer->stop();
        emit startGame();
        qDebug() << "start game";
    }

}

