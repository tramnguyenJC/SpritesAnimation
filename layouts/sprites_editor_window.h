#ifndef SPRITES_EDITOR_WINDOW_H
#define SPRITES_EDITOR_WINDOW_H

#include <QColorDialog>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QScrollArea>

#include "layouts/sprites_editor_toolbar.h"
#include "layouts/sprites_editor_menu_bar.h"
#include "controllers/sprites_editor_window_controller.h"

class SpritesEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpritesEditorWindow(QWidget *parent = nullptr);
    ~SpritesEditorWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    SpritesEditorWindowController* controller_ = nullptr;
    QScrollArea* scroll_area_ = nullptr;
    SpritesEditorMenuBar* menu_bar_ = nullptr;
    SpritesEditorToolbar* toolbar_ = nullptr;
    QWidget* parent_ = nullptr;
    QWidget* main_widget_ = nullptr;
    QVBoxLayout* main_layout_ = nullptr;

    void setupScrollArea();
    void setupToolbar();
    void setupMainWidget();
    void setupMainLayout();
    QColorDialog* createColorDialog();
};
#endif // SPRITES_EDITOR_WINDOW_H
