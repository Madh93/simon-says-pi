#include "game/gui/tile.hpp"

namespace Game {
namespace GUI {

Tile::Tile(int x, int y, const QColor &color, QObject *parent) :
    QObject(parent),
    QGraphicsRectItem(),
    tile_color(color) {

    this->setRect(x, y, 160, 90);
    this->setBrush(QBrush(tile_color));
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    QColor pressed_color = tile_color.darker(125);

    if(event->button() == Qt::LeftButton) {
        this->setBrush(QBrush(pressed_color));
    }
}

void Tile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    if(event->button() == Qt::LeftButton) {
        this->setBrush(QBrush(tile_color));
    }
}

} // namespace GUI
} // namespace Game
