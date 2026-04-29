#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <string>
#include <iostream>
#include <memory>

#include "Persoana.h"

class Angajat : public Persoana {
private:
    int experienta;
    std::string specializare;
    static int numarAngajati;
    void afiseazaVirtual(std::ostream& os) const override;

public:
    Angajat();
    Angajat(const std::string& nume, const std::string& prenume, const std::string& telefon, int experienta, const std::string& specializare);
    Angajat(const Angajat& other);
    ~Angajat() override;                    //rescrie o functie virtuala din clasa de baza Persoana

    int getExperienta() const;
    const std::string& getSpecializare() const;
    static int getNrAngajati();

    bool areExperienta() const;             //>= 5 ani => +10 lei
    std::string getRol() const override;    //rescrie o functie virtuala din clasa de baza Persoana
    std::shared_ptr<Persoana> clone() const override;
};



#endif // ANGAJAT_H

