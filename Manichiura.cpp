#include "Manichiura.h"

//constructor
Manichiura::Manichiura(const std::string& nume,float pret, int durata, bool gel, bool design, bool crema) : Unghii(nume, pret, durata, gel, design), crema(crema){}

//getter
bool Manichiura::getCrema() const{ return crema;}

int Manichiura::durataTotala() const{
    int durataFinala = Unghii::durataTotala();
    if(crema){
        durataFinala += 5;
    }
    return durataFinala;
}

//functie comuna de calcul pret
float Manichiura::calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const{
    float cost = calcPretComun(angajatExperimentat, tipPlata, clientFidel);
    if(crema){
        cost += 10;
    }
    return cost;
}

std::string Manichiura::descriereServiciu() const{
    std::string descriere = "Manichiura";
    if(getGel()) descriere += " cu gel";
    if(getDesign()) descriere += " cu design";
    if(crema) descriere += " + tratament crema";
    return descriere;
}

//clone
std::shared_ptr<Serviciu> Manichiura::clone() const{
    return std::make_shared<Manichiura>(*this);
}

void Manichiura::afiseazaVirtual(std::ostream& os) const{
    Unghii::afiseazaVirtual(os);
    os<<", Tip: Manichiura" << ", Crema: "<<(crema ? "da" : "nu");
}
