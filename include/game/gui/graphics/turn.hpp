#ifndef TURN_HPP
#define TURN_HPP

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#include "game/gui/color.hpp"

namespace Game {
namespace GUI {
namespace Graphics {

// Available turns
static const QString cpu_turn = "CPU";
static const QString player_turn = "YOU";

class Turn : public QObject, public QGraphicsEllipseItem {

    Q_OBJECT
public:
    explicit Turn(QObject *parent = 0);

    int getCurrentTurn();

signals:

public slots:
    void nextTurn();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsTextItem *text;

    void setUpText();
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
