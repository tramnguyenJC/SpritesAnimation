#ifndef CUSTOM_LAYOUTS_H
#define CUSTOM_LAYOUTS_H

#include <QHBoxLayout>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>

class CustomLayouts : public QObject {
public:
    static QVBoxLayout* createQVBoxLayout();
    static QHBoxLayout* createQHBoxLayout();
    static void setupSizePolicy(QWidget* widget, int horizontal_stretch,
                                int vertical_stretch);
    static void setupSizePolicyHorizontal(QWidget* widget,
                                          int horizontal_stretch);
    static void setupSizePolicyVertical(QWidget* widget, int vertical_stretch);
private:
    CustomLayouts();
};

#endif // CUSTOM_LAYOUTS_H
