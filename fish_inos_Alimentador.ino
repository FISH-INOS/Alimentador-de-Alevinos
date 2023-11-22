#include <SoftwareSerial.h>//INCLUSÃO DE BIBLIOTECA (BLUETOOTH) 
const int pinoRX = 0; //PINO DIGITAL 0 (RX)
const int pinoTX = 1; //PINO DIGITAL 1 (TX)
const int pinMotor2 = 2;
const int pinMotor3 = 3;
SoftwareSerial bluetooth(pinoRX, pinoTX);
int i =0, escolha= 0,continuar=0,cont=0, escolha2 =0 ,comando,comando2, contiunarbluethoot;
  

void setup() {
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  Serial.begin(9600);
  // bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  



}

void loop() {
    // inicia com desligado
    digitalWrite(pinMotor2,LOW);
    digitalWrite(pinMotor3,LOW);
    Serial.print("========================================================\n");
    Serial.print("1 - Alimentar manual\n");
    Serial.print("2 - Alimentar automatico\n");
    Serial.print("3 - Sair\n");
    Serial.print("========================================================\n");
    bluetooth.print("========================================================\n");
    bluetooth.print("1 - Alimentar manual\n");
    bluetooth.print("2 - Alimentar automatico\n");
    bluetooth.print("3 - Sair\n");
    bluetooth.print("========================================================\n");
    delay(5000);
    while(Serial.available() == 0){

    }
    comando = bluetooth.parseInt();
    escolha = Serial.parseInt();
    Serial.print(escolha);
    if(escolha == 1 || comando == 1){
      menukg();
    }
    Serial.print("========================================================\n");
    Serial.print("1 - Alimentar manual\n");
    Serial.print("2 - Alimentar automatico\n");
    Serial.print("3 - Sair\n");
    Serial.print("========================================================\n");
    bluetooth.print("========================================================\n");
    bluetooth.print("1 - Alimentar manual\n");
    bluetooth.print("2 - Alimentar automatico\n");
    bluetooth.print("3 - Sair\n");
    bluetooth.print("========================================================\n");
    while(Serial.available() == 0){

    }
    escolha = Serial.parseInt();
    comando = bluetooth.parseInt();

    
    if(escolha == 2 || comando == 2){
      cont=0;
      automatic();
    }

  }

  void manual1kg(){
    digitalWrite(pinMotor2,LOW);
    digitalWrite(pinMotor3,HIGH);
    delay(3750);
    digitalWrite(pinMotor2,HIGH);
    digitalWrite(pinMotor3,HIGH);
    //continua?
    continuar=0;
    Serial.print("========================================================\n");
    Serial.print("Deseja Contiunar?\n");
    Serial.print("1 - Sim\n");
    Serial.print("2 - Não\n");
    Serial.print("========================================================\n");
    bluetooth.print("========================================================\n");
    bluetooth.print("Deseja Contiunar?\n");
    bluetooth.print("1 - Sim\n");
    bluetooth.print("2 - Não\n");
    bluetooth.print("========================================================\n");
    delay(5000);
    while(Serial.available() == 0){

    }
    continuar = Serial.parseInt();
    contiunarbluethoot = bluetooth.parseInt(); 
    if (continuar == 2 || contiunarbluethoot == 2){
      Serial.print("Você parou");

    }
    if(continuar==1 || contiunarbluethoot == 2){
      manual1kg();
    }        
  }

  void manual5kg(){
    digitalWrite(pinMotor2,LOW);
    digitalWrite(pinMotor3,HIGH);
    delay(5000);
    digitalWrite(pinMotor2,HIGH);
    digitalWrite(pinMotor3,HIGH);
    //continua?
    continuar=0;
    Serial.print("========================================================\n");
    Serial.print("Deseja Contiunar?\n");
    Serial.print("1 - Sim\n");
    Serial.print("2 - Não\n");
    Serial.print("========================================================\n");
    bluetooth.print("========================================================\n");
    bluetooth.print("Deseja Contiunar?\n");
    bluetooth.print("1 - Sim\n");
    bluetooth.print("2 - Não\n");
    bluetooth.print("========================================================\n");
    delay(5000);
    while(Serial.available() == 0){

    }
    continuar = Serial.parseInt();
    contiunarbluethoot = bluetooth.parseInt(); 
    if (continuar == 2 || contiunarbluethoot == 2){
      Serial.print("Você parou");

    }
    if(continuar==1 || contiunarbluethoot == 2){
      manual1kg();
    }  
  }

  void automatic(){
    
    digitalWrite(pinMotor2,LOW);
    digitalWrite(pinMotor3,HIGH);
    delay(3750);
    digitalWrite(pinMotor2,HIGH);
    digitalWrite(pinMotor3,HIGH);
    cont++;
    delay(1000);
    if(cont==5){
      Serial.print("\nVocê parou\n");
    }
    else{
      automatic();
    }    
  }

  void menukg(){
    Serial.print("========================================================\n");
    Serial.print("1 - Alimentar 1kg\n");
    Serial.print("2 - Alimentar 5kg\n");
    Serial.print("3 - Sair\n");
    Serial.print("========================================================\n");
    bluetooth.print("========================================================\n");
    bluetooth.print("1 - Alimentar 1kg\n");
    bluetooth.print("2 - Alimentar 5kg\n");
    bluetooth.print("3 - Sair\n");
    bluetooth.print("========================================================\n");
    delay(5000);
    while(Serial.available() < 0){

    }
    escolha2 = Serial.parseInt();
    comando2 = bluetooth.parseInt();

    if(escolha2 == 1 || comando2 == 1){
      manual1kg();
    }
    if(escolha2 == 2 || comando2 == 2){
      manual5kg();
    }
  }