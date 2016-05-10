#include <iostream>
#include <map>


class Memento;

// originator (object)
class Car {
public:
    Car(void);
    ~Car(void);

    void run(std::string exe, int miles);

private:
    int mTotalMiles;
};

//static Memento * Car::mem = nullptr;

class Memento {
public:
    Memento(const Car &car);
    ~Memento(void);

    Car recover(void) const;

private:
    Car mCar;
};

class ICarCommand {
public:
    ICarCommand(Car * car) : mCar(car) {}
    virtual ~ICarCommand() {}

    virtual void execute(int miles) = 0;

protected:
    Car *mCar;
};

class ForwardCmd : public ICarCommand {
public:
    ForwardCmd(Car * car) : ICarCommand(car) {}
    virtual ~ForwardCmd() {}

    virtual void execute(int miles) {
        mCar->run("Car go forward ...", miles);
    }
};

class BackCmd : public ICarCommand {
public:
    BackCmd(Car * car) : ICarCommand(car) {}
    virtual ~BackCmd() {}

    virtual void execute(int miles) {
        mCar->run("Car go back ...", miles);
    }
};

class LeftCmd : public ICarCommand {
public:
    LeftCmd(Car * car) : ICarCommand(car) {}
    virtual ~LeftCmd() {}

    virtual void execute(int miles) {
        mCar->run("Car go left ...", miles);
    }
};

class RightCmd : public ICarCommand {
public:
    RightCmd(Car * car) : ICarCommand(car) {}
    virtual ~RightCmd() {}

    virtual void execute(int miles) {
        mCar->run("Car go right ...", miles);
    }
};

class CarInvoker {
public:
    CarInvoker(void) {}
    ~CarInvoker(void) {
        std::map<std::string, ICarCommand *>::iterator it;
        for(it = mCommandList.begin() ; it != mCommandList.end() ; it++) {
            delete it->second;
            mCommandList.erase(it);
        }
    }

    void registerCommand(std::string str_cmd, ICarCommand * cmd) {
        mCommandList.insert(std::pair<std::string, ICarCommand *>(str_cmd, cmd));
    }

    void run(std::string cmd, int miles = 0) {
        mCommandList[cmd]->execute(miles);
    }

    void Backup(Car *car) {
        mBackup = new Memento(*car);
    }

    void Recover(Car *car) {
        *car = mBackup->recover();
    }

private:
    std::map<std::string, ICarCommand *> mCommandList;
    Memento * mBackup;
};

Car::Car() : mTotalMiles(0)
{}

Car::~Car() { }

void Car::run(std::string exe, int miles) {
    mTotalMiles += miles;
    std::cout << exe << std::endl;
    std::cout << "Car ran " << mTotalMiles << " miles ..." << std::endl;
}

Memento::Memento(const Car &car) : mCar(car)
{}

Memento::~Memento() { }

Car Memento::recover(void) const {
    return mCar;
}

int main(int argc, char **argv) {
    Car car;
    ICarCommand * forward = new ForwardCmd(&car);
    ICarCommand * back    = new BackCmd(&car);
    ICarCommand * left    = new LeftCmd(&car);
    ICarCommand * right   = new RightCmd(&car);
    CarInvoker car_invoker;

    car_invoker.registerCommand("forward", forward);
    car_invoker.registerCommand("back", back);
    car_invoker.registerCommand("left", left);
    car_invoker.registerCommand("right", right);

    car_invoker.run("left", 10);
    std::cout << "backup the state of car ..." << std::endl;
    car_invoker.Backup(&car);
    std::cout << std::endl;
    car_invoker.run("forward", 100);
    std::cout << std::endl;
    std::cout << "car accident ..." << std::endl;
    std::cout << "recover car state ..." << std::endl;
    std::cout << std::endl;
    car_invoker.Recover(&car);
    std::cout << std::endl;
    car_invoker.run("right", 10);

    return 0;
}
