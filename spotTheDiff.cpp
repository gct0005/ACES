#include "spotTheDiff.h"
#include "ui_spotTheDiff.h"

SpotTheDiff::SpotTheDiff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpotTheDiff)
{
    ui->setupUi(this);

    // Add images
    updateImages(Balloons);

    // Add difference items
    initializeLists(Balloons);
    loadDiffItems();

    // Connect the scenes for highlighting differences on both sides
    connectScenes();

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

void SpotTheDiff::initializeLists(img select)
{
    // Clear coordinates for fresh difference data
    coords.coordinateList.clear();
    coords.sizeList.clear();

    // Copy difference data to coordinate lists for selected image
    switch(select){

        case Balloons:

        DifferenceLocations::initializeBalloonLists();
            coords.coordinateList = DifferenceLocations::balloonCoordList;
            coords.sizeList = DifferenceLocations::balloonSizeList;
            break;

        case Banana:

            DifferenceLocations::initializeBananaLists();
            coords.coordinateList = DifferenceLocations::bananaCoordList;
            coords.sizeList = DifferenceLocations::bananaSizeList;
            break;

        case Beach:

            DifferenceLocations::initializeBeachLists();
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


void SpotTheDiff::on_homeButton_clicked()
{
    emit homeClicked();
}


void SpotTheDiff::on_restartButton_clicked()
{
    removeItems();
    img selection = getNextImage();

    updateImages(selection);
    initializeLists(selection);
    loadDiffItems();
    connectScenes();

}
