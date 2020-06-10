#ifndef BRUSHES_LIST_PANEL_H
#define BRUSHES_LIST_PANEL_H

#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

#include "controllers/brushes_menu_controller.h"
#include "custom_layouts.h"
#include "brushes/brush_collection.h"
#include "brushes/brush.h"

class BrushListPanel : public QMainWindow {

public:
    BrushListPanel(QWidget* parent, BrushesMenuController*
                     brushes_menu_controller);

private slots:
    void brushSelected(QListWidgetItem* item);

private:
    void loadBrushes();
    void setupBrushList();

    QScrollArea* scroll_area_ = nullptr;
    QWidget* content_widget_ = nullptr;
    QVBoxLayout* main_layout_ = nullptr;
    QListWidget* brush_list_ = nullptr;
    BrushesMenuController* brushes_menu_controller_ = nullptr;
};
#endif // BRUSHES_LIST_PANEL_H
