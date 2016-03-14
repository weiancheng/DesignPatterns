#include <iostream>

using namespace std;


class OperatingSystem
{
public:
    virtual void get_version(void) = 0;
    virtual void set_socket(const char *ip, int port) = 0;
    virtual void run_cmd(const char *cmd) = 0;
};


class LinuxSystem : public OperatingSystem
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
    cout << "set network: " << ip << " @ " << port << endl;
}

void LinuxSystem::run_cmd(const char *cmd)
{
    cout << "exe: " << cmd << endl;
}


int main(int argc, char **argv)
{
    OperatingSystem *os = new LinuxSystem();

    os->get_version();
    os->set_socket("127.0.0.1", 9527);
    os->run_cmd("ls");

    delete os;
    
    return 0;
}
