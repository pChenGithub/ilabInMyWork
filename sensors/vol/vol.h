/*************************************************************************
	> File Name: vol.h
	> Author: chen.peng
	> Mail: 404285202@qq.com 
	> Created Time: 2019年07月29日 星期一 18时00分53秒
 ************************************************************************/

#ifndef _VOL_H_
#define _VOL_H_

#include <sensors.h>

static int read_data(void);
static int format_data(void);
static int task_vol(void);

#define SENSOR_VOL(vol) \
	struct sensor vol = { \
		\
	};

#endif
