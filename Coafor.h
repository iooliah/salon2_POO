#ifndef COAFOR_H
#define COAFOR_H
#include <string>
#include <iostream>
#include <memory>
#include "Serviciu.h"

class Coafor : public Serviciu {
private:
    bool vopsit;
    std::string lungimePar;       //"scurt", "mediu", "lung"

public:
    Coafor() = default;
    Coafor(float pret, int durata, bool vopsit, const std::string& lungimePar);

    bool getVopsit() const;
    const std::string& getLungimePar() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;

private:
    void afiseazaVirtual(std::ostream& os) const override;
};

#endif
