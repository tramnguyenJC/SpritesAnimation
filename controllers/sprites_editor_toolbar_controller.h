#ifndef SPRITES_EDITOR_TOOLBAR_CONTROLLER_H
#define SPRITES_EDITOR_TOOLBAR_CONTROLLER_H

#include <QObject>
#include <QWidget>

class SpritesEditorToolbarController : public QObject {
    Q_OBJECT
public:
    SpritesEditorToolbarController(QWidget* parent);
private:
};

#endif // SPRITES_EDITOR_TOOLBAR_CONTROLLER_H
