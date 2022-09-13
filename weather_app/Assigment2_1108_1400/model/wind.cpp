#include "wind.h"

Wind::Wind()
{
    m_speed = 0;
    m_chill = 0;
    m_direction = "N";
}

Wind::Wind(const int &speed, const int &chill, const QString &direction)
{
    m_speed = speed;
    m_chill = chill;
    m_direction = direction;
}

int Wind::speed() const
{
    return m_speed;
}

void Wind::setSpeed(int newSpeed)
{
    m_speed = newSpeed;
}

int Wind::chill() const
{
    return m_chill;
}

void Wind::setChill(int newChill)
{
    m_chill = newChill;
}

const QString &Wind::direction() const
{
    return m_direction;
}

void Wind::setDirection(const QString &newDirection)
{
    m_direction = newDirection;
}

