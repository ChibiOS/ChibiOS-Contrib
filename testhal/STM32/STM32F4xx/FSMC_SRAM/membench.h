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
 *
 */
typedef struct {
  double  memset_spd;
  double  memcpy_spd;
  double  memcmp_spd;
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
