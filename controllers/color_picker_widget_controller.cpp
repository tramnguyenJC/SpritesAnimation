#include "color_picker_widget_controller.h"

ColorPickerWidgetController::ColorPickerWidgetController(
        QWidget* parent, PaintArea* paint_area)
    : QObject(parent),
      paint_area_(paint_area) {

}

void ColorPickerWidgetController::changeBrushColor(
        const QColor& new_color) {
    paint_area_->setBrushColor(new_color);
}
