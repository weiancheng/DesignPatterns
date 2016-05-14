#include <iostream>
#include <vector>

class VoiceMessage;
class TextMessage;

class INetwork {
public:
    INetwork(void) {}
    virtual ~INetwork() {}

    virtual void sendMsg(VoiceMessage * voice) = 0;
    virtual void sendMsg(TextMessage * text) = 0;
};

class IMessage {
public:
    IMessage(std::string msg) : mMessage(msg) {}
    virtual ~IMessage() {}

    virtual void accept(INetwork * net) = 0;
    virtual std::string getMsg(void) = 0;

protected:
    std::string mMessage;
};

class TextMessage : public IMessage {
public:
    TextMessage(std::string msg);
    ~TextMessage();

    virtual void accept(INetwork * net);
    virtual std::string getMsg(void);
};

class VoiceMessage : public IMessage {
public:
    VoiceMessage(std::string msg);
    ~VoiceMessage();

    virtual void accept(INetwork * net);
    virtual std::string getMsg(void);
};

TextMessage::TextMessage(std::string msg) : IMessage(msg)
{}

TextMessage::~TextMessage() {}

void TextMessage::accept(INetwork * net) {
    net->sendMsg(this);
}

std::string TextMessage::getMsg(void) {
    return mMessage;
}

VoiceMessage::VoiceMessage(std::string msg) : IMessage(msg) {}

VoiceMessage::~VoiceMessage() {}

void VoiceMessage::accept(INetwork * net) {
    net->sendMsg(this);
}

std::string VoiceMessage::getMsg(void) {
    return mMessage;
}

class LineNetwork {
public:
    LineNetwork(void) {}
    ~LineNetwork() {}

    virtual void sendMsg(VoiceMessage * voice) {
        std::cout << "Line ~~~" << std::endl;
        std::cout << "Voice Message: " << voice->getMsg() << std::endl;
    }

    virtual void sendMsg(TextMessage * text) {
        std::cout << "Line ~~~" << std::endl;
        std::cout << "Text Message: " << text->getMsg() << std::endl;
    }
};

class FBNetwork : public INetwork {
public:
    FBNetwork(void) {}
    ~FBNetwork() {}

    virtual void sendMsg(VoiceMessage *voice) {
        std::cout << "Facebook" << std::endl;
        std::cout << "Voice Message: " << voice->getMsg() << std::endl;
    }

    virtual void sendMsg(TextMessage * text) {
        std::cout << "Facebook" << std::endl;
        std::cout << "Text Message: " << text->getMsg() << std::endl;
    }
};

class MessageTool {
public:
    MessageTool() {}
    ~MessageTool() {}

    void addMsg(IMessage * msg) {
        messages.push_back(msg);
    }

    void removeMsg(int index) {
        messages.erase(messages.begin() + index);
    }

    void doSendMsg(INetwork * network) {
        for(int i = 0 ; i < messages.size() ; i++) {
            messages[i]->accept(network);
        }
    }

private:
    std::vector<IMessage *> messages;
};

int main(int argc, char **argv) {
    IMessage * vmsg = new VoiceMessage("hi hi");
    IMessage * tmsg = new TextMessage("Hello World");
    INetwork * fbn = new FBNetwork();

    MessageTool tool;

    tool.addMsg(vmsg);
    tool.addMsg(tmsg);
    tool.doSendMsg(fbn);

    delete vmsg;
    delete tmsg;
    delete fbn;

    return 0;
}
