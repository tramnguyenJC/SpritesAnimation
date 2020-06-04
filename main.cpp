#include "layouts/sprites_editor_window.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // set stylesheet
    QFile file(":/light.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    qApp->setStyleSheet(stream.readAll());

    SpritesEditorWindow spritesEditorWindow;
    spritesEditorWindow.showMaximized();
    return app.exec();
}
