#include <iostream>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	std::srand(std::time(0));

    Die die1;
    Die die2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out_phase;
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || 
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        std::cout << "Rolled: " << rolled_value << " - Roll again\n";
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    std::cout << "Rolled: " << rolled_value << " - Start of point phase\n";
    std::cout << "Roll until " << rolled_value << " or 7 is rolled\n";

    int point = rolled_value;
    roll = shooter.throw_dice(die1, die2);

    PointPhase point_phase(point);

    while (point_phase.get_outcome(roll) != RollOutcome::seven_out && 
           point_phase.get_outcome(roll) != RollOutcome::point) {
        std::cout << "Rolled: " << roll->roll_value() << " - Roll again\n";
        roll = shooter.throw_dice(die1, die2);
    }


    std::cout << "Rolled: " << roll->roll_value() << " - End of point phase\n";

    std::cout << "Shooter rolled values:\n";
    shooter.display_rolled_values();

	return 0;
}