#include "Unghii.h"

//constructor
Unghii::Unghii(const std::string& nume, float pret, int durata, bool gel, bool design) : Serviciu(nume, pret, durata), gel(gel), design(design){}

//getters
bool Unghii::getGel() const{ return gel; }
bool Unghii::getDesign() const{ return design; }

int Unghii::durataTotala() const{
    int durataFinala = durata;
    if(gel) durataFinala += 20;
    if(design) durataFinala += 15;

    return durataFinala;
}

//functie comuna de calcul pret (Manichiura/Pedichiura)
float Unghii::calcPretComun(bool angajatExperimentat, plata tipPlata, bool clientFidel) const{
    float cost = pret;

    if(gel) cost += 50;
    if(design) cost += 20;

    if(angajatExperimentat){
        cost += 10;
    }
    if(clientFidel){
        cost = cost * 0.9f;
    }
    if(tipPlata == plata::CASH){
        cost -= 5;
    }

    return cost;
}

float Unghii::calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const{
    return calcPretComun(angajatExperimentat, tipPlata, clientFidel);
}

std::string Unghii::descriereServiciu() const{
    std::string descriere = "Serviciu unghii";
    if(gel) descriere += " cu gel";
    if(design) descriere += " cu design";
    return descriere;
}

//clone
std::shared_ptr<Serviciu> Unghii::clone() const{
    return std::make_shared<Unghii>(*this);
}
//afisare
void Unghii::afiseazaVirtual(std::ostream& os) const{
    Serviciu::afiseazaVirtual(os);
    os<< ", Tip: Unghii" << ", Gel: "<<(gel ? "da" : "nu")<< ", Design: " <<(design ? "da" : "nu");
}
