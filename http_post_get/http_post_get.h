#ifndef _HTTP_POST_GET_H_
#define _HTTP_POST_GET_H_

#include <stdio.h>
#include <string.h>

typedef enum {
    JSON,
} content_type;


/**
 * @brief Generate post form from parameters
 * @param path 
 * @param host 
 * @param content_type
 * @param message
 */
int http_post(char *buffer, char *path, char* host, content_type type, char *message);

/**
 * @brief Generate get from from parameters
 * @param path
 * @param host
 * @param type
 */
int http_get(char *buffer, char *path, char* host, content_type type);



#endif //_HTTP_POST_GET_H_ 