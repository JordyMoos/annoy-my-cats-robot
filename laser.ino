
/*
  Laser
*/

void setLaser(bool newState)
{
  laserState = newState;
  digitalWrite(PIN_LASER, newState);
}

void toggleLaser()
{
  laserState = ! laserState;
  digitalWrite(PIN_LASER, laserState);
}

/*
 Horizontal Motor
*/

void setLaserCenter()
{
  laserHorizontalState = LASER_HORIZONTAL_CENTERED;
  setLaserHorizontalLocation(LASER_HORIZONTAL_CENTER_LOCATION);
}

void startLaserAnimation()
{
  laserHorizontalState = LASER_HORIZONTAL_ANIMATING_LEFT;
}

void setLaserHorizontalLocation(int location)
{
  laserHorizontalLocation = location;
  laserMotorHorizontal.write(location);
}

void updateLaserAnimation()
{
  switch (laserHorizontalState)
  {
    case LASER_HORIZONTAL_CENTERED:
    break;

    case LASER_HORIZONTAL_ANIMATING_LEFT:
    {
      int newLocation = laserHorizontalLocation - LASER_HORIZONTAL_STEP_SIZE;
      if (newLocation <= LASER_HORIZONTAL_ANIMATE_MIN_LOCATION)
      {
        laserHorizontalState = LASER_HORIZONTAL_ANIMATING_RIGHT;
        setLaserHorizontalLocation(LASER_HORIZONTAL_ANIMATE_MIN_LOCATION);
      }
      else
      {
        setLaserHorizontalLocation(newLocation);
      }
    }
    break;

    case LASER_HORIZONTAL_ANIMATING_RIGHT:
    {
      int newLocation = laserHorizontalLocation + LASER_HORIZONTAL_STEP_SIZE;
      if (newLocation >= LASER_HORIZONTAL_ANIMATE_MAX_LOCATION)
      {
        laserHorizontalState = LASER_HORIZONTAL_ANIMATING_LEFT;
        setLaserHorizontalLocation(LASER_HORIZONTAL_ANIMATE_MAX_LOCATION);
      }
      else
      {
        setLaserHorizontalLocation(newLocation);
      }
    }
    break;
  }
}

/*
 Vertical Motor
*/

void laserTargetGround()
{
  laserTarget(LASER_MOTOR_GROUND_LOCATION);
}

void laserTargetGroundFar()
{
  laserTarget(LASER_MOTOR_GROUND_FAR_LOCATION);
}

void laserTargetCeiling()
{
  laserTarget(LASER_MOTOR_CEILING_LOCATION);
}

void laserTarget(int location)
{
  laserMotorVertical.write(location);
}

