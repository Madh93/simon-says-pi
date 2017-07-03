#include "game/settings/manager.hpp"

namespace Game {
namespace Settings {

QVariant load(QString key, const QString &filename) {

    // Load settings file
    QSettings settings(filename, QSettings::IniFormat);

    // Use ':' syntax
    key.replace(":", "/");

    // Return key
    return settings.value(key, "Key not found!");
}

} // namespace Settings
} // namespace Game
