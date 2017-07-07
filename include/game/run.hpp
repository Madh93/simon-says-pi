#ifndef RUN_HPP
#define RUN_HPP

#include <QWidget>

#include "game/loop.hpp"
#include "game/network/api.hpp"

namespace Game {

    extern Game::Loop *gameloop;
    extern Game::Network::Api *api;

    void start(QWidget* widget);
    void upload(QString name, int score);
    void updateHighscore(QWidget* widget);

} // namespace Game

#endif // RUN_HPP
