#include "game/network/api.hpp"
#include <QDebug>

namespace Game {
namespace Network {

Api::Api(QObject *parent) : QObject(parent) {

    // Manager to send REST petitions
    manager = new QNetworkAccessManager(this);
    result = "";

    // URL information
    QString host = Game::Settings::load("network:api:host").toString();
    QString port = Game::Settings::load("network:api:port").toString();
    base_url = QString("http://%1:%2").arg(host, port);

    // Signals && Slots
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestResult(QNetworkReply*)));
}

void Api::uploadScore(QString name, int score) {

    // Name of resource
    QString resource = "/score";

    // Create a JSON object
    QtJson::JsonObject json;
    json["name"] = name;
    json["score"] = score;

    // Serialize object
    QByteArray data = QtJson::serialize(json);

    // Send post petition
    postMethod(resource, data);
}

void Api::getHighscores(int limit) {

    // Name of resource
    QString resource = QString("/scores/%1").arg(limit);

    // Send get petition
    getMethod(resource);

    // Emit signal with response
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(parseHighscores()));
    timer->start(max_timeout);
}

void Api::requestResult(QNetworkReply *reply) {

    // Error response
    if (reply->error() != QNetworkReply::NoError) {
        result = "";
        return;
    }

    result = (QString)reply->readAll();
}

void Api::parseHighscores() {

    if(result.isEmpty()) {
        return;
    }

    // Deserialize JSON data
    bool ok;
    QtJson::JsonObject data = QtJson::parse(result, ok).toMap();

    if (!ok) {
        return;
    }

    // Store top highscores
    QVector<QVector<QString> > highscores;

    foreach (QVariant highscore, data["scores"].toList()) {
        QVector<QString> element;
        element << highscore.toMap()["name"].toString();
        element << highscore.toMap()["score"].toString();
        highscores << element;
    }

    emit topHighscores(highscores);
}

void Api::getMethod(QString resource) {

    QUrl url(QString(base_url).arg(resource));
    QNetworkRequest request(url);

    manager->get(request);
}

void Api::postMethod(QString resource, QByteArray data) {

    QUrl url(QString(base_url).arg(resource));
    QNetworkRequest request(url);

    // Specify a JSON object is sent
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, data);
}

} // namespace Network
} // namespace Game
