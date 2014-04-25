#define TEMPS 1000

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(TEMPS);
	digitalWrite(LED_BUILTIN, LOW);
	delay(TEMPS);
}
