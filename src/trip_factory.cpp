#include <string>
#include <iostream>

#include "trip_factory.h"


// This function can be extended to
//    create different types of Trip object based on the input string.
Trip* TripFactory::create(std::string record_str) {
/*
1公里,等待0分钟
3公里,等待0分钟
10公里,等待0分钟
2公里,等待3分钟
*/
    unsigned int distance = 0;
    unsigned int wait_time = 0;
    Trip* t = nullptr;

    std::string::size_type km_index = record_str.find("公里");
    std::string::size_type wait_start = record_str.find("等待");
    std::string::size_type wait_end = record_str.find("分钟");

    if ( km_index == std::string::npos ||
            wait_start == std::string::npos ||
            wait_end == std::string::npos) {
        std::cout << "1:" << km_index << wait_start << wait_end << std::endl;
        return nullptr;
    }

    wait_start += std::string("等待").length();
    if (wait_end <= wait_start) {
        std::cout << "2:" << km_index << wait_start << wait_end << std::endl;
        return nullptr;
    }

    std::string km_str = record_str.substr(0, km_index);
    distance = std::stol(km_str);

    std::string wait_str = record_str.substr(wait_start, wait_end - wait_start);
    wait_time = std::stol(wait_str);

    t = new (std::nothrow) BasicTrip(distance, wait_time);

    return t;
}
