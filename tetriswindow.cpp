#include "tetriswindow.h"

TetrisWindow::TetrisWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 600);
    setWindowTitle("Tetris");
}

TetrisWindow::~TetrisWindow()
{
}
