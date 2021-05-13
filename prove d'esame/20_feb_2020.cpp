#include <iostream>
#include <fstream>

using namespace std;


const int lunghezzaMax = 40;

struct foglio_t
{
    int righe = 0;
    const int colonne = lunghezzaMax;
    char (*testo) [lunghezzaMax];
};

enum stampa_t {schermo, file};

bool inizializzaVuoto(const int, foglio_t &);
void inserisciTesto(foglio_t &);
void stampaTesto(const foglio_t, const stampa_t, ostream &);
bool caricaTesto(foglio_t &);

int main()
{
    foglio_t foglioUtente = {};

	const char menu[] =
		"1. Inizializza testo\n"
		"2. Stampa testo\n"
		"3. Salva testo\n"
		"4. Carica testo\n"
		"5. Cerca righe\n"
		"6. Cerca righe 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
        {
            int nRighe;
            cout<<"Righe: ";
            cin>>nRighe;

            if (!inizializzaVuoto(nRighe, foglioUtente))
                cout<<"Inserimento errato"<<endl;

            inserisciTesto(foglioUtente);
        }
			break;
		case 2:
            stampaTesto(foglioUtente, schermo, cout);
			break;
		case 3:
        {
            ofstream o("./testo.txt");

            if (!o)
                cout<<"Errore nella creazione dello stream"<<endl;
            else
                stampaTesto(foglioUtente, file, o);
            
            o.close();
        }
        case 4:
            if (!caricaTesto(foglioUtente))
                cout<<"Errore nel caricamento"<<endl;
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}


// legge una riga da istream is e la copia nel buffer riga
void leggi_riga(istream &is, char *riga)
{
 // consuma eventuali sequenze di newline,
 // per evitare errori nella lettura di
 // una riga che si sta per effettuare
	while (is.peek() == '\n')
			is.get();

	is.get(riga, lunghezzaMax); // legge una riga
	is.get(); // consuma il newline che
		   // segue la riga appena letta
}

bool inizializzaVuoto(const int nRighe, foglio_t &foglioDiTesto)
{
    if (nRighe < 0)
        return false;
    
    if (foglioDiTesto.righe != 0)
        delete []foglioDiTesto.testo;
    
    foglioDiTesto.righe = nRighe;
    foglioDiTesto.testo = new char[nRighe][lunghezzaMax];

    return true;
}

void inserisciTesto(foglio_t &foglioDiTesto)
{
    for (int i = 0; i < foglioDiTesto.righe; i++)
    {
        int offset = i * lunghezzaMax;
        leggi_riga(cin, *(foglioDiTesto.testo) + offset);
    }

    return;
}

void stampaTesto(const foglio_t foglioDiTesto,
                 const stampa_t modalita,
                 ostream &stream)
{
    if (modalita == file)
        stream<<foglioDiTesto.righe<<endl;

    for (int i = 0; i < foglioDiTesto.righe; i++)
    {
        for (int j = 0; j < lunghezzaMax &&
             foglioDiTesto.testo[i][j] != '\0'; j++)
                stream<<foglioDiTesto.testo[i][j];
        
        stream<<endl;
    }

    return;
}

bool caricaTesto(foglio_t &foglioDiTesto)
{
    ifstream stream("./testo.txt");
    if (!stream)
        return false;

    int nRighe;
    stream>>nRighe;
    inizializzaVuoto(nRighe, foglioDiTesto);
    
    stream>>noskipws;
    stream.get();

    for (int i = 0; i < foglioDiTesto.righe; i++)
    {
        int j = 0;
        char c;
        while(stream>>c && c != '\n')
            foglioDiTesto.testo[i][j++] = c;
    }

    stream.close();

    return true;
}