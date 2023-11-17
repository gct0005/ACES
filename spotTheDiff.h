#ifndef SPOTTHEDIFF_H
#define SPOTTHEDIFF_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPoint>
#include <QList>
#include <QRandomGenerator>
#include <QSize>
#include <QVector>
#include <QWheelEvent>
#include "differenceLocations.h"
#include "differenceItem.h"

// Image dimensions
const int IMAGE_WIDTH = 560;
const int IMAGE_HEIGHT = 747;

const int NUM_IMAGES = 10;

namespace Ui {
class SpotTheDiff;
}

class SpotTheDiff : public QWidget
{
    Q_OBJECT

public:

    enum img {
        Balloons = 0,
        Banana,
        Beach,
        Cupcakes,
        Donut,
        Honey,
        Laptop,
        Sushi,
        Twine,
        Vegetable
    };
    Q_ENUM(img)

    struct coordinates {     // Coordinate structure for holding image difference points
        QList<QPoint> coordinateList;   // List of difference coordinates per image
        QList<QSize> sizeList;          // Width and height of difference (for drawing clickable objects)
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

        bool viewed[NUM_IMAGES] = {false};
    };


    explicit SpotTheDiff(QWidget *parent = nullptr);
    ~SpotTheDiff();

    void updateImageScene(const QPixmap& pixmap);
    void updateDiffScene(const QPixmap &pixmap);

    img getNextImage();     // Selects the next image and returns enum for use in other methods
    void updateImages(img select);      // calls updateScenes with the pixmaps based on getnextimage

    void loadDiffItems();
    void removeItems();
    void initializeLists(img select);
    void connectScenes();
    void highlightCorrespondingItem();

    void advanceDifferencesDisplay();
    void advanceTimerDisplay();

    void displayStartCountdown();
    void startGame();
    void endGame();

private:
    Ui::SpotTheDiff *ui;

    // Add Image Unit
    images imageArray;
    img select; // selection variable for initlists func
    coordinates coords;     // list of difference placements

    QGraphicsScene imageScene;
    QGraphicsScene diffScene;

    QVector<DifferenceItem*> differenceItems;   // Dynamic vector for allocating differenceItems unique to each image

protected:
    bool eventFilter(QObject* obj, QEvent* event) override {
        if (event->type() == QEvent::Wheel) {
            // Ignore the wheel event to prevent scrolling
            qDebug() << "Wheel event filtered";
            event->ignore();
            return true;
        }

        // Let the base class handle other events
        return QWidget::eventFilter(obj, event);
    }

signals:
    void homeClicked();

private slots:
    void on_homeButton_clicked();

    void on_restartButton_clicked();

    //void customWheelEvent(QWheelEvent* event);
};

#endif // SPOTTHEDIFF_H
