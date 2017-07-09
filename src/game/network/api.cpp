#include "game/network/api.hpp"

namespace Game {
namespace Network {

Api::Api(QObject *parent) : QObject(parent) {

    // Manager to send REST petitions
    manager = new QNetworkAccessManager(this);
    result = "";
    limit = 5;

    // URL information
    QString host = Game::Settings::load("network:api:host").toString();
    QString port = Game::Settings::load("network:api:port").toString();
    base_url = QString("http://%1:%2").arg(host, port);

    // Signals && Slots
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestResult(QNetworkReply*)));
}

void Api::uploadScore(QString name, int score) {

    // Name of resource
    QString resource = "/games";

    // Create a JSON object
    QtJson::JsonObject json;
    json["name"] = name;
    json["score"] = score;
    json["timestamp"] = QString::number(QDateTime::currentDateTimeUtc().toTime_t());

    // Serialize object
    QByteArray data = QtJson::serialize(json);

    // Send post petition
    postMethod(resource, data);
}

void Api::getHighscores(int limit) {

    // Set up limit of top highscores
    this->limit = limit;

    // Name of resource
    QString resource = QString("/topscores");

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
    QList<QVariant> data = QtJson::parse(result, ok).toList();

    if (!ok) {
        return;
    }

    // Store top highscores
    QVector<QVector<QString> > highscores;

    for (int i = 0; i < limit; i++) {
        QVector<QString> element;
        element << data[i].toMap()["name"].toString();
        element << data[i].toMap()["score"].toString();
        highscores << element;
    }

    emit topHighscores(highscores);
}

void Api::getMethod(QString resource) {

    QUrl url(base_url.append(resource));
    QNetworkRequest request(url);

    manager->get(request);
}

void Api::postMethod(QString resource, QByteArray data) {

    QUrl url(base_url.append(resource));
    QNetworkRequest request(url);

    // Specify a JSON object is sent
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->post(request, data);
}

} // namespace Network
} // namespace Game
