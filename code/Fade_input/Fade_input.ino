/*
 Fade

 variation de l'intensitée d'une led sur la pin  9
 avec la fonction analogWrite()
 variation de l'intensité max sur AO avec value = analogRead();
 variation de la vitesse  sur A1

 This example code is in the public domain.
 */

int led = 9;           // pin de la LED, doit etre une pin qui permet le pwm
int brightness = 0;    // intensitée de la LED
int fadeAmount = 1;    // graduation de changement

// the setup routine runs once when you press reset:
void setup()
{
	// declare pin 9 to be an output:
	pinMode(led, OUTPUT);
	Serial.begin(115200);
}

void loop()
{
	int max_brightness = map (analogRead(A0), 0, 1024, 2, 255);
	// on place la valeur d'intensitée
	analogWrite(led, brightness);
	Serial.println(max_brightness);
	// on change la valeur pour la prochaine foi
	brightness = brightness + fadeAmount;

	// si on est a un mini ou un max on change le signe de la graduation
	if (brightness == 0 || brightness >= max_brightness)
	{
		fadeAmount = -fadeAmount ;
	}
	// petite pose
	delay(6*255/max_brightness);
}

