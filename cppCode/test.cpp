// You can delete this line if you 
// are not using Microsoft compiler.
////////////////////////////////////////
#include <windows.h>
#include <sql.h>
#include<sqltypes.h>
#include<sqlext.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// You can delete this line if you 
// are not using Microsoft VC++ 2008/2010 compiler.
#pragma warning(disable: 4996)
////////////////////////////////////////


// Define The ODBC_Class Class
class ODBC_Class
{
	struct ColDescription
	{
		SQLSMALLINT colNumber;
		SQLCHAR colName[80];
		SQLSMALLINT nameLen;
		SQLSMALLINT dataType;
		SQLULEN colSize;
		SQLSMALLINT decimalDigits;
		SQLSMALLINT nullable;
	};
	// Attributes
public:
	SQLHANDLE EnvHandle;
	SQLHANDLE ConHandle;
	SQLHANDLE StmtHandle;
	SQLRETURN rc;
	vector<ColDescription> cols;
	vector< vector<string> > colData;
	// Operations
public:
	ODBC_Class(); // Constructor
	~ODBC_Class(); // Destructor
	SQLRETURN GetResultset();
	void DescribeColumns();
private:
	_inline SQLRETURN Describe(ColDescription& c);
	SQLRETURN GetColData(int colnum, string& str);
};

// Define The Class Constructor
ODBC_Class::ODBC_Class()
{
	// Initialize The Return Code Variable
	rc = SQL_SUCCESS;
	// Allocate An Environment Handle
	rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &EnvHandle);
	// Set The ODBC Application Version To 3.x
	if (rc == SQL_SUCCESS)
		rc = SQLSetEnvAttr(EnvHandle, SQL_ATTR_ODBC_VERSION,
			(SQLPOINTER)SQL_OV_ODBC3, SQL_IS_UINTEGER);
	// Allocate A Connection Handle
	if (rc == SQL_SUCCESS)
		rc = SQLAllocHandle(SQL_HANDLE_DBC, EnvHandle, &ConHandle);
}

// Define The Class Destructor
ODBC_Class::~ODBC_Class()
{
	// Free The Connection Handle
	if (ConHandle != NULL)
		SQLFreeHandle(SQL_HANDLE_DBC, ConHandle);
	// Free The Environment Handle
	if (EnvHandle != NULL)
		SQLFreeHandle(SQL_HANDLE_ENV, EnvHandle);
}

// Get the data for one column and return the info in the form
// of a std::string.  The ODBC driver will make all necessary
// data conversions from whatever type the data is in the database
// to SQL_CHAR.  You could make this function more comples by 
// getting the return type as it appears in the database then constructing
// a VARIANT object to hold the data.
SQLRETURN ODBC_Class::GetColData(int colnum, string& str)
{
	SQLCHAR buf[255] = { 0 };
	if ((rc = SQLGetData(StmtHandle, colnum, SQL_CHAR, buf, sizeof(buf), NULL)) == SQL_SUCCESS)
		str = reinterpret_cast<char*>(buf);
	return rc;
}

//
// Define The ShowResults() Member Function
SQLRETURN ODBC_Class::GetResultset()
{
	// Get all column description
	DescribeColumns();
	// erase anything that's in the colData vector
	colData.clear();
	// fetch a row from the resultset
	while (SQLFetch(StmtHandle) == SQL_SUCCESS)
	{
		// vector of strings to hold the column data
		vector<string> col;
		string data;
		// column counter
		int i = 1;
		// get the data for each column and add it to 
		// the col vector
		while (GetColData(i, data) == SQL_SUCCESS)
		{
			col.push_back(data);
			++i; // increment the column number
		}
		// add column data to the colData vector
		colData.push_back(col);
	}
	return SQL_SUCCESS;
}

// Get the description for one column in the resultset.
// This was made a seprate function to simplify the coding
SQLRETURN  ODBC_Class::Describe(ColDescription& c)
{
	return SQLDescribeCol(StmtHandle, c.colNumber,
		c.colName, sizeof(c.colName), &c.nameLen,
		&c.dataType, &c.colSize, &c.decimalDigits, &c.nullable);
}

// Get the description for all the columns in the resultset.
void ODBC_Class::DescribeColumns()
{
	ColDescription c;
	c.colNumber = 1;
	cols.clear();
	while (Describe(c) == SQL_SUCCESS)
	{
		cols.push_back(c);
		++c.colNumber;
	}

}


/*-----------------------------------------------------------------*/
/* The Main Function */
/*-----------------------------------------------------------------*/
int main()
{
	cout << "testing" << endl;
	// Declare The Local Memory Variables
	SQLRETURN rc = SQL_SUCCESS;
	SQLCHAR DBName[] = "master";
	SQLCHAR SQLStmt[255] = { 0 };
	// Create An Instance Of The ODBC_Class Class
	ODBC_Class Example;
	// Connect To The Northwind Sample Database
	if (Example.ConHandle != NULL)
	{
		rc = SQLConnect(Example.ConHandle, DBName, SQL_NTS,
			(SQLCHAR*)"", SQL_NTS, (SQLCHAR*)"", SQL_NTS);
		// Allocate An SQL Statement Handle
		rc = SQLAllocHandle(SQL_HANDLE_STMT, Example.ConHandle,
			&Example.StmtHandle);
		if (rc == SQL_SUCCESS)
		{
			// Define A SELECT SQL Statement
			strcpy((char*)SQLStmt, "SELECT * FROM categories");
			// Prepare And Execute The SQL Statement
			rc = SQLExecDirect(Example.StmtHandle, SQLStmt, SQL_NTS);
			// Display The Results Of The SQL Query
			if (rc == SQL_SUCCESS)
			{
				Example.GetResultset();
				// At this point you would want to do something
				// with the resultset, such as display it.
			}
		}
		// Free The SQL Statement Handle
		if (Example.StmtHandle != NULL)
			SQLFreeHandle(SQL_HANDLE_STMT, Example.StmtHandle);
		// Disconnect From The Northwind Sample Database
		rc = SQLDisconnect(Example.ConHandle);
	}
	// Return To The Operating System
	return 0;
}