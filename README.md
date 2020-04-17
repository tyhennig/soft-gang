# soft-gang
Created by:
Tyler Hennig, Rafael Amaro, Kora Lopez, Abraham Solis, Jacob Carillo, Genaro Cantu, Daniel Rodriguez

This is our midterm project for Software Engineering.

The purpose of this software is to function as a point-of-sale system for the Texas A&I store located near campus.

We broke the project into 4 modules
    -Point of sale
    -Inventory Management
    -Statistics
    -GUI
	
#################################

HOW TO SET UP PROJECT

##################################

Remember to pull the newest commit from the remote repo

******SET UP DATABASE*******

The Instructions for most of this is in the database folder of the repo

A few more steps to follow though:
1. Open Microsoft SQL Management Studio
2. Connect to the server and right click to go to properties
3. Go to security tab and click the "SQL Server and Windows Authentication mode" button
4. Open the security folder at the main screen under "Databases"
5. Right-click the Logins folder and go to new login
6. Create a login name and make sure it is SQL Server authentication
7. Disable enforce password expiration
8. Hit okay to make the user
9. Give the user admin access by running a new query and typing (Don't delete the brackets)
	GRANT CONTROL SERVER TO [type whatever the name is here];
10. Next open a different program called SQL Server 2019 Configuration Manager
11. Open the Network configuration tab (not the 32bit one)
12. Under protocols double click the TCP/IP to open the properties
13. Enable to the protocol and go to the IP Addresses tab, at the bottom set IPALL TCP Port to 1433

******SET UP ENVIRONMENT*****

This will vary greatly depending on what compiler/IDE you are using.
Abraham and Tyler are using Visual Studio so the following steps are for that.

1. Right click the project name in the Solution view on the Solution explorer
2. In the properties window we are going to change a bunch of different directories
3. In the project there is a references folder, in here is files for Visual Studio 64bit compiler
	but the files will change depending on what compiler you are using.
4. Under Include Directories add the location of the Include folder in the project (References\include)
5. Library Directories add the location of the lib folder
6. C/C++ tab add include folder to the Additional Include Directories setting
7. Linker tab -> General, add Additional Library Directories (the lib folder)
8. Linker -> Input, This one is different, under additonal dependencies you have to give it the sqlapi.lib file (Mine looks like C:\Users\TylerPC\Desktop\Coding\soft-gang\References\x86_64\lib\sqlapi.lib)
9. Lastly, in the Reference folder of the project there is a sqlapi.dll file, move this to where ever your compiler creates the exe file that is run on your machine
	in visual studio it is placed in the Debug folder that VS creates.
	If you can't find where the exe is, just try to run the program and it will say where the exe file is at the top of the console.
	

	