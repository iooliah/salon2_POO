#include "Client.h"

int Client::numarClienti = 0;

Client::Client() : Persoana(), nrVizite(0) {
    numarClienti++;
}

Client::Client(const std::string& nume, const std::string& prenume, const std::string& telefon, int nrVizite) : Persoana(nume, prenume, telefon), nrVizite(nrVizite){
    numarClienti++;
}
Client::Client(const Client& other) : Persoana(other), nrVizite(other.nrVizite){
    numarClienti++;
}

Client::~Client() {
    numarClienti--;
}

int Client::getNrVizite() const{ return nrVizite; }
void Client::incrementeazaVizite(){ ++nrVizite; }
bool Client::esteClientFidel() const{ return nrVizite >= 5; }
int Client::getNrClienti(){ return numarClienti; }

std::string Client::getRol() const{return "Client"; }


std::shared_ptr<Persoana> Client::clone() const {
    return std::make_shared<Client>(*this);
}


void Client::afiseazaVirtual(std::ostream& os) const{
    Persoana::afiseazaVirtual(os);
    os<< ", Numar vizite: " <<nrVizite;
    if(esteClientFidel()){
        os<< ", Client fidel";
    }
}
