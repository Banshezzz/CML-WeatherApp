#ifndef CITY_H
#define CITY_H

#include <QString>
#include "model/wind.h"
#include "model/atmosphere.h"
#include "model/astronomy.h"


class City
{
public:
    City();
    City(const QString &name, const QString &condition);
    explicit City(const QString &name, const QString &condition, const Wind &wind, const Atmosphere &atm, const Astronomy &astro );
    explicit City(const QString &name, const QString &condition,
                  const int &speed, const int &chill, const QString &direction,
                  const int &humidity, const int &pressure, const int &rising, const int &visibility,
                  const QString &sunrise, const QString &sunset);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &condition() const;
    void setCondition(const QString &newCondition);

    const Wind &wind() const;
    void setWind(const Wind &newWind);

    const Atmosphere &atmosphere() const;
    void setAtmosphere(const Atmosphere &newAtmosphere);

    const Astronomy &astronomy() const;
    void setAstronomy(const Astronomy &newAstronomy);

    int speed() const;
    void setSpeed(int newSpeed);

    int chill() const;
    void setChill(int newChill);

    const QString &direction() const;
    void setDirection(const QString &newDirection);

    int humidity() const;
    void setHumidity(int newHumidity);

    int pressure() const;
    void setPressure(int newPressure);

    int rising() const;
    void setRising(int newRising);

    const QString &sunrise() const;
    void setSunrise(const QString &newSunrise);

    const QString &sunset() const;
    void setSunset(const QString &newSunset);

    int visibility() const;
    void setVisibility(int newVisibility);

private:
    QString m_name;
    QString m_condition;
    Wind m_wind;
    Atmosphere m_atmosphere;
    Astronomy m_astronomy;

    int m_speed, m_chill, m_humidity, m_pressure, m_rising, m_visibility;
    QString m_direction, m_sunrise, m_sunset;

};

#endif // CITY_H

