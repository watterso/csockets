#include "csockets.h"

int send_raw(char * buffer, int size, char * ip, int port){
  struct sockaddr_in remote;
  remote.sin_family = AF_INET;
  remote.sin_addr.s_addr = inet_addr(ip);
  remote.sin_port = htons(port);
  return sock_send_raw(remote, buffer, size);
}

int sock_send_raw(struct sockaddr_in remote, char * buffer, int size){
  int socket_fd;
  if((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    //TODO output to stderr
    printf("Failed to create socket fd:\n\tERROR %d: %s\n", errno, strerror(errno));
    return -1; 
  }
  socklen_t addrlen = sizeof(remote);
  if(sendto(socket_fd, buffer, size, 0, (struct sockaddr *)&remote, addrlen) < 0) {
    //TODO output to stderr
    printf("Failed to send packet:\n\tERROR %d: %s\n", errno, strerror(errno));
    return -1; 
  }
  return size;
}
