#include "csockets.h"

int tcp_fd(char * ip, int port){
  struct sockaddr_in remote;
  remote.sin_family = AF_INET;
  remote.sin_addr.s_addr = inet_addr(ip);
  remote.sin_port = htons(port);
  return sock_tcp_fd(remote);
}

int sock_tcp_fd(struct sockaddr_in remote){
  int socket_fd;

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    //TODO output to stderr
    printf("Failed to create socket fd:\n\tERROR %d: %s\n", errno, strerror(errno));
    return -1;
  }

  if(connect(socket_fd, (struct sockaddr *)&remote, sizeof(remote)) < 0){
    //TODO output to stderr
    printf("Failed to connect socket:\n\tERROR %d: %s\n", errno, strerror(errno));
    return -1;
  }else{
    return socket_fd;
  }
}
