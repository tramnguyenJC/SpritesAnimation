#include "custom_layouts.h"

CustomLayouts::CustomLayouts() {}

QVBoxLayout* CustomLayouts::createQVBoxLayout() {
   QVBoxLayout* layout = new QVBoxLayout;
   layout->setMargin(0);
   layout->setSpacing(0);
   return layout;
}

QHBoxLayout* CustomLayouts::createQHBoxLayout() {
   QHBoxLayout* layout = new QHBoxLayout;
   layout->setMargin(0);
   layout->setSpacing(0);
   return layout;
}

void CustomLayouts::setupSizePolicy(QWidget *widget, int horizontal_stretch,
                                    int vertical_stretch) {
    QSizePolicy size_policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    size_policy.setHorizontalStretch(horizontal_stretch);
    size_policy.setVerticalStretch(vertical_stretch);
    widget->setSizePolicy(size_policy);
}

void CustomLayouts::setupSizePolicyVertical(QWidget *widget,
                                            int vertical_stretch) {
    QSizePolicy size_policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    size_policy.setVerticalStretch(vertical_stretch);
    widget->setSizePolicy(size_policy);
}

void CustomLayouts::setupSizePolicyHorizontal(QWidget *widget,
                                              int horizontal_stretch) {
    QSizePolicy size_policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    size_policy.setHorizontalStretch(horizontal_stretch);
    widget->setSizePolicy(size_policy);
}
