#ifndef MORE_HPP
#define MORE_HPP

#include <QGridLayout>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class More : public QWidget {

    Q_OBJECT
public:
    explicit More(QWidget *parent = 0);

signals:
    void backClicked();

public slots:
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // MORE_HPP
