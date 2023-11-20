// differenceLocations.h
// This file holds the coordinates and sizes of the differences per image.
// These coordinates are at 100% image scaling

// Coordinate finder: https://www.mobilefish.com/services/record_mouse_coordinates/record_mouse_coordinates.php
// Solution images in google drive

#ifndef DIFFERENCELOCATIONS_H
#define DIFFERENCELOCATIONS_H


#include <QList>
#include <QPoint>
#include <QSize>
#include <QDebug>

// Switch case in main program for enum of names, pulls from correct list in this file

namespace DifferenceLocations {

    // Scale factor for image size (will be used to alter coords for display)
    extern const qreal SCALE_FACTOR;

    // ************************* Balloons ************************* //

    extern QList<QPoint> balloonCoordList;
    extern QList<QSize>  balloonSizeList;


    // *********************** Banana Bread *********************** //

    extern QList<QPoint> bananaCoordList;
    extern QList<QSize>  bananaSizeList;


    // *************************** Beach ************************** //

    extern QList<QPoint> beachCoordList;
    extern QList<QSize>  beachSizeList;

    // ************************* Cupcakes ************************* //
    extern QList<QPoint> cupcakesCoordList;
    extern QList<QSize>  cupcakesSizeList;

    // ************************** Donut *************************** //
    extern QList<QPoint> donutCoordList;
    extern QList<QSize>  donutSizeList;


    // *************************** Honey ************************** //
    extern QList<QPoint> honeyCoordList;
    extern QList<QSize>  honeySizeList;


    // ************************** Laptop ************************** //
    extern QList<QPoint> laptopCoordList;
    extern QList<QSize>  laptopSizeList;


    // ************************** Sushi *************************** //
    extern QList<QPoint> sushiCoordList;
    extern QList<QSize>  sushiSizeList;


    // *************************** Twine ************************** //
    extern QList<QPoint> twineCoordList;
    extern QList<QSize>  twineSizeList;

    // ************************* Vegetable ************************ //
    extern QList<QPoint> vegetableCoordList;
    extern QList<QSize>  vegetableSizeList;


}
#endif // DIFFERENCELOCATIONS_H
