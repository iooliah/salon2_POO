#ifndef COSMETICA_H
#define COSMETICA_H

#include "Serviciu.h"

class Cosmetica : public Serviciu {
private:
    bool masca;
    std::string tipTratament;                   //"facial", "corp", "par"
    void afiseazaVirtual(std::ostream& os) const override;

public:
    Cosmetica() = default;
    Cosmetica(float pret, int durata, bool masca, const std::string& tipTratament);

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;


};

#endif

