#ifndef TILE_HPP
#define TILE_HPP

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>

namespace Game {
namespace GUI {

// Tile style colours
static const QColor tile_green(32, 173, 138);
static const QColor tile_red(255, 111, 73);
static const QColor tile_yellow(255, 192, 59);
static const QColor tile_blue(0, 129, 195);

class Tile : public QObject, public QGraphicsRectItem {

    Q_OBJECT
public:
    explicit Tile(int x, int y, const QColor &color, QObject *parent = 0);

signals:

public slots:

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QColor tile_color;
};

} // namespace GUI
} // namespace Game

#endif // TILE_HPP
