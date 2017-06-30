#include "game/gui/screen/simon.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Simon::Simon(QWidget *parent) : QWidget(parent) {

    // Score label
    score = new Score(this);

    // Simon board game
    board = new Board(this);

    // Turn widget
    turn = board->getTurn();

    // Add board into Graphics View
    QGraphicsView *board_view = new QGraphicsView(board, this);
    board_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Main layout (score + board)
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(score, 0, Qt::AlignCenter);
    main_layout->addWidget(board_view, 0, Qt::AlignBottom);
    main_layout->setMargin(0);

    this->setLayout(main_layout);
}


} // namespace Screen
} // namespace GUI
} // namespace Game
