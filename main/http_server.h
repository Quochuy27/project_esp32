#ifndef __HTTP_SERVER_H
#define __HTTP_SERVER_H
#include <stdint.h>
typedef void (*http_post_callback_t) (char* data, int len );
typedef void (*http_get_callback_t) (void);
void start_webserver(void);
void stop_webserver(void);
void http_set_callback_switch(void *cb);
void http_set_callback_dht11(void *cb);
void dht11_response(char *data, int len);
#endif