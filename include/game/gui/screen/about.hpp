#ifndef ABOUT_HPP
#define ABOUT_HPP

#include <QVBoxLayout>
#include <QLabel>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class About : public QWidget {

    Q_OBJECT
public:
    explicit About(QWidget *parent = 0);

signals:
    void backClicked();

public slots:
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // ABOUT_HPP
