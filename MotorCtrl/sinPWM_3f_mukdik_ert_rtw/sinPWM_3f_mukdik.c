/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sinPWM_3f_mukdik.c
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

#include "sinPWM_3f_mukdik.h"
#include "sinPWM_3f_mukdik_private.h"

/* Block signals (auto storage) */
B_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_B;

/* Block states (auto storage) */
DW_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_DW;

/* Real-time model */
RT_MODEL_sinPWM_3f_mukdik_T sinPWM_3f_mukdik_M_;
RT_MODEL_sinPWM_3f_mukdik_T *const sinPWM_3f_mukdik_M = &sinPWM_3f_mukdik_M_;
static void rate_monotonic_scheduler(void);
uint32_T plook_u32u32u64n32_evenc_f(uint32_T u, uint32_T bp0, uint32_T bpSpace,
  uint32_T maxIndex, uint64_T *fraction)
{
  uint32_T bpIndex;
  uint32_T uAdjust;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'floor'
   */
  if (u <= bp0) {
    bpIndex = 0UL;
    *fraction = 0ULL;
  } else {
    uAdjust = u - bp0;
    bpIndex = uAdjust / bpSpace;
    if (bpIndex < maxIndex) {
      *fraction = ((uint64_T)(uAdjust - bpIndex * bpSpace) << 32U) / bpSpace;
    } else {
      bpIndex = maxIndex - 1UL;
      *fraction = 4294967296ULL;
    }
  }

  return bpIndex;
}

int32_T intrp1d_s32s64s64u32u64n32l_f(uint32_T bpIndex, uint64_T frac, const
  int32_T table[])
{
  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'floor'
     Overflow mode: 'wrapping'
   */
  return (int32_T)((((int64_T)table[bpIndex + 1UL] - table[bpIndex]) * (int64_T)
                    frac) >> 32U) + table[bpIndex];
}

uint32_T plook_u32u16u64n48_evenc_f(uint16_T u, uint16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint64_T *fraction)
{
  uint32_T bpIndex;
  uint16_T uAdjust;
  uint16_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'floor'
   */
  if (u <= bp0) {
    bpIndex = 0UL;
    *fraction = 0ULL;
  } else {
    uAdjust = u - bp0;
    fbpIndex = uAdjust / bpSpace;
    if (fbpIndex < maxIndex) {
      bpIndex = fbpIndex;
      *fraction = ((uint64_T)(uAdjust - (uint16_T)bpIndex * bpSpace) << 48U) /
        bpSpace;
    } else {
      bpIndex = maxIndex - 1UL;
      *fraction = 281474976710656ULL;
    }
  }

  return bpIndex;
}

int16_T intrp1d_s16s32s32u32u64n48l_f(uint32_T bpIndex, uint64_T frac, const
  int16_T table[])
{
  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'floor'
     Overflow mode: 'wrapping'
   */
  return (int16_T)((((int32_T)table[bpIndex + 1UL] - table[bpIndex]) * (int64_T)
                    frac) >> 48U) + table[bpIndex];
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void sinPWM_3f_mukdik_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(sinPWM_3f_mukdik_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sinPWM_3f_mukdik_M->Timing.TaskCounters.TID[1])++;
  if ((sinPWM_3f_mukdik_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    sinPWM_3f_mukdik_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void sinPWM_3f_mukdik_step0(void)      /* Sample time: [0.0001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Add4;
  real_T rtb_Add;
  uint64_T frac;
  real_T rtb_Switch;
  real32_T rtb_Divide4;
  boolean_T rtb_LTEp50;
  uint32_T rtb_CastU16En16;
  int32_T rtb_LookUpTable;
  uint16_T rtb_CastU16En16_c;
  int16_T rtb_LookUpTable_g;
  real_T tmp;
  real32_T tmp_0;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Restart'
   *  Delay: '<S3>/Delay'
   */
  if (sinPWM_3f_mukdik_DW.Delay_DSTATE > sinPWM_3f_mukdik_P.Switch_Threshold) {
    rtb_Switch = sinPWM_3f_mukdik_P.Restart_Value;
  } else {
    rtb_Switch = sinPWM_3f_mukdik_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Product: '<S3>/Divide6' incorporates:
   *  Constant: '<S3>/Finomitas'
   *  Constant: '<S3>/max freq adjust'
   *  Constant: '<S3>/phase adjust '
   */
  rtb_Divide4 = (real32_T)((real32_T)((real32_T)(rtb_Switch *
    sinPWM_3f_mukdik_P.Finomitas_Value) * sinPWM_3f_mukdik_P.phaseadjust_Value) *
    sinPWM_3f_mukdik_P.maxfreqadjust_Value);

  /* DataTypeConversion: '<S8>/CastU16En16' */
  tmp_0 = (real32_T)floor(rtb_Divide4 * 4.2949673E+9F);
  if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = (real32_T)fmod(tmp_0, 4.294967296E+9);
  }

  rtb_CastU16En16 = tmp_0 < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-tmp_0 :
    (uint32_T)tmp_0;

  /* End of DataTypeConversion: '<S8>/CastU16En16' */

  /* RelationalOperator: '<S8>/LTEp50' incorporates:
   *  Constant: '<S8>/Point50'
   */
  rtb_LTEp50 = (rtb_CastU16En16 <= sinPWM_3f_mukdik_P.Point50_Value);

  /* Switch: '<S8>/QuadHandle1' incorporates:
   *  Constant: '<S8>/Point50'
   *  Sum: '<S8>/Amp50'
   */
  if (!rtb_LTEp50) {
    rtb_CastU16En16 -= sinPWM_3f_mukdik_P.Point50_Value;
  }

  /* End of Switch: '<S8>/QuadHandle1' */

  /* Switch: '<S8>/QuadHandle2' incorporates:
   *  Constant: '<S8>/Point25'
   *  Constant: '<S8>/Point50'
   *  RelationalOperator: '<S8>/LTEp25'
   *  Sum: '<S8>/p50mA'
   */
  if (!(rtb_CastU16En16 <= sinPWM_3f_mukdik_P.Point25_Value)) {
    rtb_CastU16En16 = sinPWM_3f_mukdik_P.Point50_Value - rtb_CastU16En16;
  }

  /* End of Switch: '<S8>/QuadHandle2' */

  /* Lookup_n-D: '<S7>/Look-Up Table' */
  rtb_CastU16En16 = plook_u32u32u64n32_evenc_f(rtb_CastU16En16,
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data[0],
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data[1] -
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data[0], 4096UL, &frac);
  rtb_LookUpTable = intrp1d_s32s64s64u32u64n32l_f(rtb_CastU16En16, frac,
    sinPWM_3f_mukdik_P.LookUpTable_tableData);

  /* Switch: '<S8>/SignCorrected' incorporates:
   *  UnaryMinus: '<S8>/Negate'
   */
  if (!rtb_LTEp50) {
    rtb_LookUpTable = -rtb_LookUpTable;
  }

  /* End of Switch: '<S8>/SignCorrected' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<Root>/UDC'
   */
  rtb_Add4 = sinPWM_3f_mukdik_P.Gain_Gain * sinPWM_3f_mukdik_P.UDC_Value;

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<Root>/UAC '
   *  Product: '<S1>/Divide'
   */
  rtb_Add = (real32_T)((real_T)rtb_LookUpTable * 9.3132257461547852E-10 *
                       sinPWM_3f_mukdik_P.UAC_Value) / rtb_Add4;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/ABS offset'
   *  Constant: '<S1>/Strech Const'
   *  Product: '<S1>/Product1'
   */
  rtb_Add = rtb_Add * sinPWM_3f_mukdik_P.StrechConst_Value +
    sinPWM_3f_mukdik_P.ABSoffset_Value;

  /* DataTypeConversion: '<S12>/CastU16En16' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Sum: '<S1>/120 fok tolás'
   */
  tmp = floor((rtb_Divide4 + sinPWM_3f_mukdik_P.Constant1_Value) * 65536.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_CastU16En16_c = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)
    tmp;

  /* End of DataTypeConversion: '<S12>/CastU16En16' */

  /* RelationalOperator: '<S12>/LTEp50' incorporates:
   *  Constant: '<S12>/Point50'
   */
  rtb_LTEp50 = (rtb_CastU16En16_c <= sinPWM_3f_mukdik_P.Point50_Value_e);

  /* Switch: '<S12>/QuadHandle1' incorporates:
   *  Constant: '<S12>/Point50'
   *  Sum: '<S12>/Amp50'
   */
  if (!rtb_LTEp50) {
    rtb_CastU16En16_c -= sinPWM_3f_mukdik_P.Point50_Value_e;
  }

  /* End of Switch: '<S12>/QuadHandle1' */

  /* Switch: '<S12>/QuadHandle2' incorporates:
   *  Constant: '<S12>/Point25'
   *  Constant: '<S12>/Point50'
   *  RelationalOperator: '<S12>/LTEp25'
   *  Sum: '<S12>/p50mA'
   */
  if (!(rtb_CastU16En16_c <= sinPWM_3f_mukdik_P.Point25_Value_k)) {
    rtb_CastU16En16_c = sinPWM_3f_mukdik_P.Point50_Value_e - rtb_CastU16En16_c;
  }

  /* End of Switch: '<S12>/QuadHandle2' */

  /* Lookup_n-D: '<S11>/Look-Up Table' */
  rtb_CastU16En16 = plook_u32u16u64n48_evenc_f(rtb_CastU16En16_c,
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data_l[0],
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data_l[1] -
    sinPWM_3f_mukdik_P.LookUpTable_bp01Data_l[0], 32UL, &frac);
  rtb_LookUpTable_g = intrp1d_s16s32s32u32u64n48l_f(rtb_CastU16En16, frac,
    sinPWM_3f_mukdik_P.LookUpTable_tableData_o);

  /* Switch: '<S12>/SignCorrected' incorporates:
   *  UnaryMinus: '<S12>/Negate'
   */
  if (!rtb_LTEp50) {
    rtb_LookUpTable_g = -rtb_LookUpTable_g;
  }

  /* End of Switch: '<S12>/SignCorrected' */

  /* Sum: '<S1>/Add4' incorporates:
   *  Constant: '<Root>/UAC '
   *  Constant: '<S1>/ABS offset'
   *  Constant: '<S1>/Strech Const'
   *  Product: '<S1>/Divide4'
   *  Product: '<S1>/Divide5'
   *  Product: '<S1>/Product3'
   */
  rtb_Add4 = (real32_T)((real_T)rtb_LookUpTable_g * 6.103515625E-5 *
                        sinPWM_3f_mukdik_P.UAC_Value) / rtb_Add4 *
    sinPWM_3f_mukdik_P.StrechConst_Value + sinPWM_3f_mukdik_P.ABSoffset_Value;

  /* S-Function (c2802xadc): '<S1>/innen jön majd a bemenet 0-4095-ig 69-es pin' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;
    asm(" RPT #22 || NOP");
    sinPWM_3f_mukdik_B.innenjnmajdabemenet04095ig69esp = (AdcResult.ADCRESULT0);
  }

  /* S-Function (c2802xpwm): '<S2>/SPWM R' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_Add);
  }

  /* S-Function (c2802xpwm): '<S2>/SPWM S' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_Add);
  }

  /* S-Function (c2802xpwm): '<S2>/SPWM T' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)(rtb_Add4);
  }

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S3>/Add1'
   */
  sinPWM_3f_mukdik_DW.Delay_DSTATE = sinPWM_3f_mukdik_P.Gain1_Gain *
    sinPWM_3f_mukdik_P.Constant_Value * sinPWM_3f_mukdik_P.Gain2_Gain +
    rtb_Switch;
}

/* Model step function for TID1 */
void sinPWM_3f_mukdik_step1(void)      /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (c2802xaio_di): '<S2>/UDC ' */
  {
    sinPWM_3f_mukdik_B.UDC = GpioDataRegs.AIODAT.bit.AIO6;
  }

  /* S-Function (c2802xaio_di): '<S2>/UAC ' */
  {
    sinPWM_3f_mukdik_B.UAC = GpioDataRegs.AIODAT.bit.AIO2;
  }
}

/* Model initialize function */
void sinPWM_3f_mukdik_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sinPWM_3f_mukdik_M, 0,
                sizeof(RT_MODEL_sinPWM_3f_mukdik_T));

  /* block I/O */
  (void) memset(((void *) &sinPWM_3f_mukdik_B), 0,
                sizeof(B_sinPWM_3f_mukdik_T));

  /* states (dwork) */
  (void) memset((void *)&sinPWM_3f_mukdik_DW, 0,
                sizeof(DW_sinPWM_3f_mukdik_T));

  /* Start for S-Function (c2802xadc): '<S1>/innen jön majd a bemenet 0-4095-ig 69-es pin' */
  InitAdc();
  config_ADC_SOC0 ();

  /* Start for S-Function (c2802xaio_di): '<S2>/UDC ' */
  EALLOW;
  GpioCtrlRegs.AIOMUX1.bit.AIO6 = 0;
  GpioCtrlRegs.AIODIR.bit.AIO6 = 0;
  EDIS;

  /* Start for S-Function (c2802xaio_di): '<S2>/UAC ' */
  EALLOW;
  GpioCtrlRegs.AIOMUX1.bit.AIO2 = 0;
  GpioCtrlRegs.AIODIR.bit.AIO2 = 0;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S2>/SPWM R' */

  /*** Initialize ePWM1 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 64000;           // Time Base Period Register

    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 0;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm1Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select
       EPwm1Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFF) | 0x30;

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0;  // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0;  // Compare B Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0;          // Active Compare B Load
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm1Regs.CMPA.half.CMPA = 32000;  // Counter Compare A Register
    EPwm1Regs.CMPB = 16000;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150;        // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310;       // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm1Regs.DBRED = 0;               // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0;               // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM1SOCA Period Select

       EPwm1Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable

       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1;          // EPWM1INTn Select

       EPwm1Regs.ETPS.bit.INTPRD                = 1;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1001;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm1Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0) | 0x20;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S2>/SPWM S' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 64000;           // Time Base Period Register

    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 0;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm2Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select
       EPwm2Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm2Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFF) | 0x30;

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0;  // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0;  // Compare B Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0;          // Active Compare B Load
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 32000;  // Counter Compare A Register
    EPwm2Regs.CMPB = 16000;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 150;        // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310;       // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm2Regs.DBRED = 0;               // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 0;               // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM2SOCA Period Select

       EPwm2Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable

       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1;          // EPWM2INTn Select

       EPwm2Regs.ETPS.bit.INTPRD                = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1001;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm2Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0) | 0x20;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S2>/SPWM T' */

  /*** Initialize ePWM3 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 64000;           // Time Base Period Register

    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 0;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm3Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select
       EPwm3Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm3Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFF) | 0x30;

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS               = 0;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0;  // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0;  // Compare B Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0;          // Active Compare B Load
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm3Regs.CMPA.half.CMPA = 32000;  // Counter Compare A Register
    EPwm3Regs.CMPB = 16000;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 150;        // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310;       // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm3Regs.DBRED = 0;               // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED = 0;               // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM3SOCA Period Select

       EPwm3Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable

       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN                = 0;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL               = 1;          // EPWM3INTn Select

       EPwm3Regs.ETPS.bit.INTPRD                = 1;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1001;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm3Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0) | 0x20;
    EDIS;
  }

  /* InitializeConditions for Delay: '<S3>/Delay' */
  sinPWM_3f_mukdik_DW.Delay_DSTATE = sinPWM_3f_mukdik_P.Delay_InitialCondition;
}

/* Model terminate function */
void sinPWM_3f_mukdik_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
