#include "brushes/brush.h"
#include "paint_area.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

class QPalette;

PaintArea::PaintArea(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    this->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding);
    image_ = {500, 400, DEFAULT_IMAGE_FORMAT};
    image_.fill(DEFAULT_PAINT_AREA_COLOR);
    brush_color_ = Qt::black;
    thickness_ = 3;
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

void PaintArea::insertShape(const QPainterPath &path)
{
    pending_path_ = path;
#ifndef QT_NO_CURSOR
    setCursor(Qt::CrossCursor);
#endif
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
    newImage.fill(DEFAULT_PAINT_AREA_COLOR);
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
        if (!pending_path_.isEmpty()) {
            QPainter painter(&image_);
            setupPainter(painter);

            const QRectF boundingRect = pending_path_.boundingRect();
            QLinearGradient gradient(boundingRect.topRight(),
                                     boundingRect.bottomLeft());
            gradient.setColorAt(0.0, QColor(brush_color_.red(), brush_color_.green(),
                                            brush_color_.blue(), 63));
            gradient.setColorAt(1.0, QColor(brush_color_.red(), brush_color_.green(),
                                            brush_color_.blue(), 191));
            painter.setBrush(gradient);
            painter.translate(event->pos() - boundingRect.center());
            painter.drawPath(pending_path_);

            pending_path_ = QPainterPath();
#ifndef QT_NO_CURSOR
            unsetCursor();
#endif
            update();
        } else {
            if (brush_) {
                QPainter painter(&image_);
                setupPainter(painter);
                const QRect rect = brush_->mousePress(painter,
                                                              event->pos());
                update(rect);
            }

            last_pos_ = event->pos();
        }
    }
}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && last_pos_ != QPoint(-1, -1)) {
        if (brush_) {
            QPainter painter(&image_);
            setupPainter(painter);
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
            setupPainter(painter);
            QRect rect = brush_->mouseRelease(painter, event->pos());
            update(rect);
        }

        last_pos_ = QPoint(-1, -1);
    }
}

void PaintArea::setupPainter(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(brush_color_, thickness_, Qt::SolidLine, Qt::RoundCap,
                   Qt::RoundJoin));
}
