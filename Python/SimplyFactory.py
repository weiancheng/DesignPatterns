#!/usr/bin/env python3

from abc import abstractmethod

class IPhone(object):
    @abstractmethod
    def call(self):
        pass

    @abstractmethod
    def receive(self):
        pass

class Apple(IPhone):
    def __init__(self, phone_model):
        self.__model = phone_model

    def call(self):
        print("Apple(" + self.__model + ") call somebody...")

    def receive(self):
        print("IPhone(" + self.__model + ") anwser the phone...")

class Samsung(IPhone):
    def __init__(self, phone_model):
        self.__model = phone_model

    def call(self):
        print("Samsung(" + self.__model + ") call someone...")

    def receive(self):
        print("Samsung(" + self.__model + ") anwser...")

class Motorola(IPhone):
    def __init__(self, phone_model):
        self.__model = phone_model

    def call(self):
        print("Motorola(" + self.__model + ") call the phone...")

    def receive(self):
        print("Motorola(" + self.__model + ") pick up the phone...")

""" simply factory """
def factory(phone):
    if "motorola" == phone:
        return Motorola("Moto G4")
    elif "apple" == phone:
        return Apple("IPhone 6s")
    elif "samsung" == phone:
        return Samsung("Galaxy s7")
    else:
        return None

def main():
    phone = factory("apple")
    phone.call()
    phone.receive()

if __name__ == '__main__':
    main()
