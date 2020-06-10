#include "brushes_menu_controller.h"

BrushesMenuController::BrushesMenuController(QWidget* parent,
                                                   PaintArea* paint_area)
    : QObject(parent),
      paint_area_(paint_area) {}

void BrushesMenuController::changeBrushWidth(int width) {
    paint_area_->getBrush()->setBrushWidth(width);
}

void BrushesMenuController::changeBrush(Brush* brush) {
    QColor current_brush_color = paint_area_->getBrush()->brushColor();
    brush->setBrushColor(current_brush_color);
    paint_area_->setBrush(brush);
    emit brushChangedWithNewWidth(brush->brushWidth());
}
