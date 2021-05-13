#include <iostream>
#include <fstream>
using namespace std;

const int questionAnswerMaxLength = 50;
const int answersPerQuestion = 3;

const char examFileName[] = "Esame.txt";

struct questions
{
    char question[questionAnswerMaxLength];
    char answers[answersPerQuestion][questionAnswerMaxLength];
    char correctAnswer;
};

// legge una riga da istream is e la copia nel buffer riga
void read_line(istream &is, char *line)
{
 // consuma eventuali sequenze di newline,
 // per evitare errori nella lettura di
 // una riga che si sta per effettuare
	while (is.peek() == '\n')
			is.get() ;

	is.get(line, questionAnswerMaxLength) ; // legge una riga
	is.get() ; // consuma il newline che
		   // segue la riga appena letta
}

questions * inizializza_traccia(questions *exam, int &numberOfQuestions, int userInput)
{
    if(numberOfQuestions != 0)
    {
        delete [] exam;
        numberOfQuestions = 0;
    }
    numberOfQuestions = userInput;
    exam = new questions[numberOfQuestions];

    return exam;
}

void carica_traccia(questions *exam, const int numberOfQuestions)
{
    for(int i = 0; i < numberOfQuestions; i++)
    {
        cout<<i+1<<")"<<endl;
        cout<<"Inserisci la domanda: "<<endl;
        read_line(cin, exam[i].question);

        for(int j = 0; j < answersPerQuestion; j++)
        {
            cout<<"Inserisci la risposta "<<static_cast<char>('a'+j)<<":"<<endl;
            read_line(cin, exam[i].answers[j]);
        }
        cout<<"Inserisci la risposta corretta : a, b, c..."<<endl;
        cin>>exam[i].correctAnswer;
    }
}

void stampa_traccia(const questions *exam, const int numberOfQuestions)
{
    for(int i = 0; i < numberOfQuestions; i++)
    {
        cout<<i+1<<". "<<exam[i].question<<":"<<endl;
        for(int j = 0; j < answersPerQuestion; j++)
        {
            char letter = static_cast<char>('a'+j);
            if(letter == exam[i].correctAnswer)
            {
                cout<<"* ";
            }
            cout<<letter<<") "<<exam[i].answers[j]<<endl;
        }
        cout<<endl;
        cout<<"-------------------------------"<<endl;
    }
}
questions * carica_traccia_da_file(questions *exam, int &numberOfQuestions)
{
    ifstream fileExam(examFileName);

    if(fileExam)
    {
        int numOfQuestions;
        fileExam>>numOfQuestions;
        
        exam = inizializza_traccia(exam, numberOfQuestions, numOfQuestions);

        for(int i = 0; i < numberOfQuestions; i++)
        {
            char *target = reinterpret_cast<char*>(&exam[i]);
            fileExam.read(target, sizeof(questions));
            fileExam.get();
        }

        return exam;

    }
    else
    {
        cout<<"Errore in apertura del file"<<endl;
        return 0;
    }
    
}
void salva_traccia(const questions *exam, const int numberOfQuestions)
{
    ofstream fileExam(examFileName);

    if(fileExam)
    {
        fileExam<<numberOfQuestions<<endl;
        for(int i = 0; i < numberOfQuestions; i++)
        {
            fileExam.write(reinterpret_cast<const char *>(&exam[i]), sizeof(exam));
            fileExam<<endl;
        }
        fileExam.close();
    }
    else
    {
        cout<<"Errore nella creazione del file"<<endl;
    }
    
}

int main()
{

    questions *exam;
    int numberOfQuestions = 0;

	const char menu[] =
		"1. Inizializza traccia\n"
		"2. Stampa traccia\n"
		"3. Salva traccia\n"
		"4. Carica traccia\n"
		"5. Fai domanda\n"
		"6. Fai domanda 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
            int num;
            do{
                cout<<"Inserisci il numero di domande: ";
                cin>>num;
            }while(num <= 0);
            exam = inizializza_traccia(exam, numberOfQuestions, num);
            carica_traccia(exam, numberOfQuestions);
			break;
		case 2:
            if(numberOfQuestions != 0)
            {
                stampa_traccia(exam, numberOfQuestions);
            }
            else
            {
                cout<<"Quiz vuoto"<<endl;
            }
			break;
		case 3:
            salva_traccia(exam, numberOfQuestions);
			break;
		case 4:
            exam = carica_traccia_da_file(exam, numberOfQuestions);
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