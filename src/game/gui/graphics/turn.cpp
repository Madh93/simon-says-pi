#include "game/gui/graphics/turn.hpp"

namespace Game {
namespace GUI {
namespace Graphics {

Turn::Turn(QObject *parent) : QObject(parent), QGraphicsEllipseItem() {

    // Initial turn
    setComputerTurn();
    setUpText();

    // Ellipse settings
    this->setRect(135, 65, 50, 50);
    this->setBrush(QBrush(Palette::turn_background));

    update();
}

Game::Turn Turn::getCurrentTurn() { return turn; }

void Turn::nextTurn() {

    if (turn == Game::Turn::Computer) {
        setPlayerTurn();
    } else {
        setComputerTurn();
    }

    update();
}

void Turn::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    // Disable event propagation to tiles
    event->accept();
}

void Turn::setUpText() {

    text_item = new QGraphicsTextItem(this);
    text_item->setPos(133, 70);
    text_item->setScale(1.65);
    text_item->setDefaultTextColor(Palette::turn_font);
}

void Turn::setComputerTurn() {

    turn = Game::Turn::Computer;
    text = text_computer;
}

void Turn::setPlayerTurn() {

    turn = Game::Turn::Player;
    text = text_player;
}

void Turn::update() { text_item->setPlainText(text); }

} // namespace Graphics
} // namespace GUI
} // namespace Game
