/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "KIMM_CAR_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void KIMM_CAR_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *KIMM_CAR_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"abs(body_Model.body_fixed_dx) < 0.05 and abs(body_Model.body_fixed_dy) < 0.05",
  "abs(ackerman_Steering_Model.tmp_left) < 0.99",
  "abs(ackerman_Steering_Model.tmp_right) < 0.99",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 4000.0",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 4500.0",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 9000.0",
  "tire_rear_left.gap < 0.0",
  "tire_rear_right.gap < 0.0",
  "tire_front_right.gap < 0.0",
  "tire_front_left.gap < 0.0",
  "abs(body_Model.rear_right_dx) > 1e-06",
  "abs(body_Model.rear_left_dy) > 1e-06",
  "tire_rear_right.radius * tire_rear_right.d_roll > body_Model.rear_right_dx",
  "abs(tire_rear_right.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.rear_right_dx) < 0.05 and abs(tire_rear_right.radius * tire_rear_right.d_roll) < 0.08",
  "tire_front_right.radius * tire_front_right.d_roll > body_Model.front_right_vx",
  "abs(tire_front_right.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.front_right_vx) < 0.05 and abs(tire_front_right.radius * tire_front_right.d_roll) < 0.08",
  "abs(body_Model.front_right_dy) > 1e-06",
  "tire_front_left.radius * tire_front_left.d_roll > body_Model.front_left_vx",
  "abs(tire_front_left.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.front_left_vx) < 0.05 and abs(tire_front_left.radius * tire_front_left.d_roll) < 0.08",
  "abs(body_Model.rear_left_dx) > 1e-06",
  "tire_rear_left.radius * tire_rear_left.d_roll > body_Model.rear_left_dx",
  "abs(tire_rear_left.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.rear_left_dx) < 0.05 and abs(tire_rear_left.radius * tire_rear_left.d_roll) < 0.08"};
  static const int occurEqs0[] = {1,485};
  static const int occurEqs1[] = {1,379};
  static const int occurEqs2[] = {1,385};
  static const int occurEqs3[] = {1,370};
  static const int occurEqs4[] = {1,370};
  static const int occurEqs5[] = {1,370};
  static const int occurEqs6[] = {1,396};
  static const int occurEqs7[] = {1,413};
  static const int occurEqs8[] = {1,430};
  static const int occurEqs9[] = {1,447};
  static const int occurEqs10[] = {1,487};
  static const int occurEqs11[] = {1,487};
  static const int occurEqs12[] = {1,466};
  static const int occurEqs13[] = {1,467};
  static const int occurEqs14[] = {1,469};
  static const int occurEqs15[] = {1,503};
  static const int occurEqs16[] = {1,504};
  static const int occurEqs17[] = {1,506};
  static const int occurEqs18[] = {1,508};
  static const int occurEqs19[] = {1,516};
  static const int occurEqs20[] = {1,517};
  static const int occurEqs21[] = {1,519};
  static const int occurEqs22[] = {1,521};
  static const int occurEqs23[] = {1,471};
  static const int occurEqs24[] = {1,472};
  static const int occurEqs25[] = {1,474};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11,occurEqs12,occurEqs13,occurEqs14,occurEqs15,occurEqs16,occurEqs17,occurEqs18,occurEqs19,occurEqs20,occurEqs21,occurEqs22,occurEqs23,occurEqs24,occurEqs25};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void KIMM_CAR_eqFunction_339(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_340(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_341(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_342(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_344(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_345(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_346(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_347(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_348(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_349(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_350(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_351(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_352(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_353(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_355(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_356(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_357(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_359(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_360(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_361(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_363(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_364(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_365(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_367(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_368(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_369(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_370(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_371(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_372(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_373(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_374(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_375(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_376(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_377(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_378(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_379(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_380(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_381(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_382(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_383(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_384(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_385(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_386(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_387(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_388(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_389(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_390(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_391(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_392(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_393(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_394(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_395(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_396(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_397(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_398(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_399(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_400(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_401(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_402(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_403(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_405(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_406(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_407(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_408(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_409(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_410(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_411(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_412(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_413(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_414(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_415(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_416(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_417(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_418(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_419(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_420(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_422(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_423(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_424(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_425(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_426(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_427(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_428(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_429(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_430(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_431(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_432(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_433(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_434(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_435(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_436(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_437(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_439(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_440(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_441(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_442(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_443(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_444(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_445(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_446(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_447(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_448(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_449(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_450(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_451(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_452(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_453(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_454(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_456(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_457(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_458(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_459(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_460(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_461(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_462(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_463(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_464(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_465(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_466(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_467(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_468(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_470(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_471(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_472(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_473(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_475(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_476(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_477(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_478(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_479(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_480(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_481(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_482(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_483(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_484(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_486(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_487(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_488(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_489(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_490(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_491(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_492(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_493(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_494(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_495(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_496(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_497(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_498(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_499(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_500(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_501(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_502(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_503(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_504(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_505(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_508(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_509(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_510(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_511(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_512(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_513(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_514(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_515(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_516(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_517(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_518(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_521(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_522(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_523(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_524(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_525(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_526(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_527(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_529(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_530(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_531(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_532(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_533(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_534(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_535(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_536(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_538(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_539(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_540(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_541(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_542(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_543(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_544(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_545(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_547(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_548(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_549(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_550(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_551(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_552(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_553(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_554(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_556(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_557(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_558(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_559(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_560(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_561(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_562(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_563(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_564(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_565(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_566(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_567(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_568(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_571(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_572(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_573(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_574(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_575(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_576(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_577(DATA* data, threadData_t *threadData);
extern void KIMM_CAR_eqFunction_578(DATA* data, threadData_t *threadData);

int KIMM_CAR_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  KIMM_CAR_eqFunction_339(data, threadData);

  KIMM_CAR_eqFunction_340(data, threadData);

  KIMM_CAR_eqFunction_341(data, threadData);

  KIMM_CAR_eqFunction_342(data, threadData);

  KIMM_CAR_eqFunction_344(data, threadData);

  KIMM_CAR_eqFunction_345(data, threadData);

  KIMM_CAR_eqFunction_346(data, threadData);

  KIMM_CAR_eqFunction_347(data, threadData);

  KIMM_CAR_eqFunction_348(data, threadData);

  KIMM_CAR_eqFunction_349(data, threadData);

  KIMM_CAR_eqFunction_350(data, threadData);

  KIMM_CAR_eqFunction_351(data, threadData);

  KIMM_CAR_eqFunction_352(data, threadData);

  KIMM_CAR_eqFunction_353(data, threadData);

  KIMM_CAR_eqFunction_355(data, threadData);

  KIMM_CAR_eqFunction_356(data, threadData);

  KIMM_CAR_eqFunction_357(data, threadData);

  KIMM_CAR_eqFunction_359(data, threadData);

  KIMM_CAR_eqFunction_360(data, threadData);

  KIMM_CAR_eqFunction_361(data, threadData);

  KIMM_CAR_eqFunction_363(data, threadData);

  KIMM_CAR_eqFunction_364(data, threadData);

  KIMM_CAR_eqFunction_365(data, threadData);

  KIMM_CAR_eqFunction_367(data, threadData);

  KIMM_CAR_eqFunction_368(data, threadData);

  KIMM_CAR_eqFunction_369(data, threadData);

  KIMM_CAR_eqFunction_370(data, threadData);

  KIMM_CAR_eqFunction_371(data, threadData);

  KIMM_CAR_eqFunction_372(data, threadData);

  KIMM_CAR_eqFunction_373(data, threadData);

  KIMM_CAR_eqFunction_374(data, threadData);

  KIMM_CAR_eqFunction_375(data, threadData);

  KIMM_CAR_eqFunction_376(data, threadData);

  KIMM_CAR_eqFunction_377(data, threadData);

  KIMM_CAR_eqFunction_378(data, threadData);

  KIMM_CAR_eqFunction_379(data, threadData);

  KIMM_CAR_eqFunction_380(data, threadData);

  KIMM_CAR_eqFunction_381(data, threadData);

  KIMM_CAR_eqFunction_382(data, threadData);

  KIMM_CAR_eqFunction_383(data, threadData);

  KIMM_CAR_eqFunction_384(data, threadData);

  KIMM_CAR_eqFunction_385(data, threadData);

  KIMM_CAR_eqFunction_386(data, threadData);

  KIMM_CAR_eqFunction_387(data, threadData);

  KIMM_CAR_eqFunction_388(data, threadData);

  KIMM_CAR_eqFunction_389(data, threadData);

  KIMM_CAR_eqFunction_390(data, threadData);

  KIMM_CAR_eqFunction_391(data, threadData);

  KIMM_CAR_eqFunction_392(data, threadData);

  KIMM_CAR_eqFunction_393(data, threadData);

  KIMM_CAR_eqFunction_394(data, threadData);

  KIMM_CAR_eqFunction_395(data, threadData);

  KIMM_CAR_eqFunction_396(data, threadData);

  KIMM_CAR_eqFunction_397(data, threadData);

  KIMM_CAR_eqFunction_398(data, threadData);

  KIMM_CAR_eqFunction_399(data, threadData);

  KIMM_CAR_eqFunction_400(data, threadData);

  KIMM_CAR_eqFunction_401(data, threadData);

  KIMM_CAR_eqFunction_402(data, threadData);

  KIMM_CAR_eqFunction_403(data, threadData);

  KIMM_CAR_eqFunction_405(data, threadData);

  KIMM_CAR_eqFunction_406(data, threadData);

  KIMM_CAR_eqFunction_407(data, threadData);

  KIMM_CAR_eqFunction_408(data, threadData);

  KIMM_CAR_eqFunction_409(data, threadData);

  KIMM_CAR_eqFunction_410(data, threadData);

  KIMM_CAR_eqFunction_411(data, threadData);

  KIMM_CAR_eqFunction_412(data, threadData);

  KIMM_CAR_eqFunction_413(data, threadData);

  KIMM_CAR_eqFunction_414(data, threadData);

  KIMM_CAR_eqFunction_415(data, threadData);

  KIMM_CAR_eqFunction_416(data, threadData);

  KIMM_CAR_eqFunction_417(data, threadData);

  KIMM_CAR_eqFunction_418(data, threadData);

  KIMM_CAR_eqFunction_419(data, threadData);

  KIMM_CAR_eqFunction_420(data, threadData);

  KIMM_CAR_eqFunction_422(data, threadData);

  KIMM_CAR_eqFunction_423(data, threadData);

  KIMM_CAR_eqFunction_424(data, threadData);

  KIMM_CAR_eqFunction_425(data, threadData);

  KIMM_CAR_eqFunction_426(data, threadData);

  KIMM_CAR_eqFunction_427(data, threadData);

  KIMM_CAR_eqFunction_428(data, threadData);

  KIMM_CAR_eqFunction_429(data, threadData);

  KIMM_CAR_eqFunction_430(data, threadData);

  KIMM_CAR_eqFunction_431(data, threadData);

  KIMM_CAR_eqFunction_432(data, threadData);

  KIMM_CAR_eqFunction_433(data, threadData);

  KIMM_CAR_eqFunction_434(data, threadData);

  KIMM_CAR_eqFunction_435(data, threadData);

  KIMM_CAR_eqFunction_436(data, threadData);

  KIMM_CAR_eqFunction_437(data, threadData);

  KIMM_CAR_eqFunction_439(data, threadData);

  KIMM_CAR_eqFunction_440(data, threadData);

  KIMM_CAR_eqFunction_441(data, threadData);

  KIMM_CAR_eqFunction_442(data, threadData);

  KIMM_CAR_eqFunction_443(data, threadData);

  KIMM_CAR_eqFunction_444(data, threadData);

  KIMM_CAR_eqFunction_445(data, threadData);

  KIMM_CAR_eqFunction_446(data, threadData);

  KIMM_CAR_eqFunction_447(data, threadData);

  KIMM_CAR_eqFunction_448(data, threadData);

  KIMM_CAR_eqFunction_449(data, threadData);

  KIMM_CAR_eqFunction_450(data, threadData);

  KIMM_CAR_eqFunction_451(data, threadData);

  KIMM_CAR_eqFunction_452(data, threadData);

  KIMM_CAR_eqFunction_453(data, threadData);

  KIMM_CAR_eqFunction_454(data, threadData);

  KIMM_CAR_eqFunction_456(data, threadData);

  KIMM_CAR_eqFunction_457(data, threadData);

  KIMM_CAR_eqFunction_458(data, threadData);

  KIMM_CAR_eqFunction_459(data, threadData);

  KIMM_CAR_eqFunction_460(data, threadData);

  KIMM_CAR_eqFunction_461(data, threadData);

  KIMM_CAR_eqFunction_462(data, threadData);

  KIMM_CAR_eqFunction_463(data, threadData);

  KIMM_CAR_eqFunction_464(data, threadData);

  KIMM_CAR_eqFunction_465(data, threadData);

  KIMM_CAR_eqFunction_466(data, threadData);

  KIMM_CAR_eqFunction_467(data, threadData);

  KIMM_CAR_eqFunction_468(data, threadData);

  KIMM_CAR_eqFunction_470(data, threadData);

  KIMM_CAR_eqFunction_471(data, threadData);

  KIMM_CAR_eqFunction_472(data, threadData);

  KIMM_CAR_eqFunction_473(data, threadData);

  KIMM_CAR_eqFunction_475(data, threadData);

  KIMM_CAR_eqFunction_476(data, threadData);

  KIMM_CAR_eqFunction_477(data, threadData);

  KIMM_CAR_eqFunction_478(data, threadData);

  KIMM_CAR_eqFunction_479(data, threadData);

  KIMM_CAR_eqFunction_480(data, threadData);

  KIMM_CAR_eqFunction_481(data, threadData);

  KIMM_CAR_eqFunction_482(data, threadData);

  KIMM_CAR_eqFunction_483(data, threadData);

  KIMM_CAR_eqFunction_484(data, threadData);

  KIMM_CAR_eqFunction_486(data, threadData);

  KIMM_CAR_eqFunction_487(data, threadData);

  KIMM_CAR_eqFunction_488(data, threadData);

  KIMM_CAR_eqFunction_489(data, threadData);

  KIMM_CAR_eqFunction_490(data, threadData);

  KIMM_CAR_eqFunction_491(data, threadData);

  KIMM_CAR_eqFunction_492(data, threadData);

  KIMM_CAR_eqFunction_493(data, threadData);

  KIMM_CAR_eqFunction_494(data, threadData);

  KIMM_CAR_eqFunction_495(data, threadData);

  KIMM_CAR_eqFunction_496(data, threadData);

  KIMM_CAR_eqFunction_497(data, threadData);

  KIMM_CAR_eqFunction_498(data, threadData);

  KIMM_CAR_eqFunction_499(data, threadData);

  KIMM_CAR_eqFunction_500(data, threadData);

  KIMM_CAR_eqFunction_501(data, threadData);

  KIMM_CAR_eqFunction_502(data, threadData);

  KIMM_CAR_eqFunction_503(data, threadData);

  KIMM_CAR_eqFunction_504(data, threadData);

  KIMM_CAR_eqFunction_505(data, threadData);

  KIMM_CAR_eqFunction_508(data, threadData);

  KIMM_CAR_eqFunction_509(data, threadData);

  KIMM_CAR_eqFunction_510(data, threadData);

  KIMM_CAR_eqFunction_511(data, threadData);

  KIMM_CAR_eqFunction_512(data, threadData);

  KIMM_CAR_eqFunction_513(data, threadData);

  KIMM_CAR_eqFunction_514(data, threadData);

  KIMM_CAR_eqFunction_515(data, threadData);

  KIMM_CAR_eqFunction_516(data, threadData);

  KIMM_CAR_eqFunction_517(data, threadData);

  KIMM_CAR_eqFunction_518(data, threadData);

  KIMM_CAR_eqFunction_521(data, threadData);

  KIMM_CAR_eqFunction_522(data, threadData);

  KIMM_CAR_eqFunction_523(data, threadData);

  KIMM_CAR_eqFunction_524(data, threadData);

  KIMM_CAR_eqFunction_525(data, threadData);

  KIMM_CAR_eqFunction_526(data, threadData);

  KIMM_CAR_eqFunction_527(data, threadData);

  KIMM_CAR_eqFunction_529(data, threadData);

  KIMM_CAR_eqFunction_530(data, threadData);

  KIMM_CAR_eqFunction_531(data, threadData);

  KIMM_CAR_eqFunction_532(data, threadData);

  KIMM_CAR_eqFunction_533(data, threadData);

  KIMM_CAR_eqFunction_534(data, threadData);

  KIMM_CAR_eqFunction_535(data, threadData);

  KIMM_CAR_eqFunction_536(data, threadData);

  KIMM_CAR_eqFunction_538(data, threadData);

  KIMM_CAR_eqFunction_539(data, threadData);

  KIMM_CAR_eqFunction_540(data, threadData);

  KIMM_CAR_eqFunction_541(data, threadData);

  KIMM_CAR_eqFunction_542(data, threadData);

  KIMM_CAR_eqFunction_543(data, threadData);

  KIMM_CAR_eqFunction_544(data, threadData);

  KIMM_CAR_eqFunction_545(data, threadData);

  KIMM_CAR_eqFunction_547(data, threadData);

  KIMM_CAR_eqFunction_548(data, threadData);

  KIMM_CAR_eqFunction_549(data, threadData);

  KIMM_CAR_eqFunction_550(data, threadData);

  KIMM_CAR_eqFunction_551(data, threadData);

  KIMM_CAR_eqFunction_552(data, threadData);

  KIMM_CAR_eqFunction_553(data, threadData);

  KIMM_CAR_eqFunction_554(data, threadData);

  KIMM_CAR_eqFunction_556(data, threadData);

  KIMM_CAR_eqFunction_557(data, threadData);

  KIMM_CAR_eqFunction_558(data, threadData);

  KIMM_CAR_eqFunction_559(data, threadData);

  KIMM_CAR_eqFunction_560(data, threadData);

  KIMM_CAR_eqFunction_561(data, threadData);

  KIMM_CAR_eqFunction_562(data, threadData);

  KIMM_CAR_eqFunction_563(data, threadData);

  KIMM_CAR_eqFunction_564(data, threadData);

  KIMM_CAR_eqFunction_565(data, threadData);

  KIMM_CAR_eqFunction_566(data, threadData);

  KIMM_CAR_eqFunction_567(data, threadData);

  KIMM_CAR_eqFunction_568(data, threadData);

  KIMM_CAR_eqFunction_571(data, threadData);

  KIMM_CAR_eqFunction_572(data, threadData);

  KIMM_CAR_eqFunction_573(data, threadData);

  KIMM_CAR_eqFunction_574(data, threadData);

  KIMM_CAR_eqFunction_575(data, threadData);

  KIMM_CAR_eqFunction_576(data, threadData);

  KIMM_CAR_eqFunction_577(data, threadData);

  KIMM_CAR_eqFunction_578(data, threadData);
  
  TRACE_POP
  return 0;
}

int KIMM_CAR_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = LessZC(fabs((data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ), 0.05, data->simulationInfo->storedRelations[0]);
  tmp1 = LessZC(fabs((data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */) ), 0.05, data->simulationInfo->storedRelations[1]);
  gout[0] = ((tmp0 && tmp1)) ? 1 : -1;
  tmp2 = LessZC(fabs((data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */) ), 0.99, data->simulationInfo->storedRelations[2]);
  gout[1] = (tmp2) ? 1 : -1;
  tmp3 = LessZC(fabs((data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */) ), 0.99, data->simulationInfo->storedRelations[3]);
  gout[2] = (tmp3) ? 1 : -1;
  tmp4 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4000.0, data->simulationInfo->storedRelations[4]);
  gout[3] = (tmp4) ? 1 : -1;
  tmp5 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4500.0, data->simulationInfo->storedRelations[5]);
  gout[4] = (tmp5) ? 1 : -1;
  tmp6 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 9000.0, data->simulationInfo->storedRelations[6]);
  gout[5] = (tmp6) ? 1 : -1;
  tmp7 = LessZC((data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[7]);
  gout[6] = (tmp7) ? 1 : -1;
  tmp8 = LessZC((data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[8]);
  gout[7] = (tmp8) ? 1 : -1;
  tmp9 = LessZC((data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[9]);
  gout[8] = (tmp9) ? 1 : -1;
  tmp10 = LessZC((data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[10]);
  gout[9] = (tmp10) ? 1 : -1;
  tmp11 = GreaterZC(fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 1e-06, data->simulationInfo->storedRelations[11]);
  gout[10] = (tmp11) ? 1 : -1;
  tmp12 = GreaterZC(fabs((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ), 1e-06, data->simulationInfo->storedRelations[12]);
  gout[11] = (tmp12) ? 1 : -1;
  tmp13 = GreaterZC(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ), (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) , data->simulationInfo->storedRelations[13]);
  gout[12] = (tmp13) ? 1 : -1;
  tmp14 = GreaterZC(fabs((data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[14]);
  gout[13] = (tmp14) ? 1 : -1;
  tmp15 = LessZC(fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 0.05, data->simulationInfo->storedRelations[15]);
  tmp16 = LessZC(fabs(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[16]);
  gout[14] = ((tmp15 && tmp16)) ? 1 : -1;
  tmp17 = GreaterZC(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ), (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) , data->simulationInfo->storedRelations[17]);
  gout[15] = (tmp17) ? 1 : -1;
  tmp18 = GreaterZC(fabs((data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[18]);
  gout[16] = (tmp18) ? 1 : -1;
  tmp19 = LessZC(fabs((data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ), 0.05, data->simulationInfo->storedRelations[19]);
  tmp20 = LessZC(fabs(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[20]);
  gout[17] = ((tmp19 && tmp20)) ? 1 : -1;
  tmp21 = GreaterZC(fabs((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ), 1e-06, data->simulationInfo->storedRelations[21]);
  gout[18] = (tmp21) ? 1 : -1;
  tmp22 = GreaterZC(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ), (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) , data->simulationInfo->storedRelations[22]);
  gout[19] = (tmp22) ? 1 : -1;
  tmp23 = GreaterZC(fabs((data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[23]);
  gout[20] = (tmp23) ? 1 : -1;
  tmp24 = LessZC(fabs((data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ), 0.05, data->simulationInfo->storedRelations[24]);
  tmp25 = LessZC(fabs(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[25]);
  gout[21] = ((tmp24 && tmp25)) ? 1 : -1;
  tmp26 = GreaterZC(fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 1e-06, data->simulationInfo->storedRelations[26]);
  gout[22] = (tmp26) ? 1 : -1;
  tmp27 = GreaterZC(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ), (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) , data->simulationInfo->storedRelations[27]);
  gout[23] = (tmp27) ? 1 : -1;
  tmp28 = GreaterZC(fabs((data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[28]);
  gout[24] = (tmp28) ? 1 : -1;
  tmp29 = LessZC(fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 0.05, data->simulationInfo->storedRelations[29]);
  tmp30 = LessZC(fabs(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[30]);
  gout[25] = ((tmp29 && tmp30)) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *KIMM_CAR_relationDescription(int i)
{
  const char *res[] = {"abs(body_Model.body_fixed_dx) < 0.05",
  "abs(body_Model.body_fixed_dy) < 0.05",
  "abs(ackerman_Steering_Model.tmp_left) < 0.99",
  "abs(ackerman_Steering_Model.tmp_right) < 0.99",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 4000.0",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 4500.0",
  "abs(rear_open_differential.motor_shaft_rotation_speed) < 9000.0",
  "tire_rear_left.gap < 0.0",
  "tire_rear_right.gap < 0.0",
  "tire_front_right.gap < 0.0",
  "tire_front_left.gap < 0.0",
  "abs(body_Model.rear_right_dx) > 1e-06",
  "abs(body_Model.rear_left_dy) > 1e-06",
  "tire_rear_right.radius * tire_rear_right.d_roll > body_Model.rear_right_dx",
  "abs(tire_rear_right.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.rear_right_dx) < 0.05",
  "abs(tire_rear_right.radius * tire_rear_right.d_roll) < 0.08",
  "tire_front_right.radius * tire_front_right.d_roll > body_Model.front_right_vx",
  "abs(tire_front_right.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.front_right_vx) < 0.05",
  "abs(tire_front_right.radius * tire_front_right.d_roll) < 0.08",
  "abs(body_Model.front_right_dy) > 1e-06",
  "tire_front_left.radius * tire_front_left.d_roll > body_Model.front_left_vx",
  "abs(tire_front_left.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.front_left_vx) < 0.05",
  "abs(tire_front_left.radius * tire_front_left.d_roll) < 0.08",
  "abs(body_Model.rear_left_dx) > 1e-06",
  "tire_rear_left.radius * tire_rear_left.d_roll > body_Model.rear_left_dx",
  "abs(tire_rear_left.longitudinal_slip_ratio) > 1.0",
  "abs(body_Model.rear_left_dx) < 0.05",
  "abs(tire_rear_left.radius * tire_rear_left.d_roll) < 0.08"};
  return res[i];
}

int KIMM_CAR_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  modelica_boolean tmp46;
  modelica_boolean tmp47;
  modelica_boolean tmp48;
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  modelica_boolean tmp58;
  modelica_boolean tmp59;
  modelica_boolean tmp60;
  modelica_boolean tmp61;
  
  if(evalforZeroCross) {
    tmp31 = LessZC(fabs((data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ), 0.05, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp31;
    tmp32 = LessZC(fabs((data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */) ), 0.05, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp32;
    tmp33 = LessZC(fabs((data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */) ), 0.99, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp33;
    tmp34 = LessZC(fabs((data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */) ), 0.99, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp34;
    tmp35 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4000.0, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp35;
    tmp36 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 4500.0, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[5] = tmp36;
    tmp37 = LessZC(fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ), 9000.0, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[6] = tmp37;
    tmp38 = LessZC((data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[7] = tmp38;
    tmp39 = LessZC((data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[8] = tmp39;
    tmp40 = LessZC((data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[9] = tmp40;
    tmp41 = LessZC((data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */) , 0.0, data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[10] = tmp41;
    tmp42 = GreaterZC(fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 1e-06, data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[11] = tmp42;
    tmp43 = GreaterZC(fabs((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ), 1e-06, data->simulationInfo->storedRelations[12]);
    data->simulationInfo->relations[12] = tmp43;
    tmp44 = GreaterZC(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ), (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) , data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[13] = tmp44;
    tmp45 = GreaterZC(fabs((data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[14]);
    data->simulationInfo->relations[14] = tmp45;
    tmp46 = LessZC(fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ), 0.05, data->simulationInfo->storedRelations[15]);
    data->simulationInfo->relations[15] = tmp46;
    tmp47 = LessZC(fabs(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[16]);
    data->simulationInfo->relations[16] = tmp47;
    tmp48 = GreaterZC(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ), (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) , data->simulationInfo->storedRelations[17]);
    data->simulationInfo->relations[17] = tmp48;
    tmp49 = GreaterZC(fabs((data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[18]);
    data->simulationInfo->relations[18] = tmp49;
    tmp50 = LessZC(fabs((data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ), 0.05, data->simulationInfo->storedRelations[19]);
    data->simulationInfo->relations[19] = tmp50;
    tmp51 = LessZC(fabs(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[20]);
    data->simulationInfo->relations[20] = tmp51;
    tmp52 = GreaterZC(fabs((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ), 1e-06, data->simulationInfo->storedRelations[21]);
    data->simulationInfo->relations[21] = tmp52;
    tmp53 = GreaterZC(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ), (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) , data->simulationInfo->storedRelations[22]);
    data->simulationInfo->relations[22] = tmp53;
    tmp54 = GreaterZC(fabs((data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[23]);
    data->simulationInfo->relations[23] = tmp54;
    tmp55 = LessZC(fabs((data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ), 0.05, data->simulationInfo->storedRelations[24]);
    data->simulationInfo->relations[24] = tmp55;
    tmp56 = LessZC(fabs(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[25]);
    data->simulationInfo->relations[25] = tmp56;
    tmp57 = GreaterZC(fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 1e-06, data->simulationInfo->storedRelations[26]);
    data->simulationInfo->relations[26] = tmp57;
    tmp58 = GreaterZC(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ), (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) , data->simulationInfo->storedRelations[27]);
    data->simulationInfo->relations[27] = tmp58;
    tmp59 = GreaterZC(fabs((data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) ), 1.0, data->simulationInfo->storedRelations[28]);
    data->simulationInfo->relations[28] = tmp59;
    tmp60 = LessZC(fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ), 0.05, data->simulationInfo->storedRelations[29]);
    data->simulationInfo->relations[29] = tmp60;
    tmp61 = LessZC(fabs(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) )), 0.08, data->simulationInfo->storedRelations[30]);
    data->simulationInfo->relations[30] = tmp61;
  } else {
    data->simulationInfo->relations[0] = (fabs((data->localData[0]->realVars[215]/* body_Model.body_fixed_dx DUMMY_STATE */) ) < 0.05);
    data->simulationInfo->relations[1] = (fabs((data->localData[0]->realVars[216]/* body_Model.body_fixed_dy DUMMY_STATE */) ) < 0.05);
    data->simulationInfo->relations[2] = (fabs((data->localData[0]->realVars[135]/* ackerman_Steering_Model.tmp_left variable */) ) < 0.99);
    data->simulationInfo->relations[3] = (fabs((data->localData[0]->realVars[136]/* ackerman_Steering_Model.tmp_right variable */) ) < 0.99);
    data->simulationInfo->relations[4] = (fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ) < 4000.0);
    data->simulationInfo->relations[5] = (fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ) < 4500.0);
    data->simulationInfo->relations[6] = (fabs((data->localData[0]->realVars[257]/* rear_open_differential.motor_shaft_rotation_speed variable */) ) < 9000.0);
    data->simulationInfo->relations[7] = ((data->localData[0]->realVars[362]/* tire_rear_left.gap DUMMY_STATE */)  < 0.0);
    data->simulationInfo->relations[8] = ((data->localData[0]->realVars[396]/* tire_rear_right.gap DUMMY_STATE */)  < 0.0);
    data->simulationInfo->relations[9] = ((data->localData[0]->realVars[328]/* tire_front_right.gap DUMMY_STATE */)  < 0.0);
    data->simulationInfo->relations[10] = ((data->localData[0]->realVars[294]/* tire_front_left.gap DUMMY_STATE */)  < 0.0);
    data->simulationInfo->relations[11] = (fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) > 1e-06);
    data->simulationInfo->relations[12] = (fabs((data->localData[0]->realVars[246]/* body_Model.rear_left_dy variable */) ) > 1e-06);
    data->simulationInfo->relations[13] = (((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) ) > (data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) );
    data->simulationInfo->relations[14] = (fabs((data->localData[0]->realVars[399]/* tire_rear_right.longitudinal_slip_ratio variable */) ) > 1.0);
    data->simulationInfo->relations[15] = (fabs((data->localData[0]->realVars[249]/* body_Model.rear_right_dx variable */) ) < 0.05);
    data->simulationInfo->relations[16] = (fabs(((data->simulationInfo->realParameter[239]/* tire_rear_right.radius PARAM */) ) * ((data->localData[0]->realVars[35]/* tire_rear_right.d_roll STATE(1,tire_rear_right.dd_roll) */) )) < 0.08);
    data->simulationInfo->relations[17] = (((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) ) > (data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) );
    data->simulationInfo->relations[18] = (fabs((data->localData[0]->realVars[331]/* tire_front_right.longitudinal_slip_ratio variable */) ) > 1.0);
    data->simulationInfo->relations[19] = (fabs((data->localData[0]->realVars[234]/* body_Model.front_right_vx variable */) ) < 0.05);
    data->simulationInfo->relations[20] = (fabs(((data->simulationInfo->realParameter[203]/* tire_front_right.radius PARAM */) ) * ((data->localData[0]->realVars[25]/* tire_front_right.d_roll STATE(1,tire_front_right.dd_roll) */) )) < 0.08);
    data->simulationInfo->relations[21] = (fabs((data->localData[0]->realVars[232]/* body_Model.front_right_dy variable */) ) > 1e-06);
    data->simulationInfo->relations[22] = (((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) ) > (data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) );
    data->simulationInfo->relations[23] = (fabs((data->localData[0]->realVars[297]/* tire_front_left.longitudinal_slip_ratio variable */) ) > 1.0);
    data->simulationInfo->relations[24] = (fabs((data->localData[0]->realVars[229]/* body_Model.front_left_vx variable */) ) < 0.05);
    data->simulationInfo->relations[25] = (fabs(((data->simulationInfo->realParameter[185]/* tire_front_left.radius PARAM */) ) * ((data->localData[0]->realVars[20]/* tire_front_left.d_roll STATE(1,tire_front_left.dd_roll) */) )) < 0.08);
    data->simulationInfo->relations[26] = (fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) > 1e-06);
    data->simulationInfo->relations[27] = (((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) ) > (data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) );
    data->simulationInfo->relations[28] = (fabs((data->localData[0]->realVars[365]/* tire_rear_left.longitudinal_slip_ratio variable */) ) > 1.0);
    data->simulationInfo->relations[29] = (fabs((data->localData[0]->realVars[245]/* body_Model.rear_left_dx variable */) ) < 0.05);
    data->simulationInfo->relations[30] = (fabs(((data->simulationInfo->realParameter[221]/* tire_rear_left.radius PARAM */) ) * ((data->localData[0]->realVars[30]/* tire_rear_left.d_roll STATE(1,tire_rear_left.dd_roll) */) )) < 0.08);
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

