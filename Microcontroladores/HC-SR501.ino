#include <ESP8266WiFi.h>
#include <PubSubClient.h> //Librería para la conexion MQTT
#include "DHTesp.h" //Librería del sensor DHT para las temperatura, humedada, presion
#include <ArduinoJson.h> // Librería necesaria para la serialización/deserialización de msgs en JSON
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

//------------------------------------------//
//---------------CONSTANTES-----------------//
//------------------------------------------//


// Línea necesaria para leer el voltaje Vcc observado en la entrada de alimentación
//  ADC_MODE(ADC_VCC);
// Variable manejadora del sensor DHT
DHTesp dht;
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
 

const int PIR_PIN = 13;   //PIN de entrada de datos del sensor PIR
const int PIN_DHT11 = 16; //PIN de entrada de datos del sensor DHT11


//------------------------------------------//
//---------------VARIABLES -----------------//
//------------------------------------------//

//-----------SENSOR TSL2561------------//
float lux;

//-----------SENSOR DHT11-------------//
float humidity;
float temperature;

//---------------WIFI-----------------//
const char* ssid = "silyconroom";
const char* password = "silyconhouse2019";
const char* mqtt_server = "192.168.1.163";
String IP;
float rssi;
float vcc;

//--------ENVIAR DATOS AL ENCENDER-----//
bool PrimeraVez = true;

//------------SENSOR PIR---------------//
int Sensor_Pir;


//-------------FRECUENCIAS-------------//
//Variable que indica la frecuencia con la que se actualizan los datos
int Temp = 60000; //ms

//------------JSON A PUBLICAR----------//
// String de hasta 512 caracteres en el que almacenaremos la estructura JSON con los datos
// (sensores, Vcc, uptime)... a publicar
char sdatos[512];

char datos_prio[256];
// String de en el que almacenaremos la estructura JSON con el estado de la conexión para pub
char sconexion[256];


//----------------MQTT-----------------//
// Creamos una instancia de cliente MQTT de tipo WiFi asociada a client
WiFiClient espClient;
PubSubClient client(espClient);
// Hora (en ms) en la que publicamos el último msg
unsigned long lastMsg = 0;
unsigned long now = 0;
const char* mqqt_data = "casa/escaleras/data";
String mqqt_data_prio = "casa/escaleras/SensorPrioritarios";
const char* mqqt_data_config = "casa/escaleras/config";



//-----------------------------------------------------------------------FUNCIONES-------------------------------------------------------------------------//

//------------------------------------------//
//----------- FUNCIONES WIFI ---------------//
//------------------------------------------//
void setup_wifi();
void reconnect();


//------------------------------------------//
//---------------- MQTT --------------------//
//------------------------------------------//
void callback(char* topic, byte* payload, unsigned int length); //CALLBACK
void Send_data();

//------------------------------------------//
//------------ TOMA DE DATOS ---------------//
//------------------------------------------//
void dht11();
void esp_info();
void Pir_send_info();
void TSL_Sensor();

//------------------------------------------//
//---------------- CONTROL -----------------//
//------------------------------------------//
void Pir_control_state();

//------------------------------------------//
//-------------------SETUP------------------//
//------------------------------------------//
void setup()
{
  pinMode(PIR_PIN, INPUT);
  Serial.begin(115200);
  setup_wifi();
  dht.setup(PIN_DHT11, DHTesp::DHT11);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  client.setBufferSize(512);      // Establecemos el tamaño del buffer para el manejo de msgs MQTT a 512 (msgs largos)
  Serial.println("Light Sensor Test"); 
  Serial.println("");
 
  /* Initialise the sensor */
  if(!tsl.begin())
  {
    Serial.print("No TSL2561 detected");
  }
 
  tsl.enableAutoRange(true);
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);
  Serial.println();

}

//------------------------------------------//
//--------------------LOOP------------------//
//------------------------------------------//

void loop()
{
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  if (now >= 4100000000)
  {
    Serial.println("RESET");
    ESP.restart();
  }

  Pir_control_state();
  //Serial.println("**");
  now = millis();

  if (now - lastMsg > Temp && PrimeraVez )
  {
    //Serial.println("ENVIO DATOS");
    PrimeraVez = false;
    TSL_Sensor();
    esp_info();
    //dht11();
    Send_data();
    lastMsg = now;
  }
}

//----------------------------------------------------------------------------DECLARACION DE FUNCIONES-------------------------------------------------------------------------//

///////////////////////////////////////////
//----------------TSL2561----------------//
///////////////////////////////////////////
/**
   Toma los datos del sensor TSL2561
*/
void TSL_Sensor()
{
  /* Get a new sensor event */ 
  sensors_event_t event;
  tsl.getEvent(&event);
 
  /* Display the results (light is measured in lux) */
  if (event.light)
  {
    lux = event.light;
    //Serial.print(event.light); 
    //Serial.println(" lux");
  }
  else
  {
    lux = 0;
    //Serial.println("Sensor overload");
  }
}

///////////////////////////////////////////
//---------------ESP INFO----------------//
///////////////////////////////////////////
/**
   Lee la información de la esp
*/
void esp_info()
{
  // Leemos el voltaje Vcc observado en la entrada de alimentación y lo pasamos a V
  vcc = ESP.getVcc() / 1000.0;
  // Obtenemos el RSSI de la conexión WiFi
  rssi = WiFi.RSSI();
  // Obtenemos la IP del router al que estamos conectados. Esa función me devuelve un
  // valor de tipo IPAddress -> lo pasamos a string
  IP = WiFi.localIP().toString();
}

///////////////////////////////////////////
//-----------------DHT11-----------------//
///////////////////////////////////////////
/**
   Lee los datos del sensor dht11
*/
void dht11()
{
  // Leemos los datos del sensor
  delay(dht.getMinimumSamplingPeriod());
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
}

///////////////////////////////////////////
//---------------SEND PIR----------------//
///////////////////////////////////////////
/**
   Envio de los datos del sensor PR cuando se detecte un cambio
*/
void Pir_send_info()
{
  StaticJsonDocument<512> datos;
  String channel_data = mqqt_data_prio + "/PIR";
  // Creamos el objeto anidado dht11, perteneciente a la estructura JSON datos
  JsonObject pir = datos.createNestedObject("PIR");
  pir["PIR"] = Sensor_Pir;
  JsonObject debug = datos.createNestedObject("DEBUG");
  //El campo Uptime es el número de ms desde que se inició la placa
  debug["Uptime"] = now;
  serializeJson(datos, datos_prio);
  client.publish(channel_data.c_str(), datos_prio);
}
/**
   Controla la informacion del sensor y llama a la funcion de enviar los datos cuando cambia de estado
*/
void Pir_control_state()
{
  Sensor_Pir = digitalRead(PIR_PIN);
  if ( 1 == Sensor_Pir )
  {
    //Serial.print("PIR: ");
    //Serial.println(Sensor_Pir);
    Pir_send_info();
  }
}

///////////////////////////////////////////
//---------------SEND DATA---------------//
///////////////////////////////////////////
/**
   Envia los datos de los sensores NO prioritarios como el DHT11, WIFI, etc.
*/
void Send_data()
{
  // Formateamos los datos a publicar en la estructura JSON datos
  StaticJsonDocument<512> datos;

  JsonObject debug = datos.createNestedObject("DEBUG");
  //El campo Uptime es el número de ms desde que se inició la placa
  debug["Uptime"] = now;
  debug["Vcc"] = vcc;

  // Creamos el objeto anidado dht11, perteneciente a la estructura JSON datos
  JsonObject dht11 = datos.createNestedObject("DHT11");
  dht11["Temperatura"] = temperature;
  dht11["Humedad"] = humidity;

  // Creamos el objeto anidado TSL2561, perteneciente a la estructura JSON datos
  JsonObject TSL = datos.createNestedObject("TSL2561");
  TSL["Lux"] = lux;
  
  // Creamos el objeto anidado wifi, perteneciente a la estructura JSON datos
  JsonObject wifi = datos.createNestedObject("WiFi");
  wifi["SSId"] = ssid;
  wifi["IP"] = IP;
  wifi["RSSI"] = rssi;

  // Serializamos la estructura JSON datos en el string sdatos y lo publicamos
  serializeJson(datos, sdatos);
  client.publish(mqqt_data, sdatos);
}

///////////////////////////////////////////
//--------------WIFI SETUP---------------//
///////////////////////////////////////////
/**
   Configuración wifi
*/
void setup_wifi()
{
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

///////////////////////////////////////////
//---------------RECONECT----------------//
///////////////////////////////////////////
/**
   Reconecta en caso de desconexion
*/
void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // En este caso, el clientId no es aleatorio, pero sigue siendo único porque contiene
    // el ChipId de nuestra placa. GetChipId devuelve un entero -> lo pasamos a string
    String clientId = "ESP8266Client-";
    clientId += String(ESP.getChipId()) ;

    // Formateamos el msg LWT en la estructura JSON conexion, que enviaremos al broker
    // al conectarnos (en la función conect)
    StaticJsonDocument<256> conexion;
    // Creamos la clave "online" y le asociamos el valor false. De esta forma, al ser un msg
    // LWT,cuando nos desconectemos abruptamente, se informará a los clientes que estén
    // suscritos al topic conexión de que el dispositivo no está conectado
    conexion["online"] = false;
    // Serializamos la estructura JSON conexion en el string sconexion y ya esta listo
    // para ser publicado (se publicará al llamar a connect())
    serializeJson(conexion, sconexion);

    // Intentamos conectarnos. Además del clientId, user y pass, le pasamos:
    // - el topic LWT: el msg LWT se enviará a los clientes que estén suscritos a este topic
    // - QoS: 2
    // - retain flag: true, para que este msg sustituya al msg retenido cuando se pierda la conex
    // - El msg LWT, que es el JSON {"online": false}
    if (client.connect(clientId.c_str()))//,null,null,"infind/GRUPO8/conexion",2,true,sconexion))
    {
      // Construimos ahora el msg retenido, que es el mismo que el LWT pero con online=true
      conexion["online"] = true;
      // Lo serializamos en sconexion
      serializeJson(conexion, sconexion);
      // Y lo publicamos en el topic /conexion con el retain flag puesto a true
      client.publish("infind/GRUPO8/conexion", sconexion, true);

      // Informamos por consola que nos hemos conectado
      Serial.println("connected");
      //Nos suscribimos al topic para obtener las configuraciones necesarias
      client.subscribe("infind/GRUPO8/config");

    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
///////////////////////////////////////////
//--------------CALL BACK----------------//
///////////////////////////////////////////
/**
   CALLBACK recive datos del servidos para cambir la configuracion
*/
void callback(char* topic, byte* payload, unsigned int length)
{
  // Reservo un espacio en memoria de longitud length+1 para copiar el msg recibido
  char *mensaje = (char *)malloc(length + 1);
  // Copio el msg recibido (payload) en el espacio reservado (mensaje)
  strncpy(mensaje, (char*)payload, length);

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  // Mostramos el payload recibido caracter a caracter
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Comprobamos que el msg se ha recibido por el topic infind/GRUPO8/config

  if (strcmp(topic, mqqt_data_config) == 0)
  {
    // Creamos la estructura JSON root en la que deserializaremos el msg
    StaticJsonDocument<512> root;
    // Deserializamos el mensaje en root. Además, se guarda si ha habido un error
    DeserializationError error = deserializeJson(root, mensaje);

    // Si hubo un error, informo por pantalla de cuál es
    if (error)
    {
      Serial.print("Error, deserializeJson() failed: ");
      Serial.println(error.c_str());
    }
    // Si no hubo error,
    else
    {
      //...................................................//
      //.............FRECUENCIA ENVIO DE DATOS.............//
      //...................................................//
      //comprobamos si el objeto son los datos de la frecuencia de actualizacion
      // Compruebo si la estruct JSON root, contiene la clave frecuencia que estamos buscando

      if (root.containsKey("frecuencia"))
      {
        // Comprobamos que el valor de frecuencia está dentro del rango para un correcto funcionamiento
        if (root["frecuencia"] >= 2)
        {
          // Guardamos en la vble Temp el valor correspondiente a la clave "frecuencia"
          Temp = root["frecuencia"];
          Temp = Temp * 1000;
          // Indicamos por pantalla que hemos sido capaces de extraer el valor frecuencia del msg JSON
          Serial.print("Mensaje OK, frecuencia de envio de datos = ");
          Serial.println(Temp);
        }
        else
        {
          Serial.println("El valor de \"frecuencia de envio de datos\" recibido es un numero negativo");
        }

      }
      // Si no existe ninguna clave en root que se llame frecuencia, lo indicamos por consola
      else
      {
        Serial.print("Error : ");
        Serial.println("\"frecuencia de envio de datos\" key not found in JSON");
      }
    }

  }

}
