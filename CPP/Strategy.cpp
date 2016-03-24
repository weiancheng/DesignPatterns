#include <iostream>

class Strategy
{
public:
    virtual int operation(int val1, int val2) = 0;
};


class MathAdd : public Strategy
{
public:
    int operation(int val1, int val2)
    {
        return (val1 + val2);
    }
};

class MathSub : public Strategy
{
    int operation(int val1, int val2)
    {
        return (val1 - val2);
    }
};

class MathMul : public Strategy
{
    int operation(int val1, int val2)
    {
        return (val1 * val2);
    }
};

class MathDiv : public Strategy
{
    int operation(int val1, int val2)
    {
        return (val1 / val2);
    }
};

class Math
{
private:
    Strategy *operate;

public:
    Math(Strategy *o);
    ~Math(void);

    int operation(const int val1, const int val2);
};

Math::Math(Strategy *o)
{
    operate = o;
}

Math::~Math()
{
    operate = NULL;
}

int Math::operation(const int val1, const int val2)
{
    return operate->operation(val1, val2);
}

int main(int argc, char **argv)
{
    Strategy *math_add = new MathAdd();
    Strategy *math_sub = new MathSub();
    Strategy *math_mul = new MathMul();
    Strategy *math_div = new MathDiv();

    Math math(math_mul);

    std::cout << "result: " << math.operation(10, 3) << std::endl;

    delete math_add;
    delete math_sub;
    delete math_mul;
    delete math_div;
    
    return 0;
}
