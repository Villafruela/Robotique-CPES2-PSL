float count = 0.00;
int counter = 0;
float delta = 0.10;

void setup()
{
  Serial.begin(9600);
}

void noter(float value){
  Serial.println(value);
  Serial.println(" ");
}

void loop()
{
  for(counter = 0;counter <= 9;counter++) {
    noter (count);
   	delta = 0.1;
   	count = count + delta;
	}
  for(counter = 0;counter <= 9;counter++) {
    noter (count);
   	delta = -0.1;
   	count = count + delta;
	}
  
}