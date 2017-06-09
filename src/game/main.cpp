#include <QApplication>

#include "game/gui/appwindow.hpp"

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    Game::GUI::AppWindow app_window;

    #if defined(Q_WS_QWS)
        app_window.showMaximized();
    #else
        app_window.show();
    #endif

    return app.exec();
}
