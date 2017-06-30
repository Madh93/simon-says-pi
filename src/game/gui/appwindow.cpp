#include "game/gui/appwindow.hpp"

namespace Game {
namespace GUI {

AppWindow::AppWindow(QMainWindow *parent) : QMainWindow(parent) {

    Screen::setUpDefaultScreen(this);

    // Screens
    screens["title"] = new Screen::Title(parent);
    screens["simon"] = new Screen::Simon(parent);
    screens["more"] = new Screen::More(parent);
    screens["about"] = new Screen::About(parent);

    // Stacked Widget to manage screens
    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(screens["title"]);
    stacked_widget->addWidget(screens["simon"]);
    stacked_widget->addWidget(screens["more"]);
    stacked_widget->addWidget(screens["about"]);

    // Show default screen
    this->setCentralWidget(stacked_widget);
    stacked_widget->setCurrentWidget(screens["title"]);

    // Signals & Slots
    this->connect(screens["title"], SIGNAL(moreClicked()), this, SLOT(loadMoreScreen()));
    this->connect(screens["title"], SIGNAL(playClicked()), this, SLOT(loadSimonScreen()));
    this->connect(screens["more"], SIGNAL(backClicked()), this, SLOT(loadTitleScreen()));
    this->connect(screens["more"], SIGNAL(aboutClicked()), this, SLOT(loadAboutScreen()));
    this->connect(screens["about"], SIGNAL(backClicked()), this, SLOT(loadMoreScreen()));
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

void AppWindow::loadAboutScreen() {
    stacked_widget->setCurrentWidget(screens["about"]);
}


} // namespace GUI
} // namespace Game
