#ifndef ASYNC_MORSE_H
#define ASYNC_MORSE_H

#include <Arduino.h>


/*
  Criação do Dicionário de Tradução
*/

// Classe para controle do sistema
class Morse {
    byte pino;
    int tempoPonto;
    int tempoTraco;
    int tempoEntreValores;
    int tempoEntreLetras;
    int tempoEntrePalavras;
    int tempoFinal;
    unsigned long tempo;
    String texto;
    byte indiceAtual;
    byte indiceLetraAtual;
    bool debugPrint;
    bool repetir;

  public:
    bool finalMorse;

    // Constructor dos métodos da classe Morse
    Morse( byte pin,
           int dotTime,
           int dashTime,
           int timeBetweenValues,
           int timeBetweenLetters,
           int timeBetweenWords,
           int endTime);

    void palavra(String text, bool repeat = false);
    void ativar(bool debug = false, bool state = true);
    String verificarMorse(char letra);
    void executarMorse(String morse, byte indice);
    void morseLED(int tempoMorse, String morse, bool ligado = true);

    // Definição da struct tradutorMorse
    struct tradutorMorse {
      char letra;
      String morse;
    };
};

#endif