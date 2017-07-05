#include "game/gui/screen/input.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Input::Input(QWidget *parent) : QWidget(parent) {

    // Accept button
    using Button = Game::GUI::Button;
    Button *accept_button = new Button("Accept", Palette::btn_success, this);
    accept_button->setFontSize(18);
    accept_button->setMinimumHeight(60);

    // Text label
    QLabel *text_label = new QLabel(this);
    text_label->setObjectName("input");
    text_label->setText("<center><h2>Enter your name</h2></center>");

    // Input widget
    input_widget = new InputWidget(this);

    // Main layout
    QVBoxLayout *main_layout = new QVBoxLayout(parent);
    main_layout->addWidget(text_label, 0, Qt::AlignTop);
    main_layout->addWidget(input_widget, 0, Qt::AlignCenter);
    main_layout->addWidget(accept_button, 0, Qt::AlignBottom);
    main_layout->setStretch(0, 60);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(accept_button, SIGNAL(clicked()), this, SIGNAL(acceptClicked()));
    this->connect(this, SIGNAL(acceptClicked()), this, SLOT(updateName()));
}

QString Input::getName() { return name; }

void Input::updateName() { name = input_widget->getName(); }

} // namespace Screen
} // namespace GUI
} // namespace Game
