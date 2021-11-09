#include "main.h"

//DIGITAL_SENSOR_PORT DECLARATIONS
extern const char DSP1; //DIGITAL_SENSOR_PORT1
extern const char DSP2; //DIGITAL_SENSOR_PORT2

//VARIABLE DECLARATIONS
extern const int BLMP; //BotLeftMtrPort
extern const int TLMP; //TopLeftMtrPort
extern const int BRMP; //BotRightMtrPort
extern const int TRMP; //TopRightMtrPort

extern const int BLLP; //BottomLeftLiftPort
extern const int BRLP; //BottomRightLiftPort
extern const int TLLP; //TopLeftLiftPort
extern const int TRLP; //TopRightLiftPort

//CONTROLLER DECLARATIONS
extern pros::Controller master;
extern float left;
extern float right;

//MOTOR DELCARATIONS
//my favorite type of flower <3
extern pros::Motor bot_left_mtr;
extern pros::Motor top_left_mtr;
extern pros::Motor bot_right_mtr;
extern pros::Motor top_right_mtr;

extern pros::Motor left_lift;
extern pros::Motor right_lift;
extern pros::Motor left_lift2;
extern pros::Motor right_lift2;

//MOVEMENT DECLARATIONS
extern int rmMax;
extern int fmMax;

extern int YrmMax;
extern int YfmMax;

//PISTON DECLARATIONS
extern pros::ADIDigitalOut piston1;
extern pros::ADIDigitalOut piston2;
