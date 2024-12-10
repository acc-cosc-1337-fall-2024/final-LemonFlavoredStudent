#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify roll returns value between 1-6"){
	Die die1;
	int result;
	for (int i = 0; i < 10; i++){
		result = die1.roll();
		REQUIRE(result<=6&&result>=1);
	}
}