#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

class Creature
{
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength; 
    int hitpoints; 
    string getSpecies();
public:
    Creature();
    // Initialize to human, 10 strength, 10 hit points
    Creature(int newType, int newStrength, int newHit);
    string GetType();
    int GetStrngth();
    int GetHP();

    // for type, strength, and hit points
    int getDamage();
    // Returns amount of damage this creature
    // inflicts in one round of combat
};

int Creature::GetStrngth() {
    return strength;
}
int Creature::GetHP() {
    return hitpoints;
}
string Creature::GetType() {
    return getSpecies();
}

Creature::Creature() {
    type = 0;
    strength = 10;
    hitpoints = 10;
}

Creature::Creature(int newType, int newStrength, int newHit) {
    type = newType;
    strength = newStrength;
    newHit = hitpoints;
}

string Creature::getSpecies()
{
    switch (type)
    {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
    }
    return "Unknown";
}

int Creature::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " <<
        damage << " points!" << endl;
    // Demons can inflict damage of 50 with a 5% chance
    if ((type == 2) || (type == 1))
        if ((rand() % 100) < 5)
        {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 "
                << " additional damage points!" << endl;
        }
    // Elves inflict double magical damage with a 10% chance
    if (type == 3)
    {
        if ((rand() % 10) == 0)
        {
            cout << "Magical attack inflicts " << damage <<
                " additional damage points!" << endl;
            damage = damage * 2;
        }
    }
    // Balrogs are so fast they get to attack twice
    if (type == 2)
    {
        int damage2 = (rand() % strength) + 1;
        cout << "Balrog speed attack inflicts " << damage2 <<
            " additional damage points!" << endl;
        damage = damage + damage2;
    }
    return damage;
}

class Demon :public Creature {

protected:
    int damage;
public:
    Demon(int DemonType, int DemonStrength, int Demon_HP) : Creature(DemonType, DemonStrength, Demon_HP) {

    }

    int getDamage() {
        if ((rand() % 100) < 5)
        {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 "
                << " additional damage points!" << endl;
        }
        return damage;
    }

};

class Cyberdemon :public Demon{
public:
    Cyberdemon(int CDStrength ,int CD_HP): Demon(1,CDStrength,CD_HP) {
       
   }

    string GetType() {
        return "Cyberdemon";
    }

};

class Balrog :public Demon {
public:
    Balrog(int BalrogStrength, int Balrog_HP) : Demon(2, BalrogStrength, Balrog_HP) {

    }
    string GetType() {
        return "Balrog";
    }

    int getDamage() {
        int damage2 = (rand() % GetStrngth() + 1);
        cout << "Balrog speed attack inflicts " << damage2 <<
            " additional damage points!" << endl;
        damage = damage + damage2;
        return damage;
    }
};

class Elf :public Creature {
public:
    Elf(int ElfStrength, int Elf_HP) : Creature(3, ElfStrength, Elf_HP) {

    }
    string GetType() {
        return "Elf";
    }

    int getDamage() {
        int damage = (rand() % GetStrngth()) + 1;
        if ((rand() % 10) == 0)
        {
            cout << "Magical attack inflicts " << damage <<
                " additional damage points!" << endl;
            damage = damage * 2;
        }
        return damage;
    }
};

class Human :public Creature {
public:
    Human(int HumanStrength, int Human_HP) : Creature(0, HumanStrength, Human_HP) {

    }
    string GetType() {
        return "Human";
    }
};


int main()
{
    std::cout << "RPG fantasy!\n";
    Human NewHuman = Human(10, 10);
    NewHuman.getDamage();

    Creature NewCreat = Creature();
    NewCreat.getDamage();

    Creature NewCret2 = Creature(3, 20, 50);
    NewCret2.getDamage();

    Elf NewElf = Elf(15, 20);
    NewElf.getDamage();

    Balrog Bal = Balrog(30, 30);
    Bal.getDamage();

    Cyberdemon CD = Cyberdemon(45, 20);
    CD.getDamage();


}

