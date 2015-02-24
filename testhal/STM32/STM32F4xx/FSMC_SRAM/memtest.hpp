#ifndef MEMTEST_HPP_
#define MEMTEST_HPP_

#define MEMTEST_WALKING_ONE               (1 << 0)
#define MEMTEST_WALKING_ZERO              (1 << 1)
#define MEMTEST_OWN_ADDRESS               (1 << 2)
#define MEMTEST_MOVING_INVERSION_ZERO     (1 << 3)
#define MEMTEST_MOVING_INVERSION_55AA     (1 << 4)
#define MEMTEST_MOVING_INVERSION_RAND     (1 << 5)

#define MEMTEST_RUN_ALL                   (MEMTEST_WALKING_ONE | \
                                           MEMTEST_WALKING_ZERO | \
                                           MEMTEST_OWN_ADDRESS | \
                                           MEMTEST_MOVING_INVERSION_ZERO | \
                                           MEMTEST_MOVING_INVERSION_55AA | \
                                           MEMTEST_MOVING_INVERSION_RAND)

typedef struct memtest_t memtest_t;
typedef uint32_t testtype_t;

/*
 * Error call back.
 */
typedef void (*memtestecb_t)(memtest_t *memp, testtype_t e, size_t address);

/*
 *
 */
typedef enum {
  MEMTEST_WIDTH_8,
  MEMTEST_WIDTH_16,
  MEMTEST_WIDTH_32
} memtest_bus_width_t;

/*
 *
 */
struct memtest_t {
  void                *start;
  size_t              size;
  memtest_bus_width_t width;
  memtestecb_t        ecb;
  unsigned int        rand_seed;
};

/*
 *
 */
#ifdef __cplusplus
extern "C" {
#endif
  void memtest_run(memtest_t *memp, uint32_t testmask);
#ifdef __cplusplus
}
#endif

#endif /* MEMTEST_HPP_ */
