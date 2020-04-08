#pragma once

#include "trip.h"

class TripFactory {
public:
    static Trip* create(std::string record_str);
};