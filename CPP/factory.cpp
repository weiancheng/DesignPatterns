#include <iostream>
#include <cstring>

using namespace std;


class OperatingSystem
{
public:
    OperatingSystem(void) {}
    //virtual ~OperatingSystem(void) {}
    virtual void get_version(void) = 0;
    virtual void set_socket(const char *ip, const int port) = 0;
    virtual void exe(const char *cmd) = 0;

protected:
    char mCmd[80];
    char mIP[30];
    int mPort;
};


class Linux : public OperatingSystem
{
public:
    virtual void get_version(void);
    virtual void set_socket(const char *ip, const int port);
    virtual void exe(const char *cmd);
};

class Android : public OperatingSystem
{
public:
    virtual void get_version(void);
    virtual void set_socket(const char *ip, const int port);
    virtual void exe(const char *cmd);
};

void Linux::get_version()
{
    cout << "Linux 3.2.1" << endl;
}

void Linux::set_socket(const char *ip, const int port)
{
    memcpy(mIP, ip, 30);
    mPort = port;
    cout << "Linux: " << mIP << " @ " << mPort << endl;
}

void Linux::exe(const char *cmd)
{
    memcpy(mCmd, cmd, 80);
    cout << "Linux: exe " << mCmd << endl;
}

void Android::get_version()
{
    cout << "Android Lollipop" << endl;
}

void Android::set_socket(const char *ip, const int port)
{
    memcpy(mIP, ip, 30);
    mPort = port;
    cout << "Android: " << mIP << " " << mPort << endl;
}

void Android::exe(const char *cmd)
{
    memcpy(mCmd, cmd, 80);
    cout << "Android command: " << mCmd << endl;
}

int main(int argc, char **argv)
{
    OperatingSystem *os = new Android();

    os->get_version();
    os->set_socket("192.168.0.1", 1111);
    os->exe("/bin/ls");

    delete os;

    return 0;
}

