#ifndef BOARD_HPP
#define BOARD_HPP

#include <QObject>
#include <QGraphicsScene>

#include "game/gui/graphics/tile.hpp"
#include "game/gui/graphics/turn.hpp"

namespace Game {
namespace GUI {

class Board : public QGraphicsScene {

    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);

    Graphics::Tile *getTile(Color color);
    Graphics::Turn *getTurn();

signals:
    void enabledBoard(bool);
    void clicked(Color);
    void resetTurn();

public slots:
    void showColor(Color color);
    void reset();

protected:

private:
    QHash<QString, Graphics::Tile*> tiles;
    Graphics::Turn *turn;

    void setUpTiles();
    void setUpTurn();

    Graphics::Tile *getTileByColor(Color color);
};

} // namespace GUI
} // namespace Game

#endif // BOARD_HPP
