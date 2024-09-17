#ifndef ANGAJAT
#define ANGAJAT
#include <iostream>
#include <vector>
enum class AngajatType
{
    permanent,
    temporar,
    unknown
};
enum class MonthType
{
    Ian,
    Feb,
    Mar,
    April,
    May,
    June,
    July,
    Aug,
    Sept,
    Oct,
    Nov,
    Dev

};
struct MoneyGain
{
    MonthType month;
    float money;
};
class Angajat
{
    static int idAngajat;
    std::string CNP, dataAngajarii, functia, nume, prenume;
    AngajatType type;
    std::vector<MoneyGain> money;

public:
    Angajat(std::string nume = "undefined", std::string prenume = "undefined", std::string CNP = "undefined", std::string dataAngajarii = "undefined", std::string functia = "undefined", AngajatType type = AngajatType::unknown)
        : functia(functia), CNP(CNP), nume(nume), prenume(prenume), dataAngajarii(dataAngajarii), type(type)
    {

        idAngajat++;
    };
    Angajat(Angajat &);
    friend std::ostream &operator<<(std::ostream &, const Angajat &);
    friend std::istream &operator>>(std::istream &, Angajat &);
    virtual void print(std::ostream &) const;
    virtual void read(std::istream &);
    const std::string getNume() const;
    const std::string getPreume() const;
    const std::string getCNP() const;
    const std::string getFunctia() const;
    const AngajatType getType() const;
    const std::string getDataAngajarii() const;
    void setNume(std::string);
    void setPrenume(std::string);
    void setType(AngajatType);
    void setDataAngajarii(std::string);
    void setFunctia(std::string);
    void setCNP(std::string);
    void addMoney(MoneyGain &);
};
#endif