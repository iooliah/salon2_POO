#ifndef UNGHII_H
#define UNGHII_H
#include <string>
#include <iostream>

#include "Serviciu.h"

class Unghii : public Serviciu{
protected:
    bool design;
    bool gel;

public:
    Unghii() = default;
    Unghii(const std::string& nume, float pret, int durata, bool gel, bool design);

    bool getGel() const;
    bool getDesign() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;

protected:
    void afiseaza(std::ostream& os) const override;
    float calcPretComun(bool angajatExperimentat, plata tipPlata, bool clientFidel) const;
};



#endif
