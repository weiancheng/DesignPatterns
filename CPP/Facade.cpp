#include <iostream>

using namespace std;


class SystemOne
{
public:
    void method1(void);
    void method2(void);
};

void SystemOne::method1()
{
    cout << "SystemOne: method1()" << endl;
}

void SystemOne::method2()
{
    cout << "SystemOne: methon2()" << endl;
}

class LibraryOne
{
public:
    int function1(void);
    int function2(void);
};

int LibraryOne::function1()
{
    cout << "LibraryOne: function1()" << endl;
    return 1;
}

int LibraryOne::function2()
{
    cout << "LibraryOne: function2()" << endl;
    return 0;
}

class MyFacade
{
public:
    MyFacade(void);
    ~MyFacade(void);

    bool Method_One(void);
    bool Method_Two(void);

private:
    LibraryOne lib;
    SystemOne sys;
};


MyFacade::MyFacade()
{
}

MyFacade::~MyFacade()
{
}

bool MyFacade::Method_One()
{
    cout << "This is Facade method 1" << endl;
    lib.function2();
    sys.method1();
    cout << "method 1 end" << endl;
}

bool MyFacade::Method_Two()
{
    cout << "This is Facade method 2" << endl;
    sys.method2();
    lib.function1();
    cout << "method 2 end" << endl;
}


int main(int argc, char **argv)
{
    MyFacade facade;

    facade.Method_One();
    facade.Method_Two();
    
    return 0;
}
