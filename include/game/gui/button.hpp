#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QColor>
#include <QGraphicsDropShadowEffect>

#include <game/gui/palette.hpp>

namespace Game {
namespace GUI {

class Button : public QPushButton {

    Q_OBJECT
public:
    explicit Button(QString text, const QColor &color, QWidget *parent = 0);

    void setFontSize(int size);

signals:

public slots:

private:
    QColor button_style;

    void setUpStyle();
    void setUpEffect();
};

} // namespace GUI
} // namespace Game

#endif // BUTTON_HPP
