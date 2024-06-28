#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

class ParkingGarage
{
private:
    std::stack<std::string> inGarage; // Stack for cars in the garage
    std::stack<std::string> waiting;  // Stack for cars waiting to enter
    int moves = 0;                    // Count of moves

public:
    ParkingGarage() {}

    // Function to handle car arrival
    void arrive(const std::string &licensePlate)
    {
        if (inGarage.size() < 10)
        {
            inGarage.push(licensePlate);
            std::cout << "Car with license plate " << licensePlate << " has arrived and parked." << std::endl;
        }
        else
        {
            waiting.push(licensePlate);
            std::cout << "No room for car with license plate " << licensePlate << ". It waits in line." << std::endl;
        }
    }

    // Function to handle car departure
    void depart(const std::string &licensePlate)
    {
        // Move cars from the garage to waiting, if necessary
        while (!inGarage.empty() && inGarage.top() != licensePlate)
        {
            waiting.push(inGarage.top());
            inGarage.pop();
            moves++;
        }

        if (!inGarage.empty() && inGarage.top() == licensePlate)
        {
            // Remove the departing car from the garage
            inGarage.pop();
            std::cout << "Car with license plate " << licensePlate << " has departed after " << moves << " moves." << std::endl;
        }
        else
        {
            std::cout << "Car with license plate " << licensePlate << " was not found in the garage." << std::endl;
        }

        // Move cars back from waiting to the garage
        while (!waiting.empty() && inGarage.size() < 10)
        {
            inGarage.push(waiting.top());
            waiting.pop();
        }
    }
};

int main()
{
    ParkingGarage garage;

    // Sample usage
    garage.arrive("ABC123");
    garage.arrive("XYZ789");
    garage.depart("XYZ789");
    garage.arrive("DEF456");
    garage.arrive("GHI789");
    garage.depart("XYZ123");
    garage.depart("ABC123");

    return 0;
}
