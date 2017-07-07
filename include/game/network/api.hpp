#ifndef API_HPP
#define API_HPP

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include "3rdparty/qt-json/json.h"
#include "game/settings/manager.hpp"

namespace Game {
namespace Network {

    static const int max_timeout = 1000;

class Api : public QObject {

    Q_OBJECT
public:
    explicit Api(QObject *parent = 0);

    void uploadScore(QString name, int score);
    void getHighscores(int limit = 5);

signals:
    void topHighscores(QVector<QVector<QString>>);

public slots:
    void requestResult(QNetworkReply*);
    void parseHighscores();

protected:

private:
    QNetworkAccessManager *manager;
    QString base_url;
    QString result;

    void getMethod(QString resource);
    void postMethod(QString resource, QByteArray data);
};

} // namespace Network
} // namespace Game

#endif // API_HPP
