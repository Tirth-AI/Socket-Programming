#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "cipher.h"

using namespace std;
#define port 5000

int main()
{
    cout<<"\n******************************************\n";
    cout<<"* Welcome to the Server Side of the Chat *";
    cout<<"\n******************************************\n";

    struct sockaddr_in srv;
    
    int nSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (nSocket < 0)
    {
        cout << "Error in creating socket" << endl;
        return 0;
    }
    cout << "Socket created" << endl;

    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
    srv.sin_addr.s_addr = INADDR_ANY;

    int nRet = bind(nSocket, (struct sockaddr *)&srv, sizeof(srv));
    if (nRet < 0)
    {
        cout << "Error in binding" << endl;
        return 0;
    }
    cout << "Binded Successfully" << endl;

    nRet = listen(nSocket, 3);
    if (nRet < 0)
    {
        cout << "Error in listening" << endl;
        return 0;
    }
    cout << "Listening" << endl;

    int nLen = sizeof(srv);
    int newSocket = accept(nSocket, (struct sockaddr *)&srv, (socklen_t *)&nLen);
    if (newSocket < 0)
    {
        cout << "Error in accepting" << endl;
        return 0;
    }
    cout << "Accepted" << endl;

    while (1)
    {
        char read_buffer[100];

        if (read(newSocket, read_buffer, 100) < 0)
        {
            cout << "Error in reading" << endl;
            return 0;
        }

        if (strcmp(read_buffer, "Exit") == 0)
        {
            cout << "Closing connection\n\n\n" << endl;
            break;
        }

        cout << "[Client]: " << read_buffer<<endl;

        string key = "";
        cout<<"\nEnter the Key: ";
        cin>>key;
        char *send_buffer = decryption(read_buffer, key);
        send(newSocket, send_buffer, strlen(send_buffer), 0);
        cout << endl;
    }
    close(newSocket);
    shutdown(nSocket, SHUT_RDWR);
    return 0;
}