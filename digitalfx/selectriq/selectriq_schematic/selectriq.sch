EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Diode:1N4007 D1
U 1 1 616CB060
P 7250 4100
F 0 "D1" V 7296 4020 50  0000 R CNN
F 1 "1N4007" V 7205 4020 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 7250 3925 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 7250 4100 50  0001 C CNN
	1    7250 4100
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:TIP120 Q1
U 1 1 616D0045
P 6700 2600
F 0 "Q1" H 6907 2646 50  0000 L CNN
F 1 "TIP120" H 6907 2555 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6900 2525 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 6700 2600 50  0001 L CNN
	1    6700 2600
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D2
U 1 1 616D715D
P 6900 4100
F 0 "D2" V 6946 4020 50  0000 R CNN
F 1 "1N4007" V 6855 4020 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 6900 3925 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 6900 4100 50  0001 C CNN
	1    6900 4100
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:TIP120 Q2
U 1 1 616D8C12
P 6700 3300
F 0 "Q2" H 6907 3346 50  0000 L CNN
F 1 "TIP120" H 6907 3255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6900 3225 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/TIP120-D.PDF" H 6700 3300 50  0001 L CNN
	1    6700 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3500 6800 3500
Wire Wire Line
	6800 3100 6900 3100
Wire Wire Line
	6800 2400 7250 2400
Wire Wire Line
	7250 4250 7250 4300
$Comp
L Motor:Motor_DC_ALT S2
U 1 1 61704312
P 8850 4200
F 0 "S2" H 8997 4196 50  0000 L CNN
F 1 "Solenoid" H 8997 4105 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_D14mm_H7mm_P10mm" H 8850 4110 50  0001 C CNN
F 3 "~" H 8850 4110 50  0001 C CNN
	1    8850 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 2800 6800 2800
Wire Wire Line
	6100 2800 6100 3500
Wire Wire Line
	6100 3500 6100 4200
Connection ~ 6100 3500
$Comp
L Connector:Screw_Terminal_01x04 J3
U 1 1 617A2C7D
P 5400 4200
F 0 "J3" H 5318 3775 50  0000 C CNN
F 1 "Screw_Terminal_01x04" H 5318 3866 50  0000 C CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x04_P3.50mm_Horizontal" H 5400 4200 50  0001 C CNN
F 3 "~" H 5400 4200 50  0001 C CNN
	1    5400 4200
	-1   0    0    1   
$EndComp
Text Label 4550 4050 0    50   ~ 0
KBD67_PCB_CAPS-
Text Label 4650 4150 0    50   ~ 0
KBD67_PCB_BL+
Wire Wire Line
	6500 3300 6150 3300
Wire Wire Line
	6150 3300 6150 4100
Wire Wire Line
	6150 4100 5600 4100
Wire Wire Line
	6500 2600 6050 2600
Wire Wire Line
	6050 2600 6050 4000
Wire Wire Line
	6050 4000 5600 4000
Wire Wire Line
	5600 4200 6100 4200
Wire Wire Line
	5600 4300 6900 4300
Wire Wire Line
	6900 4250 6900 4300
Connection ~ 6900 4300
Wire Wire Line
	6900 4300 7250 4300
Wire Wire Line
	7250 2400 7250 3300
Wire Wire Line
	6900 3100 6900 3900
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 617E0F35
P 8200 3300
F 0 "J1" H 8280 3246 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8280 3201 50  0001 L CNN
F 2 "" H 8200 3300 50  0001 C CNN
F 3 "~" H 8200 3300 50  0001 C CNN
	1    8200 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 617E2505
P 8200 4100
F 0 "J2" H 8280 4046 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8280 4001 50  0001 L CNN
F 2 "" H 8200 4100 50  0001 C CNN
F 3 "~" H 8200 4100 50  0001 C CNN
	1    8200 4100
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC_ALT S1
U 1 1 61702E68
P 8850 3400
F 0 "S1" H 8997 3396 50  0000 L CNN
F 1 "Solenoid" H 8997 3305 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_D14mm_H7mm_P10mm" H 8850 3310 50  0001 C CNN
F 3 "~" H 8850 3310 50  0001 C CNN
	1    8850 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	8000 3300 7250 3300
Connection ~ 7250 3300
Wire Wire Line
	7250 3300 7250 3950
Wire Wire Line
	8000 3400 7400 3400
Wire Wire Line
	7400 4300 7250 4300
Connection ~ 7250 4300
Wire Wire Line
	8000 4200 7400 4200
Wire Wire Line
	7400 3400 7400 4200
Connection ~ 7400 4200
Wire Wire Line
	7400 4200 7400 4300
Wire Wire Line
	8000 4100 7900 4100
Wire Wire Line
	7900 4100 7900 3900
Wire Wire Line
	7900 3900 6900 3900
Connection ~ 6900 3900
Wire Wire Line
	6900 3900 6900 3950
Wire Wire Line
	8850 3100 8200 3100
Wire Wire Line
	8200 3100 8200 3250
Wire Wire Line
	8850 3600 8200 3600
Wire Wire Line
	8200 3600 8200 3450
Wire Wire Line
	8850 3900 8200 3900
Wire Wire Line
	8200 3900 8200 4050
Wire Wire Line
	8850 4400 8200 4400
Wire Wire Line
	8200 4400 8200 4250
Text Label 4650 4350 0    50   ~ 0
KBD67_PCB_VCC
Text Label 4650 4250 0    50   ~ 0
KBD67_PCB_GND
$EndSCHEMATC
