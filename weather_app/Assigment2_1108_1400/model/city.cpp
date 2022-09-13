#include "city.h"

City::City()
{

}

City::City(const QString &name, const QString &condition)
{
    m_name = name;
    m_condition = condition;
}

City::City(const QString &name, const QString &condition, const Wind &wind, const Atmosphere &atm, const Astronomy &astro)
{
    m_name = name;
    m_condition = condition;
    m_wind = wind;
    m_atmosphere = atm;
    m_astronomy = astro;
}

City::City(const QString &name, const QString &condition, const int &speed, const int &chill, const QString &direction, const int &humidity, const int &pressure, const int &rising, const int &visibility, const QString &sunrise, const QString &sunset)
{
    m_name = name;
    m_condition = condition;
    m_speed = speed;
    m_chill = chill;
    m_direction = direction;
    m_humidity = humidity;
    m_pressure = pressure;
    m_rising = rising;
    m_visibility = visibility;
    m_sunrise = sunrise;
    m_sunset = sunset;
}

const QString &City::name() const
{
    return m_name;
}

void City::setName(const QString &newName)
{
    m_name = newName;
}

const QString &City::condition() const
{
    return m_condition;
}

void City::setCondition(const QString &newCondition)
{
    m_condition = newCondition;
}

const Wind &City::wind() const
{
    return m_wind;
}

void City::setWind(const Wind &newWind)
{
    m_wind = newWind;
}

const Atmosphere &City::atmosphere() const
{
    return m_atmosphere;
}

void City::setAtmosphere(const Atmosphere &newAtmosphere)
{
    m_atmosphere = newAtmosphere;
}

const Astronomy &City::astronomy() const
{
    return m_astronomy;
}

void City::setAstronomy(const Astronomy &newAstronomy)
{
    m_astronomy = newAstronomy;
}

int City::speed() const
{
    return m_speed;
}

void City::setSpeed(int newSpeed)
{
    m_speed = newSpeed;
}

int City::chill() const
{
    return m_chill;
}

void City::setChill(int newChill)
{
    m_chill = newChill;
}

const QString &City::direction() const
{
    return m_direction;
}

void City::setDirection(const QString &newDirection)
{
    m_direction = newDirection;
}

int City::humidity() const
{
    return m_humidity;
}

void City::setHumidity(int newHumidity)
{
    m_humidity = newHumidity;
}

int City::pressure() const
{
    return m_pressure;
}

void City::setPressure(int newPressure)
{
    m_pressure = newPressure;
}

int City::rising() const
{
    return m_rising;
}

void City::setRising(int newRising)
{
    m_rising = newRising;
}

const QString &City::sunrise() const
{
    return m_sunrise;
}

void City::setSunrise(const QString &newSunrise)
{
    m_sunrise = newSunrise;
}

const QString &City::sunset() const
{
    return m_sunset;
}

void City::setSunset(const QString &newSunset)
{
    m_sunset = newSunset;
}

int City::visibility() const
{
    return m_visibility;
}

void City::setVisibility(int newVisibility)
{
    m_visibility = newVisibility;
}
