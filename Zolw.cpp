#include "Zolw.h"
#include "Swiat.h"
#include <random>

Zolw::Zolw(int x, int y)
    : Zwierze('Z', 2, 1, x, y) // Inicjalizacja konstruktora klasy bazowej
{
    //swiat = Swiat::getInstance(); // Pobranie instancji klasy Swiat
    //this->swiat = swiat; // Inicjalizacja pola swiat
}

void Zolw::rysuj() {
    std::cout << getZnak();
}
void Zolw::akcja() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
    int liczba = 0;
    int x = getX();
    int y = getY();
    int a;
    bool ruchWykonany = true;
    while (ruchWykonany)
    {
        liczba = dis(gen);
        if (liczba%4==0)
        {
            liczba = dis(gen);
            switch (liczba)
            {
            case 0:
                if (ruchy[0][0] + x >= 0 && ruchy[0][1] + y >= 0)
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y }) == nullptr) {
                        a = ruchy[0][0];
                        setX(a);
                        a = ruchy[0][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[0][0];
                            setX(a);
                            a = ruchy[0][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                //ruchWykonany = false;
                break;
            case 1:
                if (ruchy[1][1] + getY() >= 0)
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y }) == nullptr) {
                        a = ruchy[1][0];
                        setX(a);
                        a = ruchy[1][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[1][0];
                            setX(a);
                            a = ruchy[1][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            case 2:
                if (ruchy[2][0] + getX() < swiat->getSzerokosc() && ruchy[2][1] + getY() >= 0)
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y }) == nullptr) {
                        a = ruchy[2][0];
                        setX(a);
                        a = ruchy[2][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[2][0];
                            setX(a);
                            a = ruchy[2][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            case 3:
                if (ruchy[3][0] + getX() >= 0)
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }) == nullptr) {
                        a = ruchy[3][0];
                        setX(a);
                        a = ruchy[3][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y })->getSila() < getSila())
                    {
                        kolizja(swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }));
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[3][0];
                            setX(a);
                            a = ruchy[3][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            case 4:
                if (ruchy[4][0] + getX() < swiat->getSzerokosc())
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }) == nullptr) {
                        a = ruchy[4][0];
                        setX(a);
                        a = ruchy[4][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[4][0];
                            setX(a);
                            a = ruchy[4][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            case 5:
                if (ruchy[5][0] + getX() >= 0 && ruchy[5][1] + getY() < swiat->getWysokosc())
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y }) == nullptr) {
                        a = ruchy[5][0];
                        setX(a);
                        a = ruchy[5][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[5][0];
                            setX(a);
                            a = ruchy[5][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            case 6:
                if (ruchy[6][1] + getY() < swiat->getWysokosc())
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y }) == nullptr) {
                        a = ruchy[6][0];
                        setX(a);
                        a = ruchy[6][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[6][0];
                            setX(a);
                            a = ruchy[6][1];
                            setY(a);
                        }

                        ruchWykonany = false;
                    }
                }
                break;
            case 7:
                if (ruchy[7][0] + getX() < swiat->getSzerokosc() && ruchy[7][1] + getY() < swiat->getWysokosc())
                {
                    if (typeid(*this) == typeid(swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y })))
                    {
                        //urodzenie
                    }
                    else if (swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }) == nullptr) {
                        a = ruchy[7][0];
                        setX(a);
                        a = ruchy[7][1];
                        setY(a);
                        ruchWykonany = false;
                    }
                    else if (getSila() == -1)
                    {
                        std::cout << "Nie mo�esz wykona� Ruchu" << std::endl;
                        ruchWykonany = false;
                    }
                    else {
                        kolizja(swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }));
                        if (getSila() != -1)
                        {
                            a = ruchy[7][0];
                            setX(a);
                            a = ruchy[7][1];
                            setY(a);
                        }
                        ruchWykonany = false;
                    }
                }
                break;
            default:
                break;
            }
        }
        ruchWykonany = false;
    }
}
void Zolw::kolizja(Organizm* inny) {
    //std::cout << "Kolizja";
    if (this == inny)
        return;
    if (inny == nullptr)
    {
        return;
    }
    else if (typeid(*this) == typeid(*inny)) {
        return;
    }
    else if (5 > inny->getSila())
    {
        std::cout << "Zolw ucieka" << std::endl;

    }
    else if (getSila() > inny->getSila())
    {
        std::cout << "Zolw wygral" << std::endl;
        if (inny->getZnak() == 'g')
        {
            setSila(3);
        }
        inny->zabij();
    }
    else if (getSila() < inny->getSila())
    {
        std::cout << "Zolw przegral" << std::endl;
        zabij();
    }
    else
    {
        std::cout << "Remis" << std::endl;
        zabij();
        inny->zabij();
    }
}
Organizm* Zolw::urodz(int x, int y) {
    return new Zolw(x, y);
}