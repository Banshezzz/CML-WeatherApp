#include "atmosphere.h"

Atmosphere::Atmosphere()
{
    m_humidity = 0;
    m_pressure = 0;
    m_visibility = 0;
}

Atmosphere::Atmosphere(const int &humidity, const int &pressure,const int &rising, const int &visibility)
{
    m_humidity = humidity;
    m_pressure = pressure;
    m_rising = rising;
    m_visibility = visibility;
}

int Atmosphere::humidity() const
{
    return m_humidity;
}

void Atmosphere::setHumidity(int newHumidity)
{
    m_humidity = newHumidity;
}

int Atmosphere::pressure() const
{
    return m_pressure;
}

void Atmosphere::setPressure(int newPressure)
{
    m_pressure = newPressure;
}

int Atmosphere::visibility() const
{
    return m_visibility;
}

void Atmosphere::setVisibility(int newVisibility)
{
    m_visibility = newVisibility;
}

int Atmosphere::rising() const
{
    return m_rising;
}

void Atmosphere::setRising(int newRising)
{
    m_rising = newRising;
}
