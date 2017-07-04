#include "game/logic/colorsequence.hpp"

namespace Game {
namespace Logic {

ColorSequence::ColorSequence() {

    initializeSequence();
}

void ColorSequence::addColor() {

    for(int i = 0; i < initialSize; i++)
        addColor();
}

Color ColorSequence::getColorAtIndex(int index) { return sequence[index]; }

void ColorSequence::resetSequence() { sequence.clear(); }


int ColorSequence::getSequenceSize() { return sequence.size(); }


int ColorSequence::pickRandomColour() {

    int randomColour = rand() % 3;
    return randomColour;
}

void ColorSequence::initializeSequence() {

    for(int i = 0; i < initialSize; i++)
        addColor();
}


} // namespace Logic
} // namespace Game
