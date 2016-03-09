#!/usr/bin/python3


class LinuxSystem(object):
    def __init__(self):
        self.__version = '3.1.25'
        self.__tag = 'Linux'

    def set_socket(self, ip, port):
        print(self.__tag + ": create socket")

    def get_version(self):
        return self.__version

    def bin(self):
        print(self.__tag + ": execute a program")


class WindowsSystem(object):
    def __init__(self):
        self.__version = 'Windows10'
        self.__tag = 'Windows'

    def set_winsock(self):
        print(self.__tag + ": create a winsock")

    def find_version(self):
        return self.__version

    def run_exe(self):
        print(self.__tag + ": execute a program.")


class AndroidSystem(object):
    def __init__(self):
        self.__version = 'Lollipop'
        self.__tag = 'Android'

    def set_sock(self, ip, port):
        print(self.__tag + ": create a socket")

    def return_version(self):
        return self.__version

    def dot_bin(self):
        print(self.__tag + ": run a program")


class SystemFacade(object):
    def __init__(self):
        self.__os = None
        self.__system = None

    def set_os(self, os):
        if os is 'Linux':
            self.__system = LinuxSystem()
        elif os is 'Win':
            self.__system = WindowsSystem()
        elif os is 'android':
            self.__system = AndroidSystem()
        else:
            return False

        self.__os = os
        return True

    def network(self, ip='localhost', port=9527):
        if self.__os == 'Linux':
            self.__system.set_socket(ip. port)
        elif self.__os == 'Win':
            self.__system.get_winsock()
        else:
            self.__system.set_sock(ip, port)

    def version(self):
        if self.__os is 'Linux':
            return self.__system.get_version()
        elif self.__os is 'Win':
            return self.__system.find_version()
        else:
            return self.__system.return_version()

    def exe_program(self):
        if self.__os is 'Linux':
            self.__system.bin()
        elif self.__os is 'Win':
            self.__system.run_exe()
        else:
            self.__system.dot_bin()


def test_facade():
    os = SystemFacade()
    os.set_os("Win")
    os.network()
