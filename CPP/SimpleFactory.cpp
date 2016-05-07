#include <iostream>

// interface
class ICar {
public:
    ICar() {}
    virtual ~ICar() {}

    virtual void forward(const int speed) = 0;
    virtual void back(const int speed) = 0;
    virtual void left(const int speed) = 0;
    virtual void right(const int speed) = 0;

protected:
    std::string mName;
    int mMaxSpeed;
};


class SportCar : public ICar {
public:
    SportCar(std::string car_name, int max_speed) {
        mName = car_name;
        mMaxSpeed = max_speed;
    }

    virtual ~SportCar() {}

    virtual void forward(const int speed) {
        std::cout << mName << ": go forward with " << speed << " miles..." <<
        std::endl;
    }

    virtual void back(const int speed) {
        std::cout << mName << ": go back with " << speed << " miles..." <<
        std::endl;
    }

    virtual void left(const int speed) {
        std::cout << mName << ": turn left with " << speed << " miles..." <<
        std::endl;
    }

    virtual void right(const int speed) {
        std::cout << mName << ": turn right with " << speed << " miles..." <<
        std::endl;
    }
};

class MuscleCar : public ICar {
public:
    MuscleCar(std::string car_name, int max_speed) {
        mName = car_name;
        mMaxSpeed = max_speed;
    }

    virtual ~MuscleCar() {}

    virtual void forward(const int speed) {
        std::cout << mName << ": go forward with " << speed << " miles..." <<
        std::endl;
    }

    virtual void back(const int speed) {
        std::cout << mName << ": go back with " << speed << " miles..." <<
        std::endl;
    }

    virtual void left(const int speed) {
        std::cout << mName << ": turn left with " << speed << " miles..." <<
        std::endl;
    }

    virtual void right(const int speed) {
        std::cout << mName << ": turn right with " << speed << " miles..." <<
        std::endl;
    }
};

class CarFactory {
public:
    CarFactory() {}
    ~CarFactory() {}

    ICar * createCar(std::string name) {
        ICar *car = nullptr;
        if(name.compare("sport car") == 0) {
            car = new SportCar("Mazda MX-5", 300);
        } else if (name.compare("muscle car") == 0) {
            car = new MuscleCar("Chevelle SS", 290);
        }

        return car;
    }
};

int main(int argc, char **argv) {
    CarFactory car_factory;
    ICar *sport_car = car_factory.createCar("sport car");

    sport_car->forward(100);
    sport_car->left(50);

    delete sport_car;

    return 0;
}