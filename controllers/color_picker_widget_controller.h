#ifndef COLOR_PICKER_WIDGET_CONTROLLER_H
#define COLOR_PICKER_WIDGET_CONTROLLER_H

#include <QObject>
#include "components/paint_area.h"

class ColorPickerWidgetController : public QObject {
    Q_OBJECT
public:
    ColorPickerWidgetController(QWidget* parent, PaintArea* paint_area);
    void changeBrushColor(const QColor& new_color);
private:
    PaintArea* paint_area_ = nullptr;
};

#endif // COLOR_PICKER_WIDGET_CONTROLLER_H
