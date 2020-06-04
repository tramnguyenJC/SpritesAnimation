#include "sprites_editor_window_controller.h"

SpritesEditorWindowController::SpritesEditorWindowController()
    : paint_area_(new PaintArea) {}

void SpritesEditorWindowController::resizePaintArea(int width, int height) {
    int image_width = paint_area_->sizeHint().width();
    int image_height = paint_area_->sizeHint().height();
    if (width > image_width|| height > image_height) {
        int newWidth = qMax(width + 128, image_width);
        int newHeight = qMax(height + 128, image_height);
        paint_area_->resizePaintArea(QSize(newWidth, newHeight));
        paint_area_->update();
    }
}
