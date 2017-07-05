#ifndef SIMON_HPP
#define SIMON_HPP

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGraphicsView>

#include "game/gui/screen/base.hpp"
#include "game/gui/board.hpp"
#include "game/gui/button.hpp"
#include "game/gui/gameover.hpp"
#include "game/gui/score.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Simon : public QWidget {

    Q_OBJECT
public:
    explicit Simon(QWidget *parent = 0);

    Game::GUI::Board *getBoard();
    Game::GUI::Score *getScore();

signals:
    void backClicked();
    void gameOver();

public slots:
    void showGameOver();
    void reset();

private:
    QGraphicsView *board_view;
    Game::GUI::Board *board;
    Game::GUI::GameOver *gameover;
    Game::GUI::Score *score;
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // SIMON_HPP
