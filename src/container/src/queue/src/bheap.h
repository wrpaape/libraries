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

#include <mem_utils/mem_swap.h>	/* MemSwap, <utils/utils> */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * EXTERNAL DEPENDENCIES
 *
 *
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

struct BHeap {
	size_t capacity;		/* count of allocated nodes */
	size_t width;			/* byte size per node */
	size_t count;			/* count of occupied nodes */
	void *nodes;			/* array of heap nodes */
	MemSwap *swap;			/* memory swapping function */
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
	struct BHeap *heap;

	HANDLE_MALLOC(heap, sizeof(struct BHeap));
	HANDLE_MALLOC(heap->nodes, width * capacity);

	heap->capacity = capacity;
	heap->width    = width;
	--(heap->nodes); /* sentinel node at index 0, i.e. 'nodes[1]' points to
			    first valid node, 'nodes[0]' is illegal */
	return heap;
}

inline void bheap_init(struct BHeap *heap,
		       int (*compare)(const void *,
				      const void *))
{

	heap->swap = assign_mem_swap(heap->width);

	if (heap->swap == NULL)
		EXIT_ON_FAILURE("BHeap node width of %zu bytes exceeds "
				"maximum supported width of %zu bytes",
				width, MAX_BYTE_BUFF_WIDTH);
	heap->count   = 0ul;
	heap->width   = width;
	heap->compare = compare;
}

inline struct BHeap *bheap_create(const size_t width,
				  int (*compare)(const void *,
						 const void *))
{
	struct BHeap *heap = bheap_alloc(1ul, width);

	bheap_init(heap, compare);

	return heap;
}


inline void bheap_clear(struct BHeap *heap)
{
	heap->count = 0ul;
}

inline void bheap_free(struct BHeap *heap)
{
	free(&heap->nodes[1l]);
	free(heap);
}

inline void bheap_realloc(struct BHeap *heap,
			  const size_t new_capacity)
{
	void *nodes = realloc(&heap->nodes[1l], heap->width * new_capacity);

	if (nodes == NULL)
		EXIT_ON_FAILURE("failed to reallocate number of nodes"
				"from %lu to %lu",
				heap->capacity, new_capacity);

	heap->capacity = new_capacity;
}



/* insertion
 ******************************************************************************/
void do_insert(void *const nodes,
	       void *const next,
	       const size_t width,
	       const ptrdiff_t i_next,
	       int (*compare)(const void *,
			      const void *));

void bheap_insert_array(struct BHeap *heap,
			void *const array,
			const size_t length);

inline void bheap_insert(struct BHeap *heap,
			 void *const next)
{
	++(heap->count);

	if (heap->count == heap->capacity)
		bheap_realloc(heap, heap->capacity * 2ul);

	while (1) {
		heap->swap(&heap->nodes[1l],next)
	}
}


	/* do_insert(heap->nodes, next, heap->count, heap->width, heap->compare); */



/* extraction
 ******************************************************************************/
void *bheap_extract(struct BHeap *heap);

void do_bheap_shift(void *const __restrict__ nodes,
		    void *const __restrict__ next,
		    const size_t width,
		    const ptrdiff_t i_next,
		    const ptrdiff_t i_base,
		    int (*compare)(const void *,
				   const void *));


/* display
 ******************************************************************************/
void print_bheap(struct BHeap *heap,
		 void (*node_to_string)(char *,
					const void *));




/* heapsort
 ******************************************************************************/
void sort_bheap_nodes(void *const nodes,
		      const size_t length,
		      const size_t width,
		      int (*compare)(const void *,
				     const void *));

inline void bheap_sort(void *const array,
		       const size_t length,
		       const size_t width,
		       int (*compare)(const void *,
				      const void *))
{
	sort_bheap_nodes(&array[-1l], length, width, compare);
}



/* convienience, misc
 ******************************************************************************/
inline struct BHeap *array_into_bheap(void *const array,
				      const size_t length,
				      const size_t width,
				      int (*compare)(const void *,
						     const void *))
{
	const size_t array_size = width * length;
	struct BHeap *heap;
	void *nodes;

	HANDLE_MALLOC(heap, sizeof(struct BHeap));
	HANDLE_MALLOC(nodes, array_size);
	memcpy(nodes, array, array_size);

	/* sentinel node at index 0 */
	--nodes;

	sort_bheap_nodes(nodes, width, length, compare);

	heap->nodes   = nodes;
	heap->count   = length;
	heap->capacity   = length;
	heap->compare = compare;

	return heap;

}
#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef CONTAINER_QUEUE_BHEAP_H_ */
