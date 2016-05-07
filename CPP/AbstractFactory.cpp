#include <iostream>

class ICar {
public:
    ICar() {}
    virtual ~ICar() {}

    virtual void forward(const int speed) = 0;
    virtual void back(const int speed) = 0;
    virtual void left(const int speed) = 0;
    virtual void right(const int speed) = 0;
    virtual std::string getCarName(void) {
        return mName;
    }

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

class IColor {
public:
    IColor(ICar * car) : mCar(car) {}
    virtual ~IColor() {}

    virtual void drawCar(void) = 0;

protected:
    ICar * mCar;
};

class Red : public IColor {
public:
    Red(ICar * car) : IColor(car) {}
    virtual ~Red() {}

    virtual void drawCar(void) {
        std::cout << mCar->getCarName() << " is a red car." << std::endl;
    }
};

class Silver : public IColor {
public:
    Silver(ICar * car) : IColor(car) {}
    virtual ~Silver() {}

    virtual void drawCar(void) {
        std::cout << mCar->getCarName() << " is a silver car." << std::endl;
    }
};

class ICarFactory {
public:
    ICarFactory() {}
    virtual ~ICarFactory() {}

    virtual ICar * createCar(void) = 0;
    virtual IColor * getColor(ICar * car) = 0;
};

class YoungManCarFactory : public ICarFactory {
public:
    YoungManCarFactory() {}
    virtual ~YoungManCarFactory() {}

    virtual ICar * createCar(void) {
        return new SportCar("Mazda MX-5", 300);
    }

    virtual IColor * getColor(ICar * car) {
        return new Silver(car);
    }
};

class BusinessManCarFactory : public ICarFactory {
public:
    BusinessManCarFactory() {}
    virtual ~BusinessManCarFactory() {}

    virtual ICar * createCar(void) {
        return new MuscleCar("Torino GT", 250);
    }

    virtual IColor * getColor(ICar * car) {
        return new Red(car);
    }
};

int main(int argc, char **argv) {
    ICarFactory * factory = new BusinessManCarFactory();

    ICar * my_car = factory->createCar();
    IColor * my_color = factory->getColor(my_car);
    my_color->drawCar();

    delete factory;

    return 0;
}
