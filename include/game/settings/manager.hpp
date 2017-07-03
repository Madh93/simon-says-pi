#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <QSettings>

namespace Game {
namespace Settings {

    QVariant load(QString key,
                 const QString &filename = ":/config/application.ini");

} // namespace Settings
} // namespace Game

#endif // MANAGER_HPP
