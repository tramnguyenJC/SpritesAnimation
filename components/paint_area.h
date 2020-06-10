#ifndef PAINT_AREA_H
#define PAINT_AREA_H

#include <QColor>
#include <QImage>
#include <QPainterPath>
#include <QWidget>

#include "brushes/brush.h"

class PaintArea : public QWidget
{
    Q_OBJECT

public:
    PaintArea(QWidget *parent = nullptr);

    bool openImage(const QString &file_name);
    bool saveImage(const QString &file_name, const char *file_format);
    void setImage(const QImage &image);

    void setBrush(Brush *brush) { brush_ = brush;}
    Brush* getBrush() const { return brush_;}
    QImage image() const { return image_; }
    QSize sizeHint() const override { return image_.size();}
    static QColor getBackgroundColor() { return QColor(background_color_);}
    static QColor getBackgroundAlphaColor() { return QColor(background_alpha_color_);}
    void resizePaintArea(const QSize &newSize);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    static QRgb background_alpha_color_;
    static QRgb background_color_;
    const QImage::Format DEFAULT_IMAGE_FORMAT = QImage::Format_ARGB32;
    void resizeImage(const QSize &newSize);

    QImage image_;
    Brush *brush_ = nullptr;
    QPoint last_pos_ = {-1, -1};

    QPainterPath pending_path_;
};

#endif // PAINTAREA_H
