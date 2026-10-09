#ifndef HAL_LESENSE_LLD_H
#define HAL_LESENSE_LLD_H

struct LESENSEDriver {
};

typedef struct LESENSEDriver LESENSEDriver;

#ifdef __cplusplus
extern "C" {
#endif

  void lesenseInit(void);
  void lesenseObjectInit(LESENSEDriver *lesensep);

#ifdef __cplusplus
}
#endif

#endif /* HAL_LESENSE_LLD_H */
