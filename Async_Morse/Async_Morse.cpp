#include "Async_Morse.h"

/*
  Definicção do Dicionário de Tradução
  OBS: underline no final de cada letra servirá
  para identificar término da letra em código Morse
*/
struct Morse::tradutorMorse dicionarioMorse[] = {
  { 'a', ". -_______" },
  { 'b', "- . . .___" },
  { 'c', "- . - .___" },
  { 'd', "- . ._____" },
  { 'e', "._________" },
  { 'f', ". . - .___" },
  { 'g', "- - ._____" },
  { 'h', ". . . .___" },
  { 'i', ". ._______" },
  { 'j', ". - - -___" },
  { 'k', "- . -_____" },
  { 'l', ". - . .___" },
  { 'm', "- -_______" },
  { 'n', "- ._______" },
  { 'o', "- - -_____" },
  { 'p', ". - - .___" },
  { 'q', "- - . -___" },
  { 'r', ". - ._____" },
  { 's', ". . ._____" },
  { 't', "-_________" },
  { 'u', ". . -_____" },
  { 'v', ". . . -___" },
  { 'w', ". - -_____" },
  { 'x', "- . . -___" },
  { 'y', "- . - -___" },
  { 'z', "- - . .___" },
  { '1', ". - - - -_" },
  { '2', ". . - - -_" },
  { '3', ". . . - -_" },
  { '4', ". . . . -_" },
  { '5', ". . . . ._" },
  { '6', "- . . . ._" },
  { '7', "- - . . ._" },
  { '8', "- - - . ._" },
  { '9', "- - - - ._" },
  { '0', "- - - - -_" }
};

const int tamanhoTradutor = sizeof(dicionarioMorse) / sizeof(dicionarioMorse[0]);

// Método para criação do objeto da classe e inicialização das variáveis
Morse::Morse( byte pin,
              int dotTime,
              int dashTime,
              int timeBetweenValues,
              int timeBetweenLetters,
              int timeBetweenWords,
              int endTime) {
  pino = pin;
  tempoPonto = dotTime;
  tempoTraco = dashTime;
  tempoEntreValores = timeBetweenValues;
  tempoEntreLetras = timeBetweenLetters;
  tempoEntrePalavras = timeBetweenWords;
  tempoFinal = endTime;
  tempo = millis();
  pinMode(pin, OUTPUT);
  finalMorse = false;
}

// Método para inserção da palavra a ser convertida em código morse
void Morse::palavra(String text, bool repeat) {
  texto = text;
  texto.toLowerCase();
  repetir = repeat;
  indiceLetraAtual = 0;
  finalMorse = false;
}


/* Método para manter o tradutor Morse sendo executado
   necessário utilizar dentro do loop e ser chamado a todo o ciclo */
void Morse::ativar(bool debug, bool state) {
  if (state) {
    String morse = verificarMorse(texto.charAt(indiceLetraAtual));
    if (debug && !debugPrint) {
      debugPrint = true;
      Serial.print("Texto: ");
      Serial.print(texto);
      Serial.print("   char: ");
      Serial.print(texto.charAt(indiceLetraAtual));
      Serial.print("    Morse: ");
      for (int i = 0; i < morse.length(); i++) {
        if (morse.charAt(i) == '_') {
          break;
        }
        Serial.print(morse.charAt(i));
      }
      Serial.println();
    }
    executarMorse(morse, indiceAtual);
  }
}

// Método para comparar a letra com o dicionário de morse e encontrar o seu correspondente em código Morse
String Morse::verificarMorse(char letra) {
  for (int i = 0; i < tamanhoTradutor; i++) {
    if (letra == dicionarioMorse[i].letra) {
      return dicionarioMorse[i].morse;
    }
  }
}

// Método para identificar cada símbolo do dicionario de morse e tratar cada um respectivamente
void Morse::executarMorse(String morse, byte indice) {
  if (morse.charAt(indice) == '.') {
    morseLED(tempoPonto, morse);
  } else if (morse.charAt(indice) == '-') {
    morseLED(tempoTraco, morse);
  } else if (morse.charAt(indice) == ' ') {
    morseLED(tempoEntreValores, morse, false);
  } else if (morse.charAt(indice) == '_') {
    if (indiceLetraAtual + 1 >= texto.length()) {
      morseLED(tempoFinal, morse, false);
    } else {
      if (texto.charAt(indiceLetraAtual + 1) == ' ') {
        morseLED(tempoEntrePalavras, morse, false);
      } else {
        morseLED(tempoEntreLetras, morse, false);
      }
    }
  }
}

// Método para execução do código Morse no LED correspondente
void Morse::morseLED(int tempoMorse, String morse, bool ligado) {
  if ((unsigned long)millis() - tempo < tempoMorse) {
    digitalWrite(pino, ligado);
  } else {
    tempo = millis();
    digitalWrite(pino, 0);
    indiceAtual++;
    if (morse.charAt(indiceAtual-1) == '_') {
      indiceAtual = 0;
      debugPrint = false;
      indiceLetraAtual++;
      if (indiceLetraAtual >= texto.length()) {
        finalMorse = true;
        if (repetir) {
          indiceLetraAtual = 0;
        }
        //acabou o texto
      }
    }
  }
}