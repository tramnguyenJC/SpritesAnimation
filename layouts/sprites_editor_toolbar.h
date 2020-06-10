#ifndef SPRITES_EDITOR_TOOLBAR_H
#define SPRITES_EDITOR_TOOLBAR_H

#include <QToolBar>
#include <QToolButton>

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
    static constexpr int BUTTON_SIZE = 40;
    SpritesEditorToolbarController* toolbar_controller_;

    QToolButton* createButton(const QIcon& icon, const QString& button_name);
    void addBrushButton();
};

#endif // SPRITES_EDITOR_TOOLBAR_H
