#ifndef __STM8S_H
#define __STM8S_H

/**
 * TODO complete register bitmaps
 */

/* GPIO */
#define PA_ODR *(unsigned char*)0x5000
#define PA_IDR *(unsigned char*)0x5001
#define PA_DDR *(unsigned char*)0x5002
#define PA_CR1 *(unsigned char*)0x5003
#define PA_CR2 *(unsigned char*)0x5004

#define PB_ODR *(unsigned char*)0x5005
#define PB_IDR *(unsigned char*)0x5006
#define PB_DDR *(unsigned char*)0x5007
#define PB_CR1 *(unsigned char*)0x5008
#define PB_CR2 *(unsigned char*)0x5009

#define PC_ODR *(unsigned char*)0x500A
#define PC_IDR *(unsigned char*)0x500B
#define PC_DDR *(unsigned char*)0x500C
#define PC_CR1 *(unsigned char*)0x500D
#define PC_CR2 *(unsigned char*)0x500E

#define PD_ODR *(unsigned char*)0x500F
#define PD_IDR *(unsigned char*)0x5010
#define PD_DDR *(unsigned char*)0x5011
#define PD_CR1 *(unsigned char*)0x5012
#define PD_CR2 *(unsigned char*)0x5013

#define PE_ODR *(unsigned char*)0x5014
#define PE_IDR *(unsigned char*)0x5015
#define PE_DDR *(unsigned char*)0x5016
#define PE_CR1 *(unsigned char*)0x5017
#define PE_CR2 *(unsigned char*)0x5018

#define PF_ODR *(unsigned char*)0x5019
#define PF_IDR *(unsigned char*)0x501A
#define PF_DDR *(unsigned char*)0x501B
#define PF_CR1 *(unsigned char*)0x501C
#define PF_CR2 *(unsigned char*)0x501D

/* Flash */
#define FLASH_CR1 *(unsigned char*)0x505A
#define FLASH_CR2 *(unsigned char*)0x505B
#define FLASH_NCR2 *(unsigned char*)0x505C
#define FLASH_FPR *(unsigned char*)0x505D
#define FLASH_NFPR *(unsigned char*)0x505E
#define FLASH_IAPRS *(unsigned char*)0x505F
#define FLASH_PUKR *(unsigned char*)0x5062
#define FLASH_DUKR *(unsigned char*)0x5064

/* Interrupt control */
#define EXTI_CR1 *(unsigned char*)0x50A0
#define EXTI_CR2 *(unsigned char*)0x50A1

/* Reset Status */
#define RST_SR *(unsigned char*)0x50B3

/* Clock Registers */
#define CLK_ICKR *(unsigned char*)0x50C0
#define CLK_ECKR *(unsigned char*)0x50C1
#define CLK_CMSR *(unsigned char*)0x50C3
#define CLK_SWR *(unsigned char*)0x50C4
#define CLK_SWCR *(unsigned char*)0x50C5
#define CLK_CKDIVR *(unsigned char*)0x50C6
#define CLK_PCKENR1 *(unsigned char*)0x50C7
#define CLK_CSSR *(unsigned char*)0x50C8
#define CLK_CCOR *(unsigned char*)0x50C9
#define CLK_PCKENR2 *(unsigned char*)0x50CA
#define CLK_HSITRIMR *(unsigned char*)0x50CC
#define CLK_SWIMCCR *(unsigned char*)0x50CD

#define CLK_ICKR_REGAH (1 << 5)
#define CLK_ICKR_LSIRDY (1 << 4)
#define CLK_ICKR_LSIEN (1 << 3)
#define CLK_ICKR_FHW (1 << 2)
#define CLK_ICKR_HSIRDY (1 << 1)
#define CLK_ICKR_HSIEN (1 << 0)

#define CLK_ECKR_HSERDY (1 << 1)
#define CLK_ECKR_HSEEN (1 << 0)

#define CLK_SWR_HSI 0xE1
#define CLK_SWR_LSI 0xD2
#define CLK_SWR_HSE 0xB4

#define CLK_SWCR_SWIF (1 << 3)
#define CLK_SWCR_SWIEN (1 << 2)
#define CLK_SWCR_SWEN (1 << 1)
#define CLK_SWCR_SWBSY (1 << 0)

#define CLK_CKDIVR_HSIDIV1 (1 << 4)
#define CLK_CKDIVR_HSIDIV0 (1 << 3)
#define CLK_CKDIVR_CPUDIV2 (1 << 2)
#define CLK_CKDIVR_CPUDIV1 (1 << 1)
#define CLK_CKDIVR_CPUDIV0 (1 << 0)

/* Watchdog */
#define WWDG_CR *(unsigned char*)0x50D1
#define WWDG_WR *(unsigned char*)0x50D2
#define IWDG_KR *(unsigned char*)0x50E0
#define IWDG_PR *(unsigned char*)0x50E1
#define IWDG_RLR *(unsigned char*)0x50E2
#define AWU_CSR1 *(unsigned char*)0x50F0
#define AWU_APR *(unsigned char*)0x50F1
#define AWU_TBR *(unsigned char*)0x50F2

/* Beep */
#define BEEP_CSR *(unsigned char*)0x50F3

/* SPI */
#define SPI_CR1 *(unsigned char*)0x5200
#define SPI_CR2 *(unsigned char*)0x5201
#define SPI_ICR *(unsigned char*)0x5202
#define SPI_SR *(unsigned char*)0x5203
#define SPI_DR *(unsigned char*)0x5204
#define SPI_CRCPR *(unsigned char*)0x5205
#define SPI_RXCRCR *(unsigned char*)0x5206
#define SPI_TXCRCR *(unsigned char*)0x5207

/* I2C */
#define I2C_CR1 *(unsigned char*)0x5210
#define I2C_CR2 *(unsigned char*)0x5211
#define I2C_FREQR *(unsigned char*)0x5212
#define I2C_OARL *(unsigned char*)0x5213
#define I2C_OARH *(unsigned char*)0x5214
#define I2C_DR *(unsigned char*)0x5216
#define I2C_SR1 *(unsigned char*)0x5217
#define I2C_SR2 *(unsigned char*)0x5218
#define I2C_SR3 *(unsigned char*)0x5219
#define I2C_ITR *(unsigned char*)0x521A
#define I2C_CCRL *(unsigned char*)0x521B
#define I2C_CCRH *(unsigned char*)0x521C
#define I2C_TRISER *(unsigned char*)0x521D
#define I2C_PECR *(unsigned char*)0x521E

/* UART */
#define UART1_SR *(unsigned char*)0x5230
#define UART1_DR *(unsigned char*)0x5231
#define UART1_BRR1 *(unsigned char*)0x5232
#define UART1_BRR2 *(unsigned char*)0x5233
#define UART1_CR1 *(unsigned char*)0x5234
#define UART1_CR2 *(unsigned char*)0x5235
#define UART1_CR3 *(unsigned char*)0x5236
#define UART1_CR4 *(unsigned char*)0x5237
#define UART1_CR5 *(unsigned char*)0x5238
#define UART1_GTR *(unsigned char*)0x5239
#define UART1_PSCR *(unsigned char*)0x523A

/* UART Status Register bits */
#define UART_SR_TXE (1 << 7)
#define UART_SR_TC (1 << 6)
#define UART_SR_RXNE (1 << 5)
#define UART_SR_IDLE (1 << 4)
#define UART_SR_OR (1 << 3)
#define UART_SR_NF (1 << 2)
#define UART_SR_FE (1 << 1)
#define UART_SR_PE (1 << 0)

/* Uart Control Register bits */
#define UART_CR1_R8 (1 << 7)
#define UART_CR1_T8 (1 << 6)
#define UART_CR1_UARTD (1 << 5)
#define UART_CR1_M (1 << 4)
#define UART_CR1_WAKE (1 << 3)
#define UART_CR1_PCEN (1 << 2)
#define UART_CR1_PS (1 << 1)
#define UART_CR1_PIEN (1 << 0)

#define UART_CR2_TIEN (1 << 7)
#define UART_CR2_TCIEN (1 << 6)
#define UART_CR2_RIEN (1 << 5)
#define UART_CR2_ILIEN (1 << 4)
#define UART_CR2_TEN (1 << 3)
#define UART_CR2_REN (1 << 2)
#define UART_CR2_RWU (1 << 1)
#define UART_CR2_SBK (1 << 0)

#define UART_CR3_LINEN (1 << 6)
#define UART_CR3_STOP1 (1 << 5)
#define UART_CR3_STOP0 (1 << 4)
#define UART_CR3_CLKEN (1 << 3)
#define UART_CR3_CPOL (1 << 2)
#define UART_CR3_CPHA (1 << 1)
#define UART_CR3_LBCL (1 << 0)

#define UART_CR4_LBDIEN (1 << 6)
#define UART_CR4_LBDL (1 << 5)
#define UART_CR4_LBDF (1 << 4)
#define UART_CR4_ADD3 (1 << 3)
#define UART_CR4_ADD2 (1 << 2)
#define UART_CR4_ADD1 (1 << 1)
#define UART_CR4_ADD0 (1 << 0)

#define UART_CR5_SCEN (1 << 5)
#define UART_CR5_NACK (1 << 4)
#define UART_CR5_HDSEL (1 << 3)
#define UART_CR5_IRLP (1 << 2)
#define UART_CR5_IREN (1 << 1)

/* TIMERS */
/* Timer 1 - 16-bit timer with complementary PWM outputs */
#define TIM1_CR1 *(unsigned char*)0x5250
#define TIM1_CR2 *(unsigned char*)0x5251
#define TIM1_SMCR *(unsigned char*)0x5252
#define TIM1_ETR *(unsigned char*)0x5253
#define TIM1_IER *(unsigned char*)0x5254
#define TIM1_SR1 *(unsigned char*)0x5255
#define TIM1_SR2 *(unsigned char*)0x5256
#define TIM1_EGR *(unsigned char*)0x5257
#define TIM1_CCMR1 *(unsigned char*)0x5258
#define TIM1_CCMR2 *(unsigned char*)0x5259
#define TIM1_CCMR3 *(unsigned char*)0x525A
#define TIM1_CCMR4 *(unsigned char*)0x525B
#define TIM1_CCER1 *(unsigned char*)0x525C
#define TIM1_CCER2 *(unsigned char*)0x525D
#define TIM1_CNTRH *(unsigned char*)0x525E
#define TIM1_CNTRL *(unsigned char*)0x525F
#define TIM1_PSCRH *(unsigned char*)0x5260
#define TIM1_PSCRL *(unsigned char*)0x5261
#define TIM1_ARRH *(unsigned char*)0x5262
#define TIM1_ARRL *(unsigned char*)0x5263
#define TIM1_RCR *(unsigned char*)0x5264
#define TIM1_CCR1H *(unsigned char*)0x5265
#define TIM1_CCR1L *(unsigned char*)0x5266
#define TIM1_CCR2H *(unsigned char*)0x5267
#define TIM1_CCR2L *(unsigned char*)0x5268
#define TIM1_CCR3H *(unsigned char*)0x5269
#define TIM1_CCR3L *(unsigned char*)0x526A
#define TIM1_CCR4H *(unsigned char*)0x526B
#define TIM1_CCR4L *(unsigned char*)0x526C
#define TIM1_BKR *(unsigned char*)0x526D
#define TIM1_DTR *(unsigned char*)0x526E
#define TIM1_OISR *(unsigned char*)0x526F

/* Timer Control Register bits */
#define TIM_CR1_ARPE (1 << 7)
#define TIM_CR1_CMSH (1 << 6)
#define TIM_CR1_CMSL (1 << 5)
#define TIM_CR1_DIR (1 << 4)
#define TIM_CR1_OPM (1 << 3)
#define TIM_CR1_URS (1 << 2)
#define TIM_CR1_UDIS (1 << 1)
#define TIM_CR1_CEN (1 << 0)

#define TIM1_CR2_MMS2 (1 << 6)
#define TIM1_CR2_MMS1 (1 << 5)
#define TIM1_CR2_MMS0 (1 << 4)
#define TIM1_CR2_COMS (1 << 2)
#define TIM1_CR2_CCPC (1 << 0)

/* Timer Slave Mode Control bits */
#define TIM1_SMCR_MSM (1 << 7)
#define TIM1_SMCR_TS2 (1 << 6)
#define TIM1_SMCR_TS1 (1 << 5)
#define TIM1_SMCR_TS0 (1 << 4)
#define TIM1_SMCR_SMS2 (1 << 2)
#define TIM1_SMCR_SMS1 (1 << 1)
#define TIM1_SMCR_SMS0 (1 << 0)

/* Timer External Trigger Enable bits */
#define TIM1_ETR_ETP (1 << 7)
#define TIM1_ETR_ECE (1 << 6)
#define TIM1_ETR_ETPS1 (1 << 5)
#define TIM1_ETR_ETPS0 (1 << 4)
#define TIM1_ETR_ETF3 (1 << 3)
#define TIM1_ETR_ETF2 (1 << 2)
#define TIM1_ETR_ETF1 (1 << 1)
#define TIM1_ETR_ETF0 (1 << 0)

/* Timer Interrupt Enable bits */
#define TIM1_IER_BIE (1 << 7)
#define TIM1_IER_TIE (1 << 6)
#define TIM1_IER_COMIE (1 << 5)
#define TIM1_IER_CC4IE (1 << 4)
#define TIM1_IER_CC3IE (1 << 3)
#define TIM1_IER_CC2IE (1 << 2)
#define TIM1_IER_CC1IE (1 << 1)
#define TIM1_IER_UIE (1 << 0)

/* Timer Status Register bits */
#define TIM1_SR1_BIF (1 << 7)
#define TIM1_SR1_TIF (1 << 6)
#define TIM1_SR1_COMIF (1 << 5)
#define TIM1_SR1_CC4IF (1 << 4)
#define TIM1_SR1_CC3IF (1 << 3)
#define TIM1_SR1_CC2IF (1 << 2)
#define TIM1_SR1_CC1IF (1 << 1)
#define TIM1_SR1_UIF (1 << 0)

#define TIM1_SR2_CC4OF (1 << 4)
#define TIM1_SR2_CC3OF (1 << 3)
#define TIM1_SR2_CC2OF (1 << 2)
#define TIM1_SR2_CC1OF (1 << 1)

/* Timer Event Generation Register bits */
#define TIM1_EGR_BG (1 << 7)
#define TIM1_EGR_TG (1 << 6)
#define TIM1_EGR_COMG ( 1 << 5)
#define TIM1_EGR_CC4G (1 << 4)
#define TIM1_EGR_CC3G (1 << 3)
#define TIM1_EGR_CC2G (1 << 2)
#define TIM1_EGR_CC1G (1 << 1)
#define TIM1_EGR_UG (1 << 0)

/* Capture/Compare Mode Register 1 - channel configured in output */
#define TIM1_CCMR1_OC1CE (1 << 7)
#define TIM1_CCMR1_OC1M2 (1 << 6)
#define TIM1_CCMR1_OC1M1 (1 << 5)
#define TIM1_CCMR1_OC1M0 (1 << 4)
#define TIM1_CCMR1_OC1PE (1 << 3)
#define TIM1_CCMR1_OC1FE (1 << 2)
#define TIM1_CCMR1_CC1S1 (1 << 1)
#define TIM1_CCMR1_CC1S0 (1 << 0)

/* Capture/Compare Mode Register 1 - channel configured in input */
#define TIM1_CCMR1_IC1F3 (1 << 7)
#define TIM1_CCMR1_IC1F2 (1 << 6)
#define TIM1_CCMR1_IC1F1 (1 << 5)
#define TIM1_CCMR1_IC1F0 (1 << 4)
#define TIM1_CCMR1_IC1PSC1 (1 << 3)
#define TIM1_CCMR1_IC1PSC0 (1 << 2)
/* #define TIM1_CCMR1_CC1S1 (1 << 1)
#define TIM1_CCMR1_CC1S0 (1 << 0) */

/* Capture/Compare Mode Register 2 - channel configured in output */
#define TIM1_CCMR2_OC2CE (1 << 7)
#define TIM1_CCMR2_OC2M2 (1 << 6)
#define TIM1_CCMR2_OC2M1 (1 << 5)
#define TIM1_CCMR2_OC2M0 (1 << 4)
#define TIM1_CCMR2_OC2PE (1 << 3)
#define TIM1_CCMR2_OC2FE (1 << 2)
#define TIM1_CCMR2_CC2S1 (1 << 1)
#define TIM1_CCMR2_CC2S0 (1 << 0)

/* Capture/Compare Mode Register 2 - channel configured in input */
#define TIM1_CCMR2_IC2F3 (1 << 7)
#define TIM1_CCMR2_IC2F2 (1 << 6)
#define TIM1_CCMR2_IC2F1 (1 << 5)
#define TIM1_CCMR2_IC2F0 (1 << 4)
#define TIM1_CCMR2_IC2PSC1 (1 << 3)
#define TIM1_CCMR2_IC2PSC0 (1 << 2)
/* #define TIM1_CCMR2_CC2S1 (1 << 1)
#define TIM1_CCMR2_CC2S0 (1 << 0) */

/* Capture/Compare Mode Register 3 - channel configured in output */
#define TIM1_CCMR3_OC3CE (1 << 7)
#define TIM1_CCMR3_OC3M2 (1 << 6)
#define TIM1_CCMR3_OC3M1 (1 << 5)
#define TIM1_CCMR3_OC3M0 (1 << 4)
#define TIM1_CCMR3_OC3PE (1 << 3)
#define TIM1_CCMR3_OC3FE (1 << 2)
#define TIM1_CCMR3_CC3S1 (1 << 1)
#define TIM1_CCMR3_CC3S0 (1 << 0)

/* Capture/Compare Mode Register 3 - channel configured in input */
#define TIM1_CCMR3_IC3F3 (1 << 7)
#define TIM1_CCMR3_IC3F2 (1 << 6)
#define TIM1_CCMR3_IC3F1 (1 << 5)
#define TIM1_CCMR3_IC3F0 (1 << 4)
#define TIM1_CCMR3_IC3PSC1 (1 << 3)
#define TIM1_CCMR3_IC3PSC0 (1 << 2)
/* #define TIM1_CCMR3_CC3S1 (1 << 1)
#define TIM1_CCMR3_CC3S0 (1 << 0) */

/* Capture/Compare Mode Register 4 - channel configured in output */
#define TIM1_CCMR4_OC4CE (1 << 7)
#define TIM1_CCMR4_OC4M2 (1 << 6)
#define TIM1_CCMR4_OC4M1 (1 << 5)
#define TIM1_CCMR4_OC4M0 (1 << 4)
#define TIM1_CCMR4_OC4PE (1 << 3)
#define TIM1_CCMR4_OC4FE (1 << 2)
#define TIM1_CCMR4_CC4S1 (1 << 1)
#define TIM1_CCMR4_CC4S0 (1 << 0)

/* Capture/Compare Mode Register 4 - channel configured in input */
#define TIM1_CCMR4_IC4F3 (1 << 7)
#define TIM1_CCMR4_IC4F2 (1 << 6)
#define TIM1_CCMR4_IC4F1 (1 << 5)
#define TIM1_CCMR4_IC4F0 (1 << 4)
#define TIM1_CCMR4_IC4PSC1 (1 << 3)
#define TIM1_CCMR4_IC4PSC0 (1 << 2)
/* #define TIM1_CCMR4_CC4S1 (1 << 1)
#define TIM1_CCMR4_CC4S0 (1 << 0) */

/* Timer 2 - 16-bit timer */
#define TIM2_CR1 *(unsigned char*)0x5300
#define TIM2_IER *(unsigned char*)0x5303
#define TIM2_SR1 *(unsigned char*)0x5304
#define TIM2_SR2 *(unsigned char*)0x5305
#define TIM2_EGR *(unsigned char*)0x5306
#define TIM2_CCMR1 *(unsigned char*)0x5307
#define TIM2_CCMR2 *(unsigned char*)0x5308
#define TIM2_CCMR3 *(unsigned char*)0x5309
#define TIM2_CCER1 *(unsigned char*)0x530A
#define TIM2_CCER2 *(unsigned char*)0x530B
#define TIM2_CNTRH *(unsigned char*)0x530C
#define TIM2_CNTRL *(unsigned char*)0x530D
#define TIM2_PSCR *(unsigned char*)0x530E
#define TIM2_ARRH *(unsigned char*)0x530F
#define TIM2_ARRL *(unsigned char*)0x5310
#define TIM2_CCR1H *(unsigned char*)0x5311
#define TIM2_CCR1L *(unsigned char*)0x5312
#define TIM2_CCR2H *(unsigned char*)0x5313
#define TIM2_CCR2L *(unsigned char*)0x5314
#define TIM2_CCR3H *(unsigned char*)0x5315
#define TIM2_CCR3L *(unsigned char*)0x5316

/* Timer 4 */
#define TIM4_CR1 *(unsigned char*)0x5340
#define TIM4_IER *(unsigned char*)0x5343
#define TIM4_SR *(unsigned char*)0x5344
#define TIM4_EGR *(unsigned char*)0x5345
#define TIM4_CNTR *(unsigned char*)0x5346
#define TIM4_PSCR *(unsigned char*)0x5347
#define TIM4_ARR *(unsigned char*)0x5348


/* ADC 1 */
#define ADC_DB0RH *(unsigned char*)0x53E0
#define ADC_DB0RL *(unsigned char*)0x53E1
#define ADC_DB1RH *(unsigned char*)0x53E2
#define ADC_DB1RL *(unsigned char*)0x53E3
#define ADC_DB2RH *(unsigned char*)0x53E4
#define ADC_DB2RL *(unsigned char*)0x53E5
#define ADC_DB3RH *(unsigned char*)0x53E6
#define ADC_DB3RL *(unsigned char*)0x53E7
#define ADC_DB4RH *(unsigned char*)0x53E8
#define ADC_DB4RL *(unsigned char*)0x53E9
#define ADC_DB5RH *(unsigned char*)0x53EA
#define ADC_DB5RL *(unsigned char*)0x53EB
#define ADC_DB6RH *(unsigned char*)0x53EC
#define ADC_DB6RL *(unsigned char*)0x53ED
#define ADC_DB7RH *(unsigned char*)0x53EE
#define ADC_DB7RL *(unsigned char*)0x53EF
#define ADC_DB8RH *(unsigned char*)0x53F0
#define ADC_DB8RL *(unsigned char*)0x53F1
#define ADC_DB9RH *(unsigned char*)0x53F2
#define ADC_DB9RL *(unsigned char*)0x53F3

#define ADC_CSR *(unsigned char*)5400
#define ADC_CR1 *(unsigned char*)5401
#define ADC_CR2 *(unsigned char*)5402
#define ADC_CR3 *(unsigned char*)5403
#define ADC_DRH *(unsigned char*)5404
#define ADC_DRL *(unsigned char*)5405
#define ADC_TDRH *(unsigned char*)5406
#define ADC_TDRL *(unsigned char*)5407
#define ADC_HTRH *(unsigned char*)5408
#define ADC_HTRL *(unsigned char*)5409
#define ADC_LTRH *(unsigned char*)540A
#define ADC_LTRL *(unsigned char*)540B
#define ADC_AWSRH *(unsigned char*)540C
#define ADC_AWSRL *(unsigned char*)540D
#define ADC_AWCRH *(unsigned char*)540E
#define ADC_AWCRL *(unsigned char*)540F

#define ADC_CSR_EOC (1 << 7)
#define ADC_CSR_AWD (1 << 6)
#define ADC_CSR_EOCIE (1 << 5)
#define ADC_CSR_AWDIE (1 << 4)
#define ADC_CSR_CH3 (1 << 3)
#define ADC_CSR_CH2 (1 << 2)
#define ADC_CSR_CH1 (1 << 1)
#define ADC_CSR_CH0 (1 << 0)

#define ADC_CR1_SPSEL2 (1 << 6)
#define ADC_CR1_SPSEL1 (1 << 5)
#define ADC_CR1_SPSEL0 (1 << 4)
#define ADC_CR1_CONT (1 << 1)
#define ADC_CR1_ADON (1 << 0)

#define ADC_CR2_EXTTRIG (1 << 6)
#define ADC_CR2_EXTSEL1 (1 << 5)
#define ADC_CR2_EXTSEL0 (1 << 4)
#define ADC_CR2_ALIGN (1 << 3)
#define ADC_CR2_SCAN (1 << 1)

#define ADC_CR3_DBUF (1 << 7)
#define ADC_CR3_DRH (1 << 6)

/* CPU */
#define A *(unsigned char*)7F00
#define PCE *(unsigned char*)7F01
#define PCH *(unsigned char*)7F02
#define PCL *(unsigned char*)7F03
#define XH *(unsigned char*)7F04
#define XL *(unsigned char*)7F05
#define YH *(unsigned char*)7F06
#define YL *(unsigned char*)7F07
#define SPH *(unsigned char*)7F08
#define SPL  *(unsigned char*)7F09
#define CCR  *(unsigned char*)7F0A
#define CFG_CCR  *(unsigned char*)7F60
#define ITC_SPR1  *(unsigned char*)7F70
#define ITC_SPR2  *(unsigned char*)7F71
#define ITC_SPR3  *(unsigned char*)7F72
#define ITC_SPR4  *(unsigned char*)7F73
#define ITC_SPR5  *(unsigned char*)7F74
#define ITC_SPR6  *(unsigned char*)7F75
#define ITC_SPR7  *(unsigned char*)7F76
#define ITC_SPR8  *(unsigned char*)7F77

/* SWIM, Debug */
#define SWIM_CSR  *(unsigned char*)7F80
#define DM_BK1RE  *(unsigned char*)7F90
#define DM_BK1RH  *(unsigned char*)7F91
#define DM_BK1RL  *(unsigned char*)7F92
#define DM_BK2RE  *(unsigned char*)7F93
#define DM_BK2RH  *(unsigned char*)7F94
#define DM_BK2RL  *(unsigned char*)7F95
#define DM_CR1  *(unsigned char*)7F96
#define DM_CR2  *(unsigned char*)7F97
#define DM_CSR1  *(unsigned char*)7F98
#define DM_CSR2  *(unsigned char*)7F99
#define DM_ENFCTR  *(unsigned char*)7F9A

/* Interrupt Vectors */
#define INT_VECTOR_RESET 0x8000
#define INT_VECTOR_TRAP 0x8004
#define INT_VECTOR_TLI 0x8008
#define INT_VECTOR_AWU 0x800C
#define INT_VECTOR_CLK 0x8010
#define INT_VECTOR_EXTI0 0x8014
#define INT_VECTOR_EXTI1 0x8018
#define INT_VECTOR_EXTI2 0x801C
#define INT_VECTOR_EXTI3 0x8020
#define INT_VECTOR_EXTI4 0x8024
#define INT_VECTOR_SPI 0x8030
#define INT_VECTOR_TIM1 0x8034
#define INT_VECTOR_TIM1_CCM 0x8038
#define INT_VECTOR_TIM2 0x803C
#define INT_VECTOR_TIM2_CCM 0x8040
#define INT_VECTOR_UART1_TX_COMPLETE 0x804C
#define INT_VECTOR_UART1_DATA_FULL 0x8050
#define INT_VECTOR_I2C 0x8054
#define INT_VECTOR_ADC1 0x8060
#define INT_VECTOR_TIM4 0x8064
#define INT_VECTOR_FLASH 0x8068

#define nointerrupts() {__asm sim __endasm;}
#define interrupts() {__asm rim __endasm;}

#endif /*__STM8S_H */
