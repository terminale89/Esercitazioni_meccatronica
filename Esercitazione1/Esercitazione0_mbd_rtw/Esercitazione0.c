/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione0.c
 *
 * Code generated for Simulink model 'Esercitazione0'.
 *
 * Model version                   : 1.6
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Tue Oct  1 18:01:12 2024
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
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator_tmp;

  /* S-Function (gpio_s32k_input): '<Root>/Digital_Input' */

  /* GPIPORTC12 signal update */
  Esercitazione0_B.Digital_Input = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* S-Function (gpio_s32k_input): '<Root>/Digital_Input1' */

  /* GPIPORTC13 signal update */
  Esercitazione0_B.Digital_Input1 = (PINS_DRV_ReadPins(PTC) >> 13) & 0x01;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Logic: '<Root>/Logical Operator3'
   */
  rtb_LogicalOperator_tmp = !Esercitazione0_B.Digital_Input;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator = (Esercitazione0_DW.clockTickCounter < 1) &&
    (Esercitazione0_DW.clockTickCounter >= 0) ? 5 : 0;
  if (Esercitazione0_DW.clockTickCounter >= 4) {
    Esercitazione0_DW.clockTickCounter = 0;
  } else {
    Esercitazione0_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* Logic: '<Root>/Logical Operator3' */
  rtb_LogicalOperator3 = (rtb_LogicalOperator_tmp ||
    (!Esercitazione0_B.Digital_Input1));

  /* Logic: '<Root>/Logical Operator6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator2'
   */
  Esercitazione0_B.LogicalOperator6 = (rtb_LogicalOperator3 &&
    (rtb_LogicalOperator_tmp && (rtb_PulseGenerator != 0) &&
     Esercitazione0_B.Digital_Input1));

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Esercitazione0_DW.clockTickCounter_i < 5) &&
    (Esercitazione0_DW.clockTickCounter_i >= 0) ? 5 : 0;
  if (Esercitazione0_DW.clockTickCounter_i >= 9) {
    Esercitazione0_DW.clockTickCounter_i = 0;
  } else {
    Esercitazione0_DW.clockTickCounter_i++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Logic: '<Root>/Logical Operator5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator1'
   */
  Esercitazione0_B.LogicalOperator5 = (rtb_LogicalOperator3 &&
    (rtb_LogicalOperator_tmp && (rtb_PulseGenerator != 0)));

  /* Logic: '<Root>/Logical Operator4' */
  Esercitazione0_B.LogicalOperator4 = (Esercitazione0_B.Digital_Input &&
    rtb_LogicalOperator3);

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output' */

  /* GPOPORTD16 Data Signal Update */
  if (Esercitazione0_B.LogicalOperator4) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */

  /* GPOPORTD0 Data Signal Update */
  if (Esercitazione0_B.LogicalOperator5) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* S-Function (gpio_s32k_output): '<Root>/Digital_Output2' */

  /* GPOPORTD15 Data Signal Update */
  if (Esercitazione0_B.LogicalOperator6) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }
}

/* Model initialize function */
void Esercitazione0_initialize(void)
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

  /* Start for S-Function (gpio_s32k_input): '<Root>/Digital_Input1' */
  {
    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTCPin13 = {
      .base = PORTC,
      .pinPortIdx = 13,
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

    /* Initialize GPIPORTC13. */
    PINS_DRV_Init(1, &gpioPORTCPin13);
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Digital_Output1' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin0 = {
      .base = PORTD,
      .pinPortIdx = 0,
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

    /* Initialize GPIPORTD0. */
    PINS_DRV_Init(1, &gpioPORTDPin0);
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
void Esercitazione0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
