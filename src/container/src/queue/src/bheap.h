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

#include <memory_utils/memory_get.h>	/* MemoryGet */
#include <memory_utils/memory_set.h>	/* MemorySet */
#include <memory_utils/memory_swap.h>	/* MemorySwap */
#include <stdbool.h>			/* bool */

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
 * TYPEDEFS, ENUM AND STRUCT DEFINITIONS
 *
 *
 * CONSTANTS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

#define BHEAP_PRINT_BUFFER_SIZE 1024ul

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * CONSTANTS
 *
 *
 * FUNCTION-LIKE MACROS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */
/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * FUNCTION-LIKE MACROS
 *
 *
 * TOP-LEVEL FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* initialize, destroy, resize
 * ══════════════════════════════════════════════════════════════════════════ */
inline void bheap_assign_accessors(struct BHeap *const restrict heap)
{
	if (heap->width == 0ul)
		EXIT_ON_FAILURE("zero byte BHeap node width is not supported: "
				"(valid width 'w' = { w ∈ ℕ | 1 ≤ w ≤ %zu })",
				WIDTH_MAX_SIZE);

	if (heap->width > WIDTH_MAX_SIZE)
		EXIT_ON_FAILURE("BHeap node width of %zu bytes exceeds "
				"supported maximum: "
				"(valid width 'w' = { w ∈ ℕ | 1 ≤ w ≤ %zu })",
				heap->width, WIDTH_MAX_SIZE);

	heap->get  = MEMORY_GET_MAP[ heap->width];
	heap->set  = MEMORY_SET_MAP[ heap->width];
	heap->swap = MEMORY_SWAP_MAP[heap->width];
}

inline void bheap_init(struct BHeap *const restrict heap,
		       const size_t capacity,
		       const size_t width,
		       int (*compare)(const void *,
				      const void *))
{
	HANDLE_MALLOC(heap->nodes, width * capacity);

	heap->capacity = capacity;
	heap->width    = width;

	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	heap->nodes = memory_offset(heap->nodes,
				    -width);

	bheap_assign_accessors(heap);

	heap->compare = compare;
	heap->count   = 0ul;
}

inline struct BHeap *bheap_create(const size_t width,
				  int (*compare)(const void *,
						 const void *))
{
	struct BHeap *restrict heap;

	HANDLE_MALLOC(heap, sizeof(struct BHeap));

	bheap_init(heap, 1ul, width, compare);

	return heap;
}

inline void bheap_clear(struct BHeap *restrict heap)
{
	/* sentinel node at index 0, i.e. 'nodes[1]' points to first valid node,
	 * 'nodes[0]' is illegal */
	free(memory_offset(heap->nodes,
			   heap->width));
}

inline void bheap_destroy(struct BHeap *restrict heap)
{
	bheap_clear(heap);
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

	heap->nodes = memory_offset(nodes,
				    -(heap->width));

	heap->capacity = new_capacity;
}



/* insertion
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_do_asc_restore(const struct BHeap *const restrict heap,
			  void *const restrict node,
			  const size_t i_node);

void inv_bheap_do_asc_restore(const struct BHeap *const restrict heap,
			      void *const restrict node,
			      const size_t i_node);

inline void bheap_insert(struct BHeap *const restrict heap,
			 void *const restrict node)
{
	++(heap->count);

	if (heap->count == heap->capacity)
		bheap_realloc(heap,
			      heap->capacity * 2ul);

	void *const restrict base = heap->get(heap->nodes,
					      heap->count);
	heap->set(base,
		  node);

	bheap_do_asc_restore(heap,
			     base,
			     heap->count);
}

inline void inv_bheap_insert(struct BHeap *const restrict heap,
			     void *const restrict node)
{
	++(heap->count);

	if (heap->count == heap->capacity)
		bheap_realloc(heap,
			      heap->capacity * 2ul);

	void *const restrict base = heap->get(heap->nodes,
					      heap->count);
	heap->set(base,
		  node);

	inv_bheap_do_asc_restore(heap,
				 base,
				 heap->count);
}


/* access
 * ══════════════════════════════════════════════════════════════════════════ */
inline bool bheap_peek(struct BHeap *const restrict heap,
		       void *const restrict buffer)
{
	if (heap->count == 0ul)
		return false;

	heap->set(buffer,
		  heap->get(heap->nodes,
			    1l));
	return true;
}

#define inv_bheap_peek(HEAP, BUFFER) bheap_peek(HEAP, BUFFER)



/* extraction
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_do_desc_restore(const struct BHeap *const restrict heap,
			   void *const restrict node,
			   const size_t i_node);

void inv_bheap_do_desc_restore(const struct BHeap *const restrict heap,
			       void *const restrict node,
			       const size_t i_node);


inline bool bheap_extract(struct BHeap *const restrict heap,
			  void *const restrict buffer)
{
	if (heap->count == 0ul)
		return false;

	void *const restrict root = heap->get(heap->nodes,
					      1l);

	void *const restrict base = heap->get(heap->nodes,
					      heap->count);

	heap->set(buffer,
		  root);

	heap->set(root,
		  base);

	--(heap->count);

	bheap_do_desc_restore(heap,
			      root,
			      1ul);
	return true;
}


inline bool inv_bheap_extract(struct BHeap *const restrict heap,
			      void *const restrict buffer)
{
	if (heap->count == 0ul)
		return false;

	void *const restrict root = heap->get(heap->nodes,
					      1l);

	void *const restrict base = heap->get(heap->nodes,
					      heap->count);

	heap->set(buffer,
		  root);

	heap->set(root,
		  base);

	--(heap->count);

	inv_bheap_do_desc_restore(heap,
				  root,
				  1ul);
	return true;
}



/* display
 * ══════════════════════════════════════════════════════════════════════════ */
void print_bheap(const struct BHeap *const restrict heap,
		 void (*node_to_string)(char *restrict,
					const void *restrict));




/* heapsort
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_heapsort(void *const array,
		    const size_t length,
		    const size_t width,
		    int (*compare)(const void *,
				   const void *));



/* convienience, misc
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_heapify(struct BHeap *const restrict heap,
		   void *const array,
		   const size_t length,
		   const size_t width,
		   int (*compare)(const void *,
				  const void *));

void inv_bheap_heapify(struct BHeap *const restrict heap,
		       void *const array,
		       const size_t length,
		       const size_t width,
		       int (*compare)(const void *,
				      const void *));

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * TOP-LEVEL FUNCTIONS
 *
 *
 * HELPER FUNCTIONS
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */

/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
 * HELPER FUNCTIONS */

#ifdef __cplusplus /* close 'extern "C" {' */
}
#endif

#endif /* ifndef CONTAINER_QUEUE_BHEAP_H_ */
