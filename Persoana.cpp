#include "Persoana.h"

Persoana::Persoana(const std::string& nume, const std::string& prenume, const std::string& telefon): nume(nume), prenume(prenume), telefon(telefon) {}const std::string& Persoana::getNume() const { return nume; }

const std::string& Persoana::getPrenume() const{ return prenume; }
const std::string& Persoana::getTelefon() const{ return telefon; }
std::string Persoana::getNumeComplet() const{ return nume + " " + prenume;}

void Persoana::afiseaza(std::ostream& os) const{
    afiseazaVirtual(os);
}

void Persoana::afiseazaVirtual(std::ostream& os) const{
    os<< "Rol: " <<getRol()<< ", Nume: " <<nume<< ", Prenume: " <<prenume<< ", Telefon: " <<telefon;
}

std::ostream& operator<<(std::ostream& os, const Persoana& p) {
    p.afiseaza(os);
    return os;
}
