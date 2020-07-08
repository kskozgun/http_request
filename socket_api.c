#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "http_post_get.h"

#define SIZEOF_BUFFER 100
#define SIZEOF_RECEIVE_BUFFER 200

int main()
{
    int ret;
    int i = 0;
    /* Socket Data */
    int socket_api;
    struct sockaddr_in server;

    /* Post Data */
    content_type type = JSON;
    char *host = "176.31.101.33:5001";
    char *path = "/api/data/AddVeri";
    char *tx_message = "{\"s\":1,\"1\":22.44,\"2\":19.12}";
    unsigned char data[5] = {1,1,25,2,30};

    /* TX and RX Buffer */
    char http_message[SIZEOF_BUFFER];
    unsigned char receive_buffer[SIZEOF_RECEIVE_BUFFER];

    /* IP4 , TCP based 
    socket_api = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_api < 0) {
        printf("error no is %d\n",socket_api);
        return socket_api;
    }*/

    /* Server Configuration */
    server.sin_family = AF_INET;
    server.sin_port = htons(5005);
    server.sin_addr.s_addr = inet_addr("176.31.101.33");    

    /* IP4 , TCP based */
    socket_api = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_api < 0) {
        printf("error no is %d\n",socket_api);
        return socket_api;
    }

    /* Connect Server */
    ret = connect(socket_api, (struct sockaddr *)&server, sizeof(server));
    if(ret < 0) {
        printf("Connection Error!\n");
    }

    /* Generate post form */ 
    ret = http_post(http_message, path, host, type, tx_message);
    if( ret < 0) {
        return ret;
    }
    
    /* Generate get form */
    //ret = http_get(http_message, path, host, type);
    //if ( ret < 0) {
    //    return -1;
    //}

    //printf("%s\n", http_message); 

    /* Send data to server */
    ret = send(socket_api, http_message, sizeof(http_message), 0);
    if (ret < 0) {
        printf("Send Error!\n");
    }
    printf("I am here\n");
    /* Receive data from server */
    ret = recv(socket_api, receive_buffer , sizeof(receive_buffer) , 0);
    if ( ret < 0){
        printf("Receive Error!\n");
	}
    printf("%d\n", receive_buffer[0]);
    
    /* Close socket */
    close(socket_api); 

    return 0;
}
