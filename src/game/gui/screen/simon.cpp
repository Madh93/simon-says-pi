#include "game/gui/screen/simon.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Simon::Simon(QWidget *parent) : QWidget(parent) {

    // Score label
    score = new Score(this);

    // Simon board game
    board = new Board(this);

    // Game Over scene
    gameover = new GameOver(this);

    // Add board into Graphics View
    board_view = new QGraphicsView(board, this);
    board_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Main layout (score + board)
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(score, 0, Qt::AlignCenter);
    main_layout->addWidget(board_view, 0, Qt::AlignBottom);
    main_layout->setMargin(0);

    this->setLayout(main_layout);
}

Game::GUI::Board* Simon::getBoard() { return board; }

Score *Simon::getScore() { return score; }

void Simon::showGameOver() {

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(hideGameOver()));

    board_view->setScene(gameover);
    timer->start(1000);
}

void Simon::hideGameOver() { board_view->setScene(board); emit gameOver(); }


} // namespace Screen
} // namespace GUI
} // namespace Game
