#ifndef STATS_HPP
#define STATS_HPP

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

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
    void updateHighscore(QVector<QVector<QString>>);

public slots:
    void showHighscore(QVector<QVector<QString>>);

private:
    QStackedWidget *stacked_widget;
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // STATS_HPP
