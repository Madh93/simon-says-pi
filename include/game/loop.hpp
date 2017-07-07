#ifndef LOOP_HPP
#define LOOP_HPP

#include <QObject>
#include <QWidget>
#include <QTimer>

#include <game/logic/simongame.hpp>
#include <game/gui/screen/simon.hpp>
#include <game/gui/screen/stats.hpp>

namespace Game {

class Loop : public QObject {

    Q_OBJECT
public:
    explicit Loop(QWidget *widget);

    void start();

signals:
    void changedTurn();
    void enabledBoard(bool);
    void colorShown(Color);
    void newPoint();
    void gameOver();

public slots:
    void run();
    void receiveColor(Color c);
    void showSequence();
    void checkSequence(Color color);

private:
    Game::Logic::SimonGame *simon;
    Game::GUI::Screen::Simon *screen;
    QHash <QString, QTimer*> timers;
    Status status;

    void computerTurn();
    void playerTurn();
    void setUpTimers();
    void setUpSignalsSlots();
    void stopGame();

    void update();
};

} // namespace Game

#endif // LOOP_HPP
