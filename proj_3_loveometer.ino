const int sensorPin = A0; 
const float baselineTemp = 16.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port

  for(int pinNumber = 3; pinNumber<6; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = -(voltage - .5) * 100; // the - sign was added by me
  Serial.println(temperature);

  if(temperature < baselineTemp+2){ // temperature < 18
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp+2 && //18 <= Temperature < 19
   temperature < baselineTemp+3){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp+3 && // 19 <= Temperature < 20
   temperature < baselineTemp+4){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
   }else if(temperature >= baselineTemp+4){ // 20 <= Temperature 
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
   }
   delay(100);
}
