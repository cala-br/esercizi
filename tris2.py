def printTab(matrice):
  # Meglio fare 
  # for row in matrice:
  #   formattedRow = ' '.join(row)
  #   print(formattedRow)
  tempStr = ""
  for i in range(len(matrice)):
      tempStr = " ".join(matrice[i])
      print(tempStr)

def aggiusta(val):
    # Gestendo una matrice 3x3 questi controlli
    # si semplificherebbero molto

    if val == 1:
        val = 0
    elif val == 3:
        val = 4
    else:
        while val < 1 or val > 3:
            val = int(input("Inserisci un valore valido: "))
    return val

def final(matr):
  # Si capisce cosa fa, ma è difficile
  # da debuggare
  # Potresti anche combinare tutto con degli or
  # for i in range(0,5,2):
  #   hasPlayerWon = \
  #     (matr[i][0]==matr[i][2] and matr[i][2]==matr[i][4] and matr[i][0]!=" ") or \
  #     (matr[0][i]==matr[2][i] and matr[2][i]==matr[4][i] and matr[0][i]!=" ") or \
  #     (matr[0][0]==matr[2][2] and matr[2][2]==matr[4][4] and matr[0][0]!=" ") or \
  #     (matr[0][4]==matr[2][2] and matr[2][2]==matr[4][0] and matr[0][4]!=" ")

  #   if hasPlayerWon:
  #     return True
    
  # return False

  check1=False
  for i in range(0,5,2):
    if matr[i][0]==matr[i][2] and matr[i][2]==matr[i][4] and matr[i][0]!=" ":
        check1=True
    if matr[0][i]==matr[2][i] and matr[2][i]==matr[4][i]and matr[0][i]!=" ":
        check1=True
    if matr[0][0]==matr[2][2] and matr[2][2]==matr[4][4]and matr[0][0]!=" ":
        check1=True
    if matr[0][4]==matr[2][2] and matr[2][2]==matr[4][0]and matr[0][4]!=" ":
        check1=True
  return check1

record = []
player = "X"
check = False

# Sarebbe meglio gestire una matrice 3x3 come gameboard
# e lasciar stampare il 'campo' alla funzione printTab
for x in range(5):
    void = [" "] * 5
    record.append(void)
for x in range(5):
    for y in range(5):
        if x % 2 != 0:
            if y % 2 == 0:
                record[x][y] = "-"
            else:
                record[x][y] = "+"
        else:
            if y % 2 != 0:
                record[x][y] = "|"
printTab(record)

# Questo può diventare un while True:
# dato che esci con un break
while check == False:
  
  # Questo blocco si può estrarre in una funzione,
  # dato che lo usi anche dopo
    newX = int(input("Giocatore " + player + " inserisci riga: ")) 
    newX = aggiusta(newX)      
    newY = int(input("Giocatore " + player + " inserisci colonna: "))
    newY = aggiusta(newY)

    while record[newX][newY] != " ":
      print("Inserisci una posizione vuota")
      newX = int(input("Giocatore " + player + " inserisci  riga: "))
      newX = aggiusta(newX)
      newY = int(input("Giocatore " + player + " inserisci colonna: "))
      newY = aggiusta(newY)
    record[newX][newY] = player
    check=final(record)

    # Questo controllo si può spostare 
    # dopo il printTab, in modo da non ripetere del codice
    # Ossia 
    # printTab(record)
    # if check:
    #   break
    if check==True:
      printTab(record)
      break
    printTab(record)

    # Questo if se vuoi puoi renderlo inline
    # player = \
    #   'X' if player == 'O' else 'O'
    #
    if player == "X":
        player = "O"
    else:
        player = "X"

print("Ha vinto il giocatore " + player)