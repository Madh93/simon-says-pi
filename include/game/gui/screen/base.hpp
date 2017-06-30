#ifndef BASE_HPP
#define BASE_HPP

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QFile>

#include "game/types.hpp"

namespace Game {
namespace GUI {
namespace Screen {

    static const int max_width = 320;
    static const int max_height = 240;

    void setUpDefaultScreen(QWidget *screen);

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // BASE_HPP
