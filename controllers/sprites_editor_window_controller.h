#ifndef SPRITES_EDITOR_WINDOW_CONTROLLER_H
#define SPRITES_EDITOR_WINDOW_CONTROLLER_H

#include <QObject>
#include "components/paint_area.h"

class SpritesEditorWindowController : public QObject {
    Q_OBJECT
public:
    SpritesEditorWindowController(QWidget* parent);

    inline PaintArea* getPaintArea() const { return paint_area_;}
    void resizePaintArea(int width, int height);
private:
    PaintArea* paint_area_ = nullptr;
};

#endif // SPRITES_EDITOR_WINDOW_CONTROLLER_H
