#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QColor>
#include <QGraphicsDropShadowEffect>

namespace Game {
namespace GUI {

// Button style colours (based on Bootstrap)
static const QColor btn_default(204, 204, 204);
static const QColor btn_primary(46, 109, 164);
static const QColor btn_success(76, 174, 76);
static const QColor btn_info(70, 184, 218);
static const QColor btn_warning(213, 133, 18);
static const QColor btn_danger(212, 63, 58);

class Button : public QPushButton {

    Q_OBJECT
public:
    explicit Button(QString text, const QColor &color, QWidget *parent = 0);
    void setFontSize(int size);

protected:
//    void paintEvent(QPaintEvent *event);

private:
    QColor button_style;

    void setUpStyle();
    void setUpEffect();

signals:

public slots:

};

} // namespace GUI
} // namespace Game

#endif // BUTTON_HPP
