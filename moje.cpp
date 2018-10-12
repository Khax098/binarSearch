#include <iostream>
#include <vector>

class Hill
{
  protected:
    int hillsAmount;
    std::vector<char> terainMap;
    int sheetAmount;

  public:
    Hill();
    ~Hill() = default;

    bool isEnoughSize(int);
};

bool Hill::isEnoughSize(int sheetSize)
{
    int sheetAmountCopy=this->sheetAmount;
    std::cout << "IE:" << sheetSize;
    for (int actualHill = 0; actualHill <= hillsAmount; ++actualHill)
    {
        if ((not sheetAmountCopy) and (actualHill >= hillsAmount))
            return true;
        if (terainMap[actualHill] == '+')
        {
            --sheetAmountCopy;
            if (sheetAmountCopy < 0)
            {
                return false;
            }
            actualHill += (sheetSize - 1);
        }
    }
}

Hill::Hill()
{
    std::cout << "podaj Ilosc Wzgorz:";
    std::cin >> hillsAmount;
    terainMap.resize(hillsAmount);
    for (size_t i = 0; i < hillsAmount; i++)
    {
        std::cin >> terainMap[i];
    }

    for (size_t i = 0; i < hillsAmount; i++)
    {
        std::cout << terainMap[i];
    }
    std::cout << "\npodaj sheetAmount:";
    std::cin >> sheetAmount;
    std::cout << sheetAmount << "\n";
}

class BinarSearch : public Hill
{
    int minimalSheetSize, maximalSheetSize;

  public:
    void searching();
    BinarSearch() : minimalSheetSize(1), maximalSheetSize(hillsAmount)
    {
        std::cout << "Tworze BInarSearch\n";
        searching();
    };
    ~BinarSearch() = default;
};

void BinarSearch::searching()
{
    int middleValue;
    std::cout << "Rozpoczynam binarshearching\n";
    while (minimalSheetSize < maximalSheetSize)
    {
        std::cout << "Rozpoczynam petle";
        middleValue = (minimalSheetSize + maximalSheetSize) / 2;
        if (isEnoughSize(middleValue))
        {
            maximalSheetSize = middleValue;
        }
        else
        {
            minimalSheetSize = middleValue;
        }

        std::cout << "middleV:" << middleValue;
    }
    std::cout << "\nRozwiazanie to:" << maximalSheetSize;
}

void search()
{
    int liczba, p = 1, k = 10;
    int srodek = 0;
    std::cout << "podaj liczbe:";
    std::cin >> liczba;

    while (p < k)
    {
        srodek = ((p + k) / 2);
        if (liczba > srodek)
        {
            std::cout << "jest wieksza niz p" << p;
            p = srodek;
            std::cout << "ustalam nowy p" << p << std::endl;
            if (p + 1 == k)
            {
                ++p;
                break;
            }
        }
        else
        {
            std::cout << "jest mniejszy niz k" << k;
            k = srodek;
            std::cout << "ustalam nowy k" << k << std::endl;
        }
    }
    //if(p+1==k) p=k;
    std::cout << "Wynik:" << p;
}

int main(int argc, char const *argv[])
{
    BinarSearch binarSearch;
    ;
    //search();
    std::cout << "koniec";
    return 0;
}
