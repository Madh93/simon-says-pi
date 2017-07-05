#ifndef RUN_HPP
#define RUN_HPP

#include <QWidget>

#include "game/loop.hpp"

namespace Game {

    static Game::Loop *gameloop = NULL;

    void start(QWidget* widget);

} // namespace Game

#endif // RUN_HPP
