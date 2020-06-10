#include "sprites_editor_toolbar.h"

#include <QDebug>

SpritesEditorToolbar::SpritesEditorToolbar(
        QWidget* parent, SpritesEditorToolbarController* toolbar_controller)
    : QToolBar(parent),
     toolbar_controller_(toolbar_controller)
{
    this->setAllowedAreas(Qt::NoToolBarArea);
    addBrushButton();
}

QToolButton* SpritesEditorToolbar::createButton(const QIcon& icon,
                                                const QString& button_name) {
    QToolButton *button = new QToolButton;
    button->setIcon(icon);
    button->setToolTip(button_name);
    button->setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    button->setIconSize(QSize(BUTTON_SIZE, BUTTON_SIZE));
    return button;
}

void SpritesEditorToolbar::addBrushButton() {
    const QIcon brush_icon = QIcon::fromTheme("brush",
                                           QIcon(":/images/icons/brush.png"));
    auto brush_button = createButton(brush_icon, tr("Brush"));
    connect(brush_button, &QToolButton::clicked, this,
            &SpritesEditorToolbar::brush);
    // button->setShortcut(QKeySequence(Qt::Key_Tab));
    this->addWidget(brush_button);
}

void SpritesEditorToolbar::brush() {
    qInfo() << "clicked";
}

