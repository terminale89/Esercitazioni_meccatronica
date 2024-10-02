/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione1.c
 *
 * Code generated for Simulink model 'Esercitazione1'.
 *
 * Model version                   : 1.8
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Tue Oct  1 17:53:05 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Esercitazione1.h"
#include "rtwtypes.h"
#include "Esercitazione1_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Esercitazion_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Esercitazione1_IN_off_g        ((uint8_T)1U)
#define Esercitazione1_IN_off_lg       ((uint8_T)1U)
#define Esercitazione1_IN_on_g         ((uint8_T)2U)
#define Esercitazione1_IN_on_r         ((uint8_T)2U)

/* Block signals (default storage) */
B_Esercitazione1_T Esercitazione1_B;

/* Block states (default storage) */
DW_Esercitazione1_T Esercitazione1_DW;

/* Real-time model */
static RT_MODEL_Esercitazione1_T Esercitazione1_M_;
RT_MODEL_Esercitazione1_T *const Esercitazione1_M = &Esercitazione1_M_;

/* Model step function */
void Esercitazione1_step(void)
{
  /* S-Function (gpio_s32k_input): '<Root>/Digital_Input' */

  /* GPIPORTC12 signal update */
  Esercitazione1_B.Digital_Input = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* Chart: '<Root>/Chart' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  if (Esercitazione1_DW.temporalCounter_i1 < 7U) {
    Esercitazione1_DW.temporalCounter_i1++;
  }

  if (Esercitazione1_DW.is_active_c3_Esercitazione1 == 0U) {
    Esercitazione1_DW.is_active_c3_Esercitazione1 = 1U;
    Esercitazione1_DW.is_c3_Esercitazione1 = Esercitazione1_IN_off_lg;
    Esercitazione1_B.lr = false;
    Esercitazione1_DW.is_off_lg = Esercitazione1_IN_on_g;
    Esercitazione1_DW.temporalCounter_i1 = 0U;
    Esercitazione1_B.lg = true;
  } else if (Esercitazione1_DW.is_c3_Esercitazione1 == Esercitazione1_IN_off_lg)
  {
    Esercitazione1_B.lr = false;
    if (Esercitazione1_B.Digital_Input) {
      Esercitazione1_DW.is_off_lg = Esercitazion_IN_NO_ACTIVE_CHILD;
      Esercitazione1_DW.is_c3_Esercitazione1 = Esercitazione1_IN_on_r;
      Esercitazione1_B.lr = true;
      Esercitazione1_B.lg = false;
    } else if (Esercitazione1_DW.is_off_lg == Esercitazione1_IN_off_g) {
      Esercitazione1_B.lg = false;
      if (Esercitazione1_DW.temporalCounter_i1 >= 5U) {
        Esercitazione1_DW.is_off_lg = Esercitazione1_IN_on_g;
        Esercitazione1_DW.temporalCounter_i1 = 0U;
        Esercitazione1_B.lg = true;
      }
    } else {
      /* case IN_on_g: */
      Esercitazione1_B.lg = true;
      if (Esercitazione1_DW.temporalCounter_i1 >= 5U) {
        Esercitazione1_DW.is_off_lg = Esercitazione1_IN_off_g;
        Esercitazione1_DW.temporalCounter_i1 = 0U;
        Esercitazione1_B.lg = false;
      }
    }
  } else {
    /* case IN_on_r: */
    Esercitazione1_B.lr = true;
    Esercitazione1_B.lg = false;
    if (!Esercitazione1_B.Digital_Input) {
      Esercitazione1_DW.is_c3_Esercitazione1 = Esercitazione1_IN_off_lg;
      Esercitazione1_B.lr = false;
      Esercitazione1_DW.is_off_lg = Esercitazione1_IN_on_g;
      Esercitazione1_DW.temporalCounter_i1 = 0U;
      Esercitazione1_B.lg = true;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output' */

  /* GPOPORTD16 Data Signal Update */
  if (Esercitazione1_B.lg) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output2' */

  /* GPOPORTD15 Data Signal Update */
  if (Esercitazione1_B.lr) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }
}

/* Model initialize function */
void Esercitazione1_initialize(void)
{
  /* Start for S-Function (gpio_s32k_input): '<Root>/Digital_Input' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTCPin12 = {
      .base = PORTC,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTC,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTC12. */
    PINS_DRV_Init(1, &gpioPORTCPin12);
  }

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin16 = {
      .base = PORTD,
      .pinPortIdx = 16,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD16. */
    PINS_DRV_Init(1, &gpioPORTDPin16);
  }

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output2' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin15 = {
      .base = PORTD,
      .pinPortIdx = 15,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
      .initValue = 0U
    };

    /* Initialize GPIPORTD15. */
    PINS_DRV_Init(1, &gpioPORTDPin15);
  }
}

/* Model terminate function */
void Esercitazione1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
