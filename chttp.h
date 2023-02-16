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
#include <curl/curl.h>

// HTTP Method Enum
typedef enum {
    GET,
    POST
} chttp_method;

// Definition of a http response
typedef struct chttp_response_s {
    size_t size;
    char *data;
} chttp_response;

// http methoods
int chttp_download(char *url, char *data, chttp_method method, char *filename, curl_off_t *current, curl_off_t *total,
                   volatile uint8_t *cancellation);

chttp_response *
chttp_fetch(char *url, struct curl_slist *headers, char *postData, chttp_method method, long ignoreHeaders);

void chttp_free(chttp_response *response);

char *chttp_escapeURL(char *url);

char *chttp_unescapeURL(char *url);

void chttp_freeURL(char *url);

#endif
