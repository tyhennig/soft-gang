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

This will vary greatly depending on what compiler/IDE you are using.
Abraham and Tyler are using Visual Studio so these steps apply to that.

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


	