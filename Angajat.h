#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <string>
#include <iostream>

#include "Persoana.h"

class Angajat : public Persoana {
private:
    int experienta;
    std::string specializare;
    static int numarAngajati;

public:
    Angajat() = default;
    Angajat(const std::string& nume, const std::string& prenume, const std::string& telefon, int experienta, const std::string& specializare);
    ~Angajat() override;                    //rescrie o functie virtuala din clasa de baza Persoana

    int getExperienta() const;
    const std::string& getSpecializare() const;
    static int getNrAngajati();

    bool areExperienta() const;             //>= 5 ani => +10 lei
    std::string getRol() const override;    //rescrie o functie virtuala din clasa de baza Persoana

protected:
    void afiseaza(std::ostream& os) const override;
};



#endif // ANGAJAT_H

