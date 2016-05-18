#include <iostream>
#include <list>
#include <cstring>
#include <cctype>

class IExpression {
public:
	IExpression(void);
	virtual ~IExpression();

	virtual void interpreter(void) = 0;
};

IExpression::IExpression() {
}

IExpression::~IExpression() {
}

class UpExpression : public IExpression {
public:
	UpExpression(std::string &output);
	~UpExpression(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

UpExpression::UpExpression(std::string &output) : mOutput(output) {
}

UpExpression::~UpExpression() {
}

void UpExpression::interpreter() {
	mOutput.append("8");
}

class DownExpress : public IExpression {
public:
	DownExpress(std::string &output);
	~DownExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

DownExpress::DownExpress(std::string &output) : mOutput(output) {
}

DownExpress::~DownExpress() {}

void DownExpress::interpreter() {
	mOutput.append("2");
}

class LeftExpress : public IExpression {
public:
	LeftExpress(std::string &output);
	~LeftExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

LeftExpress::LeftExpress(std::string &output) : mOutput(output) {
}

LeftExpress::~LeftExpress() {}

void LeftExpress::interpreter() {
	mOutput.append("4");
}

class RightExpress : public IExpression {
public:
	RightExpress(std::string &output);
	~RightExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

RightExpress::RightExpress(std::string &output) : mOutput(output) {
}

RightExpress::~RightExpress() {}

void RightExpress::interpreter() {
	mOutput.append("6");
}

class AExpress : public IExpression {
public:
	AExpress(std::string &output);
	~AExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

AExpress::AExpress(std::string &output) : mOutput(output) {
}

AExpress::~AExpress() {
}

void AExpress::interpreter() {
	mOutput.append("a");
}

class BExpress : public IExpression {
public:
	BExpress(std::string &output);
	~BExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

BExpress::BExpress(std::string &output) : mOutput(output) {
}

BExpress::~BExpress() {}

void BExpress::interpreter() {
	mOutput.append("b");
}

class CExpress : public IExpression {
public:
	CExpress(std::string &output);
	~CExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

CExpress::CExpress(std::string &output) : mOutput(output) {
}

CExpress::~CExpress() {}

void CExpress::interpreter() {
	mOutput.append("c");
}

class DExpress : public IExpression {
public:
	DExpress(std::string &output);
	~DExpress(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
};

DExpress::DExpress(std::string &output) : mOutput(output) {
}

DExpress::~DExpress() {}

void DExpress::interpreter() {
	mOutput.append("d");
}

class CommandExpression : public IExpression {
public:
	CommandExpression(std::list<std::string> &cmd_list, std::string &output);
	~CommandExpression(void);

	virtual void interpreter(void);

private:
	std::string &mOutput;
	std::list<std::string> &mList;
	IExpression *mUp;
	IExpression *mDown;
	IExpression *mRight;
	IExpression *mLeft;
	IExpression *mA;
	IExpression *mB;
	IExpression *mC;
	IExpression *mD;
};

CommandExpression::CommandExpression(std::list<std::string> &cmd_list, std::string &output)
	: mList(cmd_list), mOutput(output) {
	mUp = new UpExpression(mOutput);
	mDown = new DownExpress(mOutput);
	mRight = new RightExpress(mOutput);
	mLeft = new LeftExpress(mOutput);
	mA = new AExpress(mOutput);
	mB = new BExpress(mOutput);
	mC = new CExpress(mOutput);
	mD = new DExpress(mOutput);
}

CommandExpression::~CommandExpression() {
	if (mUp)
		delete mUp;

	if(mDown)
		delete mDown;

	if(mRight)
		delete mRight;
	if(mLeft)
		delete mLeft;

	if(mA)
		delete mA;

	if(mB)
		delete mB;

	if(mC)
		delete mC;

	if(mD)
		delete mD;
}

void CommandExpression::interpreter() {
	std::string getcmd;

	for(std::list<std::string>::iterator it = mList.begin() ; it != mList.end() ; it++) {
		getcmd = *it;
		if (getcmd.compare("UP") == 0) {
			mUp->interpreter();
		} else if (getcmd.compare("DOWN") == 0) {
			mDown->interpreter();
		} else if (getcmd.compare("RIGHT") == 0) {
			mRight->interpreter();
		} else if (getcmd.compare("LEFT") == 0) {
			mLeft->interpreter();
		} else if(getcmd.compare("A") == 0) {
			mA->interpreter();
		} else if(getcmd.compare("B") == 0) {
			mB->interpreter();
		} else if(getcmd.compare("C") == 0) {
			mC->interpreter();
		} else if(getcmd.compare("D") == 0) {
			mD->interpreter();
		}
	}
}

class Parser {
public:
	Parser(const char * const input);
	Parser(std::string &input);
	~Parser(void);

	void start(void);
	std::string skill_table(void);
	void getCommand(std::string &input);

private:
	std::list<std::string> mStackInput;
	std::string mOutput;
	IExpression *mExpress;
};

Parser::Parser(const char * const input) : mOutput(""), mExpress(new CommandExpression(mStackInput, mOutput)) {
	std::string sinput(input);
	getCommand(sinput);
}

Parser::Parser(std::string &input) : mOutput(""), mExpress(new CommandExpression(mStackInput, mOutput)) {
	getCommand(input);
}

void Parser::getCommand(std::string &str_input) {
	int begin = 0;
	int i = 0;
	int len = 0;

	for(i = 0 ; i < str_input.size() ; i++) {
		if(std::isspace(str_input.c_str()[i])) {
			if(len)
				len = i - begin;
			else
				len = i;
			if(len)
				mStackInput.push_back(str_input.substr(begin, len));
			begin = i + 1;
		}
	}

	if(begin != i) {
		mStackInput.push_back(str_input.substr(begin, i));
	}
}

Parser::~Parser() {
	if(mExpress)
		delete mExpress;
}

void Parser::start() {
	if(mStackInput.size() == 0)
		return;

	mExpress->interpreter();
}

std::string Parser::skill_table() {
	std::string output;
	if(mOutput.compare("426426b") == 0) {
		output = std::string("ultimate power");
	}
	else if(mOutput.compare("426a") == 0)
		output = std::string("hadokan");

	mOutput.clear();
	mStackInput.clear();

	return output;
}

int main(int argc, char **argv) {
	Parser parser("LEFT DOWN RIGHT A");

	parser.start();

	std::cout << parser.skill_table() << std::endl;
	std::string cmd("LEFT DOWN RIGHT LEFT DOWN RIGHT B");
	
	parser.getCommand(cmd);
	parser.start();
	std::cout << parser.skill_table() << std::endl;

	return 0;
}