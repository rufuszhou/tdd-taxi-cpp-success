#include <cmath>
#include "bill.h"

Bill::Bill(const Ride& ride) : m_ride(ride)
{
    //ctor
}

Bill::~Bill()
{
    //dtor
}

/**
1. 不大于2公里时只收起步价6元。
2. 超过2公里的部分每公里收取0.8元。
3. 超过8公里的部分，每公里加收50%长途费。
4. 停车等待时加收每分钟0.25元。
5. 最后计价的时候司机会四舍五入只收到元。
*/
unsigned int Bill::calculate()
{
    #define BASE_DISTANCE   2
    #define LONG_DISTANCE   8

    unsigned int distance = m_ride.get_distance();
    unsigned int wait     = m_ride.get_waittime();

    float bill = (distance > 0) ? 6.0 : 0;
    if (distance > BASE_DISTANCE) {
        bill += (distance - BASE_DISTANCE) * 0.8;
    }
    if (distance > LONG_DISTANCE) {
        bill += (distance - LONG_DISTANCE) * 0.8 * 0.5;
    }
    if (wait > 0) {
        bill += wait * 0.25;
    }
    return  round( bill );
}
