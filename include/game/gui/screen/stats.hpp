#ifndef STATS_HPP
#define STATS_HPP

#include <QVBoxLayout>
#include <QLabel>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"
#include "game/gui/highscore.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Stats : public QWidget {

    Q_OBJECT
public:
    explicit Stats(QWidget *parent = 0);

signals:
    void backClicked();

public slots:
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // STATS_HPP
