/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione3.c
 *
 * Code generated for Simulink model 'Esercitazione3'.
 *
 * Model version                   : 1.31
 * Simulink Coder version          : 9.8 (R2022b) 13-May-2022
 * MBDT for S32K1xx Series Version : 4.3.0 (R2016a-R2022a) 13-Sep-2022
 * C/C++ source code generated on  : Tue Oct  8 19:15:23 2024
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
#define Esercitazio_IN_Normal_stoplight ((uint8_T)2U)
#define Esercitazion_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Esercitazione3_IN_Blind_red    ((uint8_T)1U)
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
  /* Chart: '<Root>/Chart1' */
  if (Esercitazione3_DW.temporalCounter_i1 < 63U) {
    Esercitazione3_DW.temporalCounter_i1++;
  }

  if (Esercitazione3_DW.temporalCounter_i2 < 127U) {
    Esercitazione3_DW.temporalCounter_i2++;
  }

  if (Esercitazione3_DW.is_active_c1_Esercitazione3 == 0U) {
    Esercitazione3_DW.is_active_c1_Esercitazione3 = 1U;
    Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazio_IN_Normal_stoplight;
    Esercitazione3_DW.k = false;
    Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_red_on;
    Esercitazione3_DW.temporalCounter_i1 = 0U;
    Esercitazione3_B.lg = false;
  } else if (Esercitazione3_DW.is_c1_Esercitazione3 ==
             Esercitazione3_IN_Blind_red) {
    if (Esercitazione3_DW.temporalCounter_i2 >= 100U) {
      Esercitazione3_DW.is_Blind_red = Esercitazion_IN_NO_ACTIVE_CHILD;
      Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazio_IN_Normal_stoplight;
      Esercitazione3_DW.k = false;
      Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_green_on;
      Esercitazione3_DW.temporalCounter_i1 = 0U;
      Esercitazione3_B.lg = true;
    } else if (Esercitazione3_DW.trigger) {
      Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazione3_IN_Blind_red;
      Esercitazione3_DW.temporalCounter_i2 = 0U;
      Esercitazione3_DW.trigger = false;
      Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
      Esercitazione3_DW.temporalCounter_i1 = 0U;
    } else if (Esercitazione3_DW.is_Blind_red == Esercitazione3_IN_buzzer_off) {
      if (Esercitazione3_DW.temporalCounter_i1 >= 5U) {
        Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
        Esercitazione3_DW.temporalCounter_i1 = 0U;
      }

      /* case IN_buzzer_on: */
    } else if (Esercitazione3_DW.temporalCounter_i1 >= 5U) {
      Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_off;
      Esercitazione3_DW.temporalCounter_i1 = 0U;
    }
  } else {
    boolean_T guard1;

    /* case IN_Normal_stoplight: */
    guard1 = false;
    switch (Esercitazione3_DW.is_Normal_stoplight) {
     case Esercitazione3_IN_green_on:
      Esercitazione3_B.lg = true;
      if (Esercitazione3_DW.temporalCounter_i1 >= 40U) {
        Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_yellow_on;
        Esercitazione3_DW.temporalCounter_i2 = 0U;
        Esercitazione3_DW.k = false;
        Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_on_e;
        Esercitazione3_DW.temporalCounter_i1 = 0U;
        Esercitazione3_B.lg = true;
      }
      break;

     case Esercitazione3_IN_red_on:
      Esercitazione3_B.lg = false;
      if (Esercitazione3_DW.temporalCounter_i1 >= 50U) {
        Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_green_on;
        Esercitazione3_DW.temporalCounter_i1 = 0U;
        Esercitazione3_B.lg = true;
      }
      break;

     default:
      /* case IN_yellow_on: */
      if (Esercitazione3_DW.temporalCounter_i2 >= 20U) {
        if (Esercitazione3_DW.k) {
          Esercitazione3_DW.is_yellow_on = Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_Normal_stoplight =
            Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_c1_Esercitazione3 = Esercitazione3_IN_Blind_red;
          Esercitazione3_DW.temporalCounter_i2 = 0U;
          Esercitazione3_DW.trigger = false;
          Esercitazione3_DW.is_Blind_red = Esercitazione3_IN_buzzer_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
        } else if (!Esercitazione3_DW.k) {
          Esercitazione3_DW.is_yellow_on = Esercitazion_IN_NO_ACTIVE_CHILD;
          Esercitazione3_DW.is_Normal_stoplight = Esercitazione3_IN_red_on;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = false;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      if (Esercitazione3_DW.is_yellow_on == Esercitazione3_IN_yellow_off) {
        Esercitazione3_B.lg = false;
        if (Esercitazione3_DW.temporalCounter_i1 >= 5U) {
          Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_on_e;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = true;
        }
      } else {
        /* case IN_yellow_on: */
        Esercitazione3_B.lg = true;
        if (Esercitazione3_DW.temporalCounter_i1 >= 5U) {
          Esercitazione3_DW.is_yellow_on = Esercitazione3_IN_yellow_off;
          Esercitazione3_DW.temporalCounter_i1 = 0U;
          Esercitazione3_B.lg = false;
        }
      }
    }
  }

  /* End of Chart: '<Root>/Chart1' */
  /* S-Function (saeroclockpacer): '<Root>/Simulation Pace' */
  /*
   * The Clock Pacer generates no code, it is only active in
   * interpreted simulation.
   */
}

/* Model initialize function */
void Esercitazione3_initialize(void)
{
  /* (no initialization code required) */
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
