#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include "game/gui/palette.hpp"

namespace Game {
namespace GUI {

class GameOver : public QGraphicsScene {

    Q_OBJECT
public:
    explicit GameOver(QObject *parent = 0);

signals:

public slots:

protected:

private:
    QGraphicsRectItem *rect_item;
    QGraphicsTextItem *text_item;

    void setUpBackground();
    void setUpText();
};

} // namespace GUI
} // namespace Game

#endif // GAMEOVER_HPP
