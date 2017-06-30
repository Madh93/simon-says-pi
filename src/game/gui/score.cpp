#include "game/gui/score.hpp"

namespace Game {
namespace GUI {

Score::Score(QWidget *parent) : QLabel(parent) {

    this->setStyleSheet("QLabel { color:white; font: bold 36px; }");
    score = 0;

    update();
}

int Score::getScore() { return score; }

void Score::resetScore() { score = 0; update(); }

void Score::addScore() { score += 1; update(); }


void Score::update() { this->setText(QString("Score: %1").arg(score)); }

} // namespace GUI
} // namespace Game
