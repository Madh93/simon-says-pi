#include "game/gui/gameover.hpp"

namespace Game {
namespace GUI {

GameOver::GameOver(QObject *parent) : QGraphicsScene(parent) {

    // Scene settings
    this->setSceneRect(0, 0, 320, 180);

    // GameOver graphics elements
    setUpBackground();
    setUpText();
}

void GameOver::setUpBackground() {

    rect_item = new QGraphicsRectItem(0, 0, 320, 180);
    rect_item->setBrush(QBrush(Palette::gameover_background));
    this->addItem(rect_item);
}

void GameOver::setUpText() {

    text_item = new QGraphicsTextItem(rect_item);
    text_item->setPos(35, 50);
    text_item->setScale(3);
    text_item->setDefaultTextColor(Palette::gameover_font);
    text_item->setHtml("<b>GAME OVER</b>");
}


} // namespace GUI
} // namespace Game
