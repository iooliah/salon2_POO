#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "Client.h"
#include "Angajat.h"
#include "Programare.h"
#include "Manichiura.h"
#include "Pedichiura.h"
#include "Coafor.h"
#include "Cosmetica.h"
#include "Exceptii.h"

//forward declarations
Client& cautaClient(std::vector<Client>& clienti, const std::string& nume, const std::string& prenume);
Angajat& cautaAngajat(std::vector<Angajat>& angajati, const std::string& nume, const std::string& prenume);
bool specializareBuna(const Angajat& angajat, const std::string& tipServiciu);
bool angajatDisponibil(const std::vector<Programare>& programari, const Angajat& angajat, const std::string& data, const std::string& ora);
plata plataFinal(const std::string& text);

void citesteClienti(std::vector<Client>& clienti, const std::string& fis){
    std::ifstream fin(fis);
    std::string nume, prenume, telefon;
    int nrVizite;

    while(fin >> nume >> prenume >> telefon >> nrVizite){
        clienti.emplace_back(nume, prenume, telefon, nrVizite);
    }
}

void citesteAngajati(std::vector<Angajat>& angajati, const std::string& fis){
    std::ifstream fin(fis);
    std::string nume, prenume, telefon, specializare;
    int experienta;

    while(fin >> nume >> prenume >> telefon >> experienta >> specializare){
        angajati.emplace_back(nume, prenume, telefon, experienta, specializare);
    }
}

void citesteProgramari(std::vector<Programare>& programari,std::vector<Client>& clienti,std::vector<Angajat>& angajati,const std::string& fis){
    std::ifstream fin(fis);
    std::string numeClient, prenumeClient, numeAngajat, prenumeAngajat, tipServiciu, data, ora, plataText;

    while(fin>>numeClient>>prenumeClient>>numeAngajat>>prenumeAngajat>>tipServiciu>>data>>ora>>plataText){
        try{
            float pret;
            int durata;
            fin>> pret >> durata;

            Client& client = cautaClient(clienti, numeClient, prenumeClient);
            Angajat& angajat = cautaAngajat(angajati, numeAngajat, prenumeAngajat);

            if(specializareBuna(angajat, tipServiciu) == 0){
                throw ProgramareInvalidaExceptie("angajatul nu are specializarea potrivita");
            }

            std::shared_ptr<Serviciu> serviciu;

            if(tipServiciu == "MANICHIURA"){
                bool gel, design, crema;
                fin>> gel >> design >> crema;
                serviciu = std::make_shared<Manichiura>("Manichiura", pret, durata, gel, design, crema);
            }else if (tipServiciu == "PEDICHIURA"){
                bool gel, design, masaj;
                fin>> gel >> design >> masaj;
                serviciu = std::make_shared<Pedichiura>("Pedichiura", pret, durata, gel, design, masaj);
            }else if (tipServiciu == "COAFOR"){
                bool vopsit;
                std::string lungimePar;
                fin>> vopsit >> lungimePar;
                serviciu = std::make_shared<Coafor>(pret, durata, vopsit, lungimePar);
            }else if(tipServiciu == "COSMETICA"){
                bool masca;
                std::string tipTratament;
                fin>> masca >> tipTratament;
                serviciu = std::make_shared<Cosmetica>(pret, durata, masca, tipTratament);
            }else{
                throw ProgramareInvalidaExceptie("tip serviciu invalid");
            }

            if(!angajatDisponibil(programari, angajat, data, ora)){
                throw ProgramareInvalidaExceptie("angajat ocupat");
            }
            programari.emplace_back(client, angajat, serviciu, data, ora, plataFinal(plataText));
        }
        catch(const SalonExceptii& e){
            std::cout<< "Programare ignorata: " << e.what() <<std::endl;
        }
    }
}

Client& cautaClient(std::vector<Client>& clienti, const std::string& nume, const std::string& prenume){
    for(auto& c : clienti){
        if(c.getNume() == nume && c.getPrenume() == prenume){
            return c;
        }
    }
    throw ClientInexistentExceptie();
}
Angajat& cautaAngajat(std::vector<Angajat>& angajati, const std::string& nume, const std::string& prenume){
    for(auto& a : angajati){
        if(a.getNume() == nume && a.getPrenume() == prenume)
            return a;
    }
    throw AngajatInexistentExceptie();
}

bool specializareBuna(const Angajat& angajat, const std::string& tipServiciu){
    if((tipServiciu == "MANICHIURA" || tipServiciu == "PEDICHIURA") && angajat.getSpecializare() == "unghii"){
        return true;
    }
    if(tipServiciu == "COAFOR" && angajat.getSpecializare() == "coafor"){
        return true;
    }

    if(tipServiciu == "COSMETICA" && angajat.getSpecializare() == "cosmetica"){
        return true;
    }
    return false;
}
bool angajatDisponibil(const std::vector<Programare>& programari, const Angajat& angajat, const std::string& data, const std::string& ora) {
    for(const auto& p : programari){
        if(p.getData() == data && p.getOra() == ora && p.getAngajat().getNume() == angajat.getNume() && p.getAngajat().getPrenume() == angajat.getPrenume()){
            return false;
        }
    }
    return true;
}

plata plataFinal(const std::string& text){
    if(text == "CASH") return plata::CASH;
    if(text == "CARD") return plata::CARD;
    if(text == "TRANSFER") return plata::TRANSFER;
    throw ProgramareInvalidaExceptie("tip de plata invalid");
}


void adaugaClient(std::vector<Client>& clienti){
    std::string nume, prenume, telefon;
    int nrVizite;
    std::cout<< "Nume: ";
    std::cin>> nume;
    std::cout<< "Prenume: ";
    std::cin>> prenume;
    std::cout<< "Telefon: ";
    std::cin>> telefon;
    std::cout<< "Numar vizite: ";
    std::cin>> nrVizite;

    clienti.emplace_back(nume, prenume, telefon, nrVizite);

    std::ofstream fout("clienti.txt", std::ios_base::app);
    fout<< nume << " " << prenume << " " << telefon << " " << nrVizite <<std::endl;
    std::cout<< "Client adaugat.\n";
}

void adaugaProgramare(std::vector<Programare>& programari, std::vector<Client>& clienti, std::vector<Angajat>& angajati){
    std::string numeClient, prenumeClient;
    std::string numeAngajat, prenumeAngajat;
    std::string tipServiciu, data, ora, plataText;

    std::cout<< "Nume: ";
    std::cin>> numeClient;
    std::cout<< "Prenume: ";
    std::cin>> prenumeClient;
    Client& client = cautaClient(clienti, numeClient, prenumeClient);

    std::cout<< "Nume angajat: ";
    std::cin>> numeAngajat;
    std::cout<< "Prenume angajat: ";
    std::cin>> prenumeAngajat;
    Angajat& angajat = cautaAngajat(angajati, numeAngajat, prenumeAngajat);

    std::cout<< "Tip serviciu: ";
    std::cin>> tipServiciu;

    if(specializareBuna(angajat, tipServiciu)== 0){
        throw ProgramareInvalidaExceptie("angajatul nu are specializarea potrivita");
    }

    std::shared_ptr<Serviciu> serviciu;

    if(tipServiciu == "MANICHIURA"){
        bool gel, design, crema;
        std::cout<< "Gel (0/1): ";
        std::cin>> gel;
        std::cout<< "Design (0/1): ";
        std::cin>> design;
        std::cout<< "Crema (0/1): ";
        std::cin>> crema;

        serviciu = std::make_shared<Manichiura>("Manichiura", pret, durata, gel, design, crema);
    }else if(tipServiciu == "PEDICHIURA"){
        bool gel, design, masaj;
        std::cout<< "Gel (0/1): ";
        std::cin>> gel;
        std::cout<< "Design (0/1): ";
        std::cin>> design;
        std::cout<< "Masaj (0/1): ";
        std::cin>> masaj;

        serviciu = std::make_shared<Pedichiura>("Pedichiura", pret, durata, gel, design, masaj);
    }else if(tipServiciu == "COAFOR"){
        bool vopsit;
        std::string lungimePar;
        std::cout<< "Vopsit (0/1): ";
        std::cin>> vopsit;
        std::cout<< "Lungime par: ";
        std::cin>> lungimePar;

        serviciu = std::make_shared<Coafor>(pret, durata, vopsit, lungimePar);
    }else if(tipServiciu == "COSMETICA"){
        bool masca;
        std::string tipTratament;
        std::cout<< "Masca (0/1): ";
        std::cin>> masca;
        std::cout<< "Tip tratament: ";
        std::cin>> tipTratament;

        serviciu = std::make_shared<Cosmetica>(pret, durata, masca, tipTratament);
    }else{
        throw ProgramareInvalidaExceptie("tip serviciu invalid");
    }

    std::cout<< "Data: ";
    std::cin>> data;
    std::cout<< "Ora: ";
    std::cin>> ora;

    if(!angajatDisponibil(programari, angajat, data, ora)){
        throw ProgramareInvalidaExceptie("angajat ocupat");
    }

    std::cout<< "Plata (CASH/CARD/TRANSFER): ";
    std::cin>> plataText;

    programari.emplace_back(client, angajat, serviciu, data, ora, plataFinal(plataText));

    std::ofstream fout("programari.txt", std::ios_base::app);
    fout<<client.getNume()<< " " <<client.getPrenume()<< " " <<angajat.getNume()<< " " <<angajat.getPrenume()<< " " <<
    tipServiciu<< " " <<data<< " " <<ora<< " " <<plataText<< " " <<serviciu->getPret()<< " " <<serviciu->getDurata()<<std::endl;

    std::cout<<"Programare adaugata.\n";
}

int main()
{
    std::vector<Client> clienti;
    std::vector<Angajat> angajati;
    std::vector<Programare> programari;

    try{
        citesteClienti(clienti, "clienti.txt");
        citesteAngajati(angajati, "angajati.txt");
        citesteProgramari(programari, clienti, angajati, "programari.txt");

        int optiune;
        do{
            std::cout<< "\n======== SALON BRB ========\n";
            std::cout<< "1. Afiseaza clientii\n";
            std::cout<< "2. Afiseaza angajatii\n";
            std::cout<< "3. Afiseaza programarile\n";
            std::cout<< "4. Afiseaza costul fiecarei programari\n";
            std::cout<< "5. Calculeaza incasarile unei zile\n";
            std::cout<< "6. Calculeaza totalul platit de un client intr-o zi\n";
            std::cout<< "7. Adauga client nou\n";
            std::cout<< "8. Adauga programare noua\n";
            std::cout<< "9. Afiseaza programarile cu timp suplimentar\n";
            std::cout<< "10. Iesire\n";
            std::cout<< "Optiune (scrieti numarul optiunii dvs.): ";
            std::cin>>optiune;

            try{
                if(optiune == 1){                       //afisez clientii din fisiserul "clienti.txt"
                    for(const auto& c : clienti){
                        std::cout<< c <<std::endl;
                    }
                }else if(optiune == 2){                 //afisez angajatii din fisiserul "angajati.txt"
                    for(const auto& a : angajati){
                        std::cout<< a <<std::endl;
                    }
                }else if(optiune == 3){                 //afisez programarile din fisierul "programari.txt"
                    for(const auto& p : programari){
                        std::cout<< p <<std::endl;
                    }
                }else if(optiune == 4){
                    for(const auto& p : programari){
                        std::cout << p.descriereProgramare() <<std::endl;              //afisez fiecare programare
                        std::cout << "Cost final: " << p.calcCostFinal(programari) << " lei\n";      //afisez suma
                    }
                }else if(optiune == 5){
                    std::string data;
                    std::cout<< "Data: ";
                    std::cin>> data;                        //aleg data in care vreau sa vad cat s-a incasat
                    std::cout<<"Incasari in data " <<data<< ": "<< Programare::calcIncasariZi(programari, data)<<" lei\n";
                }else if(optiune == 6){
                    std::string nume, prenume, data;
                    float total = 0;
                    //scriu numele, prenumele si data pentru a vedea cat a cheltuit respectivul client
                    std::cout<< "Nume client: ";
                    std::cin>>nume;
                    std::cout<< "Prenume client: ";
                    std::cin>>prenume;
                    std::cout<< "Data: ";
                    std::cin>>data;
                    Client& client = cautaClient(clienti, nume, prenume);   //verific daca exista clientul in fisier; de nu, afisez eroare

                    for(const auto& p : programari){                        //daca gasesc in programari data aleasa si numele exact al clientului cautat
                        if(p.getData() == data && p.getClient().getNume() == client.getNume() && p.getClient().getPrenume() == client.getPrenume()){
                            total += p.calcCostFinal(programari);           //calculez suma
                        }
                    }
                    std::cout<< "Suma plata: " << total <<" lei\n";
                }else if(optiune == 7){             //creez client nou
                    adaugaClient(clienti);
                }else if(optiune == 8){             //creez programare noua
                    adaugaProgramare(programari, clienti, angajati);
                }else if(optiune == 9){             //afisez ce servicii necesita timp suplimentar
                    for(const auto& p : programari){
                        if(p.areServiciuCuTimpSuplimentar()){
                            std::cout<< p.descriereProgramare()<<std::endl;
                        }
                    }
                }else if(optiune == 10){
                    std::cout<< "La revedere!\n";
                }else{
                    std::cout<< "Optiunea nu exista\n";
                }
            }
            catch(const SalonExceptii& e) {
                std::cout<< "Eroare: " <<e.what()<<std::endl;
            }

        }while(optiune!=10);

        std::cout<< "\nTotal clienti: "<< Client::getNrClienti() <<std::endl;
        std::cout<< "Total angajati: "<< Angajat::getNrAngajati() <<std::endl;
    }
    catch(const SalonExceptii& e){
        std::cout<< "Eroare salon: " << e.what() <<std::endl;
    }
    catch(const std::exception& e){
        std::cout<< "Eroare generala: " << e.what() <<std::endl;
    }
    return 0;
}
