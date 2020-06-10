#ifndef BRUSH_WIDTH_MENU_CONTROLLER_H
#define BRUSH_WIDTH_MENU_CONTROLLER_H

#include <QObject>

#include "brushes/brush.h"
#include "components/paint_area.h"

class BrushesMenuController : public QObject {
    Q_OBJECT

public:
    BrushesMenuController(QWidget* parent, PaintArea* paint_area);
    void changeBrushWidth(int width);

signals:
    void brushChangedWithNewWidth(int new_brush_width);

public slots:
    void changeBrush(Brush* brush);

private:
    PaintArea* paint_area_;
};

#endif // BRUSH_WIDTH_MENU_CONTROLLER_H
