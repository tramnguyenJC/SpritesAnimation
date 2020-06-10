#include "pencil.h"

Pencil::Pencil(const QString& brush_name) : Brush(brush_name) {}

QRect Pencil::mousePress(QPainter &painter,const QPoint &pos)
{
    return mouseMove(painter, pos, pos);
}

QRect Pencil::mouseMove(QPainter &painter, const QPoint &oldPos,
                        const QPoint &newPos)
{
    setupPainter(painter);
    int radius = brush_width_/ 2;
    QRect boundingRect = QRect(oldPos, newPos)
            .normalized().adjusted(-radius, -radius, +radius, +radius);
    painter.drawLine(oldPos, newPos);
    painter.restore();
    return boundingRect;
}

QRect Pencil::mouseRelease(QPainter & /* painter */,
                                     const QPoint & /* pos */)
{
    return QRect(0, 0, 0, 0);
}

void Pencil::setupPainter(QPainter &painter) {
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(brush_color_, brush_width_, Qt::SolidLine, Qt::RoundCap,
                   Qt::RoundJoin));
    painter.save();
}
