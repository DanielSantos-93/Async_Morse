<h1 align="center"> Asynchronous Morse Code for Arduino | ESP32 </h1>

<p align="center">
<img loading="lazy" src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge"/>
</p>
<br>

📌 Índice
=================
<!--ts-->
   * [Sobre](#-sobre)
   * [Funcionamento](#-funcionamento)
   * [Instalação](#-instalação)
   * [Tecnologias Utilizadas](#-tecnologias-utilizadas)
   * [Autor](#-autor)
<!--te-->

<br><br>

# 📄 Sobre
**Este projeto consiste em uma biblioteca (library) para Arduino IDE na qual permite
instanciar objetos da classe Morse definindo os tempos padrões para o funcionamento daquele código morse e o GPIO vinculado a ele.**

<br><br>

# 📘 Funcionamento
**Criação da instância da classe Morse**
<li>Morse morse(pino, tempoPonto, tempoTraco, tempoEntreValores, tempoEntreLetras, tempoEntrePalavras, tempoFinal);</li><br>

**Método para definir qual palavra será traduzida em código Morse, podendo passar o argumento opcional para repetir a palavra após finalizar o código Morse**
<li>morse.palavra(String text, bool repeat = false);</li><br>

**Atributo da instância criada da classe Morse para identificar se já terminou de executar o texto**
<li>morse.finalMorse</li>

<br><br>

# ⚙ Instalação

**Para utilizar esta biblioteca, baixe o arquivo ZIP e instale a biblioteca utilizando o software Arduino IDE**

<br><br>

# 🔨 Tecnologias Utilizadas
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=arduino" />
  </a>
</p>
<li><code> Arduino IDE </code></li>

<br><br>

# 	👤 Autor

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/146108950?s=400&u=26048eb890006652c89c331eac5276730e03cb3b&v=4" width=115><br><sub>Daniel Santos</sub>](https://github.com/DanielSantos-93)
| :---: |
