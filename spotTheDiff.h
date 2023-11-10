#ifndef SPOTTHEDIFF_H
#define SPOTTHEDIFF_H

#include <QWidget>
#include <QGraphicsObject>

// Image dimensions
const int IMAGE_WIDTH = 350;
const int IMAGE_HEIGHT = 467;

namespace Ui {
class SpotTheDiff;
}

class SpotTheDiff : public QWidget
{
    Q_OBJECT

public:
    explicit SpotTheDiff(QWidget *parent = nullptr);
    ~SpotTheDiff();

private:
    Ui::SpotTheDiff *ui;

    // Add Image Unit


    void drawPerimeterLines();  // Maybe supply x,y for origin and reuse for each image? or just draw both in one call


signals:
    void homeClicked();
private slots:
    void on_homeButton_clicked();
};

#endif // SPOTTHEDIFF_H
