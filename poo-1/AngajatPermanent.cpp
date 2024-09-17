#include <iostream>
#include <vector>
#include "AngajatPermanent.h"
void AngajatPermanent::print(std::ostream &out) const
{
    Angajat::print(out);
    out << "Salariul este de " << salary << " procentul lunar este de " << procent << " bonusul maxim este de " << maxBonus << std::endl;
    for (auto i : bonus)
    {

        out << "Penru luna "
            << " bonusul a fost de " << i.money << std::endl;
    }
};
void AngajatPermanent::read(std::istream &is)
{
    Angajat::read(is);
    std::cout << "Introduceti saalariul fix" << std::endl;
    is >> salary;
    std::cout << "Introduceti procentul" << std::endl;
    is >> procent;
    std::cout << "INtroduceti bonsul maxim" << std::endl;
    is >> maxBonus;
    int i;
    std::cout << "Cate bonusuri vreti sa adaugati?" << std::endl;
    is >> i;
    int auxMN;
    MonthType auxM;
    float bonus;
    for (int j = 0; j < i; i++)
    {
        MoneyGain aux;
        std::cout << j + 1 << ". Pentru ce luna vreti sa adaugati?Puneti numarul" << std::endl;

        is >> auxMN;
        switch (auxMN)
        {
        case 1:
        {
            auxM = MonthType::Ian;
            break;
        }
        case 2:
        {
            auxM = MonthType::Feb;
            break;
        }
        case 3:
        {
            auxM = MonthType::Mar;
            break;
        }
        case 4:
        {
            auxM = MonthType::May;
            break;
        }
        case 5:
        {
            auxM = MonthType::June;
            break;
        }
        case 6:
        {
            auxM = MonthType::July;
            break;
        }
        case 7:
        {
            auxM = MonthType::Aug;
            break;
        }
        case 8:
        {
            auxM = MonthType::Sept;
            break;
        }
        case 9:
        {
            auxM = MonthType::Oct;
            break;
        }
        case 10:
        {
            auxM = MonthType::Nov;
            break;
        }
        case 11:
        {
            auxM = MonthType::Dev;
            break;
        }
        default:
            break;
        }
        std::cout << "Cat este bonusul?" << std::endl;
        is >> bonus;
        aux.money = bonus;
        aux.month = auxM;
        addBonusMonth(aux);
        addMoney(aux);
    }
};
std::ostream &
operator<<(std::ostream &out, const AngajatPermanent &obj)
{
    obj.print(out);
    return out;
};
std::istream &operator>>(std::istream &is, AngajatPermanent &obj)
{
    obj.read(is);
    return is;
};
void AngajatPermanent::addBonusMonth(MoneyGain &bm)
{
    bonus.push_back(bm);
    addMoney(bm);
};