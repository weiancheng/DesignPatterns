#include <iostream>
#include <cstring>
#include <vector>


class IExpression {
public:
	IExpression(void) {}
	virtual ~IExpression() {}

	virtual void interpreter(void) = 0;
};

class PlusExpress : public IExpression {
public:
	PlusExpress(IExpression *left, IExpression * right);
	virtual ~PlusExpress();
	void setStack(std::vector<char> *stack);

	virtual void interpreter(void);

private:
	IExpression *mLeft;
	IExpression *mRight;
	std::vector<char> *mStack;
};

PlusExpress::PlusExpress(IExpression *left, IExpression *right)
	: mLeft(left), mRight(right) {
}

PlusExpress::~PlusExpress() {
}

void PlusExpress::setStack(std::vector<char> *stack) {
	if(stack) {
		mStack = stack;
	} else {
		mStack = nullptr;
	}
}

void PlusExpress::interpreter() {
	char plus = '+';
	mLeft->interpreter();
	mStack->push_back(plus);
	mRight->interpreter();
}

class SubExpress : public IExpression {
public:
	SubExpress(IExpression *left, IExpression *right);
	void setStack(std::vector<char> *stack);
	virtual ~SubExpress();

	virtual void interpreter(void);

private:
	IExpression *mLeft;
	IExpression *mRight;
	std::vector<char> *mStack;
};

SubExpress::SubExpress(IExpression *left, IExpression *right)
	: mLeft(left), mRight(right) {
}

SubExpress::~SubExpress() {
}

void SubExpress::setStack(std::vector<char> *stack) {
	if (stack)
	{
		mStack = stack;
	} else {
		mStack = nullptr;
	}
}

void SubExpress::interpreter() {
	char sub = '-';
	mLeft->interpreter();
	mStack->push_back(sub);
	mRight->interpreter();
}

class NumberExpress : public IExpression {
public:
	NumberExpress(const int i);
	~NumberExpress();
	void setStack(std::vector<char> *stack);

	virtual void interpreter(void);

private:
	int mInt;
	std::vector<char> *mStack;
};

NumberExpress::NumberExpress(int i) : mInt(i) {
}

NumberExpress::~NumberExpress() {
}

void NumberExpress::setStack(std::vector<char> *stack) {
	if(stack) {
		mStack = stack;
	} else {
		mStack = nullptr;
	}
}

void NumberExpress::interpreter() {
	mStack->push_back(static_cast<char>(mInt));
}

class Parser {
public:
	Parser(const char * const input);
	Parser(const std::string & input);
	~Parser();

	void interpreter_preorder(void);
	void interpreter_postorder(void);

	void parseNextWord(void);

private:
	std::vector<char> mStackInput;
	std::vector<char> mStackOutput;
};

Parser::Parser(const char * const input) {
	int len = strlen(input);

	for(int i = 0 ; i < len ; i++) {
		mStackInput.push_back(input[i]);
	}

	mStackOutput.resize(len);
}

Parser::Parser(const std::string &input) {
	for(int i = 0 ; i < input.size() ; i++) {
		mStackInput.push_back(input.c_str()[i]);
	}

	mStackOutput.resize(mStackInput.size());
}

Parser::~Parser(void) {
}

void Parser::interpreter_preorder() {
	char input = mStackInput.back();
	mStackInput.pop_back();
}

void Parser::parseNextWord() {

}

int main(int argc, char **argv) {
	std::string a("hello world");	
	Parser reader(a);

	return 0;
}