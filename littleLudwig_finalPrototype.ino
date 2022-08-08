#include <Tone.h>
#include <pitches.h>

/*0b/# CDUR amoll
  1b FDUR dmoll
  3b ESDUR cmoll        JOJ / MONDSCHEINSONATA
  4# EDUR cismoll       MOONLIGHT SHADOW
  5b/7# DESDUR bmoll    WITHIN
  6b/# GESDUR fismoll   TOUCH
*/

int CDUR[] = {31, 33, 37, 41, 44, 49, 55, 62, 65, 73, 82, 87, 98, 110, 123, 131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093, 2349, 2794, 3136, 3520, 3951, 4186, 4699};
int FDUR [] = {NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_AS2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_AS6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_AS7, NOTE_C8, NOTE_D8};
int ESDUR [] = {NOTE_C1, NOTE_D1, NOTE_DS1, NOTE_F1, NOTE_G1, NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_D2, NOTE_DS2, NOTE_F2, NOTE_G2, NOTE_GS2, NOTE_AS2, NOTE_C3, NOTE_D3, NOTE_DS3, NOTE_F3, NOTE_G3, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_F6, NOTE_G6, NOTE_GS6, NOTE_AS6, NOTE_C7, NOTE_D7, NOTE_DS7, NOTE_F7, NOTE_G7, NOTE_GS7, NOTE_AS7, NOTE_C8, NOTE_D8, NOTE_DS8 };
int EDUR [] = {NOTE_B0, NOTE_CS1, NOTE_DS1, NOTE_E1, NOTE_FS1, NOTE_GS1, NOTE_A1, NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_E2, NOTE_FS2, NOTE_GS2, NOTE_A2, NOTE_B2, NOTE_CS3, NOTE_DS3, NOTE_E3, NOTE_FS3, NOTE_GS3, NOTE_A3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_DS6, NOTE_E6, NOTE_FS6, NOTE_GS6, NOTE_A6, NOTE_B6, NOTE_CS7, NOTE_DS7, NOTE_E7, NOTE_FS7, NOTE_GS7, NOTE_A7, NOTE_B7, NOTE_CS8, NOTE_DS8};
int DESDUR [] = {NOTE_C1, NOTE_CS1, NOTE_DS1, NOTE_F1, NOTE_FS1, NOTE_GS1, NOTE_AS1, NOTE_C2, NOTE_CS2, NOTE_DS2, NOTE_F2, NOTE_FS2, NOTE_GS2, NOTE_AS2, NOTE_C3, NOTE_CS3, NOTE_DS3, NOTE_F3, NOTE_FS3, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_FS5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_CS6, NOTE_DS6, NOTE_F6, NOTE_FS6, NOTE_GS6, NOTE_AS6, NOTE_C7, NOTE_CS7, NOTE_DS7, NOTE_F7, NOTE_FS7, NOTE_GS7, NOTE_AS7, NOTE_C8, NOTE_CS8, NOTE_DS8};
int GESDUR [] = {NOTE_CS1, NOTE_DS1, NOTE_F1, NOTE_GS1, NOTE_AS1, NOTE_B1, NOTE_CS2, NOTE_DS2, NOTE_F2, NOTE_GS2, NOTE_AS2, NOTE_B2, NOTE_CS3, NOTE_DS3, NOTE_F3, NOTE_GS3, NOTE_AS3, NOTE_B3, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_AS4, NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_GS5, NOTE_AS5, NOTE_B5, NOTE_CS6, NOTE_DS6, NOTE_F6, NOTE_GS6, NOTE_AS6, NOTE_B6, NOTE_CS7, NOTE_DS7, NOTE_F7, NOTE_GS7, NOTE_AS7, NOTE_B7, NOTE_CS8, NOTE_DS8 };

int HARM [] = { -12, -6, -4, -3, -2, 0, 2, 3, 4, 6, 12};
int TONWERT [] = {1, 2, 4, 8, 16, 32};
int MODWERT [] = { -8, -4, -2, 1, 2, 4, 8, 16, 32};

int xlength = sizeof(EDUR);/////////////////////////////////////CHANGE DUR HIER 1/3//////////////////////////7/////////////////

const int buzzer = 9;

const int ton1regler = A0;
const int bpmregler = A1;
const int hektikregler = A2;

const int button1 = 7;
const int button2 = 4;
const int killbutton3 = 8;
const int harmbutton4 = 2;
const int bpmled = 3;
//const int fadeled = 3;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;

int teilwerty;
int teilwertz;

int tnle;
int htnle;

Tone tone1; //ton1 + hton1
Tone tone2; //hton2

//MILLIS()
unsigned long beatpremillis = 0;
unsigned long tonpremillis = 0;

/*************************************************************************************************/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tone1.begin(5);
  tone2.begin(5);

  pinMode(buzzer, OUTPUT);
  pinMode(ton1regler, INPUT);
  pinMode(bpmregler, INPUT);
  pinMode(bpmled, OUTPUT);
  //  pinMode(fadeled, OUTPUT);
}

/*FUNKtions*/
/*************************************************************************************************/
//TON1 Regler1 auslesen
int ton1GEN() {
  int reglerReading = analogRead(ton1regler);
  int mep = map(reglerReading, 0, 1023, 0, xlength);
  return mep;
}

int brightnessMAP() {
  int reglerReadingb = analogRead(ton1regler);
  int brightness = map(reglerReadingb, 0, 1023, 0, 255);
  return brightness;
}

//-> TON1 auswählen
int ton1PICK(int mep) {
  int ton1 = EDUR[mep];/////////////////////////////////////CHANGE DUR HIER 2/3//////////////////////////////77//////////////
  return ton1;
}

//HTONPOSITION wird zufällig harmonisch zu TON1 gewählt
int harmcontrol(int mep) {
  int x = random(0, 10);
  int steps = HARM[x];
  int harmpos = mep + steps;
  return harmpos;
}

//TONBEGRENZUNG um nicht aus Array zu fallen
int grenzkontrolle(int harmpos) {
  if (harmpos >= xlength) {
    harmpos = xlength - 1;
    return harmpos;
  }
  if (harmpos < 0) {
    harmpos = 0;
    return harmpos;
  }
  return harmpos;
}

//HTON1 wird ausgewählt
int harmoton1GEN(int mep) {
  int harmpos = harmcontrol(mep);
  harmpos = grenzkontrolle(harmpos);
  int hton1 = EDUR[harmpos];/////////////////////////////////////CHANGE DUR HIER 3/3////////////////////////////////////7//77/
  return hton1;
}

//BPM Regler2 auslesen -> BPM auswählen
int bpmGEN() {
  int reglerRead2 = analogRead(bpmregler);
  int bpm = map(reglerRead2, 0, 1023, 60, 200); // bpm in ms viel viel ms ist ein beat sein sollen
  return bpm;
}

//BPM in millis für beat
int bpmMILLIMAKER(int bpm) {
  int bpmillis = 60000 / bpm;
  return bpmillis; // ist VIERTELNOTE
}

//von VIERTEL NOTE ZU GANZER UMGERECHNET für töne
int taktMAKER (int bpmillis) {
  int ganzemillis = bpmillis * 4;
  return ganzemillis;
}

//TonwertMODIFIER
int wertMOD() {
  int reglerRead3 = analogRead(hektikregler);
  int mod = map(reglerRead3, 0, 1023, 0, 8); //welche Zahl wird als teiler für tonwertteiler gemacht HuMMPGf
  int wertmod = MODWERT[mod];
  return wertmod;
}

//zufälliger WERT von Ton im gewählten BPM (Dauer)
int tonwertteiler (int ganzemillis) {
  int y = random(0, 4);
  teilwerty = TONWERT[y];
  int tonwert = ganzemillis / teilwerty;
  int wertmod = wertMOD();
  if (wertmod < 0) {
    wertmod = -wertmod;
    tonwert = tonwert * wertmod;
    Serial.println("mod x" + String(wertmod));
  } else {
    tonwert = tonwert / wertmod;
    Serial.println("mod 1/" + String(wertmod));
  }
  return tonwert;
}

//zufälliger WERT von PAUSE im gewählten BPM (Dauer)
int pauswertteiler (int bpmillis) {
  int z = random(3, 5);
  teilwertz = TONWERT[z];
  int pauswert = bpmillis / teilwertz;
  pauswert = pauswert/2;
  int wertmod = wertMOD();
  if (wertmod < 0) {
    wertmod = -wertmod;
    pauswert = pauswert/2;
  } else {
    pauswert = pauswert / wertmod;
  }
  return pauswert;
}

int ton1wertGEN(int ganzemillis) {
  int ton1wert = tonwertteiler(ganzemillis);
  return ton1wert;
}

/*int ZENpick(int mep){
  int zenmep = mep +2; //
  Serial.println(mep);
  Serial.println(zenmep);
  int zton2 = GESDUR[zenmep];/////////////////////////////////////CHANGE DUR HIER 4/4////////////////////////////////////7//77/
  }*/

/*************************************************************************************************/
void loop() {
  //MODE SWITCH >:(

  //TON1 AUS DUR ARRAY AUSWÄHLEN
  int mep = ton1GEN();
  int ton1 = ton1PICK(mep);

  //TONSUCHE BUTTON1
  button1State = digitalRead(button1);
  if (button1State == HIGH) {
    tone1.play(ton1);
    Serial.println("TONSUCHE" + String(ton1));
    //int brightness = brightnessMAP();
    //analogWrite(fadeled, brightness);
    return;
  }

  //KILL BUTTON3
  button3State = digitalRead(killbutton3);
  if (button3State == HIGH) {
    tone1.stop();
    Serial.println("☠☠☠☠☠☠☠☠☠☠☠");
    return;
  }

  //BPM AUSWÄHLEN
  int bpm = bpmGEN();
  int bpmillis = bpmMILLIMAKER(bpm);
  Serial.println("bpm " + String(bpm));
  int ganzemillis = taktMAKER(bpmillis);

  //MOD
  int wertmod = wertMOD();

  /*GRUNDTON//TONWERT ZUFÄLLIG ZU BPM WÄHLEN  ---
    int ton1wert = tonwertteiler(ganzemillis);
    int ton1paus = ton1wert;

    /////////////////////LILBGRUNDTON/////////////////
    tone1.play(ton1,ton1wert);
    delay(ton1paus);
  */

  //HTON1 Harmonie zufällig finden zu TON1
  int hton1 = harmoton1GEN(mep);
  int hton1wert = tonwertteiler(ganzemillis);
  int hton1paus = pauswertteiler(ganzemillis) ;

  //BPMSUCHE BUTTON2
  button2State = digitalRead(button2);

  //BEATMILLIS
  unsigned long beatnowmillis = millis();
  if (beatnowmillis - beatpremillis >= bpmillis) {
    beatpremillis = beatnowmillis;
    Serial.println("****************");
    digitalWrite(bpmled, HIGH);

    if (button2State == HIGH) {
      tone1.play(ton1, bpmillis);
      Serial.println("BPMSUCHE" + String(bpm));
      digitalWrite(bpmled, LOW);
      return;
    }

  } else if (button2State == LOW) {

    //TONMILLIS
    unsigned long tonnowmillis = millis();
    int toninterval = hton1wert + hton1paus;
    if (tonnowmillis - tonpremillis >= toninterval) {
      tonpremillis = tonnowmillis;
      Serial.println("♬♪♫♩♬♪♬♩♬♪♫♩♬♪♬♩♬♪♫♩♬♪♬♩");
      /////////////////////LILB/////////////////
      tone1.play(hton1, hton1wert);
      button4State = digitalRead(harmbutton4);
      if (button4State == HIGH) {
        Serial.println("II.♬♪♫♩♬♪♬♩♬♪♫♩♬♪♬♩♬♪♫♩♬♪♬♩.II");
        int zton1 = harmoton1GEN(mep);
        tone2.play(zton1, hton1wert);
      }
      if (!tone1.isPlaying()) {
        return;
      }
    }
    Serial.println("----------------");
    digitalWrite(bpmled, LOW);
    return;
  }


  ///////////////////////////////////////////Z/E/N/Y/A/////////////////////////////////////////////////
  /* int zton2 = ZENpick(mep);
    tone1.play(ton1, ton1wert);
    tone2.play(hton1, ton1wert);

    delay(ton1wert);*/


  ////////////// shyt /////////////////////////////////
  /* PRIO
    knopf für tonregler hören
    knopf für beat hören
    volume regler möglich?? nein
    ZENYA MODUS
    BPM x2 oder Regler für hektik (dauer von tonwerten)
  */
  //HARMOBUTTEN
  ///swaxsus
  //VOLUME REGLER --> library!!!! vol.tone(frequ, vol);


  //kaos knöpfle ohne array in tönen stöbern
  //motor für beat // beat allgemein
  //mit is.playing abfragen ob regler ton noch spielt
  //regler für Tonlänge langsammm bis ultra quik
  // regler für TONART arrays

  /*//BPM doppler / halbierer BUTTON3 VLT
    button2State = digitalRead(button2);
    if (button2State == HIGH) {
     if (bpm >= 100){
      bpm = bpm / 2;
      Serial.println("BUTT/2bpm " + String(bpm));
     } else {
      bpm = bpm * 2;
      Serial.println("BUTT*2bpm " + String(bpm));
      }
    } */
}
