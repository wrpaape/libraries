#include "node_cache.c"

extern size_t global_page_size; /* must be set before initialization */

void node_cache_init(struct NodeCache *cache,
			  const size_t node_size,
			  const size_t min_cache_count)
{
	const size_t node_node_size = sizeof(struct LinkNode) + node_size;

	const size_t min_cache_size = sizeof(struct LinkNode)
				    + (node_node_size * min_cache_count);

	size_t pages_per_cache_node = min_cache_size / global_page_size;

	if ((min_cache_size % global_page_size) > 0ul)
		++pages_per_cache_node;

	cache->node_size = node_size;
	cache->block_size = pages_per_cache_node * global_page_size;

	const size_t nodes_per_cache = (cache->block_size
					 - sizeof(struct LinkNode))
				      / node_node_size;

	cache->overhead_per_cache = sizeof(struct LinkNode)
				      + (node_node_size * nodes_per_cache);

	cache->free_nodes = NULL;
	cache->live_nodes = NULL;
	cache->blocks      = NULL;
}

void *node_cache_pop(void)
{
}



