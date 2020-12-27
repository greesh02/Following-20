int q = 6,w = 9,e = 10,r = 11; // changed q from 8 to 6
int rr = 3,y = 13,cc = 4,t = 12,ll = 5;//  RIGHT SENSOR- y -- 13,LEFT SENEOR- t -- 12  
int  val,n = 0,o = 8,j = 0;
int z = 0,d = 1;
int u = 0,v = 0; // U -- X / V -- Y //
int val1,val2;
int spd = 220;
int kk = 10; // MULTIPLER FOR CONTROLLING TURNING

//obs
int yy;
int xx;
int zz = 0;
int uu = 0,vv = 0; // uu -- x coordinate / vv -- y coordinate //--------------CURRENT POSITION OF THE BOT------------start node (0,0)--------facing front-------------------------------------------------------//

int trigg_f = A0,echo_f = A1;
int trigg_l = A2,echo_l = A3;
int trigg_r = A4,echo_r = A5;

long duration;
long distance_f;
long distance_l;
long distance_r;

int uf;
int ul;
int ur;

int mf,nf,pf;
int mb,nb,pb;
int ml,nl,pl;
int mr,nr,pr;

int P_vals[4];

int minimum;
int min_index;

//distance of obstacle

int dist_min = 20;
int dist_min_moving = 5;
//reverse

int reverse = 0;
int reverse_mem_f = 0 ;
int reverse_mem_b = 0 ;
int reverse_mem_r = 0 ;
int reverse_mem_l = 0 ;
//extra

int pint = 1;
String u1,v1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(q,OUTPUT);
pinMode(w,OUTPUT);
pinMode(e,OUTPUT);
pinMode(r,OUTPUT);

pinMode(t,INPUT);
pinMode(y,INPUT);
pinMode(rr,INPUT);
pinMode(cc,INPUT);
pinMode(ll,INPUT);

//ultra sonic sensors
pinMode(trigg_f,OUTPUT);
pinMode(echo_f,INPUT);
pinMode(trigg_l,OUTPUT);
pinMode(echo_l,INPUT);
pinMode(trigg_r,OUTPUT);
pinMode(echo_r,INPUT);

}



int forward(int a){
  int a1 = 1;
  int a2 = 0;
  while (a1 <= a){

    if (a1 == a){
      break;
    }
    a1 = a1 +4;
  }
  if (a1 == a){
    return a;
  }
  else{
    return a2; 
  }
  }



int right(int b){
  int b1 = 2;
  int b2 = 0;
  while (b1 <= b){

    if (b1 == b){
      break;
    }
    b1 = b1 +4;
  }
  if (b1 == b){
    return b;
  }
  else{
    return b2; 
  }
  }



int backward(int c){
  int c1 = 3;
  int c2 = 0;
  while (c1 <= c){

    if (c1 == c){
      break;
    }
    c1 = c1 +4;
  }
  if (c1 == c){
    return c;
  }
  else{
    return c2; 
  }
  }




int left(int f){
  int f1 = 4;
  int f2 = 0;
  while (f1 <= f){

    if (f1 == f){
      break;
    }
    f1 = f1 +4;
  }
  if (f1 == f){
    return f;
  }
  else{
    return f2; 
  }
  }

void line_follow(){
  while(1 == 1){

    obs_distance_front();
    if(distance_f > dist_min_moving) {


    
    // FORWARD ----------------------------------------------
 
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){ 
  analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
                                                            //--------MOVEMENT ACTUALLY LINE FOLLOWER----------//
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
}

  // RIGHT TURN---------------------------------------------
  
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 1)){ 
  
  analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
    
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
 
  analogWrite(w,0);
  analogWrite(q,spd-5*kk);//LEFT MOTOR FORWARD
  analogWrite(r,spd-5*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){
 
  analogWrite(w,0);
  analogWrite(q,spd-7*kk);//LEFT MOTOR FORWARD
  analogWrite(r,spd-7*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
  
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){
  
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd-15*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}

if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
   
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
 
    // LEFT TURN----------------------------------------------
  
if((digitalRead(ll) == 1) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
   
  analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){ 
  
   analogWrite(w,spd-2*kk);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-2*kk);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  
  analogWrite(w,spd-2*kk);                     //-------------------============================================================= from 4 to 2
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-2*kk);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
   
   analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  
 analogWrite(w,spd-6*kk);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-6*kk);//RIGHT MOTOR FORWARD
  
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){ 
   
   analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
 
}

// DETECTION----------------------------------------------------

if(((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)) || ((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1))) 
{ 
//Serial.println(n);
  digitalWrite(q,LOW);
  digitalWrite(w,LOW);//LEFT MOTOR //

  digitalWrite(r,LOW);
  digitalWrite(e,LOW);//RIGHT MOTOR //
  
 
  delay(300);

//  After detection it moves a little forward 

  digitalWrite(w,LOW);
  digitalWrite(q,HIGH);//LEFT MOTOR FORWARD
                                                            
 digitalWrite(r,LOW);
 digitalWrite(e,HIGH);//RIGHT MOTOR FORWARD
 delay(250);
 digitalWrite(q,LOW);
  digitalWrite(w,LOW);//LEFT MOTOR //

  digitalWrite(r,LOW);
  digitalWrite(e,LOW);//RIGHT MOTOR // 

  break;
}
// EXCEPTION------------------------------------------
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  //============================+++++++++++++++++++++++++++++++++++++++++
}
  }
  else {

    //---------------------------==============================--------------===========================
    reverse_line_follow();
    break;
    
  }
  }
}


void reverse_line_follow()
{

while(1 == 1){

    
    
    // BACKWARD ----------------------------------------------
 
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){ 
  analogWrite(w,spd);
  analogWrite(q,0);//LEFT MOTOR BACKWARD
                                                            //--------MOVEMENT ACTUALLY LINE FOLLOWER----------//
  analogWrite(r,spd);
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}

  // RIGHT TURN---------------------------------------------(turning left in backward direction)
  
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 1)){ 
  
  analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
    
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
 
  analogWrite(w,0);
  analogWrite(q,spd-5*kk);//LEFT MOTOR FORWARD
  analogWrite(r,spd-5*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){
 
  analogWrite(w,0);
  analogWrite(q,spd-10*kk);//LEFT MOTOR FORWARD
  analogWrite(r,spd-10*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
  
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){
  
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd-15*kk);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}

if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)){
   
   analogWrite(w,0);
  analogWrite(q,spd);//LEFT MOTOR FORWARD
  analogWrite(r,spd);                        //-------------------==========================================================
  analogWrite(e,0);//RIGHT MOTOR BACKWARD
}
 
    // LEFT TURN----------------------------------------------(turning right in backward direction)
  
if((digitalRead(ll) == 1) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
   
  analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){ 
  
   analogWrite(w,spd-2*kk);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-2*kk);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  
  analogWrite(w,spd-4*kk);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-4*kk);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
   
   analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
}
if((digitalRead(ll) == 0) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  
 analogWrite(w,spd-6*kk);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd-6*kk);//RIGHT MOTOR FORWARD
  
}
if((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 0)){ 
   
   analogWrite(w,spd);                     //-------------------=============================================================
  analogWrite(q,0);//LEFT MOTOR BACKWARD                                                 
  analogWrite(r,0);
  analogWrite(e,spd);//RIGHT MOTOR FORWARD
 
}

// DETECTION----------------------------------------------------

if(((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)) || ((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1))) 
{ 
  //detection
  reverse = 1;
  
//Serial.println(n);
  digitalWrite(q,LOW);
  digitalWrite(w,LOW);//LEFT MOTOR //

  digitalWrite(r,LOW);
  digitalWrite(e,LOW);//RIGHT MOTOR //
  
 
  delay(300);


  digitalWrite(w,LOW);
  digitalWrite(q,HIGH);//LEFT MOTOR FORWARD
                                                            //--------MOVEMENT ACTUALLY LINE FOLLOWER----------//
 digitalWrite(r,LOW);
 digitalWrite(e,HIGH);//RIGHT MOTOR FORWARD
 delay(250);
 digitalWrite(q,LOW);
  digitalWrite(w,LOW);//LEFT MOTOR //

  digitalWrite(r,LOW);
  digitalWrite(e,LOW);//RIGHT MOTOR // 

  break;
}
// EXCEPTION------------------------------------------
if((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)){
  //============================+++++++++++++++++++++++++++++++++++++++++
}
  
  
  }


  
  
}
void obs_distance()
{
//front ultra
digitalWrite(trigg_f,LOW);
delay(2);
digitalWrite(trigg_f,HIGH);
delay(10);
digitalWrite(trigg_f,LOW);
uf = digitalRead(echo_f);
duration = pulseIn(echo_f,HIGH);
distance_f = duration/58.2; // -------------------------- in cm
//Serial.println(duration);
//Serial.println("dist of object in front");
//Serial.println(distance_f);
delay(1000);

//left ultra
digitalWrite(trigg_l,LOW);
delay(2);
digitalWrite(trigg_l,HIGH);
delay(10);
digitalWrite(trigg_l,LOW);
ul = digitalRead(echo_l);
duration = pulseIn(echo_l,HIGH);
distance_l = duration/58.2;  // -------------------------- in cm
//Serial.println(duration);
//Serial.println("dist of object in front");
//Serial.println(distance_l);
delay(1000);

//right ultra
digitalWrite(trigg_r,LOW);
delay(2);
digitalWrite(trigg_r,HIGH);
delay(10);
digitalWrite(trigg_r,LOW);
ur = digitalRead(echo_r);
duration = pulseIn(echo_r,HIGH);
distance_r = duration/58.2;  // -------------------------- in cm
//Serial.println(duration);
//Serial.println("dist of object in front");
//Serial.println(distance_r);
delay(1000);

}
void obs_distance_front()
{
//front ultra
digitalWrite(trigg_f,LOW);
delay(2);
digitalWrite(trigg_f,HIGH);
delay(10);
digitalWrite(trigg_f,LOW);
uf = digitalRead(echo_f);
duration = pulseIn(echo_f,HIGH);
distance_f = duration/58.2; // -------------------------- in cm
//Serial.println(duration);
//Serial.println("dist of object in front");
//Serial.println(distance_f);

}

void loop() {
  // put your main code here, to run repeatedly:
  
while(0 ==  0){
  while (Serial.available() == 0)
  {  
  }
 yy = Serial.parseInt();
 Serial.println(yy);
 delay(1000);
 while (Serial.available() == 0)
 { 
 }
 xx = Serial.parseInt();
 Serial.println(xx);
while (1 == 1){

  
  if ((uu == xx) && (vv == yy)){
     Serial.println(uu);
     Serial.println(vv);
    uu = xx;
    vv = yy;//sends x values--------------------------to stop in python
    pint = 1;
    break;
  }
  else
  {
  while(2 == 2){

    u1 = String(uu) + "x" ;
    v1 = String(vv) + "y" ;
    
    //delay(4000);
    //if (pint == 2)
   // { 
   // Serial.println(u1); 
    
   // }
    Serial.println(u1); 
    Serial.println(v1);
    pint = 2;
     
  // (uu,vv) ----- current position of the bot -- start node (0,0)---------------------------------------------------------------------------------

if (d == forward(d)){

    Serial.println(d);
    Serial.println(100);
    
  if ( vv > 0){
   mb = uu;          // possible x coordinate               //point behind the bot
   nb = ( vv - 1);  // possible y coordinate
   //Serial.println(mb);
   //Serial.println(nb);
   pb = (abs(xx - mb) + abs(yy - nb));  
  }
  else{
    pb = 700;
     //Serial.println(101);
   //Serial.println(101);
  }
  if (( vv < 4) && (reverse_mem_f == 0)){
    mf = uu;     //possible x                                //point front of the bot    
    nf = vv+1;  //possible y
     //Serial.println(mf);
   //Serial.println(nf);
    pf = (abs(xx - mf) + abs(yy - nf)); 
  }
  else{
    pf = 700;
    //Serial.println(101);
   //Serial.println(101);
    reverse_mem_f = 0;
  }
  if ( uu > 0){
    ml = (uu - 1);   //possible x                            //point left of the bot
    nl = vv;         //possible y
     //Serial.println(ml);
   //Serial.println(nl);
    pl = (abs(xx - ml) + abs(yy - nl)); 
  }
  else{
    pl = 700;
    //Serial.println(101);
   //Serial.println(101);
  }
  if ( uu < 4) {
    mr = (uu + 1); // possible x                              //point right of the bot
    nr = vv;       // possible y
    //Serial.println(mr);
    //Serial.println(nr);
    pr = (abs(xx - mr) + abs(yy - nr));
  }
  else{
    pr = 700;
    //Serial.println(101);
   //Serial.println(101);
  }

  
    
  
}
if (d == backward(d)){

    Serial.println(d);
    Serial.println(200);
    
   if (vv < 4){
    mb = uu;    //possible x                                         //point behind the bot
    nb = vv+1;  // possible y
    //Serial.println(mb);
   //Serial.println(nb);
    pb = (abs(xx - mb) + abs(yy - nb)); 
  }
  else{
    pb = 700;
    //Serial.println(101);
   //Serial.println(101);
  }

  if (( vv > 0) && (reverse_mem_b == 0)){
    mf = uu;       //possible x                                             //point front of the bot
    nf = (vv - 1); //possible y
    //Serial.println(mf);
   //Serial.println(nf);
    
     pf = (abs(xx - mf) + abs(yy - nf)); 
  }
  else{
    pf = 700;
    //Serial.println(101);
   //Serial.println(101);
    reverse_mem_b = 0;
  }
   if ( uu < 4){
    ml = uu+1;  //possible x                                       //point left to bot
    nl = vv;    //possible y
    //Serial.println(ml);
   //Serial.println(nl);
    pl = (abs(xx - ml) + abs(yy - nl)); 
  }
   else{
    pl = 700;
    //Serial.println(101);
   //Serial.println(101);
  } 
  if ( uu > 0){
    mr = uu - 1; // possible x                                    //point right to bot
    nr = vv;      //possible y
    //Serial.println(mr);
   //Serial.println(nr);
    pr = (abs(xx - mr) + abs(yy - nr));
  }
   else{
    pr = 700;
   // Serial.println(101);
   //Serial.println(101);
  }
  
   
 
}

if(d == right(d)){

   Serial.println(d);
   Serial.println(300);
   
    if ( uu > 0){
    mb = uu - 1; // possible x                                    //point behind the bot
    nb = vv;      //possible y
    // Serial.println(mb);
   //Serial.println(nb);
    pb = (abs(xx - mb) + abs(yy - nb));
  }
   else{
    pb = 700;
    // Serial.println(101);
   //Serial.println(101);
  }
  if (( uu < 4) && (reverse_mem_r == 0)){
    mf = uu+1;  //possible x                                       //point front to bot
    nf = vv;    //possible y
    // Serial.println(mf);
  // Serial.println(nf);
    pf = (abs(xx - mf) + abs(yy - nf)); 
  }
   else{
    pf = 700;
     //Serial.println(101);
   //Serial.println(101);
    reverse_mem_r = 0;
  }

   if (vv < 4){
      ml = uu;    //possible x                                         //point left to the bot
      nl = vv+1;  // possible y
      // Serial.println(ml);
   //Serial.println(nl);
      pl = (abs(xx - ml) + abs(yy - nl)); 
  }
    else{
      pl = 700;
      // Serial.println(101);
   //Serial.println(101);
  }

    if ( vv > 0){
      mr = uu;       //possible x                                             //point right of the bot
      nr = (vv - 1); //possible y
   //    Serial.println(mr);
   //Serial.println(nr);
      pr = (abs(xx - mr) + abs(yy - nr)); 
  }
    else{
      pr = 700;
       //Serial.println(101);
   //Serial.println(101);
  }
  
     
  
}
if (d == left(d)){

    Serial.println(d);
    Serial.println(400); 
    
  if ( uu < 4) {
    mb = (uu + 1); // possible x                              //point behind of the bot
    nb = vv;       // possible y
    // Serial.println(mb);
   //Serial.println(nb);
    pb = (abs(xx - mb) + abs(yy - nb));
  }
  else{
    pb = 700;
    // Serial.println(101);
   //Serial.println(101);
  }
  if (( uu > 0) && (reverse_mem_l == 0)){
    mf = (uu - 1);   //possible x                            //point front of the bot
    nf = vv;         //possible y
    // Serial.println(mf);
  // Serial.println(nf);
    pf = (abs(xx - mf) + abs(yy - nf)); 
  }
  else{
    pf = 700;
    // Serial.println(101);
   //Serial.println(101);
    reverse_mem_l = 0;
  }

  if ( vv > 0){
   ml = uu;          // possible x coordinate               //point left to the bot
   nl = ( vv - 1);  // possible y coordinate
   // Serial.println(ml);
   //Serial.println(nl);
   pl = (abs(xx - ml) + abs(yy - nl));  
  }
  else{
    pl = 700;
   //  Serial.println(101);
   //Serial.println(101);
  }
  if ( vv < 4){
    mr = uu;     //possible x                                //point right of the bot    
    nr = vv+1;  //possible y
    // Serial.println(mr);
   //Serial.println(nr);
    pr = (abs(xx - mr) + abs(yy - nr)); 
  }
  else{
    pr = 700;
   //  Serial.println(101);
  // Serial.println(101);
  }
   
}

     P_vals[0] = pr; 
     P_vals[1] = pf;         // adding values to list----------------
     P_vals[2] = pl;
     P_vals[3] = pb;
    // Serial.println(P_vals[1]);
     //Serial.println(P_vals[3]);
     //Serial.println(P_vals[0]);
    // Serial.println(P_vals[2]);

  obs_distance();    // finding for obstacle //

  delay(300);
while (3 == 3){
if (((ul == 1) || (distance_l > dist_min )) && ( (uf == 1) || (distance_f > dist_min)) && ( (ur == 1) || (distance_r > dist_min))) {      // no obstacle on any side -----------------------------------------

    Serial.println("a");
    minimum = P_vals[0];
    min_index = 0; 
     for (int i = 0; i <= 2; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }

     break;

}


  if (( (ul == 1) || (distance_l > dist_min)) && (0 <= distance_f <= dist_min) && ( (ur == 1) || (distance_r > dist_min))) {                       // obstacle at front only---------------------------------

      P_vals[1] = 700; //kind of not considering pf value------------

       Serial.println("b");
       minimum = P_vals[0];
       min_index = 0; 
     for (int i = 0; i <= 2; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }


   break;
   
  }
if (( (ul == 1) || (distance_l > dist_min)) && ( (uf == 1) || (distance_f > dist_min)) && (0 <= distance_r <= dist_min)){          // obstacle only on right-------------------------------------------------

      P_vals[0] = 700; //kind of not considering pr value------------

    
    Serial.println("c");
     minimum = P_vals[0]; 
     min_index = 0;
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }


     break;
  
}

if ((0 <= distance_l <= dist_min) && ( (uf == 1) || (distance_f > dist_min)) && ( (ur == 1) || (distance_r > dist_min))){          //obstacle on left only------------------------------------------

     P_vals[2] = 700; //kind of not considering pl value------------

    Serial.println("d");
    minimum = P_vals[0]; 
    min_index = 0;
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }

   break;


}
if ((0 <= distance_l <= dist_min) && (0 <= distance_f <= dist_min) && ( (ur == 1) || (distance_r > dist_min))){       //obstacle on left and front-----------------------------------------------------

   P_vals[1] = 700; //kind of not considering pf value------------
   P_vals[2] = 700; //kind of not considering pl value------------

   Serial.println("e");

   minimum = P_vals[0];
   min_index = 0; 
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }


     break;
}

if (( (ul == 1) || (distance_l > dist_min)) && (0 <= distance_f <= dist_min) && (0 <= distance_r <= dist_min)){            //obstacle on front and right--------------------------------------

   P_vals[1] = 700; //kind of not considering pf value------------
   P_vals[0] = 700; //kind of not considering pr value------------

    Serial.println("f");
    minimum = P_vals[0]; 
    min_index = 0;
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }

     break;

 }

if ((0 <= distance_l <= dist_min) && ((uf == 1) || (distance_f > dist_min)) && (0 <= distance_r <= dist_min)){   //obstacle of left and right---------------------------------------------

   P_vals[2] = 700; //kind of not considering pl value------------
   P_vals[0] = 700; //kind of not considering pr value------------

    Serial.println("g");
    minimum = P_vals[0]; 
    min_index = 0;
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }

      break;
}

if ((0 <= distance_l <= dist_min) && (0 <= distance_f <= dist_min) && (0 <= distance_r <= dist_min)){         //obstacle on left, front and  right ---------------------------------------------------------

   P_vals[2] = 700; //kind of not considering pl value------------
   P_vals[1] = 700; //kind of not considering pf value------------
   P_vals[0] = 700; //kind of not considering pr value------------

    Serial.println("h");
    minimum = P_vals[0];
    min_index = 0; 
     for (int i = 0; i <= 3; i++)
     {
      if (P_vals[i] < minimum){

        minimum = P_vals[i];
        min_index = i;
      }
     }

       break; 
       
}
}

     Serial.println(P_vals[1]); //pf
     Serial.println(P_vals[2]); //pl
     Serial.println(P_vals[0]); //pr
     Serial.println(P_vals[3]); //pb

     delay(100);           //changed to 100 from 1000

//MOVEMENT------------------------------------------------------------------------------------------------------------------------------------------------------------

  while(Serial.available() == 0){
    
  }

  min_index = Serial.parseInt();

 
 
 if (min_index == 1){   // pf   //FORWARD//======================================================

      line_follow();
      if (reverse == 1){
        uu = uu;
        vv = vv;
        Serial.println(1);
        reverse = 0;
        reverse_mem_f = 1;
      }
      else{
      uu = mf;
      vv = nf;
      Serial.println(0);
      }
      break;
     }

     if (min_index == 3){  // pb    //BACKWARD//======================================================
      
      d = d+1+1; // FOR UTURN
          
        digitalWrite(w,LOW);
         digitalWrite(q,HIGH);//LEFT MOTOR FORWARD
                                                            //--------FORWARD MOVEMENT----------//
         digitalWrite(r,LOW);
         digitalWrite(e,HIGH);//RIGHT MOTOR FORWARD
         delay(300);
         digitalWrite(q,LOW);
         digitalWrite(w,LOW);//LEFT MOTOR //

         digitalWrite(r,LOW);
         digitalWrite(e,LOW);//RIGHT MOTOR //
          
       digitalWrite(w,LOW);
       digitalWrite(q,HIGH);//LEFT MOTOR FORWARD
                                                        //UTURN TURN - 2 RIGHT TURNS------
       digitalWrite(r,HIGH);
       digitalWrite(e,LOW);//RIGHT MOTOR BACKWARD
        delay(1400);
       digitalWrite(q,LOW);
       digitalWrite(w,LOW);//LEFT MOTOR //
       
       digitalWrite(r,LOW);
       digitalWrite(e,LOW);//RIGHT MOTOR //

        digitalWrite(w,HIGH);
         digitalWrite(q,LOW);//LEFT MOTOR BACKWARD
                                                            //--------BACKWARD MOVEMENT----------//
         digitalWrite(r,HIGH);
         digitalWrite(e,LOW);//RIGHT MOTOR BACKWARD
         delay(450);
         digitalWrite(q,LOW);
         digitalWrite(w,LOW);//LEFT MOTOR //

         digitalWrite(r,LOW);
         digitalWrite(e,LOW);//RIGHT MOTOR //
         
         line_follow();
          if (reverse == 1){
              uu = uu;
              vv = vv;
              Serial.println(1);
              reverse = 0;
              reverse_mem_b = 1;
           }
           else
           {
              uu = mb;
              vv = nb;
              Serial.println(0);
           }
         break;
     }

     if (min_index == 0){     // pr           //RIGHT//=========================================================================

     d = d+1;
        
        while(0 == 0){
          if(((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 1)) || ((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 1) && (digitalRead(rr) == 1)) || ((digitalRead(ll) == 0) && (digitalRead(t) == 0) && (digitalRead(cc) == 1) && (digitalRead(y) == 1) && (digitalRead(rr) == 1))){ 
          break;
        }
        else{
       analogWrite(w,0);
       analogWrite(q,200);//LEFT MOTOR FORWARD
                                                        //RIGHT TURN
       //analogWrite(r,200);
       //analogWrite(e,0);//RIGHT MOTOR BACKWARD
        }
        delay(5);
       digitalWrite(q,LOW);
       digitalWrite(w,LOW);//LEFT MOTOR //
       
       digitalWrite(r,LOW);
       digitalWrite(e,LOW);//RIGHT MOTOR //
        }
        analogWrite(w,0);
       analogWrite(q,200);//LEFT MOTOR FORWARD                                                                //RIGHT TURN
       //analogWrite(r,200);
       //analogWrite(e,0);//RIGHT MOTOR BACKWARD
        delay(25);
       digitalWrite(q,LOW);
       digitalWrite(w,LOW);//LEFT MOTOR //       
       digitalWrite(r,LOW);
       digitalWrite(e,LOW);//RIGHT MOTOR //

      line_follow();
       if (reverse == 1){
        uu = uu;
        vv = vv;
        Serial.println(1);
        reverse = 0;
        reverse_mem_r = 1;
      }
      else
      {
         uu = mr;
         vv = nr;
         Serial.println(0);
      }
      break;
      }

     if (min_index == 2 ){  // pl            //LEFT//===============================================================================                     

       d = d+3;
         
         while(0 == 0){
        if(((digitalRead(ll) == 1) && (digitalRead(t) == 0) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)) || ((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 0) && (digitalRead(y) == 0) && (digitalRead(rr) == 0)) || ((digitalRead(ll) == 1) && (digitalRead(t) == 1) && (digitalRead(cc) == 1) && (digitalRead(y) == 0) && (digitalRead(rr) == 0))){ 
          break;
        }
        else{
     // analogWrite(w,200);
     // analogWrite(q,0);//LEFT MOTOR BACKWARD
                                                            //LEFT TURN
      analogWrite(r,0);
      analogWrite(e,200);//RIGHT MOTOR FORWARD
        }
         
      delay(5);
      digitalWrite(q,LOW);
      digitalWrite(w,LOW);//LEFT MOTOR //
       
      digitalWrite(r,LOW);
      digitalWrite(e,LOW);//RIGHT MOTOR //
        
        }
      //analogWrite(w,200);
      //analogWrite(q,0);//LEFT MOTOR BACKWARD                                                                 //LEFT TURN
      analogWrite(r,0);
      analogWrite(e,200);//RIGHT MOTOR FORWARD  
      delay(25);
      digitalWrite(q,LOW);
      digitalWrite(w,LOW);//LEFT MOTOR //
      digitalWrite(r,LOW);
      digitalWrite(e,LOW);//RIGHT MOTOR //

      line_follow();
       if (reverse == 1){
        uu = uu;
        vv = vv;
        Serial.println(1);
        reverse = 0;
        reverse_mem_l = 1;
      }
      else
      {
      uu = ml;
      vv = nl;
      Serial.println(0);
      }
      break;
 }  
}
  
  

  
 
 
 }
 
 
}
}
}
