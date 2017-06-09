#ifndef TITLE_HPP
#define TITLE_HPP

#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Title : public QWidget {

    Q_OBJECT
public:
    explicit Title(QWidget *parent = 0);

signals:
    void playClicked();
    void moreClicked();

public slots:
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // TITLE_HPP
