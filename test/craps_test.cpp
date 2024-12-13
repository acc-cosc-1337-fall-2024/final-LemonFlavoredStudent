#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include <iostream>
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify roll returns value between 1-6"){
	Die die1;
	int result;
	srand(time(0));
	for (int i = 0; i < 10; i++){
		result = die1.roll();
		REQUIRE(result<=6);
		REQUIRE(result>=1);
	}
}
TEST_CASE("Verify roll_value returns value between 2-12"){
	Die die1;
	Die die2;
	Roll dice(die1,die2);
	int result;
	srand(time(0));
	for (int i = 0; i < 10; i++){
		dice.roll_dice();
		result = dice.roll_value();
		REQUIRE(result<=12);
		REQUIRE(result>=2);
		//std::cout<<result<<"\n";
	}
}

TEST_CASE("Verify shooter returns a Roll and verify that the roll result has one of the following values: 2-12"){
    Die die1;
    Die die2;
	Shooter shooter;
	int result;
	srand(time(0));
    for (int i = 0; i < 10; ++i){
        Roll* roll=shooter.throw_dice(die1, die2);
        result = roll->roll_value();
        REQUIRE(result>=2);
        REQUIRE(result<=12);
		//std::cout<<result<<"\n";
    }
}

TEST_CASE("Verify ComeOutPhase returns ComeOutPhase get outcomes returns values RollOutcome::natural, RollOutcome::craps, and RollOutcome::point") {
    ComeOutPhase come_out_phase;
    Die die1, die2;
    Roll roll(die1, die2);
    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        RollOutcome outcome = come_out_phase.get_outcome(&roll);
        bool is_valid_outcome = 
            (outcome == RollOutcome::natural) || 
            (outcome == RollOutcome::craps) || 
            (outcome == RollOutcome::point);
        REQUIRE(is_valid_outcome);
    }
}

TEST_CASE("Verify PointPhase returns valid outcomes") {
    int point = 5;
    PointPhase point_phase(point);
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        RollOutcome outcome = point_phase.get_outcome(&roll);
        bool is_valid_outcome = 
            (outcome == RollOutcome::point) || 
            (outcome == RollOutcome::seven_out) || 
            (outcome == RollOutcome::nopoint);
        REQUIRE(is_valid_outcome);
    }
}
