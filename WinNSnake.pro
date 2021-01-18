QT       += core gui widgets
TARGET = WinNSnake
CONFIG+=console
TRANSLATIONS+= winnsnake_nl.ts
CONFIG+=static
QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
DEFINES+=STATIC
DEFINES += "VERSION=1.0.0"
DEFINES += "DATE=27-DEC-2020"
DEFINES += "PACKAGE=PACKAGE"
SOURCES += \
    src/main.cpp \
    src/Display/Animations/AnimationFire.cpp \
    src/Display/Animations/AnimationGameOfLife.cpp \
    src/Display/Animations/AnimationSnakes.cpp \
    src/Display/Animations/AnimationWater.cpp \
    src/Display/Layouts/LayoutFirstTime.cpp \
    src/Display/Layouts/LayoutGame.cpp \
    src/Display/Layouts/LayoutMainMenu.cpp \
    src/Display/WindowGameHelp.cpp \
    src/Entities/Board.cpp \
    src/Entities/BoardParser.cpp \
    src/Entities/FruitManager.cpp \
    src/Entities/Game.cpp \
    src/Entities/Player.cpp \
    src/Entities/ScoreFile.cpp \
    src/States/GameStateGame.cpp \
    src/States/GameStateMainMenu.cpp \
    deps/commander/commander.c \
    deps/Engine/Flow/StateManager.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem/MenuItemCheckbox.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem/MenuItemLabel.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem/MenuItemNumberbox.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem/MenuItemTextbox.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem/MenuItemTextlist.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuAlphabetic.cpp \
    deps/Engine/Graphics/Widgets/Menu/MenuItem.cpp \
    deps/Engine/Graphics/Widgets/Dialog.cpp \
    deps/Engine/Graphics/Widgets/Menu.cpp \
    deps/Engine/Graphics/Colors.cpp \
    deps/Engine/Graphics/Layout.cpp \
    deps/Engine/Graphics/Ncurses.cpp \
    deps/Engine/Graphics/Window.cpp \
    deps/Engine/Helpers/Base64.cpp \
    deps/Engine/Helpers/File.cpp \
    deps/Engine/Helpers/INI.cpp \
    deps/Engine/Helpers/String.cpp \
    deps/Engine/Helpers/Timer.cpp \
    deps/Engine/Helpers/Utils.cpp \
    deps/Engine/EngineGlobals.cpp \
    deps/Engine/InputManager.cpp \
    src/Config/Globals.cpp \
    src/Config/Arguments.cpp
HEADERS += \
    deps/commander/commander.h \
    doc/doxygen_mainpage.hpp \
    src/Display/Animations/AnimationFire.hpp \
    src/Display/Animations/AnimationGameOfLife.hpp \
    src/Display/Animations/AnimationSnakes.hpp \
    src/Display/Animations/AnimationWater.hpp \
    src/Display/Layouts/LayoutFirstTime.hpp \
    src/Display/Layouts/LayoutGame.hpp \
    src/Display/Layouts/LayoutMainMenu.hpp \
    src/Display/WindowGameHelp.hpp \
    src/Entities/Board.hpp \
    src/Entities/BoardParser.hpp \
    src/Entities/FruitManager.hpp \
    src/Entities/Game.hpp \
    src/Entities/Player.hpp \
    src/Entities/ScoreFile.hpp \
    src/States/GameStateGame.hpp \
    src/States/GameStateMainMenu.hpp
FORMS +=
INCLUDEPATH += deps/
SUBDIRS += deps/
SUBDIRS += src/
INCLUDEPATH += src/
INCLUDEPATH += $$(PDCURSES_ROOT)
LIBS += -L$$(PDCURSES_ROOT)/wincon -lpdcurses

RESOURCES += \
    winnsnake.qrc


INCLUDEPATH +=$$(SHOWLICENSE_ROOT)
LIBS += -L$$(SHOWLICENSE_ROOT) -lshowlicense
