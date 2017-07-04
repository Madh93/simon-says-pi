#include "game/gui/screen/stats.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Stats::Stats(QWidget *parent) : QWidget(parent) {

    // Back button
    using Button = Game::GUI::Button;
    Button *back_button = new Button("Back", Palette::btn_danger, this);
    back_button->setFontSize(18);
    back_button->setMinimumHeight(60);

    // Highscores table
    HighScore *highscore = new HighScore(this);

    // Main layout
    QVBoxLayout *main_layout = new QVBoxLayout(parent);
    main_layout->addWidget(highscore, 0, Qt::AlignCenter);
    main_layout->addWidget(back_button, 0, Qt::AlignBottom);
    main_layout->setStretch(0, 60);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(back_button, SIGNAL(clicked()), this, SIGNAL(backClicked()));
}

} // namespace Screen
} // namespace GUI
} // namespace Game
