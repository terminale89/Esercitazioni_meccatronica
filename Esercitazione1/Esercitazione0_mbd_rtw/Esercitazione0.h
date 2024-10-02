/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Esercitazione0.h
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

#ifndef RTW_HEADER_Esercitazione0_h_
#define RTW_HEADER_Esercitazione0_h_
#ifndef Esercitazione0_COMMON_INCLUDES_
#define Esercitazione0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#endif                                 /* Esercitazione0_COMMON_INCLUDES_ */

#include "Esercitazione0_types.h"

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
  boolean_T Digital_Input1;            /* '<Root>/Digital_Input1' */
  boolean_T LogicalOperator6;          /* '<Root>/Logical Operator6' */
  boolean_T LogicalOperator5;          /* '<Root>/Logical Operator5' */
  boolean_T LogicalOperator4;          /* '<Root>/Logical Operator4' */
} B_Esercitazione0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator1' */
  int32_T clockTickCounter_i;          /* '<Root>/Pulse Generator' */
} DW_Esercitazione0_T;

/* Real-time Model Data Structure */
struct tag_RTM_Esercitazione0_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Esercitazione0_T Esercitazione0_B;

/* Block states (default storage) */
extern DW_Esercitazione0_T Esercitazione0_DW;

/* Model entry point functions */
extern void Esercitazione0_initialize(void);
extern void Esercitazione0_step(void);
extern void Esercitazione0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Esercitazione0_T *const Esercitazione0_M;

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
 * '<Root>' : 'Esercitazione0'
 */
#endif                                 /* RTW_HEADER_Esercitazione0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
