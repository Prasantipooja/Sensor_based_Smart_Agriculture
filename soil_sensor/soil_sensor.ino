#include <LiquidCrystal_I2C.h>  // Include LCD library

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address (adjust if necessary)
int soil = 0;  // Declare soil moisture variable
int k = 0;  // Dry count

void setup() {
    lcd.init();
    lcd.backlight();
    pinMode(A0, INPUT);  // Set A0 as input for soil sensor
    Serial.begin(9600);  // Initialize Serial for debugging
}

void loop() {
    soil = digitalRead(A0); // Read soil sensor value

    lcd.clear(); // Clear LCD before updating

    if (soil == 1) {
        lcd.setCursor(0, 0);
        lcd.print("LAND IS WET");  // Display "LAND IS WET"
    } else {
        lcd.setCursor(0, 0);
        lcd.print("LAND IS DRY");  // Display "LAND IS DRY"
        k++; // Increment dry count

        if (k <= 2) {
            sendSMS("+1234567890", "LAND IS DRY");  // Replace with actual number
            delay(750); // Delay for 750ms
        }
    }

    delay(2000); // Wait before next reading
}

// Function to send SMS (Replace with actual GSM module function)
void sendSMS(const char* number, const char* message) {
    Serial.print("Sending SMS to ");
    Serial.print(number);
    Serial.print(": ");
    Serial.println(message);
}