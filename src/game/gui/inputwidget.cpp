#include "game/gui/inputwidget.hpp"

namespace Game {
namespace GUI {

InputWidget::InputWidget(QWidget *parent) : QWidget(parent) {

    // 4 letter selectors
    for (int i = 0; i < 4; i++) {
        letters << new LetterSelector(this);
    }

    // Main layout
    QHBoxLayout *layout = new QHBoxLayout(parent);
    foreach(LetterSelector *selector, letters) {
        layout->addWidget(selector, 0, Qt::AlignCenter);
    }

    this->setLayout(layout);
}

QString InputWidget::getName() {

    QString name;

    foreach(LetterSelector *letter, letters) {
        name.push_back(letter->getValue());
    }

    return name;
}


} // namespace GUI
} // namespace Game
