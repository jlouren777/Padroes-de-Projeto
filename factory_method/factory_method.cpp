#include <iostream>
using namespace std;

class Inimigo {
 public:
  virtual void atacar() = 0;
  virtual ~Inimigo() = default;
};

class Slime : public Inimigo {
 public:
  void atacar() override { cout << "Slime bate com gosma!" << endl; }
};

class Goblin : public Inimigo {
 public:
  void atacar() override { cout << "Goblin ataca com espada!" << endl; }
};

class InimigoCreator {
 public:
  virtual Inimigo* criarInimigo() = 0;
  virtual ~InimigoCreator() = default;
};

class SlimeCreator : public InimigoCreator {
 public:
  Inimigo* criarInimigo() override { return new Slime(); }
};

class GoblinCreator : public InimigoCreator {
 public:
  Inimigo* criarInimigo() override { return new Goblin(); }
};

int main() {
  InimigoCreator* criadorSlime = new SlimeCreator();
  InimigoCreator* criadorGoblin = new GoblinCreator();

  Inimigo* slime = criadorSlime->criarInimigo();
  Inimigo* goblin = criadorGoblin->criarInimigo();

  slime->atacar();
  goblin->atacar();

  delete slime;
  delete goblin;
  delete criadorSlime;
  delete criadorGoblin;

  return 0;
}
