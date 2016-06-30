#!/usr/bin/env python3

from abc import abstractmethod

class IMainCourse(object):
    @abstractmethod
    def getMainCourseName(self):
        pass

class IDrink(object):
    @abstractmethod
    def getDrinkName(self):
        pass

class IDessert(object):
    @abstractmethod
    def getDessertName(self):
        pass

class Steak(IMainCourse):
    def __init__(self, name):
        super().__init__()
        self.__main_course = "Steak: " + name

    def getMainCourseName(self):
        return self.__main_course

class Pork(IMainCourse):
    def __init__(self, name):
        super().__init__()
        self.__main_course = "Pork: " + name

    def getMainCourseName(self):
        return self.__main_course

class Chicken(IMainCourse):
    def __init__(self, name):
        super().__init__()
        self.__main_course = "Chicken: " + name

    def getMainCourseName(self):
        return self.__main_course

class Beer(IDrink):
    def __init__(self, name):
        super().__init__()
        self.__drink = "Beer: " + name

    def getDrinkName(self):
        return self.__drink

class SoftDrink(IDrink):
    def __init__(self, name):
        super().__init__()
        self.__drink = "SoftDrink: " + name

    def getDrinkName(self):
        return self.__drink

class Tea(IDrink):
    def __init__(self, name):
        super().__init__()
        self.__drink = "Tea: " + name

    def getDrinkName(self):
        return self.__drink

class Cake(IDessert):
    def __init__(self, name):
        super().__init__()
        self.__dessert = "Cake: " + name

    def getDessertName(self):
        return self.__dessert

class Custard(IDessert):
    def __init__(self, name):
        super().__init__()
        self.__dessert = "Custard: " + name

    def getDessertName(self):
        return self.__dessert

class Doughnut(IDessert):
    def __init__(self, name):
        super().__init__()
        self.__dessert = "Doughnut: " + name

    def getDessertName(self):
        return self.__dessert

""" factory pattern """
class IFactory(object):
    @abstractmethod
    def factory(self):
        pass

class MainCourseFactory(IFactory):
    def __init__(self, food_type):
        self.__food_type = food_type

    def factory(self):
        if "steak" == self.__food_type:
            return self.__createSteak()
        elif "pork" == self.__food_type:
            return self.__createChicken()
        elif "chicken" == self.__food_type:
            return self.__createChicken()
        else:
            return None

    def __createSteak(self):
        return Steak("Beef Wellington")

    def __createPork(self):
        return Pork("Pork tenderloin")

    def __createChicken(self):
        return Chicken("Bamboo Chicken")

class DrinkFactory(IFactory):
    def __init__(self, drink_type):
        self.__drink_type = drink_type

    def factory(self):
        if "beer" == self.__drink_type:
            return self.__createBeer()
        elif "softdrink" == self.__drink_type:
            return self.__createSoftDrink()
        elif "tea" == self.__drink_type:
            return self.__createTea()
        else:
            return None

    def __createBeer(self):
        return Beer("Blue Moon")

    def __createSoftDrink(self):
        return SoftDrink("Coca Cola")

    def __createTea(self):
        return Tea("Darjeeling Tea")

class DessertFactory(IFactory):
    def __init__(self, dessert_type):
        self.__dessert_type = dessert_type

    def factory(self):
        if self.__dessert_type == "cake":
            return self.__createCake()
        elif self.__dessert_type == "custard":
            return self.__createCustard()
        elif self.__dessert_type == "doughnut":
            return self.__createDoughnut()
        else:
            return None

    def __createCake(self):
        return Cake("Cheese Cake")

    def __createCustard(self):
        return Custard("Banana Pudding")

    def __createDoughnut(self):
        return Doughnut("Rosette")

""" abstract factory pattern """
class ISet(object):
    @abstractmethod
    def orderFood(self):
        pass

    @abstractmethod
    def menu(self):
        pass

class BeefSet(ISet):
    def __init__(self):
        super().__init__()

    def menu(self):
        print("===== Menu =====")
        print("Beef Wellington")
        print("Blue Moon Beer")
        print("Cheese Cake")
        print("===============")

    def orderFood(self):
        main_course = MainCourseFactory("steak")
        drink = DrinkFactory("beer")
        dessert = DessertFactory("cake")
        return (main_course.factory(), drink.factory(), dessert.factory())

class PorkSet(ISet):
    def __init__(self):
        super().__init__()

    def menu(self):
        print("===== Menu =====")
        print("Pork tenderloin")
        print("Darjeeling Tea")
        print("Banana Pudding")
        print("===============")

    def orderFood(self):
        main_course = MainCourseFactory("pork")
        drink = DrinkFactory("tea")
        dessert = DessertFactory("custard")
        return (main_course.factory(), drink.factory(), dessert.factory())

class ChickenSet(ISet):
    def __init__(self):
        super().__init__()

    def menu(self):
        print("===== Menu =====")
        print("Bamboo Chicken")
        print("Blue Moon Beer")
        print("Rosette")
        print("===============")

    def orderFood(self):
        main_course = MainCourseFactory("chicken")
        drink = DrinkFactory("beer")
        dessert = DessertFactory("doughnut")
        return (main_course.factory(), drink.factory(), dessert.factory())


def main():
    Set = ChickenSet()
    Set.menu()
    (main, drink, dessert) = Set.orderFood()

    print(main.getMainCourseName())
    print(drink.getDrinkName())
    print(dessert.getDessertName())


if __name__ == '__main__':
    main()
