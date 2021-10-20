#include "main.h"

//Tommybot, extinguisher of light, hope, and batteries

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "thanks for nothing");
	pros::lcd::register_btn1_cb(on_center_button);

	#define DIGITAL_SENSOR_PORT 'B';

  pros::ADIDigitalOut piston ('B');
}


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	int BLmtrVal = 2;
	int TLmtrVal = 1;
	int BRmtrVal = 9;
	int TRmtrVal = 7; //9 on main bot

	pros::Motor bot_left_mtr(BLmtrVal);
	pros::Motor top_left_mtr(TLmtrVal);
	pros::Motor bot_right_mtr(BRmtrVal);
	pros::Motor top_right_mtr(TRmtrVal);

	pros::Motor left_lift(11);
	pros::Motor right_lift(3);

	int LL = 11;
	int RL = 3;

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		float left = master.get_analog(ANALOG_LEFT_Y);
		float right = master.get_analog(ANALOG_RIGHT_X);

		int rmMax = 0;
		int fmMax = 0;

		int YrmMax = 0;
		int YfmMax = 0;

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A) == 1){
			pros::c::motor_move_voltage(LL, -12000);
			pros::c::motor_move_voltage(RL, 12000);
		}
		else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) == 1){
			pros::c::motor_move_voltage(LL, 6000);
			pros::c::motor_move_voltage(RL, -6000);
		}

		if(right>0){
			if(YrmMax == 0 && YfmMax == 0){
					YrmMax = -12000;
					YfmMax = 12000;
				pros::c::motor_move_voltage(TLmtrVal, YrmMax);
				pros::c::motor_move_voltage(BLmtrVal, YrmMax);
  			pros::c::delay(2);

				pros::c::motor_move_voltage(BRmtrVal, YfmMax);
				pros::c::motor_move_voltage(TRmtrVal, YfmMax);
  			pros::c::delay(2);
		}
	}
	else if (right < 0){
		YrmMax = 12000;
		YfmMax = -12000;

		pros::c::motor_move_voltage(TLmtrVal, YrmMax);
		pros::c::motor_move_voltage(BLmtrVal, YrmMax);
		pros::c::delay(2);

		pros::c::motor_move_voltage(BRmtrVal, YfmMax);
		pros::c::motor_move_voltage(TRmtrVal, YfmMax);
		pros::c::delay(2);
	}
	else{
		YrmMax = 0;
		YfmMax = 0;
		pros::c::motor_move_voltage(TLmtrVal, YrmMax);
		pros::c::motor_move_voltage(BLmtrVal, YrmMax);
		pros::c::motor_move_voltage(BRmtrVal, YfmMax);
		pros::c::motor_move_voltage(TRmtrVal, YfmMax);
		}
// ***************************************************************************
		if(left > 0){
			  if(rmMax == 0 && fmMax == 0){
					rmMax = -12000;
					fmMax = 12000;
				pros::c::motor_move_voltage(BRmtrVal, rmMax);
  			pros::c::delay(2);
				//pros::c::motor_move_voltage(BRmtrVal, 0);

				pros::c::motor_move_voltage(BLmtrVal, fmMax);
  			pros::c::delay(2);
				//pros::c::motor_move_voltage(BLmtrVal, 0);
			}
		}
			else if (left < 0){
				rmMax = 12000;
				fmMax = -12000;

				pros::c::motor_move_voltage(BRmtrVal, rmMax);
  			pros::c::delay(2);
				//pros::c::motor_move_voltage(BRmtrVal, 0);

				pros::c::motor_move_voltage(BLmtrVal, fmMax);
  			pros::c::delay(2);
			}
			else{
				rmMax = 0;
				fmMax = 0;
				pros::c::motor_move_voltage(BRmtrVal, rmMax);
				pros::c::motor_move_voltage(BLmtrVal, fmMax);
				}
		}




}
		/*
		CONTROLLER BEHAVIOR FUCKY REPORT:
		- Forward/backwards/stopping/turning fully functional (but current iteration is untested)
		- TEST TEST TEST
		 */

		//Pneumatics are declared but not set up
