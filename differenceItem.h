#ifndef DIFFERENCEITEM_H
#define DIFFERENCEITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

const int PEN_WIDTH = 4;

class DifferenceItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

signals:
    void differenceClicked();

public:
    DifferenceItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    // Function to check if this item corresponds to another
    bool correspondsTo(const DifferenceItem* other) const;

    void highlight();

    qreal X;
    qreal Y;

private:
    QPen pen;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // DIFFERENCEITEM_H
