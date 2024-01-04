#include <Wire.h>
#include <TEA5767N.h>
#include <LiquidCrystal.h>
#include <math.h>

// Analog pin for potentiometer (tuning knob)
#define KNOB_PIN A0

// Digital pins for LCD
#define Vo 6
#define Rs 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// Initiate LCD and RADIO objects
LiquidCrystal LCD(Rs, E, D4, D5, D6, D7);
TEA5767N RADIO = TEA5767N(); // Using standard I2C pins A4 and A5

// Global vars
const int ANALOG_INPUT_RANGE = 1024;
const float MIN_FREQ = 87.5;
const float MAX_FREQ = 108.0;
const int ADDRESS = 0;
const int POT_TOLERANCE = 3;
const int CONTRAST = 75;
int current_reading;

void adjustFrequency(float freq, int oldFreq) {
    current_reading = oldFreq;

    Serial.print("Setting to Frequency: ");
    Serial.print(freq);
    Serial.println(" MHz");

    RADIO.selectFrequency(freq);
}

float convertAnalogReadToFreq(int analogValue) {
    // Analog value range is 0 - 1023
    // TEA5767 frequency range is 87.5 - 108 MHz

    const float increment = ANALOG_INPUT_RANGE / (MAX_FREQ - MIN_FREQ); // equals roughly 50
    float calculatedFrequency = (analogValue / increment) + MIN_FREQ;

    // Round to tenths place
    calculatedFrequency = calculatedFrequency * 10 + 0.5;
    calculatedFrequency = floor(calculatedFrequency);
    calculatedFrequency = calculatedFrequency / 10;

    return calculatedFrequency;
}

void printToLCD(float freq) {
    LCD.setCursor(0, 0);
    LCD.print(freq);
    LCD.setCursor(5, 0);
    LCD.print(" MHz");
}

void setup() {
    // Initialize serial
    Serial.begin(9600);

    // Initialize LCD
    analogWrite(Vo, CONTRAST);
    LCD.begin(16, 2); // width, Height

    current_reading = analogRead(KNOB_PIN); // initial reading

    float newFrequency = convertAnalogReadToFreq(current_reading);
    adjustFrequency(newFrequency, current_reading);
    printToLCD(newFrequency);
}

void loop() {
    int tuningValue = analogRead(KNOB_PIN);

    // Re-tune the radio only if the knob has been turned
    if((tuningValue >= current_reading + POT_TOLERANCE) || (tuningValue <= current_reading - POT_TOLERANCE)) {
        float newFrequency = convertAnalogReadToFreq(tuningValue);
        adjustFrequency(newFrequency, tuningValue);
        printToLCD(newFrequency);
    }
}