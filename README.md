# Sistema IoT para Control Domótico e Industrial

Este repositorio contiene el código y documentación del Trabajo Fin de Máster titulado **"Diseño e Implementación de un Sistema IoT para Control Domótico y para la Gestión Remota en Entornos Industriales"**. El proyecto combina tecnologías de microservicios, contenedores, dispositivos DIY y plataformas de código abierto para la automatización del hogar y el control remoto en entornos industriales.

## 🔧 Tecnologías utilizadas

- Docker
- Docker Compose
- MQTT (Mosquitto Broker)
- Zigbee2MQTT
- Home Assistant
- Node-RED
- Dispositivos DIY con ESP8266/ESP32
- Sensores: TSL2561, MQ-2, HC-SR501, DHT11/DHT22, sensor lluvia
- Actuadores: Relés, bombillas inteligentes, Fingerbot, IR Blaster, enchufes Tuya

---

## ⚙️ Instalación de Microservicios

### 1. Requisitos

- Un servidor local (Raspberry Pi, mini-PC o servidor NAS)
- Docker instalado
- Docker Compose instalado
- Acceso a red local y permisos para puertos y dispositivos USB (antena Zigbee)

### 2. Clonar el repositorio

```bash
git clone https://github.com/tu_usuario/tu_repositorio.git
cd tu_repositorio
