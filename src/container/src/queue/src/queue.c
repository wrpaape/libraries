#include "queue.h"

/* basic LIFO queue interface */

extern inline void queue_init(struct Queue *const restrict queue);

extern inline struct Queue *restrict queue_create(void);

extern inline void queue_push(struct Queue *const restrict queue,
			      void *data);

extern inline void *queue_peek(const struct Queue *const restrict queue);

extern inline void *queue_pop(struct Queue *const restrict queue);

inline void queue_clear(struct Queue *const restrict queue);

extern inline void queue_destroy(struct Queue *restrict queue);
