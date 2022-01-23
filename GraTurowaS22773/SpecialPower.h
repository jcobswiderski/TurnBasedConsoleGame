//
// Created by Admin on 12.01.2022.
//

#ifndef GRATUROWA_SPECIALPOWER_H
#define GRATUROWA_SPECIALPOWER_H

/**
 * Struct for Creature special power.
 *
 * It has properties which are appending when user or enemy activate his special power.
 */
struct SpecialPower {
    std::string name;
    int uses;
    int singleSpecialAttack;
    int strengthToAppend;
    int dexterityToAppend;
    int healthToAppend;
};

#endif //GRATUROWA_SPECIALPOWER_H