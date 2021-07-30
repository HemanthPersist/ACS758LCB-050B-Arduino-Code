#define VIN A0
const float vcc    = 5.00;// supply voltage 5V or 3.3V
const float factor = 0.04;// 20mV/A is the factor

float voltage;

void setup() {
    //Robojax.com ACS758 Current Sensor 
    Serial.begin(9600);
    Serial.println("Robojax Tutorial");
    Serial.println("ACS758 Current Tester");
    Serial.println("Basic Simple Code");
}

void loop() {
  //Robojax.com ACS758 Current Sensor 
  voltage =   (5.0 / 1023.0)* analogRead(VIN);// Read the voltage from sensor
  voltage =  voltage - (vcc * 0.5) + 0.007 ;// 0.007 is a value to make voltage zero when there is no current
  float current = voltage / factor;
  Serial.print("VIN :");
  Serial.print(analogRead(VIN));
  Serial.print(" V: ");
  Serial.print(voltage,3);
  Serial.print("V, I: ");
  Serial.print(current,2); Serial.println("A");
  delay(500);
}
