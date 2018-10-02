/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sinPWM_3f_mukdik.h
 *
 * Code generated for Simulink model 'sinPWM_3f_mukdik'.
 *
 * Model version                  : 1.82
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Oct  1 22:04:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sinPWM_3f_mukdik_h_
#define RTW_HEADER_sinPWM_3f_mukdik_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef sinPWM_3f_mukdik_COMMON_INCLUDES_
# define sinPWM_3f_mukdik_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_Gpio.h"
#include "IQmathLib.h"
#endif                                 /* sinPWM_3f_mukdik_COMMON_INCLUDES_ */

#include "sinPWM_3f_mukdik_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWM_GPIO (void);

/* Block signals (auto storage) */
typedef struct {
  uint16_T innenjnmajdabemenet04095ig69esp;/* '<S1>/innen jön majd a bemenet 0-4095-ig 69-es pin' */
  uint16_T UDC;                        /* '<S2>/UDC ' */
  uint16_T UAC;                        /* '<S2>/UAC ' */
} B_sinPWM_3f_mukdik_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S3>/Delay' */
} DW_sinPWM_3f_mukdik_T;

/* Parameters (auto storage) */
struct P_sinPWM_3f_mukdik_T_ {
  real_T Restart_Value;                /* Expression: 0
                                        * Referenced by: '<S3>/Restart'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 36000
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Finomitas_Value;              /* Expression: 1/10000
                                        * Referenced by: '<S3>/Finomitas'
                                        */
  real_T phaseadjust_Value;            /* Expression: 0.277777
                                        * Referenced by: '<S3>/phase adjust '
                                        */
  real_T maxfreqadjust_Value;          /* Expression: 4
                                        * Referenced by: '<S3>/max freq adjust'
                                        */
  real_T Constant1_Value;              /* Expression: 1/3
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T ABSoffset_Value;              /* Expression: 32000
                                        * Referenced by: '<S1>/ABS offset'
                                        */
  real_T UAC_Value;                    /* Expression: 300
                                        * Referenced by: '<Root>/UAC '
                                        */
  real_T UDC_Value;                    /* Expression: 600
                                        * Referenced by: '<Root>/UDC'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T StrechConst_Value;            /* Expression: 32000
                                        * Referenced by: '<S1>/Strech Const'
                                        */
  real_T Constant_Value;               /* Expression: 4095
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 50
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/4095
                                        * Referenced by: '<S1>/Gain2'
                                        */
  int32_T LookUpTable_tableData[4097]; /* Computed Parameter: LookUpTable_tableData
                                        * Referenced by: '<S7>/Look-Up Table'
                                        */
  uint32_T Point50_Value;              /* Computed Parameter: Point50_Value
                                        * Referenced by: '<S8>/Point50'
                                        */
  uint32_T Point25_Value;              /* Computed Parameter: Point25_Value
                                        * Referenced by: '<S8>/Point25'
                                        */
  uint32_T LookUpTable_bp01Data[4097]; /* Computed Parameter: LookUpTable_bp01Data
                                        * Referenced by: '<S7>/Look-Up Table'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S3>/Delay'
                                        */
  int16_T LookUpTable_tableData_o[33]; /* Computed Parameter: LookUpTable_tableData_o
                                        * Referenced by: '<S11>/Look-Up Table'
                                        */
  uint16_T Point50_Value_e;            /* Computed Parameter: Point50_Value_e
                                        * Referenced by: '<S12>/Point50'
                                        */
  uint16_T Point25_Value_k;            /* Computed Parameter: Point25_Value_k
                                        * Referenced by: '<S12>/Point25'
                                        */
  uint16_T LookUpTable_bp01Data_l[33]; /* Computed Parameter: LookUpTable_bp01Data_l
                                        * Referenced by: '<S11>/Look-Up Table'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sinPWM_3f_mukdik_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_P;

/* Block signals (auto storage) */
extern B_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_B;

/* Block states (auto storage) */
extern DW_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_DW;

/* External function called from main */
extern void sinPWM_3f_mukdik_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void sinPWM_3f_mukdik_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void sinPWM_3f_mukdik_initialize(void);
extern void sinPWM_3f_mukdik_step0(void);
extern void sinPWM_3f_mukdik_step1(void);
extern void sinPWM_3f_mukdik_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sinPWM_3f_mukdik_T *const sinPWM_3f_mukdik_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/-120 fok tolás' : Unused code path elimination
 * Block '<S1>/Add3' : Unused code path elimination
 * Block '<S1>/Base Sin scope' : Unused code path elimination
 * Block '<S1>/Base Sin scope S' : Unused code path elimination
 * Block '<S1>/Base Sin scope1' : Unused code path elimination
 * Block '<S1>/Base Sin scope2' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S1>/Divide2' : Unused code path elimination
 * Block '<S1>/Divide3' : Unused code path elimination
 * Block '<S1>/Final output 3f SCOPE ' : Unused code path elimination
 * Block '<S1>/Product2' : Unused code path elimination
 * Block '<S3>/Counter Scope' : Unused code path elimination
 * Block '<S1>/Sin2 scope ' : Unused code path elimination
 * Block '<S1>/Sin2 scope 4' : Unused code path elimination
 * Block '<S1>/Sin2 scope S' : Unused code path elimination
 * Block '<S10>/Amp50' : Unused code path elimination
 * Block '<S10>/CastU16En16' : Unused code path elimination
 * Block '<S10>/LTEp25' : Unused code path elimination
 * Block '<S10>/LTEp50' : Unused code path elimination
 * Block '<S10>/Negate' : Unused code path elimination
 * Block '<S10>/Point25' : Unused code path elimination
 * Block '<S10>/Point50' : Unused code path elimination
 * Block '<S10>/QuadHandle1' : Unused code path elimination
 * Block '<S10>/QuadHandle2' : Unused code path elimination
 * Block '<S10>/SignCorrected' : Unused code path elimination
 * Block '<S10>/p50mA' : Unused code path elimination
 * Block '<S9>/Look-Up Table' : Unused code path elimination
 */

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
 * '<Root>' : 'sinPWM_3f_mukdik'
 * '<S1>'   : 'sinPWM_3f_mukdik/Ctr_Alg'
 * '<S2>'   : 'sinPWM_3f_mukdik/HW-SW_if.'
 * '<S3>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Rate'
 * '<S4>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine'
 * '<S5>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine S'
 * '<S6>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine T'
 * '<S7>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine/Sine'
 * '<S8>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine/Sine/Handle Quarter Symmetry Sine'
 * '<S9>'   : 'sinPWM_3f_mukdik/Ctr_Alg/Sine S/Sine'
 * '<S10>'  : 'sinPWM_3f_mukdik/Ctr_Alg/Sine S/Sine/Handle Quarter Symmetry Sine'
 * '<S11>'  : 'sinPWM_3f_mukdik/Ctr_Alg/Sine T/Sine'
 * '<S12>'  : 'sinPWM_3f_mukdik/Ctr_Alg/Sine T/Sine/Handle Quarter Symmetry Sine'
 */
#endif                                 /* RTW_HEADER_sinPWM_3f_mukdik_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
