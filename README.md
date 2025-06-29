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
git clone https://github.com/PacoLC/IoT_TFM.git
cd IoT_TFM


## 📚 Bibliografía

[1] ¿Qué es IoT? - Explicación del Internet de las cosas - AWS. (s. f.). Amazon Web Services, Inc. Recuperado 27 de diciembre de 2024, de (https://aws.amazon.com/es/what-is/iot/)

[2] ¿Qué es internet de las cosas? | IoT explicada. (s. f.). SAP. Recuperado 15 de diciembre de 2024, de https://www.sap.com/spain/products/artificial-intelligence/what-is-iot.html  

[3] Qué es la domótica, cómo se aplica y cuáles son sus beneficios. (s. f.). Ferrovial. Recuperado 27 de diciembre de 2024, de https://www.ferrovial.com/es/recursos/domotica/  

[4] Domótica | Idae. (s. f.). Recuperado 27 de diciembre de 2024, de https://www.idae.es/tecnologias/eficiencia-energetica/edificacion/domotica  

[5] Alexa Smart Home—Learn about Home Automation | Amazon.com. (s. f.). Recuperado 15 de diciembre de 2024, de https://www.amazon.com/alexa-smarthome/b?ie=UTF8&node=21442899011&ref=pe_alxhub_aucc_en_us_IC_HP_1_HUB_SMA  

[6] Gestiona tu hogar inteligente con Google Home | Google Home. (s. f.). Recuperado 15 de diciembre de 2024, de https://home.google.com/intl/es_es/welcome/  

[7] ¿Qué es IIOT? Internet Industrial de las Cosas—Iberdrola. (s. f.). Recuperado 27 de diciembre de 2024, de https://www.iberdrola.com/innovacion/que-es-iiot  

[8] Home. (s. f.). Industry IoT Consortium. Recuperado 28 de diciembre de 2024, de https://www.iiconsortium.org/  

[9] An inside look at the drivers for Industry 4.0 | Nokia. (s. f.). Recuperado 28 de diciembre de 2024, de https://www.nokia.com/thought-leadership/articles/industry-4-0/three-key-drivers-forsuccess/

[10] Qué es la Inteligencia Artificial | Plan de Recuperación, Transformación y Resiliencia Gobierno de España. (s. f.). Recuperado 28 de diciembre de 2024, de https://planderecuperacion.gob.es/noticias/que-es-inteligencia-artificial-ia-prtr

[11] ¿Qué es el machine learning y que usos tiene? (s. f.). REPSOL. Recuperado 28 de diciembre de 2024, de https://www.repsol.com/es/energia-futuro/tecnologia-innovacion/machinelearning/index.cshtml

[12] ¿Qué son los microservicios? | AWS. (s. f.). Amazon Web Services, Inc. Recuperado 28 de diciembre de 2024, de https://aws.amazon.com/es/microservices/

[13] Explicación sobre los contenedores: Concepto e importancia. (s. f.). Recuperado 30 de diciembre de 2024, de https://www.redhat.com/es/topics/containers

[14] Docker y microservicios—Blog de hiberus. (s. f.). Recuperado 15 de diciembre de 2024, de https://www.hiberus.com/crecemos-contigo/docker-y-microservicios/

[15] ¿Qué es Docker y cómo funciona? Ventajas de los contenedores Docker. (s. f.). Recuperado 30 de diciembre de 2024, de https://www.redhat.com/es/topics/containers/what-is-docker

[16] VM vs Containers. (s. f.). Comparativa Clouds. Recuperado 30 de diciembre de 2024, de https://comparacloud.com/servicios-clouds/precios-cloud/

[17] Admin-factoria. (2024, septiembre 9). Docker: Qué es y cómo funciona la contenerización de aplicaciones. Ausum Cloud: Servicios y Soluciones Cloud. Recuperado 15 de diciembre de 2024, de https://ausum.cloud/docker-que-es-como-funciona-la-contenerizacion-de-aplicaciones/

[18] ¿Qué es Node-RED y para qué sirve? | Actualidad de Grupo Sinelec. (2021, febrero 4). Recuperado 15 de diciembre de 2024, de https://blog.gruposinelec.com/actualidad/que-esnode-red-y-para-que-sirve/

[19] Running under Docker: Node-RED. (s. f.). Recuperado 21 de febrero de 2025, de https://nodered.org/docs/getting-started/docker

[20] Assistant, H. (s. f.). Home Assistant. Home Assistant. Recuperado 21 de febrero de 2025, de https://www.home-assistant.io/

[21] linuxserver/homeassistant—Docker Image | Docker Hub. (s. f.). Recuperado 21 de febrero de 2025, de https://hub.docker.com/r/linuxserver/homeassistant

[22] Docker Hub Container Image Library | App Containerization. (s. f.). Recuperado 15 de diciembre de 2024, de https://hub.docker.com

[23] MQTT Essentials—All Core Concepts Explained. (s. f.). Recuperado 19 de febrero de 2025, de https://www.hivemq.com/mqtt/

[24] ¿Qué es MQTT? Definición y detalles. (s. f.). Recuperado 15 de diciembre de 2024, de https://www.paessler.com/es/it-explained/mqtt

[25] Eclipse-mosquitto—Official Image | Docker Hub. (s. f.). Recuperado 19 de febrero de 2025, de https://hub.docker.com/_/eclipse-mosquitto

[26] Ancho de banda: Definición y detalles. (s. f.). Recuperado 20 de febrero de 2025, de https://www.paessler.com/es/it-explained/bandwidth

[27] TEKTELIC. (2023, octubre 23). LoRaWAN vs Zigbee for Your IoT Project | TEKTELIC Blog. TEKTELIC. https://tektelic.com/expertise/lorawan-vs-zigbee/

[28] fgarcia. (2018, abril 19). ⇨ Descubre qué es Zigbee y para qué se utiliza. efectoLED. https://www.efectoled.com/blog/es/que-es-zigbee/

[29] ¿Qué es Zigbee? La tecnología de red eléctrica inteligente más popular del mundo | Homey. (s. f.). Recuperado 15 de diciembre de 2024, de https://homey.app/es-es/wiki/que-es-zigbee/

[30] zzh Multiprotocol RF Stick (CC2652R1—External Antenna). (s. f.). Electrolama. Recuperado 30 de diciembre de 2024, de https://electrolama.com/products/zzh-multiprotocol-rf-stick

[31] Zhang, L. (2021, septiembre 18). SONOFF Zigbee 3.0 USB Dongle Plus-P. SONOFF Official. https://sonoff.tech/product/gateway-and-sensors/sonoff-zigbee-3-0-usb-dongle-plus-p/

[32] LAUNCHXL-CC1352P Evaluation board | TI.com. (s. f.). Recuperado 30 de diciembre de 2024, de https://www.ti.com/tool/LAUNCHXL-CC1352P

[33] SONOFF ZBDongle-E control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 21 de febrero de 2025, de https://www.zigbee2mqtt.io/devices/ZBDongle-E.html

[34] Zigbee2MQTT. Supported devices(s. f.). Recuperado 24 de febrero de 2025, de https://www.zigbee2mqtt.io/supported-devices/

[35] GY-2561 TSL2561 Light intensity module Sensor module Super intensity module—AliExpress 502. (s. f.). Recuperado 24 de febrero de 2025, de https://www.aliexpress.com/item/1005006047383759.html

[36] Tuya ZigBee Light Sensor Luminance Sensor ZigBee Beam Sensor Smart Home Automation App Control Tuya Light Illumination Detector AliExpress 44. (s. f.). Aliexpress. Recuperado 24 de febrero de 2025, de https://www.aliexpress.com/item/1005008259438794.html

[37] Arduino Light Sensor—TSL2561 and Experiments with Infrared and Visible Light. (2022, noviembre 28). Maker Portal. https://makersportal.com/blog/2018/4/19/arduino-light-sensortsl2561-and-experiments-with-infrared-and-visible-light

[38] MQ-2 MQ2 Smoke Gas LPG Butane Hydrogen Gas Sensor Detector Module For arduino—AliExpress 502. (s. f.). Recuperado 24 de febrero de 2025, de https://www.aliexpress.com/item/32328262269.html

[39] Aqara JT-BZ-01AQ/A control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 24 de febrero de 2025, de https://www.zigbee2mqtt.io/devices/JT-BZ-01AQ_A.html

[40] Llamas, L. (s. f.). Detector de gases con Arduino y la familia de sensores MQ. Luis Llamas. Recuperado 24 de febrero de 2025, de https://www.luisllamas.es/arduino-detector-gas-mq/

[41] Tuya ZG-204ZM control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 24 de febrero de 2025, de https://www.zigbee2mqtt.io/devices/ZG204ZM.html

[42] HC-SR501 Adjust IR Pyroelectric Infrared PIR Human Infrared Motion Sensor Detector Module for Arduino for Raspberry Pi + Case AliExpress 502. (s. f.). Aliexpress. Recuperado 19 de marzo de 2025, de https://www.aliexpress.com/item/1005007558216824.html

[43] Aqara WSDCGQ11LM control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 26 de marzo de 2025, de https://www.zigbee2mqtt.io/devices/WSDCGQ11LM.html

[44] Aqara WSDCGQ12LM control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 26 de marzo de 2025, de https://www.zigbee2mqtt.io/devices/WSDCGQ12LM.html

[45] Adafruit Industries. (2025). DHT11, DHT22 and AM2302 Sensors. Mouser Electronics. Recuperado el 26 de marzo de 2025, de https://www.mouser.com/datasheet/2/737/dht932870.pdf?srsltid=AfmBOorFtxj-tg-RMZh4AiPynWgyEky3G_j_MJVvKmuZxrg-HookpCHe

[46] Tuya RB-SRAIN01 control via MQTT | Zigbee2MQTT. (s. f.). Recuperado 26 de marzo de 2025, de https://www.zigbee2mqtt.io/devices/RBSRAIN01.html

[47] Arduino y el sensor de agua – Prometec. (s. f.). Recuperado 26 de marzo de 2025, de https://www.prometec.net/sensor-agua/

[48] AVATTO Tuya WiFi Zigbee Smart Light Switch Module,No Neutral Wire 2 Ways Control Mini DIY Breaker Work for Alexa, google home AliExpress 13. (s. f.). Recuperado 26 de marzo de 2025, de https://www.aliexpress.com/item/1005004823480465.html

[49] Peely Bot|smart Fingerbot Plus—Zigbee & Bluetooth-compatible, Alexa & Google Home Compatible. (s. f.). Aliexpress. Recuperado 26 de marzo de 2025, de https://www.aliexpress.com/item/1005005168070181.html

[50] Tuya Zigbee Smart IR Remote Control Universal Infrared Remote for Smart Home for AC TV DVD works with Alexa Google Home—AliExpress. (s. f.). Aliexpress. Recuperado 26 de marzo de 2025, de https://www.aliexpress.com/item/1005003878194474.html

[51] Enchufe inteligente Tuya WIFI EU 16A/20A Wifi/Zigbee, monitoreo de potencia, Control de hogar inteligente, compatible con Google Home, Alexa—AliExpress 44. (s. f.). aliexpress. Recuperado 26 de marzo de 2025, de https://es.aliexpress.com/item/1005007055724435.html

[52] ¿Qué es una red privada virtual o VPN? ¿Por qué debería usar una red privada virtual o VPN? | Microsoft Azure. (s. f.). Recuperado 30 de marzo de 2025, de https://azure.microsoft.com/eses/resources/cloud-computing-dictionary/what is-vpn

[53] Donenfeld, J. A. (s. f.). WireGuard: Fast, modern, secure VPN tunnel. Recuperado 30 de marzo de 2025, de https://www.wireguard.com/

[54] FMS-200—Sistema didáctico modular de ensamblaje flexible. (s. f.). Recuperado 27 de mayo de2025, de https://www.smctraining.com/es/webpage/indexpage/287

[55] SMC International Training. (s. f.). FMS-200: Catálogo de estaciones. Estación FMS-201 – Alimentación de la base [PDF]. SMC International Training.

[56] Introducción al estándar IEC 61131-3.pdf. (s. f.). infoPLC. Recuperado 27 de mayo de 2025, de https://drive.google.com/file/d/1XE6I2xJOfW1WQpoFzB247VSwxr6YlHft/

[57] Germany, B. A. G. & C. K., Hülshorstweg 20, 33415 Verl. (s. f.). TwinCAT 3 PLC. Beckhoff Automation. Recuperado 27 de mayo de 2025, de https://www.beckhoff.com/eses/support/training-offerings/twincat-3-plc/

[58] Grafana OSS | Leading observability tool for visualizations & dashboards. (s. f.). Grafana Labs. Recuperado 27 de mayo de 2025, de https://grafana.com/oss/grafana/

[59] Node-RED Dashboard 2.0. (s. f.). Recuperado 2 de febrero de 2025, de https://dashboard.flowfuse.com/
