#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>

#include "custom_layouts.h"
#include "components/custom_color_dialog.h"
#include "controllers/color_picker_widget_controller.h"

class ColorPickerWidget : public QGroupBox {
    Q_OBJECT
public:
    ColorPickerWidget(QWidget* parent,
                      ColorPickerWidgetController* color_picker_controller);

private slots:
    void changeCurrentColor(const QColor& color);

private:
    static constexpr int COLOR_LABEL_WIDTH = 90;
    static constexpr int COLOR_LABEL_HEIGHT = 20;
    ColorPickerWidgetController* color_picker_controller_;
    QLabel* color_label_ = nullptr;
    QLabel* text_label_ = nullptr;
    QVBoxLayout* main_layout_ = nullptr;
    CustomColorDialog* color_dialog_ = nullptr;

    void setupLabels();
    void addLabelsToLayout();
    void setupLayout();
};

#endif // COLOR_PICKER_H
