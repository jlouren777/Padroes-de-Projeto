#include <iostream>
using namespace std;

class Enviador {
 public:
  virtual void enviar(const string& texto) = 0;
  virtual ~Enviador() = default;
};

class EnviadorEmail : public Enviador {
 public:
  void enviar(const string& texto) override {
    cout << "[EMAIL] " << texto << endl;
  }
};

class EnviadorSMS : public Enviador {
 public:
  void enviar(const string& texto) override {
    cout << "[SMS] " << texto << endl;
  }
};

class Mensagem {
 protected:
  Enviador* enviador;

 public:
  Mensagem(Enviador* e) : enviador(e) {}
  virtual void enviarMensagem(const string& texto) = 0;
  virtual ~Mensagem() = default;
};

class MensagemSimples : public Mensagem {
 public:
  MensagemSimples(Enviador* e) : Mensagem(e) {}

  void enviarMensagem(const string& texto) override { enviador->enviar(texto); }
};

int main() {
  Enviador* email = new EnviadorEmail();
  Enviador* sms = new EnviadorSMS();

  Mensagem* m1 = new MensagemSimples(email);
  Mensagem* m2 = new MensagemSimples(sms);

  m1->enviarMensagem("Olá, isso é um teste!");
  m2->enviarMensagem("Seu código chegou!");

  delete m1;
  delete m2;
  delete email;
  delete sms;

  return 0;
}
