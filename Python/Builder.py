#!/usr/bin/python3


class WebServer(object):
	def __init__(self, ip, port):
		self.__ip = ip
		self.__port = port
		self.__max_client = 1
		self.__max_process = 1
		self.isRunning = False

	def setMaxClientNum(self, client_num):
		if client_num < 1:
			client_num = 1
		self.__max_client = client_num

	def setMaxProcessNum(self, process_num):
		if process_num < 1:
			process_num = 1
		self.__max_process = process_num

	def initServer(self):
		print("initial Web Server ( " + self.__ip + " : " + str(self.__port) + " )")

	def startServer(self):
		if not self.isRunning:
			print("start Web Server...")
			self.isRunning = True
		else:
			print("Web Server has already been running...")

	def stopServer(self):
		if self.isRunning:
			print("stop Web Server...")
			self.isRunning = False
		else:
			print("Web Server has already been stopped...")


class ServerBuilder:
	def __init__(self):
		self.__builder_ip = "127.0.0.1"
		self.__builder_port = 9527
		self.__builder_max_client = 100
		self.__builder_max_process = 100

	def setIP(self, ip):
		self.__builder_ip = ip

	def setPort(self, port):
		self.__builder_port = port

	def setClientNum(self, num):
		if num < 1:
			num = 1
		self.__builder_max_client = num

	def setProcessNum(self, num):
		if num < 1:
			num = 1
		self.__builder_max_process = num

	def BuildServer(self):
		server = WebServer(self.__builder_ip, self.__builder_port)
		server.setMaxClientNum(self.__builder_max_client)
		server.setMaxProcessNum(self.__builder_max_process)
		return server


def main():
	server_builder = ServerBuilder()
	server_builder.setIP("192.168.0.1")
	server_builder.setPort(8888)
	server_builder.setClientNum(20)
	server_builder.setProcessNum(20)

	server = server_builder.BuildServer()
	server.initServer()
	server.startServer()
	print("executing for 10 hours later...")
	server.stopServer()

if __name__ == '__main__':
	main()
