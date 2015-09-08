#include <Adafruit_MCP4725.h>

// LEVER driver for implementation of REVEL and TeslaTouch papers by Disney Research
// for teensy 3.1
// Digital pin 4 sends hi-freq PWM (altered to send at 375kHz) to a boost converter circuit
// Analog pin 14 (it's a real DAC on the teensy 3.1) sends variable-freq sine wave to a hi-voltage transistor circuit
// that modulates the boosted supply voltage
// Pot on pin A7 sets the signal frequency
// SDA on pin A4
// SCL on pin A5
// OLED_RESET on digital pin 5

// poll pot pin to see what freq should be
// map 0-1023 analog in to 0.0125 (about 37.5 Hz) to 0.4 (about 1000Hz), add phase
// update OLED to show approx freq and bars representing texture
// 1000hz maps to a full bar every other row (ie offset 1)
// 30 hz maps to 64 on bars, 64 off bars (ie offset 64)

// TODO: implement goal-seeking feedback to keep constant current despite changing impedances
// TODO: figure out where in teh circuit the current-sensing occurs (pretty sure we're measuring voltage drop across precision resistor?)
// TODO: figure out how an RF interface might be used, maybe RFduino serial link or BlueSmiRF?

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 5
Adafruit_SSD1306 display(OLED_RESET);

#define pot 21
#define pwmOut 4
float minFreq = 0.0125*1000.0;
float maxFreq = 0.4*1000.0;

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

float phase = 0.0;
float twopi = 3.14159 * 2;
float phaseOffset = 0.05;
int tempread = 0;
int count = 0;

void setup() {
  // 0 - 4095 pwm values if res set to 12-bit
  analogWriteResolution(12);
  analogWriteFrequency(pwmOut, 375000);
  pinMode(pwmOut, OUTPUT);
  pinMode(pot, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.display();

}

void loop() {
  display.clearDisplay();
  tempread = analogRead(pot);
  phaseOffset = (4*phaseOffset + constrain(map(analogRead(pot), 0, 1023, minFreq, maxFreq), minFreq, maxFreq))/5;
  // duty cycle 75%
  analogWrite(pwmOut, int(4096 * 0.75));
  float sineVal = sin(phase) * 2000.0 + 2050.0;
  analogWrite(A14, (int)sineVal);
  //  phase = phase + 0.025;
  phase = phase + (phaseOffset/1000.0);
  //  phase = phase + 0.2; // about 600Hz
  //  phase = phase + 0.05; // about 150Hz
  //  phase = phase + 0.025; // about 75Hz
  if (phase >= twopi) phase = 0;
  count++;
  if(count%3000==0){
    updateDisplay();
  }
  if(count>100000){
    count = 0;
  }

}