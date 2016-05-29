#!/usr/bin/python3


class ICar(object):
    def __init__(self, name):
        self._car_name = name

    def goForward(self):
        raise NotImplemented

    def goBack(self):
        raise NotImplemented

    def goRight(self):
        raise NotImplemented

    def goLeft(self):
        raise NotImplemented


class IWorker(object):
    def __init__(self):
        self._car = None

    def setCar(self, car):
        self._car = car

    def doWork(self):
        raise NotImplemented

    def driveCar(self):
        raise NotImplemented


class Boss(IWorker):
    def __init__(self):
        super().__init__()

    def doWork(self):
        print("Boss is working now...")

    def driveCar(self):
        self._car.goForward()
        print("Boss drive car: ")
        self._car.goForward()
        print("Boss drive car: ")
        self._car.goBack()
        print("Boss drive car: ")
        self._car.goLeft()
        print("Boss drive car: ")
        self._car.goRight()


class Benz(ICar):
    def __init__(self, model):
        super().__init__(model)

    def goRight(self):
        print("Benz " + self._car_name + " turn right")

    def goLeft(self):
        print("Benz " + self._car_name + " turn left")

    def goForward(self):
        print("Benz " + self._car_name + " go forward")

    def goBack(self):
        print("Benz " + self._car_name + " go back")


class Toyota(ICar):
    def __init__(self, model):
        super().__init__(model)

    def __show(self, info):
        print("Toyota " + self._car_name + " " + info)

    def goRight(self):
        self.__show("turn right.")

    def goLeft(self):
        self.__show("turn left.")

    def goForward(self):
        self.__show("go forward.")

    def goBack(self):
        self.__show("go back.")


def main():
    benz = Benz('C200')

    boss = Boss()
    boss.setCar(benz)
    boss.driveCar()
    boss.doWork()

if __name__ == '__main__':
    main()
