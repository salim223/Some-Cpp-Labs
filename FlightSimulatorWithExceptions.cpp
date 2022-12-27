#include <iostream>
#include <string>
#include <limits>

class NegativeSpeedException {
public:
    NegativeSpeedException(double speed) {
        std::cout << "SYSTEM: Negative speed detected: " << speed << std::endl;
    }


};


class Airplane
{
private:
    std::string name;
    std::string location;
    double speed;
    double altitude;

public:
    Airplane() {
        name = "Boeng 747";
        location = "IAH";
        speed = 0;
        altitude = 0;
    }

    Airplane(std::string nm, std::string loc) {
        name = nm;
        location = loc;
    }

    void takeoff() {
        takeoff(250, 10000);
    }

    void takeoff(double spd, double ltd) {

        if (ltd > 13000)
        {
            throw std::invalid_argument("takeoff() altitude argument is too large. \n");
        }

        if (spd > 200) {
            speed = spd;
            std::cout << std::endl << "DISPATCH: The " << name << " is taking off. With the cruise speed: " << speed << std::endl << std::endl;
        }

        else if (spd < 0) {
            throw NegativeSpeedException(spd);

        }

        else {
            std::cout << std::endl << "DISPATCH: The " << name << " was not able to take off (low speed)." << std::endl << std::endl;
        }
    }

    void land() {
        if (speed == 0) {
            std::cout << "DISPATCH: The " << name << " is already landed." << std::endl << std::endl;
        }
        else {
            std::cout << "DISPATCH: The " << name << " is landing." << std::endl << std::endl;
            speed = 0;
        }
    }
    int showSpeed() {
        return speed;
    }

    std::string showName() {
        return name;
    }

    std::string showLoc() {
        return location;
    }

    void status() {
        std::cout << std::endl << "DISPATCH: The name of the plane is: " << showName();
        std::cout << std::endl << "DISPATCH: Plane is located at the " << showLoc() << " airport." << std::endl;
    }
};

void input_validation(std::string inp) {
    if (inp == "q" || inp.length() == 0)
        exit(0);
}

int main(int argc, const char* argv[]) {

    std::string input;
    std::string name;
    double speed = 0;
    double latitude = 0;

    std::cout << "Welcome to the Macrohard Flight Simulator v0.0014Alpha!" << std::endl;
    std::cout << "Type 'q' to exit or follow the instructions." << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << "       __|__" << std::endl;
    std::cout << "--------(_)--------" << std::endl;
    std::cout << "  O  O       O  O" << std::endl;
    std::cout << "*********************" << std::endl << std::endl;
    while (true) {
        std::cout << "SYSTEM: Enter new plane name: ";
        std::cin >> input;
        input_validation(input);
        name = input;

        std::cout << "SYSTEM: Enter flight speed: ";
        std::cin >> input;
        input_validation(input);
        speed = std::stod(input);


        std::cout << "SYSTEM: Enter planned latitude of the flight: ";
        std::cin >> input;
        input_validation(input);
        latitude = std::stod(input);

        Airplane plane(name, "IAH");
        plane.status();

        std::cout << "DISPATCH: Trying to takeoff..." << std::endl;


        try
        {
            plane.takeoff(speed, latitude);
        }
        catch (NegativeSpeedException& n)
        {
            std::cout << "SYSTEM: Exception caught!" << std::endl << std::endl;
        }
        catch (std::invalid_argument& p)
        {
            std::cout << "SYSTEM: Exception caught! Content: " << p.what() << std::endl;
        }


    }

    return 0;
}
