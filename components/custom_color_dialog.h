#ifndef CUSTOMCOLORDIALOG_H
#define CUSTOMCOLORDIALOG_H

#include <QColorDialog>
#include <QLabel>

class CustomColorDialog : public QColorDialog {
    Q_OBJECT
public:
    CustomColorDialog();

private:
    static constexpr int QCOLOR_PICKER_SIZE = 130;
    static constexpr int QCOLOR_LUMINANCE_PICKER_WIDTH = 20;
    void selectivelyDisplayComponents();
};

#endif // CUSTOMCOLORDIALOG_H
