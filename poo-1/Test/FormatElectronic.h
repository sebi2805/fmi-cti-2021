#ifndef CarteFormatElectronic
#define CarteFormatElectronic
#include <iostream>
#include <memory>
#include <vector>
#include "Bibliografie.h"
#include "Web.h"
#include "Cloneable.h"
class FormatElectronic : public Bibliografie, public Cloneable
{
    std::vector<std::shared_ptr<Web>> materiale;

public:
    FormatElectronic(std::vector<std::shared_ptr<Web>> materiale = {}) : materiale(materiale){};
    FormatElectronic(FormatElectronic &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, const FormatElectronic &);
    friend std::istream &operator>>(std::istream &, FormatElectronic &);
};
#endif