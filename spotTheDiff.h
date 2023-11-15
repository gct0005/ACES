#ifndef SPOTTHEDIFF_H
#define SPOTTHEDIFF_H

#include <QWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QPixmap>

// Image dimensions
const int IMAGE_WIDTH = 560;
const int IMAGE_HEIGHT = 747;

const int NUM_IMAGES = 10;

struct coordinates {     // Coordinate structure for holding image difference points
    int x,y;
    int w,h;        // Width and height of difference (for drawing clickable objects)
};

struct images {     // Image structure for images and their different counterparts TODO MAYBE MAKE CONSTANT?
    QPixmap normalImg[NUM_IMAGES] = {QPixmap(":/images/balloons.jpg"),
                                     QPixmap(":/images/bananaBread.jpg"),
                                     QPixmap(":/images/beach.jpg"),
                                     QPixmap(":/images/cupcakes.jpg"),
                                     QPixmap(":/images/donut.jpg"),
                                     QPixmap(":/images/honey.jpg"),
                                     QPixmap(":/images/laptop.jpg"),
                                     QPixmap(":/images/sushi.jpg"),
                                     QPixmap(":/images/twine.jpg"),
                                     QPixmap(":/images/vegetable.jpg")};      // Normal images

    QPixmap diffImg[NUM_IMAGES] = {QPixmap(":/images/balloonsDiff.jpg"),
                                   QPixmap(":/images/bananaBreadDiff.jpg"),
                                   QPixmap(":/images/beachDiff.jpg"),
                                   QPixmap(":/images/cupcakesDiff.jpg"),
                                   QPixmap(":/images/donutDiff.jpg"),
                                   QPixmap(":/images/honeyDiff.jpg"),
                                   QPixmap(":/images/laptopDiff.jpg"),
                                   QPixmap(":/images/sushiDiff.jpg"),
                                   QPixmap(":/images/twineDiff.jpg"),
                                   QPixmap(":/images/vegetableDiff.jpg")};         // Differing image

    // TODO MAKE IMAGES 160% SIZE RESIZE APPLICATION

    coordinates coords[NUM_IMAGES];      // Array of difference placement data
};


namespace Ui {
class SpotTheDiff;
}

class SpotTheDiff : public QWidget
{
    Q_OBJECT

public:
    explicit SpotTheDiff(QWidget *parent = nullptr);
    ~SpotTheDiff();

    void updateImageTile(const QPixmap& pixmap);
    void updateDiffTile(const QPixmap &pixmap);

private:
    Ui::SpotTheDiff *ui;

    // Add Image Unit
    images imageArray;


signals:
    void homeClicked();

private slots:
    void on_homeButton_clicked();

    void on_restartButton_clicked();
};

#endif // SPOTTHEDIFF_H
