all: udp tcp
udp:
	gcc -o test_udp_send test_udp_send.c ../send_raw.c
	gcc -o test_udp_listen test_udp_listen.c ../udp_listen.c

tcp:
	gcc -o test_tcp_send test_tcp_send.c ../tcp_fd.c
	gcc -o test_tcp_listen test_tcp_listen.c ../tcp_listen.c
clean:
	rm -rf test_*_send
	rm -rf test_*_listen
