#include "texture_brush.h"

#include <QDebug>
#include <QtMath>

TextureBrush::TextureBrush(const QString& brush_name, QString pixmap_path)
    : Brush(brush_name){
    pixmap_ = new QPixmap(pixmap_path);
//    *pixmap_ = pixmap_->scaled(brush_width_, brush_width_,
//                               Qt::IgnoreAspectRatio, Qt::FastTransformation);
    changePixmapColor();
}

QRect TextureBrush::mousePress(QPainter &painter,const QPoint &pos)
{
    return mouseMove(painter, pos, pos);
}

QRect TextureBrush::mouseMove(QPainter &painter, const QPoint &oldPos,
                        const QPoint &newPos)
{
    setupPainter(painter);
    int radius = brush_width_/ 2;
    QRect boundingRect = QRect(oldPos, newPos)
            .normalized().adjusted(-radius, -radius, +radius, +radius);
    drawLine(painter, oldPos, newPos);
    painter.restore();
    return boundingRect;
}

QRect TextureBrush::mouseRelease(QPainter & /* painter */,
                                     const QPoint & /* pos */)
{
    return QRect(0, 0, 0, 0);
}

void TextureBrush::setBrushColor(const QColor& color) {
    brush_color_ = color;
    setColor(brush_color_);
    changePixmapColor();
    this->setTexture(*pixmap_);
}

void TextureBrush::changePixmapColor() {
    QPainter painter_color(pixmap_);
    painter_color.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter_color.fillRect(pixmap_->rect(), color());
    painter_color.end();
}

void TextureBrush::setBrushTransparency(double transparency) {
    brush_transparency_ = transparency;
    brush_color_.setAlphaF(brush_transparency_);
}

void TextureBrush::setBrushWidth(int width) {
    brush_width_ = width;
    *pixmap_ = pixmap_->scaled(brush_width_, brush_width_,
                               Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void TextureBrush::setupPainter(QPainter &painter) {
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
//    this->setTexture(*pixmap_);
//    setColor(brush_color_);
//    painter.setBrush(*this);
//    painter.setPen(QPen(*this, brush_width_));
    painter.save();
}

void TextureBrush::drawLine(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) {
    painter.drawPixmap(QRect(oldPos.x(), oldPos.y(),
                             brush_width_, brush_width_), *pixmap_);
}

//double TextureBrush::distance(const QPoint &from, const QPoint &to) {
//    return qSqrt((from.x() - to.x())*(from.x() - to.x())
//                 + (from.y() - to.y())*(from.y() - to.y()));

//}

//QPoint nextPointWithinDistance(const QPoint& from, double distance) {
//    return QPoint(1,1);
//}
