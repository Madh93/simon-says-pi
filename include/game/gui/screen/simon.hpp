#ifndef SIMON_HPP
#define SIMON_HPP

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include "game/gui/screen/base.hpp"
#include "game/gui/board.hpp"
#include "game/gui/button.hpp"
#include "game/gui/score.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Simon : public QWidget {

    Q_OBJECT
public:
     explicit Simon(QWidget *parent = 0);

signals:
    void backClicked();

public slots:

private:
    Game::GUI::Board *board;
    Game::GUI::Score *score;
    Game::GUI::Graphics::Turn *turn;
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // SIMON_HPP
