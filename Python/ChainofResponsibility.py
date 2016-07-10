#!/usr/bin/env python3

from abc import abstractmethod

class IEmployee(object):
    def __init__(self, level, helper):
        self._level = level
        self._helper = helper

    @abstractmethod
    def work(self, level):
        pass

    @abstractmethod
    def call_helper(self, work_level):
        pass

class Professor(IEmployee):
    def __init__(self, level, helper):
        super().__init__(level, helper)

    def work(self, work_level):
        if self._level < work_level:
            self.call_helper(work_level)
        else:
            print("Professor finished this work")

    def call_helper(self, work_level):
        print("work is too hard to do, so that no one can handle this...")

class Master(IEmployee):
    def __init__(self, level, helper):
        super().__init__(level, helper)

    def work(self, work_level):
        if self._level < work_level:
            print("Master need a hand...")
            self.call_helper(work_level)
        else:
            print("Master finished this work...")

    def call_helper(self, work_level):
        self._helper.work(work_level)

class Intern(IEmployee):
    def __init__(self, level, helper):
        super().__init__(level, helper)

    def work(self, work_level):
        if  self._level < work_level:
            print("Intern can't handle this ~~~")
            self.call_helper(work_level)
        else:
            print("Intern can do this !!!")

    def call_helper(self, work_level):
        self._helper.work(work_level)

def main():
    professor = Professor(3, None)
    master = Master(2, professor)
    student = Intern(1, master)

    student.work(3)

if __name__ == '__main__':
    main()
