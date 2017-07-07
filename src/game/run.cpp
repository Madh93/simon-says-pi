#include "game/run.hpp"

namespace Game {

Game::Loop *gameloop = NULL;
Game::Network::Api *api = NULL;

void start(QWidget* widget) {

    if (gameloop == NULL) {
        gameloop = new Game::Loop(widget);
    }

    gameloop->start();
}

void upload(QString name, int score) {

    if (api == NULL) {
        api = new Game::Network::Api();
    }

    api->uploadScore(name, score);
}

void updateHighscore(QWidget* widget) {

    if (api == NULL) {
        api = new Game::Network::Api();
    }

    // Important: connect get petition with stats screen
    qApp->connect(api, SIGNAL(topHighscores(QVector<QVector<QString> >)),
            (Game::GUI::Screen::Stats*)widget, SLOT(showHighscore(QVector<QVector<QString> >)));

    api->getHighscores();
}

} // namespace Game
