#!/usr/bin/python3

import abc

class ICar(object):
	@abc.abstractmethod
	def run(self, speed):
		pass

	@abc.abstractmethod
	def forward(self):
		pass

	@abc.abstractmethod
	def back(self):
		pass

	@abc.abstractmethod
	def right(self):
		pass

	@abc.abstractmethod
	def left(self):
		pass


class SportCar(ICar):
	def __init__(self, name = "Sport Car"):
		self.__car_name = name

	def run(self, speed = 0):
		print(self.__car_name + "(sport car): " + str(speed) + " km/h")

	def forward(self):
		print(self.__car_name + "(sport car): go forward...")

	def back(self):
		print(self.__car_name + "(sport car): go back...")

	def right(self):
		print(self.__car_name + "(sport car): turn right...")

	def left(self):
		print(self.__car_name + "(sport car): turn left...")


class MuscleCar(ICar):
	def __init__(self, name = "Muscle Car"):
		self.__car_name = name

	def run(self, speed = 0):
		print(self.__car_name + "(muscle car): " + str(speed) + " km/h")

	def forward(self):
		print(self.__car_name + "(muscle car): go forward...")

	def back(self):
		print(self.__car_name + "(muscle car): go back...")

	def right(self):
		print(self.__car_name + "(muscle car): turn right...")

	def left(self):
		print(self.__car_name + "(muscle car): turn left...")


class ProxyCar(object):
	def __init__(self, car):
		self.__car = car

	def doForward(self, speed):
		self.__car.run(speed)
		self.__car.forward()

	def doBack(self, speed):
		self.__car.run(speed)
		self.__car.back()

	def doRight(self, speed):
		self.__car.run(speed)
		self.__car.right()

	def doLeft(self, speed):
		self.__car.run(speed)
		self.__car.left()


def main():
	car = SportCar("Porsche Cayman GT4")
	robot_car = ProxyCar(car)

	robot_car.doForward(100)
	robot_car.doRight(60)


if __name__ == '__main__':
	main()
