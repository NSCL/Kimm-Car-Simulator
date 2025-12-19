/* Jacobians 5 */
#include "KIMM_CAR_model.h"
#include "KIMM_CAR_12jac.h"
int KIMM_CAR_functionJacF_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int KIMM_CAR_functionJacD_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int KIMM_CAR_functionJacC_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int KIMM_CAR_functionJacB_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int KIMM_CAR_functionJacA_constantEqns(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = KIMM_CAR_INDEX_JAC_A;
  
  
  TRACE_POP
  return 0;
}

int KIMM_CAR_functionJacA_column(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = KIMM_CAR_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

int KIMM_CAR_initialAnalyticJacobianF(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int KIMM_CAR_initialAnalyticJacobianD(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int KIMM_CAR_initialAnalyticJacobianC(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int KIMM_CAR_initialAnalyticJacobianB(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
OMC_DISABLE_OPT
int KIMM_CAR_initialAnalyticJacobianA(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  const int colPtrIndex[1+38] = {0,2,9,15,11,11,11,11,15,14,14,0,0,10,10,8,8,8,8,2,2,8,9,0,2,2,8,9,0,2,2,9,9,0,2,2,9,9,0};
  const int rowIndex[251] = {0,1,0,2,3,4,5,6,7,20,25,2,3,4,5,6,7,8,20,21,25,26,30,31,35,36,2,3,4,5,6,7,9,21,26,31,36,2,3,4,5,6,7,12,20,25,30,35,2,3,4,5,6,7,10,20,25,30,35,2,3,4,5,6,7,11,20,25,30,35,2,3,4,5,6,7,13,20,21,25,26,30,31,35,36,2,3,4,5,6,7,20,21,25,26,30,31,35,36,2,3,4,5,6,7,20,21,25,26,30,31,35,36,2,3,4,5,6,7,20,25,30,35,2,3,4,5,6,7,21,26,31,36,2,3,4,5,6,7,20,21,2,3,4,5,6,7,25,26,2,3,4,5,6,7,30,31,2,3,4,5,6,7,35,36,19,20,18,19,2,3,4,5,6,7,20,22,2,3,4,5,6,7,14,20,21,24,25,23,24,2,3,4,5,6,7,25,27,2,3,4,5,6,7,15,25,26,29,30,28,29,2,3,4,5,6,7,30,32,35,2,3,4,5,6,7,16,30,31,34,35,33,34,2,3,4,5,6,7,30,35,37,2,3,4,5,6,7,17,35,36};
  int i = 0;
  
  jacobian->sizeCols = 38;
  jacobian->sizeRows = 38;
  jacobian->sizeTmpVars = 0;
  jacobian->seedVars = (modelica_real*) calloc(38,sizeof(modelica_real));
  jacobian->resultVars = (modelica_real*) calloc(38,sizeof(modelica_real));
  jacobian->tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  jacobian->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  jacobian->sparsePattern->leadindex = (unsigned int*) malloc((38+1)*sizeof(unsigned int));
  jacobian->sparsePattern->index = (unsigned int*) malloc(251*sizeof(unsigned int));
  jacobian->sparsePattern->numberOfNonZeros = 251;
  jacobian->sparsePattern->colorCols = (unsigned int*) malloc(38*sizeof(unsigned int));
  jacobian->sparsePattern->maxColors = 23;
  jacobian->constantEqns = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (38+1)*sizeof(unsigned int));
  
  for(i=2;i<38+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 251*sizeof(unsigned int));
  
  /* write color array */
  jacobian->sparsePattern->colorCols[1] = 1;
  jacobian->sparsePattern->colorCols[30] = 2;
  jacobian->sparsePattern->colorCols[31] = 3;
  jacobian->sparsePattern->colorCols[35] = 4;
  jacobian->sparsePattern->colorCols[36] = 5;
  jacobian->sparsePattern->colorCols[25] = 6;
  jacobian->sparsePattern->colorCols[26] = 7;
  jacobian->sparsePattern->colorCols[20] = 8;
  jacobian->sparsePattern->colorCols[21] = 9;
  jacobian->sparsePattern->colorCols[16] = 10;
  jacobian->sparsePattern->colorCols[17] = 11;
  jacobian->sparsePattern->colorCols[14] = 12;
  jacobian->sparsePattern->colorCols[15] = 13;
  jacobian->sparsePattern->colorCols[4] = 14;
  jacobian->sparsePattern->colorCols[2] = 15;
  jacobian->sparsePattern->colorCols[3] = 16;
  jacobian->sparsePattern->colorCols[12] = 17;
  jacobian->sparsePattern->colorCols[8] = 18;
  jacobian->sparsePattern->colorCols[9] = 19;
  jacobian->sparsePattern->colorCols[7] = 20;
  jacobian->sparsePattern->colorCols[13] = 21;
  jacobian->sparsePattern->colorCols[18] = 21;
  jacobian->sparsePattern->colorCols[23] = 21;
  jacobian->sparsePattern->colorCols[33] = 21;
  jacobian->sparsePattern->colorCols[28] = 21;
  jacobian->sparsePattern->colorCols[6] = 22;
  jacobian->sparsePattern->colorCols[10] = 23;
  jacobian->sparsePattern->colorCols[5] = 23;
  jacobian->sparsePattern->colorCols[11] = 23;
  jacobian->sparsePattern->colorCols[22] = 23;
  jacobian->sparsePattern->colorCols[19] = 23;
  jacobian->sparsePattern->colorCols[27] = 23;
  jacobian->sparsePattern->colorCols[24] = 23;
  jacobian->sparsePattern->colorCols[37] = 23;
  jacobian->sparsePattern->colorCols[34] = 23;
  jacobian->sparsePattern->colorCols[32] = 23;
  jacobian->sparsePattern->colorCols[29] = 23;
  jacobian->sparsePattern->colorCols[0] = 23;
  TRACE_POP
  return 0;
}


