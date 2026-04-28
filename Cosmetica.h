#ifndef COSMETICA_H
#define COSMETICA_H
#include <string>
#include <iostream>
#include <memory>
#include "Serviciu.h"

class Cosmetica : public Serviciu {
private:
    bool masca;
    std::string tipTratament;                   //"facial", "corp", "par"

public:
    Cosmetica() = default;
    Cosmetica(float pret, int durata, bool masca, const std::string& tipTratament);

    bool getMasca() const;
    const std::string& getTipTratament() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;

private:
    void afiseazaVirtual(std::ostream& os) const override;
};

#endif

