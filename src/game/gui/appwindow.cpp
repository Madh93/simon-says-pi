#include "game/gui/appwindow.hpp"

namespace Game {
namespace GUI {

AppWindow::AppWindow(QMainWindow *parent) : QMainWindow(parent) {

    Screen::setUpDefaultScreen(this);

    // Screens
    screens["title"] = new Screen::Title(parent);
    screens["simon"] = new Screen::Simon(parent);
    screens["input"] = new Screen::Input(parent);
    screens["retry"] = new Screen::Retry(parent);
    screens["more"] = new Screen::More(parent);
    screens["stats"] = new Screen::Stats(parent);
    screens["about"] = new Screen::About(parent);

    // Stacked Widget to manage screens
    stacked_widget = new StackedWidget(this);

    foreach (QWidget *screen, screens.values()) {
        stacked_widget->addWidget(screen);
    }

    // Show default screen
    this->setCentralWidget(stacked_widget);
    stacked_widget->setCurrentWidget(screens["title"]);

    // Signals & Slots
    setUpSignalsSlots();
}

void AppWindow::loadTitleScreen() {

    if (currentScreen() == screens["simon"]) {
        direction = Direction::BottomToTop;
    } else if (currentScreen() == screens["retry"]) {
        direction = Direction::BottomToTop;
    } else {
        direction = Direction::TopToBottom;
    }

    update(screens["title"]);
}

void AppWindow::loadSimonScreen() {

    if (currentScreen() == screens["title"]) {
        direction = Direction::TopToBottom;
    } else {
        direction = Direction::LeftToRight;
    }

    update(screens["simon"]);

    // Start game
    Game::start(screens["simon"]);
}

void AppWindow::loadInputScreen() {

    direction = Direction::RightToLeft;
    update(screens["input"]);
}

void AppWindow::loadRetryScreen() {

    direction = Direction::RightToLeft;
    update(screens["retry"]);

    QString name = ((Screen::Input*)screens["input"])->getName();
    int score = ((Screen::Simon*)screens["simon"])->getScore()->getScore();

    // Pass score to retry screen
    ((Screen::Retry*)screens["retry"])->setScore(score);

    // Upload results
    Game::upload(name, score);
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

    // Get top highscores
    Game::updateHighscore(screens["stats"]);
}

void AppWindow::loadAboutScreen() {

    direction = Direction::RightToLeft;
    update(screens["about"]);
}

void AppWindow::setUpSignalsSlots() {

    // Title screen
    this->connect(screens["title"], SIGNAL(moreClicked()), this, SLOT(loadMoreScreen()));
    this->connect(screens["title"], SIGNAL(playClicked()), this, SLOT(loadSimonScreen()));
    this->connect(screens["title"], SIGNAL(playClicked()), screens["simon"], SLOT(reset()));

    // Simon screen
    this->connect(screens["simon"], SIGNAL(gameOver()), this, SLOT(loadInputScreen()));

    // Input screen
    this->connect(screens["input"], SIGNAL(acceptClicked()), this, SLOT(loadRetryScreen()));

    // Retry screen
    this->connect(screens["retry"], SIGNAL(backClicked()), this, SLOT(loadTitleScreen()));
    this->connect(screens["retry"], SIGNAL(retryClicked()), this, SLOT(loadSimonScreen()));
    this->connect(screens["retry"], SIGNAL(retryClicked()), screens["simon"], SLOT(reset()));

    // More screen
    this->connect(screens["more"], SIGNAL(backClicked()), this, SLOT(loadTitleScreen()));
    this->connect(screens["more"], SIGNAL(statsClicked()), this, SLOT(loadStatsScreen()));
    this->connect(screens["more"], SIGNAL(aboutClicked()), this, SLOT(loadAboutScreen()));

    // Stats screen
    this->connect(screens["stats"], SIGNAL(backClicked()), this, SLOT(loadMoreScreen()));

    // About screen
    this->connect(screens["about"], SIGNAL(backClicked()), this, SLOT(loadMoreScreen()));
}

QWidget *AppWindow::currentScreen() { return stacked_widget->currentWidget(); }

void AppWindow::update(QWidget *screen) { stacked_widget->setAnimatedTransition(screen, direction); }

} // namespace GUI
} // namespace Game
