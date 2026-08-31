# KIMM Car Simulator By-Wire Vehicle Control Command
# Published by Autonomous Driving Stack / Received by Simulator

float32 accel      # 가속 페달 답력 (0.0 ~ 1.0)
float32 brake      # 유압 제동 페달 답력 (0.0 ~ 1.0)
float32 steering   # 전륜 조향각 (-1.0: 최대 좌회전, +1.0: 최대 우회전)
int32 gear         # 전자식 변속 기어 (0: Park, 1: Drive, -1: Reverse)
