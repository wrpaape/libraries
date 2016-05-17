#include "queue.h"

extern inline struct Queue *init_queue(void);

extern inline void queue_push(struct Queue *queue,
			      void *data);

extern inline void *queue_pop(struct Queue *queue);

extern inline void free_queue(struct Queue *queue);
