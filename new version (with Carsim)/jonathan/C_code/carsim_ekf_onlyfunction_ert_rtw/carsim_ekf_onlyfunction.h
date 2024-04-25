/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: carsim_ekf_onlyfunction.h
 *
 * Code generated for Simulink model 'carsim_ekf_onlyfunction'.
 *
 * Model version                  : 2.12
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Apr 25 20:21:24 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef carsim_ekf_onlyfunction_h_
#define carsim_ekf_onlyfunction_h_
#ifndef carsim_ekf_onlyfunction_COMMON_INCLUDES_
#define carsim_ekf_onlyfunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                            /* carsim_ekf_onlyfunction_COMMON_INCLUDES_ */

#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_dhFEDkxOyzERDayoNvrlfF
#define struct_tag_dhFEDkxOyzERDayoNvrlfF

struct tag_dhFEDkxOyzERDayoNvrlfF
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_dhFEDkxOyzERDayoNvrlfF */

#ifndef typedef_matlabshared_tracking_internal_
#define typedef_matlabshared_tracking_internal_

typedef struct tag_dhFEDkxOyzERDayoNvrlfF matlabshared_tracking_internal_;

#endif                             /* typedef_matlabshared_tracking_internal_ */

#ifndef struct_tag_m0ENlFroL4udBtGWEi2rrF
#define struct_tag_m0ENlFroL4udBtGWEi2rrF

struct tag_m0ENlFroL4udBtGWEi2rrF
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_m0ENlFroL4udBtGWEi2rrF */

#ifndef typedef_matlabshared_tracking_interna_a
#define typedef_matlabshared_tracking_interna_a

typedef struct tag_m0ENlFroL4udBtGWEi2rrF matlabshared_tracking_interna_a;

#endif                             /* typedef_matlabshared_tracking_interna_a */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T ZeroOrderHold1[16];           /* '<S6>/Zero-Order Hold1' */
  real_T TmpRTBAtSimulinkFunctionInport1[3];/* '<Root>/imu signal1' */
  real_T TmpRTBAtSimulinkFunctionInpor_m[3];/* synthesized block */
  real_T P_i[9];                       /* '<S1>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S1>/DataStoreMemory - x' */
  uint32_T state[2];                   /* '<S7>/MATLAB Function1' */
  uint32_T state_j[2];                 /* '<S7>/MATLAB Function1' */
  uint32_T state_jx[625];              /* '<S7>/MATLAB Function1' */
  uint32_T state_i[2];                 /* '<S5>/MATLAB Function' */
  uint32_T state_k[2];                 /* '<S5>/MATLAB Function' */
  uint32_T state_e[625];               /* '<S5>/MATLAB Function' */
  uint32_T method;                     /* '<S7>/MATLAB Function1' */
  uint32_T method_n;                   /* '<S7>/MATLAB Function1' */
  uint32_T state_n;                    /* '<S7>/MATLAB Function1' */
  uint32_T method_a;                   /* '<S5>/MATLAB Function' */
  uint32_T method_p;                   /* '<S5>/MATLAB Function' */
  uint32_T state_o;                    /* '<S5>/MATLAB Function' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<Root>/Gain' */
  const real_T Gain1;                  /* '<Root>/Gain1' */
  const real_T Gain4;                  /* '<Root>/Gain4' */
} ConstB;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID0_2;
      uint8_T TID1_2;
    } RateInteraction;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;
extern const ConstB rtConstB;          /* constant block i/o */

/* Model entry point functions */
extern void carsim_ekf_onlyfunction_initialize(void);
extern void carsim_ekf_onlyfunction_step0(void);
extern void carsim_ekf_onlyfunction_step2(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Add3' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Divide' : Unused code path elimination
 * Block '<Root>/Divide2' : Unused code path elimination
 * Block '<S1>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S1>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<Root>/Gain5' : Unused code path elimination
 * Block '<Root>/Gain9' : Unused code path elimination
 * Block '<Root>/Saturation' : Unused code path elimination
 * Block '<Root>/Saturation2' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Sum' : Unused code path elimination
 * Block '<S5>/Zero-Order Hold3' : Unused code path elimination
 * Block '<Root>/VX error' : Unused code path elimination
 * Block '<Root>/Vx' : Unused code path elimination
 * Block '<Root>/Vx_real' : Unused code path elimination
 * Block '<Root>/Vy' : Unused code path elimination
 * Block '<Root>/Vy error1' : Unused code path elimination
 * Block '<Root>/Vy_ekf' : Unused code path elimination
 * Block '<Root>/Vy_real' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<Root>/Yaw rate' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<Root>/yaw_rate_real' : Unused code path elimination
 * Block '<S1>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S7>/Zero-Order Hold5' : Eliminated since input and output rates are identical
 * Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'carsim_ekf_onlyfunction'
 * '<S1>'   : 'carsim_ekf_onlyfunction/Extended Kalman Filter'
 * '<S2>'   : 'carsim_ekf_onlyfunction/Simulink Function'
 * '<S3>'   : 'carsim_ekf_onlyfunction/Simulink Function1'
 * '<S4>'   : 'carsim_ekf_onlyfunction/Simulink Function2'
 * '<S5>'   : 'carsim_ekf_onlyfunction/Subsystem1'
 * '<S6>'   : 'carsim_ekf_onlyfunction/Wheel covarience'
 * '<S7>'   : 'carsim_ekf_onlyfunction/imu signal1'
 * '<S8>'   : 'carsim_ekf_onlyfunction/wheel speed signal'
 * '<S9>'   : 'carsim_ekf_onlyfunction/Extended Kalman Filter/Correct1'
 * '<S10>'  : 'carsim_ekf_onlyfunction/Extended Kalman Filter/Output'
 * '<S11>'  : 'carsim_ekf_onlyfunction/Extended Kalman Filter/Predict'
 * '<S12>'  : 'carsim_ekf_onlyfunction/Extended Kalman Filter/Output/MATLAB Function'
 * '<S13>'  : 'carsim_ekf_onlyfunction/Simulink Function/MATLAB Function1'
 * '<S14>'  : 'carsim_ekf_onlyfunction/Simulink Function/MATLAB Function2'
 * '<S15>'  : 'carsim_ekf_onlyfunction/Simulink Function/MATLAB Function3'
 * '<S16>'  : 'carsim_ekf_onlyfunction/Simulink Function1/MATLAB Function'
 * '<S17>'  : 'carsim_ekf_onlyfunction/Simulink Function2/MATLAB Function3'
 * '<S18>'  : 'carsim_ekf_onlyfunction/Subsystem1/MATLAB Function'
 * '<S19>'  : 'carsim_ekf_onlyfunction/Subsystem1/MATLAB Function2'
 * '<S20>'  : 'carsim_ekf_onlyfunction/Wheel covarience/MATLAB Function2'
 * '<S21>'  : 'carsim_ekf_onlyfunction/Wheel covarience/Ramp'
 * '<S22>'  : 'carsim_ekf_onlyfunction/imu signal1/MATLAB Function1'
 */
#endif                                 /* carsim_ekf_onlyfunction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
