"""
"
" date: 2016/8/29
" author: Weian Cheng
" describe: practice Prototype Pattern.
"           the key point is clone(), I used copy() to implement this patter.
"
"""
#!/usr/bin/env python3

from abc import abstractmethod
import copy


class Matrix(object):
    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def clone(self):
        pass


class Vector3(Matrix):
    def __init__(self, x=0, y=0, z=0):
        self._x = x
        self._y = y
        self._z = z

    @property
    def x(self):
        return self._x

    @property
    def y(self):
        return self._y

    @property
    def z(self):
        return self._z

    @x.setter
    def x(self, value):
        self._x = value

    @y.setter
    def y(self, value):
        self._y = value

    @z.setter
    def z(self, value):
        self._z = value

    def show(self):
        print("Vector information:")
        print("X: " + str(self._x))
        print("Y: " + str(self._y))
        print("Z: " + str(self._z))

    def clone(self):
        return copy.copy(self)  # only clone this object
        # clone this object, and clone another object.
        # return copy.deepcopy(self)


def main():
    v = Vector3()
    v.x = 10
    v.y = 20
    v.z = 30
    print("Vector1: ")
    v.show()

    print("")

    v2 = Vector3(50, 50, 50)
    print("Vector2: ")
    v2.show()

    v2 = v.clone()
    print("\nVector3: ")
    v2.show()

if __name__ == "__main__":
    main()
