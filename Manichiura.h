#ifndef MANICHIURA_H
#define MANICHIURA_H
#include <string>
#include <memory>
#include <iostream>

class Unghii;

class Manichiura : public Unghii{
protected:
    bool crema;

public:
    Manichiura() = default;
    Manichiura(const std::string& nume, float pret, int durata, bool gel, bool design, bool crema);

    bool getCrema() const;

    int durataTotala() const override;
    float calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const override;
    std::string descriereServiciu() const override;
    std::shared_ptr<Serviciu> clone() const override;

private:
    void afiseazaVirtual(std::ostream& os) const override;
};

#endif
