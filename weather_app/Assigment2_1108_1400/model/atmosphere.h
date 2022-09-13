#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H


class Atmosphere
{
public:
    Atmosphere();
    explicit Atmosphere(const int &humidity, const int &pressure, const int &rising, const int &visibility);

    int humidity() const;
    void setHumidity(int newHumidity);

    int pressure() const;
    void setPressure(int newPressure);

    int visibility() const;
    void setVisibility(int newVisibility);

    int rising() const;
    void setRising(int newRising);

private:
    int m_humidity;
    int m_pressure;
    int m_rising;
    int m_visibility;
};

#endif // ATMOSPHERE_H
