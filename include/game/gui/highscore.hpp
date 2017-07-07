#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QMap>


namespace Game {
namespace GUI {

class HighScore : public QWidget {

    Q_OBJECT
public:
    explicit HighScore(QWidget *parent = 0);


signals:

public slots:
    void updateHighscore(QVector<QVector<QString> >);

protected:

private:
    QMap<QString, QVector<QLabel*>> highscores;

    void setUpHighScores();
};

} // namespace GUI
} // namespace Game

#endif // HIGHSCORE_HPP
