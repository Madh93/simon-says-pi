#ifndef LETTERSELECTOR_HPP
#define LETTERSELECTOR_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include <game/gui/button.hpp>

namespace Game {
namespace GUI {

class LetterSelector : public QWidget {

    Q_OBJECT
public:
    explicit LetterSelector(QWidget *parent = 0);

    QChar getValue();

public slots:
    void nextLetter();
    void prevLetter();

private:
    QLabel *letter_label;
    int index;

    int getAscii();
    int mod(int k, int n);

    void update();
};

} // namespace GUI
} // namespace Game

#endif // LETTERSELECTOR_HPP
