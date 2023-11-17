// differenceLocations.cpp
// This file holds the coordinates and sizes of the differences per image

// Coordinate finder: https://www.mobilefish.com/services/record_mouse_coordinates/record_mouse_coordinates.php
// Solution images in google drive

#include "differenceLocations.h"

namespace DifferenceLocations {

// =================================== BALLOONS =================================== //

    QList<QPoint>    balloonCoordList;
    QList<QSize>     balloonSizeList;

    void initializeBalloonLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in balloon image
        balloonCoordList.append(QPoint(46, 57));
        balloonCoordList.append(QPoint(328, 182));
        balloonCoordList.append(QPoint(120, 398));
        balloonCoordList.append(QPoint(328, 380));
        balloonCoordList.append(QPoint(488, 379));
        balloonCoordList.append(QPoint(480, 504));
        balloonCoordList.append(QPoint(56, 692));
        balloonCoordList.append(QPoint(528, 694));

        // Add size values for difference locations in balloon image
        balloonSizeList.append(QSize(40, 40));
        balloonSizeList.append(QSize(50, 50));
        balloonSizeList.append(QSize(40, 40));
        balloonSizeList.append(QSize(30, 30));
        balloonSizeList.append(QSize(70, 70));
        balloonSizeList.append(QSize(60, 60));
        balloonSizeList.append(QSize(60, 60));
        balloonSizeList.append(QSize(70, 70));

        // Center the coordinates in the circle
        for (int i = 0; i < balloonCoordList.size(); ++i) {
            balloonCoordList[i] = QPoint(balloonCoordList[i].x()-balloonSizeList[i].width()/2,
                                         balloonCoordList[i].y()-balloonSizeList[i].height()/2);
        }

        qDebug() << "Balloon Lists initialized";

    }

// =================================== BANANA =================================== //

    QList<QPoint>    bananaCoordList;
    QList<QSize>     bananaSizeList;

    void initializeBananaLists() {

        // Clear lists for re-use
        bananaCoordList.clear();
        bananaSizeList.clear();

        // Add coordinate values for difference locations in banana image
        bananaCoordList.append(QPoint(210, 68));
        bananaCoordList.append(QPoint(73, 152));
        bananaCoordList.append(QPoint(396, 163));
        bananaCoordList.append(QPoint(464, 264));
        bananaCoordList.append(QPoint(196, 244));
        bananaCoordList.append(QPoint(211, 332));
        bananaCoordList.append(QPoint(398,400));
        bananaCoordList.append(QPoint(169,659));

        // Add size values for difference locations in banana image
        bananaSizeList.append(QSize(50, 50));
        bananaSizeList.append(QSize(30, 30));
        bananaSizeList.append(QSize(50, 50));
        bananaSizeList.append(QSize(50, 50));
        bananaSizeList.append(QSize(50, 50));
        bananaSizeList.append(QSize(30, 30));
        bananaSizeList.append(QSize(50, 50));
        bananaSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < bananaCoordList.size(); ++i) {
            bananaCoordList[i] = QPoint(bananaCoordList[i].x()-bananaSizeList[i].width()/2,
                                         bananaCoordList[i].y()-bananaSizeList[i].height()/2);
        }

        qDebug() << "Banana Lists initialized";

    }

// =================================== BEACH =================================== //

    QList<QPoint>    beachCoordList;
    QList<QSize>     beachSizeList;

    void initializeBeachLists() {

        // Clear lists for re-use
        beachCoordList.clear();
        beachSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint(190,171));
        beachCoordList.append(QPoint(393,318));
        beachCoordList.append(QPoint(502,401));
        beachCoordList.append(QPoint(456,534));
        beachCoordList.append(QPoint(305,456));
        beachCoordList.append(QPoint(73,483));
        beachCoordList.append(QPoint(30,622));

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                        beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== CUPCAKES =================================== //

    QList<QPoint>    cupcakesCoordList;
    QList<QSize>     cupcakesSizeList;

    void initializeCupcakesLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < bananaCoordList.size(); ++i) {
            bananaCoordList[i] = QPoint(bananaCoordList[i].x()-bananaSizeList[i].width()/2,
                                        bananaCoordList[i].y()-bananaSizeList[i].height()/2);
        }

        qDebug() << "Banana Lists initialized";

    }

// =================================== DONUT =================================== //

    QList<QPoint>    donutCoordList;
    QList<QSize>     donutSizeList;

    void initializeDonutLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== HONEY =================================== //

    QList<QPoint>    honeyCoordList;
    QList<QSize>     honeySizeList;

    void initializeHoneyLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== LAPTOP =================================== //

    QList<QPoint>    laptopCoordList;
    QList<QSize>     laptopSizeList;

    void initializeLaptopLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== SUSHI =================================== //

    QList<QPoint>    sushiCoordList;
    QList<QSize>     sushiSizeList;

    void initializeSushiLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== TWINE =================================== //

    QList<QPoint>    twineCoordList;
    QList<QSize>     twineSizeList;

    void initializeTwineLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }

// =================================== VEGETABLE =================================== //

    QList<QPoint>    vegetableCoordList;
    QList<QSize>     vegetableSizeList;

    void initializeVegetableLists() {

        // Clear lists for re-use
        balloonCoordList.clear();
        balloonSizeList.clear();

        // Add coordinate values for difference locations in beach image
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());
        beachCoordList.append(QPoint());

        // Add size values for difference locations in beach image
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(50, 50));
        beachSizeList.append(QSize(30, 30));
        beachSizeList.append(QSize(50, 50));

        // Center the coordinates in the circle
        for (int i = 0; i < beachCoordList.size(); ++i) {
            beachCoordList[i] = QPoint(beachCoordList[i].x()-beachSizeList[i].width()/2,
                                       beachCoordList[i].y()-beachSizeList[i].height()/2);
        }

        qDebug() << "Beach Lists initialized";
    }
}
