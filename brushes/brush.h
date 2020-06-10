#ifndef BRUSH_H
#define BRUSH_H


#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QString>

class Brush : public QObject,
              public QBrush
{
    Q_OBJECT
public:

    Brush(const QString& brush_name);
    virtual ~Brush() {}

    virtual QString brushName() const { return brush_name_; }
    virtual QColor brushColor() const { return brush_color_;}
    virtual void setBrushColor(const QColor& color) { brush_color_ = color;}
    virtual double brushSpacing() const { return brush_spacing_;}
    virtual void setBrushSpacing(double spacing) { brush_spacing_ = spacing;}
    virtual int brushWidth() const { return brush_width_;}
    virtual void setBrushWidth(int width) { brush_width_ = width;}
    virtual double brushTransparency() const { return brush_transparency_;}
    virtual void setBrushTransparency(double transparency) {
        brush_transparency_ = transparency;
    }

    virtual QRect mousePress(QPainter &painter, const QPoint &pos) = 0;
    virtual QRect mouseMove(QPainter &painter, const QPoint &oldPos,
                            const QPoint &newPos) = 0;
    virtual QRect mouseRelease(QPainter &painter, const QPoint &pos) = 0;

protected:
    static const QColor DEFAULT_COLOR;
    QString brush_name_;
    QColor brush_color_;
    double brush_spacing_;
    int brush_width_;
    double brush_transparency_;
};

#endif // BRUSH_H
