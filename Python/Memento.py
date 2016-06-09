#!/usr/bin/python3

from abc import abstractmethod
import copy


class ICharacter(object):
    def __init__(self):
        self._name = None
        self._attack = 0
        self._defence = 0
        self._weapon = None
        self._health_point = 0

    def _set_name(self, name):
        self._name = name

    def set_attack(self, number):
        self._attack = number

    def _set_defence(self, number):
        self._defence = number

    def _set_weapon(self, weapon):
        self._weapon = weapon

    def _set_hp(self, hp):
        self._health_point = hp

    @abstractmethod
    def do_attack(self):
        pass

    @abstractmethod
    def do_defence(self):
        pass


class Knight(ICharacter):
    def __init__(self, name, attack, defence, weapon, hp):
        super(Knight, self).__init__()
        self._set_name(name)
        self.set_attack(attack)
        self._set_defence(defence)
        self._set_weapon(weapon)
        self._set_hp(hp)

    def do_attack(self):
        print(self._name + "uses " + self._weapon +
              " attacking " + str(self._attack))

    def do_defence(self):
        print(self._name + "uses " + self._weapon +
              " defencing " + str(self._defence))

    def get_attack(self, attack):
        print(self._name + "got attack: " + str(attack))
        self._health_point -= attack
        if self._health_point <= 0:
            print(self._name + " is dead ...")


class CheckPoint(object):
    def __init__(self, character):
        self.__cps = []
        self.__character = character

    def save(self):
        self.__cps.append(copy.deepcopy(self.__character))

    def recover(self):
        if not len(self.__cps):
            return None

        return copy.deepcopy(self.__cps.pop())


def main():
    knight = Knight("Jason", 100, 50, "knife", 100)
    check_points = CheckPoint(knight)
    check_points.save()
    knight.do_attack()
    knight.get_attack(50)
    check_points.save()
    knight.do_defence()
    knight.get_attack(51)
    knight = check_points.recover()
    knight.get_attack(40)


if __name__ == '__main__':
    main()
