Projeto IoT: Monitoramento Ambiental para Situações de Desastre

Este projeto simula um sistema de monitoramento ambiental com três dispositivos ESP32, cada um equipado com um sensor DHT22. Os dados de **temperatura** e **umidade** são enviados via **MQTT** para um servidor e visualizados no **Node-RED**.


 Tecnologias Utilizadas

- ESP32
- Sensor DHT22
- Protocolo MQTT (broker: HiveMQ)
- Node-RED (dashboard e fluxo de dados)
- Wokwi (simulador online)


 Objetivo

O objetivo é simular uma rede de sensores distribuídos para **monitoramento ambiental em áreas de risco**. Cada sensor representa uma pessoa ou ponto de coleta distinto (pessoa1, pessoa2, pessoa3), enviando dados para tópicos MQTT específicos. Os dados são processados e visualizados em tempo real no Node-RED.


 Estrutura do Projeto

Este projeto contém 3 arquivos de código (`.ino`) representando 3 dispositivos ESP32 distintos:

- `dispositivo1.ino`
- `dispositivo2.ino`
- `dispositivo3.ino`

Cada um se conecta ao mesmo broker MQTT, mas publica em tópicos diferentes:

fiap/gs/desastre/dispositivo1
fiap/gs/desastre/dispositivo2
fiap/gs/desastre/dispositivo3


 Como Executar

1. Acesse o [simulador Wokwi](https://wokwi.com).
2. Abra 3 instâncias do projeto, uma para cada código (dispositivo1, 2 e 3).
3. Em cada instância, altere a linha do tópico MQTT:

   const char* mqtt_topic = "fiap/gs/desastre/dispositivoX";

Substitua o X por 1, 2, ou 3, conforme o dispositivo.
4. Dê play nos três projetos.
5. No Node-RED, configure 3 blocos MQTT IN para escutar cada tópico e exibir os dados.

