#pragma once

#include <string>
#include <vector>

#include "trip.h"

class Trips {

public:
    Trips();
    Trips(std::string path_to_records);
    Trips(const Trips&)=delete;
    Trips& operator=(const Trips&)=delete;
    virtual ~Trips();

    virtual bool read_records(std::string path_to_records);
    virtual void clear_records();

    virtual std::string to_string();

protected:
    void clear_records(std::vector<Trip*>& trips);

protected:
    std::vector<Trip*> m_ptrips;
};
