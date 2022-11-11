#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "cipher.h"

using namespace std;
#define port 5000

int main()
{
    cout<<"\n******************************************\n";
    cout<<"* Welcome to the Client Side of the Chat *";
    cout<<"\n******************************************\n";
    int nSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (nSocket < 0)
    {
        cout << "Error in creating socket" << endl;
        return 0;
    }

    struct sockaddr_in srv;
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr) <= 0)
    {
        cout << "Invalid Address" << endl;
        return 0;
    }

    int clientSocket = connect(nSocket, (struct sockaddr *)&srv, sizeof(srv));
    if (clientSocket < 0)
    {
        cout << "Error in connecting" << endl;
        return 0;
    }
    while (1)
    {
        char read_buffer[100];
        char message[100];
        char key[10];

        cout << "\nEnter the message: ";
        cin>>message;
        if (strcmp(message, "Exit") == 0)
        {
            cout << "\nExiting\n\n\n" << endl;
            send(nSocket, message, strlen(message), 0);
            break;
        }
        cout<<"Enter the Key: ";
        cin>>key;

        char *send_buffer = encryption(message, key);

        send(nSocket, send_buffer, strlen(send_buffer), 0);
        
        read(nSocket, read_buffer, 100);
        cout << "\n[Server]: " << read_buffer << endl;
       
    }
    close(nSocket);
    return 0;
}