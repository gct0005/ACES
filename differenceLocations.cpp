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

    QList<QPoint> balloonCoordList = {QPoint(27, 38),
                                      QPoint(205, 114),
                                      QPoint(75, 249),
                                      QPoint(205, 238),
                                      QPoint(300, 237),
                                      QPoint(300, 315),
                                      QPoint(35, 433),
                                      QPoint(330, 434)};

    QList<QSize> balloonSizeList = {QSize(50, 50),
                                    QSize(60, 60),
                                    QSize(50, 50),
                                    QSize(40, 40),
                                    QSize(80, 80),
                                    QSize(70, 70),
                                    QSize(100, 100),
                                    QSize(100, 100)};


    // *********************** Banana Bread *********************** //

    QList<QPoint> bananaCoordList = {QPoint(133, 44),
                                     QPoint(39,98),
                                     QPoint(250,98),
                                     QPoint(121,150),
                                     QPoint(291,166),
                                     QPoint(137,210),
                                     QPoint(254,254),
                                     QPoint(106,412)};

    QList<QSize> bananaSizeList = {QSize(70, 70),
                                   QSize(70, 70),
                                   QSize(70, 70),
                                   QSize(70, 70),
                                   QSize(60, 60),
                                   QSize(50, 50),
                                   QSize(75, 75),
                                   QSize(70, 70)};


    // *************************** Beach ************************** //

    QList<QPoint> beachCoordList = {QPoint(122,108),
                                    QPoint(247,199),
                                    QPoint(315,249),
                                    QPoint(286,334),
                                    QPoint(190,287),
                                    QPoint(46,303),
                                    QPoint(20,394)};

    QList<QSize> beachSizeList = {QSize(50, 50),
                                  QSize(70, 70),
                                  QSize(70, 70),
                                  QSize(80, 80),
                                  QSize(80, 80),
                                  QSize(60, 60),
                                  QSize(90, 90)};

    // ************************* Cupcakes ************************* //

    QList<QPoint> cupcakesCoordList = {QPoint(168,83),
                                       QPoint(302,56),
                                       QPoint(174,171),
                                       QPoint(66,330),
                                       QPoint(170,325),
                                       QPoint(316,292),
                                       QPoint(311,426)};

    QList<QSize> cupcakesSizeList = {QSize(60, 60),
                                     QSize(100, 100),
                                     QSize(130, 130),
                                     QSize(60, 60),
                                     QSize(120, 120),
                                     QSize(180, 180),
                                     QSize(100, 100)};

    // ************************** Donut *************************** //

    QList<QPoint> donutCoordList = {QPoint(287,64),
                                    QPoint(294,133),
                                    QPoint(112,153),
                                    QPoint(233,324),
                                    QPoint(132,383),
                                    QPoint(148,455),
                                    QPoint(243,426),
                                    QPoint(296,490)};

    QList<QSize> donutSizeList = {QSize(70, 70),
                                  QSize(60, 60),
                                  QSize(40, 40),
                                  QSize(40, 40),
                                  QSize(40, 40),
                                  QSize(70, 70),
                                  QSize(60, 60),
                                  QSize(240, 240)};


    // *************************** Honey ************************** //

    QList<QPoint> honeyCoordList = {QPoint(86,189),
                                    QPoint(174,175),
                                    QPoint(307,277),
                                    QPoint(35,314),
                                    QPoint(125,404),
                                    QPoint(270,389)};

    QList<QSize> honeySizeList = {QSize(60, 60),
                                  QSize(60, 60),
                                  QSize(55, 55),
                                  QSize(60, 60),
                                  QSize(60, 60),
                                  QSize(60, 60)};


    // ************************** Laptop ************************** //

    QList<QPoint> laptopCoordList = {QPoint(38,126),
                                     QPoint(167,135),
                                     QPoint(295,241),
                                     QPoint(148,264),
                                     QPoint(131,443)};

    QList<QSize> laptopSizeList = {QSize(160, 160),
                                   QSize(50, 50),
                                   QSize(80, 80),
                                   QSize(70, 70),
                                   QSize(85, 85)};


    // ************************** Sushi *************************** //

    QList<QPoint> sushiCoordList = {QPoint(226,10),
                                    QPoint(160,45),
                                    QPoint(102,151),
                                    QPoint(38,192),
                                    QPoint(26,230),
                                    QPoint(32,300),
                                    QPoint(215,346),
                                    QPoint(342,339),
                                    QPoint(142,465)};

    QList<QSize> sushiSizeList = {QSize(110, 110),
                                  QSize(90, 90),
                                  QSize(100, 100),
                                  QSize(70, 70),
                                  QSize(110, 110),
                                  QSize(160, 160),
                                  QSize(140, 140),
                                  QSize(130, 130),
                                  QSize(140, 140)};


    // *************************** Twine ************************** //

    QList<QPoint> twineCoordList = {QPoint(44,1),
                                    QPoint(272,9),
                                    QPoint(103,87),
                                    QPoint(83,211),
                                    QPoint(142,206),
                                    QPoint(18,362),
                                    QPoint(191,352),
                                    QPoint(259,336)};

    QList<QSize> twineSizeList = {QSize(180, 180),
                                  QSize(70, 70),
                                  QSize(70, 70),
                                  QSize(110, 110),
                                  QSize(110, 110),
                                  QSize(80, 80),
                                  QSize(80, 80),
                                  QSize(170, 170)};

    // ************************* Vegetable ************************ //

    QList<QPoint> vegetableCoordList = {QPoint(63,67),
                                        QPoint(118,87),
                                        QPoint(173,148),
                                        QPoint(215,127),
                                        QPoint(330,156),
                                        QPoint(276,214),
                                        QPoint(167,338)};

    QList<QSize> vegetableSizeList = {QSize(90, 90),
                                      QSize(80, 80),
                                      QSize(70, 70),
                                      QSize(70, 70),
                                      QSize(110, 110),
                                      QSize(100, 100),
                                      QSize(80, 80)};

}
