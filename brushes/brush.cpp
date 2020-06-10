#include "brush.h"

const QColor Brush::DEFAULT_COLOR = Qt::black;

Brush::Brush(const QString& brush_name)
    : brush_name_(brush_name) {
    brush_transparency_ = 1.0;
    brush_color_ = DEFAULT_COLOR;
    brush_color_.setAlphaF(brush_transparency_);
    setColor(brush_color_);
    brush_spacing_ = 0.1;
    brush_width_ = 5;
}
