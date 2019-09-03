/*
 * @Author: Yangxl
 * @LastEditors: Please set LastEditors
 * @Description: 全局宏定义
 * @Date: 2019-03-28 21:05:43
 * @LastEditTime: 2019-08-26 19:57:18
 */

#ifndef gdefine__h
#define gdefine__h

#ifdef __cplusplus
extern "C"
{
#endif

#define MD_YC ON   //采样模块
#define MD_YX ON   //遥信模块
#define MD_YK ON   //遥控模块
#define MD_MEA ON  //测量模块
#define MD_RLY ON  //保护模块
#define MD_RPT ON  //事件记录模块
#define MD_WAVE ON //录波模块
#define MD_ETH1 ON //以太网1模块
#define MD_COM1 ON //串口1模块
#define MD_COM2 ON //串口2模块
#define MD_COM3 ON //串口3模块
#define MD_COM4 ON //串口4模块
#define MD_OPT ON  //运维模块
#define MD_TEST ON //测试模块

#define FILE_NAME_LEN_MAX 40

#define CT 2
#define PT 1

#define COM_NUM_MAX 4  //串口最大数量
#define YX_NUM_MAX 2   //遥信最大数量
#define YK_NUM_MAX 1   //遥控最大数量
#define YC_NUM_MAX 16  //遥测最大数量
#define LED_NUM_MAX 18 //LED指示灯最大数量

#define SAM16 16   //采样点16
#define SAM32 32   //采样点32
#define SAM64 64   //采样点64
#define SAM128 128 //采样点128
#define SAM256 256 //采样点256
#define SAM512 512 //采样点256

#define SAM16N 4  //1<<4 2^4 =64
#define SAM32N 5  //2<<5 2^5 =64
#define SAM64N 6  //2<<6 2^6 =64
#define SAM128N 7 //2<<7 2^7 =128
#define SAM256N 8 //2<<8 2^8 =256
#define SAM512N 9 //2<<9 2^9 =512

#define SAM_DISABLE 0
#define SAM_ENABLE 1

#define SEM1 1000
#define SEM2 1001
#define SEM_RLY_EMPTY "rlyEmpty"
#define SEM_RLY_FULL "rlyFull"
#define SEM_MEA_EMPTY "meaEmpty"
#define SEM_MEA_FULL "meaFull"

#define SHM1 2000
#define SHM2 2001
#define SHM_RLY "shmRly"
#define SHM_MEA "shmMea"
#define SHM_UZ "shmUz"

#define MSG1_PROCESS 3000
#define MSG2 3001
#define MSG3 3002

#define MQ_MEA "/mqMea"
#define MQ_TEST "/mqTest"

#ifdef __cplusplus
}
#endif

#endif