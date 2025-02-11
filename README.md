<samp>
<h1 align="center"> Controle de servomotor por PWM :desktop_computer: </h1>
  
<h2 align="center"> Sobre :pencil: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Repositório com o objetivo de projetar um sistema com a ferramenta Pico SDK para simular o controle do ângulo de um servomotor, com o emprego do módulo PWM (do inglês, Pulse Width Modulation), presente no microcontrolador RP2040, como parte de uma tarefa desenvolvida na Unidade 4 do Capítulo 7 da EmbarcaTech, residência de Sistemas Embarcados. Essa tarefa foi desenvolvida pela residente Isabela Madureira Argolo.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar os seguintes componentes:

  1. Microcontrolador Raspberry Pi Pico W;
  2. Servomotor – motor micro servo padrão – Wokwi.

 &emsp;&emsp;&emsp;&emsp; O programa deve possuir as seguintes funcionalidades:

<p align="justify">  1. Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms; </p>
<p align="justify">  2. Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 12% e aguarde 05 segundos nesta posição (isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus); </p>
<p align="justify">  3. Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 7,35% e aguarde 05 segundos nesta posição (isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 90 graus); </p>
<p align="justify">  4. Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 2,5% e aguarde 05 segundos nesta posição (isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 0 graus); </p>
<p align="justify">  5. Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs,
com um atraso de ajuste de 10ms; </p>
<p align="justify">  6. Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12. O que o discente observou no comportamento da iluminação do referido LED?  </p>

<h3> Estruturação dos Arquivos </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de uma pasta chamada 'wokwi', com os arquivos diagram.json e wokwi.toml (para a simulação no Wokwi) e os arquivos pwm-embarcatech.c (que gerencia todo o projeto) e READ.ME (descrição do projeto).

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Abrir o arquivo diagram.json para usar o simulador Wokwi;
- Executar a simulação;
- (Para testar o projeto no LED RGB - GPIO 12, mude o valor de PWM_SERVO de 22 para 12, compile e execute o projeto na placa BitDogLab).

</samp>
