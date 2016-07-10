#!/usr/bin/env python3

from abc import abstractmethod

class IOperatingSystem(object):
    @abstractmethod
    def work(self):
        pass

    @abstractmethod
    def store_data(self):
        pass

class IFirewall(object):
    @abstractmethod
    def defence(self):
        pass

    @abstractmethod
    def scan_system(self):
        pass

class IBrowser(object):
    @abstractmethod
    def webside(self):
        pass

    @abstractmethod
    def store_web(self):
        pass

class Windows(IOperatingSystem):
    def __init__(self, model):
        self.__model = model

    def work(self):
        print("Windows(" + self.__model + ") is running...")

    def store_data(self):
        print("Windows(" + self.__model + ") is saving data...")

class Android(IOperatingSystem):
    def __init__(self, model):
        self.__model = model

    def work(self):
        print("Android(" + self.__model + ") is running...")

    def store_data(self):
        print("Android(" + self.__model + ") is saving data...")

class MacOS(IOperatingSystem):
    def __init__(self, model):
        self.__model = model

    def work(self):
        print("MacOS(" + self.__model + ") is running...")

    def store_data(self):
        print("MacOS(" + self.__model + ") is saving data...")

class Symantec(IFirewall):
    def __init__(self, model):
        self.__model = model

    def defence(self):
        print("Symantec " + self.__model + " is working hardly !!!")

    def scan_system(self):
        print("Symantec " + self.__model + " is scanning virus !!!")

class Trend(IFirewall):
    def __init__(self, model):
        self.__model = model

    def defence(self):
        print("Trend Micro " + self.__model + " is trying to defence virus")

    def scan_system(self):
        print("Trend Micro " + self.__model + " is scanning virus !!!")

class Kaspersky(IFirewall):
    def __init__(self, model):
        self.__model = model

    def defence(self):
        print("Kaspersky " + self.__model + " is working now")

    def scan_system(self):
        print("Kaspersky " + self.__model + " is scanning virus !!!")

class Firefox(IBrowser):
    def __init__(self, url):
        self.__url = url

    def webside(self):
        print("Firefox: " + self.__url)

    def store_web(self):
        print("Firefox: " + self.__url + " save web data...")

class Chrome(IBrowser):
    def __init__(self, url):
        self.__url = url

    def webside(self):
        print("Chrome: " + self.__url)

    def store_web(self):
        print("Chrome: " + self.__url + " save web data...")

class IE(IBrowser):
    def __init__(self, url):
        self.__url = url

    def webside(self):
        print("IE: " + self.__url)

    def store_web(self):
        print("IE: " + self.__url + " save web data...")

class System(object):
    def __init__(self, web):
        self.__windows = Windows("Windows7")
        self.__mac = MacOS("Mac OS 9")
        self.__android = Android("JellyBean")

        self.__kaspersky = Kaspersky("15.0")
        self.__symantec = Symantec("Norton360")
        self.__trend = Trend("PC-cillin")

        self.__firefox = Firefox(web)
        self.__ie = IE(web)
        self.__chrome = Chrome(web)

    def system1(self):
        self.__windows.work()
        self.__kaspersky.defence()
        self.__ie.webside()

    def system2(self):
        self.__mac.store_data()
        self.__trend.scan_system()
        self.__firefox.webside()

    def system3(self):
        self.__android.work()
        self.__symantec.scan_system()
        self.__chrome.store_web()

def main():
    system = System("yahoo")
    system.system1()

if __name__ == '__main__':
    main()
