#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
//#include <linux/io.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/bitops.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/interrupt.h>
#include <linux/time.h>
#include <linux/rtpm_prio.h>

#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#include <mach/mt_pm_ldo.h>
#include <mach/mt_typedefs.h>
#include <mach/mt_boot.h>

#include <cust_eint.h>
#include <linux/jiffies.h>
/* Pre-defined definition */
#define TPD_TYPE_CAPACITIVE
#define TPD_TYPE_RESISTIVE
#define TPD_POWER_SOURCE         
#define TPD_I2C_NUMBER           		0
#define TPD_WAKEUP_TRIAL         		60
#define TPD_WAKEUP_DELAY         		100

#define TPD_VELOCITY_CUSTOM_X 			15
#define TPD_VELOCITY_CUSTOM_Y 			20

#define TPD_POWER_SOURCE_CUSTOM         MT65XX_POWER_LDO_VGP4

#define TPD_DELAY                		(2*HZ/100)
//#define TPD_RES_X                		480
//#define TPD_RES_Y                		800
#define TPD_CALIBRATION_MATRIX  		{962,0,0,0,1600,0,0,0};

//#define TPD_HAVE_CALIBRATION
//#define TPD_HAVE_TREMBLE_ELIMINATION

//#define TPD_PROXIMITY					// if need the PS funtion,enable this MACRO
#define TPD_HAVE_BUTTON					// if have virtual key,need define the MACRO
#define TPD_BUTTON_HEIGH        		(60)
#define TPD_KEY_COUNT           		3
#define TPD_KEYS                		{ KEY_MENU, KEY_HOMEPAGE ,KEY_BACK}
#define TPD_KEYS_DIM            		{{120,1380,60,TPD_BUTTON_HEIGH},{360,1380,60,TPD_BUTTON_HEIGH},{600,1380,60,TPD_BUTTON_HEIGH}}

/******************************************************************************/
/*Chip Device Type*/
#define IC_FT5X06						0	/*x=2,3,4*/
#define IC_FT5606						1	/*ft5506/FT5606/FT5816*/
#define IC_FT5316						2	/*ft5x16*/
#define IC_FT6208						3  	/*ft6208*/
#define IC_FT6x06     					4	/*ft6206/FT6306*/
#define IC_FT5x06i     					5	/*ft5306i*/
#define IC_FT5x36     					6	/*ft5336/ft5436/FT5436i*/

#define DEVICE_IC_TYPE					IC_FT5X06

/*register address*/
#define FT6x06_REG_FW_VER				0xA6
#define FT6x06_REG_VENDOR_ID			0xA8

#if ( DEVICE_IC_TYPE == IC_FT5X06 )
  #define FTS_NAME						"FT5x06"
  #define TPD_MAX_POINTS 				5
  #define AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT5606 )
  #define FTS_NAME						"FT5606"
  #define TPD_MAX_POINTS 				5//10
  #define AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT5316 )
  #define FTS_NAME						"FT5316"
  #define TPD_MAX_POINTS 				5
  #define AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT6208 )
  #define FTS_NAME						"FT6208"
  #define TPD_MAX_POINTS 				2
  //#define AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT6x06 )
  #define FTS_NAME						"FT6x06"
  #define TPD_MAX_POINTS 				2
  //#define AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT5x06i )
  #define FTS_NAME						"FT5x06i"
  #define TPD_MAX_POINTS 				5
  #define    AUTO_CLB
#elif ( DEVICE_IC_TYPE == IC_FT5x36 )
  #define FTS_NAME						"FT5x36"
  #define TPD_MAX_POINTS 				5
  #define AUTO_CLB
#endif

#define TPD_SYSFS_DEBUG
#define FTS_CTL_IIC
#ifdef TPD_SYSFS_DEBUG
//#define TPD_AUTO_UPGRADE				// if need upgrade CTP FW when POWER ON,pls enable this MACRO
#endif

#define FTS_DBG
#ifdef FTS_DBG
#define DBG(fmt, args...) 				printk("[FTS]" fmt, ## args)
#else
#define DBG(fmt, args...) 				do{}while(0)
#endif

#endif /* TOUCHPANEL_H__ */
