#ifndef TURN_HPP
#define TURN_HPP

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#include "game/types.hpp"
#include "game/gui/palette.hpp"

namespace Game {
namespace GUI {
namespace Graphics {

// Available turns
static const QString text_computer = "CPU";
static const QString text_player = "YOU";

class Turn : public QObject, public QGraphicsEllipseItem {

    Q_OBJECT
public:
    explicit Turn(QObject *parent = 0);

    Game::Turn getCurrentTurn();

signals:

public slots:
    void nextTurn();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Game::Turn turn;
    QString text;
    QGraphicsTextItem *text_item;

    void setUpText();
    void update();
};

} // namespace Graphics
} // namespace GUI
} // namespace Game

#endif // TURN_HPP














//class myItem :public QGraphicsEllipseItem
//{
//public:
//paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 )
//{

//painter->drawText()    // Draw you text
//}

//};
