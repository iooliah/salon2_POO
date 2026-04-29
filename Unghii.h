#ifndef UNGHII_H
#define UNGHII_H
#include <string>
#include <iostream>
#include <memory>
class Serviciu;

class Unghii : public Serviciu{
protected:
    bool design;
    bool gel;
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

private:
    void afiseazaVirtual(std::ostream& os) const override;
};



#endif
