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
#include <memory_utils/memory_set.h>	/* MemoryGet */
#include <memory_utils/memory_swap.h>	/* MemorySwap */

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
	MemorySwap *swap;		/* memory swapping function */
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

	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	heap->nodes = pointer_offset(heap->nodes, -width);

	return heap;
}

inline void bheap_init(struct BHeap *heap,
		       int (*compare)(const void *,
				      const void *))
{

	heap->get     = assign_memory_get(heap->width);

	if (heap->get == NULL)
		EXIT_ON_FAILURE("BHeap node width of %zu bytes exceeds "
				"maximum supported width of %zu bytes",
				heap->width, WIDTH_MAX);

	heap->set     = assign_memory_set(heap->width);
	heap->swap    = assign_memory_swap(heap->width);
	heap->compare = compare;
	heap->count   = 0ul;
}

inline struct BHeap *bheap_create(const size_t width,
				  int (*compare)(const void *,
						 const void *))
{
	struct BHeap *heap = bheap_alloc(1ul, width);

	bheap_init(heap, compare);

	return heap;
}

inline void bheap_free(struct BHeap *heap)
{
	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	free(pointer_offset(heap->nodes,
			    heap->width));
	free(heap);
}

inline void bheap_realloc(struct BHeap *heap,
			  const size_t new_capacity)
{
	void *nodes = realloc(pointer_offset(heap->nodes,
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
			 const void *const next)
{
	++(heap->count);

	if (heap->count == heap->capacity)
		bheap_realloc(heap,
			      heap->capacity * 2ul);

	size_t i_next = heap->count;

	size_t i_parent;

	void *parent;

	while (1) {

		if (i_next == 1ul) {
			heap->set(heap->get(heap->nodes,
					    1l),
				  next);
			return;
		}

		i_parent = i_next / 2ul;



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
