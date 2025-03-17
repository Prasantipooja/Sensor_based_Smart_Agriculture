#define SOIL_MOISTURE_SENSOR A0  // Soil moisture sensor connected to A0
#define RELAY_PIN 7              // Relay module connected to D7
#define THRESHOLD 400            // Moisture threshold (adjust as needed)

void setup() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);  // Ensure pump is OFF at the start
    Serial.begin(9600);             // Start serial communication
}

void loop() {
    int moistureValue = analogRead(SOIL_MOISTURE_SENSOR); // Read soil moisture
    Serial.print("Soil Moisture Level: ");
    Serial.println(moistureValue);

    if (moistureValue > THRESHOLD) {  // If soil is dry
        Serial.println("Soil is dry! Pump ON.");
        digitalWrite(RELAY_PIN, LOW); // Turn ON the water pump
    } else {  // If soil is moist
        Serial.println("Soil is moist. Pump OFF.");
        digitalWrite(RELAY_PIN, HIGH); // Turn OFF the water pump
    }

    delay(5000); // Wait 5 seconds before checking again
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
