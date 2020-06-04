#ifndef SPRITES_EDITOR_MENU_BAR_CONTROLLER_H
#define SPRITES_EDITOR_MENU_BAR_CONTROLLER_H

#include <QObject>
#include "controllers/sprites_editor_window_controller.h"

class SpritesEditorMenuBarController : public QObject {
public:
    SpritesEditorMenuBarController(
            QWidget* parent,
            SpritesEditorWindowController* window_controller);

public slots:
    void open();
    bool saveAs();
    void brushColor();
    void brushWidth();
    void changeBrush();
//    void insertShape();
//    void applyFilter();
    void about();
    void applyStylesheet(const QString path);

private:
    QWidget* parent_;
    SpritesEditorWindowController* window_controller_;
};

#endif // SPRITES_EDITOR_MENU_BAR_CONTROLLER_H
