#include "spotTheDiff.h"
#include "ui_spotTheDiff.h"

SpotTheDiff::SpotTheDiff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotTheDiff)
{
    ui->setupUi(this);

    form = new ReadyForm(this);

    ui->stackedWidget->addWidget(form);
    connect(form, SIGNAL(startGame()), this, SLOT(StartGame()));

    ui->stackedWidget->setCurrentIndex(1);

    // Add images
//    updateImages(Balloons);

//    // Add difference items
//    initializeLists(Balloons);
//    scaleDiffPoints(coords.coordinateList);
//    centerDiffOrigins(coords.coordinateList, coords.sizeList);
//    loadDiffItems();

//    // Connect the scenes for highlighting differences on both sides
//    connectScenes();

    // Install event filters to prevent scrolling on images
    ui->imageView->viewport()->installEventFilter(this);
    ui->diffView->viewport()->installEventFilter(this);
}

SpotTheDiff::~SpotTheDiff()
{
    delete ui;
}

// Updates image scene
void SpotTheDiff::updateImageScene(const QPixmap &pixmap)
{
    imageScene.addPixmap(pixmap.scaled(IMAGE_WIDTH,IMAGE_HEIGHT));
}

// Updates differing image scene
void SpotTheDiff::updateDiffScene(const QPixmap &pixmap)
{
    diffScene.addPixmap(pixmap.scaled(IMAGE_WIDTH,IMAGE_HEIGHT));
}

// Gets the next spot the difference image to be displayed
SpotTheDiff::img SpotTheDiff::getNextImage()
{
    //int value = QRandomGenerator::global()->bounded(NUM_IMAGES); TODO change this back
    int value = QRandomGenerator::global()->bounded(3);
    return static_cast<img>(value);
}

void SpotTheDiff::updateImages(img select)
{
    updateImageScene(imageArray.normalImg[select]);
    updateDiffScene(imageArray.diffImg[select]);

    // Add images to view
    ui->imageView->setScene(&imageScene);
    ui->diffView->setScene(&diffScene);

    qDebug() << "Images updated to " << select;
}

void SpotTheDiff::initializeLists(img select)
{
    // Clear coordinates for fresh difference data
    coords.coordinateList.clear();
    coords.sizeList.clear();

    // Copy difference data to coordinate lists for selected image
    switch(select){

        case Balloons:

            coords.coordinateList = DifferenceLocations::balloonCoordList;
            coords.sizeList = DifferenceLocations::balloonSizeList;
            break;

        case Banana:

            coords.coordinateList = DifferenceLocations::bananaCoordList;
            coords.sizeList = DifferenceLocations::bananaSizeList;
            break;

        case Beach:

            coords.coordinateList = DifferenceLocations::beachCoordList;
            coords.sizeList = DifferenceLocations::beachSizeList;
            break;

        case Cupcakes: //DifferenceLocations::initializeCupckakesLists();
            // copy contents of lists
            break;
        case Donut: //DifferenceLocations::initializeDonutLists();
            // copy contents of lists
            break;
        case Honey: //DifferenceLocations::initializeHoneyLists();
            // copy contents of lists
            break;
        case Laptop: //DifferenceLocations::initializeLaptopLists();
            // copy contents of lists
            break;
        case Sushi: //DifferenceLocations::initializeSushiLists();
            // copy contents of lists
            break;
        case Twine: //DifferenceLocations::initializeTwineLists();
            // copy contents of lists
            break;
        case Vegetable: //DifferenceLocations::initializeVegetableLists();
            // copy contents of lists
            break;
    }

}

void SpotTheDiff::loadDiffItems()
{
    for (int i = 0; i < coords.coordinateList.size(); ++i) {
        QPoint coordData = coords.coordinateList[i];
        QSize sizeData = coords.sizeList[i];

        // Make difference item for each scene
        DifferenceItem *diff1 = new DifferenceItem(coordData.x(),coordData.y(),sizeData.width(),sizeData.height());
        DifferenceItem *diff2 = new DifferenceItem(coordData.x(),coordData.y(),sizeData.width(),sizeData.height());

        // Add to list of difference items
        differenceItems.append(diff1);
        differenceItems.append(diff2);

        // Add items to scenes
        imageScene.addItem(diff1);
        diffScene.addItem(diff2);

        // Debug info
        qDebug() << "X: " << coords.coordinateList[i].x()
                 << ", Y: " << coords.coordinateList[i].y();
    }
}

void SpotTheDiff::removeItems()
{
    // Disconnect Signal-Slot
    for (DifferenceItem* diffItem : differenceItems) {
        disconnect(diffItem, &DifferenceItem::differenceClicked, this, &SpotTheDiff::highlightCorrespondingItem);
    }

    // Clear lists and scenes
    differenceItems.clear();
    imageScene.clear();
    diffScene.clear();

    qDebug() << "GraphicsScenes cleared";
}

void SpotTheDiff::scaleDiffPoints(QList<QPoint> &coordinates)
{
    for (int i = 0; i < coordinates.size(); ++i) {
        coordinates[i] *= DifferenceLocations::SCALE_FACTOR;
    }
}

void SpotTheDiff::centerDiffOrigins(QList<QPoint> &coordinates, const QList<QSize> sizes)
{
    // Center the coordinates in the circle
    for (int i = 0; i < coordinates.size(); ++i) {
        coordinates[i] = QPoint(coordinates[i].x()-sizes[i].width()/2,
                         coordinates[i].y()-sizes[i].height()/2);
    }
}

void SpotTheDiff::connectScenes()
{
    // Iterate through the differenceItems and connect signals
    for (DifferenceItem* diffItem : differenceItems) {
            connect(diffItem, &DifferenceItem::differenceClicked, this, &SpotTheDiff::highlightCorrespondingItem);
    }
}

void SpotTheDiff::highlightCorrespondingItem() {
    // Identify the clicked item
    DifferenceItem* clickedItem = qobject_cast<DifferenceItem*>(sender());

    if (!clickedItem)
            return;

    // Highlight the corresponding item in the other scene
    if (imageScene.items().contains(clickedItem)) {
            // Item is in imageScene, find and highlight in diffScene
            for (QGraphicsItem* item : diffScene.items()) {
                DifferenceItem* diffItem = qgraphicsitem_cast<DifferenceItem*>(item);
                if (diffItem->correspondsTo(clickedItem)) {
                    // Highlight the item in diffScene
                    diffItem->highlight();
                    ui->diffView->viewport()->update();
                    break;
                }
            }
    } else if (diffScene.items().contains(clickedItem)) {
            // Item is in diffScene, find and highlight in imageScene
            for (QGraphicsItem* item : imageScene.items()) {
                DifferenceItem* imageItem = qgraphicsitem_cast<DifferenceItem*>(item);
                if (imageItem->correspondsTo(clickedItem)) {
                    // Highlight the item in imageScene
                    imageItem->highlight();
                    ui->imageView->viewport()->update();
                    break;
                }
            }
    }
}

void SpotTheDiff::StartGame()
{
    //adjustSceneSizes();
    ui->stackedWidget->setCurrentWidget(ui->Game);
    qDebug() << "set widget to game";

    ui->stackedWidget->removeWidget(form);
    delete form;

    removeItems();
    img selection = getNextImage();

    updateImages(selection);
    initializeLists(selection);

    scaleDiffPoints(coords.coordinateList);
    centerDiffOrigins(coords.coordinateList, coords.sizeList);

    loadDiffItems();
    connectScenes();


}

void SpotTheDiff::adjustSceneSizes()
{
    // TODO fix scaling logic for correct appearance and when correct implement in normal operation
//    QScreen *primaryScreen = QApplication::primaryScreen();

//    QRect availableGeometry = primaryScreen->availableGeometry();

//    qreal scale = qMin(availableGeometry.width() / 1300, availableGeometry.height() / 720);
//    qDebug() << "scale = " << scale;

//    QSize newSize(imageScene.width() * scale, imageScene.height() * scale);
//    ui->imageFrame->setFixedSize(newSize);
//    ui->imageView->setFixedSize(newSize);


    // Calculate the scaling factors for both width and height based on the vertical resolution
    int verticalResolution = size().height();
    qreal scaleFactor = static_cast<qreal>(verticalResolution) / imageScene.height();
    qDebug() << scaleFactor;

    imageScene.setSceneRect(imageScene.sceneRect().x(), imageScene.sceneRect().y(),
                            imageScene.width() * scaleFactor, imageScene.height() * scaleFactor);

    ui->imageView->setFixedSize(imageScene.width(), imageScene.height());

    for (DifferenceItem *item : differenceItems) {
            item->setPos(item->pos() * scaleFactor);
    }

    imageScene.update();
    // Apply the scaling factors to the image
    //pixmapItem->setPixmap(originalPixmap.scaled(originalPixmap.size() * scaleFactorX));

    //imageScene.addPixmap(imageArray.normalImg[0].scaled(IMAGE_WIDTH * scaleFactor,IMAGE_HEIGHT * scaleFactor));
}


void SpotTheDiff::on_homeButton_clicked()
{
    emit homeClicked();
    // pause game
}


void SpotTheDiff::on_restartButton_clicked()
{
    //adjustSceneSizes();

    form = new ReadyForm(this);     // TODO make this its own form with selections to replay current or go to new (Maybe add image selection screen?)

    ui->stackedWidget->addWidget(form);
    connect(form, SIGNAL(startGame()), this, SLOT(StartGame()));

    ui->stackedWidget->setCurrentIndex(1);

    removeItems();
    img selection = getNextImage();

    updateImages(selection);
    initializeLists(selection);

    scaleDiffPoints(coords.coordinateList);
    centerDiffOrigins(coords.coordinateList, coords.sizeList);

    loadDiffItems();
    connectScenes();

}
