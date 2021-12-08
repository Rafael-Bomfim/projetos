 #include <NewPing.h>

 #define TRIGGER_PIN  8  
 #define ECHO_PIN     10  
 #define MAX_DISTANCE 200 
 #define Buzzer 12
  
 NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  
  pinMode (Buzzer, OUTPUT);
  Serial.begin(115200); 

}

void loop() {
    delay(50);                     
    Serial.print("Distancia: ");
    Serial.print(sonar.ping_cm()); 
    Serial.println("cm");
    
    if(sonar.ping_cm()<=100){
      tone (Buzzer, 1200);
      delay (50);
      tone (Buzzer, 800);
      delay (50);
      tone (Buzzer, 400);
      delay (50); 
    }
   }
    
