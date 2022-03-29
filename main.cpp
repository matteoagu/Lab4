#include "Regression.hpp"

#include <iostream>

int main ()
{
    Regression reg;
    
    std::cout<<"Questo programma fa il fit a una retta un insieme di numeri inseriti dall'utente.\nDigitare a per aggiungere un punto, digitare f per fare il fit dei punti inseriti.\n\n";

    while(1<2)
    {
        char scelta{};
        std::cin>>scelta;

        if (scelta=='a')
        {
            double x{};
            double y{};

            std::cin>>x>>y;
            reg.add(x,y);
        }

        if (scelta=='f')
        {
            Result res = fit(reg);

            std::cout<<"y = "<<res.A<<" "<<res.B<<"x\n\n";    //fare meglio l'estetica dell'output
            break;
        }

        if (scelta!='a' && scelta!='f')
        {
            std::cout<<"Entrata non valida!\n";
        }
    }

}