#include "sprites_editor_toolbar.h"

#include <QToolButton>

SpritesEditorToolbar::SpritesEditorToolbar(
        QWidget* parent, SpritesEditorToolbarController* toolbar_controller)
    : QToolBar(parent),
     toolbar_controller_(toolbar_controller)
{
    this->setAllowedAreas(Qt::NoToolBarArea);
    const QIcon newIcon = QIcon::fromTheme("document-new",
                                           QIcon(":/images/icons/brush.png"));
    QToolButton *button = new QToolButton;
    button->setIcon(newIcon);
    button->setToolTip("Brush");
    button->setFixedSize(40, 40);
    button->setIconSize(QSize(40, 40));
//    button->setShortcut(QKeySequence(Qt::Key_Tab));
    this->addWidget(button);
    connect(button, &QToolButton::clicked, this, &SpritesEditorToolbar::brush);
}

void SpritesEditorToolbar::brush() {

}
