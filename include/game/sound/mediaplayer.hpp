#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <phonon/mediaobject.h>

#include "game/types.hpp"

namespace Game {
namespace Sound {

class MediaPlayer {

public:
    explicit MediaPlayer(Audio name);

    void play();

signals:

public slots:

protected:

private:
    Audio audio;
    Phonon::MediaObject *media;

    void setUpAudioFile();
};

} // namespace Sound
} // namespace Game

#endif // PLAYER_HPP
