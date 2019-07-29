/*************************************************************************
	> File Name: sensors.c
	> Author: chen.peng
	> Mail: 404285202@qq.com 
	> Created Time: 2019年07月29日 星期一 13时13分11秒
 ************************************************************************/

#include "sensors.h"

static int sM_check_sendors(struct sensorsManager* sM) {
	struct sensorsList* list = & sM->list;
	char s_count = list->count;
	struct node* node = list->node;
	char delay_t = sM->cycleTime;

	if (!count) {
	
		perror("sensors list is empty \n");
		return -1;
	}

	while (s_count--) {
		struct sensor* sensor = (struct sensor*)node;
		char tast_count = sensor->s_task.tast_count;
		int (*)() *s_task = sensors->s_task;
		//for (i=0;i<tast_count;i++)
		s_task();

		node = node->next;
	}

	usleep(delay_t);

	return 0;
}

static int sM_add_sensor(struct sensorsManager *sM, struct sensor* sensor) {

	struct sensorsList* list = & sM->list;
	char s_count = list->count;
	struct node* node = (struct node*)sensor;

	if (s_count==0) {
	
		list->node = node;
		insert_first(node);
	}else {
	
		insert(list->node->pre, node);
	}

	(list->count) ++;

	return 0;
}

static int sM_remove_sensor(struct sensorsManager* sM, struct sensor* sensor) {

	struct sensorsList* list = & sM->list;
	char s_count = list->count;
	struct node* node = (struct node*)sensor;

	if (s_count==0) {

		perror("sensors is empty \n");
		return -1;
	}else if (s_count == 1) {
	
		list->node = NULL;
		free(sensor);
	}else if (list->node != node) {

		remove(node)
		free(sensor);
	}else {
	
		list->node = node->next;
		remove(node);
		free(sensor);
	}

	(list->count) --;

	return 0;
}

static int sM_check_sendors_by_name(void) {

	return 0;
}




