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

enum class LedType {
    Success,
    Failure
};

} // namespace Game

#endif // TYPES_HPP
