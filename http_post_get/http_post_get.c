#include <sys/socket.h>
#include "http_post_get.h"



int http_post(char *buffer, char *path, char* host, content_type type, char *message)
{
    int ret;
    char *app_type;

    switch (type)
    {
        case JSON:
            app_type = "application/json";
            break;
    
        default:
            break;
    }

    ret = sprintf(buffer, "POST %s HTTP/1.1\r\n"
                          "Host: %s\r\n"
                          "Content-Type: %s\r\n"
                          "Content-Length: %ld\r\n\r\n"
                          "%s", path, host, app_type, strlen(message), message);
    if (ret < 0) {
        return -1;
    }
}

int http_get(char *buffer, char *path, char* host, content_type type)
{
    int ret;
    char *app_type;

    switch (type) 
    {
        case JSON:
            app_type = "application/json";
            break;
        
        default:
            break;
    }

    ret = sprintf(buffer, "GET %s HTTP/1.1\r\n"
                          "Host: %s\r\n"
                          "Content-Type: %s\r\n\r\n", path, host, app_type);
    if (ret < 0) {
        return 0;
    } 
}
