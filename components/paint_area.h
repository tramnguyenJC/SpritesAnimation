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
    void insertShape(const QPainterPath &path);

    inline void setBrushColor(const QColor &brush_color) {
        brush_color_ = brush_color;
    }
    inline QColor getBrushColor() const { return brush_color_;}

    inline void setBrushWidth(int width) {
        thickness_ = width;
    }
    inline int getBrushWidth() const { return thickness_;}

    inline void setBrush(Brush *brush, const QString &brush_name) {
        this->brush_ = brush;
        this->brush_name_ = brush_name;
    }
    inline Brush* getBrush() const { return brush_;}

    inline QImage image() const { return image_; }
    inline QColor brushColor() const { return brush_color_; }
    inline int brushWidth() const { return thickness_; }
    inline QSize sizeHint() const override { return image_.size();}
    void resizePaintArea(const QSize &newSize);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    const QRgb DEFAULT_PAINT_AREA_COLOR = qRgba(255,255,255,0);
    const QImage::Format DEFAULT_IMAGE_FORMAT = QImage::Format_ARGB32;
    void setupPainter(QPainter &painter);
    void resizeImage(const QSize &newSize);

    QImage image_;
    QColor brush_color_;
    int thickness_;

    Brush *brush_ = nullptr;
    QString brush_name_;
    QPoint last_pos_ = {-1, -1};

    QPainterPath pending_path_;
};

#endif // PAINTAREA_H
