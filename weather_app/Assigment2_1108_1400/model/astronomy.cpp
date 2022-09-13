#include "astronomy.h"

Astronomy::Astronomy()
{
    m_sunrise = "05:00";
    m_sunset = "17:00";
}

Astronomy::Astronomy(const QString &sunrise, const QString &sunset)
{
    m_sunrise = sunrise;
    m_sunset = sunset;
}

const QString &Astronomy::sunrise() const
{
    return m_sunrise;
}

void Astronomy::setSunrise(const QString &newSunrise)
{
    m_sunrise = newSunrise;
}

const QString &Astronomy::sunset() const
{
    return m_sunset;
}

void Astronomy::setSunset(const QString &newSunset)
{
    m_sunset = newSunset;
}
