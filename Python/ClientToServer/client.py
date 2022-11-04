import socket

c = socket.socket()

c.connect(('localhost',9999))

message = input('Enter the text: ')

c.send(bytes(message,'utf-8'))
print(c.recv(1024).decode())