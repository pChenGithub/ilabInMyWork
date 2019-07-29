/*************************************************************************
	> File Name: sensors.h
	> Author: chen.peng
	> Mail: 404285202@qq.com 
	> Created Time: 2019年07月29日 星期一 10时41分06秒
 ************************************************************************/

#ifndef _SENSORS_H_
#define _SENSORS_H_

#include "listNode.h"
/*
struct node {
	struct node* next;
	struct node* pre;
};
*/

struct sensorsList {
	char count;
	struct node* node;
};

struct sensorsManager_opt {

	int *check_sendors(void);
	int *add_sensor(void);
	int *remove_sensor(void);
	int *check_sendors_by_name(void);
};

struct sensorsManager {
	char cycleTime;   // us
	struct sensorsList list;
	struct sensorsManager_opt* opt;
};

int sM_init(void);
static int sM_check_sendors(struct sensorsManager* sM);
static int sM_add_sensor(struct sensorsManager *sM, struct sensor* sensor);
static int sM_remove_sensor(struct sensorsManager* sM, struct sensor* sensor);
static int sM_check_sendors_by_name(void);

struct sensor {
	struct node node;
	char name[16];
	int (*s_task)(void);
};
/* task count 0~5
 * task[5]
 * */

//#define SENSOR(name, task_c, ) \
//	struct sensor name = { \
//		\
//	}

#define SENSORSMANAGER(name) \
	struct sensorsManager_opt sM_opt = {\
		sM_check_sendors ,\
		sM_add_sensor, \
		sM_remove_sensor, \
		sM_check_sendors_by_name, \
	}; \
	struct sensorsManager name = { \
		 1000000, \
		{0 , null}, \
		sM_opt, \
	}

#define SENSORSMANAGER(name, opt) \
	struct sensorsManager name = { \
		 1000000, \
		{0 , null}, \
		opt, \
	}

#endif



