// differenceLocations.cpp
// This file holds the coordinates and sizes of the differences per image.
// These coordinates are at 100% image scaling

// Coordinate finder: https://www.mobilefish.com/services/record_mouse_coordinates/record_mouse_coordinates.php
// Solution images in google drive


#include "differenceLocations.h"

// Switch case in main program for enum of names, pulls from correct list in this file

namespace DifferenceLocations {

    // Scale factor for image size (will be used to alter coords for display)
    qreal SCALE_FACTOR = 1.6;

    // ************************* Balloons ************************* //

    QList<QPoint> balloonCoordList = {QPoint(29, 36),
                                      QPoint(205, 114),
                                      QPoint(75, 249),
                                      QPoint(205, 238),
                                      QPoint(305, 237),
                                      QPoint(300, 315),
                                      QPoint(35, 433),
                                      QPoint(330, 434)};

    QList<QSize> balloonSizeList = {QSize(40, 40),
                                    QSize(50, 50),
                                    QSize(40, 40),
                                    QSize(30, 30),
                                    QSize(70, 70),
                                    QSize(60, 60),
                                    QSize(60, 60),
                                    QSize(70, 70)};


    // *********************** Banana Bread *********************** //

    QList<QPoint> bananaCoordList = {QPoint(123, 49),
                                     QPoint(46,95),
                                     QPoint(250,103),
                                     QPoint(124,154),
                                     QPoint(291,166),
                                     QPoint(132,207),
                                     QPoint(249,249),
                                     QPoint(106,412)};

    QList<QSize> bananaSizeList = {QSize(40, 40),
                                   QSize(50, 50),
                                   QSize(40, 40),
                                   QSize(30, 30),
                                   QSize(70, 70),
                                   QSize(60, 60),
                                   QSize(60, 60),
                                   QSize(70, 70)};


    // *************************** Beach ************************** //

    QList<QPoint> beachCoordList = {QPoint(119,108),
                                    QPoint(247,199),
                                    QPoint(315,249),
                                    QPoint(286,334),
                                    QPoint(190,287),
                                    QPoint(46,303),
                                    QPoint(19,391)};

    QList<QSize> beachSizeList = {QSize(40, 40),
                                  QSize(50, 50),
                                  QSize(40, 40),
                                  QSize(30, 30),
                                  QSize(70, 70),
                                  QSize(60, 60),
                                  QSize(60, 60),
                                  QSize(70, 70)};

    // ************************* Cupcakes ************************* //
    QList<QPoint> cupcakesCoordList = {};
    QList<QSize> cupcakesSizeList = {};

    // ************************** Donut *************************** //
    QList<QPoint> donutCoordList = {};
    QList<QSize> donutSizeList = {};


    // *************************** Honey ************************** //
    QList<QPoint> honeyCoordList = {};
    QList<QSize> honeySizeList = {};


    // ************************** Laptop ************************** //
    QList<QPoint> laptopCoordList = {};
    QList<QSize> laptopSizeList = {};


    // ************************** Sushi *************************** //
    QList<QPoint> sushiCoordList = {};
    QList<QSize> sushiSizeList = {};


    // *************************** Twine ************************** //
    QList<QPoint> twineCoordList = {};
    QList<QSize> twineSizeList = {};

    // ************************* Vegetable ************************ //
    QList<QPoint> vegetableCoordList = {};
    QList<QSize> vegetableSizeList = {};

}
