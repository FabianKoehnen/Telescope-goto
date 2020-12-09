#ifndef __Server_cpp__
#define __Server_cpp__

#include "./TcpServer.h"

TcpServer::TcpServer(){
}

void TcpServer::init(){

    #ifdef _WIN32
        this->initWinsock();
    #endif

    this->createSocket();

    /* Erzeuge die Socketadresse des Servers. */
    memset( &server, 0, sizeof (server));
    /* IPv4-Verbindung */
    server.sin_family = AF_INET;
    /* INADDR_ANY: jede IP-Adresse annehmen */
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    /* Portnummer */
    server.sin_port = htons(PORT);

    /* Erzeuge die Bindung an die Serveradresse
     * (genauer: an einen bestimmten Port). */
    if(bind(sock,(struct sockaddr*)&server, sizeof( server)) < 0)
        error_exit("Kann das Socket nicht \"binden\"");

    /* Teile dem Socket mit, dass Verbindungswünsche
     * von Clients entgegengenommen werden. */
    if(listen(sock, 5) == -1 )
         error_exit("Fehler bei listen");

    printf("Server bereit - wartet auf Anfragen ...\n");
    /* Bearbeite die Verbindungswünsche von Clients
     * in einer Endlosschleife.
     * Der Aufruf von accept() blockiert so lange,
     * bis ein Client Verbindung aufnimmt. */
    len = sizeof(client);
    fd = accept(sock, (struct sockaddr*)&client, &len);
    if (fd < 0)
        error_exit("Fehler bei accept");
    printf("Bearbeite den Client mit der Adresse: %s\n",
        inet_ntoa(client.sin_addr));



}

TcpServer::~TcpServer(){
    #ifdef _WIN32
        closesocket(this->fd);
    #else
        close(this->fd);
    #endif
}

//recv is blocking 
bool TcpServer::available(){
    if (this->fd < 0)
        return false;

    // memset(buffer, 0, RCVBUFSIZE);

    int readBytes = recv(this->fd, this->buffer, RCVBUFSIZE, 0);
    if(readBytes == 0){
        printf("client disconected\n");
        printf("awaiting a new one\n");
        fd = accept(sock, (struct sockaddr*)&client, &len);
        printf("found one");
        memset(buffer, '\0', RCVBUFSIZE);
        return false;
    }else{
        this->isBufferRead = false;
        return true;
    }
}

void TcpServer::write(std::string data){
    send(this->fd, data.c_str(), data.length(), 0);
}

std::string TcpServer::recive(){
    if(this->isBufferRead){
        this->available();
    }
    this->isBufferRead = true;
    return this->buffer;
}

void TcpServer::error_exit(std::string error_message) {

    #ifdef _WIN32
        fprintf(stderr,"%s: %d\n", error_message.c_str(), WSAGetLastError());
    #else
        fprintf(stderr, "%s: %s\n", error_message.c_str(), strerror(errno));
    #endif

    exit(EXIT_FAILURE);
}

void TcpServer::createSocket(){
    this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this->sock < 0)
        error_exit("Fehler beim Anlegen eines Sockets");
}

#ifdef _WIN32
void TcpServer::initWinsock(){
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD (1, 1);
    if (WSAStartup (wVersionRequested, &wsaData) != 0)
        this->error_exit( "Fehler beim Initialisieren von Winsock");
    else
        printf("Winsock initialisiert\n");
}
#endif

#endif