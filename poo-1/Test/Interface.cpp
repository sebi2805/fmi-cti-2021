#include "Interface.h"
void Interface::start()
{
    int i = 1;
    while (i)
    {

        std::cout << "Ce doriti sa faceti?\n1.Afisati toate referintele\n2.Afisati toate referintele intr-un an dat\n3.Cautati o referinta dupa un nume data\n4.Afisati toate web\n5.Introduceti referinte " << std::endl;
        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            for (auto referinte : formatElectronic)
                std::cout << *referinte;
            for (auto referinte : formatFizic)
                std::cout << *referinte;
            break;
        }
        case 2:
        {
            int an;
            std::cout << "In ce an doriti sa cautati?" << std::endl;
            std::cin >> an;
            for (auto referinta : formatFizic)
                referinta->searchByYear(an);

            break;
        }
        case 3:
        {
            std::string nume;
            std::cout << "Ce nume doriti sa cautati?" << std::endl;
            std::cin >> nume;
            for (auto referinta : formatFizic)
                referinta->searchByName(nume);

            break;
        }
        case 4:
        {
            for (auto electro : formatElectronic)
                std::cout << *electro;
            break;
        }
        case 5:
        {
            int i, k;
            std::shared_ptr<FormatElectronic> aux1;
            std::shared_ptr<FormatFizic> aux2;
            std::cout << "Cate bibliografii vreti sa introduceti?" << std::endl;
            std::cin >> i;
            try
            {

                for (int j = 0; j < i; j++)
                {
                    std::cout << "Ce fel de fomart vreti sa introduceti?\n1.Electronic\n2.Fizic" << std::endl;
                    std::cin >> k;

                    if (k == 1)
                    {
                        aux1 = std::make_shared<FormatElectronic>();
                        std::cin >> *aux1;
                        formatElectronic.push_back(aux1);
                    }
                    else if (k == 2)
                    {
                        aux2 = std::make_shared<FormatFizic>();
                        std::cin >> *aux2;
                        formatFizic.push_back(aux2);
                    }
                    else
                        throw "Acest tip nu exista deocamdata";
                }
            }
            catch (const char *s)
            {
                std::cout << s;
            }
            break;
        }

        default:
            break;
        }
    }
}