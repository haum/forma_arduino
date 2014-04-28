#define LED 13
#define TEMPS 500

void setup() {
	pinMode(LED, OUTPUT);
}

void loop() {
	blink(TEMPS);
}

void blink(int temps) {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(temps);
	digitalWrite(LED_BUILTIN, LOW);
	delay(temps);
}

