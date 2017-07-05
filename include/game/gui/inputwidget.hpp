#ifndef INPUTWIDGET_HPP
#define INPUTWIDGET_HPP

#include <QWidget>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVector>

#include "game/gui/letterselector.hpp"

namespace Game {
namespace GUI {

class InputWidget : public QWidget {

    Q_OBJECT
public:
    explicit InputWidget(QWidget *parent = 0);

    QString getName();

signals:

public slots:

protected:

private:
    QVector<LetterSelector*> letters;
};

} // namespace GUI
} // namespace Game

#endif // INPUTWIDGET_HPP
