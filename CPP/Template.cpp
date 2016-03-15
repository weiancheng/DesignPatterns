#include <iostream>

using namespace std;


class OperatingSystem
{
public:
    void get_information(const char *ip, int port, const char *cmd);
    
protected:
    virtual void get_version(void) = 0;
    virtual void set_socket(const char *ip, int port) = 0;
    virtual void run_cmd(const char *cmd) = 0;
};


void OperatingSystem::get_information(const char *ip, int port, const char *cmd)
{
    set_socket(ip, port);
    get_version();
    run_cmd(cmd);
}


class LinuxSystem : public OperatingSystem
{
public:
    virtual void get_version(void);
    virtual void set_socket(const char *ip, int port);
    virtual void run_cmd(const char *cmd);
};


class WindowsSystem : public OperatingSystem
{
public:
    virtual void get_version(void);
    virtual void set_socket(const char *ip, int port);
    virtual void run_cmd(const char *cmd);
};


void LinuxSystem::get_version()
{
    cout << "Linux 3.2.1" << endl;
}

void LinuxSystem::set_socket(const char *ip, int port)
{
    cout << "Linux " << "set network: " << ip << " @ " << port << endl;
}

void LinuxSystem::run_cmd(const char *cmd)
{
    cout << "Linux exe: " << cmd << endl;
}


void WindowsSystem::get_version()
{
    cout << "Windows10" << endl;
}


void WindowsSystem::set_socket(const char *ip, int port)
{
    cout << "Windows set network: " << ip << " @ " << port << endl;
}

void WindowsSystem::run_cmd(const char *cmd)
{
    cout << "Windows exe: " << cmd << endl;
}


int main(int argc, char **argv)
{
    OperatingSystem *os = new LinuxSystem();

    os->get_information("127.0.0.1", 9527, "dir");

    delete os;
    
    return 0;
}
