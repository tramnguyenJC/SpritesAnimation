#include "color_picker_widget.h"

ColorPickerWidget::ColorPickerWidget()
    : color_label_(new QLabel()),
      color_dialog_(new CustomColorDialog())
{
    setupLabels();
    connect(color_dialog_, &QColorDialog::currentColorChanged,
            [this] {this->changeCurrentColor(color_dialog_->currentColor());});
    setupLayout();
}

void ColorPickerWidget::changeCurrentColor(const QColor& color) {
    color_label_->setStyleSheet("background-color: " + color.name());
    text_label_->setText(color_dialog_->currentColor().name());
}

void ColorPickerWidget::setupLabels() {
    color_label_->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    color_label_->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    text_label_->setText(color_dialog_->currentColor().name());
    color_label_->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
}

void ColorPickerWidget::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(color_dialog_);
    layout->addWidget(color_label_);
    layout->addWidget(text_label_);
    this->setLayout(layout);
}
