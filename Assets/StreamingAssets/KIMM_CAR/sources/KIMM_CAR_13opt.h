#if defined(__cplusplus)
  extern "C" {
#endif
  int KIMM_CAR_mayer(DATA* data, modelica_real** res, short*);
  int KIMM_CAR_lagrange(DATA* data, modelica_real** res, short *, short *);
  int KIMM_CAR_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int KIMM_CAR_setInputData(DATA *data, const modelica_boolean file);
  int KIMM_CAR_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif