#ifndef SCORE_HPP
#define SCORE_HPP

#include <QWidget>
#include <QLabel>

namespace Game {
namespace GUI {

class Score : public QLabel {

    Q_OBJECT
public:
    explicit Score(QWidget *parent = 0);

    int getScore();

signals:

public slots:
    void resetScore();
    void addScore();

protected:

private:
    int score;

    void update();
};

} // namespace GUI
} // namespace Game

#endif // SCORE_HPP
