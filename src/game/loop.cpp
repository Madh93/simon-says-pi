#include "game/loop.hpp"

namespace Game {

Loop::Loop(QWidget *widget) : QObject(widget) {

    // Initialize basics
    screen = (Game::GUI::Screen::Simon*)widget;
    simon = new Game::Logic::SimonGame();
    status = Status::Waiting;

    // Timer settings
    setUpTimers();

    // Signals && Slots
    setUpSignalsSlots();

    emit enabledBoard(false);
}

void Loop::start() { timers["game"]->start(100); }

void Loop::run() {

    // Run forever while timers["game"] is enabled

    if (status == Status::Waiting)
        computerTurn(); // Show sequence
    else if (status == Status::Playing)
        playerTurn();   // Check colors
    else if (status == Status::GameOver)
        stopGame();
}

void Loop::receiveColor(Color c) { checkSequence(c); }

void Loop::showSequence() {

    emit colorShown(simon->getNextColor());

    update();
}

void Loop::checkSequence(Color color) {

    if (!simon->checkColor(color)) {
        status = Status::GameOver;
        return;
    }

    update();
}

void Loop::computerTurn() {

    if (!timers["computer"]->isActive()) {
        // Call showSequence() function
        timers["computer"]->start(1000);
    }
}

void Loop::playerTurn() {
    // Asynchronous call to checkSequence() when receivedColor() slot is activated
}

void Loop::setUpTimers() {

    // Create
    timers["game"] = new QTimer(this);
    timers["computer"] = new QTimer(this);

    // Set a interval
    timers["game"]->setInterval(50);
    timers["computer"]->setInterval(1000);

    // Signals && Slots
    this->connect(timers["game"], SIGNAL(timeout()), this, SLOT(run()));
    this->connect(timers["computer"], SIGNAL(timeout()), this, SLOT(showSequence()));
}

void Loop::setUpSignalsSlots() {

    // When Game Over
    this->connect(this, SIGNAL(gameOver()), screen, SLOT(showGameOver()));
    this->connect(this, SIGNAL(gameOver()), screen->getBoard(), SLOT(reset()));
    this->connect(this, SIGNAL(gameOver()), screen->getScore(), SLOT(resetScore()));

    // When change turn
    this->connect(this, SIGNAL(enabledBoard(bool)), screen->getBoard(), SIGNAL(enabledBoard(bool)));
    this->connect(this, SIGNAL(changedTurn()), screen->getBoard()->getTurn(), SLOT(nextTurn()));

    // When win new point
    this->connect(this, SIGNAL(newPoint()), screen->getScore(), SLOT(addScore()));

    // When computer/player push tiles
    this->connect(this, SIGNAL(colorShown(Color)), screen->getBoard(), SLOT(showColor(Color)));
    this->connect(screen->getBoard(), SIGNAL(clicked(Color)), this, SLOT(receiveColor(Color)));
}

void Loop::stopGame() {

    emit gameOver();
    emit enabledBoard(false);

    // Reset settings
    foreach (QTimer* timer, timers) {
        timer->stop();
    }

    status = Status::Waiting;
    simon->resetGame();
}

void Loop::update() {

    // Reset settings at the end of turn
    if (simon->isNewTurn()) {
        if (status == Status::Waiting) {
            timers["computer"]->stop();
            status = Status::Playing;
            emit enabledBoard(true);
        } else {
            status = Status::Waiting;
            simon->addColor();
            emit enabledBoard(false);
            emit newPoint();
        }

        emit changedTurn();
    }
}

} // namespace Game
