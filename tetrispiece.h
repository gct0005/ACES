#ifndef TETRISPIECE_H
#define TETRISPIECE_H

#include <QWidget>

class TetrisPiece : public QWidget
{
    Q_OBJECT

public:
    TetrisPiece(QWidget *parent = nullptr);
    ~TetrisPiece();
};

#endif // TETRISPIECE_H
