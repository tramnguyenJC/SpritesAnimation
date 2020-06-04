#include "pencil.h"

#include "brush_factory.h"

Pencil::Pencil(const QString& brush_name) : Brush(brush_name) {}

QRect Pencil::mousePress(QPainter &painter,const QPoint &pos)
{
    return mouseMove(painter, pos, pos);
}

QRect Pencil::mouseMove(QPainter &painter, const QPoint &oldPos,
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

QRect Pencil::mouseRelease(QPainter & /* painter */,
                                     const QPoint & /* pos */)
{
    return QRect(0, 0, 0, 0);
}

REGISTER_TYPE(Pencil)
