#ifndef RETRY_HPP
#define RETRY_HPP

#include <QGridLayout>
#include <QLabel>

#include "game/gui/screen/base.hpp"
#include "game/gui/button.hpp"

namespace Game {
namespace GUI {
namespace Screen {

class Retry : public QWidget {

    Q_OBJECT
public:
    explicit Retry(QWidget *parent = 0);

signals:
    void backClicked();
    void retryClicked();

public slots:
    void setScore(int);

private:
    QLabel *score_label;
};

} // namespace Screen
} // namespace GUI
} // namespace Game

#endif // RETRY_HPP
