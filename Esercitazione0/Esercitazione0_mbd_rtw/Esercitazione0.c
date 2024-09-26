/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione0.c
 *
 * Code generated for Simulink model 'Esercitazione0'.
 *
 * Model version                   : 1.3
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Thu Sep 26 17:52:44 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Esercitazione0.h"
#include "rtwtypes.h"
#include "Esercitazione0_private.h"

/* Block signals (default storage) */
B_Esercitazione0_T Esercitazione0_B;

/* Block states (default storage) */
DW_Esercitazione0_T Esercitazione0_DW;

/* Real-time model */
static RT_MODEL_Esercitazione0_T Esercitazione0_M_;
RT_MODEL_Esercitazione0_T *const Esercitazione0_M = &Esercitazione0_M_;

/* Model step function */
void Esercitazione0_step(void)
{
  int32_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Esercitazione0_DW.clockTickCounter < 5) &&
    (Esercitazione0_DW.clockTickCounter >= 0) ? 5 : 0;
  if (Esercitazione0_DW.clockTickCounter >= 9) {
    Esercitazione0_DW.clockTickCounter = 0;
  } else {
    Esercitazione0_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  Esercitazione0_B.DataTypeConversion = (rtb_PulseGenerator != 0);

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */

  /* GPOPORTD16 Data Signal Update */
  if (Esercitazione0_B.DataTypeConversion) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* S-Function (gpio_s32k_input): '<Root>/Digital_Input' */

  /* GPIPORTC12 signal update */
  Esercitazione0_B.Digital_Input = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output' */

  /* GPOPORTD15 Data Signal Update */
  if (Esercitazione0_B.Digital_Input) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }
}

/* Model initialize function */
void Esercitazione0_initialize(void)
{
  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */
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
void Esercitazione0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
