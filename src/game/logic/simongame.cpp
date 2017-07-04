#include "game/logic/simongame.hpp"

namespace Game {
namespace Logic {

SimonGame::SimonGame() {

}

bool SimonGame::checkColor(Color color) {

    if(sequence.getColorAtIndex(currentIndex) == color) {
        setNewGameState();
        return true;
    }

    return false;
}

void SimonGame::resetGame() {

    turn = 0;
    currentIndex = 0;
    sequence.resetSequence();
}

ColorSequence SimonGame::getColorSequence() { return sequence; }

bool SimonGame::isNewTurn() { return (currentIndex == 0); }

void SimonGame::setNewGameState() {

    if(lastColourInSequence()) {
        turn++;
        currentIndex = 0;
        addColorToSequence();
    } else {
        currentIndex++;
    }
}

void SimonGame::addColorToSequence() { sequence.addColor(); }

bool SimonGame::lastColourInSequence() {

    return (currentIndex == (sequence.getSequenceSize() - 1));
}

} // namespace Logic
} // namespace Game
