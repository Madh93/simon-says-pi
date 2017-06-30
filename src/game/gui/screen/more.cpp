#include "game/gui/screen/more.hpp"

namespace Game {
namespace GUI {
namespace Screen {

More::More(QWidget *parent) : QWidget(parent) {

    // Buttons menu
    using Button = Game::GUI::Button;
    Button *back_button = new Button("Back", Palette::btn_danger, this);
    Button *stats_button = new Button("Stats", Palette::btn_primary, this);
    Button *about_button = new Button("About", Palette::btn_primary, this);
    stats_button->setFontSize(24);
    about_button->setFontSize(24);
    back_button->setFontSize(18);

    // Buttons size
    stats_button->setMinimumHeight(120);
    about_button->setMinimumHeight(120);
    stats_button->setMaximumHeight(120);
    about_button->setMaximumHeight(120);
    back_button->setMinimumHeight(60);

    // Main layout
    QGridLayout *main_layout = new QGridLayout(parent);
    main_layout->addWidget(stats_button, 0, 0, Qt::AlignVCenter);
    main_layout->addWidget(about_button, 0, 1, Qt::AlignVCenter);
    main_layout->addWidget(back_button, 1, 0, 1, 0, Qt::AlignBottom);
    main_layout->setRowStretch(0, 60);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(back_button, SIGNAL(clicked()), this, SIGNAL(backClicked()));
}

} // namespace Screen
} // namespace GUI
} // namespace Game
