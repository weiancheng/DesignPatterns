#!/usr/bin/env python3

from abc import abstractmethod

class IWeapon(object):
    @abstractmethod
    def attack(self):
        pass

class ICharacter(object):
    @abstractmethod
    def attack(self):
        pass

    @abstractmethod
    def defence(self):
        pass

class Gun(IWeapon):
    def attack(self):
        print("gun attack ~~")

class Knife(IWeapon):
    def attack(self):
        print("knife attack ~~")

class Sniper(ICharacter):
    def __init__(self, weapon):
        self.__weapon = weapon

    def attack(self):
        print("sniper attack")
        self.__weapon.attack()

    def defence(self):
        print("sniper defence")

class Killer(ICharacter):
    def __init__(self, weapon):
        self.__weapon = weapon

    def attack(self):
        print("killer attack")
        self.__weapon.attack()

    def defence(self):
        print("killer defence")

class Factory(object):
    def __init__(self, weapon, character):
        self.__weapon = weapon
        self.__character = character

    def __createWeapon(self):
        if self.__weapon == "gun":
            return Gun()
        elif self.__weapon == "knife":
            return Knife()
        else:
            return None

    def __createCharacter(self, weapon):
        if self.__character == 'killer':
            return Killer(weapon)
        elif self.__character == 'sniper':
            return Sniper(weapon)
        else:
            return None

    def create(self):
        weapon = self.__createWeapon()
        character = self.__createCharacter(weapon)

        return weapon, character

def main():
    factory = Factory("gun", "killer")
    weapon, character = factory.create()
    character.attack()

if __name__ == '__main__':
    main()
