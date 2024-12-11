#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
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
		std::cout<<result<<"\n";
	}
}