const int pinVermelho = 9;
const int pinAmarelo = 11;
const int pinVerde = 13;

const unsigned long intervaloVermelho = 6000; // Tempo do vermelho aceso (6 segundos)
const unsigned long intervaloAmarelo = 2000;  // Tempo do amarelo aceso (2 segundos)
const unsigned long intervaloVerde = 4000;    // Tempo do verde aceso (4 segundos)

unsigned long ultimoTempo = 0; // Marca o tempo da última troca
int estadoAtual = 0; // 0 = vermelho, 1 = amarelo, 2 = verde, 3 = amarelo

void setup() {
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);

  // Inicializa com o LED vermelho aceso
  digitalWrite(pinVermelho, HIGH);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (estadoAtual == 0 && tempoAtual - ultimoTempo >= intervaloVermelho) {
    // Muda do vermelho para o amarelo
    digitalWrite(pinVermelho, LOW);  // Desliga o vermelho
    digitalWrite(pinAmarelo, HIGH);  // Liga o amarelo
    ultimoTempo = tempoAtual;        
    estadoAtual = 1;                 
  }
  else if (estadoAtual == 1 && tempoAtual - ultimoTempo >= intervaloAmarelo) {
    // Muda do amarelo para o verde
    digitalWrite(pinAmarelo, LOW);   // Desliga o amarelo
    digitalWrite(pinVerde, HIGH);    // Liga o verde
    ultimoTempo = tempoAtual;        
    estadoAtual = 2;                 
  }
  else if (estadoAtual == 2 && tempoAtual - ultimoTempo >= intervaloVerde) {
    // Muda do verde para o amarelo
    digitalWrite(pinVerde, LOW);     // Desliga o verde
    digitalWrite(pinAmarelo, HIGH);  // Liga o amarelo
    ultimoTempo = tempoAtual;        
    estadoAtual = 3;                 
  }
  else if (estadoAtual == 3 && tempoAtual - ultimoTempo >= intervaloAmarelo) {
    // Muda do amarelo para o vermelho
    digitalWrite(pinAmarelo, LOW);   // Desliga o amarelo
    digitalWrite(pinVermelho, HIGH); // Liga o vermelho
    ultimoTempo = tempoAtual;        
    estadoAtual = 0;                 
  }
}
