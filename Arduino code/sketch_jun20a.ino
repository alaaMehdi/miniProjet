#define pin2 2
#define pin3 3
#define buzz 13
#define pir 12
#define lzr A1


void setup() {
  Serial.begin(9600);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(buzz,LOW);
}

bool actBuzz,wrt1,wrt2,wrt3 = false;

String fetch1 = "GET\\ FireBase response.\n";
String fetch2 = "Set Protocol HTTPs.\n";
String fetch3 = "RECIVE JSON";
String fetch4 = "https://miniprojet-9f728.firebaseio.com/api/System.json";
String gettingFB = "{\n"
" \"System\" : \"Active\" \n"
"}\n";

String fetch11 = "POST\\ FireBase response.\n";
String fetch22 = "Set Protocol HTTPs.\n";
String fetch33 = "SEND JSON";
String settingingFB = "{\n"
" \"Status\" : \"Intrusion\" \n"
"}\n";


void loop() {
  int sensorVal = analogRead(lzr);
  int pirState = digitalRead(pir);
  if(wrt1==false){
    Serial.println(fetch1);
    Serial.println(fetch2);
    Serial.println(fetch3);
    Serial.println(fetch4);
    Serial.println(gettingFB);
    //Serial.println("No UPDATE!");
    Serial.println(" ");
    wrt1=true;
  }
  

  if(sensorVal<100){
    actBuzz=true;
  }else{
    actBuzz=false;
  }
  
  if(pirState == LOW && actBuzz==false){
   /* if (wrt3==false){
      Serial.println("Etat Normal");
      wrt3=true;
    }*/
    
    digitalWrite(buzz,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    if(pirState == LOW || actBuzz==false)
    wrt2=false;
  }

  if(sensorVal<100){
    
    digitalWrite(buzz,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    Serial.println(" ");

    if(wrt2==false){
      Serial.println("Etat d\'Intrusion");
      Serial.println("Acivate Alarme");
      Serial.println(fetch11);
      Serial.println(fetch22);
      Serial.println(fetch33);
      Serial.println(settingingFB);
      //Serial.println("UPDATE OK");
      //Serial.println(" ");
   
      wrt2=true;
      
    }
    
    
  }

  if(pirState == HIGH){
    
    digitalWrite(buzz,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    Serial.println(" ");
  
    if(wrt2==false){
      Serial.println("Etat d\'Intrusion");
      Serial.println("Acivate Alarme");
      Serial.println(fetch11);
      Serial.println(fetch22);
      Serial.println(fetch33);
      Serial.println(settingingFB);
      //Serial.println("UPDATE OK");
      //Serial.println(" ");

      wrt2=true;
    }
    
  }
 delay(150);

}
