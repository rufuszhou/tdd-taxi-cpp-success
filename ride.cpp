//#include <regex>
#include <iostream> 

#include "ride.h"

Ride::Ride() :
    m_distance(0), m_waittime(0)
{
    //ctor
}


Ride::Ride(unsigned int distance_in_km, unsigned int waittime_in_minute) :
    m_distance(distance_in_km), m_waittime(waittime_in_minute)
{
    //ctor
}

Ride::Ride(const Ride& r):m_distance(r.m_distance), m_waittime(r.m_waittime)
{

}

Ride::~Ride()
{
    //dtor
}

/*
1公里,等待0分钟
3公里,等待0分钟
10公里,等待0分钟
2公里,等待3分钟
*/
bool Ride::from_string(std::string input) {
    std::string::size_type km_index = input.find("公里");
    std::string::size_type wait_start = input.find("等待");
    std::string::size_type wait_end = input.find("分钟");

    if(km_index == std::string::npos || wait_start == std::string::npos || wait_end == std::string::npos) {
        std::cout << "1:" << km_index << wait_start << wait_end << std::endl;
        return false;
    }

    wait_start += std::string("等待").length();
    if (wait_end <= wait_start) {
        std::cout << "2:" << km_index << wait_start << wait_end << std::endl;
        return false;
    }

    std::string km_str = input.substr(0, km_index);
    m_distance = std::stol(km_str);

    std::string wait_str = input.substr(wait_start, wait_end - wait_start);
    m_waittime = std::stol(wait_str);

    return true;
}
