/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    OTGv1/at32_otg.h
 * @brief   AT32 OTG registers layout header.
 *
 * @addtogroup USB
 * @{
 */

#ifndef AT32_OTG_H
#define AT32_OTG_H

/**
 * @brief   OTG_FS FIFO memory size in words.
 */
#define AT32_OTG1_FIFO_MEM_SIZE         320

/**
 * @brief   OTG_HS FIFO memory size in words.
 */
#define AT32_OTG2_FIFO_MEM_SIZE         1024

/**
 * @brief   Host channel registers group.
 */
typedef struct {
  volatile uint32_t HCCHAR;     /**< @brief Host channel characteristics
                                            register.                       */
  volatile uint32_t HCSPLT;     /**< @brief Host channel split register.    */
  volatile uint32_t HCINT;      /**< @brief Host channel interrupt register.*/
  volatile uint32_t HCINTMSK;   /**< @brief Host channel interrupt mask
                                            register.                       */
  volatile uint32_t HCTSIZ;     /**< @brief Host channel transfer size
                                            register.                       */
  volatile uint32_t HCDMA;      /**< @brief Host channel DMA address
                                            register.                       */
  volatile uint32_t resvd18;
  volatile uint32_t resvd1c;
} at32_otg_host_chn_t;

/**
 * @brief   Device input endpoint registers group.
 */
typedef struct {
  volatile uint32_t DIEPCTL;    /**< @brief Device control IN endpoint
                                            control register.               */
  volatile uint32_t resvd4;
  volatile uint32_t DIEPINT;    /**< @brief Device IN endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DIEPTSIZ;   /**< @brief Device IN endpoint transfer size
                                            register.                       */
  volatile uint32_t DIEPDMA;    /**< @brief Device IN endpoint DMA address
                                            register.                       */
  volatile uint32_t DTXFSTS;    /**< @brief Device IN endpoint transmit FIFO
                                            status register.                */
  volatile uint32_t resvd1C;
} at32_otg_in_ep_t;

/**
 * @brief   Device output endpoint registers group.
 */
typedef struct {
  volatile uint32_t DOEPCTL;    /**< @brief Device control OUT endpoint
                                            control register.               */
  volatile uint32_t resvd4;
  volatile uint32_t DOEPINT;    /**< @brief Device OUT endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DOEPTSIZ;   /**< @brief Device OUT endpoint transfer
                                            size register.                  */
  volatile uint32_t DOEPDMA;    /**< @brief Device OUT endpoint DMA address
                                            register.                       */
  volatile uint32_t resvd18;
  volatile uint32_t resvd1C;
} at32_otg_out_ep_t;

/**
 * @brief   USB registers memory map.
 */
typedef struct {
  volatile uint32_t GOTGCTL;    /**< @brief OTG control and status register.*/
  volatile uint32_t GOTGINT;    /**< @brief OTG interrupt register.         */
  volatile uint32_t GAHBCFG;    /**< @brief AHB configuration register.     */
  volatile uint32_t GUSBCFG;    /**< @brief USB configuration register.     */
  volatile uint32_t GRSTCTL;    /**< @brief Reset register size.            */
  volatile uint32_t GINTSTS;    /**< @brief Interrupt register.             */
  volatile uint32_t GINTMSK;    /**< @brief Interrupt mask register.        */
  volatile uint32_t GRXSTSR;    /**< @brief Receive status debug read
                                            register.                       */
  volatile uint32_t GRXSTSP;    /**< @brief Receive status read/pop
                                            register.                       */
  volatile uint32_t GRXFSIZ;    /**< @brief Receive FIFO size register.     */
  volatile uint32_t DIEPTXF0;   /**< @brief Endpoint 0 transmit FIFO size
                                            register.                       */
  volatile uint32_t GNPTXSTS;   /**< @brief Non-periodic TxFIFO size/request
                                            queue status register.          */
  volatile uint32_t resvd30;
  volatile uint32_t resvd34;
  volatile uint32_t GCCFG;      /**< @brief General controller config.      */
  volatile uint32_t GUID;       /**< @brief Controller ID register.         */
  volatile uint32_t resvd58[48];
  volatile uint32_t HPTXFSIZ;   /**< @brief Host periodic transmit FIFO size
                                            register.                       */
  volatile uint32_t DIEPTXF[15];/**< @brief Device IN endpoint transmit FIFO
                                            size registers.                 */
  volatile uint32_t resvd140[176];
  volatile uint32_t HCFG;       /**< @brief Host configuration register.    */
  volatile uint32_t HFIR;       /**< @brief Host frame interval register.   */
  volatile uint32_t HFNUM;      /**< @brief Host frame number/frame time
                                            Remaining register.             */
  volatile uint32_t resvd40C;
  volatile uint32_t HPTXSTS;    /**< @brief Host periodic transmit FIFO/queue
                                            status register.                */
  volatile uint32_t HAINT;      /**< @brief Host all channels interrupt
                                            register.                       */
  volatile uint32_t HAINTMSK;   /**< @brief Host all channels interrupt mask
                                            register.                       */
  volatile uint32_t resvd41C[9];
  volatile uint32_t HPRT;       /**< @brief Host port control and status
                                            register.                       */
  volatile uint32_t resvd444[47];
  at32_otg_host_chn_t hc[16];   /**< @brief Host channels array.            */
  volatile uint32_t resvd700[64];
  volatile uint32_t DCFG;       /**< @brief Device configuration register.  */
  volatile uint32_t DCTL;       /**< @brief Device control register.        */
  volatile uint32_t DSTS;       /**< @brief Device status register.         */
  volatile uint32_t resvd80C;
  volatile uint32_t DIEPMSK;    /**< @brief Device IN endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DOEPMSK;    /**< @brief Device OUT endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DAINT;      /**< @brief Device all endpoints interrupt
                                            register.                       */
  volatile uint32_t DAINTMSK;   /**< @brief Device all endpoints interrupt
                                            mask register.                  */
  volatile uint32_t resvd820;
  volatile uint32_t resvd824;
  volatile uint32_t resvd828;
  volatile uint32_t resvd82C;
  volatile uint32_t resvd830;
  volatile uint32_t DIEPEMPMSK; /**< @brief Device IN endpoint FIFO empty
                                            interrupt mask register.        */
  volatile uint32_t DEACHINT;   /**< @brief Device all endpoints interrupt
                                            register.                       */
  volatile uint32_t DEACHINTMSK; /**< @brief Device all endpoints interrupt
                                             mask register.                 */
  volatile uint32_t resvd840;
  volatile uint32_t DIEPEACHMSK1; /**< @brief Device IN endpoint 1
                                              interrupt mask register.      */
  volatile uint32_t resvd848[14];
  volatile uint32_t resvd880;
  volatile uint32_t DOEPEACHMSK1; /**< @brief Device OUT endpoint 1
                                              interrupt mask register.      */
  volatile uint32_t resvd888[14];
  volatile uint32_t resvd8C0[16];
  at32_otg_in_ep_t ie[16];      /**< @brief Input endpoints.                */
  at32_otg_out_ep_t oe[16];     /**< @brief Output endpoints.               */
  volatile uint32_t resvdD00[64];
  volatile uint32_t PCGCCTL;    /**< @brief Power and clock gating control
                                            register.                       */
  volatile uint32_t resvdE04[127];
  volatile uint32_t FIFO[16][1024];
} at32_otg_t;

/**
 * @name GOTGCTL register bit definitions
 * @{
 */
#define GOTGCTL_CURMOD          (1U << 21)  /**< Current mode of operation. */
#define GOTGCTL_CONIDSTS        (1U << 16)  /**< Connector ID status.       */
/** @} */

/**
 * @name GOTGINT register bit definitions
 * @{
 */
#define GOTGINT_SESENDDET       (1U << 2)   /**< Session end detected.      */
/** @} */

/**
 * @name GAHBCFG register bit definitions
 * @{
 */
#define GAHBCFG_PTXFEMPLVL      (1U << 8)   /**< Periodic TxFIFO empty
                                                 level.                     */
#define GAHBCFG_NPTXFEMPLVL     (1U << 7)   /**< Non-periodic TxFIFO empty
                                                 level.                     */
#define GAHBCFG_DMAEN           (1U << 5)   /**< DMA enable (HS only).      */
#define GAHBCFG_HBSTLEN_MASK    (15U << 1)  /**< Burst length/type mask (HS
                                                 only).                     */
#define GAHBCFG_HBSTLEN(n)      ((n) << 1)  /**< Burst length/type (HS
                                                 only).                     */
#define GAHBCFG_GLBINTMSK       (1U << 0)   /**< Global interrupt mask.     */
/** @} */

/**
 * @name GUSBCFG register bit definitions
 * @{
 */
#define GUSBCFG_COTXPKT         (1U << 31)  /**< Corrupt Tx packet.         */
#define GUSBCFG_FDEVMODE        (1U << 30)  /**< Force Device Mode.         */
#define GUSBCFG_FHSTMODE        (1U << 29)  /**< Force Host Mode.           */
#define GUSBCFG_USBTRDTIM_MASK  (15U << 10) /**< USB Turnaround time field
                                                 mask.                      */
#define GUSBCFG_USBTRDTIM(n)    ((n) << 10) /**< USB Turnaround time field
                                                 value.                     */
#define GUSBCFG_PHYSEL          (1U << 6)   /**< USB 2.0 High-Speed PHY or
                                                 USB 1.1 Full-Speed serial
                                                 transceiver Select.        */
#define GUSBCFG_TOUTCAL_MASK    (7U << 0)   /**< HS/FS timeout calibration
                                                 field mask.                */
#define GUSBCFG_TOUTCAL(n)      ((n) << 0)  /**< HS/FS timeout calibration
                                                 field value.               */
/** @} */

/**
 * @name GRSTCTL register bit definitions
 * @{
 */
#define GRSTCTL_AHBIDLE         (1U << 31)  /**< AHB master Idle.           */
#define GRSTCTL_TXFNUM_MASK     (31U << 6)  /**< TxFIFO number field mask.  */
#define GRSTCTL_TXFNUM(n)       ((n) << 6)  /**< TxFIFO number field value. */
#define GRSTCTL_TXFFLSH         (1U << 5)   /**< TxFIFO flush.              */
#define GRSTCTL_RXFFLSH         (1U << 4)   /**< RxFIFO flush.              */
#define GRSTCTL_FRMCNTRST       (1U << 2)   /**< Host frame counter reset.  */
#define GRSTCTL_PIUSFTRST       (1U << 1)   /**< PIU FS dedicated control
                                                 soft reset.                */
#define GRSTCTL_CSFTRST         (1U << 0)   /**< Controller soft reset.     */
/** @} */

/**
 * @name GINTSTS register bit definitions
 * @{
 */
#define GINTSTS_WKUPINT         (1U << 31)  /**< Resume/Remote wakeup
                                                 detected interrupt.        */
#define GINTSTS_DISCONINT       (1U << 29)  /**< Disconnect detected
                                                 interrupt.                 */
#define GINTSTS_CONIDSCHG       (1U << 28)  /**< Connector ID status change.*/
#define GINTSTS_PTXFEMP         (1U << 26)  /**< Periodic TxFIFO empty.     */
#define GINTSTS_HCHINT          (1U << 25)  /**< Host channels interrupt.   */
#define GINTSTS_PRTINT          (1U << 24)  /**< Host port interrupt.       */
#define GINTSTS_INCOMPIP        (1U << 21)  /**< Incomplete periodic
                                                 transfer.                  */
#define GINTSTS_INCOMPISOOUT    (1U << 21)  /**< Incomplete isochronous OUT
                                                 transfer.                  */
#define GINTSTS_INCOMPISOIN     (1U << 20)  /**< Incomplete isochronous IN
                                                 transfer.                  */
#define GINTSTS_OEPTINT         (1U << 19)  /**< OUT endpoints interrupt.   */
#define GINTSTS_IEPTINT         (1U << 18)  /**< IN endpoints interrupt.    */
#define GINTSTS_EOPF            (1U << 15)  /**< End of periodic frame
                                                 interrupt.                 */
#define GINTSTS_ISOOUTDROP      (1U << 14)  /**< Isochronous OUT packet
                                                 dropped interrupt.         */
#define GINTSTS_ENUMDONE        (1U << 13)  /**< Enumeration done.          */
#define GINTSTS_USBRST          (1U << 12)  /**< USB reset.                 */
#define GINTSTS_USBSUSP         (1U << 11)  /**< USB suspend.               */
#define GINTSTS_ERLYSUSP        (1U << 10)  /**< Early suspend.             */
#define GINTSTS_GOUTNAKEFF      (1U << 7)   /**< Global OUT NAK effective.  */
#define GINTSTS_GINNAKEFF       (1U << 6)   /**< Global IN non-periodic NAK
                                                 effective.                 */
#define GINTSTS_NPTXFEMP        (1U << 5)   /**< Non-periodic TxFIFO empty. */
#define GINTSTS_RXFLVL          (1U << 4)   /**< RxFIFO non-empty.          */
#define GINTSTS_SOF             (1U << 3)   /**< Start of frame.            */
#define GINTSTS_OTGINT          (1U << 2)   /**< OTG interrupt.             */
#define GINTSTS_MODEMIS         (1U << 1)   /**< Mode mismatch interrupt.   */
#define GINTSTS_CURMOD          (1U << 0)   /**< Current mode of operation. */
/** @} */

/**
 * @name GINTMSK register bit definitions
 * @{
 */
#define GINTMSK_WKUPINTMSK      (1U << 31)  /**< Resume/remote wakeup
                                                 detected interrupt mask.   */
#define GINTMSK_DISCONINTMSK    (1U << 29)  /**< Disconnect detected
                                                 interrupt mask.            */
#define GINTMSK_CONIDSCHGMSK    (1U << 28)  /**< Connector ID status change
                                                 mask.                      */
#define GINTMSK_PTXFEMPMSK      (1U << 26)  /**< Periodic TxFIFO empty mask.*/
#define GINTMSK_HCHINTMSK       (1U << 25)  /**< Host channels interrupt
                                                 mask.                      */
#define GINTMSK_PRTINTMSK       (1U << 24)  /**< Host port interrupt mask.  */
#define GINTMSK_INCOMPIPMSK     (1U << 21)  /**< Incomplete periodic
                                                 transfer mask.             */
#define GINTMSK_INCOMPISOOUTMSK (1U << 21)  /**< Incomplete isochronous OUT
                                                 transfer mask.             */
#define GINTMSK_INCOMISOINMSK   (1U << 20)  /**< Incomplete isochronous IN
                                                 transfer mask.             */
#define GINTMSK_OEPTINTMSK      (1U << 19)  /**< OUT endpoints interrupt
                                                 mask.                      */
#define GINTMSK_IEPTINTMSK      (1U << 18)  /**< IN endpoints interrupt
                                                 mask.                      */
#define GINTMSK_EOPFMSK         (1U << 15)  /**< End of periodic frame
                                                 interrupt mask.            */
#define GINTMSK_ISOOUTDROPMSK   (1U << 14)  /**< Isochronous OUT packet
                                                 dropped interrupt mask.    */
#define GINTMSK_ENUMDONEMSK     (1U << 13)  /**< Enumeration done mask.     */
#define GINTMSK_USBRSTMSK       (1U << 12)  /**< USB reset mask.            */
#define GINTMSK_USBSUSPMSK      (1U << 11)  /**< USB suspend interrupt
                                                 mask.                      */
#define GINTMSK_ERLYSUSPMSK     (1U << 10)  /**< Early suspend interrupt
                                                 mask.                      */
#define GINTMSK_GOUTNAKEFFMSK   (1U << 7)   /**< Global OUT NAK effective
                                                 mask.                      */
#define GINTMSK_GINNAKEFFMSK    (1U << 6)   /**< Global non-periodic IN NAK
                                                 effective mask.            */
#define GINTMSK_NPTXFEMPMSK     (1U << 5)   /**< Non-periodic TxFIFO empty
                                                 mask.                      */
#define GINTMSK_RXFLVLMSK       (1U << 4)   /**< Receive FIFO non-empty
                                                 mask.                      */
#define GINTMSK_SOFMSK          (1U << 3)   /**< Start of Frame mask.       */
#define GINTMSK_OTGINTMSK       (1U << 2)   /**< OTG interrupt mask.        */
#define GINTMSK_MODEMISMSK      (1U << 1)   /**< Mode mismatch interrupt
                                                 mask.                      */
/** @} */

/**
 * @name GRXSTSR register bit definitions
 * @{
 */
#define GRXSTSR_PKTSTS_MASK     (15U << 17) /**< Packet status mask.        */
#define GRXSTSR_PKTSTS(n)       ((n) << 17) /**< Packet status value.       */
#define GRXSTSR_OUT_GLOBAL_NAK  GRXSTSR_PKTSTS(1)
#define GRXSTSR_OUT_DATA        GRXSTSR_PKTSTS(2)
#define GRXSTSR_OUT_COMP        GRXSTSR_PKTSTS(3)
#define GRXSTSR_SETUP_COMP      GRXSTSR_PKTSTS(4)
#define GRXSTSR_SETUP_DATA      GRXSTSR_PKTSTS(6)
#define GRXSTSR_DPID_MASK       (3U << 15)  /**< Data PID mask.             */
#define GRXSTSR_DPID(n)         ((n) << 15) /**< Data PID value.            */
#define GRXSTSR_BCNT_MASK       (0x7FFU << 4) /**< Byte count mask.         */
#define GRXSTSR_BCNT(n)         ((n) << 4)  /**< Byte count value.          */
#define GRXSTSR_CHNUM_MASK      (15U << 0)  /**< Channel number mask.       */
#define GRXSTSR_CHNUM(n)        ((n) << 0)  /**< Channel number value.      */
#define GRXSTSR_EPTNUM_MASK     (15U << 0)  /**< Endpoint number mask.      */
#define GRXSTSR_EPTNUM(n)       ((n) << 0)  /**< Endpoint number value.     */
/** @} */

/**
 * @name GRXSTSP register bit definitions
 * @{
 */
#define GRXSTSP_PKTSTS_MASK     (15U << 17) /**< Packet status mask.        */
#define GRXSTSP_PKTSTS(n)       ((n) << 17) /**< Packet status value.       */
#define GRXSTSP_OUT_GLOBAL_NAK  GRXSTSP_PKTSTS(1)
#define GRXSTSP_OUT_DATA        GRXSTSP_PKTSTS(2)
#define GRXSTSP_OUT_COMP        GRXSTSP_PKTSTS(3)
#define GRXSTSP_SETUP_COMP      GRXSTSP_PKTSTS(4)
#define GRXSTSP_SETUP_DATA      GRXSTSP_PKTSTS(6)
#define GRXSTSP_DPID_MASK       (3U << 15)  /**< Data PID mask.             */
#define GRXSTSP_DPID(n)         ((n) << 15) /**< Data PID value.            */
#define GRXSTSP_BCNT_MASK       (0x7FFU << 4) /**< Byte count mask.         */
#define GRXSTSP_BCNT_OFF        4           /**< Byte count offset.         */
#define GRXSTSP_BCNT(n)         ((n) << 4)  /**< Byte count value.          */
#define GRXSTSP_CHNUM_MASK      (15U << 0)  /**< Channel number mask.       */
#define GRXSTSP_CHNUM(n)        ((n) << 0)  /**< Channel number value.      */
#define GRXSTSP_EPTNUM_MASK     (15U << 0)  /**< Endpoint number mask.      */
#define GRXSTSP_EPTNUM_OFF      0           /**< Endpoint number offset.    */
#define GRXSTSP_EPTNUM(n)       ((n) << 0)  /**< Endpoint number value.     */
/** @} */

/**
 * @name GRXFSIZ register bit definitions
 * @{
 */
#define GRXFSIZ_RXFDEP_MASK     (0xFFFFU << 0) /**< RxFIFO depth mask.      */
#define GRXFSIZ_RXFDEP(n)       ((n) << 0)  /**< RxFIFO depth value.        */
/** @} */

/**
 * @name DIEPTXFx register bit definitions
 * @{
 */
#define DIEPTXF_INEPTXFDEP_MASK (0xFFFFU << 16) /**< IN endpoint TxFIFO
                                                     depth mask.            */
#define DIEPTXF_INEPTXFDEP(n)   ((n) << 16)     /**< IN endpoint TxFIFO depth
                                                     depth value.           */
#define DIEPTXF_INEPTXFSTADDR_MASK (0xFFFFU << 0) /**< IN endpoint FIFOx
                                                       transmit SRAM start
													   address mask.        */
#define DIEPTXF_INEPTXFSTADDR(n) ((n) << 0)     /**< IN endpoint FIFOx
                                                     transmit SRAM start
                                                     address mask.          */
/** @} */

/**
 * @name GCCFG register bit definitions
 * @{
 */
#define GCCFG_WAIT_CLK_RCV      (1U << 22)  /**< Wait clksoure recover (HS
                                                 only).                     */
#define GCCFG_VBUSIG            (1U << 21)  /**< VBUS ignored.              */
#define GCCFG_SOFOUTEN          (1U << 20)  /**< SOF output enable.         */
#define GCCFG_BVALIDSESEN       (1U << 19)  /**< B valid sensing enable.    */
#define GCCFG_AVALIDSESEN       (1U << 18)  /**< A valid sensing enable.    */
#define GCCFG_LP_MODE           (1U << 17)  /**< Low-power mode.            */
#define GCCFG_PWRDOWN           (1U << 16)  /**< Power down.                */
/** @} */

/**
 * @name HPTXFSIZ register bit definitions
 * @{
 */
#define HPTXFSIZ_PTXFSIZE_MASK  (0xFFFFU << 16) /**< Host periodic TxFIFO
                                                     depth mask.            */
#define HPTXFSIZ_PTXFSIZE(n)    ((n) << 16)     /**< Host periodic TxFIFO
                                                     depth value.           */
#define HPTXFSIZ_PTXFSTADDR_MASK (0xFFFFU << 0) /**< Host periodic TxFIFO
                                                     start address mask.    */
#define HPTXFSIZ_PTXFSTADDR(n)  ((n) << 0)      /**< Host periodic TxFIFO
                                                     start address value.   */
/** @} */

/**
 * @name HCFG register bit definitions
 * @{
 */
#define HCFG_FSLSSUPP           (1U << 2)   /**< FS- and LS-only support.   */
#define HCFG_FSLSPCLKSEL_MASK   (3U << 0)   /**< FS/LS PHY clock select
                                                 mask.                      */
#define HCFG_FSLSPCLKSEL_48     (1U << 0)   /**< PHY clock is running at
                                                 48 MHz.                    */
#define HCFG_FSLSPCLKSEL_6      (2U << 0)   /**< PHY clock is running at
                                                 6 MHz.                     */
/** @} */

/**
 * @name HFIR register bit definitions
 * @{
 */
#define HFIR_FRINT_MASK         (0xFFFFU << 0) /**< Frame interval mask.    */
#define HFIR_FRINT(n)           ((n) << 0)     /**< Frame interval value.   */
/** @} */

/**
 * @name HFNUM register bit definitions
 * @{
 */
#define HFNUM_FTREM_MASK        (0xFFFFU << 16) /**< Frame time remaining
                                                     mask.                  */
#define HFNUM_FTREM(n)          ((n) << 16)     /**< Frame time remaining
                                                     value.                 */
#define HFNUM_FRNUM_MASK        (0xFFFFU << 0)  /**< Frame number mask.     */
#define HFNUM_FRNUM(n)          ((n) << 0)      /**< Frame number value.    */
/** @} */

/**
 * @name HPTXSTS register bit definitions
 * @{
 */
#define HPTXSTS_PTXQTOP_MASK    (0xFFU << 24)   /**< Top of the periodic
                                                     transmit request queue
                                                     mask.                  */
#define HPTXSTS_PTXQTOP(n)      ((n) << 24)     /**< Top of the periodic
                                                     transmit request queue
                                                     value.                 */
#define HPTXSTS_PTXQSPCAVAIL_MASK (0xFF<< 16)   /**< Periodic transmit request
                                                     queue space available
                                                     mask.                  */
#define HPTXSTS_PTXQSPCAVAIL(n) ((n) << 16)     /**< Periodic transmit request
                                                     queue space available
                                                     value.                 */
#define HPTXSTS_PTXFSPCAVAIL_MASK (0xFFFF<< 0)  /**< Periodic transmit data
                                                     FIFO space available
                                                     mask.                  */
#define HPTXSTS_PTXFSPCAVAIL(n) ((n) << 0)      /**< Periodic transmit data
                                                     FIFO space available
                                                     value.                 */
/** @} */

/**
 * @name HAINT register bit definitions
 * @{
 */
#define HAINT_HAINT_MASK        (0xFFFFU << 0)  /**< Channel interrupts
                                                     mask.                  */
#define HAINT_HAINT(n)          ((n) << 0)      /**< Channel interrupts
                                                     value.                 */
/** @} */

/**
 * @name HAINTMSK register bit definitions
 * @{
 */
#define HAINTMSK_HAINTMSK_MASK  (0xFFFFU << 0)  /**< Channel interrupt mask
                                                     mask.                  */
#define HAINTMSK_HAINTMSK(n)    ((n) << 0)      /**< Channel interrupt mask
                                                     value.                 */
/** @} */

/**
 * @name HPRT register bit definitions
 * @{
 */
#define HPRT_PRTSPD_MASK        (3U << 17)  /**< Port speed mask.           */
#define HPRT_PRTSPD_FS          (1U << 17)  /**< Full speed value.          */
#define HPRT_PRTSPD_LS          (2U << 17)  /**< Low speed value.           */
#define HPRT_PRTTSTCTL_MASK     (15U << 13) /**< Port test control mask.    */
#define HPRT_PRTTSTCTL(n)       ((n) << 13) /**< Port test control value.   */
#define HPRT_PRTPWR             (1U << 12)  /**< Port power.                */
#define HPRT_PRTLNSTS_MASK      (3U << 11)  /**< Port line status mask.     */
#define HPRT_PRTLNSTS_DM        (1U << 11)  /**< Logic level of D-.         */
#define HPRT_PRTLNSTS_DP        (1U << 10)  /**< Logic level of D+.         */
#define HPRT_PRTRST             (1U << 8)   /**< Port reset.                */
#define HPRT_PRTSUSP            (1U << 7)   /**< Port suspend.              */
#define HPRT_PRTRES             (1U << 6)   /**< Port resume.               */
#define HPRT_PRTOVRCCHNG        (1U << 5)   /**< Port overcurrent change.   */
#define HPRT_PRTOVRCACT         (1U << 4)   /**< Port overcurrent active.   */
#define HPRT_PRTENCHNG          (1U << 3)   /**< Port enable/disable change.*/
#define HPRT_PRTENA             (1U << 2)   /**< Port enable.               */
#define HPRT_PRTCONDET          (1U << 1)   /**< Port connect detected.     */
#define HPRT_PRTCONSTS          (1U << 0)   /**< Port connect status.       */
/** @} */

/**
 * @name HCCHAR register bit definitions
 * @{
 */
#define HCCHAR_CHENA            (1U << 31)  /**< Channel enable.            */
#define HCCHAR_CHDIS            (1U << 30)  /**< Channel disable.           */
#define HCCHAR_ODDFRM           (1U << 29)  /**< Odd frame.                 */
#define HCCHAR_DEVADDR_MASK     (0x7FU << 22) /**< Device address mask.     */
#define HCCHAR_DEVADDR(n)       ((n) << 22) /**< Device address value.      */
#define HCCHAR_MC_MASK          (3U << 20)  /**< Multi count mask.          */
#define HCCHAR_MC(n)            ((n) << 20) /**< Multi count value.         */
#define HCCHAR_EPTYPE_MASK      (3U << 18)  /**< Endpoint type mask.        */
#define HCCHAR_EPTYPE(n)        ((n) << 18) /**< Endpoint type value.       */
#define HCCHAR_EPTYPE_CTL       (0U << 18)  /**< Control transfer value.    */
#define HCCHAR_EPTYPE_ISO       (1U << 18)  /**< Isochronous transfer value.*/
#define HCCHAR_EPTYPE_BULK      (2U << 18)  /**< Bulk transfer value.       */
#define HCCHAR_EPTYPE_INTR      (3U << 18)  /**< Interrupt transfer value.  */
#define HCCHAR_LSPDDEV          (1U << 17)  /**< Low-speed device.          */
#define HCCHAR_EPTDIR           (1U << 15)  /**< Endpoint direction.        */
#define HCCHAR_EPTNUM_MASK      (15U << 11) /**< Endpoint number mask.      */
#define HCCHAR_EPTNUM(n)        ((n) << 11) /**< Endpoint number value.     */
#define HCCHAR_MPS_MASK         (0x7FFU << 0) /**< Maximum packet size mask.*/
#define HCCHAR_MPS(n)           ((n) << 0)  /**< Maximum packet size value. */
/** @} */

/**
 * @name HCINT register bit definitions
 * @{
 */
#define HCINT_DTGLERR           (1U << 10)  /**< Data toggle error.         */
#define HCINT_FRMOVRUN          (1U << 9)   /**< Frame overrun.             */
#define HCINT_BBLERR            (1U << 8)   /**< Babble error.              */
#define HCINT_XACTERR           (1U << 7)   /**< Transaction error.         */
#define HCINT_ACK               (1U << 5)   /**< ACK response
                                                 received/transmitted
                                                 interrupt.                 */
#define HCINT_NAK               (1U << 4)   /**< NAK response received
                                                 interrupt.                 */
#define HCINT_STALL             (1U << 3)   /**< STALL response received
                                                 interrupt.                 */
#define HCINT_AHBERR            (1U << 2)   /**< AHB error interrupt
                                                 (HS only).                 */
#define HCINT_CHHLTD            (1U << 1)   /**< Channel halted.            */
#define HCINT_XFERC             (1U << 0)   /**< Transfer completed.        */
/** @} */

/**
 * @name HCINTMSK register bit definitions
 * @{
 */
#define HCINTMSK_DTGLERRMSK     (1U << 10)  /**< Data toggle error mask.    */
#define HCINTMSK_FRMOVRUNMSK    (1U << 9)   /**< Frame overrun mask.        */
#define HCINTMSK_BBLERRMSK      (1U << 8)   /**< Babble error mask.         */
#define HCINTMSK_XACTERRMSK     (1U << 7)   /**< Transaction error mask.    */
#define HCINTMSK_NYETMSK        (1U << 6)   /**< NYET response received
                                                 interrupt mask.            */
#define HCINTMSK_ACKMSK         (1U << 5)   /**< ACK response
                                                 received/transmitted
                                                 interrupt mask.            */
#define HCINTMSK_NAKMSK         (1U << 4)   /**< NAK response received
                                                 interrupt mask.            */
#define HCINTMSK_STALLMSK       (1U << 3)   /**< STALL response received
                                                 interrupt mask.            */
#define HCINTMSK_AHBERRMSK      (1U << 2)   /**< AHB error mask (HS only).  */
#define HCINTMSK_CHHLTDMSK      (1U << 1)   /**< Channel halted mask.       */
#define HCINTMSK_XFERCMSK       (1U << 0)   /**< Transfer completed mask.   */
/** @} */

/**
 * @name HCTSIZ register bit definitions
 * @{
 */
#define HCTSIZ_PID_MASK         (3U << 29)  /**< PID mask.                  */
#define HCTSIZ_PID_DATA0        (0U << 29)  /**< DATA0.                     */
#define HCTSIZ_PID_DATA2        (1U << 29)  /**< DATA2.                     */
#define HCTSIZ_PID_DATA1        (2U << 29)  /**< DATA1.                     */
#define HCTSIZ_PID_MDATA        (3U << 29)  /**< MDATA.                     */
#define HCTSIZ_PID_SETUP        (3U << 29)  /**< SETUP.                     */
#define HCTSIZ_PKTCNT_MASK      (0x3FFU << 19)  /**< Packet count mask.     */
#define HCTSIZ_PKTCNT(n)        ((n) << 19) /**< Packet count value.        */
#define HCTSIZ_XFERSIZE_MASK    (0x7FFFFU << 0) /**< Transfer size mask.    */
#define HCTSIZ_XFERSIZE(n)      ((n) << 0)  /**< Transfer size value.       */
/** @} */

/**
 * @name DCFG register bit definitions
 * @{
 */
#define DCFG_PERFRINT_MASK      (3U << 11)  /**< Periodic frame interval
                                                 mask.                      */
#define DCFG_PERFRINT(n)        ((n) << 11) /**< Periodic frame interval
                                                 value.                     */
#define DCFG_DEVADDR_MASK       (0x7FU << 4)/**< Device address mask.       */
#define DCFG_DEVADDR(n)         ((n) << 4)  /**< Device address value.      */
#define DCFG_NZSTSOUTHSHK       (1U << 2)   /**< Non-zero-length status
                                                 OUT handshake.             */
#define DCFG_DEVSPD_MASK        (3U << 0)   /**< Device speed mask.         */
#define DCFG_DEVSPD_HS          (0U << 0)   /**< High speed (USB 2.0).      */
#define DCFG_DEVSPD_HS_FS       (1U << 0)   /**< High speed (USB 2.0) in FS
                                                 mode.                      */
#define DCFG_DEVSPD_FS11        (3U << 0)   /**< Full speed (USB 1.1
                                                 transceiver clock is 48
                                                 MHz).                      */
/** @} */

/**
 * @name DCTL register bit definitions
 * @{
 */
#define DCTL_PWROPRGDNE         (1U << 11)  /**< Power-on programming done. */
#define DCTL_CGOUTNAK           (1U << 10)  /**< Clear global OUT NAK.      */
#define DCTL_SGOUTNAK           (1U << 9)   /**< Set global OUT NAK.        */
#define DCTL_CGNPINNAK          (1U << 8)   /**< Clear global non-periodic
                                                 IN NAK.                    */
#define DCTL_SGNPINNAK          (1U << 7)   /**< Set global non-periodic
                                                 IN NAK.                    */
#define DCTL_TSTCTL_MASK        (7U << 4)   /**< Test control mask.         */
#define DCTL_TSTCTL(n)          ((n) << 4)  /**< Test control value.        */
#define DCTL_GOUTNAKSTS         (1U << 3)   /**< Global OUT NAK status.     */
#define DCTL_GNPINNAKSTS        (1U << 2)   /**< Global non-periodic IN
                                                 NAK status.                */
#define DCTL_SFTDISCON          (1U << 1)   /**< Software disconnect.       */
#define DCTL_RWKUPSIG           (1U << 0)   /**< Remote wakeup signaling.   */
/** @} */

/**
 * @name DSTS register bit definitions
 * @{
 */
#define DSTS_SOFFN_MASK         (0x3FFFU << 8)  /**< Frame number of the
                                                     received SOF mask.     */
#define DSTS_SOFFN(n)           ((n) << 8)      /**< Frame number of the
                                                     received SOF value.    */
#define DSTS_SOFFN_ODD          (1U << 8)       /**< Frame parity of the
                                                     received SOF value.    */
#define DSTS_ETICERR            (1U << 3)       /**< Erratic error.         */
#define DSTS_ENUMSPD_MASK       (3U << 1)       /**< Enumerated speed mask. */
#define DSTS_ENUMSPD_FS_48      (3U << 1)       /**< Full speed (PHY clock is
                                                     running at 48 MHz).    */
#define DSTS_ENUMSPD_FS_30_60   (1U << 1)       /**< Full speed (PHY clock is
                                                     running at 30/60 MHz). */
#define DSTS_ENUMSPD_HS_480     (0U << 1)       /**< High speed.            */
#define DSTS_SUSPSTS            (1U << 0)       /**< Suspend status.        */
/** @} */

/**
 * @name DIEPMSK register bit definitions
 * @{
 */
#define DIEPMSK_TXFIFOUDRMSK    (1U << 8)   /**< FIFO underrun mask.        */
#define DIEPMSK_INEPTNAKMSK     (1U << 6)   /**< IN endpoint NAK effective
                                                 mask.                      */
#define DIEPMSK_INTKNTXFEMPMSK  (1U << 4)   /**< IN token received when
                                                 TxFIFO empty mask.         */
#define DIEPMSK_TIMEOUTMSK      (1U << 3)   /**< Timeout condition mask.    */
#define DIEPMSK_EPTDISMSK       (1U << 1)   /**< Endpoint disabled
                                                 interrupt mask.            */
#define DIEPMSK_XFERCMSK        (1U << 0)   /**< Transfer completed
                                                 interrupt mask.            */
/** @} */

/**
 * @name DOEPMSK register bit definitions
 * @{
 */
#define DOEPMSK_OUTTEPDMSK      (1U << 4)   /**< OUT token received when
                                                 endpoint disabled mask.    */
#define DOEPMSK_SETUPMSK        (1U << 3)   /**< SETUP phase done mask.     */
#define DOEPMSK_EPTDISMSK       (1U << 1)   /**< Endpoint disabled
                                                 interrupt mask.            */
#define DOEPMSK_XFERCMSK        (1U << 0)   /**< Transfer completed
                                                 interrupt mask.            */
/** @} */

/**
 * @name DAINT register bit definitions
 * @{
 */
#define DAINT_OUTEPTINT_MASK    (0xFFFFU << 16) /**< OUT endpoint interrupt
                                                     bits mask.             */
#define DAINT_OUTEPTINT(n)      ((n) << 16)     /**< OUT endpoint interrupt
                                                     bits value.            */
#define DAINT_INEPTINT_MASK     (0xFFFFU << 0)  /**< IN endpoint interrupt
                                                     bits mask.             */
#define DAINT_INEPTINT(n)       ((n) << 0)      /**< IN endpoint interrupt
                                                     bits value.            */
/** @} */

/**
 * @name DAINTMSK register bit definitions
 * @{
 */
#define DAINTMSK_OUTEPTMSK_MASK (0xFFFFU << 16) /**< OUT EP interrupt mask
                                                     bits mask.             */
#define DAINTMSK_OUTEPTMSK(n)   (1U <<(16+(n))) /**< OUT EP interrupt mask
                                                     bits value.            */
#define DAINTMSK_INEPTMSK_MASK  (0xFFFFU << 0)  /**< IN EP interrupt mask
                                                     bits mask.             */
#define DAINTMSK_INEPTMSK(n)    (1U <<(n))      /**< IN EP interrupt mask
                                                     bits value.            */
/** @} */

/**
 * @name DIEPEMPMSK register bit definitions
 * @{
 */
#define DIEPEMPMSK_INEPTXFEMSK(n) (1U << (n))   /**< IN EP Tx FIFO empty
                                                     interrupt mask bit.    */
/** @} */

/**
 * @name DIEPCTL register bit definitions
 * @{
 */
#define DIEPCTL_EPTENA          (1U << 31)  /**< Endpoint enable.           */
#define DIEPCTL_EPTDIS          (1U << 30)  /**< Endpoint disable.          */
#define DIEPCTL_SETD1PID        (1U << 29)  /**< Set DATA1 PID.             */
#define DIEPCTL_SETODDFR        (1U << 29)  /**< Set odd frame.             */
#define DIEPCTL_SETD0PID        (1U << 28)  /**< Set DATA0 PID.             */
#define DIEPCTL_SETEVENFR       (1U << 28)  /**< Set even frame.            */
#define DIEPCTL_SNAK            (1U << 27)  /**< Set NAK.                   */
#define DIEPCTL_CNAK            (1U << 26)  /**< Clear NAK.                 */
#define DIEPCTL_TXFNUM_MASK     (15U << 22) /**< TxFIFO number mask.        */
#define DIEPCTL_TXFNUM(n)       ((n) << 22) /**< TxFIFO number value.       */
#define DIEPCTL_STALL           (1U << 21)  /**< STALL handshake.           */
#define DIEPCTL_EPTYPE_MASK     (3U << 18)  /**< Endpoint type mask.        */
#define DIEPCTL_EPTYPE_CTRL     (0U << 18)  /**< Control.                   */
#define DIEPCTL_EPTYPE_ISO      (1U << 18)  /**< Isochronous.               */
#define DIEPCTL_EPTYPE_BULK     (2U << 18)  /**< Bulk.                      */
#define DIEPCTL_EPTYPE_INTR     (3U << 18)  /**< Interrupt.                 */
#define DIEPCTL_NAKSTS          (1U << 17)  /**< NAK status.                */
#define DIEPCTL_EOFRNUM         (1U << 16)  /**< Even/odd frame.            */
#define DIEPCTL_DPID            (1U << 16)  /**< Endpoint data PID.         */
#define DIEPCTL_USBACEPT        (1U << 15)  /**< USB active endpoint.       */
#define DIEPCTL_MPS_MASK        (0x7FFU << 0) /**< Maximum packet size mask.*/
#define DIEPCTL_MPS(n)          ((n) << 0)  /**< Maximum packet size value. */
/** @} */

/**
 * @name DIEPINT register bit definitions
 * @{
 */
#define DIEPINT_TXFEMP          (1U << 7)   /**< Transmit FIFO empty.       */
#define DIEPINT_INEPTNAK        (1U << 6)   /**< IN endpoint NAK effective. */
#define DIEPINT_INTKNTXFEMP     (1U << 4)   /**< IN Token received when
                                                 TxFIFO is empty.           */
#define DIEPINT_TIMEOUT         (1U << 3)   /**< Timeout condition.         */
#define DIEPINT_EPTDISD         (1U << 1)   /**< Endpoint disabled
                                                 interrupt.                 */
#define DIEPINT_XFERC           (1U << 0)   /**< Transfer completed
                                                 interrupt.                 */
/** @} */

/**
 * @name DIEPTSIZ register bit definitions
 * @{
 */
#define DIEPTSIZ_MC_MASK        (3U << 29)      /**< Multi count mask.      */
#define DIEPTSIZ_MC(n)          ((n) << 29)     /**< Multi count value.     */
#define DIEPTSIZ_PKTCNT_MASK    (0x3FF<< 19)    /**< Packet count mask.     */
#define DIEPTSIZ_PKTCNT(n)      ((n) << 19)     /**< Packet count value.    */
#define DIEPTSIZ_XFERSIZE_MASK  (0x7FFFFU << 0) /**< Transfer size mask.    */
#define DIEPTSIZ_XFERSIZE(n)    ((n) << 0)      /**< Transfer size value.   */
/** @} */

/**
 * @name DTXFSTS register bit definitions.
 * @{
 */
#define DTXFSTS_INEPTXFSAV_MASK  (0xFFFFU << 0) /**< IN endpoint TxFIFO
                                                     space available.       */
/** @} */

/**
 * @name DOEPCTL register bit definitions.
 * @{
 */
#define DOEPCTL_EPTENA          (1U << 31)  /**< Endpoint enable.           */
#define DOEPCTL_EPTDIS          (1U << 30)  /**< Endpoint disable.          */
#define DOEPCTL_SETD1PID        (1U << 29)  /**< Set DATA1 PID.             */
#define DOEPCTL_SETODDFR        (1U << 29)  /**< Set odd frame.             */
#define DOEPCTL_SETD0PID        (1U << 28)  /**< Set DATA0 PID.             */
#define DOEPCTL_SETEVENFR       (1U << 28)  /**< Set even frame.            */
#define DOEPCTL_SNAK            (1U << 27)  /**< Set NAK.                   */
#define DOEPCTL_CNAK            (1U << 26)  /**< Clear NAK.                 */
#define DOEPCTL_STALL           (1U << 21)  /**< STALL handshake.           */
#define DOEPCTL_SNP             (1U << 20)  /**< Snoop mode.                */
#define DOEPCTL_EPTYPE_MASK     (3U << 18)  /**< Endpoint type mask.        */
#define DOEPCTL_EPTYPE_CTRL     (0U << 18)  /**< Control.                   */
#define DOEPCTL_EPTYPE_ISO      (1U << 18)  /**< Isochronous.               */
#define DOEPCTL_EPTYPE_BULK     (2U << 18)  /**< Bulk.                      */
#define DOEPCTL_EPTYPE_INTR     (3U << 18)  /**< Interrupt.                 */
#define DOEPCTL_NAKSTS          (1U << 17)  /**< NAK status.                */
#define DOEPCTL_EOFRNUM         (1U << 16)  /**< Even/odd frame.            */
#define DOEPCTL_DPID            (1U << 16)  /**< Endpoint data PID.         */
#define DOEPCTL_USBACEPT        (1U << 15)  /**< USB active endpoint.       */
#define DOEPCTL_MPS_MASK        (0x7FFU << 0)/**< Maximum packet size mask. */
#define DOEPCTL_MPS(n)          ((n) << 0)  /**< Maximum packet size value. */
/** @} */

/**
 * @name DOEPINT register bit definitions
 * @{
 */
#define DOEPINT_B2BSTUP         (1U << 6)   /**< Back-to-back SETUP packets
                                                 received.                  */
#define DOEPINT_OUTTEPD         (1U << 4)   /**< OUT token received when
                                                 endpoint disabled.         */
#define DOEPINT_SETUP           (1U << 3)   /**< SETUP phase done.          */
#define DOEPINT_EPTDISD         (1U << 1)   /**< Endpoint disabled
                                                 interrupt.                 */
#define DOEPINT_XFERC           (1U << 0)   /**< Transfer completed
                                                 interrupt.                 */
/** @} */

/**
 * @name DOEPTSIZ register bit definitions
 * @{
 */
#define DOEPTSIZ_RXDPID_MASK    (3U << 29)  /**< Received data PID mask.    */
#define DOEPTSIZ_RXDPID(n)      ((n) << 29) /**< Received data PID value.   */
#define DOEPTSIZ_SETUPCNT_MASK  (3U << 29)  /**< SETUP packet count mask.   */
#define DOEPTSIZ_SETUPCNT(n)    ((n) << 29) /**< SETUP packet count value.  */
#define DOEPTSIZ_PKTCNT_MASK    (0x3FFU << 19)  /**< Packet count mask.     */
#define DOEPTSIZ_PKTCNT(n)      ((n) << 19) /**< Packet count value.        */
#define DOEPTSIZ_XFERSIZE_MASK  (0x7FFFFU << 0) /**< Transfer size mask.    */
#define DOEPTSIZ_XFERSIZE(n)    ((n) << 0)  /**< Transfer size value.       */
/** @} */

/**
 * @name PCGCCTL register bit definitions
 * @{
 */
#define PCGCCTL_SUSPENDM        (1U << 4)   /**< PHY Suspended.             */
#define PCGCCTL_STOPPCLK        (1U << 0)   /**< Stop PCLK.                 */
/** @} */

#define OTG_FS_ADDR                 0x50000000
#define OTG_HS_ADDR                 0x40040000

/**
 * @brief   Accesses to the OTG_FS registers block.
 */
#define OTG_FS                      ((at32_otg_t *)OTG_FS_ADDR)

/**
 * @brief   Accesses to the OTG_HS registers block.
 */
#define OTG_HS                      ((at32_otg_t *)OTG_HS_ADDR)

#endif /* AT32_OTG_H */

/** @} */
