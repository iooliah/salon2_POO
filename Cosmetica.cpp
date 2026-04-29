#include "Cosmetica.h"

//constructor
Cosmetica::Cosmetica(float pret, int durata, bool masca, const std::string& tipTratament)
    : Serviciu("Cosmetica", pret, durata), masca(masca), tipTratament(tipTratament){}

int Cosmetica::durataTotala() const {
    int durataFinala = durata;
    if(masca){
        durataFinala += 15;
    }
    if(tipTratament == "corp"){
        durataFinala += 20;
    }else if(tipTratament == "par"){
        durataFinala += 10;
    }
    return durataFinala;
}

//calcul pret final
float Cosmetica::calcPretFinal(bool angajatExperimentat, plata tipPlata, bool clientFidel) const{
    float cost = pret;
    if(masca){
        cost += 25;
    }
    if(tipTratament =="corp"){
        cost += 40;
    }else if(tipTratament == "par"){
        cost += 20;
    }

    if(angajatExperimentat){
        cost += 10;
    }
    if(clientFidel){
        cost =cost * 0.9f;
    }
    if(tipPlata == plata::CASH){
        cost -= 5;
    }

    return cost;
}

std::string Cosmetica::descriereServiciu() const{
    std::string descriere = "Cosmetica";
    descriere += tipTratament;
    if(masca){
        descriere+= " + masca";
    }
    return descriere;
}

//clone
std::shared_ptr<Serviciu> Cosmetica::clone() const {
    return std::make_shared<Cosmetica>(*this);
}

void Cosmetica::afiseazaVirtual(std::ostream& os) const {
    Serviciu::afiseazaVirtual(os);
    os << ", Tip: Cosmetica" << ", Tratament: " << tipTratament << ", Masca: " << (masca ? "da" : "nu");
}
