#include <Async_Morse.h>

/*
 * EXEMPLO DE UTILIZAÇÃO
 */

// Instancia dois objetos da Classe Morse, um no pino 2 e um no pino 4
Morse morse1(2, 500, 2000, 500, 1500, 3000, 5000);
Morse morse2(4, 200, 1000, 200, 1000, 2000, 3000);
// (pino, tempoPonto, tempoTraco, tempoEntreValores, tempoEntreLetras, tempoEntrePalavras, tempoFinal)


void setup() {
  Serial.begin(115200);
  morse1.palavra("Daniel"); // Define a palavra "Daniel" para o objeto morse1, sem repetição
  morse2.palavra("SOS", true); // Define a palavra "SOS" para o objeto morse2, com repetição
}

void loop() {
  morse1.ativar(true); // O objeto morse1 irá ser ativado com debug Serial
  morse2.ativar(); // O objeto morse2 irá ser ativado sem debug Serial
  if (morse1.finalMorse) { // Caso a palavra do objeto morse1 finalize
    morse1.palavra("ESP32", true); // Modifique a palavra do objeto morse1 para "ESP32" com repetição
  }
}
