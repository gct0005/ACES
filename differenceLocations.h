#ifndef DIFFERENCELOCATIONS_H
#define DIFFERENCELOCATIONS_H


#include <QList>
#include <QPoint>
#include <QSize>
#include <QDebug>

// Switch case in main program for enum of names, pulls from correct list in this file

namespace DifferenceLocations {

    // Balloons
    extern QList<QPoint>    balloonCoordList;
    extern QList<QSize>     balloonSizeList;

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
}
#endif // DIFFERENCELOCATIONS_H
