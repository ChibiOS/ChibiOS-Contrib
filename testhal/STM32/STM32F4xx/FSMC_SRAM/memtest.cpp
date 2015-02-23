#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include "memtest.hpp"

/*
 *
 */
template <typename T>
class Generator {
public:
  Generator(void) : pattern(0) {;}
  virtual T get(void) = 0;
  virtual void init(T seed) {
    pattern = seed;
  }
protected:
  T pattern;
};

/*
 *
 */
template <typename T>
class GeneratorWalkingOne : public Generator<T> {
  T get(void) {
    T ret = this->pattern;

    this->pattern <<= 1;
    if (0 == this->pattern)
      this->pattern = 1;

    return ret;
  }
};

/*
 *
 */
template <typename T>
class GeneratorWalkingZero : public Generator<T> {
  T get(void) {
    T ret = ~this->pattern;

    this->pattern <<= 1;
    if (0 == this->pattern)
      this->pattern = 1;

    return ret;
  }
};

/*
 *
 */
template <typename T>
class GeneratorOwnAddress : public Generator<T> {
  T get(void) {
    T ret = this->pattern;
    this->pattern++;
    return ret;
  }
};

/*
 *
 */
template <typename T>
class GeneratorMovingInv : public Generator<T> {
  T get(void) {
    T ret = this->pattern;
    this->pattern = ~this->pattern;
    return ret;
  }
};

/*
 *
 */
template <typename T>
class GeneratorMovingInvRand : public Generator<T> {
public:
  GeneratorMovingInvRand(void) : step(0), prev(0){;}
  void init(size_t seed) {
    srand(seed);
  }

  T get(void) {
    T ret;
    if ((step & 1) == 0) {
      ret = rand();
      prev = ret;
    }
    else {
      ret = ~prev;
    }
    step++;

    return ret;
  }

private:
  size_t step;
  T prev;
};

/*
 *
 */
template <typename T>
static void memtest_sequential(memtest_t *memp, Generator<T> &generator, T seed) {
  const size_t steps = memp->size / sizeof(T);
  size_t i;
  T *mem = static_cast<T *>(memp->start);

  /* fill ram */
  generator.init(seed);
  for (i=0; i<steps; i++) {
    mem[i] = generator.get();
  }

  /* read back and compare */
  generator.init(seed);
  for (i=0; i<steps; i++) {
    if (mem[i] != generator.get()) {
      memp->ecb(memp, MEMTEST_WALKING_ONE, i*sizeof(T));
      return;
    }
  }
}

template <typename T>
static void walking_one(memtest_t *memp) {
  GeneratorWalkingOne<T> generator;
  memtest_sequential<T>(memp, generator, 1);
}

template <typename T>
static void walking_zero(memtest_t *memp) {
  GeneratorWalkingZero<T> generator;
  memtest_sequential<T>(memp, generator, 1);
}

template <typename T>
static void own_address(memtest_t *memp) {
  GeneratorOwnAddress<T> generator;
  memtest_sequential<T>(memp, generator, 0);
}

template <typename T>
static void moving_inversion(memtest_t *memp) {
  GeneratorMovingInv<T> generator;
  memtest_sequential<T>(memp, generator, 0);
}

template <typename T>
static void moving_inversion_rand(memtest_t *memp) {
  GeneratorMovingInvRand<T> generator;
  memtest_sequential<T>(memp, generator, memp->rand_seed);
}

/*
 *
 */
static void memtest_wrapper(memtest_t *memp,
                            void (*p_u8)(memtest_t *memp),
                            void (*p_u16)(memtest_t *memp),
                            void (*p_u32)(memtest_t *memp)) {
  switch(memp->width){
  case MEMTEST_WIDTH_32:
    p_u32(memp);
    p_u16(memp);
    p_u8(memp);
    break;
  case MEMTEST_WIDTH_16:
    p_u16(memp);
    p_u8(memp);
    break;
  case MEMTEST_WIDTH_8:
    p_u8(memp);
    break;
  }
}

/*
 *
 */
void memtest_run(memtest_t *memp, uint32_t testmask) {

  if ((testmask & MEMTEST_WALKING_ONE) == MEMTEST_WALKING_ONE) {
    memtest_wrapper(memp,
        walking_one<uint32_t>,
        walking_one<uint16_t>,
        walking_one<uint8_t>);
  }

  if ((testmask & MEMTEST_WALKING_ZERO) == MEMTEST_WALKING_ZERO) {
    memtest_wrapper(memp,
        walking_zero<uint32_t>,
        walking_zero<uint16_t>,
        walking_zero<uint8_t>);
  }

  if ((testmask & MEMTEST_OWN_ADDRESS) == MEMTEST_OWN_ADDRESS) {
    memtest_wrapper(memp,
        own_address<uint32_t>,
        own_address<uint16_t>,
        own_address<uint8_t>);
  }

  if ((testmask & MEMTEST_MOVING_INVERSION) == MEMTEST_MOVING_INVERSION) {
    memtest_wrapper(memp,
        moving_inversion<uint32_t>,
        moving_inversion<uint16_t>,
        moving_inversion<uint8_t>);
  }

  if ((testmask & MEMTEST_MOVING_INVERSION_RAND) == MEMTEST_MOVING_INVERSION_RAND) {
    memtest_wrapper(memp,
        moving_inversion_rand<uint32_t>,
        moving_inversion_rand<uint16_t>,
        moving_inversion_rand<uint8_t>);
  }
}

