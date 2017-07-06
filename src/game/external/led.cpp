#include "game/external/led.hpp"
#include <QDebug>

namespace Game {
namespace External {

Led::Led(QObject *parent) : QObject(parent) { }

void Led::on(LedType led, int time) {

    gpio = ledToGPIO(led);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(turnOff()));

    setGPIOfunction(0b001);
    setGPIOOutputValue(true);
    timer->start(time);
}

void Led::off(LedType led) {

    gpio = ledToGPIO(led);

    setGPIOfunction(0b001);
    setGPIOOutputValue(false);
}

void Led::turnOff() {

}

int Led::ledToGPIO(LedType led) {

    switch (led) {
        case LedType::Success : return 21; break;
        case LedType::Failure : return 22; break;
        default: return 22;
    }
}

void Led::setGPIOfunction(int code) {

    int registerIndex = gpio / 10;
    int bit = (gpio % 10) * 3;

    unsigned oldValue = gpio_registers->GPFSEL[registerIndex];
    unsigned mask = 0b111 << bit;

    gpio_registers->GPFSEL[registerIndex] = (oldValue & ~mask) | ((code << bit) & mask);
}

void Led::setGPIOOutputValue(bool value) {

    if (value) {
        gpio_registers->GPSET[gpio / 32] = (1 << (gpio % 32));
    } else {
        gpio_registers->GPCLR[gpio / 32] = (1 << (gpio % 32));
    }
}

} // namespace External
} // namespace Game
