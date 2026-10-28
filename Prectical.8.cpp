#include <iostream>
#include <string>
#include <memory>
using namespace std;

class BattleWeapon
{
public:
    virtual void attack() = 0;
    virtual ~BattleWeapon() = default;
};

class Blade : public BattleWeapon
{
public:
    void attack() override
    {
        cout << "You attack using a sword.\n";
    }
};

class Mallet : public BattleWeapon
{
public:
    void attack() override
    {
        cout << "You attack using a hammer.\n";
    }
};

class WeaponCreator
{
public:
    static unique_ptr<BattleWeapon> chooseWeapon(const string &weapon)
    {
        if (weapon == "Sword")
        {
            return make_unique<Blade>();
        }
        else if (weapon == "Hammer")
        {
            return make_unique<Mallet>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    cout << "Student name: RAMESH KUMAR\nURN: E25B001202\n\n";

    unique_ptr<BattleWeapon> a = WeaponCreator::chooseWeapon("Sword");
    if (a)
    {
        a->attack();
    }

    unique_ptr<BattleWeapon> b = WeaponCreator::chooseWeapon("Hammer");
    if (b)
    {
        b->attack();
    }

    return 0;
}
