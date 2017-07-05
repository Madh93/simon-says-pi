#include "game/gui/board.hpp"

namespace Game {
namespace GUI {

Board::Board(QObject *parent) : QGraphicsScene(parent) {

    // Scene settings
    this->setSceneRect(0, 0, 320, 180);

    // Board graphics elements
    setUpTiles();
    setUpTurn();

    // Signals && Slots
    this->connect(this, SIGNAL(resetTurn()), turn, SLOT(resetTurn()));
}

Graphics::Tile *Board::getTile(Color color) { return getTileByColor(color); }

Graphics::Turn *Board::getTurn() { return turn; }

void Board::showColor(Color color) { getTile(color)->simulatePressEvent(); }

void Board::reset() {

    foreach (Graphics::Tile *tile, tiles) {
        tile->resetColor();
    }
    emit resetTurn();
}

void Board::setUpTiles() {

    using Tile = Graphics::Tile;

    tiles["green"] = new Tile(0, 0, Color::Green, this);
    tiles["red"] = new Tile(160, 0, Color::Red, this);
    tiles["yellow"] = new Tile(0, 90, Color::Yellow, this);
    tiles["blue"] = new Tile(160, 90, Color::Blue, this);

    foreach (Tile *tile, tiles) {
        this->addItem(tile);
        connect(tile, SIGNAL(clicked(Color)), this, SIGNAL(clicked(Color)));
        connect(this, SIGNAL(enabledBoard(bool)), tile, SLOT(setEnabled(bool)));
    }
}

void Board::setUpTurn() {

    turn = new Graphics::Turn(this);
    this->addItem(turn);
}

Graphics::Tile *Board::getTileByColor(Color color) {

    switch (color) {
        case Color::Green : return tiles["green"]; break;
        case Color::Red : return tiles["red"]; break;
        case Color::Yellow : return tiles["yellow"]; break;
        default : return tiles["blue"];
    }
}

} // namespace GUI
} // namespace Game
