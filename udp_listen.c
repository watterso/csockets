#include "csockets.h"
void udp_listen(int port, int (*loop_condition)(), void (*handle_packet)(char*, int, int, struct sockaddr_in*,
                  struct sockaddr_in*)){
  struct sockaddr_in local_addr;
  int socket_fd;

  if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
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

  char buffer[MAX_RECEIVE];
  int bytes_received;
  struct sockaddr_in client_addr;
  socklen_t addrlen = sizeof(client_addr);

  while(loop_condition()){
    bytes_received = recvfrom(socket_fd, buffer, MAX_RECEIVE, 0, (struct sockaddr *) &client_addr, &addrlen);
    handle_packet(buffer, bytes_received, socket_fd, &local_addr, &client_addr);
  }
  close(socket_fd);
}
