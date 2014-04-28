#define LED 13
#define TEMPS 1000

void setup() {
	pinMode(LED, OUTPUT);
}

void loop() {
	blink();
}

void blink() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(TEMPS);
	digitalWrite(LED_BUILTIN, LOW);
	delay(TEMPS);
}

