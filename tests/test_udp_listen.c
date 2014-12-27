#include "../csockets.h"

int loop();
void handle(char * buffer, int size, int sock_fd, struct sockaddr_in* local, struct sockaddr_in* remote);

int should_loop;

int main(int argc, char** argv){
  should_loop = 1;
  udp_listen(54269, loop, handle);
}

int loop(){
  return should_loop;
}

void handle(char * buffer, int size, int sock_fd, struct sockaddr_in* local, struct sockaddr_in* remote){
  should_loop = 0;
  printf("received(%d): %s\n", size, buffer);
}
