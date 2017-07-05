#include "game/gui/graphics/tile.hpp"

#include <QDebug>
namespace Game {
namespace GUI {
namespace Graphics {

Tile::Tile(int x, int y, Color c, QObject *parent) :
    QObject(parent),
    QGraphicsRectItem() {

    this->setRect(x, y, 160, 90);

    color = c;
    getQColor();
    enabled = false;
    mediaplayer = new Game::Sound::MediaPlayer((Audio) color);

    update();
}

Color Tile::getColor() { return color; }

void Tile::resetColor() { getQColor(); update(); }

void Tile::setEnabled(bool condition) { enabled = condition; }

void Tile::simulatePressEvent() {

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulateReleaseEvent()));

    mediaplayer->play();
    setPressAnimation();
    timer->start(250);
}

void Tile::simulateReleaseEvent() { setReleaseAnimation(); }

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    if (enabled) {
        if(event->button() == Qt::LeftButton) {
            mediaplayer->play();
            setPressAnimation();
            emit clicked(color);
        }
    }
}

void Tile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    if(event->button() == Qt::LeftButton) {
        setReleaseAnimation();
    }
}

void Tile::getQColor() {

    switch (color) {
        case Color::Green : q_color = Palette::tile_green; break;
        case Color::Red : q_color = Palette::tile_red; break;
        case Color::Yellow : q_color = Palette::tile_yellow; break;
        case Color::Blue : q_color = Palette::tile_blue;
    }
}

void Tile::setPressAnimation() { q_color = q_color.darker(125); update(); }

void Tile::setReleaseAnimation() { q_color = q_color.lighter(125); update(); }

void Tile::update() { this->setBrush(QBrush(q_color)); }

} // namespace Graphics
} // namespace GUI
} // namespace Game
