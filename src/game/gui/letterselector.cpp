#include "game/gui/letterselector.hpp"

#include <QDebug>
namespace Game {
namespace GUI {

LetterSelector::LetterSelector(QWidget *parent) : QWidget(parent) {

    // Initial letter
    index = 0;

    // Control buttons
    using Button = Game::GUI::Button;
    Button *prev_button = new Button(QChar(0x25B2), Palette::btn_info, this);
    prev_button->setFontSize(12);
    prev_button->setMinimumHeight(34);
    prev_button->setMinimumWidth(50);
    prev_button->setAutoRepeat(true);
    prev_button->setAutoRepeatDelay(400);
    prev_button->setAutoRepeatInterval(100);

    Button *next_button = new Button(QChar(0x25BC), Palette::btn_info, this);
    next_button->setFontSize(12);
    next_button->setMinimumHeight(34);
    next_button->setMinimumWidth(50);
    next_button->setAutoRepeat(true);
    next_button->setAutoRepeatDelay(400);
    next_button->setAutoRepeatInterval(100);

    // Text label
    letter_label = new QLabel(this);
    letter_label->setObjectName("letterselector");
    update();

    // Main layout
    QVBoxLayout *layout = new QVBoxLayout(parent);
    layout->addWidget(prev_button, 0, Qt::AlignTop);
    layout->addWidget(letter_label, 0, Qt::AlignCenter);
    layout->addWidget(next_button, 0, Qt::AlignBottom);
    layout->addSpacing(2);

    this->setLayout(layout);

    // Signals && Slots
    connect(prev_button, SIGNAL(clicked()), this, SLOT(prevLetter()));
    connect(next_button, SIGNAL(clicked()), this, SLOT(nextLetter()));
}

QChar LetterSelector::getValue() { return QChar(getAscii()); }

void LetterSelector::nextLetter() { index++; update(); }

void LetterSelector::prevLetter() { index--; update(); }

int LetterSelector::getAscii() { return 65 + mod(index, 26); }

int LetterSelector::mod(int k, int n) { return ((k %= n) < 0) ? k+n : k; }

void LetterSelector::update() {

    letter_label->setText(QString("<h1>%1</h1>").arg(getValue()));
}


} // namespace GUI
} // namespace Game
