#!/usr/bin/python3

from abc import abstractmethod


class ICommand(object):
    @abstractmethod
    def execute(self, speed):
        pass


class Forward(ICommand):
    def __init__(self, car):
        self.__car = car

    def execute(self, speed):
        self.__car.run(speed)
        self.__car.forward()


class Back(ICommand):
    def __init__(self, car):
        self.__car = car

    def execute(self, speed):
        self.__car.run(speed)
        self.__car.back()


class Right(ICommand):
    def __init__(self, car):
        self.__car = car

    def execute(self, speed):
        self.__car.run(speed)
        self.__car.right()


class Left(ICommand):
    def __init__(self, car):
        self.__car = car

    def execute(self, speed):
        self.__car.run(speed)
        self.__car.left()


class Car(object):
    def __init__(self, name):
        self.__car_name = name

    def run(self, speed=1):
        print(self.__car_name + " speed: " + str(speed) + "km/h")

    def forward(self):
        print(self.__car_name + " go forward...")

    def back(self):
        print(self.__car_name + " go back...")

    def right(self):
        print(self.__car_name + " turn right...")

    def left(self):
        print(self.__car_name + " turn left...")


class CarInvoker(object):
    def __init__(self):
        self.__cmd_list = {}

    def set_command(self, name, cmd):
        self.__cmd_list.update({name:cmd})

    def exe(self, cmd, speed=1):
        self.__cmd_list[cmd].execute(speed)


def main():
    car = Car("Mazda 3")
    forward_cmd = Forward(car)
    back_cmd = Back(car)
    right_cmd = Right(car)
    left_cmd = Left(car)

    invoker = CarInvoker()
    invoker.set_command("forward", forward_cmd)
    invoker.set_command("back", back_cmd)
    invoker.set_command("right", right_cmd)
    invoker.set_command("left", left_cmd)

    invoker.exe("right", 90)
    invoker.exe("forward", 120)


if __name__ == '__main__':
    main()
