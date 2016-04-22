#include <iostream>


// interface
class Weapon {
public:
    virtual void setWeaponName(std::string name) = 0;
    virtual void setAttack(int power) = 0;
    virtual void setDefence(int num_shield) = 0;
    virtual void showDetail(void) = 0;

    virtual ~Weapon() {}

protected:
    std::string mName;
    int mAttack;
    int mDefence;
};

class Tank : public Weapon {
public:
    void setWeaponName(std::string name) {
        mName = name;
    }

    void setAttack(int power) {
        mAttack = power;
    }

    void setDefence(int num_shield) {
        mDefence = num_shield;
    }

    void setSpeed(int speed) {
        mSpeed = speed;
    }

    void showDetail(void) {
        std::cout << "Weapon Name: " << mName << std::endl;
        std::cout << "Attack: " << mAttack << std::endl;
        std::cout << "Defence: " << mDefence << std::endl;
    }

private:
    int mSpeed;
};

class B2Airplane : public Weapon {
public:
    void setWeaponName(std::string name) {
        mName = name;
    }

    void setAttack(int power) {
        mAttack = power;
    }

    void setDefence(int num_shield) {
        mDefence = num_shield;
    }

    void setWeight(int weight) {
        mWeight = weight;
    }

    void showDetail(void) {
        std::cout << "Weapon Name: " << mName << std::endl;
        std::cout << "Attack: " << mAttack << std::endl;
        std::cout << "Defence: " << mDefence << std::endl;
        std::cout << "Weight: " << mWeight << std::endl;
    }

private:
    int mWeight;
};

enum EGunWeapon {
    EGNURIFLE = 1000,
    EGUNAK47  = 1001,
    EGUNM16   = 1002,
};

class Gun : public Weapon {
public:
    void setWeaponName(std::string name) {
        mName = name;
    }

    void setAttack(int power) {
        mAttack = power;
    }

    void setDefence(int num_shield) {
        mDefence = num_shield;
    }

    void setGun(EGunWeapon gun) {
        mGun = gun;
    }

    void showDetail(void) {
        switch (mGun) {
            case EGNURIFLE:
            std::cout << "I'm a rich man." << std::endl;
                break;

            case EGUNAK47:
            std::cout << "I'm a terrorist." << std::endl;
                break;

            case EGUNM16:
            std::cout << "I'm a police." << std::endl;
                break;

            default:
            std::cout << "I'm a poor guy." << std::endl;
        }
        std::cout << "Weapon Name: " << mName << std::endl;
        std::cout << "Attack: " << mAttack << std::endl;
        std::cout << "Defence: " << mDefence << std::endl;
    }

private:
    EGunWeapon mGun;
};

class WeaponBuilder {
public:
    virtual ~WeaponBuilder() {}
    virtual Weapon *build(void) = 0;
};

class TankBuilder : public WeaponBuilder {
public:
    TankBuilder(Tank *tank) {
        mTank = tank;
    }

    Weapon *build(void) {
        mTank->setWeaponName(std::string("Tiger-II"));
        mTank->setAttack(300);
        mTank->setDefence(100);
        mTank->setSpeed(20);

        return mTank;
    }

private:
    Tank *mTank;
};

class B2AirplaneBuilder : public WeaponBuilder {
public:
    B2AirplaneBuilder(B2Airplane *b2) {
        mB2 = b2;
    }

    Weapon *build(void) {
        mB2->setWeaponName(std::string("B-2 Spirit"));
        mB2->setAttack(30000);
        mB2->setDefence(2000);
        mB2->setWeight(158000);

        return mB2;
    }

private:
    B2Airplane *mB2;
};

class RifleBuilder : public WeaponBuilder {
public:
    RifleBuilder(Gun *gun) {
        mGun = gun;
    }

    Weapon *build(void) {
        mGun->setWeaponName(std::string("Blaser R8"));
        mGun->setGun(EGNURIFLE);
        mGun->setAttack(100);
        mGun->setDefence(0);

        return mGun;
    }

private:
    Gun *mGun;
};

class AK47Builder : public WeaponBuilder {
public:
    AK47Builder(Gun *gun) {
        mGun = gun;
    }

    Weapon *build(void) {
        mGun->setGun(EGUNAK47);
        mGun->setWeaponName(std::string("Kalashnikov"));
        mGun->setAttack(80);
        mGun->setDefence(0);

        return mGun;
    }

private:
    Gun *mGun;
};

class M16Builder : public WeaponBuilder {
public:
    M16Builder(Gun *gun) {
        mGun = gun;
    }

    Weapon *build(void) {
        mGun->setGun(EGUNM16);
        mGun->setWeaponName(std::string("M16A4"));
        mGun->setAttack(70);
        mGun->setDefence(0);

        return mGun;
    }

private:
    Gun *mGun;
};

int main(int argc, char **argv) {
    Weapon *airplane = nullptr;
    WeaponBuilder *air_builder = new B2AirplaneBuilder(new B2Airplane());

    airplane = air_builder->build();

    airplane->showDetail();

    delete(air_builder);
    delete(airplane);

    std::cout << std::endl;

    WeaponBuilder *gun_builder = new AK47Builder(new Gun());
    Weapon *gun = gun_builder->build();
    gun->showDetail();

    delete(gun_builder);
    delete(gun);

    return 0;
}
