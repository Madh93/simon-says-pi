#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <phonon/mediaobject.h>

#include "game/types.hpp"
#include "game/settings/manager.hpp"

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
    bool disabled();
};

} // namespace Sound
} // namespace Game

#endif // PLAYER_HPP
