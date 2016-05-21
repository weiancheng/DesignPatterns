#include <iostream>

class Singleton {
public:
    ~Singleton();
    static Singleton * getInstance(void);

private:
    Singleton(void);
    static Singleton * instance;
};

Singleton * Singleton::instance = nullptr;

Singleton::Singleton() {
    std::cout << "Hello, this is singleton object." << std::endl;
}

Singleton::~Singleton() {
    std::cout << "destroy this object." << std::endl;
}

Singleton * Singleton::getInstance() {
    if(instance == nullptr) {
        instance = new Singleton();
    } else {
        return instance;
    }
}

int main(int argc, char **argv) {
    Singleton * s = Singleton::getInstance();

    // delete s;

    return 0;
}
