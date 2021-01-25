#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;




   /* Client_network::Client_network (bool done, short int port){

    

    string ip = "localhost";

    string pseudo;
    cout << "your username :";
    getline(cin, pseudo);

    TcpSocket socket;
    if (socket.connect(ip,port)==Socket::Done)
    {
        cout << "connected to the server" << endl;
        Packet sendPacket;
        sendPacket << pseudo;
        socket.send(sendPacket);
    }else {

        cout << "server DOWN" << endl;
    }
    }*/