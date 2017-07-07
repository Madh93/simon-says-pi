#include "game/gui/screen/stats.hpp"

namespace Game {
namespace GUI {
namespace Screen {

Stats::Stats(QWidget *parent) : QWidget(parent) {

    // Back button
    using Button = Game::GUI::Button;
    Button *back_button = new Button("Back", Palette::btn_danger, this);
    back_button->setFontSize(18);
    back_button->setMinimumHeight(60);

    // Loading label
    QLabel *loading = new QLabel(this);
    loading->setObjectName("loading");
    loading->setText("<center>Loading...</center>");

    // Highscores table
    HighScore *highscore = new HighScore(this);

    // Stacked widget to manage loading and highscore widgets
    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(loading);
    stacked_widget->addWidget(highscore);

    // Main layout
    QVBoxLayout *main_layout = new QVBoxLayout(parent);
    main_layout->addWidget(stacked_widget, 0, Qt::AlignCenter);
    main_layout->addWidget(back_button, 0, Qt::AlignBottom);
    main_layout->setStretch(0, 60);

    this->setLayout(main_layout);

    // Signals && Slots
    this->connect(back_button, SIGNAL(clicked()), this, SIGNAL(backClicked()));
    this->connect(this, SIGNAL(updateHighscore(QVector<QVector<QString> >)),
                  highscore, SLOT(updateHighscore(QVector<QVector<QString> >)));
}

void Stats::showHighscore(QVector<QVector<QString>> scores) {

    emit updateHighscore(scores);
    stacked_widget->setCurrentIndex(1);
}

} // namespace Screen
} // namespace GUI
} // namespace Game
