
#include <DHT.h>

//dht
#define DHTPIN 4
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
//dht

int smoke = A5;

void setup() {

  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps

  Serial.println(F("DHTxx test!"));
  dht.begin();
  
  pinMode(smoke, INPUT);
  Serial.begin(9600);
}

void loop() {
    delay(2000);

  int val;
      Serial.print("sound value: ");
      val=analogRead(A1);   //connect mic sensor to Analog 0
      Serial.print(val,DEC);//print the sound value to serial
  
//dht
  // Wait a few seconds between measurements.

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("  Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F "));
//dht
  
  int analogSensor = analogRead(smoke);

  Serial.print("  Gas value: ");
  Serial.println(analogSensor);
  
}
