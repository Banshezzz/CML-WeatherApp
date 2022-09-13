#ifndef ASTRONOMY_H
#define ASTRONOMY_H

#include <QString>

class Astronomy
{
public:
    Astronomy();
    explicit Astronomy(const QString &sunrise, const QString &sunset );

    const QString &sunrise() const;
    void setSunrise(const QString &newSunrise);

    const QString &sunset() const;
    void setSunset(const QString &newSunset);

private:
    QString m_sunrise;
    QString m_sunset;
};

#endif // ASTRONOMY_H
