#ifndef WIND_H
#define WIND_H

#include <QString>
#include <QMetaType>
#include <QVariant>

class Wind
{
public:
    Wind();
    explicit Wind(const int &speed, const int &chill, const QString &direction);

    int speed() const;
    void setSpeed(int newSpeed);

    const QString &direction() const;
    void setDirection(const QString &newDirection);

    int chill() const;
    void setChill(int newChill);



private:
    int m_speed;
    int m_chill;
    QString m_direction;
};

Q_DECLARE_METATYPE(Wind);

#endif // WIND_H

