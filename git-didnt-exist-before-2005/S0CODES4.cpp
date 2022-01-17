#include<string.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<iostream.h>

#define sync(u) u%2

class Profile
{
public:

char pfname[25];
int hghscr;
int lstscr;
int zcount;

Profile()
{
	strcpy(pfname, "default_profile");
	hghscr = 0;
	lstscr = 0;
	zcount = 0;
}

void getdata(int k9_r)
{
	hghscr = 0;
	lstscr = 0;
	zcount = 0;
}

void putdata()
{
	cout<<"PROFILE: "<<pfname<<endl;
	cout<<"TOTAL ZOMBIES KILLED: "<<zcount<<endl;
	cout<<"HIGHEST SCORE: "<<hghscr<<endl;
	cout<<"LAST SCORE: "<<<lstscr<<endl;
	cout<<endl<<"<PRESS ENTER>"<<endl;
}

};

class Obj
{
public:

char objname[50];
char title[110];
char descript[110];
char bravo[110];
int dref;
int valid;
float armour;
float health;
float attack;
int maxammo;

Obj(
char Cobjname[50],
char Ctitle[110],
char Cdescript[110],
char Cbravo[110],
int Cdref,
int Cvalid,
float Carmour,
float Chealth,
float Cattack,
int Cmaxammo)
{
	strcpy(objname, Cobjname);
	strcpy(title, Ctitle);
	strcpy(descript, Cdescript);
	strcpy(bravo, Cbravo);
	dref = Cdref;
	valid = Cvalid;
	armour = Carmour;
	health = Chealth;
	attack = Cattack;
	maxammo = Cmaxammo;
}

Obj()
{
	strcpy(objname, "\n");
	strcpy(title, "\n");
	strcpy(descript, "\n");
	strcpy(bravo, "\n");
	dref = 0;
	valid = 0;
	armour = 0.0;
	health = 0.0;
	attack = 0.0;
	maxammo = 0;
}

};

class RoomSlots
{
public:

char objname[50];
char title[110];
char descript[110];
char bravo[110];
int dref;
int valid;
float armour;
float health;
float attack;
int maxammo;

RoomSlots(
char Cobjname[50],
char Ctitle[110],
char Cdescript[110],
char Cbravo[110],
int Cdref,
int Cvalid,
float Carmour,
float Chealth,
float Cattack,
int Cmaxammo)
{
	strcpy(objname, Cobjname);
	strcpy(title, Ctitle);
	strcpy(descript, Cdescript);
	strcpy(bravo, Cbravo);
	dref = Cdref;
	valid = Cvalid;
	armour = Carmour;
	health = Chealth;
	attack = Cattack;
	maxammo = Cmaxammo;
}

RoomSlots()
{
	strcpy(objname, "\n");
	strcpy(title, "\n");
	strcpy(descript, "\n");
	strcpy(bravo, "\n");
	dref = 0;
	valid = 0;
	armour = 0.0;
	health = 0.0;
	attack = 0.0;
	maxammo = 0;
}

};       /*LivingRoom[],Kitchen[],Backyard[],LocalInfirmary[],Streets[],Church[],PoliceStation[]*/


//||||||||||||||||||||||||||||||||||enemydb

class Enemy
{
public:

char btype[50];
float zhealth;
float zattack;

Enemy(
char Cbtype[50],
float Czhealth,
float Czattack)
{
	strcpy(btype, Cbtype);
	zhealth = Czhealth;
	zattack = Czattack;
}

Enemy()
{
	strcpy(btype, "\n");
	zhealth = 0.0;
	zattack = 0.0;
}

};

Enemy Zombie[2] = {
                  Enemy("LEAN AND THIN ZOMBIE",8,2),
                  Enemy("FAT ZOMBIE",12,2.5)
                  };

Enemy BossZombie("ACID ZOMBIE",90,15);

//||||||||||||||||||||||||||||||||||enemydb

//ii. DATABASE INITIALISATION

fstream file("PLAYPROF.dat", ios::in|ios::out|ios::binary)
Profile player;

//i. OBJECT INITIALISATION
      //livingroom
	  Obj torch1000("LIGHT-TORCH","A PHOSPHORUS TORCH","UTILITY: increase surrounding awareness","You picked up torch, which enhances visibility and thus, attack potential. USE REMAINING:15 ATTACK:+2.5",1000,1,0,15,2.5,15);
	  Obj redbull1001("REDBULL CAN","A REDBULL CAN","Redbull, hyperactivity?","You drank Redbull (got wings). HEALTH:+2.0",1001,1,0,2.0,0,0);
	  Obj tv1002("TV","TV MONITOR","TV, turn on/off (!turning on may attract zombies from the streets)","\n",1002,1,0,0,0,0);
	  Obj bed1003("BED","BED","Bed? Take a nap.","You took a nap, your vital signs look good. HEALTH:+0.2",1003,1,0,0.2,0,0);
	  Obj umbrella1004("UMBRELLA","OLD TORN UMBRELLA","Umbrella, good-to-go weapon.","You picked up UMBRELLA. USE REMAINING:16 ATTACK:+3.0",1004,1,0,16,3.0,16);

      //kitchen
      Obj stalebread1005("STALE BREAD","SOME STALE BREAD","Stale bread, take a taste","You ate the bread. HEALTH:+2.0",1005,1,0,2.0,0,0);
      Obj knife1006("KNIFE","A BUTCHER'S KNIFE","Zombie-Butcher!","You picked up a knife. USE REMAINING:12 ATTACK:+6.0",1006,1,0,12,6.0,12);
      Obj cookies1007("COOKIES","SCATTERED BAKED COOKIES","Fresh cookies, have some maybe?","You ate cookies. HEALTH:+3.0",1007,1,0,3.0,0,0);
      Obj fork1008("FORK","A FORK ON THE CROKERY HANGER","Fork?...is a very small weapon.","You picked up a fork. USE REMAINING:5 ATTACK:+1.5",1008,1,0,5,1.5,5);
      Obj oldjacket1009("OLD JACKET","AN OLD JACKET","Thick, old, jacket. Hard to penetrate.","You put the jacket on. ARMOUR LEVEL 1",1009,1,1.08,0,0,0);
      Obj vinegar1010("VINEGAR","SPILLED VINEGAR","Vinegar has strong stench. Apply to cover scent and distract attacking zombies.","You used Vinegar. HEALTH:+0.80",1010,1,0,0.8,0,0);
      Obj tap1011("WATER TAP","LEAKING WATER TAP","Drink Water.","You drank water. HEALTH:+0.25",1011,1,0,0.25,0,0);
      Obj china1012("CHINAWARE","CHINAWARE ON THE CROCKERY HANGER","Examine.","Expensive, shiny, china bowl.",1012,1,0,0,0,0);
      Obj molotov1013("MOLOTOVS","PETROL BOMBS","Explosives, what are you thinking?","You picked up Molotovs. EXPLOSIVES REMAINING:4 ATTACK:+7.0",1013,1,0,4,7,4);
      Obj cell1014("CELL PHONE","CELL PHONE NEAR THE STOVE","Examine.","Battery is dead. Cell phone cannot be used.",1014,1,0,0,0,0);

      //backyard
      Obj leaf1015("LEAF","GREEN MAPLE LEAF","Maple leaf has medicinal value.","You extracted health. HEALTH:+10.0",1015,1,0,10,0,0);

      //localinfirmary
      Obj medikit1016("MEDIKIT","MEDIKIT ON THE DESK","Medikit will help you gain health.","You gained health. HEALTH:+15.0",1016,1,0,15,0,0);
      Obj rottenapple1017("APPLE","AN APPLE ON THE FLOOR","Pick it up.","The Apple is too rotten to be eaten.",1017,1,0,0,0,0);
      Obj gun1018("DESERT EAGLE","A COLT PISTOL","It's a loaded Desert Eagle pistol!","You picked up a pistol. LOADED AMMO:15 ATTACK:+10.0",1018,1,0,15,10,15);
      Obj policevest1019("POLICE-VEST","BLOOD STAINED POLICE-VEST","Police-Vest is a Professional Armour.","You put Polive-vest on. ARMOUR LEVEL 2",1019,1,1.15,0,0,0);
      Obj bandages1020("BANDAGES","A PAIR OF BANDAGES","You gain health when you apply bandages.","You applied bandages. HEALTH:+2.0",1020,1,0,2.0,0,0);
      Obj books1021("BOOKS","BOOKS ON THE SHELF","Read Contents.","Books of a medical practitioner.",1021,1,0,0,0,0);

      //streets
      Obj rod1022("IRON ROD","A BROKEN IRON ROD","It's heavy and broken sharp at one end... could be a weapon.","You picked up the rod. USE REMAINING:50 ATTACK+8.0",1022,1,0,50,8,50);
      Obj garbage1023("GARBAGE","AN ERECT GARBAGE TIN BY THE SIDE OF THE STREET","Look in.","There is a slurry of orange zombie blood.",1023,1,0,0,0,0);
      Obj car1024("CAR","A BROKEN DOWN CAR AT THE END OF THE STREET","Look into it.","Dead person on the seat, infected with the zombie virus.\nWill turn into a zombie soon.",1024,1,0,0,0,0);

      //church
      Obj dagger1025("DAGGER","A DAGGER","Dagger is sharp to cut.","You picked up the dagger. ATTACK+8.0",1025,1,0,30,8,30);
      Obj photo1026("PHOTOGRAPH","PHOTOGRAPH ON THE WALL","Take a look.","Painting of Jesus entitled \' The Last Supper\'.",1026,1,0,0,0,0);
      Obj dead1027("DEAD","A DEAD BODY NEAR THE ALTAR","Take a close look.","The body has been melted with what seems to be a kind of smoking, green slurry.",1027,1,0,0,0,0);
      Obj medikit1028("MEDIKIT","MEDIKIT","Medikit will help you gain health.","You gained health. HEALTH+15.0",1028,1,0,15,0,0);

      //ps
      Obj rifle1029("WINCHESTER-98","A RIFLE","WINCHESTER-98 SHRAPNEL THROWER... a professional zombie killer it is!","You picked up the Winchester Rifle. LOADED AMMO:0 ATTACK:+17.0",1029,1,0,0,17,25);
      Obj shrapnel1030("AMMO","SHRAPNEL AMMO CRATE","Open.","You picked up ammo.",1030,1,0,20,0,20);
      Obj acidstain1031("STAIN","SOME GREEN STAIN ON THE FLOOR,","Examine.","There have been acid stains before. Why are they here?",1031,1,0,0,0,0);
      Obj dirt1032("DIRT","UNUSUAL GOOEY DIRT ON THE FLOOR AT ANOTHER PLACE","Examine.","The lumps have presence of zombie-blood.",1032,1,0,0,0,0);
      Obj medikit1033("MEDIKIT","AN UNLOCKED MEDIKIT","Medikit will help you gain health.","You gained health. HEALTH:+15.0",1033,1,0,15,0,0);
      Obj dead1034("DEAD","ANOTHER DEAD BODY (OF A POLICEMAN)","Examine.","His pocket might have car keys. He was trying to escape.\nThere is a police car parked outside.",1034,1,0,0,0,0);
      Obj keys1035("KEYS","SOMETHING UNDER THE OFFICER'S HAND","Examine.","Car Keys.",1035,1,0,0,0,0);

//FIRST PERSON GLOBAL PARAMETERS
	 char n[20];
	 float health = 10;
     //underlying carries slot item info and respective attack potential value
	 Obj slotobj[2] = {Obj("hand is free","empty","empty","empty",0,0,0.0,0.0,1.0,0), Obj("hand is free","empty","empty","empty",0,0,0.0,0.0,1.0,0)};
     Obj armourobj("empty","empty","empty","empty",0,0,0.0,0.0,0.0,0);
	 int points = 0;
	 int kills = 0;

	 char in[20];

//default OBJECT STATIONS INI.
	 RoomSlots LivingRoom[5];
     RoomSlots Kitchen[10];
     RoomSlots Backyard[1];
     RoomSlots LocalInfirmary[10];
     RoomSlots Streets[3];
     RoomSlots Church[4];
     RoomSlots PS[8];

//MISC. VARIABLES
	 char ch=' ';
	 char str[30];
	 int i_temp;
	 int i = -1;
	 int alertflag = 0;
	 int flag = 0;
	 Obj temp;

//FUNCTIONS DECLARED
	 void titlebox(void);
	 void smenu(void);
	 void gameover(void);
	 void introd(void);
	 void initialise(void);
	 void inventory(void);
	 void battle(void);
	 void battlex(void);

	 void livingroom(void);
	 void kitchen(void);
	 void backyard(void);
     void localinfirmary(void);
     void streets(void);
     void church(void);
     void ps(void);



//FUNCTION DEFINITIONS
void livingroomtext()
{
strcpy(in,"Living Room");
cout<<"\n*********************************HOUSE: LIVING ROOM*****************************\n";
cout<<"You are in your living room. It's dark but there is enough illumination to grapple things. It's quiet outside. You haven't spotted a zombie for more than a couple of days because you have been confined to the room. You are not supposed to make noise, as noise and light from homes may attract zombies. Electricity has been cut off and your cell phone is not working. However, you can see some things you could make use of."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"You can see the following objects:\n1. "<<LivingRoom[0].title<<"\n2. "<<LivingRoom[1].title<<"\n3. "<<LivingRoom[2].title<<"\n4. "<<LivingRoom[3].title<<"\n5. "<<LivingRoom[4].title; cout<<"\nFrom here, you can go to:\nh. KITCHEN"<<endl;
}
void livingroom()
{
livingroomtext();
while(1)
{
cout<<"\n+> ";
cin>>ch;
switch(ch)
{
case '1' : //to

if(LivingRoom[0].valid==1)
{
i++;
cout<<LivingRoom[0].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&LivingRoom[0],sizeof(LivingRoom[0]));
memcpy(&LivingRoom[0],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object is not found in the room."<<endl;
break;

case '2' :

if(LivingRoom[1].valid==1)
{
cout<<LivingRoom[1].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += LivingRoom[1].health;
cout<<LivingRoom[1].bravo<<endl;
LivingRoom[1].valid = 0;
strcpy(LivingRoom[1].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case '3' :

if(LivingRoom[2].valid==1)
{
cout<<LivingRoom[2].descript<<"   <PRESS ENTER>"<<endl;
getch();
if(alertflag==0) { cout<<"Stay alert. Zombies might be heading your way. You turned on the TV."<<endl; alertflag = 1; }
else { cout<<"You're safe. You turned off the TV."<<endl; alertflag = 0; }
}
break;

case '4' :

cout<<LivingRoom[3].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += 0.2;
cout<<LivingRoom[3].bravo<<endl;
break;

case '5' : //to

if(LivingRoom[4].valid==1)
{
i++;
cout<<LivingRoom[4].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&LivingRoom[4],sizeof(LivingRoom[4]));
memcpy(&LivingRoom[4],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case 't' : cout<<"You dont't have a previous ROOM to go to."<<endl;
case 'h' : kitchen(); break;
case 'i' : inventory(); break;
case 'r' : livingroomtext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void kitchentext()
{
strcpy(in,"Kitchen");
cout<<"\n*************************************KITCHEN************************************\n";
cout<<"This is your kitchen. You have used almost all the food in here. However, some stale food is still remaining."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"You can see the following objects:\n1. "<<Kitchen[0].title<<"\n2. "<<Kitchen[1].title<<"\n3. "<<Kitchen[2].title<<"\n4. "<<Kitchen[3].title<<"\n5. "<<Kitchen[4].title<<"\n6. "<<Kitchen[5].title<<"\n7. "<<Kitchen[6].title<<"\n8. "<<Kitchen[7].title<<"\n9. "<<Kitchen[8].title<<"\n0. "<<Kitchen[9].title; cout<<"\nFrom here, you can go to and back to the following:\nh. BACKYARD, (there is some strange noise outside, flashes through the window)\nt. LIVING ROOM"<<endl;
}
void kitchen()
{
kitchentext();
while(1)
{
cout<<endl<<"What do you want to do next?"<<endl;
cin>>ch;
switch(ch)
{
case '1' :

if(Kitchen[0].valid==1)
{
cout<<Kitchen[0].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Kitchen[0].health;
cout<<Kitchen[0].bravo<<endl;
Kitchen[0].valid = 0;
strcpy(Kitchen[0].title,"empty");
}
else cout<<"Object not found in the room."<<endl;
break;

case '2' :

i++;
if(Kitchen[1].valid==1)
{
cout<<Kitchen[1].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&Kitchen[1],sizeof(Kitchen[1]));
memcpy(&Kitchen[1],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '3' :

if(Kitchen[2].valid==1)
{
cout<<Kitchen[2].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Kitchen[2].health;
cout<<Kitchen[2].bravo<<endl;
Kitchen[2].valid = 0;
strcpy(Kitchen[2].title,"empty");
}
else cout<<"Object not found in the room."<<endl;
break;

case '4' :

i++;
if(Kitchen[3].valid==1)
{
cout<<Kitchen[3].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&Kitchen[3],sizeof(Kitchen[3]));
memcpy(&Kitchen[3],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '5' :

i++;
if(Kitchen[4].valid==1)
{
cout<<Kitchen[4].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&armourobj,sizeof(armourobj));
memcpy(&armourobj,&Kitchen[4],sizeof(Kitchen[4]));
memcpy(&Kitchen[4],&temp,sizeof(temp));

cout<<armourobj.bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '6' :

if(Kitchen[5].valid==1)
{
cout<<Kitchen[5].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Kitchen[5].health;
cout<<Kitchen[5].bravo<<endl;
Kitchen[5].valid = 0;
strcpy(Kitchen[5].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case '7' :

cout<<Kitchen[6].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Kitchen[6].health;
cout<<Kitchen[6].bravo<<endl;
break;

case '8' :

cout<<Kitchen[7].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Kitchen[7].bravo<<endl;
break;

case '9' :
i++;
if(Kitchen[8].valid==1)
{
cout<<Kitchen[8].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&Kitchen[8],sizeof(Kitchen[8]));
memcpy(&Kitchen[8],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '0' :

cout<<Kitchen[9].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Kitchen[9].bravo<<endl;
break;

case 't' : livingroom(); break;
case 'h' : backyard(); break;
case 'i' : inventory(); break;
case 'r' : kitchentext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void backyardtext()
{
strcpy(in,"Backyard");
cout<<"\n*************************************BACKYARD***********************************\n";
cout<<"Not having been maintained for weeks, over grown grass and debris has made the backyard difficult to walk into. There are traces of zombie blood, too."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"You can see only one object here\n1. "<<Backyard[0].title<<endl;
cout<<"From here, you can go to and back to:\nh. LOCAL INFIRMARY\nt. KITCHEN"<<endl; }
void backyard()
{
backyardtext();
cout<<"\n<PRESS ENTER>"<<endl;
getch();
cout<<"Oh no! a rummaging zombie just saw you from the streets.\nYou need to fight your way back to safety.\nIt's heading your way. Here, it comes!"<<endl;
battle();
backyardtext();
while(1)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

if(Backyard[0].valid==1)
{
cout<<Backyard[0].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Backyard[0].health;
cout<<Backyard[0].bravo<<endl;
Backyard[0].valid = 0;
strcpy(Backyard[0].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case 't' : kitchen();
case 'h' : localinfirmary(); break;
case 'i' : inventory(); break;
case 'r' : backyardtext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void localinfirmarytext()
{
strcpy(in,"Local Infirmary");
cout<<"\n********************************LOCAL INFIRMARY********************************\n";
cout<<"The infirmary is located at the street next to that you house is at, making it accessible through your backyard. The infirmary used to be run by clinic practitioner in a small 30x30ft room directly overlooking the street. You carefully crossed the street as not to alert the zombie at a distance. The room is full of debris that has wounded round the torn green curtains that used to shield the only door."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"You can explore the following objects:\n1. "<<LocalInfirmary[0].title<<"\n2. "<<LocalInfirmary[1].title<<"\n3. "<<LocalInfirmary[2].title<<"\n4. "<<LocalInfirmary[3].title<<"\n5. "<<LocalInfirmary[4].title<<"\n6. "<<LocalInfirmary[5].title; cout<<"\nFrom here, you can go to and back to:\nh. STREETS\nt. BACKYARD"<<endl; }
void localinfirmary()
{
localinfirmarytext();
while(1)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

if(LocalInfirmary[0].valid==1)
{
cout<<LocalInfirmary[0].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += LocalInfirmary[0].health;
cout<<LocalInfirmary[0].bravo<<endl;
LocalInfirmary[0].valid = 0;
strcpy(LocalInfirmary[0].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case '2' :

cout<<LocalInfirmary[1].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<LocalInfirmary[1].bravo<<endl;
break;

case '3' :

i++;
if(LocalInfirmary[2].valid==1)
{
cout<<LocalInfirmary[2].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&LocalInfirmary[2],sizeof(LocalInfirmary[2]));
memcpy(&LocalInfirmary[2],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '4' :

i++;
if(LocalInfirmary[3].valid==1)
{
cout<<LocalInfirmary[3].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&armourobj,sizeof(armourobj));
memcpy(&armourobj,&LocalInfirmary[3],sizeof(LocalInfirmary[3]));
memcpy(&LocalInfirmary[3],&temp,sizeof(temp));

cout<<armourobj.bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '5' :

if(LocalInfirmary[4].valid==1)
{
cout<<LocalInfirmary[4].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += LocalInfirmary[4].health;
cout<<LocalInfirmary[4].bravo<<endl;
LocalInfirmary[4].valid = 0;
strcpy(LocalInfirmary[4].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case '6' :

cout<<LocalInfirmary[5].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<LocalInfirmary[5].bravo<<endl;
break;

case 't' : backyard(); break;
case 'h' : streets(); break;
case 'i' : inventory(); break;
case 'r' : localinfirmarytext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void streetstext()
{
strcpy(in,"Streets");
cout<<"\n**************************************STREETS***********************************\n";
cout<<"You are out from under the infirmary's roof, out into the streets. You are carefully walking down the path, trying to make no noise. However, you are not in the shadows."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"There are some random things in the street:\n1. "<<Streets[0].title<<"\n2. "<<Streets[1].title<<"\n3. "<<Streets[2].title<<endl; cout<<"From here, you can go to and back to:\nh. CHURCH \nt. LOCAL INFIRMARY"<<endl;
}
void streets()
{
streetstext();
cout<<"\n<PRESS ENTER>"<<endl;
getch();
cout<<"Look! Zombies are coming. You've been spotted.\nHere, they come."<<endl;
battle();
cout<<"And here is another one!"<<endl;
battle();
streetstext();
while(1)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

i++;
if(Streets[0].valid==1)
{
cout<<Streets[0].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&Streets[0],sizeof(Streets[0]));
memcpy(&Streets[0],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '2' :

cout<<Streets[1].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Streets[1].bravo<<endl;
break;

case '3' :

cout<<Streets[2].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Streets[2].bravo<<endl;
break;

case 't' : localinfirmary(); break;
case 'h' : church(); break;
case 'i' : inventory(); break;
case 'r' : streetstext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void churchtext()
{
strcpy(in,"Church");
cout<<"\n**************************************CHURCH************************************\n";
cout<<"The church has been destroyed by zombie attacks. What you see in front was very much different from the time when you used to come here strolling, with your pet dog."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"The following can be seen around:\n1. "<<Church[0].title<<"\n2. "<<Church[1].title<<"\n3. "<<Church[2].title<<"\n4. "<<Church[3].title<<endl<<endl; cout<<"From here, you can go to and back to:\nh. POLICE STATION \nt. STREETS"<<endl;
}
void church()
{
churchtext();
cout<<"\n<PRESS ENTER>"<<endl;
getch();
cout<<"Zombies are coming gain. Get ready."<<endl;
battle();
cout<<"There is a herd of them!"<<endl;
battle();
cout<<"They keep coming, here is another one."<<endl;
battle();
churchtext();
while(1)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

i++;
if(Church[0].valid==1)
{
cout<<Church[0].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&Church[0],sizeof(Church[0]));
memcpy(&Church[0],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '2' :

cout<<Church[1].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Church[1].bravo<<endl;
break;

case '3' :

cout<<Church[2].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<Church[2].bravo<<endl;
break;

case '4' :

if(Church[3].valid==1)
{
cout<<Church[3].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += Church[3].health;
cout<<Church[3].bravo<<endl;
Church[3].valid = 0;
strcpy(Church[3].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case 't' : streets(); break;
case 'h' : ps(); break;
case 'i' : inventory(); break;
case 'r' : churchtext(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void pstext()
{
strcpy(in,"Police Station");
cout<<"\n***********************************POLICE STATION*******************************\n";
cout<<"You have finally reached your destination. This is the place when you are supposed to be extracted from. However, the police station is now a mess. You need to be careful though."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<"You can interact with the following objects:\n1. "<<PS[0].title<<"\n2. "<<PS[1].title<<"\n3. "<<PS[2].title<<"\n4. "<<PS[3].title<<"\n5. "<<PS[4].title<<endl; cout<<"From here, you can go back to:\nt. CHURCH\nc. or CONTINUE"<<endl;
}
void pstext2()
{
strcpy(in,"Police Station");
cout<<"There are some things more in here:\n1. "<<PS[5].title<<"\n2. "<<PS[6].title<<endl;
}
void ps()
{
int boost = 0;
pstext();
cout<<"It's too quiet.";
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"Zombies are coming gain."<<endl;
battle();
pstext();
while(boost==0)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

i++;
if(PS[0].valid==1)
{
cout<<PS[0].descript<<"   <PRESS ENTER>"<<endl;
getch();

memcpy(&temp,&slotobj[sync(i)],sizeof(slotobj[sync(i)]));
memcpy(&slotobj[sync(i)],&PS[0],sizeof(PS[0]));
memcpy(&PS[0],&temp,sizeof(temp));

cout<<slotobj[sync(i)].bravo<<endl;
}
else cout<<"Object not found in the room."<<endl;
break;

case '2' :

if(PS[1].valid==1)
{
cout<<PS[1].descript<<"   <PRESS ENTER>"<<endl;
getch();
if(slotobj[0].dref==1029) { slotobj[0].health += PS[1].maxammo; cout<<PS[1].bravo<<endl; PS[1].valid = 0; }
else if(slotobj[1].dref==1029) { slotobj[1].health += PS[1].maxammo; cout<<PS[1].bravo<<endl; PS[1].valid = 0; }
else cout<<"You don't have the weapon this ammo is required for."<<endl;
break;
}
else cout<<"Crate is empty."<<endl;
break;

case '3' :

cout<<PS[2].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<PS[2].bravo<<endl;
break;

case '4' :

cout<<PS[3].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<PS[3].bravo<<endl;
break;

case '5' :

if(PS[4].valid==1)
{
cout<<PS[4].descript<<"   <PRESS ENTER>"<<endl;
getch();
health += PS[4].health;
cout<<PS[4].bravo<<endl;
PS[4].valid = 0;
strcpy(PS[4].title,"empty");
}
else cout<<"Object is not found in the room."<<endl;
break;

case 't' : church(); break;
case 'i' : inventory(); break;
case 'r' : pstext(); break;
case 'e' : smenu();
case 'c' : boost = 1; break;
default  : cout<<"Please retry."<<endl;
}
}
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"Behooollldd!!! A huge Acid Zombie is heading towards you."<<endl;
battlex();

//escape...

cout<<"How nice you survived!"<<endl;
pstext2();
while(1)
{
cout<<endl<<"\n+>";
cin>>ch;
switch(ch)
{
case '1' :

cout<<PS[5].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<PS[5].bravo<<endl;
break;

case '2' :

cout<<PS[6].descript<<"   <PRESS ENTER>"<<endl;
getch();
cout<<PS[6].bravo<<endl;
cout<<"You found car keys and there is a police vehicle standing by."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"Approach the car."<<endl;
cout<<"<PRESS ENTER> to open the door, and escape>"<<endl;
getch();
cout<<"You escaped!\nThank you for playing the game."<<endl;
getch(); smenu();
break;

case 'i' : inventory(); break;
case 'r' : pstext2(); break;
case 'e' : smenu();
default  : cout<<"Please retry."<<endl;
}
}
}

void inventory()
{
cout<<endl<<"ROOM :"<<endl;
cout<<"      "<<in<<endl;
cout<<"INVENTORY:"<<endl;
cout<<"          HEALTH > "<<health<<endl;
cout<<"          ARMOUR > ANTI-PENETRATION "<<armourobj.armour<<"x"<<endl;
cout<<"          ATTACK > "<<slotobj[0].attack+slotobj[1].attack<<endl;
cout<<"YOU ARE CARRYING: \nWEAPON(S): <"<<slotobj[0].objname<<":"<<slotobj[0].health<<"/"<<slotobj[0].maxammo<<"> <"<<slotobj[1].objname<<":"<<slotobj[1].health<<"/"<<slotobj[1].maxammo<<"> \nARMOUR: <"<<armourobj.objname<<">"<<endl<<endl;
}

void battlex()
{
int p;
cout<<"\n<PRESS ENTER>"<<endl;
getch();

cout<<"Zombie type:    "<<BossZombie.btype<<endl;
cout<<"Zombie health : "<<BossZombie.zhealth<<endl;
cout<<"Zombie attack : "<<BossZombie.zattack<<endl<<"\n<PRESS ENTER>"<<endl;
getch();

while(BossZombie.zhealth>0 && health>0)
{
cout<<"Press 1 to attack with whatever you got.\nPress 2 to try to dodge its attacks."<<endl;
cin>>ch;
switch(ch)
{
case '1' :

randomize(); p = random(2); cout<<"Performing attack with <"<<slotobj[p].objname<<":"<<(((slotobj[p].health)>0)?slotobj[p].health:0)<<"/"<<slotobj[p].maxammo<<">\n";
cout<<"\n<PRESS ENTER>"<<endl; getch();
(slotobj[p].health)--;
if(slotobj[p].health<=0) { slotobj[p].attack = 0.5; cout<<"\nWeapon depleted. Using melee. ATTACK:0.5"<<endl; getch(); }
else cout<<"USES REMAINING: "<<slotobj[p].health<<endl;
BossZombie.zhealth-=(slotobj[p].attack + ((alertflag>0)?-1:0));
health-=(BossZombie.zattack/(2+armourobj.armour)); cout<<"Your Health: "<<((health>0)?health:0)<<"  Zombie's health: "<<(((BossZombie.zhealth)>0)?(BossZombie.zhealth):0)<<endl;
break;

case '2' :

randomize(); if(random(3)==0)
health-=((BossZombie.zattack)/armourobj.armour);
cout<<"Your Health: "<<((health>0)?health:0)<<"  Zombie's health: "<<(((BossZombie.zhealth)>0)?(BossZombie.zhealth):0)<<endl;
break;

case 'e' : smenu();
case 'i' : inventory(); break;

default :

cout<<"You can't have that option. Hurry up, the acid zombie is attacking you."<<endl;
health-=((BossZombie.zattack)/armourobj.armour);
break;
}
}
if (health<=0) { cout<<"Game over! You struggled, but died.\n\n\n<PRESS ENTER>"<<endl; getch(); gameover(); }
cout<<"You killed the zombie."<<endl;
cout<<"Consider checking your health and weapon status. <PRESS ENTER>"<<endl;
getch();
kills++;
points += 30;
}

void battle()
{
int q; int p;
cout<<"\n<PRESS ENTER>"<<endl;
getch();

randomize();
q = sync(random(100)+1);

cout<<"Zombie type:    "<<Zombie[q].btype<<endl;
cout<<"Zombie health : "<<Zombie[q].zhealth<<endl;
cout<<"Zombie attack : "<<Zombie[q].zattack<<endl<<"<PRESS ENTER>"<<endl;
getch();

while(Zombie[q].zhealth>0 && health>0)
{
cout<<"Press 1 to attack with whatever you got.\nPress 2 to try to dodge its attacks."<<endl;
cin>>ch;
switch(ch)
{
case '1' :

randomize(); p = random(2); cout<<"Performing attack with <"<<slotobj[p].objname<<":"<<(((slotobj[p].health)>0)?slotobj[p].health:0)<<"/"<<slotobj[p].maxammo<<">\n";
cout<<"\n<PRESS ENTER>"<<endl; getch();
(slotobj[p].health)--;
if(slotobj[p].health<=0) { slotobj[p].attack = 0.5; cout<<"\nWeapon depleted. Using melee. ATTACK:0.5"<<endl; getch(); }
else cout<<"USES REMAINING: "<<slotobj[p].health<<endl;
Zombie[q].zhealth-=(slotobj[p].attack + ((alertflag>0)?-1:0));
randomize();
if(random(2)==0) health-=(Zombie[q].zattack/(2+armourobj.armour)); cout<<"Your Health: "<<((health>0)?health:0)<<"  Zombie's health: "<<(((Zombie[q].zhealth)>0)?(Zombie[q].zhealth):0)<<endl;
break;

case '2' :

randomize(); if(random(3)==0) health-=((Zombie[q].zattack)/armourobj.armour);
cout<<"Your Health: "<<((health>0)?health:0)<<"  Zombie's health: "<<(((Zombie[q].zhealth)>0)?(Zombie[q].zhealth):0)<<endl;
break;

case 'e' : smenu();
case 'i' : inventory(); break;

default :

cout<<"You can't have that option. Hurry up, the zombie is attacking you."<<endl;
health-=((Zombie[q].zattack)/armourobj.armour);
break;
}
}
if (health<=0) { cout<<"Game over! You died.\nThank you for playing.\n\n<PRESS ENTER>"<<endl; getch(); gameover();}
cout<<"You killed the zombie."<<endl;
cout<<"Consider checking your health and weapon status. <PRESS ENTER>"<<endl;
getch();
kills++;
if(q == 0) points += 10;
else points += 15;
}

void gameover()
{
titlebox();
cout<<"SCORE: "<<points<<endl;
cout<<"ZOMBIES KILLED: "<<kills<<endl;

player.zcount += kills;
if(points>hghscr) hghscr = points;
player.lstscr = points;

cout<<"Current Statistics: \n";
player.putdata();
getch();
file.write((char*)&player, sizeof(player));
smenu();
}

void introd()
{
initialise();
titlebox();
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"A dark world."<<endl;
cout<<"It has been 84 days since the experimental bio-weapon exploded in the Mendel Laboratory, located in NorthWest Downtown of the City, releasing a deadly bioengineered virus in the locality. This virus is turning common people into Zombies. Most of the people have been evacuated from the city, leaving only a few including you and others who couldn't survive and succumbed to transform into zombies. You need to save your life, remain in the shadows, use all available resources and push through to reach the Police Headquarter some 500 metres to your location. You will likely find some help there."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<endl<<endl;
cout<<"Let\'s do this "<<player.pfname<<"!"<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<"You are in a dark room, in your house. Lights must remain off, as not to alert the zombies in the streets of human presence. Hungry, thirsty, too weak to fight, your supplies have exhausted. You need to go out and do something. Go now, and explore: take the things that are necessary."<<endl;
cout<<"\n<PRESS ENTER>"<<endl; getch();
cout<<endl;
cout<<"Things you can do:\npress i for displaying inventory,\npress r for redisplaying room description,\npress e for exitting from the game.\nRest of the interactions can be done through number keys."<<endl;
cout<<"\n<PRESS ENTER>\n";
getch();
livingroom();
}

void titlebox() { clrscr(); cout<<"***********************ZOMBIE APOCALYPSE SURVIVOR ver1.1************************"<<endl<<endl; }

void smenu()
{
titlebox();
file.seekg(0, ios::beg);
cout<<"a. CREATE_NEW/OVERWRITE PROFILE"<<endl;
cout<<"START GAME: "<<endl;
cout<<"b. USE EXISTING PROFILE"<<endl;
cout<<"EXPLORE: "<<endl;
cout<<"c. VIEW STATISTICS"<<endl;
cout<<"d. HALL OF FAME"<<endl;
cout<<"e. CREDITS"<<endl<<endl;
cout<<"q. QUIT"<<endl<<endl;
cout<<"+> ";
cin>>ch;
switch(ch)
{
	case 'a' : flag = 0;
			   titlebox();
			   cout<<endl<<"Enter profile name:\n+> ";
			   gets(str);
			   while(file.read((char*)&player, sizeof(player)))
			   if(!strcmpi(player.pfname,str)) { flag = 1; break; }
			   if(file.eof()) file.clear();
			   if(flag) file.seekg(-(sizeof(player)), ios::cur);
			   player.getdata(0);
			   smenu();
			   break;

	case 'b' : flag = 0;
			   titlebox();
			   cout<<"Existing profiles:\n\n";
			   while(file.read((char*)&player, sizeof(player)))
			   cout<<++i_temp<<". "<<player.pfname<<endl;
			   file.clear();
			   file.seekg(0, ios::beg);
			   cout<<endl<<"Enter profile name:\n+> ";
			   gets(str);
			   while(file.read((char*)&player, sizeof(player)))
			   if(!strcmpi(player.pfname,str)) { flag = 1; break; }
			   if(file.eof()) file.clear();
			   if(flag) { file.seekg(-(sizeof(player)), ios::cur); introd(); }
			   else { cout<<"Try again! <PRESS ENTER>"; getch(); smenu(); }
			   break;

	case 'c' : flag = 0;
			   titlebox();
			   cout<<"Existing profiles:\n\n";
			   while(file.read((char*)&player, sizeof(player)))
			   cout<<++i_temp<<". "<<player.pfname<<endl;
			   file.clear();
			   file.seekg(0, ios::beg);
			   cout<<endl<<"Enter profile name:\n+> ";
			   gets(str);
			   while(file.read((char*)&player, sizeof(player)))
			   if(!strcmpi(player.pfname,str)) { flag = 1; break; }
			   if(file.eof()) file.clear();
			   if(flag) { player.putdata(); getch(); }
			   else { cout<<"Try again! <PRESS ENTER>"; getch(); smenu(); }
			   smenu();
			   break;

	case 'd' : titlebox();
			   while(file.read((char*)&player, sizeof(player))) { player.putdata(); getch(); }
			   cout<<"\n\n<PRESS ENTER>"
			   if(file.eof()) file.clear();
			   smenu();
			   break;

	case 'e' : titlebox();
			   cout<<"Coded, debugged, compiled, executed, played and enjoyed by: AbeshRoy(XIIA1), JayantaPandit(XIIA1) and SourishMandal(XIIA1)"<<endl;
			   getch();
			   smenu();
			   break;

	case 'q' : exit(0);

	default : cout<<"Please try again. <PRESS ENTER>";
			  getch();
			  smenu;
}
}

void main()
{
clrscr();
smenu();
}

void initialise()
{
memcpy(&LivingRoom[0],&torch1000,sizeof(torch1000));
memcpy(&LivingRoom[1],&redbull1001,sizeof(redbull1001));
memcpy(&LivingRoom[2],&tv1002,sizeof(tv1002));
memcpy(&LivingRoom[3],&bed1003,sizeof(bed1003));
memcpy(&LivingRoom[4],&umbrella1004,sizeof(umbrella1004));

memcpy(&Kitchen[0],&stalebread1005,sizeof(stalebread1005));
memcpy(&Kitchen[1],&knife1006,sizeof(knife1006));
memcpy(&Kitchen[2],&cookies1007,sizeof(cookies1007));
memcpy(&Kitchen[3],&fork1008,sizeof(fork1008));
memcpy(&Kitchen[4],&oldjacket1009,sizeof(oldjacket1009));
memcpy(&Kitchen[5],&vinegar1010,sizeof(vinegar1010));
memcpy(&Kitchen[6],&tap1011,sizeof(tap1011));
memcpy(&Kitchen[7],&china1012,sizeof(china1012));
memcpy(&Kitchen[8],&molotov1013,sizeof(molotov1013));
memcpy(&Kitchen[9],&cell1014,sizeof(cell1014));

memcpy(&Backyard[0],&leaf1015,sizeof(leaf1015));

memcpy(&LocalInfirmary[0],&medikit1016,sizeof(medikit1016));
memcpy(&LocalInfirmary[1],&rottenapple1017,sizeof(rottenapple1017));
memcpy(&LocalInfirmary[2],&gun1018,sizeof(gun1018));
memcpy(&LocalInfirmary[3],&policevest1019,sizeof(policevest1019));
memcpy(&LocalInfirmary[4],&bandages1020,sizeof(bandages1020));
memcpy(&LocalInfirmary[5],&books1021,sizeof(books1021));

memcpy(&Streets[0],&rod1022,sizeof(rod1022));
memcpy(&Streets[1],&garbage1023,sizeof(garbage1023));
memcpy(&Streets[2],&car1024,sizeof(car1024));

memcpy(&Church[0],&dagger1025,sizeof(dagger1025));
memcpy(&Church[1],&photo1026,sizeof(photo1026));
memcpy(&Church[2],&dead1027,sizeof(dead1027));
memcpy(&Church[3],&medikit1028,sizeof(medikit1028));

memcpy(&PS[0],&rifle1029,sizeof(rifle1029));
memcpy(&PS[1],&shrapnel1030,sizeof(shrapnel1030));
memcpy(&PS[2],&acidstain1031,sizeof(acidstain1031));
memcpy(&PS[3],&dirt1032,sizeof(dirt1032));
memcpy(&PS[4],&medikit1033,sizeof(medikit1033));
memcpy(&PS[5],&dead1034,sizeof(dead1034));
memcpy(&PS[6],&keys1035,sizeof(keys1035));
}
