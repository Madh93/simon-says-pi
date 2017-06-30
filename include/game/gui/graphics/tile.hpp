#ifndef TILE_HPP
#define TILE_HPP

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QTimer>

#include "game/types.hpp"
#include "game/gui/palette.hpp"

namespace Game {
namespace GUI {
namespace Graphics {

class Tile : public QObject, public QGraphicsRectItem {

    Q_OBJECT
public:
    explicit Tile(int x, int y, Color c, QObject *parent = 0);

    Color getColor();

signals:
    void clicked();

public slots:
    void simulatePressEvent();
    void simulateReleaseEvent();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Color color;
    QColor q_color;

    void setPressAnimation();
    void setReleaseAnimation();
    void update();
};

} // namespace Graphics
} // namespace GUI
} // namespace Game

#endif // TILE_HPP
