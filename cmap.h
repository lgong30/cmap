#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H



#ifdef __cplusplus
extern "C" {
#endif
void *map_create();
bool map_empty(void *);
void map_insert(void *,int,int);
bool map_erase(void *,int );
int map_find(void *,int);
bool map_exists(void *,int);
bool map_update(void *,int,int);
int map_size(void *);
int map_max(void *);
void map2arrays(void *,int *,int *);
void map_print(void *);
#ifdef __cplusplus
}
#endif



#endif