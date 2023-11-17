#ifndef DIFFERENCELOCATIONS_H
#define DIFFERENCELOCATIONS_H


#include <QList>
#include <QPoint>
#include <QSize>
#include <QDebug>

// Switch case in main program for enum of names, pulls from correct list in this file

namespace DifferenceLocations {

    // Scale factor for image size (will be used to alter coords for display)
    const qreal SCALE_FACTOR = 1.2;

    // Balloons
    // Difference coordinates at 100% scaling

    extern QList<QPoint>    balloonCoordList;
//        = {QPoint(29, 36),
//                                         QPoint(205, 114),
//                                         QPoint(75, 249),
//                                         QPoint(205, 238),
//                                         QPoint(305, 237),
//                                         QPoint(300, 315),
//                                         QPoint(35, 433),
//                                         QPoint(330, 434)};

    extern QList<QSize>     balloonSizeList;
//        = {QSize(40, 40),
//                                        QSize(50, 50),
//                                        QSize(40, 40),
//                                        QSize(30, 30),
//                                        QSize(70, 70),
//                                        QSize(60, 60),
//                                        QSize(60, 60),
//                                        QSize(70, 70)};


    // Change to be just standard init list func for each
    void initializeBalloonLists();

    // Banana Bread
    extern QList<QPoint>    bananaCoordList;
    extern QList<QSize>     bananaSizeList;

    void initializeBananaLists();

    // Beach
    extern QList<QPoint>    beachCoordList;
    extern QList<QSize>     beachSizeList;

    void initializeBeachLists();

    // Cupcakes
    extern QList<QPoint>    cupcakesCoordList;
    extern QList<QSize>     cupcakesSizeList;

    void initializeCupcakesLists();

    // Donut
    extern QList<QPoint>    donutCoordList;
    extern QList<QSize>     donutSizeList;

    void initializeDonutLists();

    // Honey
    extern QList<QPoint>    honeyCoordList;
    extern QList<QSize>     honeySizeList;

    void initializeHoneyLists();

    // Laptop
    extern QList<QPoint>    laptopCoordList;
    extern QList<QSize>     laptopSizeList;

    void initializeLaptopLists();

    // Sushi
    extern QList<QPoint>    sushiCoordList;
    extern QList<QSize>     sushiSizeList;

    void initializeSushiLists();

    // Twine
    extern QList<QPoint>    twineCoordList;
    extern QList<QSize>     twineSizeList;

    void initializeTwineLists();

    // Vegetable
    extern QList<QPoint>    vegetableCoordList;
    extern QList<QSize>     vegetableSizeList;

    void initializeVegetableLists();

    void scalePoints(QList<QPoint> &coordinates, const qreal SCALE_FACTOR);
}
#endif // DIFFERENCELOCATIONS_H
