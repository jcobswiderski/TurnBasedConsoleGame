#include "Creature.h"
#include <iostream>

/**
 * Basic constructor.
 *
 * It sets all instance properties to default values.
 */
Creature::Creature() {
    this->name = "undefined";
    this->type = none;
    this->strength = 0;
    this->dexterity = 0;
    this->maxHealth = 0;
    this->health = 0;
    this->level = 0;
    this->experience = 0;
    this->lot = 0;
    this->upgradePoints = 0;
}

/**
 * Perform level promotion.
 *
 * It allows to upgrade Creature level.
 */
void Creature::promotion() {
    this->level++;
    std::cout << "\n" + this->getName() + " level up! (" + std::to_string(this->getLevel()) + ")\n";
    this->upgradePoints++;
}

/**
 * Main constructor.
 *
 * It allows to create instance with defined values.
 */
Creature::Creature(std::string name, CreatureType type, int strength, int dexterity, int maxHealth) {
    this->name = name;
    this->type = type;
    this->strength = strength;
    this->dexterity = dexterity;
    this->health = maxHealth;
    this->maxHealth = maxHealth;
    this->level = 1;
    this->experience = 0;
    this->lot = calculateLot();
    this->upgradePoints = 0;
}

/**
 * Calculate lot from Creature.
 *
 * Calculate lot value after Creature death.
 */
int Creature::calculateLot() {
    return this->getLevel() * (this->getStrength() + 10 * this->getDexterity());
}

/**
 * Getter for lot ratio.
 *
 * Return lot from Creature after death.
 */
int Creature::getLot() {
    return this->lot;
}

/**
 * Updating property after upgrade.
 *
 * Decreasing upgrade points -1.
 */
void Creature::decreseUpgradePoints() {
    this->upgradePoints--;
}

/**
 * Append experience after won.
 */
void Creature::addExp(int exp) {
    this->experience += exp;
}

/**
 * Getter for current Creature level.
 */
int Creature::getLevel() {
    return this->level;
}

/**
 * Makeshift constructor for special power.
 *
 * It allows to define special power and append them to specific Creature.
 */
void Creature::defineSpecialPower(std::string name, int uses, int singleSpecialAttack, int strengthToAppend, int dexterityToAppend, int healthToAppend) {
    this->specialPower.name = name;
    this->specialPower.uses = uses;
    this->specialPower.singleSpecialAttack = singleSpecialAttack;
    this->specialPower.strengthToAppend = strengthToAppend;
    this->specialPower.dexterityToAppend = dexterityToAppend;
    this->specialPower.healthToAppend = healthToAppend;
}

/**
 * Short info about Creature stats.
 */
std::string Creature::getShortInfo() {
    return name + "(" + std::to_string(strength) + "dmg " + std::to_string(health) + "/" + std::to_string(maxHealth) + "hp " + std::to_string(specialPower.uses) + "spec" + ")";
}

/**
 * Calculating is there a need to update user level.
 */
bool Creature::isLevelUp(int const expToPromotion) {
    if(this->getExperience() >= expToPromotion)
        return true;
    return false;
}

/**
 * Experience getter.
 */
int Creature::getExperience() {
    return this->experience;
}

/**
 * Longer info about Creature stats.
 */
std::string Creature::getInfo() {
    return "[" + name + "](" +
           std::to_string(level) + " LVL | " +
           std::to_string(strength) + " STR | " +
           std::to_string(dexterity) + " DEX | " +
           std::to_string(health) + " HP | " +
           specialPower.name + " x" + std::to_string(specialPower.uses) + ")";
}

/**
 * Reset creature health to default state.
 */
void Creature::refillHealth() {
    this->health = this->getMaxHealth();
}

/**
 * Getter for Creature health.
 */
int Creature::getHealth() {
    return this->health;
}

/**
 * Getter for Creature name.
 */
std::string Creature::getName() {
    return this->name;
}

/**
 * Setter for Creature level.
 */
void Creature::setLevel(int const level) {
    this->level = level;
}

/**
 * Setter for Creature health.
 */
void Creature::setHealth(int healthToReclaim) {
    this->health = health - healthToReclaim;

    if(health < 0) {
        this->health = 0;
    }
}

/**
 * Getter for Creature maximal health.
 */
int Creature::getMaxHealth() {
    return this->maxHealth;
}

/**
 * Getter for Creature strength.
 */
int Creature::getStrength() {
    return this->strength;
}

/**
 * Getter for Creature dexterity.
 */
int Creature::getDexterity() {
    return dexterity;
}

/**
 * Getter for Creature type.
 */
CreatureType Creature::getType() {
    return type;
}

/**
 * Performing special power.
 *
 * It allows to permanently append extra stats or temporary increase Creature attack.
 */
int Creature::useSpecialPower() {
    if(this->specialPower.uses < 1) {
        return -1;
    } else {
        this->strength += this->specialPower.strengthToAppend;
        this->dexterity += this->specialPower.dexterityToAppend;
        this->health += this->specialPower.healthToAppend;
        this->specialPower.uses--;

        if(this->specialPower.singleSpecialAttack != 0) {
            return this->specialPower.singleSpecialAttack;
        } else {
            return 0;
        }
    }
}

/**
 * Getter for special power name.
 */
std::string Creature::getSpecialPowerName() {
    return this->specialPower.name;
}

/**
 * Setter for Creature strength.
 */
void Creature::setStrength(int const strength) {
    this->strength = strength;
}

/**
 * Setter for Creature dexterity.
 */
void Creature::setDexterity(const int dexterity) {
    this->dexterity = dexterity;
}

/**
 * Getter for current user upgrade points.
 */
int Creature::getUpgradePoints() {
    return this->upgradePoints;
}

/**
 * Getter for special power strength property.
 */
int Creature::getSpecialPowerStrength() {
    return this->specialPower.strengthToAppend;
}

/**
 * Getter for special power dexterity property.
 */
int Creature::getSpecialPowerDexterity() {
    return this->specialPower.dexterityToAppend;
}

/**
 * Getter for special power health property.
 */
int Creature::getSpecialPowerHealth() {
    return this->specialPower.healthToAppend;
}

/**
 * Getter for special power uses.
 */
int Creature::getSpecialPowerUses() {
    return this->specialPower.uses;
}
