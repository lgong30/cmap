#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "cmap.h"



#define FAIL(msg) \
do{                            \
    printf("%s failed\n",msg); \
    exit(-1);                  \
}while(0)

#define SUCCESS(msg) \
	printf("%s succeeded\n",msg)

#define INFO(msg) \
	printf("test %s ...\n",msg)

void print_linsep()
{
	int i;
	for (i = 0;i < 70;++ i)
		printf("=");
	printf("\n");
}
void rl(int n)
{
	int i;
	for (i = 0;i < n;++ i)
		printf("\n");
}



int main()
{
	int okay = 0;
	char *msg;

    int TEST_NUM = 1e4, TEST_DEL = TEST_NUM / 2;
    int *dels = (int *)malloc(TEST_DEL * sizeof(int));
    int MAX_V = 1e6;
    int i, r, c, j, verosity = 1;

    srand(time(NULL));

	msg = "map create";
	INFO(msg);
	void *m = map_create();

	if (m == NULL) 
		okay = -1;
		
	if (okay == -1)
		FAIL(msg);
	else
		SUCCESS(msg);
    print_linsep();
    rl(2);

    printf("\n");

    msg = "map insert";

    INFO(msg);
    print_linsep();

    c = 0;
    j = 0;
    for (i = 0;i < TEST_NUM;++ i)
    {
    	r = rand() % MAX_V + 1;
    	if (verosity >= 1)
    	{
    		printf("\tinsert %5d => %5d\n",r,i);
    	}
    	if(map_exists(m,r) && verosity >=1)
    		printf("\t%5d existed\n",r);
    	else
    	{
    		map_insert(m,r,i);
    		++ c;
    		if (j < TEST_DEL)
    		{
    			dels[j] = r;
    		    ++j;
    		}
    	}
    }
    okay = (c == map_size(m)?0:-1);
    if (okay == -1)
    	FAIL(msg);
    else
    	{
    		rl(2);
    		map_print(m);
    		SUCCESS(msg);
    	}
    print_linsep();
    rl(2);

    msg = "map update";
    INFO(msg);
    for (i = 0;i < TEST_DEL;++ i)
    {
    	r = (int)(((double)rand())/RAND_MAX * MAX_V - MAX_V / 2);
    	if(!map_update(m,dels[i],r))
    	{
    		okay = -1;
    		break;
    	}
    	if (verosity >= 1)
    	{
    		printf("\tupdate %5d => %5d\n",dels[i],r + dels[i]);
    		rl(2);
    		map_print(m);
    		rl(2);
    	}
    	dels[i] += r;
    }
    if (okay == -1)
    	FAIL(msg);
    else
    	{
    		rl(2);
    		map_print(m);
    		SUCCESS(msg);
    	}
    print_linsep();
    rl(2);  

    msg = "map to arrays";
    int *keys = (int *)malloc(sizeof(int) * map_size(m));
    int *values =  (int *)malloc(sizeof(int) * map_size(m));

    printf("arrays:\n");
    map2arrays(m,keys,values);
    for (i = 0;i < map_size(m);++ i)
    	printf("\t\t%5d => %5d\n",keys[i],values[i]);
    if (okay == -1)
    	FAIL(msg);
    else
    	{
    		rl(2);
    		map_print(m);
    		SUCCESS(msg);
    	}
    print_linsep();
    rl(2);  

    msg = "map delete (valid)";


    for (i = 0;i < TEST_DEL;++ i)
    {
    	if(!map_erase(m,dels[i]))
    	{
    		okay = -1;
    		break;
    	}
    	if (verosity >= 1)
    	{
    		printf("delete %5d => %5d\n",dels[i],r);
    		rl(2);
    		map_print(m);
    		rl(2);
    	}
    }
    if (okay == -1)
    	FAIL(msg);
    else
    	{
    		rl(2);
    		map_print(m);
    		SUCCESS(msg);
    	}
    print_linsep();
    rl(2); 


    msg = "map delete (invalid)";


    for (i = 0;i < TEST_DEL;++ i)
    {
    	r = MAX_V + 10;
    	if(map_erase(m,r))
    	{
    		okay = -1;
    		break;
    	}
    	if (verosity >= 1)
    	{
    		printf("delete %5d => %5d\n",dels[i],r);
    		rl(2);
    		map_print(m);
    		rl(2);
    	}
    }
    if (okay == -1)
    	FAIL(msg);
    else
    	{
    		rl(2);
    		map_print(m);
    		SUCCESS(msg);
    	}
    print_linsep();
    rl(2); 

    free(keys);
    free(values);


    free(dels);
	return 0;
}