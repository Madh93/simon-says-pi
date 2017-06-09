TARGET = simon-says-pi
target.path = /
INSTALLS += target


INCLUDEPATH += include


HEADERS += \
    include/game/gui/appwindow.hpp \
    include/game/gui/button.hpp \
    include/game/gui/screen/base.hpp \
    include/game/gui/screen/more.hpp \
    include/game/gui/screen/title.hpp


SOURCES += \
    src/game/main.cpp \
    src/game/gui/appwindow.cpp \
    src/game/gui/button.cpp \
    src/game/gui/screen/base.cpp \
    src/game/gui/screen/more.cpp \
    src/game/gui/screen/title.cpp


RESOURCES += \
    resources.qrc


QMAKE_CXXFLAGS += -std=c++11
