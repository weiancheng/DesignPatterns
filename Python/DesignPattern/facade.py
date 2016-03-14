#!/usr/bin/python3

import abc


class OperatingSystem(object):
    @abc.abstractmethod
    def set_socket(self, ip, port):
        pass

    @abc.abstractmethod
    def get_version(self):
        pass

    @abc.abstractmethod
    def bin(self):
        pass


class LinuxSystem(OperatingSystem):
    def __init__(self):
        self.__version = '3.1.25'
        self.__tag = 'Linux'

    def set_socket(self, ip, port):
        print("Linux create a socket: %s@%s" % (str(ip), str(port)))

    def get_version(self):
        print("Linux system is %s" % (self.__version))

    def bin(self):
        print(self.__tag + ": execute a program")


class WindowsSystem(OperatingSystem):
    def __init__(self):
        self.__version = 'Windows10'
        self.__tag = 'Windows'

    def set_socket(self, ip, port):
        print(self.__tag + ": create a winsock")

    def get_version(self):
        print("Windows: %s" % (self.__version))

    def bin(self):
        print(self.__tag + ": execute a program.")


class AndroidSystem(OperatingSystem):
    def __init__(self):
        self.__version = 'Lollipop'
        self.__tag = 'Android'

    def set_socket(self, ip, port):
        print(self.__tag + ": create a socket")

    def get_version(self):
        print("Android: %s" % (self.__version))

    def bin(self):
        print(self.__tag + ": run a program")


class SystemFacade(object):
    def __init__(self):
        pass

    @staticmethod
    def get_os(os):
        if os is 'Linux':
            return LinuxSystem()
        elif os is "Windows":
            return WindowsSystem()
        elif os is "Android":
            return AndroidSystem()
        else:
            return None


def test_facade():
    system = SystemFacade()
    os = system.get_os("Windows")

    os.get_version()
    os.set_socket('127.0.0.1', 9527)
    os.bin()
