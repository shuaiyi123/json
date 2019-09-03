/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-27 23:15:58
 * @LastEditTime: 2019-09-03 02:17:05
 * @LastEditors: Please set LastEditors
 */
#include <semaphore.h>

#include "gshm.h"
#include "ghead.h"
#include "devcfg.h"
#include "cjson_op.h"
/**
 * @description: 创建共享内存
 * @param {type} 
 * @return: 返回文件描述符
 */
int createShm()
{
    int shmfd;
    //创建shmjson
    shmfd = shm_open(SHM_JSON, O_RDWR, 0666);
    if (-1 == shmfd)
    {
        logMsg(logErr,"%s open failed:",SHM_JSON);
        return -1;
    }
    //设置shmjson大小
    if (-1 == ftruncate(shmfd, sizeof(TOTALSTRU)))
    {
        logMsg(logErr,"%s ftruncate failed.\n",SHM_JSON);
        return -1;
    }
    //映射shmjson
    tol = (TOTALSTRU *)mmap(NULL, sizeof(TOTALSTRU), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (MAP_FAILED == tol)
    {
        logMsg(logErr,"%s mmap failed.\n",SHM_JSON);
        return -1;
    }
    return shmfd;
}
/**
 * @description: 创建有名信号量
 * @param {type} 
 * @return: 信号标识符
 */
sem_t *createSem(const char *semName,int value)
{
    int val;
    sem_t *semId;
    semId=sem_open(semName,O_RDWR);
    if (semId == SEM_FAILED)
    {
        logMsg(logErr,"%s open error!\n",semName);
        return SEM_FAILED;
    }
    sem_getvalue(semId,&val);
    logMsg(logInfo,"currently shared-memory sem value is :%d\n",val);
    return semId;
}

