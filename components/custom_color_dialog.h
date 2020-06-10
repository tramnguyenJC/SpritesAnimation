#ifndef CUSTOMCOLORDIALOG_H
#define CUSTOMCOLORDIALOG_H

#include <QHBoxLayout>
#include <QColorDialog>
#include <QLabel>
#include <QLayout>

class CustomColorDialog : public QColorDialog {
    Q_OBJECT
public:
    CustomColorDialog();

private:
    static constexpr int QCOLOR_PICKER_SIZE = 120;
    static constexpr int QCOLOR_LUMINANCE_PICKER_WIDTH = 20;
    void selectivelyDisplayComponents();
    void clearLayoutMarginAndSpacing(QLayout* layout);
};

#endif // CUSTOMCOLORDIALOG_H
