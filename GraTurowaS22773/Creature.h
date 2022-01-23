#ifndef GRATUROWA_CREATURE_H
#define GRATUROWA_CREATURE_H

#include <string>
#include "CreatureType.h"
#include "SpecialPower.h"

/**
 * Creature class.
 *
 * It allows to create instances of Creature class. Every Creature has access to several methods and properties.
 * Basic properties are name, type, strength and dexterity. There's also properties for level, exprience, lot and
 * upgrade points. Almost every property has its own setter and getter. Class implements also methods to display info
 * about single instances: getInfo() and getShortInfo().
 */
class Creature {
private:
    std::string name;
    CreatureType type;

    int strength; // = damage
    int dexterity; // = chance to avoid attack

    int health;
    int maxHealth;

    int level;
    int experience;
    int upgradePoints;
    int lot; // = exp from Creature after die
    int calculateLot();

    SpecialPower specialPower;
public:
    Creature();
    Creature(std::string name, CreatureType type, int strength, int dexterity, int health);

    void defineSpecialPower(std::string name, int uses, int singleSpecialAttack, int strengthToAppend, int dexterityToAppend, int healthToAppend);
    int useSpecialPower();
    int getSpecialPowerStrength();
    int getSpecialPowerDexterity();
    int getSpecialPowerHealth();
    int getSpecialPowerUses();

    std::string getName();
    std::string getSpecialPowerName();
    std::string getShortInfo();
    std::string getInfo();
    int getExperience();
    int getHealth();
    int getUpgradePoints();
    int getMaxHealth();
    int getStrength();
    int getLevel();
    int getLot();
    int getDexterity();
    CreatureType getType();

    void setHealth(int healthToReclaim);
    void setStrength(int const strength);
    void setDexterity(int const dexterity);
    void setLevel(int const level);

    void addExp(int exp);
    void refillHealth();
    void decreseUpgradePoints();
    void promotion();
    bool isLevelUp(int const expToPromotion);
};

#endif
