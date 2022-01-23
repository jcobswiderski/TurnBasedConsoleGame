#include <iostream>
#include "Creature.h"
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <ctime>

using std::cout, std::endl, std::cin;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
constexpr int userTeamCapacity = 6;
constexpr int enemyTeamCapacity = 4;
constexpr int numberOfCreatures = 24;


/**
 * Initialization of Creatures array.
 *
 * It takes one Creature* pointer to array and fill it with predeifned Creatures.
 */
void initalizeCreaturesArr(Creature* const creatures) {
    creatures[0] = {"Whirlpool", creaturetype_water, 300, 30, 1250};
    creatures[0].defineSpecialPower("Hydro Pump", 1, 0, 100, 0, 200);

    creatures[1] = {"Shark", creaturetype_water, 200, 20, 1000};
    creatures[1].defineSpecialPower("Brine", 2, 480, 0, 0, 100);

    creatures[2] = {"Frosty Hydra", creaturetype_water, 200, 20, 1000};
    creatures[2].defineSpecialPower("Bubble Beam", 3, 300, 50, 0, 0);

    creatures[3] = {"Heartless Pirate", creaturetype_water, 333, 10, 1200};
    creatures[3].defineSpecialPower("Surf", 1, 0, 0, 0, 1000);

    creatures[4] = {"Dirt Centipede", creaturetype_earth, 350, 20, 1400};
    creatures[4].defineSpecialPower("Mud-Slap", 2, 450, 0, 0, 0);

    creatures[5] = {"Dirtworm", creaturetype_earth, 400, 0, 900};
    creatures[5].defineSpecialPower("Eruption", 1, 0, 0, 0, 1100);

    creatures[6] = {"Rattlesnake", creaturetype_earth, 200, 0, 900};
    creatures[6].defineSpecialPower("Terrain Pulse", 1, 0, 200, 0, 1500);

    creatures[7] = {"Giant Earwig", creaturetype_earth, 300, 0, 1200};
    creatures[7].defineSpecialPower("Stored Power", 3, 380, 50, 5, 150);

    creatures[8] = {"Green Wyvern", creaturetype_air, 275, 10, 1450};
    creatures[8].defineSpecialPower("Spit Up", 5, 150, 0, 5, 300);

    creatures[9] = {"Puff", creaturetype_air, 300, 15, 1170};
    creatures[9].defineSpecialPower("Hyper Voice", 3, 350, 25, 5, 100);

    creatures[10] = {"Hornet", creaturetype_air, 600, 0, 780};
    creatures[10].defineSpecialPower("Fleur Cannon", 1, 0, 0, 5, 0);

    creatures[11] = {"Vulture", creaturetype_air, 333, 20, 890};
    creatures[11].defineSpecialPower("Intoxicated Mind", 3, 366, 20, 3, 50);

    creatures[12] = {"Blaze Gust", creaturetype_fire, 540, 0, 600};
    creatures[12].defineSpecialPower("Breath of Flame", 1, 700, 0, 3, 0);

    creatures[13] = {"Beastly Demon", creaturetype_fire, 370, 0, 1460};
    creatures[13].defineSpecialPower("Fire Blast", 2, 0, 50, 5, 200);

    creatures[14] = {"Blazebug", creaturetype_fire, 235, 0, 1800};
    creatures[14].defineSpecialPower("Fire Spin", 1, 400, 0, 0, 0);

    creatures[15] = {"Evil Witch", creaturetype_fire, 375, 0, 1200};
    creatures[15].defineSpecialPower("Heat Wave", 2, 0, 50, 10, 0);

    creatures[16] = {"White Crawler", creaturetype_ice, 290, 0, 1350};
    creatures[16].defineSpecialPower("Roar of Time", 3, 0, 50, 5, 100);

    creatures[17] = {"Myconid", creaturetype_ice, 600, 0, 660};
    creatures[17].defineSpecialPower("Freezing Glare", 2, 0, 0, 15, 0);

    creatures[18] = {"Furious Snowman", creaturetype_ice, 255, 0, 1250};
    creatures[18].defineSpecialPower("Blizzard", 3, 333, 0, 0, 300);

    creatures[19] = {"Ice Werewolf", creaturetype_ice, 322, 0, 1300};
    creatures[19].defineSpecialPower("Icy Wind", 1, 700, 0, 0, 0);

    creatures[20] = {"Plunderer", creaturetype_steel, 500, 0, 700};
    creatures[20].defineSpecialPower("Techno Blast", 1, 700, 0, 0, 0);

    creatures[21] = {"Shady Thug", creaturetype_steel, 320, 0, 1100};
    creatures[21].defineSpecialPower("Confusion", 3, 100, 0, 3, 200);

    creatures[22] = {"Drunk Brigand", creaturetype_steel, 300, 0, 700};
    creatures[22].defineSpecialPower("Heal", 3, 0, 0, 0, 500);

    creatures[23] = {"Undead Soldier", creaturetype_steel, 400, 0, 999};
    creatures[23].defineSpecialPower("Psycho Boost", 1, 700, 30, 0, 100);
}


/**
 * Displaying all content from Creature array
 *
 * It takes one Creature* pointer to array and display single Creatures in console lines
 */
void showCreaturesArr(Creature* const team, size_t const size) {
    for(size_t i=0; i<size; i++) {
        cout << "\t" + std::to_string(i+1) + ". " + team[i].getInfo() + "\n";
    }
}

/**
 * Generating team for player.
 *
 * It takes two Creature* pointers to arrays, one for source array and second one for destination. It prompts user
 * to choose Creatures team before start game.
 */
void generateTeam(Creature* const creatures, Creature* const team) {
    cout << "Avaliable creatures:\n";
    showCreaturesArr(creatures, numberOfCreatures);

    cout << "\nChoose your team [ENTER 6 CREATURE INDEXES]:\n";

    int counter = 0;
    while(counter != userTeamCapacity) {
        cout << "Input " + std::to_string((counter+1)) + " index:";
        std::string input;
        std::cin >> input;

        if(input == "-h" || input == "--help") {
            SetConsoleTextAttribute(color, 11);
            cout << "Wybierz szesc postaci, ktore beda Ci towarzyszyly we wszystkich turach rozgrywki. "
                    "Ta sama postac mozesz wybrac kilkukrotnie. Pamietaj, ze kazda postac charakteryzuje sie "
                    "odmiennymi statystykami oraz mocami specjalnymi. Rozwaznie dobieraj postacie, pamietaj "
                    "ze maja one rozne wspolczynniki odpornosci na dane moce.\n";
            SetConsoleTextAttribute(color, 7);
        } else if(std::stoi(input) > 0 && std::stoi(input) <= numberOfCreatures) {
            team[counter] = creatures[std::stoi(input)-1];
            counter++;
        }
    }
}

/**
 * Welcome console interface.
 *
 * It allows to choose what player wanna do.
 */
int welcomePrompt() {
    std::string option;
    do {
        cout << "\nGraTurowa" << endl;

        cout << "(1) Create team and begin gameplay\n";
        cout << "(2) Load savegame and continue gameplay\n";
        cout << "(3) Exit\n";

        cout << "\nInput:";
        cin >> option;
        if(option == "--help" || option == "-h") {
            SetConsoleTextAttribute(color, 11);
            cout << "Aby rozpoczac rozgrywke wprowadz z klawiatury wartosc 1. Jezeli chcesz kontynuowac wczesniej "
                    "zapisana rozgrywke wprowadz wartosc 2. Jezeli natomiast chcesz opuscic gre, wprowadz wartosc 3.\n";
            SetConsoleTextAttribute(color, 7);
        }
    } while(option != "1" && option != "2" && option != "3");

    int optionNumber = std::stoi(option);
    return optionNumber;
}


/**
 * Choosing difficulty level for user.
 *
 * It allows to choose difficulty game level.
 */
int chooseDifficulty() {
    std::string option;
    do {
        cout << endl << "Choose level of difficulty" << endl;
        cout << "(1) Easy" << endl;
        cout << "(2) Medium" << endl;
        cout << "(3) Hard" << endl;

        cout << "\nInput:";
        cin >> option;
        if(option == "--help" || option == "-h") {
            SetConsoleTextAttribute(color, 11);
            cout << "Poziom trudnosci ma wplyw na liczbe rund jakie gracz bedzie musial stoczyc z wrogiem. Dla "
                    "poziomu latwego sa to cztery rundy. Dla poziomu sredniego jest to szesc rund. Poziom trudny "
                    "charakteryzuje sie osmioma rundami. Aby rozpoczac rozgrywke w trybie latwym wprowadz z "
                    "klawiatury wartosc 1. Aby rozpoczac rozgrywke w trybie srednim wprowadz z klawiatury wartosc "
                    "2. Aby rozpoczac rozgrywke w trybie trudnym wprowadz z klawiatury wartosc 3.\n";
            SetConsoleTextAttribute(color, 7);
        }
    } while(option != "1" && option != "2" && option != "3");

    int optionNumber = std::stoi(option);
    return optionNumber;
}

/**
 * Drawing index for enemy Creatures team list.
 *
 * It draws index from 0 to number of Creatures and returns it.
 */
int randEnemyIndex() {
    return (std::rand() % numberOfCreatures);
}

/**
 * Reducing damage according to Creature type resistance.
 *
 * It returns reduced damage according to source Creature type and destination Creature type.
 * Basic indicator is 0.8 for negative immunity and 1.2 for positive immunity.
 */
int damageResistance(CreatureType const userType, CreatureType const enemyType, int const damage) {
    if(
            (userType == creaturetype_water && (enemyType == creaturetype_earth || enemyType == creaturetype_fire)) ||
            (userType == creaturetype_earth && (enemyType == creaturetype_fire || enemyType == creaturetype_ice || enemyType == creaturetype_steel)) ||
            (userType == creaturetype_air && enemyType == creaturetype_ice) ||
            (userType == creaturetype_fire && (enemyType == creaturetype_ice || enemyType == creaturetype_steel)) ||
            (userType == creaturetype_ice && enemyType == creaturetype_earth) ||
            (userType == creaturetype_steel && (enemyType == creaturetype_water || enemyType == creaturetype_air))
            ) {
        return damage*1.2;
    } else if(
            (userType == creaturetype_water && enemyType == creaturetype_water) ||
            (userType == creaturetype_earth && enemyType == creaturetype_air) ||
            (userType == creaturetype_air && (enemyType == creaturetype_earth || enemyType == creaturetype_steel)) ||
            (userType == creaturetype_fire && (enemyType == creaturetype_water || enemyType == creaturetype_earth)) ||
            (userType == creaturetype_ice && (enemyType == creaturetype_water || enemyType == creaturetype_fire || enemyType == creaturetype_ice)) ||
            (userType == creaturetype_steel && (enemyType == creaturetype_fire || enemyType == creaturetype_steel))
            ) {
        return 0.8*damage;
    }
    else
        return damage;
}

/**
 * Drawing and determining if the player avoid attack.
 *
 * Chance of avoidness is calculated depending on dexterity of Creature.
 * More dexterity equals more chance to avoid attack.
 */
bool avoidAttack(Creature& creature) {
    int draw = (std::rand() % 100);
    if(draw <= creature.getDexterity()) // more dexterity = more chance to avoid attack
        return true;
    return false;
}

/**
 * Upgrading creature stats.
 *
 * Console interface allowing to choose whether the user wants to increase strength or dexterity.
 */
void upgrade(Creature& creature) {
    std::string option;
    do {
        cout << "You have " + std::to_string(creature.getUpgradePoints()) + " upgrade points!\n";

        cout << "\t(1) Upgrade strength +75\n";
        cout << "\t(2) Upgrade dexterity +5\n";
        cout << "\t(3) Cancel\n\n";

        cout << "Input:";
        cin >> option;

        if(option == "--help" || option == "-h") {
            SetConsoleTextAttribute(color, 11);
            cout << "Wartosc ataku postaci zalezna jest od jej sily. Moc zadanych obrazen zalezy od wartosci "
                    "ataku oraz odpornosci przeciwnika na dany typ ataku. Kazda postac ma okreslona szanse "
                    "na unik, wartosc ta jest zdefiniowana jako zrecznosc. Kazda postac posiada moc specjalna. "
                    "Moc specjalna moze nalezec do grupy mocy ofensywnych, defensywnych lub obu grup jednoczenie. "
                    "Typ mocy specjalnej ma wplyw na statystyki postaci lub moc ataku. Moc specjalna moze na trwale "
                    "zwiekszyc wartosc zycia, sily, zrecznosci postaci lub jednorazowo zadac przeciwnikowi silniejszy "
                    "cios. Kazda moc specjalna posiada okreslona liczbe uzyc. W trakcie tury gracza mozna zamienic "
                    "dotychczas uzywana postac. Zamiana postaci wiaze sie z utrata tury przez gracza. Nowo dobrana "
                    "postac moze podjac akcje dopiero w nastepnej turze gracza. Aby zaatakowac przeciwnika zwyklym "
                    "atakiem wprowadz z klawiatury wartosc 1. Aby uzyc mocy specjalnej wprowadz wartosc 2. Aby "
                    "zmienic aktualna postac wprowadz z klawiatury wartosc 3. Aby wyswietlic sklad swojej grupy "
                    "postaci wprowadz z klawiatury wartosc 4. \n";
            SetConsoleTextAttribute(color, 7);
        }
    } while(option != "1" && option != "2" && option != "3");

    if(option == "1") {
        creature.setStrength(creature.getStrength() + 75);
        cout << "Strength increased!\n";
    } else if(option == "2") {
        creature.setDexterity(creature.getDexterity() + 5);
        cout << "Dexterity increased!\n";
    } else {
        return;
    }
    creature.decreseUpgradePoints();
}

/**
 * Mechanism for performing user turn.
 *
 * It allows to input one of 5 options, which has impact on future state of game. If user enter wrong input
 * system will automatically repeat user turn.
 */
int userTurn(Creature* const userCreatures, int current, Creature& enemy) {
    bool repeatTour = false;
    do {
        repeatTour = false;
        std::string option;
        do {
            SetConsoleTextAttribute(color, 5);
            cout << "\n\nUSER's TOUR:" << endl;
            SetConsoleTextAttribute(color, 7);
            cout << "[User] " + userCreatures[current].getShortInfo() + " vs " + "[Enemy] " + enemy.getShortInfo() << endl;

            cout << "\t(1) Attack\n";
            cout << "\t(2) Special Power\n";
            cout << "\t(3) Switch current creature\n";
            cout << "\t(4) Show team\n";
            cout << "\t(5) Evaluate\n";

            cout << "Input:";
            cin >> option;

            if(option == "--help" || option == "-h") {
                SetConsoleTextAttribute(color, 11);
                cout << "Wartosc ataku postaci zalezna jest od jej sily. Moc zadanych obrazen zalezy od wartosci "
                        "ataku oraz odpornosci przeciwnika na dany typ ataku. Kazda postac ma okreslona szanse na "
                        "unik, wartosc ta jest zdefiniowana jako zrecznosc. Kazda postac posiada moc specjalna. Moc "
                        "specjalna moze nalezec do grupy mocy ofensywnych, defensywnych lub obu grup jednoczenie. Typ "
                        "mocy specjalnej ma wplyw na statystyki postaci lub moc ataku. Moc specjalna moze na trwale "
                        "zwiekszyc wartosc zycia, sily, zrecznosci postaci lub jednorazowo zadac przeciwnikowi "
                        "silniejszy cios. Kazda moc specjalna posiada okreslona liczbe uzyc. W trakcie tury gracza "
                        "mozna zamienic dotychczas uzywana postac. Zamiana postaci wiaze sie z utrata tury przez "
                        "gracza. Nowo dobrana postac moze podjac akcje dopiero w nastepnej turze gracza. Aby "
                        "zaatakowac przeciwnika zwyklym atakiem wprowadz z klawiatury wartosc 1. Aby uzyc mocy "
                        "specjalnej wprowadz wartosc 2. Aby zmienic aktualna postac wprowadz z klawiatury wartosc "
                        "3. Aby wyswietlic sklad swojej grupy postaci wprowadz z klawiatury wartosc 4. \n";
                SetConsoleTextAttribute(color, 7);
            }
        } while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5");

        int optionNumber = std::stoi(option);
        switch (optionNumber) {
            case 1: {
                SetConsoleTextAttribute(color, 2);
                int damage = damageResistance(userCreatures[current].getType(), enemy.getType(), userCreatures[current].getStrength());
                if(avoidAttack(enemy)) {
                    cout << "[User] " + userCreatures[current].getShortInfo() +
                            " hit [Enemy] " + enemy.getShortInfo() + " -" + std::to_string(0) << endl;
                    cout << "Attack avoided!" << endl;
                    SetConsoleTextAttribute(color, 7);
                    return 0;
                }
                enemy.setHealth(damage);
                cout << "[User] " + userCreatures[current].getShortInfo() +
                        " hit [Enemy]  " + enemy.getShortInfo() + " -" + std::to_string(damage) << endl;
                SetConsoleTextAttribute(color, 7);
                break;
            }

            case 2: {
                SetConsoleTextAttribute(color, 2);
                int flag = userCreatures[current].useSpecialPower();
                if(flag == -1) {
                    cout << "You don't have more uses of special power! Do something else..." << endl;
                    repeatTour = true;
                    SetConsoleTextAttribute(color, 7);
                    break;
                }

                cout << userCreatures[current].getSpecialPowerName() << "\n";

                if(userCreatures[current].getSpecialPowerStrength())
                    cout << "+" + std::to_string(userCreatures[current].getSpecialPowerStrength()) + " strength\n";

                if(userCreatures[current].getSpecialPowerDexterity())
                    cout << "+" + std::to_string(userCreatures[current].getSpecialPowerDexterity()) + " dexterity\n";

                if(userCreatures[current].getSpecialPowerHealth())
                    cout << "+" + std::to_string(userCreatures[current].getSpecialPowerHealth()) + " health\n";

                if(flag > 0) {
                    enemy.setHealth(flag);
                    cout << "[User] " + userCreatures[current].getShortInfo() +
                            " hit [Enemy] " + enemy.getShortInfo() + " -" + std::to_string(flag) << endl;
                }

                SetConsoleTextAttribute(color, 7);
                break;
            }

            case 3: {
                if(current == userTeamCapacity) {
                    SetConsoleTextAttribute(color, 2);
                    cout << "You cannot change creature!" << endl;
                    repeatTour = true;
                    SetConsoleTextAttribute(color, 7);
                    break;
                }

                std::string creatureIndex;
                int creatureIndexNumber;

                do {
                    cout << endl << "Which creature you want to use?" << endl;
                    showCreaturesArr(userCreatures, userTeamCapacity);

                    cout << "Input:";
                    cin >> creatureIndex;

                    if(creatureIndex == "-h" || creatureIndex == "--help") {
                        SetConsoleTextAttribute(color, 11);
                        cout << "Gracz ma mozliwosc podmiany aktualnie wykorzystywanej postaci na inna. Warunkiem "
                                "podmiany jest dobor zyjacej postaci sposrod zespolu dobranego na poczatku rozgrywki. "
                                "Decyzji o podmianie postaci nie mozna anulowac. Podmiana postaci wiaze sie z utrata "
                                "tury przez gracza. Nowo wybrana postac moze zostac uzyta dopiero w nastepnej turze. "
                                "Jedynym sposobem na anulowanie zamiany postaci jest wybor tej samej postaci w "
                                "okienku wyboru.\n";
                        SetConsoleTextAttribute(color, 7);
                    } else if(creatureIndex == "1" || creatureIndex == "2" || creatureIndex == "3" || creatureIndex == "4" || creatureIndex == "5" || creatureIndex == "6"){
                        creatureIndexNumber = std::stoi(creatureIndex) - 1;
                    } else {
                        continue;
                    }
                } while(creatureIndexNumber <= current || creatureIndexNumber > userTeamCapacity);

                SetConsoleTextAttribute(color, 2);
                cout << "Current creature has been changed to " + userCreatures[creatureIndexNumber].getShortInfo() + "\n";
                SetConsoleTextAttribute(color, 7);

                Creature temp = userCreatures[current];
                userCreatures[current] = userCreatures[creatureIndexNumber];
                userCreatures[creatureIndexNumber] = temp;
                break;
            }

            case 4: {
                cout << "Your team:\n";
                showCreaturesArr(userCreatures, userTeamCapacity);
                repeatTour = true;
                break;
            }

            case 5: {
                if(userCreatures[current].getUpgradePoints() > 0) {
                    upgrade(userCreatures[current]);
                } else {
                    cout << "You don't have upgrade points!\n";
                }
                repeatTour = true;
                break;
            }
        }
    } while(repeatTour);

    if(enemy.getHealth() <= 0)
        return enemy.getLot(); // if enemy creature killed
    else
        return 0; // if enemy still alive after attack
}

/**
 * Mechanism for performing enemy's turn.
 *
 * It allows to automatically perform enemy's turn. It takes into account whether chance to avoid attack
 * and possibillity to use special power.
 */
int enemyTurn(Creature& enemy, Creature& user) {
    SetConsoleTextAttribute(color, 5);
    cout << endl << "\nENEMY's TOUR:" << endl;
    SetConsoleTextAttribute(color, 7);

    Sleep(1000); // tour delay

    cout << "[Enemy] " + enemy.getShortInfo() << " vs [User] " << user.getShortInfo() << endl;

    SetConsoleTextAttribute(color, 4);
    int damage = damageResistance(enemy.getType(), user.getType(), enemy.getStrength());

    if(enemy.getSpecialPowerUses() && (std::rand() % 100)%3 == 0) { // 33% chance to use
        damage = enemy.useSpecialPower();
        cout << enemy.getSpecialPowerName() << "\n";

        if(enemy.getSpecialPowerStrength())
            cout << "+" + std::to_string(enemy.getSpecialPowerStrength()) + " strength" << endl;

        if(enemy.getSpecialPowerDexterity())
            cout << "+" + std::to_string(enemy.getSpecialPowerDexterity()) + " dexterity" << endl;

        if(enemy.getSpecialPowerHealth())
            cout << "+" + std::to_string(enemy.getSpecialPowerHealth()) + " health" << endl;

        if(damage > 0) {
            user.setHealth(damage);
            cout << "[Enemy] " + enemy.getShortInfo() + " hit [User] " + user.getShortInfo() + " -" + std::to_string(damage) << endl;
        }
    } else if(avoidAttack(user)) {
        SetConsoleTextAttribute(color, 4);
        cout << "[Enemy] " + enemy.getShortInfo() + " hit [User] " + user.getShortInfo() + " -" + std::to_string(0) << endl;
        cout << "Attack avoided!\n";
        SetConsoleTextAttribute(color, 7);
        return 0;
    } else {
        user.setHealth(damage);
        cout << "[Enemy] " + enemy.getShortInfo()  + " hit [User] " +  user.getShortInfo() + " -" + std::to_string(damage) << endl;
    }
    SetConsoleTextAttribute(color, 7);

    if(user.getHealth() <= 0)
        return user.getLot();
    else
        return 0;
}

/**
 * Calculate experience needed to promotion.
 *
 * It allows to automatically perform enemy's turn. It takes into account whether the enemy has chance to
 * avoid attack and possibillity to use special power.
 */
int getExpToPromotion(int destinationLevel) {
    if(destinationLevel > 1)
        return destinationLevel*100 + getExpToPromotion(destinationLevel-1);
    else
        return 100;
}

/**
 * Starting round and controling state during game.
 *
 * It allows to start new round, generate enemy's team and control count of dead player and enemy's creatures.
 */
bool startRound(int num, Creature* const team, Creature* const enemies) {
    SetConsoleTextAttribute(color, 15);
    cout << "\nRound number " + std::to_string(num+1) + "\n";
    SetConsoleTextAttribute(color, 7);

    Creature roundEnemies[enemyTeamCapacity] {};
    for(int i=0; i<enemyTeamCapacity; i++)
        roundEnemies[i] = enemies[randEnemyIndex()];

    for(size_t i=0; i<userTeamCapacity; i++) {
        if(team[i].getHealth() > 0)
            team[i].refillHealth();
    }

    cout << "Your's team:\n";
    showCreaturesArr(team, userTeamCapacity);

    cout << "Enemy's team:\n";
    showCreaturesArr(roundEnemies, enemyTeamCapacity);

    int currentPlayer = 0;
    for(size_t i=0; i<userTeamCapacity; i++) {
        if(team[i].getHealth() > 0) {
            currentPlayer = i;
            break;
        }
    }

    int currentEnemy = 0, deadPlayerCreatures = 0, deadEnemyCreatures = 0;
    while(deadPlayerCreatures != userTeamCapacity || deadEnemyCreatures != enemyTeamCapacity) {
        int tourResult = userTurn(team, currentPlayer, roundEnemies[currentEnemy]);
        if(tourResult > 0) {
            cout << "Enemy's creature killed!\n";

            team[currentPlayer].addExp(roundEnemies[currentEnemy].getLot());
            cout << "+" + std::to_string(roundEnemies[currentEnemy].getLot()) + "xp [" +
                    std::to_string(team[currentPlayer].getExperience()) + " / " +
                    std::to_string(getExpToPromotion(team[currentPlayer].getLevel() + 1)) + "]";

            if(team[currentPlayer].isLevelUp(getExpToPromotion(team[currentPlayer].getLevel()+1)))
                team[currentPlayer].promotion();

            deadEnemyCreatures++;
            currentEnemy++;
        }

        if(deadEnemyCreatures == enemyTeamCapacity)
            return true;

        int enemyResult = enemyTurn(roundEnemies[currentEnemy], team[currentPlayer]);
        if(enemyResult > 0) {
            cout << "User's creature killed!" << endl;
            deadPlayerCreatures++;
            currentPlayer++;
        }

        if(deadPlayerCreatures == userTeamCapacity)
            return false;
    }
}

//bool readSavegame(Creature* const creatures)
//{
//    std::ifstream stream("./savegame.txt");
//
//    if(!stream.good()) {
//        cout << "There's a problem with a file!\n";
//        return false;
//    }
//
//    std::string line;
//    std::getline(stream, line);
//    int difficulty = std::stoi(line);
//
//    std::getline(stream, line);
//    int roundNumber = std::stoi(line);
//
//    Creature team[userTeamCapacity] {};
//    for(size_t i=0; i<userTeamCapacity; i++) {
//        std::getline(stream, line); // name
//        for(size_t j=0; j<numberOfCreatures; j++) {
//            if(line == creatures[j].getName()) {
//                team[i] = creatures[j];
//                break;
//            }
//        }
//        std::getline(stream, line); // level
//        int level = std::stoi(line);
//        team[i].setLevel(level);
//
//    }
//    return true;
//}

/**
 * Saving game state.
 *
 * It allows to save current game state and user team properties.
 */
void saveToFile(int const difficulty, int const round, Creature* const team) {
    std::ofstream stream;
    stream.open ("./savegame.txt");

    stream << difficulty << "\n";
    stream << round << "\n";

    for(size_t i=0; i<userTeamCapacity; i++) {
        stream << team[i].getName() << "\n";
        stream << team[i].getLevel() << "\n";
        stream << team[i].getExperience() << "\n";
        stream << team[i].getHealth() << "\n";
        stream << team[i].getStrength() << "\n";
        stream << team[i].getDexterity() << "\n";
        stream << team[i].getSpecialPowerUses() << "\n\n";
    }

    stream.close();
    cout << "Save completed. See you soon!\n";
    exit(0);
}

/**
 * Starting the game and calling every new round to be performed.
 *
 * It allows to start new game and call n-rounds depending od difficulty level.
 */
void startGame(int const difficulty, Creature* const team, Creature* const creatures) {
    cout << "\nConfiguration has been loaded. Starting game...\n";

    int rounds;
    if(difficulty == 1) rounds = 4;
    else if(difficulty == 2) rounds = 6;
    else rounds = 8;

    int userPoints = 0, enemyPoints = 0;
    for(int currentRoundNum=0; currentRoundNum<rounds; currentRoundNum++) {
        if(enemyPoints == 1 || userPoints == rounds)
            break;

//        cout << endl << "USER_POINTS:" << userPoints << " ENEMY_POINTS:" << enemyPoints << endl << endl;

        if(startRound(currentRoundNum, team, creatures)) {
            userPoints++;

            std::string option;
            do {
                cout << "(1) Continue\n";
                cout << "(2) Save and exit\n";

                cout << "\nInput:";
                cin >> option;
                if(option == "--help" || option == "-h") {
                    SetConsoleTextAttribute(color, 11);
                    cout << "Po kazdej rundzie istnieje mozliwosc zapisu stanu gry i kontynuowania jej w przyszlosci. "
                            "Pliki z zapisem przechowywane sa w katalogu roboczym projektu pod nazwa '...'. "
                            "Aby zapisac stan gry wprowadz za pomoca klawiatury wartosc 2. Jezeli natomiast chcesz "
                            "kontynuowac rozgrywke wprowadz wartosc 1.\n";
                    SetConsoleTextAttribute(color, 7);
                }
            } while(option != "1" && option != "2");

            if(option == "2")
                saveToFile(difficulty, currentRoundNum, team);

        } else {
            enemyPoints++;
        }
    }

    if(enemyPoints == 1) {
        cout << "\nEndgame! Enemy has won the game!";
    } else {
        cout << "\nEndgame! User won the game!";
    }

}

/**
 * Main function.
 *
 * Entry point to game mechanics and control.
 */
int main() {
    srand(time(NULL));

    Creature creatures[numberOfCreatures] {};
    initalizeCreaturesArr(creatures);
    Creature team[userTeamCapacity] {};

    int control;
    do {
        control = welcomePrompt();
        switch(control) {
            case 1:
                generateTeam(creatures, team); // OK
                startGame(chooseDifficulty(), team, creatures);
                break;
            case 2: {
                //if(!readSavegame(creatures))
                control = -1;
                cout << "Option unavaliable!\n";
                break;
            }
            case 3:
                exit(0);
        }
    } while(control != 1 && control != 2 && control != 3);
    return 0;
}