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
}powe;
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
int mov = CLOCKWISE;
int Quads[] = {0,0,0,0};
int cicle = 0;
double distance;
//***********************************************Functions***********************************************
void change_sense_to_clk()
{
  mov = CLOCKWISE;
}
void change_sense_to_aclk()
{
  mov = ANTICLOCKWISE;
}

//B3
void state_0_15()
{
  Quads[First]++;
  if(Quads[First]%4 == 0)
     cicle++;
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
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pin_B3, INPUT_PULLUP);
  pinMode(pin_B2, INPUT_PULLUP);
  pinMode(pin_B1, INPUT_PULLUP);
  pinMode(pin_B0, INPUT_PULLUP);
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin_B3), state_8_7, RISING);
  attachInterrupt(digitalPinToInterrupt(pin_B3), state_0_15, FALLING);
  //attachInterrupt(digitalPinToInterrupt(pin_B2), state_4_3, RISING);
  //attachInterrupt(digitalPinToInterrupt(pin_B2), state_12_11, FALLING);
  
  
  attachInterrupt(digitalPinToInterrupt(pin_SW1), change_sense_to_clk, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_SW2), change_sense_to_aclk, FALLING);
    
}



void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sentido: ");
  Serial.println(mov);
  Serial.print("Ciclos: ");
  Serial.println(cicle);
  Serial.print("quad1: ");
  Serial.println(Quads[First]);
  //if(cicle == 1)
    //distance = Quads[First]*pi*Diameter;
}
