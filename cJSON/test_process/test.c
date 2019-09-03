/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-01 18:36:16
 * @LastEditTime: 2019-09-03 02:34:57
 * @LastEditors: Please set LastEditors
 */
#include <semaphore.h>
#include "ghead.h"
#include "devcfg.h"
#include "gshm.h"
#include "cjson_op.h"

static int do_abort = 0;
void funSIGINT(int signo);
int main(int argc, char *argv[])
{
    int shmfd;
    sem_t *semId;
    sem_t *devId;
    sem_t *verId;
    sem_t *mfrId;
    sem_t *ycId;
    sem_t *yxId;
    sem_t *ykId;
    sem_t *comId;
    sem_t *ethId;
    sem_t *hmiId;
    sem_t *spiId;
    sem_t *sdId;
    sem_t *usbId;
    sem_t *dbgId;
    sem_t *setcfgId;
    sem_t *set1Id;
    sem_t *set2Id;
    sem_t *set3Id;
  
    signal(SIGINT, &funSIGINT);
    //打开共享空间
    shmfd=createShm();
    if(-1==shmfd){
        logMsg(logErr,"created shared-memory failed!");
        exit(-1);
    }
    //打开信号量
    semId=createSem(SEM_GET_JSON,0);
    if(SEM_FAILED==semId){
        logMsg(logErr, "created SEM_GET_JSON error!");
        exit(-1);
    }
    //打开更新json文件信号量
    devId=sem_open(SEM_DEVCFG_JSON, O_RDWR);
    if (devId == SEM_FAILED){
        logMsg(logErr,"created devId sem failed.");
        exit(-1);
    }
    verId=sem_open(SEM_VER_JSON, O_RDWR);
    if (verId == SEM_FAILED){
        logMsg(logErr,"created verId sem failed.");
        exit(-1);
    }
    mfrId=sem_open(SEM_MFR_JSON, O_RDWR);
    if (mfrId == SEM_FAILED){
        logMsg(logErr,"created mfrId sem failed.");
        exit(-1);
    } 
    ycId=sem_open(SEM_YC_JSON, O_RDWR);
    if (ycId == SEM_FAILED){
        logMsg(logErr,"created ycId sem failed.");
        exit(-1);
    }
    yxId=sem_open(SEM_YX_JSON, O_RDWR);
    if (yxId == SEM_FAILED){
        logMsg(logErr,"created yxId sem failed.");
        exit(-1);
    }
    ykId=sem_open(SEM_YK_JSON, O_RDWR);
    if (ykId == SEM_FAILED){
        logMsg(logErr,"created ykId sem failed.");
        exit(-1);
    }
    comId=sem_open(SEM_COM_JSON, O_RDWR);
    if (comId == SEM_FAILED){
        logMsg(logErr,"created comId sem failed.");
        exit(-1);
    }
    ethId=sem_open(SEM_ETH_JSON, O_RDWR);
    if (ethId == SEM_FAILED){
        logMsg(logErr,"created ethId sem failed.");
        exit(-1);
    }
    hmiId=sem_open(SEM_HMI_JSON, O_RDWR);
    if (hmiId == SEM_FAILED){
        logMsg(logErr,"created hmiId sem failed.");
        exit(-1);
    }
    spiId=sem_open(SEM_SPI_JSON, O_RDWR);
    if (spiId == SEM_FAILED){
        logMsg(logErr,"created spiId sem failed.");
        exit(-1);
    }
    sdId=sem_open(SEM_SD_JSON, O_RDWR);
    if (sdId == SEM_FAILED){
        logMsg(logErr,"created sdId sem failed.");
        exit(-1);
    }
    usbId=sem_open(SEM_USB_JSON, O_RDWR);
    if (usbId == SEM_FAILED){
        logMsg(logErr,"created usbId sem failed.");
        exit(-1);
    }
    dbgId=sem_open(SEM_DBG_JSON, O_RDWR);
    if (dbgId == SEM_FAILED){
        logMsg(logErr,"created dbgId sem failed.");
        exit(-1);
    }
    setcfgId=sem_open(SEM_SETCFG_JSON,O_RDWR);
    if (setcfgId == SEM_FAILED){
        logMsg(logErr,"created setcfgId sem failed.");
        exit(-1);
    }
    set1Id=sem_open(SEM_SET1_JSON, O_RDWR);
    if (set1Id == SEM_FAILED){
        logMsg(logErr,"created set1Id sem failed.");
        exit(-1);
    }
    set2Id=sem_open(SEM_SET2_JSON, O_RDWR);
    if (set2Id == SEM_FAILED){
        logMsg(logErr,"created set2Id sem failed.");
        exit(-1);
    }
    set3Id=sem_open(SEM_SET3_JSON, O_RDWR);
    if (set3Id == SEM_FAILED){
        logMsg(logErr,"created set3Id sem failed.");
        exit(-1);
    } 

    //等待json文件解析完成
    sem_wait(semId);

    //修改devcfg.josn参数，发送相应的信号量,以同步到json文件
    tol->gtDEV.YC_num=12;
    sem_post(devId);
    //修改yc.json参数，发送相应信号量，以同步到json文件
    tol->gtYC_CHN[0].coe0=0;
    sem_post(ycId);
    //修改com.json参数,发送相应信号量，以同步到json文件
    strncpy(tol->gtCOM_CHN[0].Name,"WIFI001",JSON_FILE_ITEM_LEN);
    sem_post(comId);
    //修改set3.json参数，发送相应信号量，以同步到json文件
    strncpy(tol->gtset3.fv,"1.0.1",JSON_FILE_ITEM_LEN);
    sem_post(set3Id);

    while (!do_abort);
    //取消shmRly映射
    if (-1 == munmap(tol, sizeof(TOTALSTRU)))
    {
        logMsg(logErr,"munmap tol failed:");
        return ERROR;
    }
    //关闭shmRly
     close(shmfd);
     
    // sem_close(semId);//关闭信号量
    // sem_unlink(SEM_GET_JSON);//断开信号量连接
    // sem_close(devId);//关闭信号量
    // sem_unlink(SEM_DEVCFG_JSON);//断开信号量连接
    // sem_close(verId);//关闭信号量
    // sem_unlink(SEM_VER_JSON);//断开信号量连接
    // sem_close(mfrId);//关闭信号量
    // sem_unlink(SEM_MFR_JSON);//断开信号量连接
    // sem_close(ycId);//关闭信号量
    // sem_unlink(SEM_YC_JSON);//断开信号量连接
    // sem_close(yxId);//关闭信号量
    // sem_unlink(SEM_YX_JSON);//断开信号量连接
    // sem_close(ykId);//关闭信号量
    // sem_unlink(SEM_YK_JSON);//断开信号量连接
    // sem_close(comId);//关闭信号量
    // sem_unlink(SEM_COM_JSON);//断开信号量连接
    // sem_close(ethId);//关闭信号量
    // sem_unlink(SEM_ETH_JSON);//断开信号量连接
    // sem_close(hmiId);//关闭信号量
    // sem_unlink(SEM_HMI_JSON);//断开信号量连接
    // sem_close(spiId);//关闭信号量
    // sem_unlink(SEM_SPI_JSON);//断开信号量连接
    // sem_close(sdId);//关闭信号量
    // sem_unlink(SEM_SD_JSON);//断开信号量连接
    // sem_close(usbId);//关闭信号量
    // sem_unlink(SEM_USB_JSON);//断开信号量连接
    // sem_close(dbgId);//关闭信号量
    // sem_unlink(SEM_DBG_JSON);//断开信号量连接
    // sem_close(setcfgId);//关闭信号量
    // sem_unlink(SEM_SETCFG_JSON);//断开信号量连接
    // sem_close(set1Id);//关闭信号量
    // sem_unlink(SEM_SET1_JSON);//断开信号量连接
    // sem_close(set2Id);//关闭信号量
    // sem_unlink(SEM_SET2_JSON);//断开信号量连接
    // sem_close(set3Id);//关闭信号量
    // sem_unlink(SEM_SET3_JSON);//断开信号量连接
}

/**
 * @param {int} 
 * @return: void
 * @Description: 收到"ctrl+c"停止
 */
void funSIGINT(int signo)
{
    logMsg(logFatal,"test.c funSIGINT got a signal %d", signo);
    do_abort = 1;
   // exit(-1);
}
