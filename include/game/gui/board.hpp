#ifndef BOARD_HPP
#define BOARD_HPP

#include <QObject>
#include <QGraphicsScene>

#include "game/gui/tile.hpp"

namespace Game {
namespace GUI {

class Board : public QGraphicsScene {

    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);

signals:

public slots:

protected:

private:
    QHash<QString, Game::GUI::Tile*> tiles;

    void setUpTiles();
};

} // namespace GUI
} // namespace Game

#endif // BOARD_HPP
