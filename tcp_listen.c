#include "csockets.h"

void tcp_listen(int port, int conn_queue_size, int (*loop_condition)(), void (*handle_conn)(int, struct sockaddr_in*)){
  struct sockaddr_in local_addr;
  int socket_fd;

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    //TODO output to stderr
    printf("Failed to create socket fd:\n\tERROR %d: %s\n", errno, strerror(errno));
    return;
  }

  local_addr.sin_family = AF_INET;
  local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  local_addr.sin_port = htons(port);

  if (bind(socket_fd, (struct sockaddr *)&local_addr, sizeof(local_addr)) < 0) {
    //TODO output to stderr
    printf("Failed to bind socket:\n\tERROR %d: %s\n", errno, strerror(errno));
    return;
  }

  if(listen(socket_fd, conn_queue_size) < 0){
    //TODO output to stderr
    printf("Failed to listen:\n\tERROR %d: %s\n", errno, strerror(errno));
    return;
  } 

  struct sockaddr_in client_addr;
  socklen_t addrlen = sizeof(client_addr);
  while(loop_condition()){
    int new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, &addrlen);
    handle_conn(new_socket, &client_addr);
  }
}
