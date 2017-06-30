#include "game/gui/screen/about.hpp"

namespace Game {
namespace GUI {
namespace Screen {

About::About(QWidget *parent) : QWidget(parent) {

    // Back button
    using Button = Game::GUI::Button;
    Button *back_button = new Button("Back", Palette::btn_danger, this);
    back_button->setFontSize(18);
    back_button->setMinimumHeight(60);

    // About text
    QLabel *text_label = new QLabel(this);
    text_label->setObjectName("about");
    text_label->setText("<center><h1>Simon Says Pi</h1>"
                        "Final project for <i>Embedded Systems</i>"
                        "<h3>Developed by:</h3>"
                        "Miguel Angel Delgado Hernandez<br>"
                        "Hector Rodriguez Perez</center>"
                        );

    // Main layout
    QVBoxLayout *main_layout = new QVBoxLayout(parent);
    main_layout->addWidget(text_label, 0, Qt::AlignCenter);
    main_layout->addWidget(back_button, 0, Qt::AlignBottom);
    main_layout->setStretch(0, 60);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(back_button, SIGNAL(clicked()), this, SIGNAL(backClicked()));
}

} // namespace Screen
} // namespace GUI
} // namespace Game
