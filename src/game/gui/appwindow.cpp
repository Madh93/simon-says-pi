#include "game/gui/appwindow.hpp"

namespace Game {
namespace GUI {

AppWindow::AppWindow(QMainWindow *parent) : QMainWindow(parent) {

    Screen::setUpDefaultScreen(this);

    QStackedWidget *stacked_widget = new QStackedWidget(this);
    QSignalMapper *signal_mapper = new QSignalMapper(this);

    // Screens
    Screen::Title *title_screen = new Screen::Title(parent);
    Screen::More *more_screen = new Screen::More(parent);

    stacked_widget->addWidget(title_screen);
    stacked_widget->addWidget(more_screen);

    this->connect(title_screen, SIGNAL(moreClicked()), signal_mapper, SLOT(map()));
    this->connect(more_screen, SIGNAL(backClicked()), signal_mapper, SLOT(map()));

    signal_mapper->setMapping(title_screen, 1);
    signal_mapper->setMapping(more_screen, 0);

    this->connect(signal_mapper, SIGNAL(mapped(int)), stacked_widget, SLOT(setCurrentIndex(int)));

    // Show
    this->setCentralWidget(stacked_widget);
}

} // namespace GUI
} // namespace Game
