#ifndef MEMCPY_DMA_H_
#define MEMCPY_DMA_H_

/*
 *
 */
typedef struct {
  const stm32_dma_stream_t *dma;
} memcpy_dma_engine_t;

/*
 *
 */
#ifdef __cplusplus
extern "C" {
#endif
  void memcpy_dma_start(void);
  void memcpy_dma_stop(void);
  void memcpy_dma(void *dest, const void *src, size_t size);
#ifdef __cplusplus
}
#endif

#endif /* MEMCPY_DMA_H_ */
