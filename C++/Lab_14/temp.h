#ifndef TEMP_H
#define TEMP_H

enum TempScale { C, F, K };

class Temperature {
    public:
        Temperature();
        void setTempKelvin(double t);
        void setTempCelcius(double t);
        void setTempFahrenheit(double t);
        double get(TempScale scale);
    private:
        double tempKelvin;
};

#endif