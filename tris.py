def printGameboard(gameboard):
  divider = '\n- + - + -\n'
  formattedRows = \
    [' | '.join(row) for row in gameboard]

  formattedGameboard = \
    divider.join(formattedRows)

  print(formattedGameboard)
  

def chooseCell(gameboard, player):
  x = int(input(f'Giocatore {player} inserisci riga: '))
  x = validatePosition(x)
  
  y = int(input(f'Giocatore {player} inserisci colonna: '))
  y = validatePosition(y)

  isCellOccupied = gameboard[x][y] != ' '
  if isCellOccupied:
    print('Inserisci una posizione vuota')
    return chooseCell(gameboard, player)

  return (x, y)


def validatePosition(pos):
  while pos < 1 or pos > 3:
    pos = int(input("Inserisci un valore valido: "))
    
  pos -= 1
  return pos


def checkIfPlayerWon(gameboard, player):
  board = gameboard
  for i in range(3):
    hasPlayerWon = \
      (board[i][0] == player and board[i][0] == board[i][1] and board[i][1] == board[i][2]) or \
      (board[0][i] == player and board[0][i] == board[1][i] and board[1][i] == board[2][i]) or \
      (board[0][0] == player and board[0][0] == board[1][1] and board[1][1] == board[2][2]) or \
      (board[0][2] == player and board[0][2] == board[1][1] and board[1][1] == board[2][0])

    if hasPlayerWon:
      return True
    
  return False


SIDES = 3
gameboard = [
  [' '] * SIDES
  for _ in range(SIDES)
]

player = "X"

printGameboard(gameboard)
while True:
  x, y = chooseCell(gameboard, player)
  gameboard[x][y] = player

  hasPlayerWon = \
    checkIfPlayerWon(gameboard, player)
  
  printGameboard(gameboard)
  if hasPlayerWon:
    break

  player = \
    'X' if player == 'O' else 'O'

print(f'Ha vinto il giocatore {player}')
