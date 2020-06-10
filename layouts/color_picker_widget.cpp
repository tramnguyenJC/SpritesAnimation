#include "color_picker_widget.h"

ColorPickerWidget::ColorPickerWidget(
        QWidget* parent, ColorPickerWidgetController* color_picker_controller)
    : QGroupBox(parent),
      color_picker_controller_(color_picker_controller),
      color_label_(new QLabel()),
      text_label_(new QLabel()),
      color_dialog_(new CustomColorDialog())
{
    setupLabels();
    connect(color_dialog_, &QColorDialog::currentColorChanged,
            [this] {this->changeCurrentColor(color_dialog_->currentColor());});
    setupLayout();

}

void ColorPickerWidget::changeCurrentColor(const QColor& color) {
    color_label_->setStyleSheet("background-color: " + color.name());
    text_label_->setText(color.name());
    color_picker_controller_->changeBrushColor(color);
}

void ColorPickerWidget::setupLabels() {
    color_label_->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    color_label_->setFixedSize(COLOR_LABEL_WIDTH, COLOR_LABEL_HEIGHT);
    text_label_->setText(color_dialog_->currentColor().name());
}

void ColorPickerWidget::addLabelsToLayout() {
    QWidget* labels_widget = new QWidget;
    QHBoxLayout* horizontal_layout = new QHBoxLayout();
    horizontal_layout->addWidget(color_label_);
    horizontal_layout->addWidget(text_label_);
    labels_widget->setLayout(horizontal_layout);
    main_layout_->addWidget(labels_widget, Qt::AlignHCenter);
}

void ColorPickerWidget::setupLayout() {
    main_layout_ = CustomLayouts::createQVBoxLayout();
    main_layout_->addWidget(color_dialog_, Qt::AlignHCenter);
    addLabelsToLayout();
    this->setLayout(main_layout_);
}
