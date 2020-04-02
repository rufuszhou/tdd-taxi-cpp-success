#ifndef RIDE_H
#define RIDE_H

#include <string>

class Ride
{
    public:
        Ride();
        Ride(unsigned int distance_in_km, unsigned int waittime_in_minute);
        Ride(const Ride& r);
        ~Ride();

        inline unsigned int get_distance() { return m_distance; }
        inline unsigned int get_waittime() { return m_waittime; }
        inline void set_distance(unsigned int d) { m_distance = d; }
        inline void set_waittime(unsigned int w) { m_waittime = w; }

        bool from_string(std::string input);       //example: "3公里,等待0分钟"

    private:
        unsigned int m_distance;        // in "km"
        unsigned int m_waittime;        // in "minute"
};

#endif // RIDE_H
