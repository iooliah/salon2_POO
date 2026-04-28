#include "Angajat.h"

int Angajat::numarAngajati = 0;

Angajat::Angajat() : Persoana(), experienta(0), specializare("necunoscuta"){
    numarAngajati++;
}

Angajat::Angajat(const std::string& nume, const std::string& prenume, const std::string& telefon, int experienta, const std::string& specializare)
: Persoana(nume, prenume, telefon), experienta(experienta),specializare(specializare){
    numarAngajati++;
}

Angajat::~Angajat()
    numarAngajati--;
}

int Angajat::getExperienta() const{ return experienta; }
const std::string& Angajat::getSpecializare() const{ return specializare; }
int Angajat::getNrAngajati(){ return numarAngajati; }

bool Angajat::areExperienta() const{
    return experienta>=5;
}

std::string Angajat::getRol() const{
    return "Angajat";
}

std::shared_ptr<Persoana> Angajat::clone() const{
    return std::make_shared<Angajat>(*this);
}

void Angajat::afiseazaVirtual(std::ostream& os) const{
    Persoana::afiseazaVirtual(os);
    os<< ", Experienta: " <<experienta<< " ani" << ", Specializare: " <<specializare;
    if(areExperienta()){
        os<< ", Angajat experimentat";
    }
}
