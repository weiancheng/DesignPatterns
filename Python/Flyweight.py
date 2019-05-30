#!/usr/bin/env python3

from abc import abstractmethod
from enum import Enum


class EUsageState(Enum):
    Using = 0
    NotUse = 1


class IGun(object):
    def __init__(self):
        self.__state = EUsageState.Using

    @abstractmethod
    def show(self):
        pass


def main():
    pass

if __name__ == "__main__":
    main()
