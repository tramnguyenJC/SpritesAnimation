#include "eraser.h"

#include "brush_factory.h"

Eraser::Eraser(const QString& brush_name) : Brush(brush_name) {}

QRect Eraser::mousePress(QPainter &painter,const QPoint &pos)
{
    return mouseMove(painter, pos, pos);
}

QRect Eraser::mouseMove(QPainter &painter, const QPoint &oldPos,
                        const QPoint &newPos)
{
    painter.save();

    int rad = painter.pen().width() / 2;
    QRect boundingRect = QRect(oldPos, newPos).normalized()
                                              .adjusted(-rad, -rad, +rad, +rad);
    painter.drawLine(oldPos, newPos);
    painter.restore();
    return boundingRect;
}

QRect Eraser::mouseRelease(QPainter & /* painter */,
                                     const QPoint & /* pos */)
{
    return QRect(0, 0, 0, 0);
}

REGISTER_TYPE(Eraser)
