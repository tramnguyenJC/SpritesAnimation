#include "custom_color_dialog.h"

CustomColorDialog::CustomColorDialog()
{
    this->setWindowFlags(Qt::Widget);
    this->setOptions(QColorDialog::DontUseNativeDialog
                    | QColorDialog::NoButtons);
    selectivelyDisplayComponents();
}

void CustomColorDialog::selectivelyDisplayComponents() {
    for (const auto& child : this->findChildren<QWidget*>()) {
        QString class_name = child->metaObject()->className();
        if (class_name == "QColorPicker") {
            child->setFixedSize(QCOLOR_PICKER_SIZE, QCOLOR_PICKER_SIZE);
        } else if (class_name == "QColorLuminancePicker") {
            child->setFixedSize(QCOLOR_LUMINANCE_PICKER_WIDTH,
                                QCOLOR_PICKER_SIZE);
        } else {
            child->hide();
        }
    }
}
