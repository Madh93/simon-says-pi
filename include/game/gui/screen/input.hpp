#ifndef INPUT_HPP
#define INPUT_HPP

#include <QVBoxLayout>
#include <QLabel>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"
#include "game/gui/inputwidget.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Input : public QWidget {

    Q_OBJECT
public:
    explicit Input(QWidget *parent = 0);

    QString getName();

signals:
    void acceptClicked();

public slots:
    void updateName();

private:
    InputWidget *input_widget;
    QString name;
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // INPUT_HPP
