CC = gcc
OUTPUT = http_request
HTTP_PATH = http_post_get

all: http_request exe_file 

http_request:
	$(CC) -c $(HTTP_PATH)/*.c 

exe_file:
	$(CC) socket_api.c -o run *.o -I$(HTTP_PATH)

clean:
	rm *.o 
	rm run