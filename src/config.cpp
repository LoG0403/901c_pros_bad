#include "config.hpp"

//DIGITAL_SENSOR_PORT DECLARATIONS
const char DSP1 = 'A'; //DIGITAL_SENSOR_PORT1
const char DSP2 = 'B'; //DIGITAL_SENSOR_PORT2

//VARIABLE DECLARATIONS
const int BLMP = 6; //BotLeftMtrPort, 6 On Prog Bot, 2 On Main
const int TLMP = 5; //TopLeftMtrPort, 5 OPB, 2 OM
const int BRMP = 9; //BotRightMtrPort, 9 OPB, 9 OM
const int TRMP = 7; //TopRightMtrPort, 7 OPB, 8 OM

const int BLLP = 11; //BottomLeftLiftPort
const int BRLP = 3; //BottomRightLiftPort
const int TLLP = 15; //TopLeftLiftPort
const int TRLP = 16; //TopRightLiftPort

//CONTROLLER DECLARATIONS
pros::Controller master(pros::E_CONTROLLER_MASTER);

//MOTOR DELCARATIONS
//my favorite type of flower <3
pros::Motor bot_left_mtr(BLMP);
pros::Motor top_left_mtr(TLMP);
pros::Motor bot_right_mtr(BRMP);
pros::Motor top_right_mtr(TRMP);

pros::Motor left_lift(BLLP);
pros::Motor right_lift(BRLP);
pros::Motor left_lift2(TLLP);
pros::Motor right_lift2(TRLP);

//MOVEMENT DECLARATIONS
int rmMax = 0;
int fmMax = 0;

int YrmMax = 0;
int YfmMax = 0;

//PISTON DECLARATIONS
pros::ADIDigitalOut piston1 (DSP1);
pros::ADIDigitalOut piston2 (DSP2);
