#define LED_BUILTIN 13
#define TEMPS 1000

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
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

