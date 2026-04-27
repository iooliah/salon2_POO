#ifndef SERVICIU_H
#define SERVICIU_H

#include <string>
#include <iostream>

enum class plata{CASH, CARD, TRANSFER};

class Serviciu {
protected:
    std::string nume;
    float pret;
    int durata;

public:
    Serviciu() = default;
    Serviciu(const std::string& nume, float pret, int durata);
    virtual ~Serviciu() = default;

    const std::string& getNume() const;
    float getPret() const;
    int getDurata() const;

    void afiseaza(std::ostream& os) const;

    //functii virtuale pure
    virtual float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const = 0;
    virtual std::string descriereServiciu() const = 0;
    virtual int durataTotala() const = 0;

    virtual std::shared_ptr<Serviciu> clone() const = 0;

    //interfata non-virtuala pentru afisare
    //friend std::ostream& operator<<(std::ostream& os, const Serviciu& s);

protected:
    virtual void afiseaza(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Serviciu& s);


#endif // SERVICIU_H
