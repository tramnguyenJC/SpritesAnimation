#include "brushes/brush.h"
#include "paint_area.h"

#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

#include <QBitmap>

class QPalette;
QRgb PaintArea::background_alpha_color_ = qRgba(255,255,255,0);
QRgb PaintArea::background_color_ = qRgb(255,255,255);

PaintArea::PaintArea(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    this->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding);
    image_ = {500, 400, DEFAULT_IMAGE_FORMAT};
    image_.fill(background_alpha_color_);
}

bool PaintArea::openImage(const QString &file_name)
{
    QImage image;
    if (!image.load(file_name))
        return false;

    setImage(image);
    return true;
}

bool PaintArea::saveImage(const QString &file_name, const char *file_format)
{
    return image_.save(file_name, file_format);
}

void PaintArea::setImage(const QImage &image)
{
    image_ = image.convertToFormat(QImage::Format_ARGB32);
    update();
    updateGeometry();
}

void PaintArea::resizePaintArea(const QSize &newSize) {
    this->resize(newSize);
    resizeImage(newSize);
}

void PaintArea::resizeImage(const QSize &newSize)
{
    if (image_.size() == newSize)
        return;

    QImage newImage(newSize, DEFAULT_IMAGE_FORMAT);
    newImage.fill(background_alpha_color_);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image_);
    image_ = newImage;
}

void PaintArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), image_);
}

void PaintArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (brush_) {
            QPainter painter(&image_);
            const QRect rect = brush_->mousePress(painter,
                                                          event->pos());
            update(rect);
        }
        last_pos_ = event->pos();
    }
}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && last_pos_ != QPoint(-1, -1)) {
        if (brush_) {
            QPainter painter(&image_);
            const QRect rect = brush_->mouseMove(painter, last_pos_,
                                                         event->pos());
            update(rect);
        }

        last_pos_ = event->pos();
    }
}

void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && last_pos_ != QPoint(-1, -1)) {
        if (brush_) {
            QPainter painter(&image_);
            QRect rect = brush_->mouseRelease(painter, event->pos());
            update(rect);
        }

        last_pos_ = QPoint(-1, -1);
    }
}
