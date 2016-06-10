#include <utils/utils.h>
#include "bheap.h"

/* create, initialize, clear, destroy, resize
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline void bheap_assign_accessors(struct BHeap *const restrict heap);

extern inline void bheap_init(struct BHeap *const restrict heap,
			      const size_t capacity,
			      const size_t width,
			      int (*compare)(const void *,
					     const void *));

extern inline struct BHeap *bheap_create(const size_t width,
					 int (*compare)(const void *,
							const void *));

extern inline void bheap_clear(struct BHeap *restrict heap);

extern inline void bheap_destroy(struct BHeap *restrict heap);


extern inline void bheap_realloc(struct BHeap *const restrict heap,
				 const size_t new_capacity);

/* insertion
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline void bheap_insert(struct BHeap *const restrict heap,
				void *const restrict next);

extern inline void inv_bheap_insert(struct BHeap *const restrict heap,
				    void *const restrict next);


void bheap_do_asc_restore(const struct BHeap *const restrict heap,
			  void *const restrict node,
			  const size_t i_node)
{
	/* sentinel node has been reached, 'node' is new root node
	 * ────────────────────────────────────────────────────────────────── */
	if (i_node == 1ul)
		return;

	const size_t i_parent = i_node / 2ul;
	void *const restrict parent = heap->get(heap->nodes,
						i_parent);

	/* if 'node' belongs above 'parent', swap then continue to grandparent
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(node, parent) < 0) {

		heap->swap(node,
			   parent);

		bheap_do_asc_restore(heap,
				     parent,
				     i_parent);
	}
}

void inv_bheap_do_asc_restore(const struct BHeap *const restrict heap,
			      void *const restrict node,
			      const size_t i_node)
{
	/* sentinel node has been reached, 'node' is new root node
	 * ────────────────────────────────────────────────────────────────── */
	if (i_node == 1ul)
		return;

	const size_t i_parent = i_node / 2ul;
	void *const restrict parent = heap->get(heap->nodes,
						i_parent);

	/* if 'node' belongs above 'parent', swap then continue to grandparent
	 * ────────────────────────────────────────────────────────────────── */
	if (heap->compare(node, parent) > 0) {

		heap->swap(node,
			   parent);

		inv_bheap_do_asc_restore(heap,
					 parent,
					 i_parent);
	}
}



/* access
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline bool bheap_peek(struct BHeap *const restrict heap,
			      void *const restrict buffer);




/* extraction
 * ══════════════════════════════════════════════════════════════════════════ */
extern inline bool bheap_extract(struct BHeap *const restrict heap,
				 void *const restrict buffer);

extern inline bool inv_bheap_extract(struct BHeap *const restrict heap,
				     void *const restrict buffer);

void bheap_do_desc_restore(const struct BHeap *const restrict heap,
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
	if (heap->compare(lchild, node) < 0) {

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
		if (heap->compare(lchild, rchild) < 0) {
			/* swap 'lchild' with 'node' and continue recursion
			 * down left branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   lchild);

			bheap_do_desc_restore(heap,
					      lchild,
					      i_lchild);

		} else {
			/* swap 'rchild' with 'node' and continue recursion
			 * down right branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   rchild);

			bheap_do_desc_restore(heap,
					      rchild,
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
	if (heap->compare(rchild, node) < 0) {

		/* swap 'rchild' with 'node' and continue recursion down right
		 * branch
		 * ────────────────────────────────────────────────────────── */
		heap->swap(node,
			   rchild);

		bheap_do_desc_restore(heap,
				      rchild,
				      i_rchild);
	}
	/* otherwise, 'node' belongs above lchild and rchild, return
	 * ────────────────────────────────────────────────────────────────── */
}




void inv_bheap_do_desc_restore(const struct BHeap *const restrict heap,
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
	if (heap->compare(lchild, node) > 0) {

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
		if (heap->compare(lchild, rchild) > 0) {

			/* swap 'lchild' with 'node' and continue recursion
			 * down left branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   lchild);

			inv_bheap_do_desc_restore(heap,
						  lchild,
						  i_lchild);

		} else {
			/* swap 'rchild' with 'node' and continue recursion
			 * down right branch
			 * ────────────────────────────────────────────────── */
			heap->swap(node,
				   rchild);

			inv_bheap_do_desc_restore(heap,
						  rchild,
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
	if (heap->compare(rchild, node) > 0) {

		/* swap 'rchild' with 'node' and continue recursion down right
		 * branch
		 * ────────────────────────────────────────────────────────── */
		heap->swap(node,
			   rchild);

		inv_bheap_do_desc_restore(heap,
					  rchild,
					  i_rchild);
	}
	/* otherwise, 'node' belongs above lchild and rchild, return
	 * ────────────────────────────────────────────────────────────────── */
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
void bheap_heapsort(void *const array,
		    const size_t length,
		    const size_t width,
		    int (*compare)(const void *,
				   const void *))
{
	struct BHeap heap;

	inv_bheap_heapify(&heap,
			  array,
			  length,
			  width,
			  compare);

	do {
		heap.swap(array,
			  heap.get(heap.nodes,
				   heap.count));

		--(heap.count);

		inv_bheap_do_desc_restore(&heap,
					  array,
					  1ul);
	} while (heap.count > 1ul);
}


/* convienience, misc
 * ══════════════════════════════════════════════════════════════════════════ */
void bheap_heapify(struct BHeap *const restrict heap,
		   void *const array,
		   const size_t length,
		   const size_t width,
		   int (*compare)(const void *,
				  const void *))
{
	heap->width = width;

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
		bheap_do_desc_restore(heap,
				      heap->get(heap->nodes,
						1l),
				      1ul);

		if (heap->count == length)
			return;

		++(heap->count);

		heap->nodes = heap->get(heap->nodes,
					-1l);
	}
}



void inv_bheap_heapify(struct BHeap *const restrict heap,
		       void *const array,
		       const size_t length,
		       const size_t width,
		       int (*compare)(const void *,
				      const void *))
{
	heap->width = width;

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
		inv_bheap_do_desc_restore(heap,
					  heap->get(heap->nodes,
						    1l),
					  1ul);

		if (heap->count == length)
			return;

		++(heap->count);

		heap->nodes = heap->get(heap->nodes,
					-1l);
	}
}

