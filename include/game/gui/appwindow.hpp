#ifndef APPWINDOW_HPP
#define APPWINDOW_HPP

#include <QMainWindow>

#include "game/run.hpp"
#include "game/gui/stackedwidget.hpp"
#include "game/gui/screen/about.hpp"
#include "game/gui/screen/more.hpp"
#include "game/gui/screen/simon.hpp"
#include "game/gui/screen/stats.hpp"
#include "game/gui/screen/title.hpp"

namespace Game {
namespace GUI {

class AppWindow : public QMainWindow {

    Q_OBJECT
public:
    explicit AppWindow(QMainWindow *parent = 0);

signals:

public slots:
    void loadTitleScreen();
    void loadSimonScreen();
    void loadMoreScreen();
    void loadStatsScreen();
    void loadAboutScreen();

private:
    StackedWidget *stacked_widget;
    QHash<QString, QWidget*> screens;
    Direction direction;

    QWidget *currentScreen();
    void update(QWidget *screen);
};

} // namespace GUI
} // namespace Game

#endif // APPWINDOW_HPP
