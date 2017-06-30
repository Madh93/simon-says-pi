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

    // Load screen stylesheet
    screen->setObjectName("screen");
    QFile file(":/qss/application.qss");
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    screen->setStyleSheet(stylesheet);
}

} // namespace Screen
} // namespace GUI
} // namespace Game
