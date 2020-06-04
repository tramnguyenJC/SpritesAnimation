#ifndef SPRITES_EDITOR_WINDOW_H
#define SPRITES_EDITOR_WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QScrollArea>

#include "layouts/sprites_editor_toolbar.h"
#include "layouts/sprites_editor_menubar.h"
#include "layouts/color_picker_widget.h"
#include "controllers/sprites_editor_window_controller.h"
#include "controllers/sprites_editor_menubar_controller.h"
#include "controllers/sprites_editor_toolbar_controller.h"
#include "controllers/color_picker_widget_controller.h"

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
    QScrollArea* scroll_area_ = nullptr;
    ColorPickerWidget* color_picker_widget_ = nullptr;
    SpritesEditorMenuBar* menubar_ = nullptr;
    SpritesEditorToolbar* toolbar_ = nullptr;
    QWidget* parent_ = nullptr;
    QWidget* main_widget_ = nullptr;
    QVBoxLayout* main_layout_ = nullptr;

    void setupControllers();
    void setupScrollArea();
    void setupColorPickerWidget();
    void setupMenuBar();
    void setupToolbar();
    void setupMainWidget();
    void setupMainLayout();
    void setLayoutMarginAndSpacing();

    QVBoxLayout* createQVBoxLayout();
    QHBoxLayout* createQHBoxLayout();
};
#endif // SPRITES_EDITOR_WINDOW_H
