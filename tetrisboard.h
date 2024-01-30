#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <QWidget>

class TetrisBoard : public QWidget
{
    Q_OBJECT

public:
    TetrisBoard(QWidget *parent = nullptr);
    ~TetrisBoard();
};

#endif // TETRISBOARD_H
