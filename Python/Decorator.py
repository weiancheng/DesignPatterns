#!/usr/bin/python3

''' http://ot-note.logdown.com/posts/67571/-decorator-with-without-arguments-in-function-class-form '''

from abc import abstractmethod


# decorator pattern with class
# interface
class ICar(object):
    @abstractmethod
    def forward(self, speed=1):
        pass

    @abstractmethod
    def back(self, speed=1):
        pass

    @abstractmethod
    def right(self, speed=1):
        pass

    @abstractmethod
    def left(self, speed=1):
        pass

# decorator
class Turbo(ICar):
    def __init__(self, car):
        self.__car = car

    def forward(self, power=100):
        self.__car.forward(power + 100)

    def back(self, power=100):
        self.__car.back(power + 50)

    def right(self, power=100):
        self.__car.right(power + 30)

    def left(self, power=100):
        self.__car.left(power + 30)


class SportCar(ICar):
    def __init__(self, name):
        self.__car_name = name

    def forward(self, speed=1):
        print(self.__car_name + " go forward, " + str(speed) + "km/h")

    def back(self, speed=1):
        print(self.__car_name + " go back, " + str(speed) + "km/h")

    def right(self, speed=1):
        print(self.__car_name + " turn right, " + str(speed) + "km/h")

    def left(self, speed=1):
        print(self.__car_name + " turn left, " + str(speed) + "km/h")


# decorator pattern with function
def turbo(func):
    def more_power(s):
        func(s + 100)

    return more_power


@turbo
def speed(speed=1):
    print("car speed: " + str(speed) + 'km/h')


def main():
    car = Turbo(SportCar("Mazda 6"))
    car.forward(150)

    speed(100)


if __name__ == '__main__':
    main()
