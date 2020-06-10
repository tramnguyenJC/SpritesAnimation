#include "eraser.h"

#include "components/paint_area.h"

Eraser::Eraser(const QString& brush_name) : Brush(brush_name) {}

QRect Eraser::mousePress(QPainter &painter,const QPoint &pos)
{
    return mouseMove(painter, pos, pos);
}

QRect Eraser::mouseMove(QPainter &painter, const QPoint &oldPos,
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

QRect Eraser::mouseRelease(QPainter & /* painter */,
                                     const QPoint & /* pos */)
{
    return QRect(0, 0, 0, 0);
}

void Eraser::setupPainter(QPainter &painter) {
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    QColor eraser_color(brush_color_);
    painter.setPen(QPen(eraser_color, brush_width_, Qt::SolidLine, Qt::RoundCap,
                   Qt::RoundJoin));
    painter.save();
}
