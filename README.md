# Edge Computing: CP01 - Monitorador de luminosidade

### Introdução
Para o primeiro checkpoint da matéria de Edge Computing, desenvolvemos um sistema de monitoramento de luminosidade que emite um aviso sonoro e luminoso para informar que determinado nível de luminosidade está muito alto. Este projeto é pensado para o case da Vinheria Agnello, para que possa ser usado para um melhor controle do armazenamento de garrafas de vinho.

### Funcionamento
O projeto utiliza como plataforma principal a placa Arduino Uno R3. Conectada nela estão 3 LEDs (vermelho, amarelo e verde), um sensor de luz fotossensível (LDR) e um buzzer. O nível de luminosidade é lido pelo LDR, interpretado pelo Arduino e de acordo com a leitura é feita uma das ações: Acender LED verde (luminosidade adequada); Acender o LED amarelo (luminosidade no limite); Acender o LED vermelho e tocar o buzzer (luminosidade acima do limite).

### Grupo
<li>Alessandra Vaiano (RM551497)</li>  
<li>André Lambert (RM99148)</li>  
<li>Bryan Willian (RM551305)</li>
<li>Lucas Feijó (RM99727)</li>
<li>Vitor Maia (RM99658)</li>

### Simulação do Protótipo
[Link para o Tinkercad](https://www.tinkercad.com/things/kDG7NP2PDzb?sharecode=s7ckZW9Jap535T9Thr7LFq1yI2gnE3UjsxngkxGnrg0)

### Componentes utilizados
<li>Arduino Uno R3</li>
<li>Sensor LDR (para luminosidade)</li>
<li>Protoboard</li>
<li>LEDs</li>
<li>Resistores</li>
<li>Buzzer</li>
<li>Cabos Jumper</li>

### Código
O código para o programa é escrito em C++ e se encontra no arquivo "arduino.c". Utilize o software Arduino IDE para carregar este código para a placa.

### Imagem do circuito
![Imagem](https://github.com/Projetos-Fiap/Edge-Computing-CP01/blob/main/circuit_cp01.png?raw=true)
