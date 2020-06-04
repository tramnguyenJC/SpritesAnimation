QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brushes/brush.cpp \
    brushes/eraser.cpp \
    brushes/pencil.cpp \
    components/custom_color_dialog.cpp \
    components/paint_area.cpp \
    controllers/color_picker_widget_controller.cpp \
    controllers/sprites_editor_menubar_controller.cpp \
    controllers/sprites_editor_toolbar_controller.cpp \
    controllers/sprites_editor_window_controller.cpp \
    layouts/brushes_sidebar.cpp \
    layouts/color_picker_widget.cpp \
    layouts/sprites_editor_menubar.cpp \
    layouts/sprites_editor_toolbar.cpp \
    layouts/sprites_editor_window.cpp \
    main.cpp

HEADERS += \
    brushes/brush.h \
    brushes/brush_factory.h \
    brushes/eraser.h \
    brushes/pencil.h \
    components/custom_color_dialog.h \
    components/paint_area.h \
    controllers/color_picker_widget_controller.h \
    controllers/sprites_editor_menubar_controller.h \
    controllers/sprites_editor_toolbar_controller.h \
    controllers/sprites_editor_window_controller.h \
    layouts/brushes_sidebar.h \
    layouts/color_picker_widget.h \
    layouts/sprites_editor_menubar.h \
    layouts/sprites_editor_toolbar.h \
    layouts/sprites_editor_window.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/BreezeStyleSheets/breeze.qrc \
    resources/resources.qrc \

DISTFILES += \
    resources/images/icons/new.png


