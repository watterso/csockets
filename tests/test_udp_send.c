#include "../csockets.h"

int main(int argc, char** argv){
  int ret  = send_raw("hola", 4, "127.0.0.1", 54269);  
  printf("sent %d bytes\n", ret);
}
