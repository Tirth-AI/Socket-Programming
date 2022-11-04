# from curses.ascii import isdigit
import socket
import re

s = socket.socket()
print('Socket created')

s.bind(('localhost',9999))

s.listen(3)
print('Waiting for connections')

while True:
    c, addr = s.accept()
    message = c.recv(1024).decode()
    print('Connected with ', addr)    
    print('Message received', message)
    
    isAlpha = bool(re.search("^[a-zA-Z]+$", message))
    isAlphaNum = bool(re.search("\w", message))    
    isDigit = bool(re.search("^\d+$", message))    
    isFloat = bool(re.search("^-?[0-9]+.[0-9]+$", message))    
    isWhiteSpace = bool(re.search("\s", message))    
    
    if(isAlpha):
        print('It is alpha')
        
    elif(isDigit):
        print('It is numberic')  
        
    elif(isFloat):
        print('It is a float nunber')

    elif(isAlphaNum and not isDigit):
        print('It is alphanumeric')
        
    elif(isWhiteSpace):
        print('It is WhiteSpace')
        
    else:
        print('It is special character')   
       
    c.send(bytes('Welcome!','utf-8'))
    c.close()