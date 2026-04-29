#ifndef PEDICHIURA_H
#define PEDICHIURA_H

#include "Unghii.h"

class Pedichiura : public Unghii{
protected:
    bool masaj;

public:
    Pedichiura() = default;
    Pedichiura(const std::string& nume, float pret, int durata, bool gel, bool design, bool masaj);

    bool getMasaj() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;


protected:
    void afiseazaVirtual(std::ostream& os) const override;
};

#endif

