#include "include/game/gui/stackedwidget.hpp"

namespace Game {
namespace GUI {

StackedWidget::StackedWidget(QWidget *parent): QStackedWidget(parent) {

    active = false;
    speed = 500;
    animation = QEasingCurve::Linear;
    current_screen = NULL;
    next_screen = NULL;
    current_point = QPoint(0, 0);
}

void StackedWidget::setSpeed(int value) { speed = value; }

void StackedWidget::setAnimation(QEasingCurve::Type type) { animation = type; }

void StackedWidget::setAnimatedTransition(QWidget *screen, Direction direction){

    // Check if transitions are enabled
    if (disabled()) {
        this->setCurrentWidget(screen);
        return;
    }

    // Check active animation
    if (active) {
        return;
    }

    // Initial settings
    active = true;
    current_screen = this->currentWidget();
    next_screen = screen;

    // Check differente screens transition
    if (screen == current_screen) {
        active = false;
        return;
    }

    // Shifts calculatios
    int offset_x = this->frameRect().width();
    int offset_y = this->frameRect().height();
    next_screen->setGeometry(0, 0, offset_x, offset_y);

    switch(direction) {
        case Direction::BottomToTop : offset_x = 0; offset_y = -offset_y; break;
        case Direction::TopToBottom : offset_x = 0; break;
        case Direction::RightToLeft : offset_y = 0; offset_x = -offset_x; break;
        case Direction::LeftToRight : offset_y = 0; break;
    }

    // Re-positioning the next screen
    QPoint next_point = next_screen->pos();
    current_point = current_screen->pos();
    next_screen->move(next_point.x() - offset_x, next_point.y() - offset_y);
    next_screen->show();
    next_screen->raise();

    // Animation for current screen
    QPropertyAnimation *current_animation = new QPropertyAnimation(current_screen, "pos", this);
    current_animation->setDuration(speed);
    current_animation->setEasingCurve(animation);
    current_animation->setStartValue(QPoint(current_point.x(), current_point.y()));
    current_animation->setEndValue(QPoint(offset_x + current_point.x(), offset_y + current_point.y()));

    // Animation for next screen
    QPropertyAnimation *next_animation = new QPropertyAnimation(next_screen, "pos", this);
    next_animation->setDuration(speed);
    next_animation->setEasingCurve(animation);
    next_animation->setStartValue(QPoint(-offset_x + next_point.x(), -offset_y + next_point.y()));
    next_animation->setEndValue(QPoint(next_point.x(), next_point.y()));

    // Group both animations
    QParallelAnimationGroup *group_animation = new QParallelAnimationGroup(this);
    group_animation->addAnimation(current_animation);
    group_animation->addAnimation(next_animation);

    // Start animated transition
    connect(group_animation, SIGNAL(finished()), this, SLOT(finishAnimatedTransition()));
    group_animation->start();
}

void StackedWidget::finishAnimatedTransition() {

    this->setCurrentWidget(next_screen);
    current_screen->move(current_point);
    current_screen->hide();

    active = false;
}

bool StackedWidget::disabled() { return !Game::Settings::load("gui:transitions:enabled").toBool(); }

} // namespace GUI
} // namespace Game
