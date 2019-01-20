
void driveForward()
{
  digitalWrite(PIN_DRIVE_LEFT_1, HIGH);
  digitalWrite(PIN_DRIVE_LEFT_2, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_1, HIGH);
  digitalWrite(PIN_DRIVE_RIGHT_2, LOW);
  analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_FORWARD_SPEED);
  analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_FORWARD_SPEED);
}

void driveLeft()
{
  digitalWrite(PIN_DRIVE_LEFT_1, HIGH);
  digitalWrite(PIN_DRIVE_LEFT_2, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_2, HIGH);
  analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_TURN_SPEED);
  analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_TURN_SPEED);
}

void driveRight()
{
  digitalWrite(PIN_DRIVE_LEFT_1, LOW);
  digitalWrite(PIN_DRIVE_LEFT_2, HIGH);
  digitalWrite(PIN_DRIVE_RIGHT_1, HIGH);
  digitalWrite(PIN_DRIVE_RIGHT_2, LOW);
  analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_TURN_SPEED);
  analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_TURN_SPEED);
}

void driveReverse()
{
  digitalWrite(PIN_DRIVE_LEFT_1, LOW);
  digitalWrite(PIN_DRIVE_LEFT_2, HIGH);
  digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_2, HIGH);
  analogWrite(PIN_DRIVE_LEFT_SPEED, DRIVE_REVERSE_SPEED);
  analogWrite(PIN_DRIVE_RIGHT_SPEED, DRIVE_REVERSE_SPEED);
}

void driveStop()
{
  digitalWrite(PIN_DRIVE_LEFT_1, LOW);
  digitalWrite(PIN_DRIVE_LEFT_2, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_1, LOW);
  digitalWrite(PIN_DRIVE_RIGHT_2, LOW);
}
