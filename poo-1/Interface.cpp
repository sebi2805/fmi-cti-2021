#include <iostream>
#include "Interface.h"
#include "Angajat.h"
#include "AngajatPermanent.h"
#include "AngajatTemporar.h"
#include "memory"
void Interface::start()
{
    int i = 1;
    while (i)
    {
        std::cout << "1.Adaugati angajati\n2.Adaugati angajat nou\n3.Afisati toti anagajtii\n4.Angajatii care termina intr o luna data";

        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            int j;
            std::cout << "Cati angajat vreti sa adaugati" << std::endl;
            std::cin >> j;
            for (int k = 0; k < j; k++)

            {
                int type;
                std::cout << "Ce tip de anagajati vreti sa inserati?\n1.Temporar\n2.Permanent" << std::endl;
                std::cin >> type;
                if (type == 1)
                    anagajati.push_back(std::make_shared<Angajat>(*dynamic_cast<Angajat *>(new AngajatTemporar())));
                else if (i == 2)
                    anagajati.push_back(std::make_shared<Angajat>(*dynamic_cast<Angajat *>(new AngajatPermanent())));
                else
                    throw "Acest tip de angajat nu exista";
                std::cin >> *anagajati[k];
            };
            break;
        }
        case 2:
        {
            int type;
            std::cout << "Ce tip de anagajati vreti sa inserati?\n1.Temporar\n2.Permanent" << std::endl;
            std::cin >> type;
            std::cout << type;
            if (type == 1)
                anagajati.push_back(std::make_shared<Angajat>(*dynamic_cast<Angajat *>(new AngajatTemporar())));
            else if (type == 2)
                anagajati.push_back(std::make_shared<Angajat>(*dynamic_cast<Angajat *>(new AngajatPermanent())));
            else
                throw "Acest tip de angajat nu exista";
            std::cin >> *anagajati[anagajati.size() - 1];
            break;
        };
        case 3:
        {
            for (auto inc : anagajati)
            {
                inc->print(std::cout);
                std::cout << std::endl;
            }
            break;
        }
        case 4:
        {

            std::cout << "In ce luna suntem?...";
            break;
        }
        }
    }
}
