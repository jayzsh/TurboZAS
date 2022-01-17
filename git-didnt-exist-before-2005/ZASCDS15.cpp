#include<string.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<graphics.h>
#include<iostream.h>

class Profile
{
	public:

	int pfvalid;
	char pfname[25];
	char password[7];
	int passvalid;
	int mcount;
	int hghscr;
	int lstscr;
	int zcount;

	Profile()
	{
		pfvalid = 1;
		strcpy(pfname, "default_profile");
		passvalid = 0;
		strcpy(password, "000000");
		mcount = 0;
		hghscr = 0;
		lstscr = 0;
		zcount = 0;
	}

	void ini()
	{
		pfvalid = 1;
		strcpy(pfname, "default_profile");
		passvalid = 0;
		strcpy(password, "000000");
		mcount = 0;
		hghscr = 0;
		lstscr = 0;
		zcount = 0;
	}

	void storeCdata(char sstring[], char sstring2[], int cpassvalid)
	{
		pfvalid = 1;
		passvalid = cpassvalid;
		strcpy(pfname, sstring);
		strcpy(password, sstring2);
	}

	void putdata()
	{
		cout<<"PROFILE: "<<pfname<<endl;
		cout<<"TOTAL MATCHES PLAYED: "<<mcount<<endl;
		cout<<"TOTAL ZOMBIES KILLED: "<<zcount<<endl;
		cout<<"HIGHEST SCORE: "<<hghscr<<endl;
		cout<<"LAST SCORE: "<<lstscr<<endl;
		cout<<endl<<"<PRESS ENTER>"<<endl;
	}

	void restorepswrd(char pswrdrecovery[])
	{
		strcpy(password,pswrdrecovery);
	}

	void incmcount()
	{
		(this->mcount)++;
	}

	void deletepf()
	{
		pfvalid = 0;
		strcpy(pfname, "NULL");
		passvalid = 0;
		strcpy(password, "000000");
		mcount = 0;
		hghscr = 0;
		lstscr = 0;
		zcount = 0;
	}
};

class Obj
{
	public:

	char objname[15];
	char title[50];
	char descript[110];
	char bravo[110];
	int dref;
	int valid;
	float armour;
	float health;
	float attack;
	int maxammo;

	Obj(
	char Cobjname[],
	char Ctitle[],
	char Cdescript[],
	char Cbravo[],
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

	char objname[15];
	char title[50];
	char descript[110];
	char bravo[110];
	int dref;
	int valid;
	float armour;
	float health;
	float attack;
	int maxammo;

	RoomSlots(
	char Cobjname[],
	char Ctitle[],
	char Cdescript[],
	char Cbravo[],
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

};       //LivingRoom[],Kitchen[],Backyard[],LocalInfirmary[],Streets[],Church[],PoliceStation[]

class Enemy
{
	public:

	char btype[25];
	float zhealth;
	float zattack;

	Enemy(
	char Cbtype[],
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

Enemy Zombie[3] = {
		  Enemy("LEAN AND THIN ZOMBIE",15,2),
		  Enemy("FAT ZOMBIE",20,3),
		  Enemy("ACID ZOMBIE",100,15)
		  };

//i. DATABASE INI.
fstream file("PLAYPROF.dat", ios::in|ios::out|ios::binary);
Profile player;

//ii. OBJECT INI.
      //livingroom
      Obj infinitystone0999("INFINITY STONE","","You found an Infinity Stone at a secret location.","Picked up Infinity Stone. ATTACK:40.0",999,1,0,999,40.0,999);
      Obj torch1000("LIGHT-TORCH","A PHOSPHORUS TORCH","UTILITY: increase surrounding awareness","You picked up torch, which enhances visibility and thus, attack potential. ATTACK:2.5",1000,1,0,15,2.5,15);
      Obj redbull1001("REDBULL CAN","A REDBULL CAN","Redbull is an Energy Drink!","You got wings. HEALTH:+2.0",1001,1,0,2.0,0,0);
      Obj tv1002("TV","TV MONITOR","TV, turn on/off (!turning on may attract zombies from the streets)","\n",1002,1,0,0,0,0);
      Obj bed1003("BED","BED","Bed? Take a nap.","You took a nap, your vital signs look good. HEALTH:+0.2",1003,1,0,0.2,0,0);
      Obj umbrella1004("UMBRELLA","OLD TORN UMBRELLA","Umbrella, good-to-go weapon.","You picked up UMBRELLA. ATTACK:3.0",1004,1,0,16,3.0,16);

      //kitchen
      Obj stalebread1005("STALE BREAD","SOME STALE BREAD","Stale bread, take a taste","You ate the bread. HEALTH:+2.0",1005,1,0,2.0,0,0);
      Obj knife1006("KNIFE","A BUTCHER'S KNIFE","Zombie-Butcher!","You picked up a knife. ATTACK:6.0",1006,1,0,12,6.0,12);
      Obj cookies1007("COOKIES","SCATTERED BAKED COOKIES","Fresh cookies, have some maybe?","You ate cookies. HEALTH:+3.0",1007,1,0,3.0,0,0);
      Obj fork1008("FORK","A FORK ON THE CROKERY HANGER","Fork?...is a very small weapon.","You picked up a fork. ATTACK:1.5",1008,1,0,5,1.5,5);
      Obj oldjacket1009("OLD JACKET","AN OLD JACKET","Thick, old, jacket. Hard to penetrate.","You put the jacket on. ARMOUR LEVEL 1",1009,1,1.08,0,0,0);
      Obj vinegar1010("VINEGAR","SPILLED VINEGAR","Vinegar has strong stench. Apply to cover scent and distract attacking zombies.","You used Vinegar. HEALTH:+0.80",1010,1,0,0.8,0,0);
      Obj tap1011("WATER TAP","LEAKING WATER TAP","Drink Water.","You drank water. HEALTH:+0.25",1011,1,0,0.25,0,0);
      Obj china1012("CHINAWARE","CHINAWARE ON THE CROCKERY HANGER","Examine.","Expensive, shiny, china bowl.",1012,1,0,0,0,0);
      Obj molotov1013("MOLOTOVS","PETROL BOMBS","Explosives, what are you thinking?","You picked up Molotovs. ATTACK:7.0",1013,1,0,4,7,4);
      Obj cell1014("CELL PHONE","CELL PHONE NEAR THE STOVE","Examine.","Battery is dead. Cell phone cannot be used.",1014,1,0,0,0,0);

      //backyard
      Obj leaf1015("LEAF","GREEN MAPLE LEAF","Maple leaf has medicinal value.","You extracted health. HEALTH:+10.0",1015,1,0,10,0,0);

      //localinfirmary
      Obj medikit1016("MEDIKIT","MEDIKIT ON THE DESK","Medikit will help you gain health.","You gained health. HEALTH:+15.0",1016,1,0,15,0,0);
      Obj rottenapple1017("APPLE","AN APPLE ON THE FLOOR","Pick it up.","The Apple is too rotten to be eaten.",1017,1,0,0,0,0);
      Obj gun1018("DESERT EAGLE","A COLT PISTOL","It's a loaded Desert Eagle pistol!","You picked up a pistol. ATTACK:10.0",1018,1,0,15,10,15);
      Obj policevest1019("POLICE-VEST","BLOOD STAINED POLICE-VEST","Police-Vest is a Professional Armour.","You put Polive-vest on. ARMOUR LEVEL 2",1019,1,1.15,0,0,0);
      Obj bandages1020("BANDAGES","A PAIR OF BANDAGES","You gain health when you apply bandages.","You applied bandages. HEALTH:+2.0",1020,1,0,2.0,0,0);
      Obj books1021("BOOKS","BOOKS ON THE SHELF","Read Contents.","Books of a medical practitioner.",1021,1,0,0,0,0);

      //streets
      Obj rod1022("IRON ROD","A BROKEN IRON ROD","It's heavy and broken sharp at one end... could be a weapon.","You picked up the rod. ATTACK:8.0",1022,1,0,50,8,50);
      Obj garbage1023("GARBAGE","AN ERECT GARBAGE TIN BY THE SIDE OF THE STREET","Look in.","There is a slurry of orange zombie blood.",1023,1,0,0,0,0);
      Obj car1024("CAR","A BROKEN DOWN CAR AT THE END OF THE STREET","Look into it.","Dead person on the seat, infected with the zombie virus.\nWill turn into a zombie soon.",1024,1,0,0,0,0);

      //church
      Obj dagger1025("DAGGER","A DAGGER","Dagger is sharp to cut.","You picked up the dagger. ATTACK:8.0",1025,1,0,30,8,30);
      Obj photo1026("PHOTOGRAPH","PHOTOGRAPH ON THE WALL","Take a look.","Painting of \'The Last Supper\'.",1026,1,0,0,0,0);
      Obj dead1027("DEAD","A DEAD BODY NEAR THE ALTAR","Take a close look.","The body has been melted with what seems to be a kind of smoking, green slurry.",1027,1,0,0,0,0);
      Obj medikit1028("MEDIKIT","MEDIKIT","Medikit will help you gain health.","You gained health. HEALTH+15.0",1028,1,0,15,0,0);

      //ps
      Obj rifle1029("WINCHESTER-94","A RIFLE","WINCHESTER-94 SHRAPNEL THROWER is a professional zombie killer!","You picked up the Winchester Rifle. ATTACK:15.0",1029,1,0,0,15,25);
      Obj shrapnel1030("AMMO","AMMO CRATE","Open.","You picked up 12 shrapnels for Win-94.",1030,1,0,20,0,12);
      Obj acidstain1031("STAIN","SOME GREEN STAIN ON THE FLOOR,","Examine.","There have been acid stains before. Why are they here?",1031,1,0,0,0,0);
      Obj dirt1032("DIRT","UNUSUAL GOOEY DIRT ON THE FLOOR AT ANOTHER PLACE","Examine.","The lumps have presence of zombie-blood.",1032,1,0,0,0,0);
      Obj medikit1033("MEDIKIT","AN UNLOCKED MEDIKIT","Medikit will help you gain health.","You gained health. HEALTH:+15.0",1033,1,0,15,0,0);
      Obj dead1034("DEAD","ANOTHER DEAD BODY (OF A POLICEMAN)","Examine.","His pocket might have car keys. He was trying to escape.\nThere is a police car parked outside.",1034,1,0,0,0,0);
      Obj keys1035("KEYS","SOMETHING UNDER THE OFFICER'S HAND","Examine.","Car Keys.",1035,1,0,0,0,0);

//FIRST PERSON GLOBAL PARAMETERS
	 float health = 10;
	 Obj slotobj[2] = {Obj("hand is free","empty","empty","empty",0,0,0.0,0.0,1.0,0),
	 Obj("hand is free","empty","empty","empty",0,0,0.0,0.0,1.0,0)};
	 Obj armourobj("empty","empty","empty","empty",0,0,1.0,0.0,0.0,0);
	 int points = 0;
	 int kills = 0;
	 char in[20];

//default OBJECT STATIONS INI.
     RoomSlots LivingRoom[6];
     RoomSlots Kitchen[10];
     RoomSlots Backyard[1];
     RoomSlots LocalInfirmary[10];
     RoomSlots Streets[3];
     RoomSlots Church[4];
     RoomSlots PS[8];

//MISC. VARIABLES
	 char ch=' ';
	 char str[30];
	 char gpassword[15];
	 char gpassvalid;
	 char input[15];
	 int i_temp;
	 int alertflag = 0;
	 int flag = 0;
	 int c = 0;
	 Obj temp;
	 int _swap;

//FUNCTIONS INI.
	 void infoscrn(void);
	 void loadscrn(void);
	 void initialise(void);
	 void smenu(void);
	  int noprofile(void);
	 void updatestat(void);

	 void titlebox(void);
	 char cmdinp(char);
	 
	 void introd(void);
	 void inventory(void);
	  int ceil(float);
	 void numbar(float, int);
	 void askswap(void);
	 void battle(int);
	 void gameover(void);
	 void replenish(int);
	 
	 void zkillACue(void);
	 void gamelostACue(void);
	 void gamewinACue(void);

	 void livingroom(void);
	 void kitchen(void);
	 void backyard(void);
	 void localinfirmary(void);
	 void streets(void);
	 void church(void);
	 void ps(void);
	 
	 void livingroomtext(void);
	 void kitchentext(void);
	 void backyardtext(void);
	 void localinfirmarytext(void);
	 void streetstext(void);
	 void churchtext(void);
	 void pstext(int);


//FUNCTION DEFINITIONS
void main() { infoscrn(); loadscrn(); while(1) smenu(); }

void infoscrn()
{
	system("CLS");
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	system("CLS");
	setbkcolor(4);
	for(int i=1;i<=35;i++) cout<<char(219);
	cout<<"> README <";
	for(int j=1;j<=35;j++) cout<<char(219);
	cout<<endl;
	cout<<"                      CENTRAL BOARD OF SECONDARY EDUCATION\n                   ANNUAL COMPUTER SCIENCE PROJECT EVALUATION\n\t\t\t   STD. XII : SESSION 2019-20"<<endl<<endl;
	cout<<"This project has been developed by students of DAV MODEL SCHOOL, DURGAPUR:"<<endl;
	cout<<" "<<(char)5<<"  Abesh Roy     , XII A1 <GAME CODE; SOUND; GRAPHICS; DEBUGGING> \n "<<char(5)<<"  Jayanta Pandit, XII A1 <GAME CODE; GRAPHICS; DATABASE; DEBUGGING>\n "<<char(5)<<"  Sourish Mandal, XII A1 <GAME CODE; STORY; DEBUGGING; EDITING>"<<endl<<endl;
	cout<<"PROJECT : Single Player Text-based Adventure/Survival Game using Turbo C++"<<endl;
	cout<<"BYTENAME (what we like to call it) : ZOMBIE APOCALYSE SURVIVOR VER1.1"<<endl<<endl;
	cout<<"PROJECT DESCRIPTION :"<<endl<<endl;
	cout<<"VER1.0 ended up implementing one of the most challenging ideas of using structure variables as real life objects in the game. This upgraded VER1.1 includes the requisite update to the use of OOP instead of the older SOP, audio cues and integrated graphics using EGAVGA.BGI module of the TURBOC LIBRARY.";
	cout<<" The new implementations include an excessively wide range of class concept derivatives viz. file handling to save player profiles, and arrays (used throughout), as well as use of GRAPHICS.h and DOS.h headers. <PRESS ENTER> and enjoy playing."<<endl;
	cout<<endl<<" ";
	for(i=1;i<=78;i++) cout<<char(219);
	getch();
	closegraph();
}

void loadscrn()
{
	int gd2 = DETECT, gm2;
	initgraph(&gd2,&gm2,"c:\\turboc3\\bgi");
	int c = 67, x = 310, y = 185;
	setbkcolor(0);
	for (int i = 1; i <= c; i++)
		{
			clrscr();
			int points[]=
			{
				x-75,y+125,x-100,y-75,x-75,y-67,x-72,y-84,x-69,y-94,x-50,y-119,
				x-8,y-140,x+40,y-138,x+64,y-127,x+78,y-115,x+90,y-99,x+100,y-75,
				x+125,y-60,x+100,y+125,x+35,y+125,x+35,y+100,x+30,y+5,x+25,y+18,
				x+32,y-75,x+19,y-87,x+24,y-76,x+18,y-48,x+18,y-75,x-8,y-89,x+3,
				y-75,x+3,y-46,x-13,y-80,x-45,y-78,x-23,y-75,x-10,y-48,x-35,y-65,
				x-52,y-50,x-33,y-52,x-15,y-30,x-15,y-10,x-32,y-5,x-50,y-18,x-36,
				y+9,x-13,y+13,x-13,y+27,x-16,y+23,x-18,y+125,x-75,y+125
			};
			setcolor(0);
			setfillstyle(1,0);
			bar(x-115,y-155,x+138,y+190);
			setcolor(0);
			setfillstyle(9,15);
			fillpoly(43,points);
			setcolor(0);
			setfillstyle(1,0);
			fillellipse(x-40,y+125,25,25);
			fillellipse(x-10,y+120,25,25);
			fillellipse(x+25,y+135,25,25);
			fillellipse(x+55,y+125,25,25);
			setcolor(15);
			settextstyle(0,HORIZ_DIR,4);
			outtextxy(x-82,y+145,"ZOMBIE");
			settextstyle(0,HORIZ_DIR,1);
			outtextxy(x-78,y+178,"APOCALYPSE SURVIVOR 1.1");
			line(x-115,y+135,x+138,y+135);
	
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n       ";
			for (int j = 1; j <= i; j++) { if(i == 1) break; cout<<char(178); }
			for (int k = i+1; k <= c; k++) { cout<<char(176); }
			cout<<endl;
			if(i == 1) { cout<<"\t\t\t      Waiting to Load..."; delay(1000); }
			else if(i<67)
			cout<<"\t\t\t\tLoading...( "<<int(i/67.0*100.0)<<"% )";
			else
			{
				cout<<"\t\t\t\tLoading...( "<<int(i/67.0*100.0)<<"% )"<<endl;
				cout<<"\t\t       < LOADING COMPLETE : PRESS ENTER >";
			}
			delay(25);
		}
	getch();
}

void initialise()
{
	memcpy(&LivingRoom[0],&torch1000,sizeof(torch1000));
	memcpy(&LivingRoom[1],&redbull1001,sizeof(redbull1001));
	memcpy(&LivingRoom[2],&tv1002,sizeof(tv1002));
	memcpy(&LivingRoom[3],&bed1003,sizeof(bed1003));
	memcpy(&LivingRoom[4],&umbrella1004,sizeof(umbrella1004));
	memcpy(&LivingRoom[5],&infinitystone0999,sizeof(infinitystone0999));

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

void smenu()
{
	clrscr();
	titlebox();
	flag = 0;
	int _cpass;
	i_temp = 0;
	c = 0;
	char dec;
	int i_o;
	file.seekg(0, ios::beg);
	cout<<"\t\t\t  <-A-> <-CREATE_NEW_PROFILE->"<<endl<<endl;
	cout<<"\t\t\t\t  :START GAME: "<<endl<<endl;
	cout<<"\t\t\t <-B-> <-USE_EXISTING_PROFILE->"<<endl<<endl;
	cout<<"\t\t\t\t   :EXPLORE: "<<endl<<endl;
	cout<<"\t\t\t<-C-> <-ERASE_EXISTING_PROFILE->"<<endl<<endl;
	cout<<"\t\t\t   <-D->  <-VIEW_STATISTICS->"<<endl<<endl;
	cout<<"\t\t\t     <-E-> <-HALL_OF_FAME->"<<endl<<endl;
	cout<<"\t\t\t       <-F->  <-CREDITS->"<<endl<<endl;
	cout<<"\t\t\t         <-Q-> <-QUIT->"<<endl<<endl<<endl;
	cout<<"\t\t\t+> ";
	ch = cmdinp('m');
	switch(ch)
	{
		case 'a' : flag = 0;
				   dec=' ';
				   i_o=1;
				   _cpass=0;
				   gpassvalid=0;
				   clrscr();
				   titlebox();
				   cout<<endl<<"Enter profile name:\n    +> ";
				   gets(str);
				   if (strlen(str)>20 || strlen(str)<1)
				   {
					   cout<<"Max. and min. characters are 20 and 1, repectively. Please try again.\n<PRESS ENTER>";
					   getch();
					   smenu();
				   }

				   while(file.read((char*)&player, sizeof(player)))
				   { c++; if(player.pfvalid && !strcmpi(player.pfname,str)) { cout<<"Profile name already exists. Please try again.\n<PRESS ENTER>"; getch(); i_o=0; break; } }

				   for (int i=5 ; (dec!='Y' && dec!='y' && dec!='N' && dec!='n' && i_o==1) ; i++)
				   {
						cout<<"\nDo you want to protect your profile with a password <Y/N> ? ";
						cin>>dec;
						if (dec=='Y' || dec=='y')
						{
							cout<<"Enter new password of 6 characters : "; gets(gpassword);
							for (int j=5;j>1 && (strlen(gpassword)!=6);j++)
							{
								cout<<"Password should be of 6 characters. Enter password again : ";
								gets(gpassword);
								if(strlen(gpassword)==6) { gpassvalid=1; break; }
							}
							gpassvalid=1;
							_cpass=1;
						}
						else if(dec!='Y' && dec!='y' && dec!='N' && dec!='n') { cout<<"Wrong choice!\n<PRESS ENTER>\n"; getch(); break; }
						else { _cpass=2; gpassvalid=0; }
				   }

				   if(file.eof()) file.clear();
				   if(_cpass)
				   {
						player.ini();
						player.storeCdata(str,gpassword,gpassvalid);
						updatestat();
						cout<<"\nNew profile is created.\n<PRESS ENTER>";
						getch();
				   }
				   smenu();
				   break;

		case 'b' : flag = 0;
				   clrscr();
				   titlebox();
				   _cpass=0;
				   if(noprofile()) break;
				   cout<<"Existing profiles:\n\n";
				   while(file.read((char*)&player, sizeof(player)))
				   if(player.pfvalid) cout<<++i_temp<<". "<<player.pfname<<endl;
				   file.clear();
				   file.seekg(0, ios::beg);
				   cout<<endl<<"Enter profile name:\n    +> ";
				   gets(str);
				   i_temp = 0;
				   while(file.read((char*)&player, sizeof(player)))
				   {
						c++;
						if(player.pfvalid && !strcmpi(player.pfname,str))
						{
							flag = 1;
							if(player.passvalid==1)
							{
								cout<<"Enter profile password : ";
								gets(gpassword);
								if(!strcmp(player.password,gpassword)) { _cpass=1; break; }
								else { break; }
							}
							else { _cpass=1; break; }
						}
				   }
				   if(file.eof()) file.clear();
				   if(flag && _cpass) { cout<<"\nWelcome!"; delay(800); file.seekg((c-1)*(sizeof(player))); introd(); }
				   else if(flag && _cpass==0) { cout<<"Incorrect Password. Please try again.\n<PRESS ENTER>\n"; getch(); }
				   else { cout<<"Player not found. Try again! <PRESS ENTER>"; getch(); }
				   smenu();
				   break;

		case 'c' : flag = 0;
				   clrscr();
				   titlebox();
				   _cpass=0;
				   if(noprofile()) break;
				   cout<<"Existing profiles:\n\n";
				   while(file.read((char*)&player, sizeof(player)))
				   if(player.pfvalid) cout<<++i_temp<<". "<<player.pfname<<endl;
				   file.clear();
				   i_temp = 0;
				   file.seekg(0, ios::beg);
				   cout<<endl<<"Enter profile to be removed:\n    +> ";
				   gets(str);
				   i_o=0;
				   while(file.read((char*)&player, sizeof(player)))
				   {
						c++;
						if(player.pfvalid && !strcmpi(player.pfname,str))
						{
							flag = 1;
							if(player.passvalid==1)
							{
								cout<<"Enter profile password : ";
								gets(gpassword);
								if(!strcmp(player.password,gpassword)) { _cpass=1; break; }
								else { break; }
							}
							else { _cpass=1; break; }
						}
						else i_o=1;
				   }
				   if(file.eof()) file.clear();
				   if(flag && _cpass) { file.seekg((c-1)*(sizeof(player))); player.deletepf(); updatestat();
				   cout<<"Profile is succesfully deleted.\n<PRESS ENTER>";getch(); smenu(); }
				   else if(flag && _cpass==0) { cout<<"Incorrect Password. Please try again.\n<PRESS ENTER>\n"; getch(); smenu(); }
				   else if(i_o) { cout<<"Player not found. Try again! <PRESS ENTER>"; getch(); smenu(); }
				   break;

		case 'd' : flag = 0;
				   clrscr();
				   titlebox();
				   if(noprofile()) break;
				   cout<<"Existing profiles:\n\n";
				   while(file.read((char*)&player, sizeof(player)))
				   if(player.pfvalid) cout<<++i_temp<<". "<<player.pfname<<endl;
				   file.clear();
				   i_temp = 0;
				   file.seekg(0, ios::beg);
				   cout<<endl<<"Enter profile name:\n    +> ";
				   gets(str);
				   while(file.read((char*)&player, sizeof(player)))
				   if(player.pfvalid && !strcmpi(player.pfname,str)) { flag = 1; break; }
				   if(file.eof()) file.clear();
				   if(flag) { cout<<endl; player.putdata(); getch(); }
				   else { cout<<"Player not found. Try again! <PRESS ENTER>"; getch(); smenu(); }
				   smenu();
				   break;

		case 'e' : clrscr();
				   titlebox();
				   if(noprofile()) break;
				   while(file.read((char*)&player, sizeof(player))) { if(player.pfvalid) { player.putdata(); getch(); } }
				   cout<<"\n\n<PRESS ENTER>\n\n";
				   if(file.eof()) file.clear();
				   smenu();
				   break;

		case 'i' : clrscr();
				   titlebox();
				   while(file.read((char*)&player, sizeof(player))) { cout<<"PFVALID: "<<player.pfvalid<<" PASSVALID: "<<player.passvalid<<" PASSWORD: "<<player.password<<endl; player.putdata(); getch(); }
				   cout<<"\n\n<PRESS ENTER>\n\n";
				   if(file.eof()) file.clear();
				   smenu();
				   break;

		case 'f' : clrscr();
				   titlebox();
				   setbkcolor(6);
				   cout<<"   Developed, mapped, designed, composed, coded, debugged, and compiled by :\n\n\t(1) Abesh Roy,\n\n\t(2) Jayanta Pandit and\n\n\t(3) Sourish Mandal";
				   getch();
				   smenu();
				   break;

		case 'q' : exit(0);

		default  : cout<<"Please provide a valid choice.   <PRESS ENTER>";
				   getch();
				   smenu();
	}
}

int noprofile()
{
	c=0;
	file.seekg(0, ios::end);
	if(!file.tellg()) { cout<<"No existing profiles found.\nPlease create a new one and come back to continue :)\n<PRESS ENTER>"; getch(); file.seekg(0); return 1; }
	file.seekg(0);
	while(file.read((char*)&player, sizeof(player)))
	if(player.pfvalid) { file.seekg(0); return 0; }
	cout<<"No existing profiles found.\nPlease create a new one and come back to continue :)\n<PRESS ENTER>";
	getch();
	file.seekg(0);
	if(file.eof()) file.clear();
	return 1;
}

void updatestat() { file.write((char*)&player, sizeof(player)); player.ini(); file.seekg(0); }

void titlebox()
{
	clrscr();
	system("CLS");
	setbkcolor(RED);
	for(int i = 1; i <= 23; i++) cout<<char(219);
	cout<<"> ZOMBIE APOCALYPSE SURVIVOR 1.1 <";
	for(i = 1; i <= 23; i++) cout<<char(219);
	cout<<endl<<endl;
}

char cmdinp(char iota)
{
	gets(input);
	if(iota == 'g')
	{
		     if(!strcmpi(input,"1")) return '1';
		else if(!strcmpi(input,"2")) return '2';
		else if(!strcmpi(input,"3")) return '3';
		else if(!strcmpi(input,"4")) return '4';
		else if(!strcmpi(input,"5")) return '5';
		else if(!strcmpi(input,"6")) return '6';
		else if(!strcmpi(input,"7")) return '7';
		else if(!strcmpi(input,"8")) return '8';
		else if(!strcmpi(input,"9")) return '9';
		else if(!strcmpi(input,"0")) return '0';
		else if(!strcmpi(input,"i")) return 'i';
		else if(!strcmpi(input,"e")) return 'e';
		else if(!strcmpi(input,"r")) return 'r';
		else if(!strcmpi(input,"h")) return 'h';
		else if(!strcmpi(input,"t")) return 't';
		else if(!strcmpi(input,"c")) return 'c';
		else if(!strcmpi(input,"infinityfun")) return 'z';
		else if(!strcmpi(input,"icanjump")) return 'y';
		else if(!strcmpi(input,"makemehealthy")) return 'm';
		else return 'x';
	}
	else if(iota == 'b')
	{
		     if(!strcmpi(input,"1")) return '1';
		else if(!strcmpi(input,"2")) return '2';
		else return 'x';
	}
	else if(iota == 'm')
	{
		 	  if(!strcmpi(input,"a")) return 'a';
		 else if(!strcmpi(input,"b")) return 'b';
		 else if(!strcmpi(input,"c")) return 'c';
		 else if(!strcmpi(input,"d")) return 'd';
		 else if(!strcmpi(input,"e")) return 'e';
		 else if(!strcmpi(input,"f")) return 'f';
		 else if(!strcmpi(input,"q")) return 'q';
		 else if(!strcmpi(input,"i")) return 'i';
	}
}

void introd()
{
	initialise();
	replenish(2);
	titlebox();
	setbkcolor(BLUE);
	cout<<"\n<PRESS ENTER>"<<endl<<endl; getch();
	cout<<"A dark world."<<endl;
	cout<<"It has been 84 days since the experimental bio-weapon exploded in the Genetics Research Laboratory, located in NorthWest Downtown of the City, releasing a deadly bioengineered virus in the locality. This virus is turning common people into Zombies. Most of the people have been evacuated from the city, leaving only a few including you and others who couldn't survive and succumbed to transform into the living dead. You need to save your life, remain in the shadows, use all available resources and push through to reach the Police Headquarter some 500 metres to your location. You will likely find some help there."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch();
	cout<<endl;
	cout<<"Let\'s do this "<<player.pfname<<"!"<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch();
	cout<<endl<<"You are in a dark room, in your house. Lights must remain off, as not to alert the zombies in the streets of human presence. You are hungry, thirsty, and too weak to fight. Your supplies have exhausted. You need to go out and do something. Go now, and explore: take the things that are necessary."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch();
	cout<<endl;
	cout<<"Things you can do:\n Press I for displaying inventory\n Press R for redisplaying room description\n Press E for exiting from the game.\n Rest of the interactions can be done through number keys."<<endl;
	cout<<"\n<PRESS ENTER>\n";
	getch();
	livingroom();
}

void inventory()
{
	cout<<endl<<"ROOM :"<<endl;
	cout<<"      "<<in<<endl;
	cout<<"INVENTORY:"<<endl;
	cout<<"          HEALTH > ";
	numbar(health, 80);
	cout<<endl;
	if(armourobj.armour>1)
	{
		cout<<"          ARMOUR > LEVEL ";
		if(armourobj.armour<1.1) cout<<"1";
		else cout<<2;
		cout<<endl;
	}
	cout<<"          ATTACK > "<<slotobj[0].attack+slotobj[1].attack<<endl;
	cout<<"YOU ARE CARRYING: \nWEAPON(S): <"<<slotobj[0].objname<<":"<<((slotobj[0].health<=0)?0:slotobj[0].health)<<"/"<<slotobj[0].maxammo<<"> <"<<slotobj[1].objname<<":"<<((slotobj[1].health<=0)?0:slotobj[1].health)<<"/"<<slotobj[1].maxammo<<">";
	cout<<endl<<"ARMOUR: <"<<armourobj.objname<<">"<<endl;
}

int ceil(float _fmp) { return (int(_fmp)+1); }

void numbar(float lim1, int lim2)
{
	int counter;
	counter = 1;
	cout<<"< ";
	while(counter<=ceil(lim1/2.5)) { if(lim1==0) break; cout<<(char)178; counter++; }
	while(counter<=(int)(lim2/2.5)) { cout<<(char)176; counter++; }
	cout<<" >";
}

void askswap()
{
	char _k;
	cout<<endl<<"CHOOSE SLOT : "<<endl;
	cout<<"(1) <"<<slotobj[0].objname<<":"<<slotobj[0].health<<"/"<<slotobj[0].maxammo<<">"<<endl;
	cout<<"(2) <"<<slotobj[1].objname<<":"<<slotobj[1].health<<"/"<<slotobj[1].maxammo<<">"<<endl;
	cout<<"\n    +> ";
	cin>>_k;
	if(_k!='1' && _k!='2') { cout<<"Please retry."; askswap(); }
	else _swap = ((_k=='1')?0:1);
	_k=0;
	cout<<endl;
}

void battle(int fmp)
{
	if(fmp==0)
	{
		int q; int p;
		cout<<"\n<PRESS ENTER>"<<endl<<endl;
		getch();

		randomize();
		q = random(1000)%2;

		cout<<"Zombie type:    "<<Zombie[q].btype<<endl;
		cout<<"Zombie health : "<<Zombie[q].zhealth<<endl;
		cout<<"Zombie attack : "<<Zombie[q].zattack<<endl<<endl<<"<PRESS ENTER>"<<endl;
		getch();

		while(Zombie[q].zhealth>0 && health>0)
		{
			cout<<"\nPress 1 to attack.\nPress 2 to try to dodge its attacks."<<endl;
			cout<<"\n    +> ";
			ch = cmdinp('b');
			switch(ch)
			{
				case '1' :

					randomize(); p = random(1000)%2; cout<<"\nPerforming attack with <"<<slotobj[p].objname<<":"<<(((slotobj[p].health)>0)?slotobj[p].health:0)<<"/"<<slotobj[p].maxammo<<">";
					cout<<"   <PRESS ENTER>"<<endl; getch();
					if(slotobj[p].health<=0) { slotobj[p].attack = 1.0; if(slotobj[p].dref!=0) cout<<"\nWeapon depleted. "; cout<<"Using melee. ATTACK:1.0"<<endl; getch(); }
					else cout<<"USES REMAINING: "<<slotobj[p].health-1<<endl;
					slotobj[p].health--;
					Zombie[q].zhealth-=(slotobj[p].attack + ((alertflag>0)?-0.5:0));
					randomize();
					if((random(1000)%2)==0) health-=(Zombie[q].zattack/(2+armourobj.armour));
					cout<<endl<<"Your Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;;
					cout<<endl<<"Zombie's health: ";
					((((Zombie[q].zhealth)>0)?numbar(Zombie[q].zhealth,((q==0)?15:20)):numbar(0,((q==0)?15:20))));
					cout<<endl<<endl;
					break;

				case '2' :

					randomize(); if((random(1000)%3)==0) health-=((Zombie[q].zattack)/armourobj.armour);
					cout<<"\nYour Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;
					cout<<"Zombie's health: ";
					(((Zombie[q].zhealth)>0)?numbar(Zombie[q].zhealth,((q==0)?15:20)):numbar(0,((q==0)?15:20)));
					cout<<endl<<endl;
					break;

				case 'e' : gameover(); smenu();
				case 'i' : inventory(); break;

				default :

					cout<<"\nYou can't have that option. Hurry up, the zombie is attacking you."<<endl<<endl;
					health-=((Zombie[q].zattack)/armourobj.armour);
					cout<<"Your Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;
					cout<<"Zombie's health: ";
					(((Zombie[q].zhealth)>0)?numbar(Zombie[q].zhealth,((q==0)?15:20)):numbar(0,((q==0)?15:20)));
					cout<<endl<<endl;
					break;
			}
		}
		if (health<=0) { cout<<"Game over! You died.\n<PRESS ENTER>"<<endl; gamelostACue();getch(); gameover(); smenu(); }
		cout<<"You killed the zombie."<<endl; zkillACue();
		cout<<"Consider checking your health and weapon status. <PRESS ENTER>"<<endl;
		getch();
		kills++;
		if(q == 0) points += 10;
		else points += 15;
		replenish(1);
		}

	else
	{
		int p;
		cout<<"\n<PRESS ENTER>"<<endl<<endl;
		getch();

		cout<<"Zombie type:    "<<Zombie[2].btype<<endl;
		cout<<"Zombie health : "<<Zombie[2].zhealth<<endl;
		cout<<"Zombie attack : "<<Zombie[2].zattack<<endl<<"\n\n<PRESS ENTER>"<<endl<<endl;
		getch();

		while(Zombie[2].zhealth>0 && health>0)
		{
			cout<<"\nPress 1 to attack.\nPress 2 to try to dodge its attacks."<<endl;
			cout<<"\n    +> ";
			ch = cmdinp('b');
			switch(ch)
			{
				case '1' :

					randomize(); p = random(1000)%2; cout<<"Performing attack with <"<<slotobj[p].objname<<":"<<(((slotobj[p].health)>0)?slotobj[p].health:0)<<"/"<<slotobj[p].maxammo<<">";
					cout<<"   <PRESS ENTER>"<<endl; getch();
					if(slotobj[p].health<=0) { slotobj[p].attack = 1.0; if(slotobj[p].dref!=0) cout<<"\nWeapon depleted. "; cout<<"Using melee. ATTACK:1.0"<<endl; getch(); }
					else cout<<"USES REMAINING: "<<slotobj[p].health-1<<endl;
					(slotobj[p].health)--;
					Zombie[2].zhealth-=(slotobj[p].attack + ((alertflag>0)?-0.5:0));
					health-=(Zombie[2].zattack/(2+armourobj.armour));
					cout<<"Your Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;
					cout<<"Zombie's health: ";
					(((Zombie[2].zhealth)>0)?numbar(Zombie[2].zhealth,100):numbar(0,100));
					cout<<endl<<endl;
					break;

				case '2' :

					randomize(); if((random(1000)%3)==0)
					health-=((Zombie[2].zattack)/armourobj.armour);
					cout<<"\nYour Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;
					cout<<"Zombie's health: ";
					(((Zombie[2].zhealth)>0)?numbar(Zombie[2].zhealth,100):numbar(0,100));
					cout<<endl<<endl;
					break;

				case 'e' : gameover(); smenu();
				case 'i' : inventory(); break;

				default :
			
					cout<<"\nYou can't have that option. Hurry up, the acid zombie is attacking you."<<endl<<endl;
					health-=((Zombie[2].zattack)/armourobj.armour);
					cout<<"Your Health:     ";
					((health>0)?numbar(health, 80):numbar(0,80));
					cout<<endl<<endl;
					cout<<"Zombie's health: ";
					(((Zombie[2].zhealth)>0)?numbar(Zombie[2].zhealth,100):numbar(0,100));
					cout<<endl<<endl;
					break;
			}
		}
		if (health<=0) { cout<<"Game over! You struggled, but died.\n\n\n<PRESS ENTER>"<<endl; gamelostACue(); getch(); gameover(); smenu(); }
		cout<<"You killed the zombie."<<endl; zkillACue();
		cout<<"Consider checking your health and weapon status. <PRESS ENTER>"<<endl;
		getch();
		kills++;
		points += 50;
		replenish(1);
	}
}

void gameover()
{
	system("CLS");
	titlebox();
	cout<<"Thank you for playing.\n\n";
	cout<<"SCORE: "<<points<<endl;
	cout<<"ZOMBIES KILLED: "<<kills<<endl;

	player.zcount += kills;
	if(points>player.hghscr) player.hghscr = points;
	player.lstscr = points;

	cout<<endl<<"Current Statistics: "<<endl;

	player.restorepswrd(gpassword);
	player.incmcount();
	player.putdata();
	getch();
	file.write((char*)&player,sizeof(player));
	player.ini();
	smenu();
}

void replenish(int param_)
{
	if(param_ == 1) { Zombie[0].zhealth = 15; Zombie[1].zhealth = 20; }
	else {

		Zombie[0].zhealth = 15;
		Zombie[1].zhealth = 20;
		Zombie[2].zhealth = 100;
		health = 10;

		alertflag = 0;

		strcpy(slotobj[0].objname, "hand is free");
		strcpy(slotobj[0].title, "empty");
		strcpy(slotobj[0].descript, "empty");
		strcpy(slotobj[0].bravo, "empty");
		slotobj[0].dref = 0;
		slotobj[0].valid = 0;
		slotobj[0].armour = 0.0;
		slotobj[0].health = 0.0;
		slotobj[0].attack = 1.0;
		slotobj[0].maxammo = 0;

		strcpy(slotobj[1].objname, "hand is free");
		strcpy(slotobj[1].title, "empty");
		strcpy(slotobj[1].descript, "empty");
		strcpy(slotobj[1].bravo, "empty");
		slotobj[1].dref = 0;
		slotobj[1].valid = 0;
		slotobj[1].armour = 0.0;
		slotobj[1].health = 0.0;
		slotobj[1].attack = 1.0;
		slotobj[1].maxammo = 0;

		strcpy(armourobj.objname, "empty");
		strcpy(armourobj.title, "empty");
		strcpy(armourobj.descript, "empty");
		strcpy(armourobj.bravo, "empty");
		armourobj.dref = 0;
		armourobj.valid = 0;
		armourobj.armour = 1.0;
		armourobj.health = 0.0;
		armourobj.attack = 0.0;
		armourobj.maxammo = 0;

		points = 0;
		kills = 0;

		initialise();

	 	 }
}

void zkillACue()
{
	for (int i=0;i<2;i++)
		{
			sound(200); delay(100);
			sound(400); delay(100);
			sound(600); delay(100);
						delay(150);
		}
	sound(200); delay(150); nosound(); delay(75);
	sound(200); delay(200); sound(800); delay(400);
	nosound();
}

void gamelostACue()
{
	int c=4;
	while(c<=9)
	{
		int count=(c*100);
		while(count>=(c*100)-300)
		{
			sound(count);
			delay(1);
			count-=2;
		}
		c++;
	}
	c=9;
	while(c>=4)
	{
		int count=((c*100)-300);
		while(count<=(c*100))
		{
			sound(count);
			delay(1);
			count+=2;
		}
		c--;
	}
	nosound();
}

void gamewinACue()
{
	sound(300);
	delay(200);
	nosound();
	delay(75);
	for (int i=1;i<=5;i++)
		{
			sound(100*i);
			delay(150);
		}
	nosound();
	delay(100);
	sound(200);
	delay(200);
	nosound();
	delay(75);
	sound(800);
	delay(900);
	nosound();
}

// GAME ROOM FUNCS.
void livingroom()
{
	flag = 0;
	livingroomtext();
	while(1)
	{
		cout<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case 'm' :
			
				cout<<endl<<"You have gained full health.   <PRESS ENTER>"<<endl; getch();
				health = 80; break;

			case 'z' :

				if(LivingRoom[5].valid==1)
				{
					cout<<endl<<LivingRoom[5].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&LivingRoom[5],sizeof(LivingRoom[5]));
					memcpy(&LivingRoom[5],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '1' :

				if(LivingRoom[0].valid==1)
				{
					cout<<endl<<LivingRoom[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&LivingRoom[0],sizeof(LivingRoom[0]));
					memcpy(&LivingRoom[0],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '2' :

				if(LivingRoom[1].valid==1)
				{
					cout<<endl<<LivingRoom[1].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += LivingRoom[1].health;
					if(health > 80) health = 80;
					cout<<LivingRoom[1].bravo<<endl;
					LivingRoom[1].valid = 0;
					strcpy(LivingRoom[1].title,"empty");
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '3' :

				if(LivingRoom[2].valid==1)
				{
					cout<<endl<<LivingRoom[2].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					if(alertflag==0) { cout<<"Stay alert. Zombies might be heading your way. You turned on the TV."<<endl; alertflag = 1; }
					else { cout<<"You're safe. You turned off the TV."<<endl; alertflag = 0; }
				}
				break;

			case '4' :

				cout<<endl<<LivingRoom[3].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				health += 0.2;
				if(health > 80) health = 80;
				cout<<LivingRoom[3].bravo<<endl;
				break;

			case '5' :

				if(LivingRoom[4].valid==1)
				{
					cout<<endl<<LivingRoom[4].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&LivingRoom[4],sizeof(LivingRoom[4]));
					memcpy(&LivingRoom[4],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case 't' : cout<<"You dont't have a previous ROOM to go to."<<endl;
			case 'h' : kitchen(); break;
			case 'y' : flag = 1; cout<<endl<<"You made a superhuman jump to the police station.   <PRESS ENTER>"<<endl; getch(); ps(); break;
			case 'i' : inventory(); break;
			case 'r' : livingroomtext(); break;
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void kitchen()
{
	kitchentext();
	while(1)
	{
		cout<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				if(Kitchen[0].valid==1)
				{
					cout<<endl<<Kitchen[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += Kitchen[0].health;
					if(health > 80) health = 80;
					cout<<Kitchen[0].bravo<<endl;
					Kitchen[0].valid = 0;
					strcpy(Kitchen[0].title,"empty");
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '2' :

				if(Kitchen[1].valid==1)
				{
					cout<<endl<<Kitchen[1].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&Kitchen[1],sizeof(Kitchen[1]));
					memcpy(&Kitchen[1],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '3' :

				if(Kitchen[2].valid==1)
				{
					cout<<endl<<Kitchen[2].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += Kitchen[2].health;
					if(health > 80) health = 80;
					cout<<Kitchen[2].bravo<<endl;
					Kitchen[2].valid = 0;
					strcpy(Kitchen[2].title,"empty");
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '4' :

				if(Kitchen[3].valid==1)
				{
					cout<<endl<<Kitchen[3].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&Kitchen[3],sizeof(Kitchen[3]));
					memcpy(&Kitchen[3],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '5' :

				if(Kitchen[4].valid==1)
				{
					cout<<endl<<Kitchen[4].descript<<"   <PRESS ENTER>"<<endl;
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
					cout<<endl<<Kitchen[5].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += Kitchen[5].health;
					if(health > 80) health = 80;
					cout<<Kitchen[5].bravo<<endl;
					Kitchen[5].valid = 0;
					strcpy(Kitchen[5].title,"empty");
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '7' :

				cout<<endl<<Kitchen[6].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				health += Kitchen[6].health;
				if(health > 80) health = 80;
				cout<<Kitchen[6].bravo<<endl;
				break;

			case '8' :

				cout<<endl<<Kitchen[7].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Kitchen[7].bravo<<endl;
				break;

			case '9' :

				if(Kitchen[8].valid==1)
				{
					cout<<endl<<Kitchen[8].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&Kitchen[8],sizeof(Kitchen[8]));
					memcpy(&Kitchen[8],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '0' :

				cout<<endl<<Kitchen[9].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Kitchen[9].bravo<<endl;
				break;

			case 't' : livingroom(); break;
			case 'h' : backyard(); break;
			case 'i' : inventory(); break;
			case 'r' : kitchentext(); break;
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void backyard()
{
	backyardtext();
	cout<<"\n<PRESS ENTER>"<<endl<<endl;
	getch();
	cout<<"Oh no! a rummaging zombie just saw you from the streets.\nYou need to fight your way back to safety.\nIt's heading your way. Here, it comes!"<<endl;
	battle(0);
	if(alertflag == 1) { cout<<endl<<"They've been alerted and they're swarming. It'll be difficult to defeat a herd! You'd better kept the TV off. Here comes another one!"<<endl; battle(0); }
	backyardtext();
	while(1)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				if(Backyard[0].valid==1)
				{
					cout<<endl<<Backyard[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += Backyard[0].health;
					if(health > 80) health = 80;
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
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void localinfirmary()
{
	localinfirmarytext();
	while(1)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				if(LocalInfirmary[0].valid==1)
				{
					cout<<endl<<LocalInfirmary[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += LocalInfirmary[0].health;
					if(health > 80) health = 80;
					cout<<LocalInfirmary[0].bravo<<endl;
					LocalInfirmary[0].valid = 0;
					strcpy(LocalInfirmary[0].title,"empty");
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '2' :

				cout<<endl<<LocalInfirmary[1].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<LocalInfirmary[1].bravo<<endl;
				break;

			case '3' :

				if(LocalInfirmary[2].valid==1)
				{
					cout<<endl<<LocalInfirmary[2].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&LocalInfirmary[2],sizeof(LocalInfirmary[2]));
					memcpy(&LocalInfirmary[2],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '4' :

				if(LocalInfirmary[3].valid==1)
				{
					cout<<endl<<LocalInfirmary[3].descript<<"   <PRESS ENTER>"<<endl;
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
					cout<<endl<<LocalInfirmary[4].descript<<"   <PRESS ENTER>";
					getch();
					cout<<endl;
					health += LocalInfirmary[4].health;
					if(health > 80) health = 80;
					cout<<LocalInfirmary[4].bravo<<endl;
					LocalInfirmary[4].valid = 0;
					strcpy(LocalInfirmary[4].title,"empty");
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case '6' :

				cout<<endl<<LocalInfirmary[5].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<LocalInfirmary[5].bravo<<endl;
				break;

			case 't' : backyard(); break;
			case 'h' : streets(); break;
			case 'i' : inventory(); break;
			case 'r' : localinfirmarytext(); break;
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void streets()
{
	streetstext();
	cout<<"\n<PRESS ENTER>"<<endl;
	getch();
	cout<<endl<<"Look! Zombies are coming. You've been spotted.\nHere, they come."<<endl;
	battle(0);
	cout<<"And here is another one!"<<endl;
	battle(0);
	streetstext();
	while(1)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				;
				if(Streets[0].valid==1)
				{
					cout<<endl<<Streets[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&Streets[0],sizeof(Streets[0]));
					memcpy(&Streets[0],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '2' :

				cout<<endl<<Streets[1].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Streets[1].bravo<<endl;
				break;

			case '3' :

				cout<<endl<<Streets[2].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Streets[2].bravo<<endl;
				break;

			case 't' : localinfirmary(); break;
			case 'h' : church(); break;
			case 'i' : inventory(); break;
			case 'r' : streetstext(); break;
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void church()
{
	churchtext();
	cout<<"\n<PRESS ENTER>"<<endl;
	getch();
	cout<<"Zombies are coming again. Get ready."<<endl;
	battle(0);
	cout<<endl<<"There is a herd of them!"<<endl;
	battle(0);
	cout<<endl<<"They keep coming, here is another one."<<endl;
	battle(0);
	churchtext();
	while(1)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				if(Church[0].valid==1)
				{
					cout<<endl<<Church[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&Church[0],sizeof(Church[0]));
					memcpy(&Church[0],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
				}
				else cout<<"Object not found in the room."<<endl;
				break;

			case '2' :

				cout<<endl<<Church[1].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Church[1].bravo<<endl;
				break;

			case '3' :

				cout<<endl<<Church[2].descript<<"   <PRESS ENTER>"<<endl;
				getch();
				cout<<Church[2].bravo<<endl;
				break;

			case '4' :

				if(Church[3].valid==1)
				{
					cout<<endl<<Church[3].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					health += Church[3].health;
					if(health > 80) health = 80;
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
			case 'e' : gameover(); break;
			default  : cout<<"Please retry."<<endl;
		}
	}
}

void ps()
{
	if(flag==0) {
	int boost = 0;
	pstext(0);
	cout<<"It's too quiet.";
	cout<<"   <PRESS ENTER>"<<endl; getch();
	cout<<endl<<"Zombies are coming again."<<endl;
	battle(0);
	pstext(0);
	while(boost==0)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
		{
			case '1' :

				if(PS[0].valid==1)
				{
					cout<<PS[0].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					askswap();

					memcpy(&temp,&slotobj[_swap],sizeof(slotobj[_swap]));
					memcpy(&slotobj[_swap],&PS[0],sizeof(PS[0]));
					memcpy(&PS[0],&temp,sizeof(temp));

					cout<<slotobj[_swap].bravo<<endl;
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
					if(health > 80) health = 80;
					cout<<PS[4].bravo<<endl;
					PS[4].valid = 0;
					strcpy(PS[4].title,"empty");
				}
				else cout<<"Object is not found in the room."<<endl;
				break;

			case 't' : church(); break;
			case 'i' : inventory(); break;
			case 'r' : pstext(0); break;
			case 'e' : gameover(); break;
			case 'c' : boost = 1; break;
			default  : cout<<"Please retry."<<endl;
		}
	}
	cout<<"\n<PRESS ENTER>"<<endl<<endl; getch();
	cout<<"Behooollldd!!! A huge Acid Zombie is heading towards you."<<endl;
	battle(1);

	//escape...
	cout<<endl<<"How nice you survived!"<<endl; }
	pstext(1);
	while(1)
	{
		cout<<endl<<"\n    +> ";
		ch = cmdinp('g');
		switch(ch)
			{
				case '1' :

					cout<<endl<<PS[5].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					cout<<PS[5].bravo<<endl;
					break;

				case '2' :

					cout<<endl<<PS[6].descript<<"   <PRESS ENTER>"<<endl;
					getch();
					cout<<PS[6].bravo<<endl;
					cout<<"You found car keys and there is a police vehicle standing by."<<endl;
					cout<<"\n<PRESS ENTER>"<<endl; getch();
					cout<<endl<<"Approach the car."<<endl;
					cout<<endl<<"<PRESS ENTER> to open the door, and escape"<<endl;
					getch();
					cout<<"\nYou escaped!\n\nThank you for playing the game."<<endl;
					gamewinACue();
					getch(); gameover(); break;

				case 'i' : inventory(); break;
				case 'r' : pstext(1); break;
				case 'e' : gameover(); break;
				default  : cout<<"Please retry."<<endl;
			}
	}
}

// GAME ROOM TEXT FUNCS.
void livingroomtext()
{
	strcpy(in,"Living Room"); //31#31
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> HOUSE: LIVING ROOM <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"You are in your living room. It's dark but there is enough illumination to grapple things. It's quiet outside. You haven't spotted a zombie for more than a couple of days because you have been confined to the room. You are not supposed to make noise, as noise and light from homes may attract zombies. Your cell phone is not working. However, you can see some things you could make use of."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl<<endl; getch();
	cout<<"You can see the following objects:\n1. "<<LivingRoom[0].title<<"\n2. "<<LivingRoom[1].title<<"\n3. "<<LivingRoom[2].title<<"\n4. "<<LivingRoom[3].title<<"\n5. "<<LivingRoom[4].title; cout<<"\nFrom here, you can go to:\n(H) KITCHEN"<<endl;
}

void kitchentext()
{
	strcpy(in,"Kitchen"); //37#36
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> KITCHEN <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"This is your kitchen. You have used almost all the food in here. However, some stale food is still remaining."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<endl<<"You can see the following objects:\n1. "<<Kitchen[0].title<<"\n2. "<<Kitchen[1].title<<"\n3. "<<Kitchen[2].title<<"\n4. "<<Kitchen[3].title<<"\n5. "<<Kitchen[4].title<<"\n6. "<<Kitchen[5].title<<"\n7. "<<Kitchen[6].title<<"\n8. "<<Kitchen[7].title<<"\n9. "<<Kitchen[8].title<<"\n0. "<<Kitchen[9].title; cout<<"\nFrom here, you can go to and back to the following:\n(H) BACKYARD, (there is some strange noise outside, flashes through the window)\n(T) LIVING ROOM"<<endl;
}

void backyardtext()
{
	strcpy(in,"Backyard"); //36#36
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> BACKYARD <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"Not having been maintained for weeks, over grown grass and debris has made the backyard difficult to walk into. There are traces of zombie blood, too."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl<<endl; getch(); cout<<"You can see only one object here\n1. "<<Backyard[0].title<<endl;
	cout<<"From here, you can go to and back to:\n(H) LOCAL INFIRMARY\n(T) KITCHEN";
}

void localinfirmarytext()
{
	strcpy(in,"Local Infirmary"); //33#32
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> LOCAL INFIRMARY <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"The infirmary is located at the street next to that your house is on, making it accessible through your backyard. The infirmary used to be run by clinic practitioner in a small chamber directly overlooking the street. You carefully crossed the street as not to alert the zombie at a distance. The room is full of debris that included the ripped apart remains of the green curtains that used to screen light from the only door."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<endl<<"You can explore the following objects:\n1. "<<LocalInfirmary[0].title<<"\n2. "<<LocalInfirmary[1].title<<"\n3. "<<LocalInfirmary[2].title<<"\n4. "<<LocalInfirmary[3].title<<"\n5. "<<LocalInfirmary[4].title<<"\n6. "<<LocalInfirmary[5].title; cout<<"\nFrom here, you can go to and back to:\n(H) STREETS\n(T) BACKYARD";
}

void streetstext()
{
	strcpy(in,"Streets"); //37#36
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> STREETS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"You are out from under the infirmary's roof, out into the streets. You are carefully walking down the path, trying to make no noise. However, you are not in the shadows."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<endl<<"There are some random things in the street:\n1. "<<Streets[0].title<<"\n2. "<<Streets[1].title<<"\n3. "<<Streets[2].title<<endl; cout<<"From here, you can go to and back to:\n(H) CHURCH \n(T) LOCAL INFIRMARY"<<endl;
}

void churchtext()
{
	strcpy(in,"Church"); //36#36
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> CHURCH <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout<<"The church has been destroyed by zombie attacks. What you see in front was very much different from the time when you used to come here strolling, with your pet dog."<<endl;
	cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<endl<<"The following can be seen around:\n1. "<<Church[0].title<<"\n2. "<<Church[1].title<<"\n3. "<<Church[2].title<<"\n4. "<<Church[3].title<<endl; cout<<"From here, you can go to and back to:\n(H) POLICE STATION \n(T) STREETS"<<endl;
}

void pstext(int iota)
{
	strcpy(in,"Police Station"); //33#33
	if(!iota)
	{
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POLICE STATION <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout<<"You have finally reached your destination. This is the place when you are supposed to be extracted from. However, the police station is now a mess. You need to be careful though."<<endl;
		cout<<"\n<PRESS ENTER>"<<endl; getch(); cout<<endl<<"You can interact with the following objects:\n1. "<<PS[0].title<<"\n2. "<<PS[1].title<<"\n3. "<<PS[2].title<<"\n4. "<<PS[3].title<<"\n5. "<<PS[4].title<<endl; cout<<"From here, you can go back to:\n(T) CHURCH\n(C) or CONTINUE"<<endl;
	}
	else
	{
		cout<<endl<<"There are some things more in here:\n1. "<<PS[5].title<<"\n2. "<<PS[6].title<<endl;
	}
}