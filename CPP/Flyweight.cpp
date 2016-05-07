#include <iostream>

enum EColor {
    ERed = 0,
    EBlack = 1,
    EYellow = 2,
};

enum EShape {
    ESquare = 0,
    ETriangle = 3,
    ECircle = 6,
};

class IColor {
public:
    IColor(void) {}
    virtual ~IColor() {}

    virtual void drawColor(void) = 0;
};

class Red : public IColor {
public:
    Red(void) {}
    virtual ~Red() {}

    virtual void drawColor(void) {
        std::cout << "I use Red color to ";
    }
};

class Black : public IColor {
public:
    Black(void) {}
    virtual ~Black() {}

    virtual void drawColor(void) {
        std::cout << "I use Black color to ";
    }
};

class Yellow : public IColor {
public:
    Yellow(void) {}
    virtual ~Yellow() {}

    virtual void drawColor(void) {
        std::cout << "I use Yellow color to ";
    }
};

class IShape {
public:
    IShape(IColor *color) : mColor(color) {}
    virtual ~IShape() {}

    virtual void draw(void) = 0;
    virtual void showDetail(void) = 0;

protected:
    IColor *mColor;
};

class Square : public IShape {
public:
    Square(IColor *color) : IShape(color) {}
    virtual ~Square() {}

    virtual void draw(void) {
        mColor->drawColor();
        std::cout << "draw a square picture." << std::endl;
    }

    virtual void showDetail(void) {
        std::cout << "Shape: Square" << std::endl;
    }
};

class Circle : public IShape {
public:
    Circle(IColor *color) : IShape(color) {}
    virtual ~Circle() {}

    virtual void draw(void) {
        mColor->drawColor();
        std::cout << "draw a circle picture." << std::endl;
    }

    virtual void showDetail(void) {
        std::cout << "Shape: Circle" << std::endl;
    }
};

class Triangle : public IShape {
public:
    Triangle(IColor *color) : IShape(color) {}
    virtual ~Triangle() {}

    virtual void draw(void) {
        mColor->drawColor();
        std::cout << "draw a triangle picture." << std::endl;
    }

    virtual void showDetail(void) {
        std::cout << "Shape: Triangle" << std::endl;
    }
};

class FlyweightFactory {
public:
    static void init(void) {
        mColors[0] = new Red();
        mColors[1] = new Black();
        mColors[2] = new Yellow();

        for(int i = 0 ; i < 9 ; i++) {
            mShape[i] = nullptr;
        }
    }

    static IShape * getShapeByColor(EShape shape, EColor color) {
        int index = shape + color;
        if(mShape[index] == nullptr) {
            switch(shape) {
                case ECircle:
                std::cout << "create a circle" << std::endl;
                    mShape[index] = new Circle(mColors[color]);
                    break;

                case ETriangle:
                std::cout << "create a triangle" << std::endl;
                    mShape[index] = new Triangle(mColors[color]);
                    break;

                case ESquare:
                std::cout << "create a square" << std::endl;
                    mShape[index] = new Square(mColors[color]);
                    break;
            }
        }

        return mShape[index];
    }

private:
    static IColor * mColors[3];
    static IShape * mShape[9];
};

IColor * FlyweightFactory::mColors[3];
IShape * FlyweightFactory::mShape[9];

int main(int argc, char **argv) {
    FlyweightFactory::init();
    IShape * shape = FlyweightFactory::getShapeByColor(ESquare, EYellow);
    IShape * shape2 = FlyweightFactory::getShapeByColor(ESquare, EYellow);

    shape->draw();
    shape2->draw();

    return 0;
}
