#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#define port 13
#define bufsize 512
#define address "172.16.40.1"

int main()
{   
    char buffer[bufsize];
    string str ("Время\n");
    int s, n;
    struct sock saddr; 
    saddr.sin_addr.s_addr = addr(address);//адрес
    saddr.sin_port = htons(port);//порт
    saddr.sin_family = AF_INET; //семейство адресов, с которым взаимодействует сокет
    s = socket(AF_INET, SOCK_DGRAM, 0); //датаграммы передаем со значением протокола 0
    connect(s, (struct sockaddr *)&saddr, sizeof(saddr)); //подклбчаемся к серверу
    sendto(s, message, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(saddr)); //спрашиваем время
    recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); //получаем время
    puts(buffer); //выводим время
    close(s); //закрываемся
}