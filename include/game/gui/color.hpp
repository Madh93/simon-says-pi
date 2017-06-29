#ifndef COLOR_HPP
#define COLOR_HPP

#include <QColor>

namespace Game {
namespace GUI {
namespace Color {

// Screen style colours
static const QColor screen_background(35, 50, 55);

// Button style colours (based on Bootstrap)
static const QColor btn_default(204, 204, 204);
static const QColor btn_primary(46, 109, 164);
static const QColor btn_success(76, 174, 76);
static const QColor btn_info(70, 184, 218);
static const QColor btn_warning(213, 133, 18);
static const QColor btn_danger(212, 63, 58);

// Tile style colours
static const QColor tile_green(32, 173, 138);
static const QColor tile_red(255, 111, 73);
static const QColor tile_yellow(255, 192, 59);
static const QColor tile_blue(0, 129, 195);

// Turn style colours
static const QColor turn_background(35, 50, 55);
static const QColor turn_font(255, 255, 255);

} // namespace Color
} // namespace GUI
} // namespace Game

#endif // COLOR_HPP
