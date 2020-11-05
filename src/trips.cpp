#include <string>
#include <iostream>
#include <fstream>
#include "trips.h"
#include "trip_factory.h"

Trips::Trips();

Trips::Trips(std::string path_to_records) {
    read_records(path_to_records);
}

Trips::~Trips() {
    clear_records();
}

bool Trips::read_records(std::string path_to_records) {
    bool result = true;
    std::vector<Trip*> trips;
    std::ifstream input_file;

    input_file.open(path_to_records);
    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            Trip* p_trip = TripFactory::create(line);

            if (p_trip) {
               trips.push_back(p_trip);
            } else {
                std::cerr<< "Failed to parse line: "
                         << line
                         << " in file: "
                         << path_to_records
                         << std::endl;
                result = false;
                break;
            }
        }
    } else {
        std::cerr<< "Failed to open file: " << path_to_records << std::endl;
        result = false;
    }
    input_file.close();
    if (result) {
        clear_records();
        m_ptrips = trips;
    } else {
        clear_records(trips);
    }
    return result;
}

void Trips::clear_records() {
    clear_records(m_ptrips);
}

void Trips::clear_records(std::vector<Trip*>& trips) {
    for (std::vector<Trip*>::iterator it=trips.begin();
            it != trips.end();
            it++) {
        if ( *it != nullptr ) {
            delete *it;
        }
    }
    trips.clear();
}

std::string Trips::to_string() {
    std::string output;
    for (std::vector<Trip*>::iterator it = m_ptrips.begin();
            it != m_ptrips.end();
            it++) {
        output = output + (*it)->to_string() + "\n";
    }
    return output;
}
