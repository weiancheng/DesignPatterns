#include <iostream>
#include <string>

class Weapon
{
public:
	virtual void setWeaponName(std::string name) {
		WeaponName = name;
	}

	virtual std::string getWeaponName(void) {
		return WeaponName;
	}

	virtual int Damage(void) = 0;
	virtual int Defence(void) = 0;
	virtual void ShowProperties(void) = 0;

protected:
	std::string WeaponName;
	int mDamage;
	int mDefence;
};

class Sword  : public Weapon
{
public:
	Sword(const int Damage = 10, const int defence = 10) {
		mDamage = Damage;
		mDefence = defence;
	}

	int Damage(void) {
		return mDamage;
	}

	int Defence(void) {
		return mDefence;
	}

	void ShowProperties(void) {
		std::cout << "Weapon Name: " << WeaponName << std::endl;
		std::cout << "Physical Damage: " << mDamage << std::endl;
		std::cout << "Physical Defence: " << mDefence << std::endl;
	}
};

class Gun : public Weapon {
public:
	Gun(const int Damage = 20, const int defence = 5) {
		mDamage = Damage;
		mDefence = defence;
	}

	int Damage(void) {
		return mDamage;
	}

	int Defence(void) {
		return mDefence;
	}

	void ShowProperties(void) {
		std::cout << "Weapon Name: " << WeaponName << std::endl;
		std::cout << "Physical Damage: " << mDamage << std::endl;
		std::cout << "Physical Defence: " << mDefence << std::endl;
	}
};

class Shield : public Weapon {
public:
	Shield(const int Damage = 5, const int defence = 20) {
		mDamage = Damage;
		mDefence = defence;
	}

	int Damage(void) {
		return mDamage;
	}

	int Defence(void) {
		return mDefence;
	}

	void ShowProperties(void) {
		std::cout << "Weapon Name: " << WeaponName << std::endl;
		std::cout << "Physical Damage: " << mDamage << std::endl;
		std::cout << "Physical Defence: " << mDefence << std::endl;
	}
};

class Magic : public Weapon {
public:
	Magic(Weapon *weapon) {
		mWeapon = weapon;
	}

	virtual void setWeaponName(std::string name) {
		mWeapon->setWeaponName(name);
	}

	virtual std::string getWeaponName(void) {
		return mWeapon->getWeaponName();
	}

	virtual int Damage(void) {
		return mWeapon->Damage();
	}

	virtual int Defence(void) {
		return mWeapon->Defence();
	}

	virtual void ShowProperties(void) = 0;

	virtual int MagicDamage(void)  = 0;

protected:
	Weapon *mWeapon;
	int mMagicDamage;
};

class FireMagic : public Magic {
public:
	FireMagic(Weapon *weapon)
	: Magic(weapon) {
		mMagicDamage = 20;
	}

	~FireMagic(void) {
		if(mWeapon)
			delete mWeapon;
	}

	virtual int Damage(void) {
		return mWeapon->Damage() + 20;
	}

	virtual int Defence(void) {
		return mWeapon->Defence() + 5;
	}

	virtual void ShowProperties(void) {
		std::cout << "Weapon Name: " << mWeapon->getWeaponName() << std::endl;
		std::cout << "Physical Damage: " << this->Damage() << std::endl;
		std::cout << "Physical Defence: " << this->Defence() << std::endl;
		std::cout << "Magic Damage: " << mMagicDamage<< std::endl;
	}

protected:
	int MagicDamage(void) {
		return mMagicDamage;
	}
};

class IceMagic : public Magic {
public:
	IceMagic(Weapon *weapon)
	: Magic(weapon) {
		mMagicDamage = 10;
	}

	~IceMagic(void) {
		if(mWeapon)
			delete mWeapon;
	}

	virtual int Damage(void) {
		return mWeapon->Damage() + 10;
	}

	virtual int Defence(void) {
		return mWeapon->Defence() + 10;
 	}

 	virtual void ShowProperties(void) {
		std::cout << "Weapon Name: " << mWeapon->getWeaponName() << std::endl;
		std::cout << "Physical Damage: " << this->Damage() << std::endl;
		std::cout << "Physical Defence: " << this->Defence() << std::endl;
		std::cout << "Magic Damage: " << mMagicDamage<< std::endl;
	}

protected:
 	int MagicDamage(void) {
 		return mMagicDamage;
 	}
};

int main(int argc, char **argv)
{
	Weapon * fire_gun = new FireMagic(new Gun());
	Weapon *ice_shield = new IceMagic(new Shield());

	fire_gun->setWeaponName("fire Gun");
	ice_shield->setWeaponName("ice Shield");

	fire_gun->ShowProperties();
	std::cout << std::endl;
	ice_shield->ShowProperties();

	delete fire_gun;
	delete ice_shield;

	return 0;
}