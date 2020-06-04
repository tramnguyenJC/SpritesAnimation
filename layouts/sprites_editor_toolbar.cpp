#include "sprites_editor_toolbar.h"

#include <QToolButton>

SpritesEditorToolbar::SpritesEditorToolbar(
        QWidget* parent, SpritesEditorWindowController* window_controller)
    : QToolBar(parent),
     window_controller_(window_controller)
{
    this->setAllowedAreas(Qt::AllToolBarAreas);
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
