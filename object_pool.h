#ifndef _OBJECT_POOL_H
#define _OBJECT_POOL_H

#include <stdlib.h>

typedef struct object_pool object_pool;

/*
 * pool_size denotes the number of objects in each pool.
 *
 * The memorypool itself can hold infinite pools, so there is no limit on the
 * amount of objects you can allocate.
 */
object_pool *object_pool_new(size_t object_size, size_t pool_size);

/*
 * get and put are used to get objects from the object_pool that can then be used.
 * Putting an object will allow it to be reused by the memory pool.
 *
 * Note: It is *not* necessary to 'put' objects allocated using 'get'.
 * All objects allocated by this pool will be freed back to the system when
 * object_pool_free is called. 'put' is use useful to keep the total
 * memory-usage of the pool down if you know objects won't be used again.
 */
void *object_pool_get(object_pool *pool);

/* 
 * Releases all of the allocated objects and object_pool itself.
 */
void object_pool_free(object_pool *pool);

#endif
