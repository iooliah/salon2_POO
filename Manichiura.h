#ifndef MANICHIURA_H
#define MANICHIURA_H
#include <string>
#include <iostream>

#include "Unghii.h"

class Manichiura : public Unghii{
protected:
    bool crema();

public:
    Manichiura() = default;
    Manichiura(const std::string& nume, float pret, int durata, bool gel, bool design, bool crema);

    bool getcrema() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;

protected:
    void afiseaza(std::ostream& os) const override;
};

#endif
