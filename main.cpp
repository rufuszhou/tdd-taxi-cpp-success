#include <iostream>
#include <string>
#include <fstream>

#include "ride.h"
#include "bill.h"

using namespace std;


int main(int argc, char* argv[])
{
    ifstream input_file;

    if (argc != 2)
    {
        cerr << "Usage: tdd_taxi_cpp path_to_input_file" << endl;
        return 1;
    }
    input_file.open(argv[1]);
    if (input_file.is_open())
    {
        string line;
        while(std::getline(input_file, line))
        {
            Ride r;
            if (r.from_string(line))
            {
                cout<<Bill(r).to_string() <<endl;
            }
            else
            {
                cerr << "Failed to parse line: " << line << endl;
            }
        }
    }
    else
    {
        cerr<< "Failed to open file: " << argv[1] << endl;
        return 1;
    }

    return 0;
}
