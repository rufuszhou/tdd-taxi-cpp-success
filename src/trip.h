#pragma once

#include <string>
#include <vector>
#include <sstream>

// different types of Trip can be extended from here
class Trip {
public:
    Trip() {};
    virtual ~Trip() {};
    virtual inline std::string to_string() {
        std::stringstream ss;
        ss << "收费" << calculate() << "元";
        return ss.str();
    }
protected:
    virtual unsigned int calculate() = 0;
};

class BasicTrip : public Trip {
public:
    BasicTrip();
    BasicTrip(unsigned int distance_in_km, unsigned int waittime_in_minute);
    BasicTrip(const BasicTrip& r);
    BasicTrip& operator=(const BasicTrip&);
    virtual ~BasicTrip();

    inline unsigned int get_distance() { return m_distance; }
    inline unsigned int get_waittime() { return m_waittime; }
    inline void set_distance(unsigned int d) { m_distance = d; }
    inline void set_waittime(unsigned int w) { m_waittime = w; }

protected:
    virtual unsigned int calculate();

protected:
    unsigned int m_distance;        // in "km"
    unsigned int m_waittime;        // in "minute"
};

