#ifndef STACKEDWIDGET_HPP
#define STACKEDWIDGET_HPP

#include <QWidget>
#include <QStackedWidget>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include "game/settings/manager.hpp"

/* REFERENCE:
 * http://qt.shoutwiki.com/wiki/Extending_QStackedWidget_for_sliding_page_animations_in_Qt
 */

namespace Game {
namespace GUI {

enum class Direction {
    LeftToRight,
    RightToLeft,
    TopToBottom,
    BottomToTop
};

class StackedWidget : public QStackedWidget {

    Q_OBJECT
public:
    explicit StackedWidget(QWidget *parent = 0);

    void setSpeed(int value);
    void setAnimation(QEasingCurve::Type type);
    void setAnimatedTransition(QWidget *screen, Direction direction);

public slots:
    void finishAnimatedTransition();

private:
    bool active;
    int speed;
    QEasingCurve::Type animation;
    QWidget *current_screen;
    QWidget *next_screen;
    QPoint current_point;

    bool disabled();
};

} // namespace GUI
} // namespace Game

#endif // STACKEDWIDGET_HPP
