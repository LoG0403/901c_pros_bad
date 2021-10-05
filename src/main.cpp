#include "main.h"

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
	pros::lcd::set_text(1, "Stay Schemin!");
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
	int TRmtrVal = 10;

	pros::Motor bot_left_mtr(BLmtrVal);
	pros::Motor top_left_mtr(TLmtrVal);
	pros::Motor bot_right_mtr(BRmtrVal);
	pros::Motor top_right_mtr(TRmtrVal);

	pros::Motor left_lift(11);
	pros::Motor right_lift(3);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		float left = master.get_analog(ANALOG_LEFT_Y);
		float right = master.get_analog(ANALOG_RIGHT_Y);

		//pros::E_CONTROLLER_ANALOG_LEFT_Y != master.get_analog(ANALOG_LEFT_Y)

		float negativeL = 0.0-left;
		float negativeR = 0.0-right;

		while(right > 0 or right < 0){
		pros::delay(20);
		pros::c::motor_move(-BLmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		pros::c::motor_move(TLmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		pros::c::motor_move(-BRmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		pros::c::motor_move(TRmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    pros::delay(2);
		}

		while(left > 0 or left < 0){
		pros::delay(20);
		pros::c::motor_move(-BLmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y));
		pros::c::motor_move(-TLmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y));
		pros::c::motor_move(BRmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y));
		pros::c::motor_move(TRmtrVal,pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y));
    pros::delay(2);
		}

		//CONTROLLER BEHAVIOR FUCKY: left stick still jams, and the program only works with one stick at a time, but donuts are functional
		//Pneumatics are declared but not set up

	}
}
