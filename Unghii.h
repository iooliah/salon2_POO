#ifndef UNGHII_H
#define UNGHII_H

#include "Serviciu.h"

class Unghii : public Serviciu{
protected:
    bool gel;
    bool design;
    float calcPretComun(bool angajatExperimentat, plata tipPlata, bool clientFidel) const;

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
    void afiseazaVirtual(std::ostream& os) const override;
};



#endif
