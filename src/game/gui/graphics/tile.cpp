#include "game/gui/graphics/tile.hpp"

namespace Game {
namespace GUI {
namespace Graphics {

Tile::Tile(int x, int y, Color c, QObject *parent) :
    QObject(parent),
    QGraphicsRectItem() {

    color = c;

    switch (color) {
        case Color::Green : tile_color = Palette::tile_green; break;
        case Color::Red : tile_color = Palette::tile_red; break;
        case Color::Yellow : tile_color = Palette::tile_yellow; break;
        case Color::Blue : tile_color = Palette::tile_blue;
    }

    this->setBrush(QBrush(tile_color));
    this->setRect(x, y, 160, 90);
}

Color Tile::getColor() { return color; }

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    QColor pressed_color = tile_color.darker(125);

    if(event->button() == Qt::LeftButton) {
        this->setBrush(QBrush(pressed_color));
        emit clicked();
    }
}

void Tile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    if(event->button() == Qt::LeftButton) {
        this->setBrush(QBrush(tile_color));
    }
}

} // namespace Graphics
} // namespace GUI
} // namespace Game
