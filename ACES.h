#ifndef ACES_H
#define ACES_H

#include <QWidget>
#include "spotTheDiff.h"

// Window WxH
const int WIDTH = 800;
const int HEIGHT = 600;

QT_BEGIN_NAMESPACE
namespace Ui { class ACES; }
QT_END_NAMESPACE

class ACES : public QWidget
{
    Q_OBJECT

public:
    ACES(QWidget *parent = nullptr);
    ~ACES();

private slots:
    void on_spotDiffButton_clicked();
    void moveHome();

private:
    Ui::ACES *ui;

    SpotTheDiff spotDiffGame;
};
#endif // ACES_H