#include "brushes_menu.h"

BrushesMenu::BrushesMenu(
        QWidget* parent, BrushesMenuController* brushes_menu_controller)
    : QWidget(parent),
      brushes_menu_controller_(brushes_menu_controller),
      brush_width_descriptor_(new QLabel),
      brush_width_label_(new QLabel),
      brush_width_menu_(new QGroupBox)
{
    setupBrushWidthSlider();
    setupBrushWidthLabels();
    setupBrushWidthLabelsWidget();
    setupBrushListPanel();
    setupBrushWidthMenu();
    setupMainLayout();
}

void BrushesMenu::setupBrushWidthSlider() {
    brush_width_slider_ = new QSlider(Qt::Horizontal);
    brush_width_slider_->setMinimum(MIN_BRUSH_WIDTH);
    brush_width_slider_->setMaximum(MAX_BRUSH_WIDTH);
    brush_width_slider_->setFocusPolicy(Qt::StrongFocus);
    brush_width_slider_->setTickPosition(QSlider::TicksBothSides);
    brush_width_slider_->setTickInterval(5);
    brush_width_slider_->setSingleStep(1);
    connect(brush_width_slider_, &QSlider::valueChanged, this,
            &BrushesMenu::brushWidthChanged);
    connect(brushes_menu_controller_,
            &BrushesMenuController::brushChangedWithNewWidth,
            this, &BrushesMenu::updateBrushWidthSlider);
}


void BrushesMenu::setupBrushWidthLabels() {
    brush_width_descriptor_->setText("Brush Width");
    brush_width_label_->setText(QString::number(brush_width_slider_->value()));
}

void BrushesMenu::setupBrushWidthLabelsWidget() {
    brush_width_labels_widget_ = new QWidget(brush_width_menu_);
    QHBoxLayout* layout = CustomLayouts::createQHBoxLayout();
    layout->addWidget(brush_width_descriptor_);
    layout->addWidget(brush_width_label_);
    brush_width_labels_widget_->setLayout(layout);
}

void BrushesMenu::setupBrushWidthMenu() {
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(brush_width_slider_);
    layout->addWidget(brush_width_labels_widget_, Qt::AlignHCenter);
    brush_width_menu_->setLayout(layout);
}

void BrushesMenu::setupBrushListPanel() {
    brushes_list_panel_ = new BrushListPanel(this, brushes_menu_controller_);
}

void BrushesMenu::setupMainLayout() {
    main_layout_ = CustomLayouts::createQVBoxLayout();
    CustomLayouts::setupSizePolicyVertical(brush_width_menu_, 1);
    CustomLayouts::setupSizePolicyVertical(brushes_list_panel_, 3);
    main_layout_->addWidget(brush_width_menu_);
    main_layout_->addWidget(brushes_list_panel_);
    this->setLayout(main_layout_);
}

void BrushesMenu::brushWidthChanged() {
    int width = brush_width_slider_->value();
    brushes_menu_controller_->changeBrushWidth(width);
    brush_width_label_->setText(QString::number(width));
}

void BrushesMenu::updateBrushWidthSlider(int new_brush_width) {
    brush_width_slider_->setValue(new_brush_width);
}
