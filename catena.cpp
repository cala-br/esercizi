#include <iostream>
using namespace std;


int main()
{
    /* Programma per la gestione di una Catena di Anelli.
   Gli anelli della catena possono essere di RAME o di FERRO.
   Possono essere presenti al piu' due anelli di RAME, mentre non esiste un 
   limite al numero di anelli di FERRO. All'inizio la catena è vuota.
   Gli anelli della catena sono numerati a partire da 1.
   Il programma deve fornire un menu con le seguenti operazioni:
   1) inserire un anello di RAME o di FERRO in posizione j (uno alla volta)
      Le posizioni ammissibili vanno dalla prima a quella immediatamente 
      successiva all'ultima. Il programma da un messaggio di notifica nel caso
      in cui non sia possibile effettuare l'inserimento.
      Quando un anello è inserito nella posizione j, tutti quelli che si 
      trovano nelle posizioni da j in poi si spostano in avanti di una 
      posizione. Il numero totale di anelli aumenta ovviamente di una unità.
   2) eliminare l'anello in posizione j (uno alla volta)
      Il programma da un messaggio di notifica nel caso in cui non sia
      possibile effettuare l'estrazione.
      Cosa succede agli anelli dalla posizione j+1 in poi?
   3) stampare la catena nel seguente formato:
       FFRFR
       dove F indica un anello di FERRO; R indica un anello di RAME.
       La catena precedente ha 5 anelli; gli in posizione 1, 2 e 4 sono di 
       ferro, mentre gli anelli in posizione 3 e 5 sono di RAME.
   4) Terminare
*/
    int firstRing = 1;
    int lastRing = 1;

    const int NOT_PRESENT = -1;
    int firstCopperRing = NOT_PRESENT;
    int secondCopperRing = NOT_PRESENT;

    const int IRON = 1;
    const int COPPER = 2;

    const int ADD_RING = 1;
    const int REMOVE_RING = 2;
    const int PRINT_CHAIN = 3;
    const int EXIT = 4;

    int option;
    while (true)
    {
        std::cout
            << "Choose an option\n"
            << "1. Add ring\n"
            << "2. Remove ring\n"
            << "3. Print chain\n"
            << "4. Exit\n"
            << " >> ";

        std::cin >> option;
        switch (option)
        {
        case ADD_RING: {
            std::cout
                << "\nPick a material\n"
                << "1. Iron\n"
                << "2. Copper\n"
                << " >> ";

            int material;
            std::cin >> material;

            const bool isMaterialInvalid = 
                material != COPPER and material != IRON;

            if (isMaterialInvalid) {
                std::cout << "This material is invalid.\n";
                break;
            }

            if (material == COPPER) {
                const bool areAllCopperRingsUsed =
                    firstCopperRing != NOT_PRESENT and secondCopperRing != NOT_PRESENT;

                if (areAllCopperRingsUsed) {
                    std::cout << "All copper rings are used.\n";
                    break;
                }
            }

            std::cout
                << "\nInsert a ring\n"
                << "Available indexes range from " << firstRing << " to " << lastRing << '\n'
                << " >> ";

            int position;
            std::cin >> position;

            const bool isNotInRange = 
                position < firstRing or position > lastRing;

            if (isNotInRange) {
                std::cout << "It's impossible to insert a ring at this index.\n";
                break;
            }

            lastRing++;

            if (material == COPPER) {
                if (firstCopperRing == NOT_PRESENT) {
                    firstCopperRing = position;
                    break;
                }
                else if (secondCopperRing == NOT_PRESENT) {
                    secondCopperRing = position;
                    break;
                }
            }
            else {
                if (firstCopperRing == position)
                    firstCopperRing++;

                else if (secondCopperRing == position)
                    secondCopperRing++;
            }

            bool hasFirstRing = firstCopperRing != NOT_PRESENT;
            bool hasSecondRing = secondCopperRing != NOT_PRESENT;
            const bool hasCopperRings = hasFirstRing or hasSecondRing;
            
            if (!hasCopperRings) break;

            if (position < firstCopperRing and hasFirstRing) {
                firstCopperRing++;
            }

            if (position < secondCopperRing and hasSecondRing) {
                secondCopperRing++;
            }
            break;
        }

        case REMOVE_RING: {
            std::cout
                << "\nRemove a ring\n"
                << "Available indexes range from " << firstRing << " to " << (lastRing - 1) << '\n'
                << " >> ";

            int position;
            std::cin >> position;

            const bool isNotInRange = 
                position < firstRing or position > lastRing;

            if (isNotInRange) {
                std::cout << "It's impossible to remove the ring at this index.\n";
                break;
            }

            lastRing--;
            
            bool hasFirstRing = firstCopperRing != NOT_PRESENT;
            bool hasSecondRing = secondCopperRing != NOT_PRESENT;
            const bool hasCopperRings = hasFirstRing or hasSecondRing;
            
            if (!hasCopperRings) break;

            if (hasFirstRing) {
                if (firstCopperRing == position) {
                    firstCopperRing = NOT_PRESENT;
                }
                else if (position < firstCopperRing) {
                    firstCopperRing--;
                }
            }

            if (hasSecondRing) {
                if (secondCopperRing == position) {
                    secondCopperRing = NOT_PRESENT;
                }
                else if (position < secondCopperRing) {
                    secondCopperRing--;
                }
            }

            break;
        }

        case PRINT_CHAIN: {
            const bool hasFirstRing = firstCopperRing != NOT_PRESENT;
            const bool hasSecondRing = secondCopperRing != NOT_PRESENT;
            const bool hasCopperRings = hasFirstRing or hasSecondRing;

            if (!hasCopperRings) {
                for (int i = firstRing; i < lastRing; ++i)
                    std::cout << 'F';

                break;
            }

            int furtherLeftCopper = NOT_PRESENT;
            int furtherRightCopper = NOT_PRESENT;

            if (!hasSecondRing and hasFirstRing) {
                furtherLeftCopper = firstCopperRing;
            }
            else if (!hasFirstRing and hasSecondRing) {
                furtherLeftCopper = secondCopperRing;
            }
            else if (firstCopperRing < secondCopperRing) {
                furtherLeftCopper = firstCopperRing;
                furtherRightCopper = secondCopperRing;
            }
            else {
                furtherLeftCopper = secondCopperRing;
                furtherRightCopper = firstCopperRing;
            }

            int i = firstRing;
            for (; i < furtherLeftCopper; ++i)
                std::cout << 'F';
            std::cout << 'R';
            i++;

            if (furtherRightCopper != NOT_PRESENT) {
                for (; i < furtherRightCopper; ++i) 
                    std:: cout << 'F';
                std::cout << 'R';
                i++;
            }

            for (; i < lastRing; ++i)
                std::cout << 'F';

            break;
        }

        case EXIT: 
            std::cout << "Exiting...";
            return 0;
        }

        std::cout << "\n\n";
    } 
}