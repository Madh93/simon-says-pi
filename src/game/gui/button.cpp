#include "game/gui/button.hpp"

namespace Game {
namespace GUI {


Button::Button(QString text, const QColor &color, QWidget *parent):
    QPushButton(text, parent),
    button_style(color) {

    this->setObjectName("button");

    setUpStyle();
    setUpEffect();

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    this->setSizePolicy(sizePolicy);
}

void Button::setFontSize(int size) {

    this->setFont(QFont("Comic Sans", size));
}

void Button::setUpStyle() {

    QString normal_color = button_style.name();
    QString pressed_color = button_style.darker(125).name();

    // Pressed color animation
    this->setStyleSheet(QString(
                        "QPushButton#button {"
                            "background-color: %1; }"
                        "QPushButton#button:pressed {"
                            "background-color: %2; }"
                        ).arg(normal_color, pressed_color));
}

void Button::setUpEffect() {

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(1);
    effect->setOffset(1,1);
    this->setGraphicsEffect(effect);
}


} // namespace GUI
} // namespace Game
