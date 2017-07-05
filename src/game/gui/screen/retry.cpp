#include "game/gui/screen/retry.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Retry::Retry(QWidget *parent) : QWidget(parent) {

    // Buttons menu
    using Button = Game::GUI::Button;
    Button *back_button = new Button("Back", Palette::btn_danger, this);
    back_button->setFontSize(24);
    back_button->setMinimumHeight(120);
    back_button->setMaximumHeight(120);

    Button *retry_button = new Button("Retry", Palette::btn_success, this);
    retry_button->setFontSize(24);
    retry_button->setMinimumHeight(120);
    retry_button->setMaximumHeight(120);

    // Score label
    score_label = new QLabel(this);
    score_label->setObjectName("score");
    score_label->setText("<center>Your score: 0</center>");

    // Main layout
    QGridLayout *main_layout = new QGridLayout(parent);
    main_layout->addWidget(score_label, 0, 0, 0, 0, Qt::AlignTop);
    main_layout->addWidget(back_button, 1, 0, Qt::AlignVCenter);
    main_layout->addWidget(retry_button, 1, 1, Qt::AlignVCenter);
    main_layout->setRowStretch(1, 50);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(back_button, SIGNAL(clicked()), this, SIGNAL(backClicked()));
    this->connect(retry_button, SIGNAL(clicked()), this, SIGNAL(retryClicked()));
}

void Retry::setScore(int score) {

    score_label->setText(QString("<center>Your score: %1</center>").arg(score));
}

} // namespace Screen
} // namespace GUI
} // namespace Game
