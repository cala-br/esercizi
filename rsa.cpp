#include <iostream>
#include <cmath>

using namespace std;


unsigned int e = 5;
unsigned int d = 173;
unsigned int r = 323;


unsigned int cipher(unsigned int number);
unsigned int decipher(unsigned int secret);
unsigned int computePowWithRemainder(
    unsigned int number,
    unsigned int exponent,
    unsigned int divider
);

int main()
{
    enum MenuOption {
        UPDATE_KEY = 1,
        CIPHER,
        DECIPHER,
        EXIT,
    };

    unsigned int num;
    int option;
    while (true)
    {
        cout << 
            "Chiave attualmente in uso: (" << e << ", " << d << ", " << r << ")\n"
            "1 Inserimento nuova chiave RSA\n"
            "2 Cifratura di un numero\n"
            "3 Decifratura di un numero\n"
            "4 Uscita\n"
            " >> ";
        cin >> option;

        switch (option)
        {
        case UPDATE_KEY:
            cout << "Nuova chiave: ";
            cin >> e >> d >> r;
            break;

        case CIPHER: {
            cout << "Numero da cifrare: ";
            cin >> num;

            cout << cipher(num);
            break;
        }

        case DECIPHER: {
            cout << "Numero da decifrare: ";
            cin >> num;

            cout << decipher(num);
            break;
        }

        case EXIT: 
            return 0;
        }

        cout << "\n\n";
    }
}



unsigned int cipher(unsigned int number) {
    return computePowWithRemainder(number, e, r);
}

unsigned int decipher(unsigned int secret) {
    return computePowWithRemainder(secret, d, r);
}


unsigned int computePowWithRemainder(
    unsigned int number,
    unsigned int exponent,
    unsigned int divider
) {
    unsigned int result = 1;
    unsigned int exp = exponent;

    for (; exp > 0; --exp) {
        result = (result * number) % divider;
    }
 
    return result;
}
