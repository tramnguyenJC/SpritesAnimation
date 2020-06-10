#ifndef SPRITES_EDITOR_WINDOW_H
#define SPRITES_EDITOR_WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QScrollArea>

#include "controllers/color_picker_widget_controller.h"
#include "controllers/brushes_menu_controller.h"
#include "controllers/sprites_editor_window_controller.h"
#include "controllers/sprites_editor_menubar_controller.h"
#include "controllers/sprites_editor_toolbar_controller.h"
#include "layouts/brushes_menu.h"
#include "layouts/custom_layouts.h"
#include "layouts/color_picker_widget.h"
#include "layouts/sprites_editor_toolbar.h"
#include "layouts/sprites_editor_menubar.h"

class SpritesEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpritesEditorWindow(QWidget *parent = nullptr);
    ~SpritesEditorWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    SpritesEditorWindowController* window_controller_ = nullptr;
    SpritesEditorMenuBarController* menubar_controller_ = nullptr;
    SpritesEditorToolbarController* toolbar_controller_ = nullptr;
    ColorPickerWidgetController* color_picker_controller_ = nullptr;
    BrushesMenuController* brushes_menu_controller_ = nullptr;
    QScrollArea* scroll_area_ = nullptr;
    ColorPickerWidget* color_picker_widget_ = nullptr;
    SpritesEditorMenuBar* menubar_ = nullptr;
    SpritesEditorToolbar* toolbar_ = nullptr;
    BrushesMenu* brushes_menu_ = nullptr;
    QWidget* parent_ = nullptr;

    QWidget* main_widget_ = nullptr;
    QHBoxLayout* main_layout_ = nullptr;

    void setupControllers();
    void setupScrollArea();
    void setupColorPickerWidget();
    void setupBrushesMenu();
    void setupMenuBar();
    void setupToolbar();
    void setupMainWidget();
    void setupMainLayout();
    QGroupBox* createLeftPanel();
    QGroupBox* createMiddlePanel();
    QGroupBox* createRightPanel();
};
#endif // SPRITES_EDITOR_WINDOW_H
