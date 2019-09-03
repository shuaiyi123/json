/*
 * @Description: 创建共享文件，使用mmap映射进内存，并强制转化为结构体类型
 * @Author: your name
 * @Date: 2019-08-27 22:51:55
 * @LastEditTime: 2019-09-03 02:17:02
 * @LastEditors: Please set LastEditors
 */
#ifndef shm__h
#define shm__h

#ifdef __cplusplus
extern "C"
{
#endif

//共享内存
#define SHM_JSON   "shm_struct"

//读取共享内存信号量
#define SEM_GET_JSON "sem_get_json"
//更新devcfg.json信号量
#define SEM_DEVCFG_JSON "sem_gevcfg_json"
//更新ver.json
#define SEM_VER_JSON "sem_ver_json"
//更新mfr.json
#define SEM_MFR_JSON "sem_mfr_json"
//更新yc.json
#define SEM_YC_JSON "sem_yc_json"
//更新yx.json
#define SEM_YX_JSON "sem_yx_json"
//更新yk.json
#define SEM_YK_JSON "sem_yk_json"
//更新com.json
#define SEM_COM_JSON "sem_com_json"
//更新eth.json
#define SEM_ETH_JSON "sem_eth_json"
//更新hmi.json
#define SEM_HMI_JSON "sem_hmi_json"
//更新spi.json
#define SEM_SPI_JSON "sem_spi_json"
//更新sd.json
#define SEM_SD_JSON  "sem_sd_json"
//更新usb.json
#define SEM_USB_JSON "sem_usb_json"
//更新dbg.json
#define SEM_DBG_JSON "sem_dbg_json"
//更新setcfg.json
#define SEM_SETCFG_JSON "sem_setcfg_json"
//更新set1.json
#define SEM_SET1_JSON "sem_set1_json"
//更新set2.json
#define SEM_SET2_JSON "sem_set2_json"
//更新set3.json
#define SEM_SET3_JSON "sem_set3_json"


int createShm();
sem_t *createSem(const char *semName,int value);
void *jsonUpdate_pthread(void *do_abort);
#ifdef __cplusplus
}
#endif

#endif