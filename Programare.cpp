//calcul incasari zi
//calcul cost final


#include "Programare.h"

Programare::Programare(const Client& client, const Angajat& angajat, std::shared_ptr<Serviciu> serviciu, const std::string& data, const std::string& ora, plata tipPlata)
: client(client), angajat(angajat), serviciu(serviciu)), data(data), ora(ora), tipPlata(tipPlata){}

