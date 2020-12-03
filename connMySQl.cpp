#include "connMySQl.h"
#include <string.h>

using namespace std;

void checkDB()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "password", "administration", 3306, NULL, 0);

	if (conn)
	{
		string query = "SELECT * FROM users";
		int qstate = 0;
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				cout << "ID: " << row[0] << " " << "Name: " << row[1] << " " << "Password: " << row[2] << " " << "Phone: " << row[3] << endl;
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) <<endl;
		}
	}
	else {
		cout << "Connection to database has failed!" << endl;
	}

}

void insertUser() {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "password", "administration", 3306, NULL, 0);

	if (conn)
	{
		string name;
		string password;
		string phone;

		cout << "Enter the name: " << endl;
		cin >> name;

		cout << "Enter the password: " << endl;
		cin >> password;

		cout << "Enter the phone: " << endl;
		cin >> phone;

		stringstream ss1;
		ss1 << "INSERT INTO users (name, password, phone) VALUES('" << name << "','" << password << "','" << phone << "')";
		string query = ss1.str();
		int qstate = 0;
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			cout << "User added" << endl;
		}
		else
		{
			cout << "Insert Error" << mysql_error(conn) << endl;
		}
	}
	else {
		cout << "Connection to database has failed!" << endl;
	}
}