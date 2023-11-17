#include "differenceItem.h"

DifferenceItem::DifferenceItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent)
{
    // This part is so the highlight will occur in both windows cuz pos() is being a pos
    X = x;
    Y = y;
    setBrush(Qt::transparent);
    pen.setColor(Qt::red);
    pen.setWidth(4);
    setPen(pen);
    setAcceptHoverEvents(true);
}

bool DifferenceItem::correspondsTo(const DifferenceItem *other) const
{
    if (!other) {
        return false;  // Invalid pointer
    }

    // Check if positions and sizes match
    return (X == other->X);
}

void DifferenceItem::highlight()
{
    setPen(QPen(Qt::green));
    qDebug() << "highlight";
}

void DifferenceItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setPen(QPen(Qt::green));
    emit differenceClicked();
    qDebug() << "differenceDetected";
    QGraphicsEllipseItem::mousePressEvent(event);
}

void DifferenceItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(QBrush(Qt::yellow));
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void DifferenceItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(Qt::transparent);
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}


