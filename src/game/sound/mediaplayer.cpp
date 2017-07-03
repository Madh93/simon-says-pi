#include "game/sound/mediaplayer.hpp"

namespace Game {
namespace Sound {

MediaPlayer::MediaPlayer(Audio name) {

    audio = name;
    setUpAudioFile();
}

void MediaPlayer::play() {

    if (disabled()) {
        return;
    } else {
        media->play();
    }
}

void MediaPlayer::setUpAudioFile() {

    QString filename;

    switch(audio) {
        case Audio::Green : filename = "://assets/sound/green.wav"; break;
        case Audio::Red : filename = "://assets/sound/red.wav"; break;
        case Audio::Yellow : filename = "://assets/sound/yellow.wav"; break;
        case Audio::Blue : filename = "://assets/sound/blue.wav";
    }

    if (disabled()) {
        return;
    } else {
        media = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource(filename));
    }
}

bool MediaPlayer::disabled() { return !Game::Settings::load("sound:enabled").toBool(); }

} // namespace Sound
} // namespace Game
