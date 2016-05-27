#include <utils/utils.h>
#include "bheap.h"

/* initialize, destroy, resize
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline struct BHeap *bheap_alloc(const size_t capacity,
					const size_t width);

extern inline void bheap_assign_accessors(struct BHeap *const restrict heap);

extern inline void bheap_init(struct BHeap *const restrict heap,
			      int (*compare)(const void *,
					     const void *));

extern inline struct BHeap *bheap_create(const size_t width,
					 int (*compare)(const void *,
							const void *));

extern inline void bheap_free(struct BHeap *restrict heap);


extern inline void bheap_realloc(struct BHeap *const restrict heap,
				 const size_t new_capacity);

/* insertion
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline void bheap_insert(struct BHeap *const restrict heap,
				void *const restrict next);


void bheap_do_insert(const struct BHeap *const restrict heap,
		     void *const restrict node,
		     const size_t i_next)
{
	/* sentinel node has been reached, 'node' is new root node
	 * ────────────────────────────────────────────────────────────────── */
	if (i_next == 1ul) {
		heap->set(heap->get(heap->nodes,
				    1ul),
			  node);
		return;
	}


	const size_t i_parent = i_next / 2ul;
	void *const restrict parent = heap->get(heap->nodes,
						i_parent);

	/* if 'node' belongs below 'parent'
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(parent, node)) {

		heap->set(heap->get(heap->nodes,
				    i_next),
			  node);
	} else {

		heap->set(heap->get(heap->nodes,
				    i_next),
			  parent);

		bheap_do_insert(heap,
				node,
				i_parent);
	}
}




/* extraction
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline bool bheap_extract(struct BHeap *const restrict heap,
				 void *const restrict buffer);

void bheap_do_shift_over(const struct BHeap *const restrict heap,
			 void *const restrict node,
			 const size_t i_next)
{
	const size_t i_lchild = i_next * 2ul;

	/* if base level of heap has been reached (no more children), replace
	 * ────────────────────────────────────────────────────────────────── */
	if (i_lchild > heap->count) {

		heap->set(heap->get(heap->nodes,
				    i_next),
			  node);
		return;
	}

	const size_t i_rchild = i_lchild + 1ul;

	void *const restrict lchild = heap->get(heap->nodes,
						i_lchild);

	/* compare left child with 'node':
	 *
	 * if 'lchild' belongs above 'node'...
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(lchild, node)) {

		/* if base level of heap has been reached (no more children),
		 * place 'node' below 'lchild' and return
		 * ────────────────────────────────────────────────────────── */
		if (i_rchild > heap->count) {
			heap->set(heap->get(heap->nodes,
					    i_next),
				  lchild);

			heap->set(lchild,
				  node);
			return;
		}

		void *const restrict rchild = heap->get(heap->nodes,
							i_rchild);

		/* compare left child with right child:
		 *
		 * if 'lchild' belongs above 'rchild'...
		 * ────────────────────────────────────────────────────────── */
		if (heap->compare(lchild, rchild)) {
			/* place 'lchild' at 'i_next' and continue recursion
			 * down left branch
			 * ────────────────────────────────────────────────── */
			heap->set(heap->get(heap->nodes,
					    i_next),
				  lchild);

			bheap_do_shift_over(heap,
					    node,
					    i_lchild);

		} else {
			/* place 'rchild' at 'i_next' and continue recursion
			 * down right branch
			 * ────────────────────────────────────────────────── */
			heap->set(heap->get(heap->nodes,
					    i_next),
				  rchild);

			bheap_do_shift_over(heap,
					    node,
					    i_rchild);
		}
		return;
	}

	/* if base level of heap has been reached (no more children), place
	 * 'node' above 'lchild' (new base/last element) and return
	 * ────────────────────────────────────────────────────────────────── */
	if (i_rchild > heap->count) {
		heap->set(heap->get(heap->nodes,
				    i_next),
			  node);
		return;
	}

	void *const restrict rchild = heap->get(heap->nodes,
						i_rchild);
	/* compare 'node' with right child:
	 *
	 * if 'rchild' belongs above 'node'...
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(rchild, node)) {

		/* place 'rchild' at 'i_next' and continue recursion down right
		 * branch
		 * ────────────────────────────────────────────────────────── */
		heap->set(heap->get(heap->nodes,
				    i_next),
			  rchild);

		bheap_do_shift_over(heap,
				    node,
				    i_rchild);
	} else {
		/* otherwise, 'node' belongs above lchild and rchild: place at
		 * 'i_next' and return
		 * ────────────────────────────────────────────────────────── */
		heap->set(heap->get(heap->nodes,
				    i_next),
			 node);
	}
}




/* display
 * ══════════════════════════════════════════════════════════════════════════ */
void print_bheap(const struct BHeap *const restrict heap,
		 void (*node_to_string)(char *restrict,
					const void *restrict))
{
	const size_t count = heap->count;

	if (count == 0ul) {
		puts("[ EMPTY ]");
		return;
	}

	char buffer[BHEAP_PRINT_BUFFER_SIZE];

	const void *const restrict nodes = heap->nodes;

	MemoryGet *const get = heap->get;

	for (size_t i = 1ul; i <= count; ++i) {
		node_to_string(&buffer[0],
			       get(nodes, i));

		printf("%zu) {\n%s\n}\n", i, buffer);
	}
}




/* heapsort
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_sort(void *const array,
		const size_t length,
		const size_t width,
		int (*compare)(const void *,
			       const void *))
{
	struct BHeap heap;


	bheap_heapify_min(&heap,
			  array,
			  length,
			  width,
			  compare);


	do {
		heap.swap(array,
			  heap.get(heap.nodes,
				   heap.count));

		--(heap.count);

		bheap_do_shift_swap_min(&heap,
					array,
					1ul);

	} while (heap.count > 1ul);
}


/* convienience, misc
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_do_shift_swap_min(const struct BHeap *const restrict heap,
			     void *const restrict node,
			     const size_t i_node)
{
	const size_t i_lchild = i_node * 2ul;

	/* if base level of heap has been reached (no more children), return
	 * ────────────────────────────────────────────────────────────────── */
	if (i_lchild > heap->count)
		return;

	const size_t i_rchild = i_lchild + 1ul;

	void *const restrict lchild = heap->get(heap->nodes,
						i_lchild);

	/* compare left child with 'node':
	 *
	 * if 'lchild' belongs above 'node'...
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(lchild, node)) {

		/* if base level of heap has been reached (no more children),
		 * swap 'node' with 'lchild' and return
		 * ────────────────────────────────────────────────────────── */
		if (i_rchild > heap->count) {

			heap->swap(node,
				   lchild);
			return;
		}

		void *const restrict rchild = heap->get(heap->nodes,
							i_rchild);

		/* compare left child with right child:
		 *
		 * if 'lchild' belongs above 'rchild'...
		 * ────────────────────────────────────────────────────────── */
		if (heap->compare(lchild, rchild)) {
			/* swap 'lchild' with 'node' and continue recursion
			 * down left branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   lchild);

			bheap_do_shift_swap_min(heap,
						node,
						i_lchild);

		} else {
			/* swap 'rchild' with 'i_node' and continue recursion
			 * down right branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   rchild);

			bheap_do_shift_swap_min(heap,
						node,
						i_rchild);
		}
		return;
	}

	/* if base level of heap has been reached (no more children), return
	 * ────────────────────────────────────────────────────────────────── */
	if (i_rchild > heap->count)
		return;

	void *const restrict rchild = heap->get(heap->nodes,
						i_rchild);
	/* compare 'node' with right child:
	 *
	 * if 'rchild' belongs above 'node'...
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(rchild, node)) {

		/* swap 'rchild' with 'node' and continue recursion down right
		 * branch
		 * ────────────────────────────────────────────────────────── */
		heap->swap(node,
			   rchild);

		bheap_do_shift_swap_min(heap,
					node,
					i_rchild);
	}
	/* otherwise, 'node' belongs above lchild and rchild, return
	 * ────────────────────────────────────────────────────────────────── */
}

void bheap_heapify_min(struct BHeap *const restrict heap,
		       void *const array,
		       const size_t length,
		       const size_t width,
		       int (*compare)(const void *,
				      const void *))
{
	heap->width   = width;

	bheap_assign_accessors(heap);

	heap->compare = compare;

	if (length < 2ul) {
		heap->count = length;
		heap->nodes = heap->get(array,
					-1l);
		return;
	}


	heap->count = 2ul;
	heap->nodes = heap->get(array,
				length - 3l);


	while (1) {
		bheap_do_shift_swap_min(heap,
					heap->get(heap->nodes,
						  1ul),
					1ul);


		PRINT_ARRAY(((int *)array), length, "%d");

		if (heap->count == length)
			return;

		++(heap->count);

		heap->nodes = heap->get(heap->nodes,
					-1l);
	}
}

