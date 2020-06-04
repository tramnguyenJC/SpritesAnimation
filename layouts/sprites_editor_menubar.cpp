#include "sprites_editor_menubar.h"
#include "brushes/brush.h"

#include <QActionGroup>
#include <QApplication>
#include <QMessageBox>
#include <QPointer>

SpritesEditorMenuBar::SpritesEditorMenuBar(
        QWidget* parent, SpritesEditorMenuBarController* menu_bar_controller)
    : QMenuBar(parent),
      menu_bar_controller_(menu_bar_controller)
{
}

void SpritesEditorMenuBar::initialize() {
    createActions();
    createMenus();
    loadBrushes();
    if (!brush_action_group_->actions().isEmpty()) {
        brush_action_group_->actions().at(0)->trigger();
    }
}

SpritesEditorMenuBar::~SpritesEditorMenuBar() {

}

void SpritesEditorMenuBar::createActions()
{
    createOpenAction();
    createSaveAsAction();
    createExitAction();
    createBrushColorAction();
    createBrushWidthAction();
    createDarkModeAction();
    createLightModeAction();
    brush_action_group_ = new QActionGroup(this);
    createAboutAction();
    createAboutQtAction();
}

void SpritesEditorMenuBar::createOpenAction() {
    open_action_ = new QAction(tr("&Open..."), this);
    open_action_->setShortcuts(QKeySequence::Open);
    connect(open_action_, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::open);
}

void SpritesEditorMenuBar::createSaveAsAction() {
    save_as_action_ = new QAction(tr("&Save As..."), this);
    save_as_action_->setShortcuts(QKeySequence::SaveAs);
    connect(save_as_action_, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::saveAs);
}

void SpritesEditorMenuBar::createExitAction() {
    exit_action_ = new QAction(tr("&Exit"), this);
    exit_action_->setShortcuts(QKeySequence::Quit);
    connect(exit_action_, &QAction::triggered, this,
            &SpritesEditorMenuBar::close);
}

void SpritesEditorMenuBar::createBrushColorAction() {
    brush_color_action_ = new QAction(tr("Brush Color..."), this);
    connect(brush_color_action_, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::brushColor);
}

void SpritesEditorMenuBar::createBrushWidthAction() {
    brush_width_action_ = new QAction(tr("Brush Width..."), this);
    connect(brush_width_action_, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::brushWidth);
}

void SpritesEditorMenuBar::createDarkModeAction() {
    dark_mode_action_ = new QAction(tr("Dark mode"), this);
    connect(dark_mode_action_, &QAction::triggered, this,
            [this] { menu_bar_controller_->applyStylesheet(":/dark.qss");});
}

void SpritesEditorMenuBar::createLightModeAction() {
    light_mode_action_ = new QAction(tr("Light mode"), this);
    connect(light_mode_action_, &QAction::triggered, menu_bar_controller_,
            [this] { menu_bar_controller_->applyStylesheet(":/light.qss");});
}


void SpritesEditorMenuBar::createAboutAction() {
    about_action_ = new QAction(tr("About"), this);
    connect(about_action_, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::about);
}

void SpritesEditorMenuBar::createAboutQtAction() {
    about_qt_action_ = new QAction(tr("About Qt"), this);
    connect(about_qt_action_, &QAction::triggered, qApp,
            &QApplication::aboutQt);
}

void SpritesEditorMenuBar::createMenus()
{
    createFileMenu();
    createBrushMenu();

    shapes_menu_ = this->addMenu(tr("Shapes"));
    filter_menu_ = this->addMenu(tr("Filter"));
    createViewMenu();
    this->addSeparator();
    createHelpMenu();
}

void SpritesEditorMenuBar::createFileMenu() {
    file_menu_ = this->addMenu(tr("File"));
    file_menu_->addAction(open_action_);
    file_menu_->addAction(save_as_action_);
    file_menu_->addSeparator();
    file_menu_->addAction(exit_action_);

}

void SpritesEditorMenuBar::createBrushMenu() {
    brush_menu_ = this->addMenu(tr("Brush"));
    brush_menu_->addAction(brush_color_action_);
    brush_menu_->addAction(brush_width_action_);
    brush_menu_->addSeparator();
}

void SpritesEditorMenuBar::createViewMenu() {
    help_menu_ = this->addMenu(tr("View"));
    help_menu_->addAction(dark_mode_action_);
    help_menu_->addAction(light_mode_action_);
}

void SpritesEditorMenuBar::createHelpMenu() {
    help_menu_ = this->addMenu(tr("Help"));
    help_menu_->addAction(about_action_);
    help_menu_->addAction(about_qt_action_);
}

void SpritesEditorMenuBar::loadBrushes()
{
    const QStringList brushes =  Brush::getBrushNames();
    for (const QString& brush_name : brushes) {
        loadBrush(brush_name);
    }
    if (brush_action_group_) {
        brush_menu_->setEnabled(!brush_action_group_->actions().isEmpty());
    }
//    shapes_menu_->setEnabled(!shapes_menu_->actions().isEmpty());
//    filter_menu_->setEnabled(!filter_menu_->actions().isEmpty());
}

void SpritesEditorMenuBar::loadBrush(QString brush_name) {
    QPointer<Brush> brush = Brush::create(brush_name);

    auto action = new QAction(brush_name, brush);
    connect(action, &QAction::triggered, menu_bar_controller_,
            &SpritesEditorMenuBarController::changeBrush);
    brush_menu_->addAction(action);
    if (brush_action_group_) {
        action->setCheckable(true);
        brush_action_group_->addAction(action);
    }
}
