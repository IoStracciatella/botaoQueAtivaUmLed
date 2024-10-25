#define LED_PIN 8
#define BUTTON_PIN 7

byte ultimoEstadoDoBotao;
byte estadoLed = LOW;

unsigned long ultimaVezQueOEstadoDoBotaoMudou = millis();
unsigned long tempoDeDebounce = 50; // millis

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    ultimoEstadoDoBotao = digitalRead(BUTTON_PIN);
}

void loop() {
    if (millis() - ultimaVezQueOEstadoDoBotaoMudou >= tempoDeDebounce) {
        byte estadoBotao = digitalRead(BUTTON_PIN);
        if (estadoBotao != ultimoEstadoDoBotao) {
            ultimaVezQueOEstadoDoBotaoMudou = millis();
            ultimoEstadoDoBotao = estadoBotao;
            if (estadoBotao == LOW) { // released
                if (estadoLed == HIGH) {
                    estadoLed = LOW;
                } else {
                    estadoLed = HIGH;
                }
                digitalWrite(LED_PIN, estadoLed);
            }
        }
    }
}