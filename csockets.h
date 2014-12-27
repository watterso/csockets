#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define MAX_RECEIVE 2048

int send_raw(char * buffer, int size, char * ip, int port);
int sock_send_raw(struct sockaddr_in remote, char * buffer, int size);
int sock_tcp_fd(struct sockaddr_in remote);
int tcp_fd(char * ip, int port);
void tcp_listen(int port, int conn_queue_size, int (*loop_condition)(), void (*handle_conn)(int, struct sockaddr_in*));
void udp_listen(int port, int (*loop_condition)(), void (*handle_packet)(char*, int, int, struct sockaddr_in*,
                  struct sockaddr_in*));
