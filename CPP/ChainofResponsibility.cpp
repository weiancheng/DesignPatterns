#include <iostream>

class JusticeLeague {
public:
    JusticeLeague(std::string name, int power)
            : mName(name)
            , mPower(power) {
    }
    ~JusticeLeague() {
        if (mHero)
            delete mHero;
    }

    virtual void getHero(JusticeLeague *hero) {
        mHero = hero;
    }

    virtual void doJustice(int enemy_power) = 0;

protected:
    std::string mName;
    int mPower;
    JusticeLeague *mHero;
};

class Superman : public JusticeLeague {
public:
    Superman(std::string name, int power)
            : JusticeLeague(name, power) {
    }

    virtual void doJustice(int enemy_power) {
        if (mPower >= enemy_power) {
            std::cout << mName << " destroyed the enemy." << std::endl;
        }
        else {
            std::cout << mName << " can't handle this ..." << std::endl;
            std::cout << "The enemy destroyed the world." << std::endl;
        }
    }
};

class TheFlash : public JusticeLeague {
public:
    TheFlash(std::string name, int power)
            : JusticeLeague(name, power){
    }

    virtual void doJustice(int enemy_power) {
        if(mPower >= enemy_power) {
            std::cout << mName << " destroyed the enemy." << std::endl;
        } else {
            std::cout << mName << " need help ..." << std::endl;
            mHero->doJustice(enemy_power);
        }
    }
};

class Batman : public JusticeLeague {
public:
    Batman(std::string name, int power) :
            JusticeLeague(name, power){
    }

    virtual void doJustice(int enemy_power) {
        if(mPower >= enemy_power) {
            std::cout << mName << " destroyed the enemy." << std::endl;
        } else {
            std::cout << mName << " need help ..." << std::endl;
            mHero->doJustice(enemy_power);
        }
    }
};


int main(int argc, char **argv) {
    JusticeLeague *batman = new Batman("Bat man", 200);
    JusticeLeague *flash = new TheFlash("The Flash", 800);
    JusticeLeague *super_man = new Superman("Super man", 1200);

    batman->getHero(flash);
    flash->getHero(super_man);

    int enemy = 2000;

    batman->doJustice(enemy);

    delete(batman);

    return 0;
}