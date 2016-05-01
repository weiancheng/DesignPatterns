#include <iostream>

class Weapon {
public:
    Weapon(std::string name, const int attack, const int defence) {
        mName = name;
        mAttack = attack;
        mDefence = defence;
    }
    ~Weapon() {}

    virtual void useAttack(int attack) = 0;
    virtual void useDefence(int defence) = 0;

protected:
    std::string mName;
    int mAttack;
    int mDefence;
};

class Knife : public Weapon {
public:
    Knife(std::string name, const int attack, const int defence)
            : Weapon(name, attack, defence)
    {
    }

    virtual void useAttack(int base_attack) {
        int attack = base_attack + mAttack;
        std::cout << mName << ": attack " << attack << " points." << std::endl;
    }

    virtual void useDefence(int base_defence) {
        int defence = base_defence + mDefence;
        std::cout << mName << ": defence " << defence << " points." << std::endl;
    }
};

class AK47 : public Weapon {
public:
    AK47(std::string name, const int attack, const int defence)
            : Weapon(name, attack, defence) {
    }

    virtual void useAttack(int base_attack) {
        int attack = base_attack + mAttack;
        std::cout << mName << ": attack " << attack << " points." << std::endl;
    }

    virtual void useDefence(int base_defence) {
        int defence = base_defence + mDefence;
        std::cout << mName << ": defence " << defence << " points." << std::endl;
    }
};

class Character {
public:
    ~Character() {}

    virtual void setProperties(std::string name, int attack, int defence) {
        mName = name;
        mAttack = attack;
        mDefence = defence;
    }

    // bridge method
    virtual void getWeapon(Weapon *weapon) {
        if (nullptr == weapon)
            return;
        mWeapon = weapon;
    }

    virtual void Attack(void) = 0;
    virtual void Defence(void) = 0;

protected:
    std::string mName;
    int mAttack;
    int mDefence;
    Weapon *mWeapon;
};

class Police : public Character {
public:
    virtual void Attack(void) {
        mWeapon->useAttack(mAttack);
    }

    virtual void Defence(void) {
        mWeapon->useDefence(mDefence);
    }

    ~Police() {
        if (mWeapon)
            delete mWeapon;
    }
};

class Terrorist : public Character {
public:
    virtual void Attack(void) {
        mWeapon->useAttack(mAttack);
    }

    virtual void Defence(void) {
        mWeapon->useDefence(mDefence);
    }

    ~Terrorist() {
        if (mWeapon)
            delete mWeapon;
    }
};

int main(int agrc, char **argv) {
    Character *police = new Police();

    police->setProperties("counter terrorist", 100, 50);
    police->getWeapon(new AK47("ak47", 100, 30));
    police->Attack();
    police->Defence();

    delete police;

    return 0;
}