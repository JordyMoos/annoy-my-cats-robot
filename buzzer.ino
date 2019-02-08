
void updateBuzzer() {
    if (isTooting) {
      buzzOn();
    }
    else {
        switch (driveStatus) {
            case DRIVING_REVERSE:
                if ((millis() / BUZZER_REVERSE_TIME) % 2)
                    buzzOn();
                else
                    buzzOff();
                break;
    
            default:
                buzzOff();
        }
    }
}

void buzzOff() {
    digitalWrite(PIN_BUZZER, HIGH);
}

void buzzOn() {
    digitalWrite(PIN_BUZZER, LOW);
}

