/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-27 06:25:20
 * @LastEditTime: 2019-08-27 23:35:28
 * @LastEditors: Please set LastEditors
 */
#ifndef cjson_op__h
#define cjson_op__h

#ifdef __cplusplus
extern "C"
{
#endif

#include "cJSON.h"

    char *openJsonFile(char *file);
    long saveJsonFile(cJSON *json, char *fileName);

#ifdef __cplusplus
}
#endif

#endif
