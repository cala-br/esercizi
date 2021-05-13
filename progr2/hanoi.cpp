#include <iostream>
#include <vector>

enum class Peg {
  A = 'a',
  B = 'b',
  C = 'c',
};

struct HanoiTower {
  int numberOfPegs;
  Peg sourcePeg;
  Peg destinationPeg;
  Peg sparePeg;
};

struct HanoiMove {
  Peg from;
  Peg to;
};


std::ostream& operator<<(std::ostream& out, const HanoiMove& move) {
  out << "Move from " << (char)move.from
      << " to "       << (char)move.to;
  
  return out;
}


void hanoi(HanoiTower tower, std::vector<HanoiMove>& moves) {
  if (tower.numberOfPegs == 1) {
    moves.push_back({
      .from = tower.sourcePeg,
      .to = tower.destinationPeg,
    });

    return;
  }

  hanoi({
    .numberOfPegs = tower.numberOfPegs - 1,
    .sourcePeg = tower.sourcePeg,
    .destinationPeg = tower.sparePeg,
    .sparePeg = tower.destinationPeg,
  }, moves);

  moves.push_back({
    .from = tower.sourcePeg,
    .to = tower.destinationPeg,
  });

  hanoi({
    .numberOfPegs = tower.numberOfPegs - 1,
    .sourcePeg = tower.sparePeg,
    .destinationPeg = tower.destinationPeg,
    .sparePeg = tower.sourcePeg,
  }, moves);
}


int main() {
  std::vector<HanoiMove> moves;

  hanoi({3, Peg::A, Peg::C, Peg::B}, moves);

  for (const auto move : moves) {
    std::cout << move << '\n';
  }
}