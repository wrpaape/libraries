#ifndef CONTAINER_QUEUE_BHEAP_H_
#define CONTAINER_QUEUE_BHEAP_H_

#ifdef __cplusplus /* ensure C linkage */
extern "C" {
#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict' */
#define restrict __restrict__
#endif
#endif


/* EXTERNAL DEPENDENCIES
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#include <memory_utils/memory_set.h>	/* MemorySet */
#include <memory_utils/memory_get.h>	/* MemoryGet */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

struct BHeap {
	void *nodes;			/* byte array buffer */
	size_t count;			/* count of occupied nodes */
	size_t capacity;		/* count of allocated nodes */
	size_t width;			/* byte size per node */
	MemoryGet *get;			/* array access function */
	MemorySet *set;			/* memory setting function */
	int (*compare)(const void *,	/* node comparison function */
		       const void *);
};

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS */


/* initialize, destroy, resize
 ******************************************************************************/
inline struct BHeap *bheap_alloc(const size_t capacity,
				 const size_t width)
{
	struct BHeap *restrict heap;

	HANDLE_MALLOC(heap, sizeof(struct BHeap));
	HANDLE_MALLOC(heap->nodes, width * capacity);

	heap->capacity = capacity;
	heap->width    = width;

	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	heap->nodes = memory_offset(heap->nodes,
				    -width);

	return heap;
}

inline void bheap_init(struct BHeap *const restrict heap,
		       int (*compare)(const void *,
				      const void *))
{

	heap->get     = assign_memory_get(heap->width);

	if (heap->get == NULL)
		EXIT_ON_FAILURE("BHeap node width of %zu bytes exceeds "
				"maximum supported width of %zu bytes",
				heap->width, WIDTH_MAX);

	heap->set     = assign_memory_set(heap->width);
	heap->compare = compare;
	heap->count   = 0ul;
}

inline struct BHeap *bheap_create(const size_t width,
				  int (*compare)(const void *,
						 const void *))
{
	struct BHeap *const restrict heap = bheap_alloc(1ul, width);

	bheap_init(heap, compare);

	return heap;
}

inline void bheap_free(const struct BHeap *const restrict heap)
{
	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	free(memory_offset(heap->nodes,
			   heap->width));
	free(heap);
}

inline void bheap_realloc(struct BHeap *const restrict heap,
			  const size_t new_capacity)
{
	const void *const restrict nodes = realloc(memory_offset(heap->nodes,
								 heap->width),
						   heap->width * new_capacity);

	if (nodes == NULL)
		EXIT_ON_FAILURE("failed to reallocate node capacity "
				"from %lu to %lu",
				heap->capacity, new_capacity);

	heap->nodes = pointer_offset(nodes,
				     -(heap->width));

	heap->capacity = new_capacity;
}



/* insertion
 ******************************************************************************/
void bheap_do_insert(const struct BHeap *const restrict heap,
		     void *const restrict node,
		     const size_t i_next);

void bheap_insert_array(const struct BHeap *const restrict heap,
			void *const array,
			const size_t length);

inline void bheap_insert(struct BHeap *const restrict heap,
			 const void *const node)
{
	++(heap->count);

	if (heap->count == heap->capacity)
		bheap_realloc(heap,
			      heap->capacity * 2ul);

	bheap_do_insert(heap,
			node,
			heap->count);
}




/* extraction
 ******************************************************************************/
inline void *bheap_extract(struct BHeap *const restrict heap)
{
	if (heap->count == 0ul)
		return NULL;

	const void *const restrict root = heap->get(heap->nodes,
						    1ul);

	void *const restrict base = heap->get(heap->nodes,
					      heap->count);

	--(heap->count);

	bheap_do_shift(heap,
		       base,
		       1ul);
	return root;
}

void bheap_do_shift(const struct BHeap *const restrict heap,
		    void *const restrict node,
		    const size_t i_next);



/* display
 ******************************************************************************/
void print_bheap(const struct BHeap *const restrict heap,
		 void (*node_to_string)(char *restrict,
					const void *restrict));




/* heapsort
 ******************************************************************************/
/* void sort_bheap_nodes(void *const nodes, */
/* 		      const size_t length, */
/* 		      const size_t width, */
/* 		      int (*compare)(const void *, */
/* 				     const void *)); */

/* inline void bheap_sort(void *const array, */
/* 		       const size_t length, */
/* 		       const size_t width, */
/* 		       int (*compare)(const void *, */
/* 				      const void *)) */
/* { */
/* 	sort_bheap_nodes(&array[-1l], length, width, compare); */
/* } */



/* convienience, misc
 ******************************************************************************/
/* inline struct BHeap *array_into_bheap(void *const array, */
/* 				      const size_t length, */
/* 				      const size_t width, */
/* 				      int (*compare)(const void *, */
/* 						     const void *)) */
/* { */
/* 	const size_t array_size = width * length; */
/* 	const struct BHeap *const restrict heap; */
/* 	void *nodes; */

/* 	HANDLE_MALLOC(heap, sizeof(struct BHeap)); */
/* 	HANDLE_MALLOC(nodes, array_size); */
/* 	memcpy(nodes, array, array_size); */

/* 	/1* sentinel node at index 0 *1/ */
/* 	--nodes; */

/* 	sort_bheap_nodes(nodes, width, length, compare); */

/* 	heap->nodes   = nodes; */
/* 	heap->count   = length; */
/* 	heap->capacity   = length; */
/* 	heap->compare = compare; */

/* 	return heap; */

/* } */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef CONTAINER_QUEUE_BHEAP_H_ */
