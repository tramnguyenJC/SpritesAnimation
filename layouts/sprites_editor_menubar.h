#ifndef SPRITES_EDITOR_MENU_BAR_H
#define SPRITES_EDITOR_MENU_BAR_H

#include "controllers/sprites_editor_menubar_controller.h"

#include <QMenu>
#include <QMenuBar>


class SpritesEditorMenuBar : public QMenuBar {
    Q_OBJECT
public:
    SpritesEditorMenuBar(QWidget* parent,
                         SpritesEditorMenuBarController* menu_bar_controller);
    void initialize();
    ~SpritesEditorMenuBar();

private:
    void createActions();
    void createOpenAction();
    void createSaveAsAction();
    void createExitAction();
    void createBrushColorAction();
    void createBrushWidthAction();
    void createDarkModeAction();
    void createLightModeAction();
    void createAboutAction();
    void createAboutQtAction();

    void createMenus();
    void createFileMenu();
    void createBrushMenu();
    void createViewMenu();
    void createHelpMenu();
    void loadBrushes();
    void loadBrush(QString brush_name);

    SpritesEditorMenuBarController* menu_bar_controller_ = nullptr;
    QMenu *file_menu_ = nullptr;
    QMenu *brush_menu_ = nullptr;
    QMenu *shapes_menu_ = nullptr;
    QMenu *filter_menu_ = nullptr;
    QMenu *help_menu_ = nullptr;
    QActionGroup *brush_action_group_ = nullptr;
    QAction *open_action_ = nullptr;
    QAction *save_as_action_ = nullptr;
    QAction *exit_action_ = nullptr;
    QAction *brush_width_action_ = nullptr;
    QAction *brush_color_action_ = nullptr;
    QAction *dark_mode_action_ = nullptr;
    QAction *light_mode_action_ = nullptr;
    QAction *about_action_ = nullptr;
    QAction *about_qt_action_ = nullptr;

};

#endif // SPRITES_EDITOR_MENU_BAR_H
