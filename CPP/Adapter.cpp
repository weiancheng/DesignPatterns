#include <iostream>

class Phone {
public:
    virtual ~Phone() {}
    virtual void setNumber(const int num) = 0;
    virtual void call(void) = 0;
    virtual void receive(void) = 0;

protected:
    int mNumber;
};

class SmartPhone : public Phone {
public:
    void setNumber(const int num) {
        mNumber = num;
        std::cout << "set number into smart phone." << std::endl;
    }

    void call(void) {
        std::cout << "call: " << mNumber << " by Smart Phone" << std::endl;
    }

    void receive(void) {
        std::cout << "receive a call by Smart Phone." << std::endl;
    }
};

class TelePhone : public Phone {
public:
    void setNumber(const int num) {
        mNumber = num;
        std::cout << "set number into phone book" << std::endl;
    }

    void call(void) {
        std::cout << "call: " << mNumber << " by TelePhone" << std::endl;
    }

    void receive(void) {
        std::cout << "receive a call by TelePhone" << std::endl;
    }
};

class Skype {
public:
    virtual ~Skype() {}
    virtual void getIP(std::string IP) = 0;
    virtual void sendRequest(void) = 0;
    virtual void recvRequest(void) = 0;

protected:
    std::string mIP;
};

class Pad : public Skype {
public:
    void getIP(std::string IP) {
        mIP = IP;
    }

    void sendRequest(void) {
        std::cout << "send a connection to " << mIP << " from Pad." << std::endl;
    }

    void recvRequest(void) {
        std::cout << "get a connection (Pad)." << std::endl;
    }
};

class SkypeWrapper : public Phone {
public:
    SkypeWrapper(Skype *device) {
        mDevice = device;
    }

    void setNumber(const int num) {
        mNumber = num;
        std::cout << "convert telephone number to IP ..." << std::endl;
        std::string ip("127.0.0.1");
        mDevice->getIP(ip);
    }

    void call(void) {
        std::cout << "call: " << mNumber << std::endl;
        mDevice->sendRequest();
    }

    void receive(void) {
        std::cout << "receive a call ... " << std::endl;
        mDevice->recvRequest();
    }

    ~SkypeWrapper() {
        if(mDevice)
            delete mDevice;
    }

private:
    Skype *mDevice;
};

class Computer : public Skype {
public:
    void getIP(std::string IP) {
        mIP = IP;
    }

    void sendRequest(void) {
        std::cout << "senda connection to " << mIP << " from Computer." << std::endl;
    }

    void recvRequest(void) {
        std::cout << "get a connection (Computer)." << std::endl;
    }
};

int main(int argc, char **argv) {
    Phone *netphone = new SkypeWrapper(new Computer());

    netphone->setNumber(5555);
    netphone->call();
    netphone->receive();

    delete netphone;

    return 0;
}
