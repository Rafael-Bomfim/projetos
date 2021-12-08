//**********************************************************Progamação OBR 2020***************************************************************************//
  
   #define VelocidadeMotorEsq 2   //Controla a velocidade do motor esquerdo 0 a 255 
   #define MotorEsq_Frente    3   //Movimenta o motor esquerdo para frente    Motor: fios Brancos e Vermelhos
   #define MotorEsq_Re        4   //Movimenta o motor esquerdo para trás
   #define VelocidadeMotorDir 6   //Controla a velocidade do motor direito 0 a 255
   #define MotorDir_Frente    7   //Movimenta o motor direito para frente
   #define MotorDir_Re        8   //Movimenta o motor direito para trás

   #define Sensor1           A0   //Sensor de linha lado esquerdo
   #define Sensor2           A1   //Sensor de linha lado esquerdo
   #define Sensor3           A2   //Sensor de linha lado direito
   #define Sensor4           A3   //Sensor de linha lado direito 
   #define Sensor5           A4   //Sensor de linha lado esquerdo
   #define Sensor6           A5   //Sensor de linha lado direito
   
  //******************************************************************Variáveis****************************************************************************//
   int mSen = 250;                 //Valor médio dos sensores de linha
   int mSenV = 85;                 //Valor médio dos sensores verdes 
   int forcaMotorEsq = 150;        //Potência do motor esquerdo 0 a 255 
   int forcaMotorDir = 150;        //Potência do motor direito 0 a 255

   //*************************************************************Funções**********************************************************************************//

  //***********************************************************Virar para a Esquerda***********************************************************************//
    void VirarEsquerda() {
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
    digitalWrite (MotorEsq_Frente, LOW);
    digitalWrite (MotorEsq_Re, HIGH);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, HIGH);
    digitalWrite (MotorDir_Re, LOW);
  }

  //************************************************************Virar para a Direita***********************************************************************//
    void VirarDireita() {
    analogWrite  (VelocidadeMotorEsq, forcaMotorEsq);
    digitalWrite (MotorEsq_Frente, HIGH);
    digitalWrite (MotorEsq_Re, LOW);
    analogWrite  (VelocidadeMotorDir, forcaMotorDir);
    digitalWrite (MotorDir_Frente, LOW);
    digitalWrite (MotorDir_Re, HIGH);
    
}
  //************************************************************Movimentar para Frente*********************************************************************//
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
 //****************************************************************Obstáculo Direita***********************************************************************//
    void ObstaculoDireita() {
    pare();
    delay(250);
    VirarDireita();
    delay (250);
    pare();
    delay(250);
    Frente ();
    delay(250);
    pare();
    delay(250);
    VirarEsquerda();
    delay(250);
    pare();
    delay(250);
    Frente ();
    delay(250);
    pare();
    delay(250);
    VirarEsquerda();
    delay(250);
    pare();
    delay(250);
    Frente();
    delay(250);
    }

 //***********************************************************************Setup****************************************************************************//
  void setup() {
  pinMode (VelocidadeMotorEsq, OUTPUT);
  pinMode (MotorEsq_Frente, OUTPUT);
  pinMode (MotorEsq_Re, OUTPUT);
  pinMode (VelocidadeMotorDir, OUTPUT);
  pinMode (MotorDir_Frente, OUTPUT);
  pinMode (MotorDir_Re, OUTPUT);
  pinMode (Sensor1, INPUT);
  pinMode (Sensor2, INPUT);
  pinMode (Sensor3, INPUT);
  pinMode (Sensor4, INPUT);
  pinMode (Sensor5, INPUT);
  pinMode (Sensor6, INPUT);
  Serial.begin (9600);//Velocidade de leitura do Monitor serial 9600 bits por segundo//
}
 //********************************************************************Loop********************************************************************************//
  void loop() {
  int ESen1 = analogRead (Sensor1); //Variável que guarda a leitura do sensor 1.
  int ESen2 = analogRead (Sensor2); //Variável que guarda a leitura do sensor 2.
  int ESen3 = analogRead (Sensor3); //Variável que guarda a leitura do sensor 3.
  int ESen4 = analogRead (Sensor4); //Variável que guarda a leitura do sensor 4.
  int ESen5 = analogRead (Sensor5); //Variável que guarda a leitura do sensor 5.
  int ESen6 = analogRead (Sensor6); //Variável que guarda a leitura do sensor 6.
  Serial.print   ("ESen1=");
  Serial.print   (ESen1);
  Serial.print   ("ESen2=");
  Serial.print   (ESen2);
  Serial.print   ("Esen3=");
  Serial.print   (ESen3);
  Serial.print   ("ESen4=");
  Serial.print   (ESen4);
  Serial.print   ("ESen5=");
  Serial.print   (ESen5);
  Serial.print   ("Esen6=");
  Serial.println (ESen6);

  if((ESen1 < mSen) && (ESen2 > mSen) && (ESen3 < mSen) && (ESen4 < mSen) && (ESen5 < mSenV) && (ESen6 < mSenV)){
    VirarEsquerda();
  }

  if((ESen1 < mSen) && (ESen2 < mSen) && (ESen3 > mSen) && (ESen4 < mSen) && (ESen5 < mSenV) && (ESen6 < mSenV)){
    VirarDireita();
  }

  if((ESen1 < mSen) && (ESen2 > mSen) && (ESen3 > mSen) && (ESen4 < mSen) && (ESen5 < mSenV) && (ESen6 < mSenV)){
    Frente();
  }
  
  }
  
