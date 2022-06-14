#define pin_B3 2
#define pin_B2 3
#define pin_B1 4
#define pin_B0 5
#define pin_SW1 18
#define pin_SW2 19

typedef enum SENTIDO
{
  CLOCKWISE,
  ANTICLOCKWISE
}sense;

//B3
void estado_0_15()
{
  
}
void estado_8_7()
{
  
}
//B2
void estado_12_11()
{
  
}
void estado_4_3()
{
  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_B3, INPUT_PULLUP);
  pinMode(pin_B2, INPUT_PULLUP);
  pinMode(pin_B1, INPUT_PULLUP);
  pinMode(pin_B0, INPUT_PULLUP);
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin_B3), estado_8_7, RISING);
  attachInterrupt(digitalPinToInterrupt(pin_B3), estado_0_15, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_B2), estado_4_3, RISING);
  attachInterrupt(digitalPinToInterrupt(pino_B2), estado_12_11, FALLING);
  
}



void loop() {
  // put your main code here, to run repeatedly:
 
}
