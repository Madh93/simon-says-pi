#include "game/gui/highscore.hpp"

namespace Game {
namespace GUI {

HighScore::HighScore(QWidget *parent) : QWidget(parent) {

    // Main layout
    QGridLayout *layout = new QGridLayout(parent);
    layout->setHorizontalSpacing(50);

    // Create highscores labels
    setUpHighScores();

    // Add labels to grid layout
    QFlags<Qt::AlignmentFlag> alignation;
    int column = 0;
    int row = 0;

    foreach (QVector<QLabel*> data, highscores) {
        foreach (QLabel *label, data) {
            label->setObjectName(QString("highscore%1").arg(row));
            alignation = (column < 2) ? Qt::AlignLeft : Qt::AlignCenter;
            layout->addWidget(label, row, column, 1, 1, alignation);
            row++;
        }
        column++;
        row = 0;
    }

    this->setLayout(layout);
}

void HighScore::updateHighscore(QVector<QVector<QString> > scores) {

    int i = 1;

    foreach (QVector<QString> element, scores) {
        highscores["names"][i]->setText(element[0]);
        highscores["scores"][i++]->setText(element[1]);
    }
}

void HighScore::setUpHighScores() {

    // Places labels
    highscores["#"] << new QLabel("RANK", this);
    highscores["#"] << new QLabel("1st", this);
    highscores["#"] << new QLabel("2nd", this);
    highscores["#"] << new QLabel("3rd", this);
    highscores["#"] << new QLabel("4th", this);
    highscores["#"] << new QLabel("5th", this);

    // Names labels
    highscores["names"] << new QLabel("NAME", this);
    highscores["names"] << new QLabel("????", this);
    highscores["names"] << new QLabel("????", this);
    highscores["names"] << new QLabel("????", this);
    highscores["names"] << new QLabel("????", this);
    highscores["names"] << new QLabel("????", this);

    // Scores labels
    highscores["scores"] << new QLabel("SCORE", this);
    highscores["scores"] << new QLabel("0", this);
    highscores["scores"] << new QLabel("0", this);
    highscores["scores"] << new QLabel("0", this);
    highscores["scores"] << new QLabel("0", this);
    highscores["scores"] << new QLabel("0", this);
}

} // namespace GUI
} // namespace Game
