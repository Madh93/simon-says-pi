#ifndef APPWINDOW_HPP
#define APPWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QSignalMapper>

#include "game/gui/screen/title.hpp"
#include "game/gui/screen/more.hpp"

namespace Game {
namespace GUI {

class AppWindow : public QMainWindow {

    Q_OBJECT
public:
    explicit AppWindow(QMainWindow *parent = 0);

signals:

public slots:
};

} // namespace GUI
} // namespace Game

#endif // APPWINDOW_HPP
