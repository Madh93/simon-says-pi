#include "game/gui/graphics/turn.hpp"

#include <QDebug>

namespace Game {
namespace GUI {
namespace Graphics {

Turn::Turn(QObject *parent) : QObject(parent), QGraphicsEllipseItem() {

    // Ellipse settings
    this->setRect(135, 65, 50, 50);
    this->setBrush(QBrush(Game::GUI::Color::turn_background));

    // Text settings
    setUpText();
}

int Turn::getCurrentTurn() {

    return text->toPlainText() == cpu_turn ? 0 : 1;
}

void Turn::nextTurn() {

    if (text->toPlainText() == cpu_turn) {
        text->setPlainText(player_turn);
    } else {
        text->setPlainText(cpu_turn);
    }
}

void Turn::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    // Disable event propagation
    event->accept();
}

void Turn::setUpText() {

    text = new QGraphicsTextItem(cpu_turn, this);
    text->setPos(133, 70);
    text->setScale(1.65);
    text->setDefaultTextColor(Game::GUI::Color::turn_font);
}

} // namespace Graphics
} // namespace GUI
} // namespace Game
