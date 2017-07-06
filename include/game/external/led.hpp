#ifndef LED_HPP
#define LED_HPP

#include <QObject>
#include <QTimer>
#include <asm/io.h>
#include <mach/platform.h>

#include "game/types.hpp"

namespace Game {
namespace External {

struct GPIORegisters {
    uint32_t GPFSEL[6];
    uint32_t Reserved1;
    uint32_t GPSET[2];
    uint32_t Reserved2;
    uint32_t GPCLR[2];
};

class Led : public QObject {

    Q_OBJECT
public:

    explicit Led(QObject *parent = 0);

    void on(LedType led, int time);
    void off(LedType led);

private slots:
    void turnOff();

private:
    struct GPIORegisters *gpio_registers;
    int gpio;

    int ledToGPIO(LedType led);
    void setGPIOfunction( int code);
    void setGPIOOutputValue(bool value);
};
} // namespace Leds
} // namespace Game

#endif // LED_HPP
