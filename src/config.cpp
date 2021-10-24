#include "config.hpp"

//DIGITAL_SENSOR_PORT DECLARATIONS
static char DSP1 = 'A'; //DIGITAL_SENSOR_PORT1
static char DSP2 = 'B'; //DIGITAL_SENSOR_PORT2
#define DIGITAL_SENSOR_PORT DSP1;
#define DIGITAL_SENSOR_PORT DSP2;

//VARIABLE DECLARATIONS
static int BLMP = 2; //BotLeftMtrPort
static int TLMP = 1; //TopLeftMtrPort
static int BRMP = 9; //BotRightMtrPort
static int TRMP = 8; //TopRightMtrPort
static int BLLP = 11; //BottomLeftLiftPort
static int BRLP = 3; //BottomRightLiftPort
static int TLLP = 15; //TopLeftLiftPort
static int TRLP = 16; //TopRightLiftPort

//MOTOR DELCARATIONS
pros::Motor bot_left_mtr(BLMP);
pros::Motor top_left_mtr(TLMP);
pros::Motor bot_right_mtr(BRMP);
pros::Motor top_right_mtr(TRMP);

pros::Motor left_lift(BLLP);
pros::Motor right_lift(BRLP);
pros::Motor left_lift2(TLLP);
pros::Motor right_lift2(TRLP);

//CONTROLLER DECLARATIONS
pros::Controller master(pros::E_CONTROLLER_MASTER);
float left = master.get_analog(ANALOG_LEFT_Y);
float right = master.get_analog(ANALOG_RIGHT_X);

//MOVEMENT DECLARATIONS
int rmMax = 0;
int fmMax = 0;

int YrmMax = 0;
int YfmMax = 0;

//PISTON DECLARATIONS
pros::ADIDigitalOut piston1 (DSP1);
pros::ADIDigitalOut piston2 (DSP2);
