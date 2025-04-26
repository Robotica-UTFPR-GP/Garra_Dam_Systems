#include <Servo.h>

#define esteira 13
// Criar objetos servo
Servo base;
Servo extensao;
Servo elevar;
Servo garra;



// Variáveis de posição
int posBaseCentro = 90;
int posBaseDireita = 140;
int posBaseEsquerda = 40;

int posExtensaoRecolhida = 50;
int posExtensaoEstendida = 100;

int posElevado = 190;
int posBaixo = 180;

int posGarraAberta = 60;
int posGarraFechada = 120;

void setup() {
  base.attach(3);
  extensao.attach(5);
  elevar.attach(6);
  garra.attach(9);

  pinMode(esteira, OUTPUT);
  // Posição inicial: base central, braço pra cima, garra fechada
  base.write(posBaseCentro);
  extensao.write(posExtensaoRecolhida);
  elevar.write(posElevado);
  garra.write(posGarraFechada);
  delay(1000);
  digitalWrite(esteira, LOW);
}

void loop() {
  
  // 1. Simula chegada do bloco na direita (sensor)
  delay(1000); // tempo para simular sensor
  // Para esteira (simulado)

  // 2. Movimento para pegar o bloco
  base.write(posBaseDireita);
  delay(800);

  extensao.write(posExtensaoEstendida);
  elevar.write(posBaixo);
  garra.write(posGarraAberta);
  delay(1000);

  garra.write(posGarraFechada);
  delay(800);

  // 3. Volta para posição inicial
  elevar.write(posElevado);
  extensao.write(posExtensaoRecolhida);
  delay(800);

  // 4. Leva para esquerda e solta bloco
  base.write(posBaseEsquerda);
  delay(800);

  extensao.write(posExtensaoEstendida);
  elevar.write(posBaixo);
  delay(800);

  garra.write(posGarraAberta);
  delay(800);

  // 5. Volta para posição base
  extensao.write(posExtensaoRecolhida);
  elevar.write(posElevado);
  delay(800);

  base.write(posBaseCentro);
  garra.write(posGarraFechada);
  delay(2000); // Espera antes de novo ciclo
}
