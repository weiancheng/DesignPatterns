#include <iostream>
#include <string>

using namespace std;

class IFileServer {
public:
    virtual bool isExist(void) = 0;
    virtual void downloadFile(string file_name) = 0;
    virtual void authorization(void) = 0;
    virtual void uploadFile(string file_path) = 0;
    virtual bool checkServerState(void) = 0;
    virtual void adjustNetworkSpeed(void) = 0;
    virtual void setBufferSize(int buf_size) = 0;
    virtual void create_socket(string ip) = 0;
    virtual void connection(void) = 0;

    virtual ~IFileServer() {}
};

class FileServer : public IFileServer {
public:
    FileServer(void)
            : mIP(""), auth(false), hasConnection(false)
    {}

    bool isExist(void) {
        return hasConnection;
    }

    void downloadFile(string file_name) {
        if(auth)
            cout << "download file: " << file_name << endl;
        else
            cout << "no authorization" << endl;
    }

    void authorization(void) {
        cout << "authorization()" << endl;
        auth = true;
    }

    void uploadFile(string file_path) {
        if(auth)
            cout << "up load file: " << file_path << endl;
        else
            cout << "no authorization" << endl;
    }

    bool checkServerState(void) {
        if(hasConnection) {
            cout << "check server's state ..." << endl;
            return true;
        } else {
            cout << "not connection to server ..." << endl;
            return false;
        }
    }

    void adjustNetworkSpeed(void) {
        if(hasConnection)
            cout << "adjust network speed (bps)" << endl;
        else
            cout << "no connection" << endl;
    }

    void setBufferSize(int buf_size) {
        cout << "change buffer size to " << buf_size << endl;
    }

    void create_socket(string ip) {
        mIP = ip;
        cout << "create socket, ip: " << mIP << endl;
    }

    void connection(void) {
        if(mIP.compare("")) {
            cout << "create connection" << endl;
            hasConnection = true;
        } else {
            cout << "error: no socket..." << endl;
            hasConnection = false;
        }
    }

private:
    string mIP;
    bool hasConnection;
    bool auth;
};

class IFileServerProxy {
public:
    virtual void connection(void) = 0;
    virtual void upload(string file_name) = 0;
    virtual void download(string file_name) = 0;
    virtual void disconnection(void) = 0;
};

class FileServerProxy : public IFileServerProxy {
public:
    // constructor
    FileServerProxy(const string ip) {
        IP = ip;
        file_server = new FileServer();
        file_server->setBufferSize(1024);
    }

    // destructor
    ~FileServerProxy() {
        if(file_server)
            delete(file_server);
    }

    void connection(void) {
        file_server->create_socket(IP);
        file_server->connection();
        file_server->authorization();
    }

    void upload(string file_name) {
        if(file_server->isExist() &&
                file_server->checkServerState()) {
            file_server->adjustNetworkSpeed();
            file_server->uploadFile(file_name);
        } else {
            cout << "Error: upload()" << endl;
        }
    }

    void download(string file_name) {
        if(file_server->isExist() &&
                file_server->checkServerState()) {
            file_server->adjustNetworkSpeed();
            file_server->downloadFile(file_name);
        } else {
            cout << "Error: download()" << endl;
        }
    }

    void disconnection(void) {
        if(file_server) {
            delete file_server;
            file_server = NULL;
        }
    }

private:
    FileServer * file_server;
    string IP;
};

int main(int argc, char **argv) {
    const string ip = "127.0.0.1";
    IFileServerProxy *ftp = new FileServerProxy(ip);
    ftp->connection();
    ftp->upload("test.zip");
    ftp->download("test.jpg");
    ftp->disconnection();
    delete ftp;

    return 0;
}