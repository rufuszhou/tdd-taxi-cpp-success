#ifndef BILL_H
#define BILL_H

#include <string>
#include <sstream>
#include "ride.h"


class Bill
{
public:
    Bill(const Ride& ride);
    virtual ~Bill();

    inline std::string to_string() {
        std::stringstream ss;
        ss << "收费" << calculate() << "元";
        return ss.str();
    }

protected:
    virtual unsigned int calculate();

    Ride m_ride;
};

#endif // BILL_H
