#include <ESP8266WiFi.h>
#include <DHT.h>

#define SSID ${{ secrets.SSID }}
#define PSW ${{ secrets.WIFIPSW }}
#define DHTPIN 1
#define MODEL DHT22

DHT dht(DHTPIN, MODEL);

int chk;
float hum;  //Variabile in cui verrà inserita la % di umidità
float temp; //Variabile in cui verrà inserita la temperatura

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PSW);

  //Serial.begin(115200);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  /*Serial.println("");
    Serial.print("Connesso a: ");
    Serial.println("ssid");
    Serial.print("Indirizzo IP: ");
    Serial.println(WiFi.localIP());
    Serial.println("##########################");*/
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  //Stampa umidità e temperatura tramite monitor seriale
  Serial.print("Umidità: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
}
