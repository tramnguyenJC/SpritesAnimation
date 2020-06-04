#include "sprites_editor_window.h"

#include <QDebug>
#include <QSplitter>

SpritesEditorWindow::SpritesEditorWindow(QWidget *parent)
    : QMainWindow(parent),
      scroll_area_(new QScrollArea)
{
    setupControllers();
    setupScrollArea();
    setupColorPickerWidget();
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
}

void SpritesEditorWindow::setupScrollArea() {
    scroll_area_->setBackgroundRole(QPalette::Dark);
    scroll_area_->setWidget(window_controller_->getPaintArea());
//    QPalette pal = scroll_area_->palette();
//    pal.setColor(scroll_area_->backgroundRole(), QColor(230,230,230));
//    scroll_area_->setPalette(pal);
}

void SpritesEditorWindow::setupColorPickerWidget() {
    color_picker_widget_ = new ColorPickerWidget(this,
                                                 color_picker_controller_);
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

    QGroupBox* horizontalGroupBox = new QGroupBox();
    QHBoxLayout *hLayout = createQHBoxLayout();
    hLayout->addWidget(color_picker_widget_);
    hLayout->addWidget(scroll_area_);
    horizontalGroupBox->setLayout(hLayout);

    main_layout_ = createQVBoxLayout();
    main_layout_->setMenuBar(menubar_);
    main_layout_->addWidget(horizontalGroupBox);
    main_widget_->setLayout(main_layout_);
    //    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //    QSplitter *splitter = new QSplitter(parent);
    //      QListView *listview = new QListView;
    //      QTreeView *treeview = new QTreeView;
    //      QTextEdit *textedit = new QTextEdit;
    //      splitter->addWidget(listview);
    //      splitter->addWidget(treeview);
    //      splitter->addWidget(textedit);
}

QVBoxLayout* SpritesEditorWindow::createQVBoxLayout() {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    return layout;
}

QHBoxLayout* SpritesEditorWindow::createQHBoxLayout() {
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    return layout;
}
