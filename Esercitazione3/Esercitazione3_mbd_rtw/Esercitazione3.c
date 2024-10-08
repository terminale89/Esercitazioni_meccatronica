/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione3.c
 *
 * Code generated for Simulink model 'Esercitazione3'.
 *
 * Model version                   : 1.14
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Mon Oct  7 17:12:38 2024
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Esercitazione3.h"
#include "rtwtypes.h"
#include "Esercitazione3_private.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define Esercitazio_IN_Normal_stoplight ((uint8_T)3U)
#define Esercitazion_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Esercitazione3_IN_Blind_red    ((uint8_T)1U)
#define Esercitazione3_IN_Blind_yellow ((uint8_T)2U)
#define Esercitazione3_IN_buzzer_off   ((uint8_T)1U)
#define Esercitazione3_IN_buzzer_on    ((uint8_T)2U)
#define Esercitazione3_IN_green_on     ((uint8_T)1U)
#define Esercitazione3_IN_red_on       ((uint8_T)2U)
#define Esercitazione3_IN_yellow_off   ((uint8_T)1U)
#define Esercitazione3_IN_yellow_on    ((uint8_T)3U)
#define Esercitazione3_IN_yellow_on_e  ((uint8_T)2U)

/* Block signals (default storage) */
B_Esercitazione3_T Esercitazione3_B;

/* Block states (default storage) */
DW_Esercitazione3_T Esercitazione3_DW;

/* Real-time model */
static RT_MODEL_Esercitazione3_T Esercitazione3_M_;
RT_MODEL_Esercitazione3_T *const Esercitazione3_M = &Esercitazione3_M_;

/* Model step function */
void Esercitazione3_step(void)
{
  /* S-Function (gpio_s32k_input): '<Root>/sw2' */

  /* GPIPORTC12 signal update */
  Esercitazione3_B.sw2 = (PINS_DRV_ReadPins(PTC) >> 12) & 0x01;

  /* Chart: '<Root>/Chart1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  if (Esercitazione3_DW.temporalCounter_i1 < 31U) {
    Esercitazione3_DW.temporalCounter_i1++;
  }

  if (Esercitazione3_DW.temporalCounter_i2 < 63U) {
    Esercitazione3_DW.temporalCounter_i2++;
  }

  if (Esercitazione3_DW.is_active_c1_Esercitazione3 == 0U) {
    Esercitazione3_DW.is_active_c1_Esercitazione3 = 1U;
    Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazio_IN_Normal_stoplight;
    Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_red_on;
    Esercitazione3_DW.temporalCounter_i1 = 0U;
    Esercitazione3_B.lr = true;
    Esercitazione3_B.lg = false;
    Esercitazione3_B.lb = false;
  } else {
    switch (Esercitazione3_DW.is_c1_Esercitazione3) {
     case Esercitazione3_IN_Blind_red:
      if (Esercitazione3_DW.temporalCounter_i2 >= 50U) {
        Esercitazione3_DW.is_Blind_red = Esercitazion_IN_NO_ACTIVE_CHILD;
        Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazio_IN_Normal_stoplight;
        Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_green_on;
        Esercitazione3_DW.temporalCounter_i1 = 0U;
        Esercitazione3_B.lr = false;
        Esercitazione3_B.lg = true;
        Esercitazione3_B.lb = false;
      } else if (Esercitazione3_DW.is_Blind_red == Esercitazione3_IN_buzzer_off)
      {
        Esercitazione3_B.lb = false;
        if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
          Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lb = true;
        }
      } else {
        /* case IN_buzzer_on: */
        Esercitazione3_B.lb = true;
        if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
          Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_off;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lb = false;
        }
      }
      break;

     case Esercitazione3_IN_Blind_yellow:
      if (Esercitazione3_DW.temporalCounter_i2 >= 10U) {
        Esercitazione3_DW.is_Blind_yellow = Esercitazion_IN_NO_ACTIVE_CHILD;
        Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazione3_IN_Blind_red;
        Esercitazione3_DW.temporalCounter_i2 = 0U;
        Esercitazione3_DW.k = 0.0;
        Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
        Esercitazione3_DW.temporalCounter_i1 = 0U;
        Esercitazione3_B.lb = true;
      } else if (Esercitazione3_DW.is_Blind_yellow ==
                 Esercitazione3_IN_yellow_off) {
        Esercitazione3_B.lg = false;
        Esercitazione3_B.lr = false;
        if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
          Esercitazione3_DW.is_Blind_yellow = Esercitazione3_IN_yellow_on_e;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = true;
          Esercitazione3_B.lr = true;
        }
      } else {
        /* case IN_yellow_on: */
        Esercitazione3_B.lg = true;
        Esercitazione3_B.lr = true;
        if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
          Esercitazione3_DW.is_Blind_yellow = Esercitazione3_IN_yellow_off;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = false;
          Esercitazione3_B.lr = false;
        }
      }
      break;

     default:
      /* case IN_Normal_stoplight: */
      switch (Esercitazione3_DW.is_Normal_stoplight) {
       case Esercitazione3_IN_green_on:
        Esercitazione3_B.lr = false;
        Esercitazione3_B.lg = true;
        Esercitazione3_B.lb = false;
        if (Esercitazione3_B.sw2) {
          Esercitazione3_DW.is_Normal_stoplight =
            Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_c1_Esercitazione3 =
            Esercitazione3_IN_Blind_yellow;
          Esercitazione3_DW.temporalCounter_i2 = 0U;
          Esercitazione3_DW.is_Blind_yellow = Esercitazione3_IN_yellow_on_e;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = true;
          Esercitazione3_B.lr = true;
        } else if (Esercitazione3_DW.temporalCounter_i1 >= 20U) {
          Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_yellow_on;
          Esercitazione3_DW.temporalCounter_i2 = 0U;
          Esercitazione3_B.lb = false;
          Esercitazione3_DW.k = 0.0;
          Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_on_e;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = true;
          Esercitazione3_B.lr = true;
        }
        break;

       case Esercitazione3_IN_red_on:
        Esercitazione3_B.lr = true;
        Esercitazione3_B.lg = false;
        Esercitazione3_B.lb = false;
        if (Esercitazione3_B.sw2) {
          Esercitazione3_DW.is_Normal_stoplight =
            Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazione3_IN_Blind_red;
          Esercitazione3_DW.temporalCounter_i2 = 0U;
          Esercitazione3_DW.k = 0.0;
          Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lb = true;
        } else if (Esercitazione3_DW.temporalCounter_i1 >= 25U) {
          Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_green_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lr = false;
          Esercitazione3_B.lg = true;
          Esercitazione3_B.lb = false;
        }
        break;

       default:
        /* case IN_yellow_on: */
        Esercitazione3_B.lb = false;
        if ((Esercitazione3_DW.temporalCounter_i2 >= 10U) &&
            (Esercitazione3_DW.k == 1.0)) {
          Esercitazione3_DW.is_yellow_on = Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_Normal_stoplight =
            Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazione3_IN_Blind_red;
          Esercitazione3_DW.temporalCounter_i2 = 0U;
          Esercitazione3_DW.k = 0.0;
          Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lb = true;
        } else if (Esercitazione3_DW.temporalCounter_i2 >= 10U) {
          Esercitazione3_DW.is_yellow_on = Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_red_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lr = true;
          Esercitazione3_B.lg = false;
          Esercitazione3_B.lb = false;
        } else {
          Esercitazione3_DW.k = Esercitazione3_B.sw2;
          if (Esercitazione3_DW.is_yellow_on == Esercitazione3_IN_yellow_off) {
            Esercitazione3_B.lg = false;
            Esercitazione3_B.lr = false;
            if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
              Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_on_e;
              Esercitazione3_DW.temporalCounter_i1 = 0U;
              Esercitazione3_B.lg = true;
              Esercitazione3_B.lr = true;
            }
          } else {
            /* case IN_yellow_on: */
            Esercitazione3_B.lg = true;
            Esercitazione3_B.lr = true;
            if (Esercitazione3_DW.temporalCounter_i1 >= 3U) {
              Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_off;
              Esercitazione3_DW.temporalCounter_i1 = 0U;
              Esercitazione3_B.lg = false;
              Esercitazione3_B.lr = false;
            }
          }
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* S-Function (gpio_s32k_output): '<Root>/Blue_led' */

  /* GPOPORTD0 Data Signal Update */
  if (Esercitazione3_B.lb) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* S-Function (gpio_s32k_output): '<Root>/Green_led' */

  /* GPOPORTD16 Data Signal Update */
  if (Esercitazione3_B.lg) {
    PINS_DRV_SetPins(PTD, 1UL<<16);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<16);
  }

  /* S-Function (gpio_s32k_output): '<Root>/Red_led' */

  /* GPOPORTD15 Data Signal Update */
  if (Esercitazione3_B.lr) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }
}

/* Model initialize function */
void Esercitazione3_initialize(void)
{
  /* Start for S-Function (gpio_s32k_input): '<Root>/sw2' */
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Blue_led' */
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Green_led' */
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

  /* Start for S-Function (gpio_s32k_output): '<Root>/Red_led' */
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
void Esercitazione3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
