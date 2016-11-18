#include "temp.h"

Temperature::Temperature() {
    tempKelvin = 0.0;
}

void Temperature::setTempCelcius(double t) {
    tempKelvin = t + 273.15;
}

void Temperature::setTempKelvin(double t) {
    tempKelvin = t;
}

void Temperature::setTempFahrenheit(double t) {
    tempKelvin = ((5 / 9) * (t - 32)) + 273.15;
}

double Temperature::get(TempScale scale) {
    double temp = tempKelvin;

    if (scale == K) return temp;
    temp = temp - 273.150;

    return scale == C ? temp : (temp * 1.8) + 32.0;
}