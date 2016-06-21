#!/usr/bin/python3

from abc import abstractmethod
from enum import Enum


class LEVEL(Enum):
    Boss = 0
    Director = 1
    Manager = 2
    Engineer = 3
    Intern = 4

class IEmployee(object):
    def __init__(self, name, level, ID, dp):
        self._mLevel = level
        self._mName = name
        self._mID = ID
        self._mDepartment = dp

    def set_level(self, level=LEVEL.Engineer):
        self._mLevel = level

    def set_name(self, name):
        self._mName = name

    def set_id(self, id):
        self._mID = id

    def set_department(self, dp):
        self._mDepartment = dp

    @abstractmethod
    def add_member(self, member):
        raise Exception("Not support this function...")

    @abstractmethod
    def remove_member(self, member):
        raise Exception("Not support this function...")


class Manager(IEmployee):
    def __init__(self, name, level, ID, dp):
        super().__init__(name, level, ID, dp)
        self.__mMembers = []

    def add_member(self, member):
        self.__mMembers.append(member)

    def remove_member(self, mID):
        for member in self.__mMembers:
            if member.__mID == mID:
                member.erase(member)

    def __call__(self):
        print("Name: " + self._mName + " (" + str(self._mID) + ")")
        print(self._mDepartment + " " + str(self._mLevel))
        print("has member:" + str(len(self.__mMembers)))


class BasicWorker(IEmployee):
    def __init__(self, name, level, ID, dp):
        super().__init__(name, level, ID, dp)

    def __call__(self):
        print("Name: " + self._mName + " (" + str(self._mID) + ")")
        print(self._mDepartment + " " + str(self._mLevel))

def main():
    ceo = Manager("Bill", LEVEL.Boss, 1, "Company")
    computer_director = Manager("Jack", LEVEL.Director, 100, "Computer")
    financial_director = Manager("Jim", LEVEL.Director, 102, "Financial")
    ceo.add_member(computer_director)
    ceo.add_member(financial_director)

    computer_manager = Manager("Tim", LEVEL.Manager, 1002, "Computer")
    financial_manger = Manager("Mary", LEVEL.Manager, 1020, "Financial")

    computer_director.add_member(computer_manager)
    financial_director.add_member(financial_manger)

    computer_engineer = BasicWorker("Alan", LEVEL.Engineer, 10021, "Computer")
    computer_manager.add_member(computer_engineer)

    financial_manger()  
    print("")
    computer_engineer()
    
if __name__ == '__main__':
    main()
