#include <iostream>
#include <map>
#include <utility> /* for pair */
#include <assert.h>
#include "cmap.h"

typedef std::map<int,int> CMap;

/* create an empty map */
void *map_create()
{
	CMap *m = new CMap();
	return ((void *)m);
}
/* check the map is empty or not */
bool map_empty(void *m)
{
  	return ((CMap *)m)->empty();
}
/* map insert with (key,value)-pair */
void map_insert(void *m,int key,int value)
{
	 CMap *mymap = ((CMap *)m);
	 CMap::iterator it = mymap->begin();
     mymap->insert (it, std::pair<int,int>(key,value));  // max efficiency inserting
}
/* map delete with key, return false if the key does no exist */
bool map_erase(void *m,int key)
{
	CMap *mymap = (CMap *)m;
	CMap::iterator it = mymap->find(key);

	if (it != mymap->end())
	{
		mymap->erase(it);
		return true;
	}
	return false;
}
/* map find with key, return -1 if not found */
int map_find(void *m,int key)
{
	CMap *mymap = (CMap *)m;
	CMap::iterator it = mymap->find(key);

	if (it != mymap->end()) return it->second;
	else return -1;
}
/* map exists */
bool map_exists(void *m,int key)
{
	CMap *mymap = (CMap *)m;
	CMap::iterator it = mymap->find(key);

    return (it != mymap->end());
}
/* map update with key and incremental value, 
   note that here the key is the value to be
   updated.
*/
bool map_update(void *m,int key,int delta)
{
	CMap *mymap = (CMap *)m;
	CMap::iterator it = mymap->find(key);

	if (it == mymap->end()) return false;
	int value = it->second;
	key +=  delta;
	mymap->erase(it);
	mymap->insert(mymap->begin(),std::pair<int,int>(key,value));
	return true;	
}
/* size of your map */
int map_size(void *m)
{
	return ((CMap *)m)->size();
}
/* get the value corresponding to the maximum key:
   note that, in CMap, pairs are sorted from small 
   to large
*/
int map_max(void *m)
{
	return ((CMap *)m)->rbegin()->second;
}
/* convert a map to two arrays: key array and value array:
   from smallest to largest (measured by keys)
*/
void map2arrays(void *m,int *keys,int *values)
{
 	assert(keys != NULL && values != NULL);	
 	int i = 0;
 	CMap::iterator it;
 	CMap *mymap = ((CMap *)m);

 	for (it = mymap->begin();it != mymap->end();++ it)
 	{
 		keys[i] = it->first;
 		values[i] = it->second;
 		++ i;
 	}

}
/* print your map */
void map_print(void *m)
{
 	CMap *mymap = ((CMap *)m);
  	CMap::iterator it;	

    std::cout << "Your map:" << "\n";
  	for (it = mymap->begin();it != mymap->end();++ it)
  		std::cout << "\t\t" << it->first << " => " << it->second << "\n";
}
