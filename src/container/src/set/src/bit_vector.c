#include "bit_vector.h"

extern inline void
get_bit_point(struct BitPoint *const restrict point,
	      const struct BitVector *const restrict set,
	      const int x);

extern inline void
bit_vector_init(struct BitVector *const restrict set,
		const int min,
		const int max);

extern inline struct BitVector *
bit_vector_create(const int min,
		  const int max);



extern inline void
bit_vector_free_buckets(struct BitVector *restrict set);

extern inline void
bit_vector_free(struct BitVector *restrict set);



extern inline bool
bit_vector_is_ib(const struct BitVector *const restrict set,
		 const int x);

extern inline bool
bit_vector_is_ob(const struct BitVector *const restrict set,
		 const int x);



extern inline bool
bit_vector_member_ib(const struct BitVector *const restrict set,
		     const int x);

extern inline bool
bit_vector_member(const struct BitVector *const restrict set,
		  const int x);

extern inline bool
bit_vector_handle_member(const struct BitVector *const restrict set,
			 const int x);



extern inline bool
bit_vector_put_ib(struct BitVector *const restrict set,
		  const int x);

extern inline bool
bit_vector_put(struct BitVector *const restrict set,
	       const int x);

extern inline bool
bit_vector_handle_put(struct BitVector *const restrict set,
		      const int x);
