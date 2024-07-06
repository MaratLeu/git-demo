QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chosing_character.cpp \
    game.cpp \
    game_nikita.cpp \
    game_usach.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chosing_character.h \
    game.h \
    game_nikita.h \
    game_usach.h \
    mainwindow.h

FORMS += \
    chosing_character.ui \
    game.ui \
    game_nikita.ui \
    game_usach.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    winresourse.qrc \
    winresourse.qrc
