import socket
from cipherEncrypt import railFenceCipherEncrypt

c = socket.socket()

c.connect(('localhost',9999))

name = input('Enter your name: ')
key = int(input('Enter the key: '))
encryptedText = railFenceCipherEncrypt(name, key)   
c.send(bytes(encryptedText,'utf-8'))
print(c.recv(1024).decode())