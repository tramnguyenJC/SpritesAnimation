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
    brushes/pencil.cpp \
    color_picker.cpp \
    controllers/sprites_editor_menu_bar_controller.cpp \
    controllers/sprites_editor_window_controller.cpp \
    layouts/sprites_editor_menu_bar.cpp \
    layouts/sprites_editor_toolbar.cpp \
    layouts/sprites_editor_window.cpp \
    main.cpp \
    paint_area.cpp

HEADERS += \
    brushes/brush.h \
    brushes/brush_factory.h \
    brushes/pencil.h \
    color_picker.h \
    controllers/sprites_editor_menu_bar_controller.h \
    controllers/sprites_editor_window_controller.h \
    layouts/sprites_editor_menu_bar.h \
    layouts/sprites_editor_toolbar.h \
    layouts/sprites_editor_window.h \
    paint_area.h \

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


