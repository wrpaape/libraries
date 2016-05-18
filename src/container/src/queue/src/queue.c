#include "queue.h"

/* basic LIFO queue interface */

extern inline struct Queue *queue_alloc(void);

extern inline void queue_init(struct Queue *queue);

extern inline struct Queue *queue_create(void);

extern inline void queue_push(struct Queue *queue,
			      void *data);

extern inline void *queue_peek(struct Queue *queue);

extern inline void *queue_pop(struct Queue *queue);

extern inline void queue_free(struct Queue *queue);
