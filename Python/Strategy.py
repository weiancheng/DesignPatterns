#!/usr/bin/env python3

from abc import abstractmethod


class CompressAlgorithm(object):
    @abstractmethod
    def compress(self):
        pass

    @abstractmethod
    def decompress(self):
        pass

    @abstractmethod
    def test_file(self):
        pass


class Compress7z(CompressAlgorithm):
    def __init__(self, file_name):
        self.__file_name = file_name

    def compress(self):
        print("compress " + self.__file_name + " -> " + self.__file_name + ".7z")

    def decompress(self):
        print("decompress " + self.__file_name + ".7z")

    def test_file(self):
        print("test " + self.__file_name + " ...")


class CompressZip(CompressAlgorithm):
    def __init__(self, file_name):
        self.__file_name = file_name

    def compress(self):
        print("compress " + self.__file_name + " -> " + self.__file_name + ".zip")

    def decompress(self):
        print("decompress " + self.__file_name + ".zip")

    def test_file(self):
        print("test " + self.__file_name + " ...")


class CompressRAR(CompressAlgorithm):
    def __init__(self, file_name):
        self.__file_name = file_name

    def compress(self):
        print("compress " + self.__file_name + " -> " + self.__file_name + ".rar")

    def decompress(self):
        print("decompress " + self.__file_name + ".rar")

    def test_file(self):
        print("test " + self.__file_name + " ...")


class StrategyExample(object):
    def __init__(self, algo=None):
        self.__compress_algo = algo

    def execute1(self, file_name):
        self.__compress_algo(file_name).compress()
        self.__compress_algo(file_name).test_file()
        self.__compress_algo(file_name).decompress()

    def execute2(self, file_name):
        algorithm = self.__compress_algo(file_name)
        algorithm.compress()
        algorithm.test_file()
        algorithm.decompress()

def main():
    test = StrategyExample(Compress7z)
    print("execute 1")
    test.execute1("aaa")
    print("\nexecute 2")
    test.execute2("bbb")

if __name__ == "__main__":
    main()
