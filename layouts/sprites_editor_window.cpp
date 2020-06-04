#include "sprites_editor_window.h"

#include <QDebug>

SpritesEditorWindow::SpritesEditorWindow(QWidget *parent)
    : QMainWindow(parent),
      controller_(new SpritesEditorWindowController),
      scroll_area_(new QScrollArea)
{
    setupScrollArea();
    setupToolbar();
    setupMainWidget();
    setupMainLayout();
    setWindowTitle(tr("Plug & Paint"));
}

SpritesEditorWindow::~SpritesEditorWindow() {
    delete scroll_area_;
}

void SpritesEditorWindow::resizeEvent(QResizeEvent* event) {
    controller_->resizePaintArea(width(), height());
    QWidget::resizeEvent(event);
}

void SpritesEditorWindow::setupScrollArea() {
    scroll_area_->setBackgroundRole(QPalette::Dark);
    scroll_area_->setWidget(controller_->getPaintArea());
//    QPalette pal = scroll_area_->palette();
//    pal.setColor(scroll_area_->backgroundRole(), QColor(230,230,230));
//    scroll_area_->setPalette(pal);
}

void SpritesEditorWindow::setupToolbar() {
    toolbar_ = new SpritesEditorToolbar(this, controller_);
    this->addToolBar(toolbar_);
}

void SpritesEditorWindow::setupMainWidget() {
    main_widget_ = new QWidget(this);
    setCentralWidget(main_widget_);
}

QColorDialog* SpritesEditorWindow::createColorDialog() {
    QColorDialog *colorDialog = new QColorDialog(this);
    colorDialog->setWindowFlags(Qt::Widget);
    colorDialog->setOptions(QColorDialog::DontUseNativeDialog
                    | QColorDialog::NoButtons);
    return colorDialog;
}

void SpritesEditorWindow::setupMainLayout() {
    main_layout_ = new QVBoxLayout;

    menu_bar_ = new SpritesEditorMenuBar(this, controller_);
    menu_bar_->initialize();
    main_layout_->setMenuBar(menu_bar_);

    QGroupBox* horizontalGroupBox = new QGroupBox();
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(createColorDialog());
    hLayout->addWidget(scroll_area_);
    horizontalGroupBox->setLayout(hLayout);

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
