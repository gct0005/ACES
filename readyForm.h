#ifndef READYFORM_H
#define READYFORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class ReadyForm;
}

class ReadyForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReadyForm(QWidget *parent = nullptr);
    ~ReadyForm();

signals:
    void startGame();

private slots:
    void onStartButtonClicked();
    void updateCountdown();

private:
    Ui::ReadyForm *ui;

    QTimer *countdownTimer;
    int countdownValue;
};

#endif // READYFORM_H
