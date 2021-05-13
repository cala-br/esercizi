#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
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

if (argc < 2) {
cerr<<"Argomenti mancanti"<<endl;
return 1;
}
vector<string> linee_output;

string linea_aggancio(argv[1]);
string linea;
bool buffering = false;

while (getline( cin, linea )) {
if (confronta_contenuto_linee(linea, linea_aggancio)) {
buffering = true;
linee_output.clear();
}
if (buffering)
linee_output.push_back(linea);
}

// stampa le ultime linee a partire dall'ultima stampa
for (std::vector<string>::const_iterator i = linee_output.begin();
     i != linee_output.end(); ++i)
std::cout << *i<<endl;

return 0;
}
