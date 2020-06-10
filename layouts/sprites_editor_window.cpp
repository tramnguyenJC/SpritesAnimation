#include "sprites_editor_window.h"

#include <QDebug>
#include <QSplitter>

SpritesEditorWindow::SpritesEditorWindow(QWidget *parent)
    : QMainWindow(parent),
      scroll_area_(new QScrollArea)
{
    // Setting up controllers should precede other components
    setupControllers();
    setupScrollArea();
    setupColorPickerWidget();
    setupBrushesMenu();
    setupToolbar();
    setupMenuBar();
    setupMainWidget();
    setupMainLayout();
    setWindowTitle(tr("Plug & Paint"));
}

SpritesEditorWindow::~SpritesEditorWindow() {
    delete scroll_area_;
}

void SpritesEditorWindow::resizeEvent(QResizeEvent* event) {
    window_controller_->resizePaintArea(width(), height());
    QWidget::resizeEvent(event);
}

void SpritesEditorWindow::setupControllers() {
    window_controller_ = new SpritesEditorWindowController(this);
    menubar_controller_ = new SpritesEditorMenuBarController(
                this, window_controller_);
    toolbar_controller_ = new SpritesEditorToolbarController(this);
    color_picker_controller_ = new ColorPickerWidgetController(
                this, window_controller_->getPaintArea());
    brushes_menu_controller_ = new BrushesMenuController(this,
                        window_controller_->getPaintArea());
}

void SpritesEditorWindow::setupScrollArea() {
    scroll_area_->setBackgroundRole(QPalette::Dark);
    scroll_area_->setWidget(window_controller_->getPaintArea());
}

void SpritesEditorWindow::setupColorPickerWidget() {
    color_picker_widget_ = new ColorPickerWidget(this,
                                                 color_picker_controller_);
}

void SpritesEditorWindow::setupBrushesMenu() {
    brushes_menu_ = new BrushesMenu(this, brushes_menu_controller_);
}

void SpritesEditorWindow::setupMenuBar() {
    menubar_ = new SpritesEditorMenuBar(this, menubar_controller_);
    menubar_->initialize();
}

void SpritesEditorWindow::setupToolbar() {
    toolbar_ = new SpritesEditorToolbar(this, toolbar_controller_);
    this->addToolBar(toolbar_);
}

void SpritesEditorWindow::setupMainWidget() {
    main_widget_ = new QWidget(this);
    setCentralWidget(main_widget_);
}

void SpritesEditorWindow::setupMainLayout() {
    main_layout_ = CustomLayouts::createQHBoxLayout();
    main_layout_->setMenuBar(menubar_);
    main_layout_->addWidget(createLeftPanel());
    main_layout_->addWidget(createMiddlePanel());
    main_layout_->addWidget(createRightPanel());
    main_widget_->setLayout(main_layout_);
}

QGroupBox* SpritesEditorWindow::createLeftPanel() {
    QGroupBox* left_panel = new QGroupBox();
    CustomLayouts::setupSizePolicyHorizontal(left_panel, 1);
    CustomLayouts::setupSizePolicyVertical(color_picker_widget_, 1);
    CustomLayouts::setupSizePolicyVertical(brushes_menu_, 2);
    QVBoxLayout *layout = CustomLayouts::createQVBoxLayout();
    layout->addWidget(color_picker_widget_);
    layout->addWidget(brushes_menu_);
    left_panel->setLayout(layout);
    return left_panel;
}

QGroupBox* SpritesEditorWindow::createMiddlePanel() {
    QGroupBox* middle_panel = new QGroupBox();
    CustomLayouts::setupSizePolicyHorizontal(middle_panel, 3);
    QVBoxLayout *layout = CustomLayouts::createQVBoxLayout();
    layout->addWidget(scroll_area_);
    middle_panel->setLayout(layout);
    return middle_panel;
}

QGroupBox* SpritesEditorWindow::createRightPanel() {
    QGroupBox* right_panel = new QGroupBox();
    CustomLayouts::setupSizePolicyHorizontal(right_panel, 1);
    QVBoxLayout *layout = CustomLayouts::createQVBoxLayout();
    layout->addWidget(new QWidget(this));
    right_panel->setLayout(layout);
    return right_panel;
}
