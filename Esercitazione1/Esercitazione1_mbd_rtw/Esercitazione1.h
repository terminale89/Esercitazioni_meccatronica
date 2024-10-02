/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione1.h
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

#ifndef RTW_HEADER_Esercitazione1_h_
#define RTW_HEADER_Esercitazione1_h_
#ifndef Esercitazione1_COMMON_INCLUDES_
#define Esercitazione1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#endif                                 /* Esercitazione1_COMMON_INCLUDES_ */

#include "Esercitazione1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T Digital_Input;             /* '<Root>/Digital_Input' */
  boolean_T lr;                        /* '<Root>/Chart' */
  boolean_T lg;                        /* '<Root>/Chart' */
} B_Esercitazione1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_c3_Esercitazione1;        /* '<Root>/Chart' */
  uint8_T is_off_lg;                   /* '<Root>/Chart' */
  uint8_T is_active_c3_Esercitazione1; /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Esercitazione1_T;

/* Real-time Model Data Structure */
struct tag_RTM_Esercitazione1_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Esercitazione1_T Esercitazione1_B;

/* Block states (default storage) */
extern DW_Esercitazione1_T Esercitazione1_DW;

/* Model entry point functions */
extern void Esercitazione1_initialize(void);
extern void Esercitazione1_step(void);
extern void Esercitazione1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Esercitazione1_T *const Esercitazione1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Esercitazione1'
 * '<S1>'   : 'Esercitazione1/Chart'
 */
#endif                                 /* RTW_HEADER_Esercitazione1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
