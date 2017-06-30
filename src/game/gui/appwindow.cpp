#include "game/gui/appwindow.hpp"
#include <QDebug>

namespace Game {
namespace GUI {

AppWindow::AppWindow(QMainWindow *parent) : QMainWindow(parent) {

    Screen::setUpDefaultScreen(this);

    // Screens
    screens["title"] = new Screen::Title(parent);
    screens["simon"] = new Screen::Simon(parent);
    screens["more"] = new Screen::More(parent);

    // Stacked Widget to manage screens
    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(screens["title"]);
    stacked_widget->addWidget(screens["simon"]);
    stacked_widget->addWidget(screens["more"]);

    // Show default screen
    this->setCentralWidget(stacked_widget);
    stacked_widget->setCurrentWidget(screens["title"]);

    // Signals & Slots
    this->connect(screens["title"], SIGNAL(moreClicked()), this, SLOT(loadMoreScreen()));
    this->connect(screens["title"], SIGNAL(playClicked()), this, SLOT(loadSimonScreen()));
    this->connect(screens["more"], SIGNAL(backClicked()), this, SLOT(loadTitleScreen()));
}

void AppWindow::loadTitleScreen() {
    stacked_widget->setCurrentWidget(screens["title"]);
}

void AppWindow::loadSimonScreen() {
    stacked_widget->setCurrentWidget(screens["simon"]);
}

void AppWindow::loadMoreScreen() {
    stacked_widget->setCurrentWidget(screens["more"]);
}


} // namespace GUI
} // namespace Game
