#include "../csockets.h"

int loop();
void handle(int sock_fd, struct sockaddr_in* remote);

int should_loop;

int main(int argc, char** argv){
  should_loop = 1;
  tcp_listen(54269, 5, loop, handle);
}

int loop(){
  return should_loop;
}

void handle(int sock_fd, struct sockaddr_in* remote){
  char buffer[MAX_RECEIVE];
  int num_read = read(sock_fd, buffer, MAX_RECEIVE);
  should_loop = 0;
  printf("received(%d): %s\n", num_read, buffer);
  close(sock_fd);
}
