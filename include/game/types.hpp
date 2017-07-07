#ifndef TYPES_HPP
#define TYPES_HPP

namespace Game {

enum class Color {
    Green,
    Red,
    Yellow,
    Blue
};

enum class Turn {
    Computer,
    Player
};

enum class Audio {
    Green,
    Red,
    Yellow,
    Blue
};

enum class Status {
    Waiting,
    Playing,
    GameOver,
};

enum class Direction {
    LeftToRight,
    RightToLeft,
    TopToBottom,
    BottomToTop
};

enum class LedType {
    Success,
    Failure
};

} // namespace Game

#endif // TYPES_HPP
