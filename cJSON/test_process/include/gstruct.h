/*
 * @Author: Yangxl
 * @LastEditors: Please set LastEditors
 * @Description: 全局变量的结构定义
 * @Date: 2019-03-29 14:18:19
 * @LastEditTime: 2019-09-01 23:40:08
 */

#ifndef gstruct__h
#define gstruct__h

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include "gdefine.h"
#include "gtypedef.h"

#define JSON_FILE_NAME_LEN 20
#define JSON_FILE_ITEM_LEN 20

    // logMsg信息级别
    enum
    {
        logInfo = 0,
        logWarn,
        logErr,
        logFatal
    };

    // 设备配置
    typedef struct tagDEV
    {
        char fv[20];
        int YC_num;                       //遥测
        int YX_num;                       //遥信
        int YK_num;                       //遥控
        int COM_num;                      //串口
        int ETH_num;                      //以太网
        int HMI_num;                      //人机
        int SPI_num;                      //SPI
        int SD_num;                       //SD卡
        int USB_num;                      //USB
        //int I2C_num;                      //I2C
        int PCIE_num;                     //PCIE
        int HWB_num;                      //IRIG-B码
        int VER_num;                      //版本信息
        int MFR_num;                      //生产信息
        int DBG_num;                      //调试
        int SET1_num;                     //set1控制字、定值、压板
        int SET2_num;                     //set2控制字、定值、压板
        int SET3_num;                     //set3控制字、定值、压板
        int SETCFG_num;                   //setcfg
        char YC_file[JSON_FILE_NAME_LEN]; //YC配置文件名称
        char YX_file[JSON_FILE_NAME_LEN];
        char YK_file[JSON_FILE_NAME_LEN];
        char COM_file[JSON_FILE_NAME_LEN];
        char ETH_file[JSON_FILE_NAME_LEN];
        char HMI_file[JSON_FILE_NAME_LEN];
        char SPI_file[JSON_FILE_NAME_LEN];
        char SD_file[JSON_FILE_NAME_LEN];
        char USB_file[JSON_FILE_NAME_LEN];
        //char I2C_file[JSON_FILE_NAME_LEN];
        char PCIE_file[JSON_FILE_NAME_LEN];
        char HWB_file[JSON_FILE_NAME_LEN];
        char VER_file[JSON_FILE_NAME_LEN];
        char MFR_file[JSON_FILE_NAME_LEN];
        char DBG_file[JSON_FILE_NAME_LEN];
        char SET1_file[JSON_FILE_NAME_LEN];
        char SET2_file[JSON_FILE_NAME_LEN];
        char SET3_file[JSON_FILE_NAME_LEN];
        char SETCFG_file[JSON_FILE_NAME_LEN];
    } TDEV;
    //extern TDEV *gtDEV;

    // 版本信息
    typedef struct tagVER
    {
        char fv[JSON_FILE_ITEM_LEN];    //配置文件版本号
        char hv[JSON_FILE_ITEM_LEN];    //硬件版本
        char sv[JSON_FILE_ITEM_LEN];    //软件版本
        char svOld[JSON_FILE_ITEM_LEN]; //软件上一版本
    } TVER;
   // extern TVER *gtVER;

    // 生产信息
    typedef struct tagMFR
    {
        char fv[JSON_FILE_ITEM_LEN];    //配置文件版本号
        char type1[JSON_FILE_ITEM_LEN]; //产品标志1
        char type2[JSON_FILE_ITEM_LEN]; //产品标志2
        char mfr[JSON_FILE_ITEM_LEN];   //生产厂家
        char id[JSON_FILE_ITEM_LEN];    //装置ID
        char date[JSON_FILE_ITEM_LEN];
    } TMFR;
    //extern TMFR *gtMFR;

    // 遥测模块
    typedef struct tagYC
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //遥测板类型
        int num;                     //数量
        int kg;
       // int flag;                    //附带标志
    } TYC;
   // extern TYC *gtYC;

    // 遥测通道
    typedef struct tagYC_CHN
    {
        char Name[JSON_FILE_NAME_LEN]; //名称
        char Type[JSON_FILE_NAME_LEN ];  //单位
        int idx0;      //序号0
        int idx1;      //序号1
        int k0;        //比例系数0
        int k1;        //比例系数1
        int coe0;      //增益系数0
        int coe1;      //增益系数1
        int flag;      //附带标志
    } TYC_CHN;
    //extern TYC_CHN *gtYC_CHN;

    // 遥信模块
    typedef struct tagYX
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //遥测板类型
        int num;                     //数量
        int kg;                      //控制字
       // int flag;                    //附带标志
    } TYX;
    //extern TYX *gtYX;

    // 遥信通道
    typedef struct tagYX_CHN
    {
        char Name[JSON_FILE_NAME_LEN];  //名称
        int filterTime; //去抖时间
        int flag;       //附带标志
    } TYX_CHN;
   // extern TYX_CHN *gtYX_CHN;

    // 遥控模块
    typedef struct tagYK
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //遥控板类型
        int num;                     //数量
        int kg;                      //控制字
     //   int flag;                    //附带标志
    } TYK;
   // extern TYK *gtYK;

    // 遥控通道
    typedef struct tagYK_CHN
    {
        char Name[JSON_FILE_NAME_LEN]; //名称
        int keepTime;  //合保持时间
        int resetTime; //复归时间
        int flag;      //附带标志
    } TYK_CHN;
    //extern TYK_CHN *gtYK_CHN;

    // 串口模块
    typedef struct tagCOM
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //串口类型
        int num;                     //数量
        int kg;                      //控制字
    //    int flag;                    //附带标志
    } TCOM;
    //extern TCOM *gtCOM;

    //串口号信息
    typedef struct tagCOM_CHN
    {
        char Name[JSON_FILE_NAME_LEN]; //名称
        int  mode;    //串口模式
        ushort  addr;     //串口通信地址
        uint baudRate; //波特率
        uchar dataLen; //数据位
        uchar stopLen;  //停止位
        uchar parity; //校验
    } TCOM_CHN;
   // extern TCOM_CHN *gtCOM_CHN;

    // 以太网规约
    typedef struct tagPROT
    {
        
        char protName[20];
        ushort driverId;
        ushort addr;
        ushort cs;
        ushort tcpUdp;
        ushort portL;
        ushort portR;
        char ip[20];
        char mask[20];
        char gateIP[20];
        char routeIp[20];
        char routeMask[20];
        char mac[20];
    } PROT;
    //以太网模块
    typedef struct tagETH
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //以太网类型
        int num;                     //以太网个数
        int kg ;                     //控制字
        char name[20];               //以太网名称
        PROT prot[3] ;                //iec101规约、iec103规约、modubus规约
    }TETH;
    //extern TETH *gtETH;
    // 人机模块
    typedef struct tagHMI
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;
        int num;
        char led1Name[20];
        int  led1KeepTime;
        char led2Name[20];
        int  led2KeepTime;
        char led3Name[20];
        int  led3KeepTime;
        char lcdName[20];
        int  lcdType;
    } THMI;
    //extern THMI *gtHMI;

    // SPI模块
    typedef struct tagSPI
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                    //SPI类型
        int num;                     //数量
        int kg;                      //控制字
        char Name[20];               //名称
        int mode;                    //模式
    } TSPI;
   // extern TSPI *gtSPI;

    // SD模块
    typedef struct tagSD
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                   //SD类型
        int num;                     //SD数量
        int kg;                      //控制字
        char Name[20];               //名称
        int mode;                    //模式
    } TSD;
   // extern TSD *gtSD;

    // USB模块
    typedef struct tagUSB
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                   //SD类型
        int num;                     //SD数量
        int kg;                      //控制字
        char Name[20];               //名称
        char dir[24];                //usb挂载目录
        int mode;                    //模式
    } TUSB;
   // extern TUSB *gtUSB;

    // DEBUG模块
    typedef struct tagDBG
    {
        char fv[JSON_FILE_ITEM_LEN]; //配置文件版本号
        int type;                   //SD类型
        int num;                    //SD数量
        int kg;                     //控制字
        int Level1;                 //调试等级
        int Level2;
        int Level3;
    } TDBG;
    // extern TDBG *gtDBG;

    //SET文件
    typedef struct tagSET
    {
        char fv[JSON_FILE_NAME_LEN]; //配置文件版本号
        int num;
        int zone;   //区域
        int kg[5];  //控制字
        int dzUmk[3]; //定值umk
        int dzTmk[3]; //定值tmk
        int yb_SL;   //压板
        int yb_TRIP; //压板触发
        int sysUmk[3]; //系统umk
        int sysTmk[3]; //系统tmk
    }TSET;

    //SETCFG文件
    typedef struct tagSETCFG
    {
        char fv[JSON_FILE_NAME_LEN];
        int num;
        int cur_Zone;
        int pre_Zone;

    }TSETCFG;
    
    // 系统时间
    typedef struct tagSYSTIME
    {
        unsigned short ms;   //例如: 979 必须偶地址开始
        unsigned char ss;    //例如:  39
        unsigned char min;   //例如:  59
        unsigned char hh;    //例如:  13
        unsigned char dd;    //例如:  32
        unsigned char mm;    //例如:  08
        unsigned short yy;   //例如:2013
        unsigned char unuse; //保证为偶数
    } TSYSTIME;
   // extern TSYSTIME *gtSYSTIME;

    // 设备状态 IsReady = true 可用  IsReady = true 不可用，需要初始化
    typedef struct tagDevState
    {
        bool LED_IsReady;
        bool YX_IsReady;
        bool YK_IsReady;
        bool YC_IsReady;
        bool COM1_IsReady;
        bool RTC_IsReady;
    } TDEVSTATE;
    //extern TDEVSTATE *gtDevState;

    //总模块
    typedef struct tStru
    {
        TDEV gtDEV; //设备配置信息
        TVER gtVER; //版本信息
        TMFR gtMFR; //厂家信息
        TYC gtYC;  //遥测模块信息
        TYC_CHN gtYC_CHN[YC_NUM_MAX];//遥测通道
        TYX gtYX; //遥信模块
        TYX_CHN gtYX_CHN[YX_NUM_MAX];//遥信通道
        TYK gtYK; //遥控模块
        TYK_CHN gtYK_CHN; //遥控通道
        TCOM  gtCOM; //串口模块
        TCOM_CHN gtCOM_CHN[COM_NUM_MAX]; //串口通信
        TETH gtETH; //以太网
        THMI gtHMI; //人机
        TSPI gtSPI; 
        TSD  gtSD;
        TUSB gtUSB;
        TDBG gtDBG; //调试信息
        TSET gtset1;
        TSET gtset2;
        TSET gtset3;
        TSETCFG gtsetcfg;

        TDEVSTATE gtDevState;
        TSYSTIME gtSYSTIME;
    }TOTALSTRU;
    extern TOTALSTRU *tol;
#ifdef __cplusplus
}
#endif

#endif