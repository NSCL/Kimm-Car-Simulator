#ifndef KIMM_CAR__H
#define KIMM_CAR__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
real_array omc_calc__coordinate(threadData_t *threadData, real_array _yaw_pitch_roll);
DLLExport
modelica_metatype boxptr_calc__coordinate(threadData_t *threadData, modelica_metatype _yaw_pitch_roll);
static const MMC_DEFSTRUCTLIT(boxvar_lit_calc__coordinate,2,0) {(void*) boxptr_calc__coordinate,0}};
#define boxvar_calc__coordinate MMC_REFSTRUCTLIT(boxvar_lit_calc__coordinate)


DLLExport
real_array omc_change__of__coordinate(threadData_t *threadData, real_array _target_coordinate, real_array _vector_wrt_world);
DLLExport
modelica_metatype boxptr_change__of__coordinate(threadData_t *threadData, modelica_metatype _target_coordinate, modelica_metatype _vector_wrt_world);
static const MMC_DEFSTRUCTLIT(boxvar_lit_change__of__coordinate,2,0) {(void*) boxptr_change__of__coordinate,0}};
#define boxvar_change__of__coordinate MMC_REFSTRUCTLIT(boxvar_lit_change__of__coordinate)


DLLExport
real_array omc_normalized__tire__force__coordinate(threadData_t *threadData, real_array _forward, real_array _left);
DLLExport
modelica_metatype boxptr_normalized__tire__force__coordinate(threadData_t *threadData, modelica_metatype _forward, modelica_metatype _left);
static const MMC_DEFSTRUCTLIT(boxvar_lit_normalized__tire__force__coordinate,2,0) {(void*) boxptr_normalized__tire__force__coordinate,0}};
#define boxvar_normalized__tire__force__coordinate MMC_REFSTRUCTLIT(boxvar_lit_normalized__tire__force__coordinate)


DLLExport
real_array omc_Modelica_Math_Matrices_inv(threadData_t *threadData, real_array _A);
DLLExport
modelica_metatype boxptr_Modelica_Math_Matrices_inv(threadData_t *threadData, modelica_metatype _A);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_inv,2,0) {(void*) boxptr_Modelica_Math_Matrices_inv,0}};
#define boxvar_Modelica_Math_Matrices_inv MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_inv)


DLLExport
real_array omc_Modelica_Math_Matrices_LAPACK_dgetrf(threadData_t *threadData, real_array _A, integer_array *out_pivots, modelica_integer *out_info);
DLLExport
modelica_metatype boxptr_Modelica_Math_Matrices_LAPACK_dgetrf(threadData_t *threadData, modelica_metatype _A, modelica_metatype *out_pivots, modelica_metatype *out_info);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_LAPACK_dgetrf,2,0) {(void*) boxptr_Modelica_Math_Matrices_LAPACK_dgetrf,0}};
#define boxvar_Modelica_Math_Matrices_LAPACK_dgetrf MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_LAPACK_dgetrf)

extern void dgetrf_(int* /*_m*/, int* /*_n*/, double* /*_LU*/, int* /*_lda*/, int* /*_pivots*/, int* /*_info*/);

DLLExport
real_array omc_Modelica_Math_Matrices_LAPACK_dgetri(threadData_t *threadData, real_array _LU, integer_array _pivots, modelica_integer *out_info);
DLLExport
modelica_metatype boxptr_Modelica_Math_Matrices_LAPACK_dgetri(threadData_t *threadData, modelica_metatype _LU, modelica_metatype _pivots, modelica_metatype *out_info);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_LAPACK_dgetri,2,0) {(void*) boxptr_Modelica_Math_Matrices_LAPACK_dgetri,0}};
#define boxvar_Modelica_Math_Matrices_LAPACK_dgetri MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_Matrices_LAPACK_dgetri)

extern void dgetri_(int* /*_n*/, double* /*_inv*/, int* /*_lda*/, int* /*_pivots*/, double* /*_work*/, int* /*_lwork*/, int* /*_info*/);
#include "KIMM_CAR_model.h"


#ifdef __cplusplus
}
#endif
#endif

