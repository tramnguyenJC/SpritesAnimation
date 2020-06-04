#ifndef SPRITES_EDITOR_TOOLBAR_H
#define SPRITES_EDITOR_TOOLBAR_H

#include <QButtonGroup>
#include <QToolBar>

#include "brushes/brush.h"
#include "controllers/sprites_editor_toolbar_controller.h"

class SpritesEditorToolbar : public QToolBar {
    Q_OBJECT
public:
    SpritesEditorToolbar(QWidget* parent,
                         SpritesEditorToolbarController* toolbar_controller);

private slots:
    void brush();

private:
    QButtonGroup* button_group_;
    SpritesEditorToolbarController* toolbar_controller_;

};

#endif // SPRITES_EDITOR_TOOLBAR_H
