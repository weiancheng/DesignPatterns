#!/usr/bin/python3


class IMessage(object):
    def update(self):
        raise NotImplemented


class Line(IMessage):
    def __init__(self, user):
        self.__user = user

    def update(self):
        print("Line: " + self.__user + " got a message.")


class FBMessage(IMessage):
    def __init__(self, user):
        self.__user = user

    def update(self):
        print("Facebook Message: " + self.__user + " got a message.")


class MessageServer(object):
    def __init__(self):
        self.__client_list = []

    def attach(self, client):
        self.__client_list.append(client)

    def detach(self, client):
        for user in self.__client_list:
            if user == client:
                self.__client_list.remove(user)

    def notify(self):
        for client in self.__client_list:
            client.update()


def main():
    jack = Line("Jack")
    amy = FBMessage("Amy")

    server = MessageServer()
    server.attach(jack)
    server.attach(amy)

    server.notify()

    server.detach(jack)

    server.notify()

if __name__ == '__main__':
    main()
