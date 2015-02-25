#ifndef MEMBENCH_H_
#define MEMBENCH_H_

/*
 *
 */
typedef struct {
  void    *start;
  size_t  size;
} membench_t;

/*
 * all values in B/s
 */
typedef struct {
  uint32_t  memset;
  uint32_t  memcpy;
  uint32_t  memcpy_dma;
  uint32_t  memcmp;
} membench_result_t;

/*
 *
 */
#ifdef __cplusplus
extern "C" {
#endif
  void membench_run(membench_t *dest, const membench_t *src, membench_result_t *ret);
#ifdef __cplusplus
}
#endif

#endif /* MEMBENCH_H_ */
