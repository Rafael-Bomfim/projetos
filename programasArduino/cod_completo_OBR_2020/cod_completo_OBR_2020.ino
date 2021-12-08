   
   
   #include <NewPing.h>
   #define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
   #define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
   #define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
  
   #define VelocidadeMotorEsq 2   //Controla a velocidade do motor esquerdo 0 a 255 
   #define MotorEsq_Frente    3   //Movimenta o motor esquerdo para frente    Motor: fios Brancos e Vermelhos
   #define MotorEsq_Re        4   //Movimenta o motor esquerdo para trás
   #define VelocidadeMotorDir 6   //Controla a velocidade do motor direito 0 a 255
   #define MotorDir_Frente    7   //Movimenta o motor direito para frente
   #define MotorDir_Re        8   //Movimenta o motor direito para trás

   #define Sensor1           A0   //Sensor de linha lado esquerdo
   #define Sensor2           A1   //Sensor de linha lado direito
   #define Sensor3           A2   //Sensor verde lado esquerdo
   #define Sensor4           A3   //Sensor verde lado direito
   NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



   
  //******************************************************************Variáveis****************************************************************************// 
   int mSen = 50;                    //Valor médio dos sensores de linha
   int mSenV = 30;
   int forcaMotorEsq = 180;          //Potência do motor esquerdo 0 a 255 
   int forcaMotorDir = 180;          //Potência do motor direito 0 a 255
   int ESen1 = analogRead (Sensor1); //Variável que guarda a leitura do sensor 1.
   int ESen2 = analogRead (Sensor2); //Variável que guarda a leitura do sensor 2.

   //*************************************************************Funções********************************************************************************//

  //*******************************************************Virar para a Esquerda*************************************************************************//
    void VirarEsquerda() {
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
    digitalWrite (MotorEsq_Frente, LOW);
    digitalWrite (MotorEsq_Re, HIGH);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, HIGH);
    digitalWrite (MotorDir_Re, LOW);
  }
  //************************************************************Virar para a Direita*********************************************************************//
    void VirarDireita() { 
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
    digitalWrite (MotorEsq_Frente, HIGH);
    digitalWrite (MotorEsq_Re, LOW);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, LOW);
    digitalWrite (MotorDir_Re, HIGH);   
  }
  //************************************************************Movimentar para Frente*******************************************************************//
    void Frente () {
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
    digitalWrite (MotorEsq_Frente, HIGH);
    digitalWrite (MotorEsq_Re, LOW);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, HIGH);
    digitalWrite (MotorDir_Re, LOW);
    }
  //************************************************************Movimentar para Trás***********************************************************************//
   void re() {
   analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
   digitalWrite (MotorEsq_Frente, LOW);
   digitalWrite (MotorEsq_Re, HIGH);        
   analogWrite  (VelocidadeMotorDir, forcaMotorDir);
   digitalWrite (MotorDir_Frente, LOW);
   digitalWrite (MotorDir_Re, HIGH);
   }
  //**********************************************************************Parar****************************************************************************//
    void pare() {
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq); 
    digitalWrite (MotorEsq_Frente, LOW);
    digitalWrite (MotorEsq_Re, LOW);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, LOW);
    digitalWrite (MotorDir_Re, LOW); 
  }
  void ObstaculoDireita() {
    pare();
    delay(500);
    VirarDireita();
    delay (1800);
    pare();
    delay(500);
    Frente ();
    delay(1800);
    pare();
    delay(500);
    VirarEsquerda();
    delay(1800);
    pare();
    delay(500);
    Frente ();
    delay(3000);
    pare();
    delay(500);
    VirarEsquerda();
    delay(1800);
    pare();
    delay(500);
    Frente();
    delay(1000);
    pare();
    delay(500);
    VirarDireita();
    delay(1000);
    Frente();
    
    }
  //*********************************************************************Setup*******************************************************************************//
  void setup() {
  pinMode (VelocidadeMotorEsq, OUTPUT);
  pinMode (MotorEsq_Frente, OUTPUT);
  pinMode (MotorEsq_Re, OUTPUT);
  pinMode (VelocidadeMotorDir, OUTPUT);
  pinMode (MotorDir_Frente, OUTPUT);
  pinMode (MotorDir_Re, OUTPUT);
  pinMode (Sensor1, INPUT);
  pinMode (Sensor2, INPUT);
  Serial.begin (9600);//Velocidade de leitura do Monitor serial 9600 bits por segundo//
  }
   //********************************************************************Loop********************************************************************************//
  void loop() {
  int ESen1 = analogRead (Sensor1); //Variável que guarda a leitura do sensor 1.
  int ESen2 = analogRead (Sensor2); //Variável que guarda a leitura do sensor 2.
  Serial.print   ("ESen1=");
  Serial.print   (ESen1);
  Serial.print   ("  ESen2=");
  Serial.println   (ESen2);
  delay(50);
  Serial.print("Ping ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  
  if((ESen1 < mSen) && (ESen2 > mSen)) {
    VirarDireita();
  if((ESen1 > mSen) && (ESen2 > mSen)) {
    VirarDireita();
  }
  }
  if((ESen1 < mSen) && (ESen2 > mSen)) {
  VirarDireita();
  }
  if((ESen1 > mSen) && (ESen2 < mSen)) {
    VirarEsquerda();
  }
  if((ESen1 < mSen) && (ESen2 < mSen)) {
    Frente();
  }
  if((ESen1 > mSen) && (ESen2 > mSen)) {
    VirarDireita();
  }

  if((sonar.ping_cm()<=5) && (sonar.ping_cm()>0)) {
      ObstaculoDireita();
  if((ESen1 < mSen) && (ESen2 > mSen)) {
  VirarDireita();
  }
  }
   
  }
