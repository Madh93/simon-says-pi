#ifndef COLORSEQUENCE_HPP
#define COLORSEQUENCE_HPP

#include <QVector>
#include <QTime>

#include "game/types.hpp"

namespace Game {
namespace Logic {

class ColorSequence {

public:
    explicit ColorSequence();

    void addColor();
    Color getColorAtIndex(int index);
    void resetSequence();
    int getSequenceSize();

private:
    QVector<Color> sequence;
    const int initialSize = 1;

    Color pickRandomColour();
    void initializeSequence();
};

} // namespace Logic
} // namespace Game

#endif // COLORSQUENCE_HPP
