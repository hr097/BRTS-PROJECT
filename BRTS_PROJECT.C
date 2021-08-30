/* 
   author : HARSHIL RAMANI
   date : 14/06/2021
   edit : by Harshil Ramani 
   Description : BRTS Pass Method and Regular Charge Evaluation method
   project type : Personal project 
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

/* GLOBAL MACRO DECLARATION */

#define student_discount 40  //educational students
#define women_discount 25   //job women
#define men_discount 20    //job  men
#define senior_citizen_discount 50  // Senior Citizen
#define General_discount 20      //Normal
#define Differently_abledPerson_discount 60  //job men/women
#define Visually_impairedPerson_discount 100  //job  men/women
#define Army_Policeofficer_discount 100      //Army Or Police
#define Political_Leader_discount 65         //political leader
#define Other_Government_discount 55         // Other Government Officer

/***********************/

/* GLOBAL  VARIABLE DECLARATION */   //? we declare it global because later on we can modify it easily
float regular_price = 0.75;
int regular_per_meter = 100;
int gst_rate = 5;
int que_ans_var;
int startpointid,endpointid;
static int count=0;
/***********************/

/* GLOBAL DECLARATION FOR RECEIPT */
struct receipt
{
char name[50];  // ! done
char mobieNo[11];  // ! done
char start_place[30]; // ! done
char end_place[30];   // ! done
int charge;           // ! done
}receipt1;

/***********************/

/* FUNCTION DECLARATION */
float distanceCalculation(int,int);
float normalChargecalculation(float);
void payment(float);
int que_ans(void);
void endView(); //*  Frequently used Function used function 
int brtspass(int);
void calculation(float);

void saving(int);
void receipt();
/***********************/

main(int argv,char *argc[])
{
	while(1){
    //? VARIABLE DECLARTION

    int choice,ans;
    float distancekm,normalCharge;
    char stationName[10][40]={"SIMADA SMVS JUNCTION",
    "SIMADA MAIN JUNCTION",
    "CANAL MAIN JUNCTION",
    "AMEZIA JUNCTION",
    "KHARVARNAGAR JUNCTION",
    "ANUVRATDWAR JUNCTION",
    "J.P.DOWER JUNCTION",
    "VNSGU JUNCTION",
    "MAHARANA-PRATAP JUNCTION",
    "VR VESU JUNCTION"};
    
    //? *******************

	 
    

    //display for  user input  info

    printf("\n\n\n\t\t\t\t\t\t    RIHA BRTS\t\t\n");
    
	printf("\n  Enter Your Name: ");
    scanf("%[^\n]",&receipt1.name);
    fflush(stdin);

    askmobi:
	printf("\n  Enter Your Mobile Number[10-Digit]: ");
    scanf("%s",&receipt1.mobieNo);
	fflush(stdin);

	if(strlen(receipt1.mobieNo)!=10)
	{
		printf("\n  Enter Mobile Number Properly.\n");
		goto askmobi;
	}

    printf("\n\n\n\t\t\t\t*************************************************");
    printf("\n\t\t\t\t*\t\t\t\t\t\t*");
    printf("\n\t\t\t\t*\t1) SIMADA SMVS JUNCTION\t\t\t*\n\t\t\t\t*\t2) SIMADA MAIN JUNCTION\t\t\t*\n\t\t\t\t*\t3) CANAL MAIN JUNCTION\t\t\t*");
    printf("\n\t\t\t\t*\t4) AMEZIA JUNCTION\t\t\t*\n\t\t\t\t*\t5) KHARVARNAGAR JUNCTION\t\t*\n\t\t\t\t*\t6) ANUVRATDWAR JUNCTION\t\t\t*");
    printf("\n\t\t\t\t*\t7) J.P.DOWER JUNCTION\t\t\t*\n\t\t\t\t*\t8) VNSGU JUNCTION\t\t\t*\n\t\t\t\t*\t9) MAHARANA-PRATAP JUNCTION\t\t*\n\t\t\t\t*\t10)VR VESU JUNCTION\t\t\t*");
    printf("\n\t\t\t\t*\t\t\t\t\t\t*");
    printf("\n\t\t\t\t*************************************************");
   
    //instruction part
   
    printf("\n\n\t\t\tNOTE : Enter Entry  And Exit Point According To Shown Details.");

    restart:   // * reasking choice
 	
    //input part

    printf("\n\n  Enter Starting Point : ");   
    scanf("%d",&startpointid);
	strcpy(receipt1.start_place,stationName[(startpointid-1)]);
    printf("\n  Enter Ending Point :  ");
    scanf("%d",&endpointid);
	strcpy(receipt1.end_place,stationName[(endpointid-1)]);
    
    if(startpointid<1||startpointid>10||endpointid<1||endpointid>10||startpointid==endpointid)
    {   
		  printf("\n******************************************************Error Occured*****************************************************\n"); 
		  if(startpointid<1||startpointid>10)
		  {
	      printf("\n\t\t\t\t    Invalid Input  of Starting Point ! \n");
	      }
	      if(endpointid>10||endpointid<1)
	      {
		  printf("\n\t\t\t\t    Invalid Input  of Ending Point ! \n");
		  }
	      if(startpointid==endpointid)
	      { 
		  printf("\n\t\t\t\t    Entry And Exit Points Both Are  The Same ! \n");
		  }
	      printf("\n\t\t\t\t   \"Please Re-Enter Both Points Together Correctly\"");
		  printf("\n\n************************************************************************************************************************\n");
		  goto restart;    //// * reasking choice
	}
    else
    {

    distancekm = distanceCalculation(startpointid,endpointid); // distance in meter or km
    normalCharge = normalChargecalculation(distancekm);   //  Ride rate (in rupees)
    payment(normalCharge);                                 // total pay
    
	receipt1.charge =(int) normalCharge; 
	
    
	// asking user if he/she is intersted in brts pass or not

    printf("\n\n************************************************************************************************************************");
	printf("\n\n\t\t\t\t      Are You Intersted In Getting BRTS Pass ? ");
	printf("\n\n\t\t\t\tIf  Yes  Then Type 1 Otherwise You Can Exit By Pressing 0 \n");

    que_ans_var = que_ans();
    if(que_ans_var==0){endView();}
    else
    {
             choice = brtspass(que_ans_var);
             switch(choice)
             {
case 1:        { printf("\n\n************************************************************************************************************************");
	 			printf("\n\t\t\t\t         WE GIVE 40 PERCENT DISCOUNT ON STUDENT PASS ");
				printf("\n\n\t\t\t\t      Are You Intersted In Getting Student BRTS Pass ? ");
				printf("\n\n\t\t\t\t  If  Yes  Then Type 1 Otherwise You Can Exit By Pressing 0 \n");

			que_ans_var = 0; // * reseting value
			printf("\n\t\t\t\t\t\t\t");
			que_ans_var = que_ans();
			
			if(que_ans_var==1)
			{
				
			printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
	        printf("\n\t\t\t\t\t\t  AND TYPE \"STUDENT PASS\"\n");
	        printf("\n\n\t\t\t\t     |**************************************************|");
		 	printf("\n\t\t\t\t     |\t                                                |");
			printf("\n\t\t\t\t     |\t  1)SCHOOL OR COLLEGE BONOFIED CERTIFICATE      |");
		 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
		 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
		 	printf("\n\t\t\t\t     |\t                                                |");
		    printf("\n\t\t\t\t     ****************************************************\n");
		    
		    printf("\n\n\t\t\t\t    |****************************************************|");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776564               |");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    ******************************************************\n");
            saving(normalCharge);
			}
            else
            {
              	endView();
			}
			    break;
			}
case 2: 
					{
            printf("\n\n************************************************************************************************************************");
			printf("\n\t\t\t\tWE GIVE DISCOUNT ON GENERAL PASS BY FOlLOWING CATEGARY");
				printf("\n\n\t\t\t\t     |*********************************************|");
			 	printf("\n\t\t\t\t     |\t  1)Senior_citizen : 50  Percent           |");
			 	printf("\n\t\t\t\t     |\t  2)Reguler General Pass : 20 Percent      |");
			 	printf("\n\t\t\t\t     |\t                                           |");
			 	printf("\n\t\t\t\t     |\t  EXIT BY PRESSING 0                       |");
			 	printf("\n\t\t\t\t     ***********************************************\n");
			    
				
			printf("\n\t\t\t\t         Which Pass You Would Like To Get?");
			start2:
			printf("\n\t\t\t\t\t\t\t");
			scanf("%d",&ans);
			
			
			if(ans==1)
			{   //seniour citizen
		    printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
	        printf("\n\t\t\t\t\t\t  AND TYPE \"SENIOR CITIZEN PASS\"\n");
	        printf("\n\n\t\t\t\t     |**************************************************|");
		 	printf("\n\t\t\t\t     |\t                                                |");
			printf("\n\t\t\t\t     |\t  1)AADHARCAD                                   |");
		 	printf("\n\t\t\t\t     |\t  2)RETIREMENT CERTIFICATE                      |");
		 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
		 	printf("\n\t\t\t\t     |\t                                                |");
		    printf("\n\t\t\t\t     ****************************************************\n");
		    
		    printf("\n\n\t\t\t\t    |****************************************************|");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776565               |");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    ******************************************************\n");
			
			saving(normalCharge);
			}
			else if(ans==2)
		    {  //general pass
			printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
	        printf("\n\t\t\t\t\t\t  AND TYPE \"GENERAL PASS\"\n");
	        printf("\n\n\t\t\t\t     |**************************************************|");
		 	printf("\n\t\t\t\t     |\t                                                |");
			printf("\n\t\t\t\t     |\t               *ONLY TWO DOUMENTS*              |");
			printf("\n\t\t\t\t     |\t                                                |");
		 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
		 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
		 	printf("\n\t\t\t\t     |\t                                                |");
		    printf("\n\t\t\t\t     ****************************************************\n");
		    
		    printf("\n\n\t\t\t\t    |****************************************************|");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776566               |");
		    printf("\n\t\t\t\t    |\t                                                 |");
		    printf("\n\t\t\t\t    ******************************************************\n");
			saving(normalCharge);	    
			}
			else if(ans==0)
			{
			  	endView();
			}
			else
			{
			printf("\n\n\t\t\t\t\t           Invalid Input !!!");
			printf("\n\n\t\t\t\t\t    Please  Enter  Correct  Input !\n\t\t\t\t\t\t\t");
			goto start2;	 
			}	
			    break;}
case 3:{	//job pass
                printf("\n\n************************************************************************************************************************");
				printf("\n\t\t\t\tWE GIVE DISCOUNT ON JOB PASS BY FOlLOWING CATEGARY");
				printf("\n\n\t\t\t\t     |**********************************************|");
			 	printf("\n\t\t\t\t     |\t  1)Women :  25   Percent                   |");
			 	printf("\n\t\t\t\t     |\t  2)Men   :  20    Percent                  |");
			 	printf("\n\t\t\t\t     |\t  3)Differently abled Person : 60  Percent  |");
			 	printf("\n\t\t\t\t     |\t  4)Visually Impaired person : 100 Percent  |");
			 	printf("\n\t\t\t\t     |\t                                            |");
			 	printf("\n\t\t\t\t     |\t  EXIT BY PRESSING 0                        |");
			    printf("\n\t\t\t\t     ************************************************\n");
			    
			    
					printf("\n\t\t\t\t         Which Pass You Would Like To Get?");
			
					start3:
					printf("\n\t\t\t\t\t\t\t");
					scanf("%d",&ans);
					
					if(ans==1||ans==2)
					{
			
	  	            printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
			  	    
					if(ans==1)
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS WOMAN\"\n");
			        if(ans==2)
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS MAN\"\n");
			        
			        printf("\n\n\t\t\t\t     |**************************************************|");
				 	printf("\n\t\t\t\t     |\t                                                |");
					printf("\n\t\t\t\t     |\t  1)JOB I-CARD                                  |");
				 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
				 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
				 	printf("\n\t\t\t\t     |\t                                                |");
				    printf("\n\t\t\t\t     ****************************************************\n");
				    
				    if(ans==1)
				    {
					
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776567               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************\n");
					saving(normalCharge);
				    }
				    else if(ans==2)
				    {
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776568               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************\n");	
				    saving(normalCharge);
					}	 
					
					}
					else if(ans==3||ans==4)
					{
			
	  	            printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
			  	    
					if(ans==3)
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS Differently abled\"\n");
			        if(ans==4)
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS Visually Impaired \"\n");
			        
			        printf("\n\n\t\t\t\t     |**************************************************|");
				 	printf("\n\t\t\t\t     |\t                                                |");
					printf("\n\t\t\t\t     |\t  1)JOB I-CARD                                  |");
				 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
				 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
				 	printf("\n\t\t\t\t     |    3)DOCTOR APPROVED CERTIFICATE OF DISABILITY   |");
				 	printf("\n\t\t\t\t     |\t                                                |");
				    printf("\n\t\t\t\t     ****************************************************\n");
				    
				    if(ans==3)
				    {
					
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776569               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************\n");
					
					saving(normalCharge);
				    }
				    else if(ans==4)
				    {
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  WHATSAPP NUMBER : +91 9988776570               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t           *ONLY FOR BLIND PERSON*               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  IF THAT IS NOT POSSIBLE THAN YOU CAN CONTACT   |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t  OUR REPRESENTATIVE AT HELPLINE 1800-123-009    |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************\n");	
				    	 
					saving(normalCharge);   
					}
					else if(ans==0)
					{
						endView();
					}
					else
					{
					printf("\n\n\t\t\t\t\t           Invalid Input !!!");
					printf("\n\n\t\t\t\t\t    Please  Enter  Correct  Input !\n\t\t\t\t\t\t\t");
					goto start3;	 
					}	
		

					}
                    break;}
case 4:{        //government work

                printf("\n\n************************************************************************************************************************");
			    printf("\n\t\t\t\tWE GIVE DISCOUNT ON GOVERNMENT-WORK PASS BY FOlLOWING CATEGARY");
				printf("\n\n\t\t\t\t     |*********************************************|");
			 	printf("\n\t\t\t\t     |\t  1)Army OR Police Officer : 100 Percent   |");
			 	printf("\n\t\t\t\t     |\t  2)Political Leader :  65 Percent         |");
			 	printf("\n\t\t\t\t     |\t  3)Other Government Officer : 55 Percent  |");
			 	printf("\n\t\t\t\t     |\t                                           |");
			 	printf("\n\t\t\t\t     |\t  EXIT BY PRESSING 0                       |");
			    printf("\n\t\t\t\t     ***********************************************\n");
			    
			    
			    printf("\n\t\t\t\t         Which Pass You Would Like To Get?");
			
				start4:
				printf("\n\t\t\t\t\t\t\t");
				scanf("%d",&ans);
					
			        if(ans==1)
					{
			
	  	            printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
			
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS ARMY OR POLICE\"");
			        
			        
			        printf("\n\t\t\t\t     |**************************************************|");
				 	printf("\n\t\t\t\t     |\t                                                |");
					printf("\n\t\t\t\t     |\t  1)ARMY I-CARD                                 |");
				 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
				 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
				 	printf("\n\t\t\t\t     |    3)GOVERNMENT ARMY CERTIFICATE DETAILS         |");
				 	printf("\n\t\t\t\t     |\t                                                |");
				    printf("\n\t\t\t\t     ****************************************************");
				    
				   
					
				    printf("\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t       WHATSAPP NUMBER : +91 9988776571          |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t   *WE VALUE AND HEARTLY RESPECT INDIAN ARMY*    |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t           *JAY HIND ! JAY BHARAT*               |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************");
				    
					saving(normalCharge);	 
					
					}
					else if(ans==2)
					{
			
	  	            printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
			  	    
					
			        printf("\n\t\t\t\t\t\t  AND TYPE \"JOB PASS POLITICAL LEADER\"");
			       
			        
			        printf("\n\n\t\t\t\t     |**************************************************|");
				 	printf("\n\t\t\t\t     |\t                                                |");
					printf("\n\t\t\t\t     |\t  1)ELECTION  CARD                              |");
				 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
				 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
				 	printf("\n\t\t\t\t     |    3)GOVERNMENT OF INDIA APPROVED LEDAERSHIP     |");
				 	printf("\n\t\t\t\t     |      CERTIFICATE                                 |");
				 	printf("\n\t\t\t\t     |\t                                                |");
				    printf("\n\t\t\t\t     ****************************************************");
				    
				    
					
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t        WHATSAPP NUMBER : +91 9988776572         |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************");
				    
					saving(normalCharge);	
				    }
				    else if(ans==3)
					{
					 printf("\n\t\t\tPLEASE SEND THE COPY OF FOLLOWING DOCUMENTS ON THE FOLLOWING WHATSAPP NUMBER\n");
			  	    
					
			        printf("\n\t\t\t\t\t  AND TYPE \"JOB PASS OTHER GOVERNMENT WORKER\"\n");
			       
			        
			        printf("\n\n\t\t\t\t     |**************************************************|");
				 	printf("\n\t\t\t\t     |\t                                                |");
					printf("\n\t\t\t\t     |\t  1)GOVERNMENT APPROVED JOB CARD                |");
				 	printf("\n\t\t\t\t     |\t  2)AADHARCARD                                  |");
				 	printf("\n\t\t\t\t     |    3)ADDRESS PROOF DETAILS                       |");
				 	printf("\n\t\t\t\t     |    3)GOVERNMENT OF INDIA APPROVED WORKER         |");
				 	printf("\n\t\t\t\t     |      CERTIFICATE                                 |");
				 	printf("\n\t\t\t\t     |\t                                                |");
				    printf("\n\t\t\t\t     ****************************************************");
				    
				    
					
				    printf("\n\n\t\t\t\t    |****************************************************|");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    |\t        WHATSAPP NUMBER : +91 9988776573         |");
				    printf("\n\t\t\t\t    |\t                                                 |");
				    printf("\n\t\t\t\t    ******************************************************");
				   
				 
					saving(normalCharge);
					    
					}
					else if(ans==0)
					{
						endView();
					}
					else 
					{
					printf("\n\n\t\t\t\t\t           Invalid Input !!!");
					printf("\n\n\t\t\t\t\t    Please  Enter  Correct  Input !\n\t\t\t\t\t\t\t");
					goto start4;	 
					}
			    
                        break;}
                default: endView();
             }
    }
	
    }

getch();
}
}

// ! FUNCTION DEFINATIONS ! //

float distanceCalculation(int startp,int endp)
{
	//declaration
	int distance[10]={00,100,730,1220,1555,1789,2000,3216,4340,5500};  
    float distancekm,return_value;
	
	//process
	startp=startp-1;
	endp=endp-1;
	distancekm=(float)distance[startp]-distance[endp];
	
	if(distancekm<0){ distancekm*=(-1);}   // * e.g. : 10-1 and 1-10 both are same km


	return_value=distancekm;  // by default it will return distance in km
                                         
	
	//output print decide

	if(distancekm<1000)
	{     //no need of conversion
	      printf("\n\t\t\t\tTOTAL DISTANCE BETWEEN TWO STATION IS : %.0f (Meter)",distancekm);
    }
	else
	{
		//conversion in km
	    distancekm=(distancekm*1)/1000;
 	    printf("\n\t\t\t\tTOTAL DISTANCE BETWEEN TWO STATION IS  %.3f  (km)",distancekm);
	}
	
	return return_value;  
}

float normalChargecalculation(float distancekm)
{
    float charge;
  
    charge= (float) (distancekm * regular_price) / (regular_per_meter);
    printf("\n\n\t\t\t\tTOTAL RIDE CHARGE IS %.2f RUPEES ",charge);
 
    return charge;
}
void payment(float normalCharge)
{ 
     int pay; 
     float pays,gstamount;   //calculating 5 % GST 
     gstamount=((normalCharge)*(gst_rate)/100);
     pays=(normalCharge)+(gstamount);
	 printf("\n\n\t\t\t\tTOTAL GST AMOUNT : %.2f RUPEES  (5 Percent GST Applicable On Travelling)",gstamount);  
     printf("\n\n\t\t\t\tTOTAL AMOUNT INCLUDING GST : %.2f RUPEES",pays);
     
    // yearchargecalc=pays;
     
	 pay=ceil(pays);
	 
	 printf("\n\n\t\t\t\tYOU HAVE TO PAY ONLY %d RUPEES ",pay);

}

 int que_ans()
 {   
    int ans;
    start:
	printf("\n\t\t\t\t\t\t\t");
	scanf("%d",&ans);
	
	
	if(ans==1||ans==0)
	{
		
	  return ans;
	
	}
	else
	{
	    printf("\n\n\t\t\t\t\t        Invalid Input !!!");
	    printf("\n\n\t\t\t\t\t   Please  Enter  Correct  Input !");	
	    goto start;	 
	}

 }

 void endView()
{  
	    printf("\n\n\t\t\t\t      |**********************************************|");
	 	printf("\n\t\t\t\t      |\t       THANKS FOR TRAVELLING BY BRTS.        |");
	 	printf("\n\t\t\t\t      |\t                                             |");
	 	printf("\n\t\t\t\t      |     HAVE  A   NICE  AND   SAFE   JOURNEY     |");
	 	printf("\n\t\t\t\t      |\t                                             |");
	    printf("\n\t\t\t\t      ************************************************");	
        receipt();
		printf("\n\n\n\t\t\t\t                RECEIPT PRINTED SUCCESSFULLY.         ");
		
		fflush(stdin);
}

int brtspass(int a)
{  		
       static int category;  //declaration
        

	 	if(a==1)
	 	{

		printf("\n\t\t\t\tFor Which Purpose You Would Like to Get BRTS Pass ?");
	 	printf("\n\n\t\t\t\t     |****************************************|");
	 	printf("\n\t\t\t\t     |\t  1)Educational Purpose               |");
	 	printf("\n\t\t\t\t     |\t  2)Normal Travelling                 |");
	 	printf("\n\t\t\t\t     |\t  3)Job Purpose                       |");
	 	printf("\n\t\t\t\t     |\t  4)Goverment Work                    |");
	 	printf("\n\t\t\t\t     |\t                                      |");
	 	printf("\n\t\t\t\t     |\t  EXIT BY PRESSING 0                  |");
	    printf("\n\t\t\t\t     ******************************************\n");
	    printf("\n\n\t\t\t\t     Please Select Your Categary: ");
	 	
		start0: 
	 	scanf("%d",&category);
	 	
	 	if(category==1||category==2||category==3||category==4)
	 	{	
		 return category;	
		}
		else if(category==0)
		{
			return category;
		}
		 else
			{
			printf("\n\n\t\t\t\t\t           Invalid Input !!!");
			printf("\n\n\t\t\t\t\t    Please  Enter  Correct  Input !\n\t\t\t\t\t\t\t   ");	
			goto start0;	 
			}
	    
        }
}




void calculation(float normalcharge)
{   


    //printf("\n normal charge : %f \t keyword : %d ",normalcharge,keyword);
    
    float yearlypay,discount;  //declaration   //here discount means GST
    float resultstore[10];
    int k,saving,finalstore[10]; //int values
   
     /*regular charge*/
    printf("\n\n\t\t      |************************** REGULAR SAVING CALCULATION ********************************|");
	printf("\n\t\t      |                                                                                      |");	  
    yearlypay=(float)normalcharge*365.5;
    discount=(float)(yearlypay*5/100);
    //printf("\n  discount : %f ",discount);
    yearlypay=yearlypay+discount;
    resultstore[1]=yearlypay;
    k=ceil(yearlypay);
    finalstore[1]=k;
    printf("\n\t\t      |      Total You Have To Pay  %d (RUPEES) YEARLY IF YOU DONT HAVE BRTS PASS.        |",k);
    printf("\n\t\t      |                                                                                      |");
    yearlypay=(float)(normalcharge*29.50);     //saving variable space
    discount=(float)(yearlypay*5/100);
     //printf("\n  discount : %f ",discount);
    yearlypay=yearlypay+discount;
    resultstore[2]=yearlypay;
    k=ceil(yearlypay);
    finalstore[2]=k;
    printf("\n\t\t      |      Total You Have To Pay %d (RUPEES) MONTHLY IF YOU DONT HAVE BRTS PASS.         |",k);
    printf("\n\t\t      |                                                                                      |");
    printf("\n\t\t      ****************************************************************************************\n");	
    
    
    yearlypay=discount=k=0;  //reseting each value
    
	/*Yearly  saving*/
	printf("\n\n\t\t      |************************** YEARLY SAVING CALCULATION *********************************|");
	printf("\n\t\t      |                                                                                      |");	
	printf("\n\t\t      |                                                                                      |");  
    yearlypay=(float)normalcharge*365.5;
    discount=(float)(resultstore[1]*40/100);
    //printf("\n  discount : %f ",discount);
    yearlypay=resultstore[1]-discount;
    resultstore[3]=yearlypay;
    k=ceil(yearlypay);
    finalstore[3]=k;
    saving=finalstore[1]-k;
    printf("\n\t\t      |                            *Savings : %d  (RUPEES)                                 |",saving);
    printf("\n\t\t      |                                                                                      |");
    printf("\n\t\t      |      Total You Have To Pay  %d (RUPEES) YEARLY IF YOU  HAVE BRTS PASS.             |",k);
    printf("\n\t\t      |                                                                                      |");
    printf("\n\t\t      ****************************************************************************************\n");
    
    yearlypay=discount=k=saving=0;   //reseting each value
     
	/*Monthly saving */
	printf("\n\n\t\t      |************************** MONTHLY SAVING CALCULATION ********************************|");
	printf("\n\t\t      |                                                                                      |");
	printf("\n\t\t      |                                                                                      |"); 
	
	discount=(float)(resultstore[2]*40/100);
    //printf("\n  discount : %f ",discount);
    yearlypay=resultstore[2]-discount;
    resultstore[4]=yearlypay;
    k=ceil(yearlypay);
    finalstore[4]=k;
    saving=finalstore[2]-k;
    printf("\n\t\t      |                            *Savings : %d  (RUPEES)                                  |",saving);
    printf("\n\t\t      |                                                                                      |");
    printf("\n\t\t      |      Total You Have To Pay  %d (RUPEES) MONTHLY IF YOU  HAVE BRTS PASS.             |",k);
	printf("\n\t\t      |                                                                                      |");
    printf("\n\t\t      ****************************************************************************************\n");
    
	
    endView();
	

}

void saving(int normalCharge)
{
	// ? Further Development comman for all

				printf("\n\n\t\t\t      Are You Intersted in Money Saving Calulation If You Get The PASS ?");
				
				printf("\n\n\t\t\t\t  If  Yes  Then Type 1 Otherwise You Can Exit By Pressing 0 \n\t\t\t\t\t\t\t     ");
				
				que_ans_var = 0; // * reseting value
				que_ans_var = que_ans();
				
				if(que_ans_var==1)
			    {  
					printf("\n\n\t\t\t\t    |****************************************************|");
		    		printf("\n\t\t\t\t    |\t                                                 |");
		    		printf("\n\t\t\t\t    |\t    STARTING POINT : %d ENDING POINT : %d         |",startpointid,endpointid);
		    		printf("\n\t\t\t\t    |\t                                                 |");
		    		printf("\n\t\t\t\t    ******************************************************\n");
				      
				      
					printf("\n\n\t\t\t\t    Is This  Your Daily Route For Travelling By BRTS ?");	
					printf("\n\n\t\t\t\t  If  Yes  Then Type 1 Otherwise You Can Exit By Pressing 0\n\t\t\t\t\t\t\t     ");
					 
					que_ans_var = 0; // * reseting value
					que_ans_var = que_ans();
				  
					if(que_ans_var==1)
					{  
					  	calculation(normalCharge); // parameters empty
					}
					else
					{
						endView();	
					}
						
				}
				else
				{
				 endView();	
				}
				
			// ? further Development end

}

void receipt()
{

    time_t seconds;
    int h,m,s;
    
    time(&seconds);
    seconds = seconds + 3600 ;  // * here 1800 less add bce gmt 30 minutes cover
    h = ( (seconds%86400)/3600 )+ 6;  // * 6 add because of GMT TIME 5:30 DIFFRENCE
    m = (seconds%86400)%3600/60;
    s = (seconds%86400)%3600%60;
	
	FILE *ptr,*ptr2;
	ptr=fopen("receipt.txt","w");
	ptr2=fopen("receipt_all.txt","a");
	if(ptr==NULL || ptr2==NULL)
	{
		printf("\nFILE NOT OPENED !");
		exit(1);
	}
    
	/*working start here of first file */
	
	fprintf(ptr,"Name :\t");
	fprintf(ptr,"%s",receipt1.name);
	fprintf(ptr,"\nDate :\t");
	fprintf(ptr,"%s",__DATE__);
	fprintf(ptr,"\nTicket Buying Time :  ");
	fprintf(ptr,"%s",__TIME__);
	fprintf(ptr,"\nTicket Valid Up to :  ");
	fprintf(ptr,"%d:",h);
	fprintf(ptr,"%d:",m);
	fprintf(ptr,"%d",s);
	fprintf(ptr,"\nFrom :\t");
	fprintf(ptr,"%s ",receipt1.start_place);
	fprintf(ptr,"\nTo :\t");
	fprintf(ptr,"%s",receipt1.end_place);
	fprintf(ptr,"\nCharge :\t");
	fprintf(ptr,"%d rupees ",receipt1.charge);
	fprintf(ptr,"\nMobile No :\t");
    fprintf(ptr,"%s",receipt1.mobieNo);
	fprintf(ptr,"\n\n");
	fprintf(ptr,"%s","* THANKS FOR VISTING BY RIHA BRTS \n HAVE A  NICE AND SAFE JOURNEY. *");
    fprintf(ptr,"\nHelpLine Number :\t");
    fprintf(ptr,"%s","1800-123-112");
	
	/*working end here of first file */
    fclose(ptr);
    count++;

	/*working start here of second file */
	fprintf(ptr2,"\n(%d)\n",count);
	fprintf(ptr2,"\nName :\t");
	fprintf(ptr2,"%s",receipt1.name);
	fprintf(ptr2,"\nDate :\t");
	fprintf(ptr2,"%s",__DATE__);
	fprintf(ptr2,"\nTicket Buying Time :  ");
	fprintf(ptr2,"%s",__TIME__);
	fprintf(ptr2,"\nTicket Valid Up to :  ");
	fprintf(ptr2,"%d:",h);
    fprintf(ptr2,"%d:",m);
    fprintf(ptr2,"%d",s);
	fprintf(ptr2,"\nFrom :\t");
	fprintf(ptr2,"%s",receipt1.start_place);
	fprintf(ptr2,"\nTo :\t");
	fprintf(ptr2,"%s",receipt1.end_place);
	fprintf(ptr2,"\nCharge :\t");
	fprintf(ptr2,"%d rupees ",receipt1.charge);
	fprintf(ptr2,"\nMobile No :\t");
    fprintf(ptr2,"%s",receipt1.mobieNo);
	fprintf(ptr2,"\n\n");
	

	/*working end here of second file */
	fclose(ptr2);

}

