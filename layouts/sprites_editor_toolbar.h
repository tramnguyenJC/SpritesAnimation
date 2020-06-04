#ifndef SPRITES_EDITOR_TOOLBAR_H
#define SPRITES_EDITOR_TOOLBAR_H

#include <QButtonGroup>
#include <QToolBar>

#include "brushes/brush.h"
#include "controllers/sprites_editor_window_controller.h"

class SpritesEditorToolbar : public QToolBar {
    Q_OBJECT
public:
    SpritesEditorToolbar(QWidget* parent,
                         SpritesEditorWindowController* window_controller);

private slots:
    void brush();

private:
    QButtonGroup* button_group_;
    SpritesEditorWindowController* window_controller_;

};

#endif // SPRITES_EDITOR_TOOLBAR_H
