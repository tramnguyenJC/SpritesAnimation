#ifndef BRUSH_WIDTH_MENU_H
#define BRUSH_WIDTH_MENU_H

#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QSlider>
#include <QWidget>

#include "custom_layouts.h"
#include "controllers/brushes_menu_controller.h"
#include "brush_list_panel.h"

class BrushesMenu : public QWidget {
    Q_OBJECT
public:
    BrushesMenu(QWidget* parent, BrushesMenuController*
                   brush_width_controller);

private slots:
    void updateBrushWidthSlider(int new_brush_width);

private:
    static const int MAX_BRUSH_WIDTH = 50;
    static const int MIN_BRUSH_WIDTH = 0;
    QVBoxLayout* main_layout_ = nullptr;
    BrushesMenuController* brushes_menu_controller_ = nullptr;
    QSlider* brush_width_slider_ = nullptr;
    QLabel* brush_width_descriptor_ = nullptr;
    QWidget* brush_width_labels_widget_ = nullptr;
    QLabel* brush_width_label_ = nullptr;
    QGroupBox* brush_width_menu_ = nullptr;
    BrushListPanel* brushes_list_panel_ = nullptr;

    void setupBrushWidthSlider();
    void setupBrushWidthLabels();
    void setupBrushWidthLabelsWidget();
    void setupBrushWidthMenu();
    void setupBrushListPanel();
    void setupMainLayout();
    void brushWidthChanged();
};

#endif // BRUSH_WIDTH_MENU_H
