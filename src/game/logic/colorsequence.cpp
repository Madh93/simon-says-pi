#include "game/logic/colorsequence.hpp"

namespace Game {
namespace Logic {

ColorSequence::ColorSequence() {

    initializeSequence();
}

void ColorSequence::addColor() {

    sequence << pickRandomColour();
}

Color ColorSequence::getColorAtIndex(int index) { return sequence[index]; }

void ColorSequence::resetSequence() { sequence.clear(); addColor(); }


int ColorSequence::getSequenceSize() { return sequence.size(); }


Color ColorSequence::pickRandomColour() {

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int randomColour = qrand() % 4;
    return (Color)randomColour;
}

void ColorSequence::initializeSequence() {

    for(int i = 0; i < initialSize; i++)
        addColor();
}


} // namespace Logic
} // namespace Game
