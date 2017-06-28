#include "game/gui/screen/base.hpp"

namespace Game {
namespace GUI {
namespace Screen {

void setUpDefaultScreen(QWidget *screen) {

    // Screen Position (Center for Desktop)
    QRect desktopRect = QApplication::desktop()->availableGeometry(screen);
    QPoint center = desktopRect.center();
    screen->move(center.x() - max_width*0.5, center.y() - max_height*0.5);

    // Screen size
    screen->setMinimumSize(max_width, max_height);
    screen->setMaximumSize(max_width, max_height);

    // Screen style
    screen->setStyleSheet("background-color: #233237;");
}

} // namespace Screen
} // namespace GUI
} // namespace Game
