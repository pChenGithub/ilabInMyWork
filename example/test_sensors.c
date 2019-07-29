/*************************************************************************
	> File Name: test_sensors.c
	> Author: chen.peng
	> Mail: 404285202@qq.com 
	> Created Time: 2019年07月29日 星期一 15时17分01秒
 ************************************************************************/

#include <stdio.h>
#include "sensors.h"

int main(int argc, char* argv[] ) {

	SENSORSMANAGER(sensorsManager);
	struct sensor vol
	sensorsManager.opt->sM_add_sensor(&sensorsManager, &vol);
	struct sensor rfid;
	sensorsManager.opt->sM_add_sensor(&sensorsManager, &rfid);

	while (1) {
	
		sensorsManager.opt->check_sendors(&sensorsManager);
	}

	return 0;
}


void exit_app(void) {

	exit(-1);
}

