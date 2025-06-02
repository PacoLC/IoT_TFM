# 🏭 TwinCAT MQTT Client para Estación FMS201

Este proyecto implementa un cliente MQTT sobre TwinCAT 3 para comunicar una estación de automatización industrial (FMS201) con un dashboard remoto basado en Node-RED. El sistema permite tanto la **publicación periódica de datos** (entradas/salidas del sistema) como la **recepción de comandos en formato JSON**, que son interpretados y ejecutados por el PLC.

## 📦 Características principales

- 🔗 Conexión MQTT mediante `FB_IotMqttClient`.
- 📤 Publicación periódica de entradas y salidas a topics MQTT (`FMS201/E`, `FMS201/S`).
- 📥 Subscripción a comandos de control desde topic `FMS201/DashBoard`.
- 🔍 Lectura y parsing de payloads JSON mediante `FB_JsonSaxReader`.
- ⚙️ Asignación automática de valores a variables del sistema en función de claves JSON (`"RUN"`, `"REV"`, `"A0"`, etc.).
- 🔁 Modularizado en métodos reutilizables para publicación, parsing y asignación.

## 🧠 Arquitectura general

```text
[ Node-RED ] ⇄ MQTT ⇄ [ TwinCAT 3 PLC (Beckhoff) ]
                        ⇡          ⇣
              sPayloadPubE    sPayloadRcv
```

- `FMS201/E`: Publica las **entradas** del sistema (estados, sensores, etc.).
- `FMS201/S`: Publica las **salidas** actuales (actuadores activos).
- `FMS201/DashBoard`: Recibe mensajes JSON de control para actualizar el estado del sistema.

## ⚙️ Configuración

### Parámetros MQTT

```pascal
fbMqttClient.sHostName := '172.16.78.14';
fbMqttClient.nHostPort := 1883;
fbMqttClient.sTopicPrefix := '';
```

> Puedes cambiar `sHostName` para apuntar a tu broker MQTT (por ejemplo, `broker.hivemq.com` o un servidor local).

### Topics configurados

- `sTopicPubE`: `'FMS201/E'` → Publicación de entradas
- `sTopicPubS`: `'FMS201/S'` → Publicación de salidas
- `sTopicRcv`: `'FMS201/DashBoard'` → Subscripción para recibir comandos

## 🧾 Payload JSON esperado

El payload recibido debe ser un JSON plano con pares clave-valor. Ejemplo:

```json
{
  "SM": true,
  "RUN": true,
  "REV": false,
  "A1": true,
  "PV": 10
}
```

- Las claves como `"RUN"`, `"REV"`, `"A1"` representan actuadores específicos.
- `"SM"` habilita el modo manual del PLC.
- `"PV"` es un valor numérico entero (por ejemplo, unidades solicitadas).

## 🧩 Funciones principales

### ✅ mAssignBoolValue
Asigna valores booleanos a salidas del sistema en función de una clave.

### ✅ mAssignIntValue
Asigna valores enteros (como unidades) a variables internas del PLC.

### ✅ mParseJSON
Parsea manualmente el payload JSON recibido y realiza las asignaciones necesarias.

### ✅ mCreatePayloadInputs / mCreatePayloadOutputs
Generan los mensajes JSON que describen el estado actual del sistema (entradas/salidas).

## 🛠 Requisitos

- 🧠 TwinCAT 3 configurado y con licencia activada.
- ⚙️ Librerías: `TF6310 MQTT`, `Tc3_IoTBase`, `Tc3_JsonXml`, etc.
- 💡 Acceso a red con el broker MQTT.
- 🔧 Conocimiento básico en ST (Structured Text).

## 📚 Referencias

- [Beckhoff MQTT Library (TF6310)](https://www.beckhoff.com)
- [JSON SAX Reader/Writer for TwinCAT](https://infosys.beckhoff.com/)
- [Node-RED](https://nodered.org)
- [MQTT Specification](https://mqtt.org)

## 📝 Autor

Francisco Luque del Castillo  
Málaga, 2025  
Trabajo Fin de Máster – Universidad de Málaga

## 📝 Tutor y Cotutor

Tutor: 
Cotutor:  
