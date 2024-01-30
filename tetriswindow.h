#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QWidget>

class TetrisWindow : public QWidget
{
    Q_OBJECT

public:
    TetrisWindow(QWidget *parent = nullptr);
    ~TetrisWindow();
};

#endif // TETRISWINDOW_H
