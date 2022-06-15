//***********************************************Defines***********************************************
#define pin_B3 2
#define pin_B2 3
#define pin_B1 4
#define pin_B0 5
#define pin_SW1 18
#define pin_SW2 19

#define pi 3.14159265
#define Diameter 20
//***********************************************Typedefs***********************************************
typedef enum POWER
{
  OFF,
  ON
}pow;
typedef enum ANGLES
{
  First,
  Second,
  Third,
  Fourth
}angl;
typedef enum SENSE
{
  CLOCKWISE,
  ANTICLOCKWISE
}ses;

//Variables
int move = CLOCKWISE;
int Quads[] = (OFF,OFF,OFF,OFF);
int cicle = 0;
double distance;
//***********************************************Functions***********************************************
void change_sense()
{
  move = !move;
  cicle++;
}

//B3
void state_0_15()
{
  Quads[First]++;
}
void state_8_7()
{
  Quads[Second]++;
}
//B2
void state_12_11()
{
  Quads[Third]++;
}
void state_4_3()
{
  Quads[Fourth]++;
}

//***********************************************Functions Arduino***********************************************
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_B3, INPUT_PULLUP);
  pinMode(pin_B2, INPUT_PULLUP);
  pinMode(pin_B1, INPUT_PULLUP);
  pinMode(pin_B0, INPUT_PULLUP);
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin_B3), state_8_7, RISING);
  attachInterrupt(digitalPinToInterrupt(pin_B3), state_0_15, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_B2), state_4_3, RISING);
  attachInterrupt(digitalPinToInterrupt(pino_B2), state_12_11, FALLING);
  
  
  attachInterrupt(digitalPinToInterrupt(pino_SW1), change_sense, FALLING);
  attachInterrupt(digitalPinToInterrupt(pino_SW2), change_sense, FALLING);
    
}



void loop() {
  // put your main code here, to run repeatedly:
  if(cicle == 1)
    distance = Quads[First]*pi*Diameter;
}
