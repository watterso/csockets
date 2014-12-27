#include "../csockets.h"

int main(int argc, char** argv){
  int fd = tcp_fd("127.0.0.1", 54269);
  int num_wrote = write(fd, "hola", 4);
  printf("sent %d bytes\n", num_wrote);
  close(fd);
}
