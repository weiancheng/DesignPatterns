#!/usr/bin/python3


class OrdinarySingleton(object):
    __static_instance = None

    def __new__(cls, *args, **kwargs):
        if not cls.__static_instance:
            cls.__static_instance = \
                super(OrdinarySingleton, cls).__new__(cls, *args, **kwargs)

        return cls.__static_instance

    def setInformation(self, info):
        self.information = info

    def getInformation(self):
        return self.information


class BorgSingleton(object):
    __static_instance = {}

    def __init__(self):
        self.__dict__ = BorgSingleton.__static_instance

    def setInformation(self, info):
        self.information = info

    def getInformation(self):
        return self.information


def test_BorgSinglton():
    singleton = BorgSingleton()
    singleton.setInformation("test Borg Singleton")

    singleton2 = BorgSingleton()
    print(singleton2.getInformation())


def test_OrdinarySingleton():
    singleton = OrdinarySingleton()
    singleton.setInformation("this is ordinary singleton")

    singleton2 = OrdinarySingleton()
    print(singleton2.getInformation())



def main():
    test_BorgSinglton()
    test_OrdinarySingleton()

if __name__ == '__main__':
    main()