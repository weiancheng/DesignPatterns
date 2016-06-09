#!/usr/bin/python3

from abc import abstractmethod


class ICar(object):
    @abstractmethod
    def forward(self, speed=1):
        pass

    @abstractmethod
    def right(self, speed=1):
        pass

    @abstractmethod
    def left(self, speed=1):
        pass

    @abstractmethod
    def back(self, speed=1):
        pass


class SportCar(ICar):
    def __init__(self, car_name):
        self.__name = car_name

    def forward(self, speed=1):
        print("(Sport Car)" + self.__name + " go forward with " +
              str(speed) + "km/h")

    def right(self, speed=1):
        print("(Sport Car)" + self.__name + " turn right with " +
              str(speed) + "km/h")

    def left(self, speed=1):
        print("(Sport Car)" + self.__name + " turn left with " +
              str(speed) + "km/h")

    def back(self, speed=1):
        print("(Sport Car)" + self.__name + " go back with " +
              str(speed) + "km/h")


class MuscleCar(ICar):
    def __init__(self, car_name):
        self.__name = car_name

    def forward(self, speed=1):
        print("(Muscle Car)" + self.__name + " go forward with " +
              str(speed) + "km/h")

    def right(self, speed=1):
        print("(Muscle Car)" + self.__name + " turn right with " +
              str(speed) + "km/h")

    def left(self, speed=1):
        print("(Muscle Car)" + self.__name + " turn left with " +
              str(speed) + "km/h")

    def back(self, speed=1):
        print("(Muscle Car)" + self.__name + " go back with " +
              str(speed) + "km/h")


class AI(object):
    def __init__(self, car):
        self.__car = car

    def speed(self, speed):
        print("AI " + self.__car + " speed: " + str(speed) + "km/h")

    def go_forward(self):
        print("AI " + self.__car + " go forward.")

    def go_back(self):
        print("AI " + self.__car + " go back.")

    def go_right(self):
        print("AI " + self.__car + " turn right.")

    def go_left(self):
        print("AI " + self.__car + " turn left.")


# adapter pattern
class Adapter(ICar):
    def __init__(self, ai):
        self.__ai = ai

    def forward(self, speed=1):
        self.__ai.speed(speed)
        self.__ai.go_forward()

    def back(self, speed=1):
        self.__ai.speed(speed)
        self.__ai.go_back()

    def right(self, speed=1):
        self.__ai.speed(speed)
        self.__ai.go_right()

    def left(self, speed=1):
        self.__ai.speed(speed)
        self.__ai.go_left()


def main():
    # car = MuscleCar("Chevelle SS")
    # car.forward(40)

    ai = Adapter(AI("AlphaGo"))
    ai.forward(60)


if __name__ == '__main__':
    main()
