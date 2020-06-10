#include "controllers/sprites_editor_menubar_controller.h"

#include <QAction>
#include <QApplication>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>


SpritesEditorMenuBarController::SpritesEditorMenuBarController(
        QWidget* parent,
        SpritesEditorWindowController* window_controller)
    : parent_(parent),
      window_controller_(window_controller) {
}

void SpritesEditorMenuBarController::open()
{
    const QString fileName = QFileDialog::getOpenFileName(parent_,
                                                          tr("Open File"),
                                                          QDir::currentPath());
    if (!fileName.isEmpty()) {
        if (!window_controller_->getPaintArea()->openImage(fileName)) {
            QMessageBox::information(parent_, tr("Plug & Paint"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        window_controller_->getPaintArea()->adjustSize();
    }
}

bool SpritesEditorMenuBarController::saveAs()
{
    const QString initialPath = QDir::currentPath() + "/untitled.png";

    const QString fileName = QFileDialog::getSaveFileName(parent_,
                                                          tr("Save As"),
                                                          initialPath);
    if (fileName.isEmpty())
        return false;

    return window_controller_->getPaintArea()->saveImage(fileName, "png");
}

void SpritesEditorMenuBarController::applyStylesheet(const QString path) {
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    qApp->setStyleSheet(stream.readAll());
}

void SpritesEditorMenuBarController::brushColor()
{
    const QColor newColor = QColorDialog::getColor(
                window_controller_->getPaintArea()->getBrush()->brushColor());
    if (newColor.isValid())
        window_controller_->getPaintArea()->getBrush()->setBrushColor(newColor);
}

void SpritesEditorMenuBarController::brushWidth()
{
    bool ok;
    const int newWidth = QInputDialog::getInt(
                parent_, tr("Plug & Paint"), tr("Select brush width:"),
                window_controller_->getPaintArea()->getBrush()->brushWidth(),
                1, 50, 1, &ok);
    if (ok)
        window_controller_->getPaintArea()->getBrush()->setBrushWidth(newWidth);
}

void SpritesEditorMenuBarController::changeBrush()
{
    auto action = qobject_cast<QAction *>(sender());
    auto brush = qobject_cast<Brush *>(action->parent());
    window_controller_->getPaintArea()->setBrush(brush);
}

void SpritesEditorMenuBarController::about()
{
   QMessageBox::about(parent_, tr("About Plug & Paint"),
            tr("The <b>Plug & Paint</b> example demonstrates how to write Qt "
               "applications that can be extended through plugins."));
}
