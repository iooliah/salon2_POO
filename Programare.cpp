#include <utility>
#include "Programare.h"
#include "Manichiura.h"
#include "Pedichiura.h"
#include "Unghii.h"
#include "Coafor.h"

Programare::Programare(const Client& client, const Angajat& angajat, std::shared_ptr<Serviciu> serviciu, const std::string& data, const std::string& ora, plata tipPlata)
: client(client), angajat(angajat), serviciu(serviciu), data(data), ora(ora), tipPlata(tipPlata){}

//constructor copiere
Programare::Programare(const Programare& other) : client(other.client), angajat(other.angajat), serviciu(other.serviciu ? other.serviciu->clone() : nullptr),data(other.data), ora(other.ora), tipPlata(other.tipPlata) {}

//copy and swap
Programare& Programare::operator=(Programare other){
    swap(*this, other);
    return *this;
}
void swap(Programare& a, Programare& b){
    using std::swap;
    swap(a.client, b.client);
    swap(a.angajat, b.angajat);
    swap(a.serviciu, b.serviciu);
    swap(a.data, b.data);
    swap(a.ora, b.ora);
    swap(a.tipPlata, b.tipPlata);
}

//getters
const Client& Programare::getClient() const{ return client; }
const Angajat& Programare::getAngajat() const{ return angajat; }
const std::string& Programare::getData() const{ return data; }
const std::string& Programare::getOra() const{ return ora; }

bool Programare::esteAcelasiClient(const Client& c1, const Client& c2){
    if((c1.getNume()==c2.getNume()) && (c1.getPrenume()==c2.getPrenume()) && (c1.getTelefon()==c2.getTelefon())){
        return true;
    }
    return false;
}
int Programare::getDurataTotala() const{
    return serviciu->durataTotala();
}

//functii statice
int Programare::numaraProgramariClientZi(const std::vector<Programare>& programari, const Client& client, const std::string& data){
    int nr=0;
    for(const Programare& programare : programari){
        if(programare.getData()==data && esteAcelasiClient(programare.getClient(), client)){
            nr++;
        }
    }
    return nr;
}
float Programare::calcIncasariZi(const std::vector<Programare>& programari, const std::string& data){
    float suma = 0;
    for(const Programare& programare : programari){
        if(programare.getData() == data){
            suma += programare.calcCostFinal(programari);
        }
    }
    return suma;
}

//apelare virtuala prin pointer de baza
float Programare::calcCostFinal(const std::vector<Programare>& toateProgramarile) const{
    bool angajatExperimentat = angajat.areExperienta();
    bool clientFidel = client.esteClientFidel();
    float cost = serviciu->calcPretFinal(angajatExperimentat, tipPlata, clientFidel);
    int nrProgramariZi = numaraProgramariClientZi(toateProgramarile, client, data);

    if(data == "11.09"){
        cost = cost* 0.9f;
    }
    if(nrProgramariZi >= 2){
        cost = cost* 0.9f;
    }
    return cost;
}


//dynamic_pointer_cast
bool Programare::areServiciuCuTimpSuplimentar() const{
    auto manichiura = std::dynamic_pointer_cast<Manichiura>(serviciu);
    auto pedichiura = std::dynamic_pointer_cast<Pedichiura>(serviciu);
    auto unghii = std::dynamic_pointer_cast<Unghii>(serviciu);
    auto coafor = std::dynamic_pointer_cast<Coafor>(serviciu);

    if(manichiura && (manichiura->getCrema() || manichiura->getGel() || manichiura->getDesign()) ){
        return true;
    }
    if(pedichiura && (pedichiura->getMasaj() || pedichiura->getGel() || pedichiura->getDesign())){
        return true;
    }
    if(unghii && (unghii->getGel() || unghii->getDesign())){
        return true;
    }
    if(coafor && coafor->getVopsit()){
        return true;
    }
    return false;
}


std::string Programare::descriereProgramare() const{
    return client.getNumeComplet()+ " are programare la " + serviciu->descriereServiciu() + " cu " + angajat.getNumeComplet() + " pe data de " + data+ " la ora " +ora;
}

//operator <<
std::ostream& operator<<(std::ostream& os, const Programare& p){
    os<< "Client: " << p.client<< "\nAngajat: " << p.angajat<< "\nServiciu: ";
    os<<*p.serviciu;
    os<<"\nDescriere serviciu: " <<p.serviciu->descriereServiciu();
    os<<"\nDurata totala: " <<p.serviciu->durataTotala() << " minute";
    os<< "\nData: "<<p.data<< "\nOra: " <<p.ora<< "\nTip plata: ";

    if(p.tipPlata == plata::CASH){
        os<< "CASH";
    }else if(p.tipPlata == plata::CARD){
        os<< "CARD";
    }else {
        os<< "TRANSFER";
    }
    return os;
}
