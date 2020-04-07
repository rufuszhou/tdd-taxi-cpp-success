#include <iostream>
#include "trips.h"


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: tdd_taxi_cpp path_to_input_file" << std::endl;
        return 1;
    }

    Trips trips(argv[1]);
    std::cout << trips.to_string() << std::endl;
    return 0;
}
