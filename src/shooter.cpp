#include "shooter.h"
#include <iostream>
using std::cout;

Roll* Shooter::throw_dice(Die& d1, Die& d2) {
    Roll* new_roll = new Roll(d1, d2);
    new_roll->roll_dice();
    rolls.push_back(new_roll);
    return new_roll;
}

void Shooter::display_rolled_values() {
    for (Roll* roll : rolls) {
        cout<<"Rolled value: "<<roll->roll_value()<<"\n";
    }
}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}
