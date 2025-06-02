# 🧱 Sistema Domótico IoT con Docker Compose

Este proyecto configura un entorno completo de automatización del hogar e integración IoT utilizando contenedores Docker. Incluye los siguientes servicios principales:

- **Home Assistant**: Plataforma de automatización del hogar.
- **Node-RED**: Entorno de programación visual para lógica y flujos.
- **Mosquitto**: Broker MQTT ligero para comunicación entre dispositivos.
- **Zigbee2MQTT**: Puente entre dispositivos Zigbee y MQTT para integración directa con Home Assistant y Node-RED.

## 🚀 Servicios incluidos

### 🏠 Home Assistant
- Imagen: `ghcr.io/home-assistant/home-assistant:latest`
- Accesible en: `http://localhost:8123`
- Monta configuración en `../datafiles/ha/config`
- Modo privilegiado: `true` (para acceso completo a hardware)
- Reinicio automático: `unless-stopped`

### 🔄 Node-RED
- Imagen: `nodered/node-red:latest`
- Accesible en: `http://localhost:1880`
- Volumen de datos: `../datafiles/node-red-data`
- Conectado a red personalizada `node-red-net`

### 📡 Mosquitto (Broker MQTT)
- Imagen: `eclipse-mosquitto:latest`
- Puertos: `1883` (MQTT), `9001` (WebSocket)
- Configuración persistente en: `../datafiles/mosquitto/config`, `/data`, `/log`
- Reinicio automático

### 🧿 Zigbee2MQTT
- Imagen: `koenkk/zigbee2mqtt`
- Puerto web: `http://localhost:8080`
- Volumen de datos: `../datafiles/zigbee2mqtt/data`
- Usa dispositivo `/dev/ttyUSB0` como adaptador Zigbee (ajustar si es necesario)
- Compatible con ConBee, Sonoff, CC2531, etc.

## 🗂 Estructura de carpetas esperada

```
.
├── docker-compose.yml
└── ../datafiles
    ├── ha
    │   └── config/
    ├── node-red-data/
    ├── mosquitto
    │   ├── config/
    │   ├── data/
    │   └── log/
    └── zigbee2mqtt
        └── data/
```

## ⚙️ Uso

### Iniciar todos los servicios

```bash
docker-compose up -d
```

### Parar servicios

```bash
docker-compose down
```

### Ver logs de un servicio (ej. Home Assistant)

```bash
docker logs -f homeassistant
```

## 📌 Requisitos

- Docker y Docker Compose instalados
- Acceso al dispositivo Zigbee en `/dev/ttyUSB0`
- Crear estructura de carpetas si no existe (`../datafiles/...`)

## 🌐 Accesos rápidos

- Home Assistant → http://localhost:8123
- Node-RED → http://localhost:1880
- Zigbee2MQTT Frontend → http://localhost:8080
- MQTT (Mosquitto) → puerto 1883

## 📚 Referencias

- [Home Assistant Docs](https://www.home-assistant.io/docs/)
- [Node-RED](https://nodered.org/docs/)
- [Mosquitto MQTT](https://mosquitto.org/)
- [Zigbee2MQTT Docs](https://www.zigbee2mqtt.io/)

## 📝 Autor

Francisco Luque del Castillo  
Trabajo Fin de Máster – Universidad de Málaga  
2025

## 📝 Tutor y Cotutor

Tutor: 
Cotutor:  
