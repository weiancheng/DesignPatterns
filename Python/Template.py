#!/usr/bin/env python3

from abc import abstractmethod


class Animal(object):
    def __init__(self):
        self._name = None
        self._feet = 0
        self._eat = None

    def show_info(self):
        print("Name: " + self._name)
        print("Feet: " + str(self._feet))
        print("Eat: " + self._eat)

    @abstractmethod
    def howl(self):
        pass

    @abstractmethod
    def attack(self):
        pass


class Dog(Animal):
    def __init__(self):
        super().__init__()
        self._name = "Dog"
        self._feet = int(4)
        self._eat = "meat"

    def howl(self):
        print(self._name + " is barking")

    def attack(self):
        print(self._name + "beats someone")


class Horse(Animal):
    def __init__(self):
        super().__init__()
        self._name = "Horse"
        self._feet = int(4)
        self._eat = "grass"

    def howl(self):
        print(self._name + " neigh")

    def attack(self):
        print(self._name + "kicks someone")


class Rooster(Animal):
    def __init__(self):
        super().__init__()
        self._name = "Rooster"
        self._feet = int(2)
        self._eat = "omnivore"

    def howl(self):
        print(self._name + " crow")

    def attack(self):
        print(self._name + "don't attack")


def main():
    animal = Rooster()
    animal.show_info()
    print("\n")
    animal.howl()
    animal.attack()

if __name__ == '__main__':
    main()
