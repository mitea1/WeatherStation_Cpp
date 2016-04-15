/**
*****************************************************************************
**
**  File        : main.cpp
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO/STM32
**                STMicroelectronics STM32Lxx Standard Peripherals Library
**
**  Distribution: The file is distributed �as is,� without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
**
*****************************************************************************
*/

/* Includes */
#include <stddef.h>
//#include "stm32l1xx.h"
#include "Test.h"


/* Private typedef */
/* Private define  */
  #define MESSAGE5   " program built with "
  #define MESSAGE6   " Atollic TrueSTUDIO "


/* Private macro */
/* Private variables */


/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
 Test myTest;
 Test yourTest(5);


int main(void)
{

  /* Infinite loop */
  while (1)
  {
	  myTest.doSomething();
	  yourTest.doSomething();
  }
  return 0;
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
extern "C" void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
extern "C" void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}

#ifdef USE_SEE
#ifndef USE_DEFAULT_TIMEOUT_CALLBACK
/**
  * @brief  Basic management of the timeout situation.
  * @param  None.
  * @retval sEE_FAIL.
  */
uint32_t sEE_TIMEOUT_UserCallback(void)
{
  /* Return with error code */
  return sEE_FAIL;
}
#endif
#endif /* USE_SEE */


#ifdef USE_STM32L_DISCOVERY
/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */
extern "C" void RCC_Configuration(void)
{
  /* Enable the GPIOs Clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC| RCC_AHBPeriph_GPIOD| RCC_AHBPeriph_GPIOE| RCC_AHBPeriph_GPIOH, ENABLE);

  /* Enable comparator clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_COMP | RCC_APB1Periph_LCD | RCC_APB1Periph_PWR,ENABLE);

  /* Enable SYSCFG */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG , ENABLE);

  /* Allow access to the RTC */
  PWR_RTCAccessCmd(ENABLE);

  /* Reset Backup Domain */
  RCC_RTCResetCmd(ENABLE);
  RCC_RTCResetCmd(DISABLE);

  /*!< LSE Enable */
  RCC_LSEConfig(RCC_LSE_ON);

  /*!< Wait till LSE is ready */
  while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
  {}

  /*!< LCD Clock Source Selection */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
}

/**
  * @brief  To initialize the I/O ports
  * @caller main
  * @param None
  * @retval None
  */
extern "C" void  Init_GPIOs (void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure User Button pin as input */
  GPIO_InitStructure.GPIO_Pin = USER_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStructure);


/* Configure the GPIO_LED pins  LD3 & LD4*/
  GPIO_InitStructure.GPIO_Pin = LD_GREEN|LD_BLUE;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(LD_PORT, &GPIO_InitStructure);
  GPIO_LOW(LD_PORT,LD_GREEN);
  GPIO_LOW(LD_PORT,LD_BLUE);

/* Configure Output for LCD */
/* Port A */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 |GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init( GPIOA, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource8,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource15,GPIO_AF_LCD) ;

/* Configure Output for LCD */
/* Port B */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9 \
                                 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init( GPIOB, &GPIO_InitStructure);

#ifdef USE_ALL_LCD_SEGMENTS
/**
 * Note!
 * PB3 is connected to C, M, COLON, and DP segments for the second digit on the LCD
 * PB3 is also the SWO pin used for the Serial Wire Viewer (SWV)
 * If PB3 is used by LCD then SWV will not work for the STM32L_DISCOVERY board
 **/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource3,GPIO_AF_LCD) ;
#endif
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource4,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource12,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource13,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource14,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15,GPIO_AF_LCD) ;

/* Configure Output for LCD */
/* Port C*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6 \
                                 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |GPIO_Pin_11 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init( GPIOC, &GPIO_InitStructure);


  GPIO_PinAFConfig(GPIOC, GPIO_PinSource0,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource1,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource2,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource3,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource8,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource9,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,GPIO_AF_LCD) ;
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11,GPIO_AF_LCD) ;
}



/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
extern "C" void Delay(uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);

}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
extern "C" void TimingDelay_Decrement(void)
{

  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
#endif
