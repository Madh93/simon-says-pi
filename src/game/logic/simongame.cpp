#include "game/logic/simongame.hpp"

namespace Game {
namespace Logic {

SimonGame::SimonGame() {

    sequence = new Game::Logic::ColorSequence;
    currentIndex = 0;
}

SimonGame::~SimonGame() {

    if (sequence) {
        delete sequence;
        sequence = NULL;
    }
}

bool SimonGame::checkColor(Color color) {

    if(sequence->getColorAtIndex(currentIndex) == color) {
        setNewGameState();
        return true;
    }

    return false;
}

void SimonGame::resetGame() {

    turn = 0;
    currentIndex = 0;
    sequence->resetSequence();
}

ColorSequence *SimonGame::getColorSequence() { return sequence; }

Color SimonGame::getNextColor() {

    int index = currentIndex;

    if (lastColourInSequence()) {
        currentIndex = 0;
    } else {
        currentIndex++;
    }

    return sequence->getColorAtIndex(index);
}

bool SimonGame::isNewTurn() { return (currentIndex == 0); }

void SimonGame::addColor() { addColorToSequence(); }

void SimonGame::setNewGameState() {

    if(lastColourInSequence()) {
        turn++;
        currentIndex = 0;
    } else {
        currentIndex++;
    }
}

void SimonGame::addColorToSequence() { sequence->addColor(); }

bool SimonGame::lastColourInSequence() {

    return (currentIndex == (sequence->getSequenceSize() - 1));
}

} // namespace Logic
} // namespace Game
