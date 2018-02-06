int S3 = 9;
int S2 = 10;
int outpin = 8;
unsigned int plusewidth;
int r ; // kırmızı renk
int g ;// yeşil renk
int b ;// mavi renk
int w ;// beyaz renk

void setup() {
  Serial.begin(9600); //seri haberleşme başladı
  pinMode(S3, OUTPUT);// sensör çıkış pinleri
  pinMode(S2, OUTPUT);
  pinMode(outpin, INPUT);// TCS3200 sensör giriş pini
}
//  void red(){
//    renk_oku();
// if ( r < g && r < b && r > w && g > b && g > w && b > w && r < 550) {
//    Serial.println("*! RED *!");
// //çigi izlemeye başla 
//  }
//  else {
//    
//    //durdur veya ara
//    }}
void loop() {
   renk_oku();

  Serial.print("R : ");
  Serial.print(r);
  Serial.print(" G : ");
 Serial.print(g);
  Serial.print(" B : ");
  Serial.print(b);
  Serial.print( " W : ");
  Serial.print(w);
  Serial.println("");
  
 if ( r < g && r < b && r > w && g > b && g > w && b > w && r < 550) {
    Serial.println("*! RED *!");
 
  }

  else if ( r < b && r > w && g < b && g > w && b > w ) {
    Serial.println("*! GREEN *!");
  
  }
  else if ( r > g && r > b && r > w && g > b && g > w && b > w  ) {
   Serial.println("*! BLUE *!");

 }
  else if (r < g && r > b && r > w && g > b && g > w && b > w ) {
    Serial.println("*! WHİTE *!");

 }
 else
   Serial.println("!----------------------OKUNAMADI----------------------!");

  //delay (100);

}

void renk_oku() { // renk algılama kodu

  // kırımızı renk için okuma işlemi
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  r = pulseIn(outpin, LOW);
//  r = plusewidth / 400. - 1;
//  r = (255 - r);
  /*----------------------*/

  //yeşil renk için okuma işlemi
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  g = pulseIn(outpin, LOW);
// g = plusewidth / 400. - 1;
//    g = (255 - g);

  /*----------------------*/

  //mavi renk için okuma işlemi
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  b = pulseIn(outpin, LOW);
//   b = plusewidth / 400. - 1;
//  b = (255 - b);

  /*----------------------*/

  //beyaz renk için okuma işlemi
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  w = pulseIn(outpin, LOW);
//
//    w = (255 - w);
}
