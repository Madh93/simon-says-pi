#include "game/gui/board.hpp"

namespace Game {
namespace GUI {

Board::Board(QObject *parent) : QGraphicsScene(parent) {

    // Scene settings
    this->setSceneRect(0, 0, 320, 180);

    // Tiles
    setUpTiles();
}

void Board::setUpTiles() {

    using Game::GUI::Tile;

    tiles["green"] = new Tile(0, 0, tile_green, this);
    tiles["red"] = new Tile(160, 0, tile_red, this);
    tiles["yellow"] = new Tile(0, 90, tile_yellow, this);
    tiles["blue"] = new Tile(160, 90, tile_blue, this);

    foreach (Tile *tile, tiles) {
        this->addItem(tile);
    }
}

} // namespace GUI
} // namespace Game
