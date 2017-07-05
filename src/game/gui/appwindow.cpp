#include "game/gui/appwindow.hpp"

namespace Game {
namespace GUI {

AppWindow::AppWindow(QMainWindow *parent) : QMainWindow(parent) {

    Screen::setUpDefaultScreen(this);

    // Screens
    screens["title"] = new Screen::Title(parent);
    screens["simon"] = new Screen::Simon(parent);
    screens["more"] = new Screen::More(parent);
    screens["stats"] = new Screen::Stats(parent);
    screens["about"] = new Screen::About(parent);

    // Stacked Widget to manage screens
    stacked_widget = new StackedWidget(this);
    stacked_widget->addWidget(screens["title"]);
    stacked_widget->addWidget(screens["simon"]);
    stacked_widget->addWidget(screens["more"]);
    stacked_widget->addWidget(screens["stats"]);
    stacked_widget->addWidget(screens["about"]);

    // Show default screen
    this->setCentralWidget(stacked_widget);
    stacked_widget->setCurrentWidget(screens["title"]);

    // Signals & Slots
    this->connect(screens["title"], SIGNAL(moreClicked()), this, SLOT(loadMoreScreen()));
    this->connect(screens["title"], SIGNAL(playClicked()), this, SLOT(loadSimonScreen()));
    this->connect(screens["simon"], SIGNAL(gameOver()), this, SLOT(loadTitleScreen()));
    this->connect(screens["more"], SIGNAL(backClicked()), this, SLOT(loadTitleScreen()));
    this->connect(screens["more"], SIGNAL(statsClicked()), this, SLOT(loadStatsScreen()));
    this->connect(screens["more"], SIGNAL(aboutClicked()), this, SLOT(loadAboutScreen()));
    this->connect(screens["stats"], SIGNAL(backClicked()), this, SLOT(loadMoreScreen()));
    this->connect(screens["about"], SIGNAL(backClicked()), this, SLOT(loadMoreScreen()));
}

void AppWindow::loadTitleScreen() {

    if (currentScreen() == screens["simon"]) {
        direction = Direction::BottomToTop;
    } else {
        direction = Direction::TopToBottom;
    }

    update(screens["title"]);
}

void AppWindow::loadSimonScreen() {

    direction = Direction::TopToBottom;
    update(screens["simon"]);

    // Start game
    Game::start(screens["simon"]);
}

void AppWindow::loadMoreScreen() {

    if (currentScreen() == screens["title"]) {
        direction = Direction::BottomToTop;
    } else if (currentScreen() == screens["about"]) {
        direction = Direction::LeftToRight;
    } else if (currentScreen() == screens["stats"]) {
        direction = Direction::RightToLeft;
    }

    update(screens["more"]);
}

void AppWindow::loadStatsScreen() {

    direction = Direction::LeftToRight;
    update(screens["stats"]);
}

void AppWindow::loadAboutScreen() {

    direction = Direction::RightToLeft;
    update(screens["about"]);
}

QWidget *AppWindow::currentScreen() { return stacked_widget->currentWidget(); }

void AppWindow::update(QWidget *screen) { stacked_widget->setAnimatedTransition(screen, direction); }

} // namespace GUI
} // namespace Game
