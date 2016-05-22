#include <iostream>
#include <list>

class IEmployee {
public:
    IEmployee(const std::string &name) : mName(name) {};
    virtual ~IEmployee() {};

    virtual void update(void) = 0;

protected:
    std::string mName;
};

class Boss {
public:
    Boss(void);
    ~Boss();

    void attach(IEmployee &employee);
    void detach(IEmployee &employee);

    void notify(void);

private:
    std::list<IEmployee *> mEmployees;
};

Boss::Boss() { }

Boss::~Boss() { }

void Boss::attach(IEmployee &employee) {
    mEmployees.push_back(&employee);
}

void Boss::detach(IEmployee &employee) {
    std::list<IEmployee *>::iterator it;

    for(it = mEmployees.begin() ; it != mEmployees.end() ; it++) {
        if((*it) == &employee) {
            mEmployees.erase(it);
        }
    }
}

void Boss::notify() {
    std::list<IEmployee *>::iterator it;

    for(it = mEmployees.begin() ; it != mEmployees.end() ; it++) {
        (*it)->update();
    }
}

class Engineer : public IEmployee {
public:
    Engineer(std::string name);
    ~Engineer();

    virtual void update(void);
};

Engineer::Engineer(std::string name) : IEmployee(name) {
}

Engineer::~Engineer() { }

void Engineer::update() {
    std::cout << "Boss: " << mName << ", you have to work now !!!" << std::endl;
}

class Assister : public IEmployee {
public:
    Assister(std::string name);
    ~Assister();

    virtual void update(void);
};

Assister::Assister(std::string name) : IEmployee(name) {
}

Assister::~Assister() {
}

void Assister::update() {
    std::cout << "Boss: ";
    std::cout << mName;
    std::cout << ", booking a meeting room for us, please." << std::endl;
}

int main(int argc, char **argv) {
    Boss boss;

    IEmployee * jack = new Engineer("Jack");
    IEmployee * totah = new Engineer("Totah");
    IEmployee * amy = new Assister("Amy");

    boss.attach(*jack);
    boss.attach(*totah);
    boss.attach(*amy);

    boss.notify();

    boss.detach(*jack);
    boss.detach(*totah);
    boss.detach(*amy);


    delete jack;
    delete totah;
    delete amy;

    return 0;
}
