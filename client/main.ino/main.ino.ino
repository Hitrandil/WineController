#include <DHTesp.h>
#include <ESP8266WiFi.h>

/*TODO: costanti da file esterni*/

#define WIFI_SSID "Vodafone- Minelli Valera"
#define WIFI_PSW "C.90h@q36GDln*08svrn_"

#define DHT_PIN 16
#define DHT_MODEL DHTesp::DHT22


DHTesp dht;
void setup() {
  /*------ SET DEBUG ------*/
  Serial.begin(115200);
  /*-----------------------*/
  int count = 0;
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PSW);
  while (WiFi.status() != WL_CONNECTED && count<=60 ) {
    /*attendo per due minuti la connessione, se non si connette proseguo ugualmente*/
    delay(2000);
    count++;
    Serial.print(".");
  }
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED){
      Serial.print("Connesso! Indirizzo ip: ");
      Serial.print(WiFi.localIP());
      Serial.println("");
  }else{
    Serial.print("ERRORE DI CONNESSIONE");
  }
 
  dht.setup(DHT_PIN, DHT_MODEL); //DIGITAL 0 = GPIO 16
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  /*------ START DEBUG ------*/
  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println();
  delay(2000);
}
