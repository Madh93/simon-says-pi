#ifndef SIMONGAME_HPP
#define SIMONGAME_HPP

#include "game/logic/colorsequence.hpp"

namespace Game {
namespace Logic {

class SimonGame {

public:
    explicit SimonGame();
    ~SimonGame();

    bool checkColor(Color color);
    void resetGame();
    ColorSequence *getColorSequence();
    Color getNextColor();
    bool isNewTurn();
    void addColor();

private:
    ColorSequence *sequence;
    int turn;
    int currentIndex;

    void setNewGameState();
    void addColorToSequence();
    bool lastColourInSequence();
};

} // namespace Logic
} // namespace Game

#endif // SIMONGAME_HPP
