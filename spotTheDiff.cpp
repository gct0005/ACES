#include "spotTheDiff.h"
#include "ui_spotTheDiff.h"

SpotTheDiff::SpotTheDiff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotTheDiff)
{
    ui->setupUi(this);

    // Setup Ready form for user to start the game
    form = new ReadyForm(this);

    ui->stackedWidget->addWidget(form);
    connect(form, SIGNAL(startGame()), this, SLOT(StartGame()));

    // Set the ready form to be the visible widget
    ui->stackedWidget->setCurrentIndex(1);

//    img selection = getNextImage();
//    updateImages(selection);

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
    imageScene.addPixmap(pixmap.scaled(IMAGE_WIDTH*DifferenceLocations::SCALE_FACTOR,IMAGE_HEIGHT*DifferenceLocations::SCALE_FACTOR));
}

// Updates differing image scene
void SpotTheDiff::updateDiffScene(const QPixmap &pixmap)
{
    diffScene.addPixmap(pixmap.scaled(IMAGE_WIDTH*DifferenceLocations::SCALE_FACTOR,IMAGE_HEIGHT*DifferenceLocations::SCALE_FACTOR));
}

// Gets the next spot the difference image to be displayed
SpotTheDiff::img SpotTheDiff::getNextImage()
{
    //int value = QRandomGenerator::global()->bounded(NUM_IMAGES); TODO change this back
    int value = QRandomGenerator::global()->bounded(3);

    if (imagesRemaining == 0) {
        // Currently reset the images viewed status
        //imagesRemaining = NUM_IMAGES;
        imagesRemaining = 3;

        for (int i = 0; i < 3/*NUM_IMAGES*/; ++i) {
            imageArray.viewed[i] = false;
        }
        // Eventually make the game end
    }

    while (imageArray.viewed[value] == true && imagesRemaining != 0) {
       value = QRandomGenerator::global()->bounded(3);
    }

    imageArray.viewed[value] = true;
    imagesRemaining--;

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


void SpotTheDiff::adjustSceneSizes(qreal scaleFactor)
{
    imageScene.setSceneRect(imageScene.sceneRect().x(), imageScene.sceneRect().y(),
                            IMAGE_WIDTH * scaleFactor, IMAGE_HEIGHT * scaleFactor);
    diffScene.setSceneRect(diffScene.sceneRect().x(), diffScene.sceneRect().y(),
                            IMAGE_WIDTH * scaleFactor, IMAGE_HEIGHT * scaleFactor);

    ui->imageView->setFixedSize(imageScene.width(), imageScene.height());
    ui->diffView->setFixedSize(diffScene.width(), diffScene.height());

    imageScene.update();
    ui->imageView->viewport()->update();
    ui->diffView->viewport()->update();
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

}
