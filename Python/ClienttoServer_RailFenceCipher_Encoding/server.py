import socket
from cipherDecrypt import railFenceCipherDecrypt

s = socket.socket()

print('Socket created')

s.bind(('localhost',9999))

s.listen(3)
print('Waiting for connections')

while True:
    c, addr = s.accept()
    name = c.recv(1024).decode()
    print("Message Received: ", name)
    key = int(input('Enter the key: '))
    decryptedText = railFenceCipherDecrypt(name, key)
    print('Decrypted Text: ',decryptedText)
    c.close()
    
