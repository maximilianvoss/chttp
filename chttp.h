/*
 * Copyright 2021 Maximilian Voss (maximilian@voss.rocks)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _CHTTP_H
#define _CHTTP_H

#include <stdint.h>

// HTTP Method Enum
typedef enum {
    GET,
    POST
} httpmethod_t;

// Definition of a http response
typedef struct http_response_s {
    size_t size;
    char *data;
} http_response_t;

// http methoods
int http_download(char *url, char *data, httpmethod_t method, char *filename, curl_off_t *current, curl_off_t *total,
                  volatile uint8_t *cancellation);

http_response_t *http_fetch(char *url, char *postData, httpmethod_t method, long ignoreHeaders);

void http_freeResponse(http_response_t *response);

#endif
