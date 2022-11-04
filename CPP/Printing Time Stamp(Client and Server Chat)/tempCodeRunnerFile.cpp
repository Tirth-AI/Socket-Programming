
        read(newSocket, read_buffer, 1024);
        time_t t1 = time(NULL);
        char *receivalTime = substr(ctime(&t1), 11, 19);
        char *clientSentTime = substr(read_buffer, 0, 8);

        char *receivedMessage = substr(read_buffer, 8, strlen(read_buffer));