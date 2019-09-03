/*
 * @Author: Yangxl
 * @LastEditors: Please set LastEditors
 * @Description: 装置参数相关处理函数声明
 * @Date: 2019-04-02 09:31:31
 * @LastEditTime: 2019-08-30 02:02:21
 */

#ifndef devcfg__h
#define devcfg__h

#ifdef __cplusplus
"C"
{
#endif

#include "cJSON.h"

    int devCfgInit(char *fileName);
    void *verCfgInit(void *fileName);
    void *mfrCfgInit(void *fileName);
    void *ycCfgInit(void *fileName);
    void *yxCfgInit(void *fileName);
    void *ykCfgInit(void *fileName);
    void *comCfgInit(void *fileName);
    void *ethCfgInit(void *fileName);
    void *hmiCfgInit(void *fileName);
    void *spiCfgInit(void *fileName);
    void *sdCfgInit(void *fileName);
    void *usbCfgInit(void *fileName);
    void *dbgCfgInit(void *fileName);
    void *setcfgCfgInit(void *fileName);
    void *set1CfgInit(void *fileName);
    void *set2CfgInit(void *fileName);
    void *set3CfgInit(void *fileName);


    int getDevCfgPara(cJSON * json);
    int getDevCfgVER(cJSON * json);
    int getDevCfgMFR(cJSON * json);
    int getDevCfgYC(cJSON * json);
    int getDevCfgYX(cJSON * json);
    int getDevCfgYK(cJSON * json);
    int getDevCfgCOM(cJSON * json);
    int getDevCfgETH(cJSON * json);
    int getDevCfgHMI(cJSON * json);
    int getDevCfgSPI(cJSON *json);
    int getDevCfgSD(cJSON * json);
    int getDevCfgUSB(cJSON * json);
    int getDevCfgDBG(cJSON * json);
    int getDevCfgSETCFG(cJSON *json);
    int getDevCfgSETN(int s_num,TSET *setN,cJSON *json);
    int getDevCfgItem(cJSON * json, char *ItemName, int *DevNum, char *DevCfgFile);
    int setDevCfgDBG(cJSON * json);
    
    //update jsonFile
    int devcfgJsonUp(char *fileName);
    int verJsonUp(char *fileName);
    int mfrJsonUp(char *fileName);
    int ycJsonUp(char *fileName);
    int yxJsonUp(char *fileName);
    int ykJsonUp(char *fileName);
    int comJsonUp(char *fileName);
    int ethJsonUp(char *fileName);
    int hmiJsonUp(char *fileName);
    int spiJsonUp(char *fileName);
    int sdJsonUp(char *fileName);
    int usbJsonUp(char *fileName);
    int dbgJsonUp(char *fileName);
    int setcfgJsonUp(char *fileName);
    int setnJsonUp(TSET *setN,char *fileName);

#ifdef __cplusplus
}
#endif

#endif