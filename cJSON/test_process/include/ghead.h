/*
 * @Author: Yangxl
 * @LastEditors: Please set LastEditors
 * @Description: 涉及操作系统、数据类型、数据结构的头文件列表 供各个模块调用
 * @Date: 2019-04-10 16:41:28
 * @LastEditTime: 2019-08-30 02:31:51
 */

#ifndef ghead__h
#define ghead__h

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "gtypedef.h"
#include "gdefine.h"
#include "gstruct.h"
#include "syslog.h"

#ifdef __cplusplus
}
#endif

#endif
