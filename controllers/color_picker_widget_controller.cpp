#include "color_picker_widget_controller.h"
#include "brushes/eraser.h"

ColorPickerWidgetController::ColorPickerWidgetController(
        QWidget* parent, PaintArea* paint_area)
    : QObject(parent),
      paint_area_(paint_area) {

}

void ColorPickerWidgetController::changeBrushColor(
        const QColor& new_color) {
    auto eraser = qobject_cast<Eraser*>(paint_area_->getBrush());
    if (!eraser) {
        paint_area_->getBrush()->setBrushColor(new_color);
    }
}
