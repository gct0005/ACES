#ifndef SPOTTHEDIFF_H
#define SPOTTHEDIFF_H

#include <QWidget>
#include <QGraphicsObject>

namespace Ui {
class SpotTheDiff;
}

class SpotTheDiff : public QWidget
{
    Q_OBJECT

public:
    explicit SpotTheDiff(QWidget *parent = nullptr);
    ~SpotTheDiff();

private:
    Ui::SpotTheDiff *ui;

    // Add Image Unit


//signals:
    // void homeclicked
};

#endif // SPOTTHEDIFF_H
