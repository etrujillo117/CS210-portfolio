#include <iostream>
#include <jni.h>
#include <vector>
#include "Animal.h"
#include <iomanip>
#include <ostream>
#include <fstream>
using namespace std;

std::vector<Animal> zoovector ={};

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

//Add an animal object to vector
void AddAnimal()
{
	//declare variables to capture user input
	int option, userTrackNum, userEggs, userNurse;
	std:string userName, userType, userSubType;

	//loop menu until user exits
	    bool menu = true;
	   do {
	    cout << "     *Add Animal*\n";
	    cout << "**********************\n";
	    cout << "Which animal would you like to add?\n";
	    cout << "1.Crocodile\n2.Goose\n3.Pelican\n4.Bat\n5.Whale\n6.SeaLion\n7.Return to Main Menu\n\nEnter Option: ";
	    cin >> option;
   switch(option)
	    {
	    case 1:
	    {
	    	cout << "Enter Tracking Number: ";
	    	cin >> userTrackNum;
	    	//validate input
	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    			{
	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    			    cin.clear();
	    			    cin.ignore();
	    			    cin >> userTrackNum;
	    			}
	    	cout << "Enter animal name: ";
	    	cin >> userName;
	    	//validate input
	    		    while(!cin || userName.size() > 15)
	    		    	{
	    		    	    cout << "Invalid input. Please enter a name less than 15 characters\n";
	    		    	    cin.clear();
	    		    	    cin.ignore();
	    		    	    cin >> userName;
	    		    	}
	    	cout << "Enter animal type: ";
	    	cin >> userType;
	    	//validate input
	    		while (userType != "Oviparous")
	    		{
	    			cout << "Invalid input. Please input 'Oviparous'\n";
	    			cin.clear();
	    			cin.ignore();
	    			cin >> userType;
	    		}
	    	cout << "Enter animal subType: ";
	    	cin >> userSubType;
	    	//validate input
	    	while (userSubType != "Crocodile")
	    		{
	    			cout << "Invalid input. Please input 'Crocodile'\n";
	    			cin.clear();
	    		    cin.ignore();
	    		    cin >> userSubType;
	    		    		}
	    	cout << "Number of eggs laid: ";
	    	cin >> userEggs;
	    	//validate input
	    		    while(!cin || userEggs < 0)
	    		    	{
	    		    	    cout << "Invalid input. Please enter 0 or more";
	    		    	    cin.clear();
	    		    	    cin.ignore();
	    		    	    cin >> userEggs;
	    		    	}

	    		    //verify user wants to save or cancel
	    		    char ch;
	    		    bool submenu = true;
	    		    while (submenu == true)
	    		    {
	    		    cout << "Enter 's' to save or 'c' to cancel\n";
	    		    cin >> ch;
	    		    	if (ch == 's')
	    		    	{
	    		    		Crocodile newcroc(userTrackNum,userName,userEggs);
	    		    			zoovector.push_back(newcroc);
	    		    			submenu = false;
	    		    	}
	    		    	else if (ch == 'c')
	    		    	{
	    		    		submenu = false;
	    		    	}
	    		    	else
	    		    	{
	    		    		cout << "Invalid input\n";
	    		    		cin.clear();
	    		    		cin.ignore();
	    		    	}
	    		    }

	    	break;
	    }
	    case 2:
	    {
	    	    	cout << "Enter Tracking Number: ";
	    	    	cin >> userTrackNum;
	    	    	//validate input
	    	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    	    			{
	    	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    	    			    cin.clear();
	    	    			    cin.ignore();
	    	    			    cin >> userTrackNum;
	    	    			}
	    	    	cout << "Enter animal name: ";
	    	    	cin >> userName;
	    	    	//validate input
	    	    		    while(!cin || userName.size() > 15)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter a name less than 15 characters\n";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userName;
	    	    		    	}
	    	    		    cout << "Enter animal type: ";
	    	    		    	    	cin >> userType;
	    	    		    	    	//validate input
	    	    		    	    		while (userType != "Oviparous")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Oviparous'\n";
	    	    		    	    			cin.clear();
	    	    		    	    			cin.ignore();
	    	    		    	    			cin >> userType;
	    	    		    	    		}
	    	    		    	    	cout << "Enter animal subType: ";
	    	    		    	    	cin >> userSubType;
	    	    		    	    	//validate input
	    	    		    	    	while (userSubType != "Goose")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Goose'\n";
	    	    		    	    			cin.clear();
	    	    		    	    		    cin.ignore();
	    	    		    	    		    cin >> userSubType;
	    	    		    	    		    		}
	    	    	cout << "Number of eggs laid: ";
	    	    	cin >> userEggs;
	    	    	//validate input
	    	    		    while(!cin || userEggs < 0)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter 0 or more";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userEggs;
	    	    		    	}
	    	    		    //verify user wants to save or cancel
	    	    		    char ch;
	    	    		    bool submenu = true;
	    	    		    while (submenu == true)
	    	    		        {
	    	    		         cout << "Enter 's' to save or 'c' to cancel\n";
	    	    		    	 cin >> ch;
	    	    		    		if (ch == 's')
	    	    		    	    	{
	    	    		    	     		Goose newgoose(userTrackNum,userName,userEggs);
	    	    		    	      			zoovector.push_back(newgoose);
	    	    		    	      			submenu = false;
	    	    		    	        	}
	    	    		    	    else if (ch == 'c')
	    	    		    	      	{
	    	    		    	       		submenu = false;
	    	    		    	        	}
	    	    		    	    else
	    	    		    	       	{
	    	    		    	       		cout << "Invalid input\n";
	    	    		    	       		cin.clear();
	    	    		    	       		cin.ignore();
	    	    		    	        	}
	    	    	}
	    	    	break;
	    	    }
	    case 3:
	    {
	    	    	cout << "Enter Tracking Number: ";
	    	    	cin >> userTrackNum;
	    	    	//validate input
	    	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    	    			{
	    	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    	    			    cin.clear();
	    	    			    cin.ignore();
	    	    			    cin >> userTrackNum;
	    	    			}
	    	    	cout << "Enter animal name: ";
	    	    	cin >> userName;
	    	    	//validate input
	    	    		    while(!cin || userName.size() > 15)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter a name less than 15 characters\n";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userName;
	    	    		    	}
	    	    		    cout << "Enter animal type: ";
	    	    		    	    	cin >> userType;
	    	    		    	    		while (userType != "Oviparous")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Oviparous'\n";
	    	    		    	    			cin.clear();
	    	    		    	    			cin.ignore();
	    	    		    	    			cin >> userType;
	    	    		    	    		}
	    	    		    	    	cout << "Enter animal subType: ";
	    	    		    	    	cin >> userSubType;
	    	    		    	    	while (userSubType != "Pelican")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Pelican'\n";
	    	    		    	    			cin.clear();
	    	    		    	    		    cin.ignore();
	    	    		    	    		    cin >> userSubType;
	    	    		    	    		    		}
	    	    	cout << "Number of eggs laid: ";
	    	    	cin >> userEggs;
	    	    	//validate input
	    	    		    while(!cin || userEggs < 0)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter 0 or more";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userEggs;
	    	    		    	}

	    	    		    char ch;
	    	    		    bool submenu = true;
	    	    		    while (submenu == true)
	    	    			    {
	    	    			    cout << "Enter 's' to save or 'c' to cancel\n";
	    	    			    cin >> ch;
	    	    			    	if (ch == 's')
	    	    		   		    	{
	    	    		  		    		Pelican newpel(userTrackNum,userName,userEggs);
	    	    		 		    			zoovector.push_back(newpel);
	    	    		   		    			submenu = false;
	    	    		    		    	}
	    	    		 	    	else if (ch == 'c')
	    	    		   		    	{
	    	    		   		    		submenu = false;
	    	    		     		    	}
	    	    		 	    	else
	    	    		   		    	{
	    	    		  		    		cout << "Invalid input\n";
	    	    		   		    		cin.clear();
	    	    		   		    		cin.ignore();
	    	    		     		    	}
	   	    		    }
	    	    	break;
	    	    }
	    case 4:
	    {
	    	    	cout << "Enter Tracking Number: ";
	    	    	cin >> userTrackNum;
	    	    	//validate input
	    	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    	    			{
	    	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    	    			    cin.clear();
	    	    			    cin.ignore();
	    	    			    cin >> userTrackNum;
	    	    			}
	    	    	cout << "Enter animal name: ";
	    	    	cin >> userName;
	    	    	//validate input
	    	    		    while(!cin || userName.size() > 15)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter a name less than 15 characters";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userName;
	    	    		    	}
	    	    		    cout << "Enter animal type: ";
	    	    		    	    	cin >> userType;
	    	    		    	    		while (userType != "Mammal")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Mammal'\n";
	    	    		    	    			cin.clear();
	    	    		    	    			cin.ignore();
	    	    		    	    			cin >> userType;
	    	    		    	    		}
	    	    		    	    	cout << "Enter animal subType: ";
	    	    		    	    	cin >> userSubType;
	    	    		    	    	while (userSubType != "Bat")
	    	    		    	    		{
	    	    		    	    			cout << "Invalid input. Please input 'Bat'\n";
	    	    		    	    			cin.clear();
	    	    		    	    		    cin.ignore();
	    	    		    	    		    cin >> userSubType;
	    	    		    	    		    		}
	    	    	cout << "Enter 1 if Nursing, 0 if not: ";
	    	    	cin >> userNurse;
	    	    	//validate input
	    	    		    while(!cin || userNurse < 0 || userNurse > 1)
	    	    		    	{
	    	    		    	    cout << "Invalid input. Please enter 0 or 1\n";
	    	    		    	    cin.clear();
	    	    		    	    cin.ignore();
	    	    		    	    cin >> userNurse;
	    	    		    	}
	    	    		    char ch;
	    	    		    bool submenu = true;
	     	    		    while (submenu == true)
	 	    	    		    {
	 		    	    		    cout << "Enter 's' to save or 'c' to cancel\n";
	   		    	    		    cin >> ch;
	   		    	    		    	if (ch == 's')
	     		    	    		    	{
	    		    	    		    		Bat newbat(userTrackNum,userName,userNurse);
	     		    	    		    			zoovector.push_back(newbat);
	     		    	    		    			submenu = false;
	        		    	    		    	}
	    	    	    		    	else if (ch == 'c')
	       		    	    		    	{
	      		    	    		    		submenu = false;
	        		    	    		    	}
	    	    	    		    	else
	       		    	    		    	{
	      		    	    		    		cout << "Invalid input\n";
	       		    	    		    		cin.clear();
	       		    	    		    		cin.ignore();
	        		    	    		    	}
	       		    }
	    	    	break;
	    	    }
	    case 5:
	    {
	    	    	    	cout << "Enter Tracking Number: ";
	    	    	    	cin >> userTrackNum;
	    	    	    	//validate input
	    	    	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    	    	    			{
	    	    	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    	    	    			    cin.clear();
	    	    	    			    cin.ignore();
	    	    	    			    cin >> userTrackNum;
	    	    	    			}
	    	    	    	cout << "Enter animal name: ";
	    	    	    	cin >> userName;
	    	    	    	//validate input
	    	    	    		    while(!cin || userName.size() > 15)
	    	    	    		    	{
	    	    	    		    	    cout << "Invalid input. Please enter a name less than 15 characters";
	    	    	    		    	    cin.clear();
	    	    	    		    	    cin.ignore();
	    	    	    		    	    cin >> userName;
	    	    	    		    	}
	    	    	    		    cout << "Enter animal type: ";
	    	    	    		   	cin >> userType;
	    	    	    		 		while (userType != "Mammal")
	    	    	    		    		{
	    	    	    		 				cout << "Invalid input. Please input 'Mammal'\n";
	    	    	    		 				cin.clear();
	    	    	    		    	    	cin.ignore();
	    	    	    		    	    	cin >> userType;
	    	    	    		    		}
	    	    	    		    cout << "Enter animal subType: ";
	    	    	    		    cin >> userSubType;
	    	    	    		    	while (userSubType != "Whale")
	    	    	    		    	{
	    	    	    		     			cout << "Invalid input. Please input 'Whale'\n";
	    	    	    		      			cin.clear();
	    	    	    		       		    cin.ignore();
	    	    	    		       		    cin >> userSubType;
	    	    	    		    		}
	    	    	    	cout << "Enter 1 if Nursing, 0 if not: ";
	    	    	    	cin >> userNurse;
	    	    	    	//validate input
	    	    	    		    while(!cin || userNurse < 0 || userNurse > 1)
	    	    	    		    	{
	    	    	    		    	    cout << "Invalid input. Please enter 0 or 1\n";
	    	    	    		    	    cin.clear();
	    	    	    		    	    cin.ignore();
	    	    	    		    	    cin >> userNurse;
	    	    	    		    	}
	    	    	    		    char ch;
	    	    	    		    bool submenu = true;
	    	    	    		    while (submenu == true)
	       		    	    		    {
	        		    	    		    cout << "Enter 's' to save or 'c' to cancel\n";
	        		    	    		    cin >> ch;
	      	    		    	    		    	if (ch == 's')
	        	    		    	    		    	{
	        	    		    	    		    		Whale newwhale(userTrackNum,userName,userNurse);
	       	    	    		    	    		    		zoovector.push_back(newwhale);
	        	    		    	    		    			submenu = false;
	       	    	    		    	    		    	}
	       	    		    	    		    	else if (ch == 'c')
	        	    		    	    		    	{
	        	    		    	    		    		submenu = false;
	      	    	    		    	    		    	}
	     	    		    	    		    	else
	        	    		    	    		    	{
	        	    		    	    		    		cout << "Invalid input\n";
	        	    		    	    		    		cin.clear();
	        	    		    	    		    		cin.ignore();
	            	    		    	    		    	}
	    	   		    }

	    	    	    	break;
	    	    	    }
	    case 6:
	    {
	    	    	    	cout << "Enter Tracking Number: ";
	    	    	    	cin >> userTrackNum;
	    	    	    	//validate input
	    	    	    		while(!cin || userTrackNum < 0 || userTrackNum > 999999)
	    	    	    			{
	    	    	    			    cout << "Invalid input. Please enter a six digit tracking number";
	    	    	    			    cin.clear();
	    	    	    			    cin.ignore();
	    	    	    			    cin >> userTrackNum;
	    	    	    			}
	    	    	    	cout << "Enter animal name: ";
	    	    	    	cin >> userName;
	    	    	    	//validate input
	    	    	    		    while(!cin || userName.size() > 15)
	    	    	    		    	{
	    	    	    		    	    cout << "Invalid input. Please enter a name less than 15 characters\n";
	    	    	    		    	    cin.clear();
	    	    	    		    	    cin.ignore();
	    	    	    		    	    cin >> userName;
	    	    	    		    	}
	    	    	    		    cout << "Enter animal type: ";
	    	    	    		   	cin >> userType;
	    	    	    		 		while (userType != "Mammal")
	    	    	    		    		{
	    	    	    					cout << "Invalid input. Please input 'Mammal'\n";
	    	    	    	 				cin.clear();
	    	    	    	    	    	cin.ignore();
	    	    	    	    	    	cin >> userType;
	    	    	    		    		}
	    	    	    		    	    cout << "Enter animal subType: ";
	    	    	    		    	    cin >> userSubType;
	    	    	    		    	 while (userSubType != "SeaLion")
	    	    	    		    	  	{
	    	    	    		    		 cout << "Invalid input. Please input 'SeaLion'\n";
	    	    	    		    		 cin.clear();
	    	    	    		    	     cin.ignore();
	    	    	    		    	     cin >> userSubType;
	    	    	    		    	  	}
	    	    	    	cout << "Enter 1 if Nursing, 0 if not: ";
	    	    	    	cin >> userNurse;
	    	    	    	//validate input
	    	    	    		    while(!cin || userNurse < 0 || userNurse > 1)
	    	    	    		    	{
	    	    	    		    	    cout << "Invalid input. Please enter 0 or 1\n";
	    	    	    		    	    cin.clear();
	    	    	    		    	    cin.ignore();
	    	    	    		    	    cin >> userNurse;
	    	    	    		    	}
	    	    	    		    char ch;
	    	    	    		    bool submenu = true;
	    	    	    		    while (submenu == true)
	    	    	    		        {
	    	    	    		    	    cout << "Enter 's' to save or 'c' to cancel\n";
	    	    	    		    	    cin >> ch;
	    	    	    		     		    	if (ch == 's')
	    	    	    		       		    	{
	    	    	    		     		    		SeaLion newsea(userTrackNum,userName,userNurse);
	    	    	    		     		    		zoovector.push_back(newsea);
	    	    	    		       		    			submenu = false;
	    	    	    		        		    	}
	    	    	    		       		    	else if (ch == 'c')
	    	    	    		       		    	{
	    	    	    		       		    		submenu = false;
	    	    	    		        		    	}
	    	    	    		       		    	else
	    	    	    		       		    	{
	    	    	    		       		    		cout << "Invalid input\n";
	    	    	    		       		    		cin.clear();
	    	    	    		       		    		cin.ignore();
	    	    	    		        		    	}
	    	    	    		    }

	    	    	    	break;
	    	    	    }
	    case 7:
	    	cout << "Now Exiting...\n";
	    		menu=false;
	    	break;
	    default:
	    	cout << "\nInvalid Option\n";
	    	    cin.clear();
	    	    cin.ignore(10000, '\n');
	    }
	   }while (menu==true);

}

//Remove animal object from vector by tracking number or name
void RemoveAnimal()
{
	std::string removeName;
	int removeNum;
	char c;
	bool submenu = true;

	//ask user to enter either tracking number or name to remove animal object from vector
while (submenu == true) {
	cout << "Enter the name or tracking number of the animal you would like "
		 << "to delete: ";
	cin >> removeName;

	//check is input is integer or string
	std::istringstream inttest(removeName);
	if (inttest>>removeNum) {
	    //it's an integer. remove by tracking number
	    cout << "Would you like to delete " << removeNum << "? press 'y' to confirm or 'c' to cancel\n";
	    cin >> c;
	    if (c == 'y')
	    	   	{
	    	for (int i = 0; i < zoovector.size(); ++i)
	    		{
	    			if(zoovector[i].name == removeName || zoovector[i].TrackNum == removeNum)
	    			{
	    				zoovector.erase(zoovector.begin()+i);
	    				cout << "Animal successfully deleted\n";
	    				break;
	    			}
	    		}
	    	    	submenu = false;
	    	   	}
	    	    	else if (c == 'c')
	    	   	    	{
	    	      	submenu = false;
	    	        	}
	    	       	else
	    	        	{
	    	        		cout << "Invalid input\n";
	    	        		cin.clear();
	    	        		cin.ignore();
	    	        	}
	} else {
		//it's a string. remove by name
			    cout << "Would you like to delete " << removeName << "? press 'y' to confirm or 'c' to cancel\n";
			    cin >> c;
			    if (c == 'y')
			    	   	{
			    	for (int i = 0; i < zoovector.size(); ++i)
			    		{
			    			if(zoovector[i].name == removeName || zoovector[i].TrackNum == removeNum)
			    			{
			    				zoovector.erase(zoovector.begin()+i);
			    				cout << "Animal successfully deleted\n";
			    				break;
			    			}
			    		}
			    	    	submenu = false;
			    	   	}
			    	    	else if (c == 'c')
			    	   	    	{
			    	      	submenu = false;
			    	        	}
			    	       	else
			    	        	{
			    	        		cout << "Invalid input\n";
			    	        		cin.clear();
			    	        		cin.ignore();
			    	        	}
	}


}

}

//display vector in tabular format
void DisplayData()
{
cout << "Track# |  Name         | Type         | Subtype        | Eggs | Nurse\n";
cout << "----------------------------------------------------------------------\n";
	for (int i=0; i<zoovector.size(); i++){
				    cout << setw(6) << zoovector[i].TrackNum << setw(16) << zoovector[i].name
				    		<< setw(16) << zoovector[i].type << setw(16) << zoovector[i].subType
								<< setw(5) << zoovector[i].eggs << setw(7) << zoovector[i].nurse << " \n";
				}
}

//load data from txt file into vector
void LoadDataFromFile()
{
		ifstream inputFile;
			int txtTrackingNum;
			string txtName;
			string txtType;
			string txtSubType;
			int txtEggs;
			int txtNurse;

			//open txt file
			inputFile.open("zoodata.txt");
			//clear vector
			zoovector.clear();

			//loop though each animal in the txt file to create a new animal object and store in vector
			while(inputFile >> txtTrackingNum >> txtName >> txtType >> txtSubType >> txtEggs >> txtNurse)
			{
				Animal newan(txtTrackingNum,txtName, txtType, txtSubType, txtEggs, txtNurse);
				    zoovector.push_back(newan);
			}
			cout << "Load complete.\n";
			inputFile.close();
}

//output vector to txt file
void SaveDataToFile()
{
	ofstream outputFile;
		int count = 0;
		int maxNum;
		int txtTrackingNum;
		string txtName;
		string txtType;
		string txtSubType;
		int txtEggs;
		int txtNurse;

		maxNum = zoovector.size();

		//open txt file
		outputFile.open("zoodata.txt");
		//clear txt file
		outputFile.clear();
		//loop through each animal object in vector and output to txt file
		for (int i=0; i<zoovector.size(); i++){
		    outputFile << setw(6) << zoovector[i].TrackNum << setw(16) << zoovector[i].name
		   		<< setw(16) << zoovector[i].type << setw(16) << zoovector[i].subType
					<< setw(5) << zoovector[i].eggs << setw(7) << zoovector[i].nurse << " \n";
		}
		cout << "Save successfully completed.\n";
		outputFile.close();
}

//display main menu
void DisplayMenu()
{
	//loop through menu until user exits
    int option;
    bool menu = true;
   do {
    cout << "\t*MENU*\n";
    cout << "**********************\n";
    cout << "1.Add Animal\n2.Remove Animal\n3.Load Data From File\n4.Save Data To File\n5.Generate Data\n6.Display Data\n7.Exit\n\nEnter Option: ";
    cin >> option;
    switch(option)
    {
    case 1:
    	AddAnimal();
    	break;
    case 2:
    	RemoveAnimal();
    	break;
    case 3:
    	LoadDataFromFile();
    	break;
    case 4:
    	SaveDataToFile();
    	break;
    case 5:
    	GenerateData();
    	break;
    case 6:
    	DisplayData();
    	break;
    case 7:
    	cout << "Now Exiting...";
    	menu=false;
    	break;
    default:
    	cout << "\nInvalid Option\n";
    	cin.clear();
    	cin.ignore(10000, '\n');
    }
   }while (menu==true);
}


int main()
{
	Goose newbat1(1245,"luna", 3);
		zoovector.push_back(newbat1);
		Bat newbat2(89524,"izzy", 1);
		zoovector.push_back(newbat2);
		DisplayData();
	DisplayMenu();
	return 1;
}
