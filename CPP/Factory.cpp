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

class IFactory {
public:
    IFactory() {}
    virtual ~IFactory() {}

    virtual ICar * createCar(void) = 0;
};

class MuscleCarFactory : public IFactory {
public:
    MuscleCarFactory() {}
    virtual ~MuscleCarFactory() {}

    virtual ICar * createCar(void) {
        return new MuscleCar("Chevelle SS", 290);
    }
};

class SportCarFactory : public IFactory {
public:
    SportCarFactory() {}
    ~SportCarFactory() {}

    virtual ICar * createCar(void) {
        return new SportCar("Mazda MX-5", 300);
    }
};

int main(int argc, char **argv) {
    IFactory * car_factory = new SportCarFactory();
    ICar *sport_car = car_factory->createCar();

    sport_car->forward(100);
    sport_car->left(50);

    delete sport_car;

    return 0;
}