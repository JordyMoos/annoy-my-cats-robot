
void driveForward() {
    digitalWrite(PIN_DRIVE_LEFT_1, HIGH);
    digitalWrite(PIN_DRIVE_LEFT_2, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_1, HIGH);
    digitalWrite(PIN_DRIVE_RIGHT_2, LOW);
    analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_FORWARD_SPEED);
    analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_FORWARD_SPEED);

    driveStatus = DRIVING_FORWARD;
}

void driveLeft() {
    digitalWrite(PIN_DRIVE_LEFT_1, HIGH);
    digitalWrite(PIN_DRIVE_LEFT_2, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_2, HIGH);
    analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_TURN_SPEED);
    analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_TURN_SPEED);

    driveStatus = DRIVING_LEFT;
}

void driveRight() {
    digitalWrite(PIN_DRIVE_LEFT_1, LOW);
    digitalWrite(PIN_DRIVE_LEFT_2, HIGH);
    digitalWrite(PIN_DRIVE_RIGHT_1, HIGH);
    digitalWrite(PIN_DRIVE_RIGHT_2, LOW);
    analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_TURN_SPEED);
    analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_TURN_SPEED);

    driveStatus = DRIVING_RIGHT;
}

void driveReverse() {
    digitalWrite(PIN_DRIVE_LEFT_1, LOW);
    digitalWrite(PIN_DRIVE_LEFT_2, HIGH);
    digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_2, HIGH);
    analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_REVERSE_SPEED);
    analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_REVERSE_SPEED);

    driveStatus = DRIVING_REVERSE;
}

void driveStop() {
    digitalWrite(PIN_DRIVE_LEFT_1, LOW);
    digitalWrite(PIN_DRIVE_LEFT_2, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
    digitalWrite(PIN_DRIVE_RIGHT_2, LOW);

    driveStatus = DRIVING_STOPPED;
}
