#include "game/gui/screen/title.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Title::Title(QWidget *parent) : QWidget(parent) {

    // Title logo
    QPixmap img("://assets/img/title-logo.png");
    QLabel *logo = new QLabel;
    logo->setPixmap(img);
    logo->setMaximumHeight(80);

    // Buttons menu
    using Button = Game::GUI::Button;
    Button *play_button = new Button("Play", Palette::btn_success, this);
    Button *more_button = new Button("More", Palette::btn_primary, this);
    Button *exit_button = new Button("Exit", Palette::btn_danger, this);
    play_button->setFontSize(36);
    more_button->setFontSize(18);
    exit_button->setFontSize(18);

    // Menu layout
    QGridLayout *menu_layout = new QGridLayout(parent);
    menu_layout->addWidget(play_button, 0, 0, 0, 1);
    menu_layout->addWidget(more_button, 0, 1);
    menu_layout->addWidget(exit_button, 1, 1);

    // Window Layout (logo + menu)
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(logo);
    main_layout->addLayout(menu_layout);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(play_button, SIGNAL(clicked()), this, SIGNAL(playClicked()));
    this->connect(more_button, SIGNAL(clicked()), this, SIGNAL(moreClicked()));
    this->connect(exit_button, SIGNAL(clicked()), qApp, SLOT(quit()));
}

} // namespace Screen
} // namespace GUI
} // namespace Game
