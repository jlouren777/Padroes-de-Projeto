#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MusicaIterator {
 public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual string currentItem() = 0;
  virtual ~MusicaIterator() = default;
};

class Playlist {
 public:
  virtual MusicaIterator* criarIterator() = 0;
  virtual ~Playlist() = default;
};

class PlaylistSimples : public Playlist {
 private:
  vector<string> musicas;

 public:
  PlaylistSimples(const vector<string>& lista) : musicas(lista) {}

  int count() const { return musicas.size(); }
  string get(int index) const { return musicas[index]; }

  MusicaIterator* criarIterator() override;
};

class PlaylistIterator : public MusicaIterator {
 private:
  const PlaylistSimples* playlist;
  int index;

 public:
  PlaylistIterator(const PlaylistSimples* p) : playlist(p), index(0) {}

  void first() override { index = 0; }

  void next() override { index++; }

  bool isDone() override { return index >= playlist->count(); }

  string currentItem() override { return playlist->get(index); }
};

MusicaIterator* PlaylistSimples::criarIterator() {
  return new PlaylistIterator(this);
}

int main() {
  vector<string> lista = {"Música A", "Música B", "Música C", "Música D"};

  Playlist* playlist = new PlaylistSimples(lista);
  MusicaIterator* it = playlist->criarIterator();

  cout << "Tocando playlist:\n";

  for (it->first(); !it->isDone(); it->next()) {
    cout << "▶ " << it->currentItem() << endl;
  }

  delete it;
  delete playlist;
  return 0;
}
