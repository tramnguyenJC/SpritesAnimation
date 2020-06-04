#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>

#include "components/custom_color_dialog.h"

class ColorPickerWidget : public QGroupBox {
    Q_OBJECT
public:
    ColorPickerWidget();

private slots:
    void changeCurrentColor(const QColor& color));

private:
    QLabel* color_label_ = nullptr;
    QLabel* text_label_ = nullptr;
    CustomColorDialog* color_dialog_ = nullptr;

    void setupLabels();
    void setupLayout();
};

#endif // COLOR_PICKER_H
