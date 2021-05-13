#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
for (unsigned int i = 0 ; i < s.size() ; i++)
s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
turn_lowercase(linea1);
turn_lowercase(linea2);

string buf1, buf2;
stringstream stream1(linea1), stream2(linea2);

// controllo prima riga della stampa
while (true) {
stream1>>buf1;
stream2>>buf2;

if (!stream1 || !stream2 || buf1 != buf2)
break;
}

if (stream1 || stream2)
return false;

return true;
}

int main(int argc, char** argv)
{
if (argc < 3) {
cout<<"Argomenti mancanti"<<endl;
return 1;
}

int num_linee = atoi(argv[1]);

cout<<"Ora leggo l'output del programma, e come ultima stampa dello stato"
    <<endl<<"mi aspetto:"<<endl;

for (int i = 0 ; i < num_linee ; i++)
cout<<argv[i+2]<<endl;

string linea;
bool letta_una_linea = false;
int indice_linea_corretta = 0;

while (getline( cin, linea ) && indice_linea_corretta < num_linee) {
letta_una_linea = true;
string linea_corretta(argv[indice_linea_corretta+2]);

if (!confronta_contenuto_linee(linea, linea_corretta)) {
cout<<"La seguente riga:"<<endl;
cout<<linea<<endl;
cout<<"Non coincide con la riga attesa, ossia con:"
    <<endl;
cout<<linea_corretta<<endl;

return 1;
}
indice_linea_corretta++;
}

cout<<endl;

if (!letta_una_linea) {
cout<<"Non ho trovato nessuna riga corretta di stampa dello stato!"
    <<endl;
cout<<"Verifica la presenza di tali righe nell'output"<<endl
    <<"e la correttezza del formato di tali righe"<<endl;

return 1;
}

cout<<"Test superato!!!"<<endl;
cout<<"-------------------------------------------------------------"
    <<endl;

return 0;
}
