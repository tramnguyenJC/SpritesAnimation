#include "brush_list_panel.h"

BrushListPanel::BrushListPanel(
        QWidget* parent, BrushesMenuController* brushes_menu_controller)
    : QMainWindow(parent),
      scroll_area_(new QScrollArea),
      content_widget_(new QWidget),
      main_layout_(new QVBoxLayout),
      brush_list_(new QListWidget),
      brushes_menu_controller_(brushes_menu_controller)
{
    setWindowFlags(Qt::Widget);
    setupBrushList();
    loadBrushes();
    scroll_area_->setWidget(brush_list_);
    scroll_area_->setWidgetResizable(true);
    setCentralWidget(scroll_area_);
}


void BrushListPanel::brushSelected(QListWidgetItem* item) {
    const QString brush_name = item->text();
    auto brush_collection = BrushCollection::getBrushCollection();
    Brush* brush = brush_collection[brush_name];
    brushes_menu_controller_->changeBrush(brush);
}


void BrushListPanel::loadBrushes() {
    auto brush_collection = BrushCollection::getBrushCollection();
    for (const auto& key : brush_collection.keys()) {
        Brush* brush = brush_collection[key];
        brush_list_->addItem(new QListWidgetItem(brush->brushName()));
    }
}

void BrushListPanel::setupBrushList() {
     brush_list_->setLayout(main_layout_);
     brush_list_->setDragDropMode(QAbstractItemView::InternalMove);
     connect(brush_list_, &QListWidget::itemClicked, this,
             &BrushListPanel::brushSelected);
}
