#include "game/run.hpp"

namespace Game {

void start(QWidget* widget) {

    if (gameloop == NULL) {
        gameloop = new Game::Loop(widget);
    }

    gameloop->start();
}

} // namespace Game
