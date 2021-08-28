/************************header  files****************/

#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
int q, w;
/************ CLASS FOR GETTING DETAILS OF DOCTORS ************/
class Doctor
{
	int dage, dcode;
	char quali[40], dept[40], dname[40], dob[15], dcno[11];
	float fees;
public:
	void dget()
	{
		cout << "\nenter doctor name      :";cin >> dname;
		cout << "\n enter the age         :";cin >> dage;
		cout << "\n enter the dob         :";cin >> dob;
		cout << "\n qualification         :";cin >> quali;
		cout << "\n special in:           :";cin >> dept;
		cout << "\n consulting fees       :";cin >> fees;
		cout << "\n doctor ID             :";cin >> dcode;
		cout << "\n contact no.           :";cin >> dcno;
	}
	void dput()
	{
		cout << "\nID            :" << dcode;
		cout << "\n name         :" << dname;
		cout << "\n age          :" << dage;
		cout << "\n dob          :" << dob;
		cout << "\n qualification:" << quali;
		cout << "\n specialist   :" << dept;
		cout << "\n fees         :" << fees;
		cout << "\ncontact no.   :" << dcno;
	}
	int check()
	{
		return dcode;
	}
	void modi()
	{
		int dage1, dcode1, x;
		char quali1[40], dept1[40], dname1[40], dob1[15], dcno1[11];
		float fees1;
		cout << "\n************************************************************";
		cout << "\n1.modify doctor name";
		cout << "\n2.modify doctor age";
		cout << "\n3.modify dob";
		cout << "\n4.modify qualification";
		cout << "\n5.modify core specialist";
		cout << "\n6.modify consulting fees";
		cout << "\n7.modify doctor ID";
		cout << "\n8.modify contact no.";
		cout << "\n************************************************************";
		cout << "\n enter your choice:";cin >> x;
		if (x == 1)
		{
			cout << "\nenter doctor name      :";cin >> dname1;  strcpy_s(dname, dname1);
		}
		else if (x == 2) {
			cout << "\n enter the age         :";cin >> dage1;  dage = dage1;
		}
		else if (x == 3) {
			cout << "\n enter the dob         :";cin >> dob1;  strcpy_s(dob, dob1);
		}

		else if (x == 4) {
			cout << "\n qualification         :";cin >> quali1;  strcpy_s(quali, quali1);
		}
		else if (x == 5) {
			cout << "\n special in:           :";cin >> dept1;   strcpy_s(dept, dept1);
		}
		else if (x == 6) {
			cout << "\n consulting fees       :";cin >> fees1;  fees = fees1;
		}
		else if (x == 7) {
			cout << "\n doctor ID             :";cin >> dcode1;dcode = dcode1;
		}
		else if (x == 8) {
			cout << "\n contact no.           :"; cin >> dcno1; strcpy_s(dcno, dcno1);
		}
		else cout << "\n SORRY ! choice not avail";
	}
	char* fcheck()
	{
		return dept;
	}
	float fee() { return fees; }
}d;
//********************* PATIENT CLASS *******************  //
class Patient
{
	char pname[40], pdob[20], problem[30], bgrp[20], pcno[11];
	int page, pcode;
public:
	void pget()
	{
		cout << "\nenter patient name      :";cin >> pname;
		cout << "\n enter dob of patient   :";cin >> pdob;
		cout << "\n patient age            :";cin >> page;
		cout << "\n problem with patient   :";cin >> problem;
		cout << "\n blood group            :";cin >> bgrp;
		cout << "\n contact no             :";cin >> pcno;
		cout << "\n patient id             :";cin >> pcode;
	}
	void pput()
	{
		cout << "\nname        :" << pname;
		cout << "\nage         :" << page;
		cout << "\nproblem     :" << problem;
		cout << "\n blood group:" << bgrp;
		cout << "\n contact no :" << pcno;
		cout << "\n pID        :" << pcode;

	}
	int pcheck()
	{
		return pcode;
	}
	void pmodi()
	{
		char pname1[40], pdob1[20], problem1[30], bgrp1[20], pcno1[11];
		int page1, pcode1, x;
		cout << "\n************************************************************";
		cout << "\n1.modify patient name";
		cout << "\n2.modify dob";
		cout << "\n3.modify patient age";
		cout << "\n4.modify problem";
		cout << "\n5.modify core specialist";
		cout << "\n6.modify blood group";
		cout << "\n7.modify contact no";
		cout << "\n8.modify patient ID";
		cout << "\n************************************************************";
		cout << "\n enter your choice:";cin >> x;
		cout << "\nenter new details \n\n	";
		if (x == 1) {
			cout << "\nenter patient name      :";cin >> pname1; strcpy_s(pname, pname1);
		}
		else if (x == 2) {
			cout << "\n enter dob of patient   :";cin >> pdob1; strcpy_s(pdob, pdob1);
		}
		else if (x == 3) {
			cout << "\n patient age            :";cin >> page1; page = page1;
		}
		else if (x == 4) {
			cout << "\n problem with patient   :";cin >> problem1; strcpy_s(problem, problem1);
		}
		else if (x == 5) {
			cout << "\n blood group            :";cin >> bgrp1; strcpy_s(bgrp, bgrp1);
		}
		else if (x == 6) {
			cout << "\n contact no             :";cin >> pcno1;strcpy_s(pcno, pcno1);
		}
		else if (x == 7) {
			cout << "\n patient id             :";cin >> pcode1;pcode = pcode1;
		}
		else cout << "\nSORRY! wrong choice";
	}
	char* gcheck()
	{
		return problem;
	}
}p;
/************************** appending doctor details ******/
void dappend()
{
	char c = 'y';int x = 0;
	ofstream fout("doctor.dat", ios::binary | ios::app);
	cout << "\n****************************************************\n";
	cout << " \n            DOCTOR DETAILS           \n";
	cout << "\n****************************************************\n";
	while (c == 'y' || c == 'Y')
	{
		cout << "\n ENTER THE DETAILS";
		d.dget();
		fout.write((char*)&d, sizeof(d));
		cout << "\n enter y or Y to continue appending n to stop:";
		cin >> c;
		x++;
	}     q = x;
	fout.close();
}
//************************* appending patient details **********//
void pappend()
{
	char c = 'y';int x = 0;
	ofstream fout("patient.dat", ios::binary | ios::app);
	cout << "\n****************************************************\n";
	cout << " \n            PATIENT DETAILS           \n";
	cout << "\n****************************************************\n";
	while (c == 'y' || c == 'Y')
	{
		cout << "\n ENTER THE DETAILS";
		p.pget();
		fout.write((char*)&p, sizeof(p));
		cout << "\n enter y or Y to continue appending n to stop:";
		cin >> c;
		x++;
	}  w = x;
	fout.close();
}
//************************* search doctor *************//
void dsearch()
{
	int n;
	char c = 'y';
	cout << "\nenter the id no to be searched:";
	cin >> n;
	ifstream fin("doctor.dat", ios::binary);
	while (!fin.eof())
	{
		fin.read((char*)&d, sizeof(d));
		if (d.check() == n)
		{
			d.dput();
			c = 'n';break;
		}
	}
	if (c == 'y')
		cout << "\n record not found";
	fin.close();
}
//******************** searching patient **********//
void psearch()
{
	int n;
	char c = 'y';
	cout << "\nenter the id no to be searched:";
	cin >> n;
	ifstream fin("patient.dat", ios::binary);
	while (!fin.eof())
	{
		fin.read((char*)&p, sizeof(p));
		if (p.pcheck() == n)
		{
			p.pput();
			c = 'n';break;
		}
	}
	if (c == 'y')
		cout << "\n record not found";
	fin.close();

}
//******************** doctor modification **********//
void dmodify()
{
	int n;long p;char c = 'y';
	fstream f("doctor.dat", ios::binary | ios::in | ios::out);
	cout << "\n enter the doctor id to be modified:";cin >> n;
	while (!f.eof())
	{
		p = f.tellg();
		f.read((char*)&d, sizeof(d));
		if (d.check() == n)
		{
			d.modi();
			f.seekg(p);
			f.write((char*)&d, sizeof(d));
			c = 'n';
			cout << "\n record modified";
			break;
		}
	}
	if (c == 'y')
		cout << "\n record not found";
	f.close();
}
//********************* patient modification **************//
void pmodify()
{
	int n;long q;char c = 'y';
	fstream f("patient.dat", ios::binary | ios::in | ios::out);
	cout << "\n enter the patient id to be modified:";cin >> n;
	while (!f.eof())
	{
		q = f.tellg();
		f.read((char*)&p, sizeof(p));
		if (p.pcheck() == n)
		{
			p.pmodi();
			f.seekg(q);
			f.write((char*)&p, sizeof(p));
			c = 'n';
			cout << "\n record modified";   f.close();
			break;
		}
	}
	if (c == 'y')
		cout << "\n record not found";
	f.close();

}
//********************* deletion doctor record ***************//
void ddelete()
{
	int n, x = 0;
	ofstream fout("temp.dat", ios::binary);
	ifstream fin("doctor.dat", ios::binary);
	cout << "\n enter the ID no to be deleted:";cin >> n;
	while (!fin.eof())
	{
		fin.read((char*)&d, sizeof(d));
		if (d.check() == n)
		{
			cout << "\n record deleted";x = 1;fin.close();fout.close();break;
		}
		else fout.write((char*)&d, sizeof(d));
	}
	if (x == 0)
		cout << "\n record not found";
	fin.close();fout.close();
	remove("doctor.dat");rename("temp.dat", "doctor.dat");
}
//************************** delete patient records ***********//
void pdelete()
{
	int n, x = 0;
	ofstream fout("temp.dat", ios::binary);
	ifstream fin("patient.dat", ios::binary);
	cout << "\n enter the ID no to be deleted:";cin >> n;
	while (!fin.eof())
	{
		fin.read((char*)&p, sizeof(p));
		if (p.pcheck() == n)
		{
			cout << "\n record deleted";x = 1;fin.close();fout.close();break;
		}
		else fout.write((char*)&p, sizeof(p));
	}
	if (x == 0)
		cout << "\n record not found";
	fin.close();fout.close();
	remove("patient.dat");rename("temp.dat", "patient.dat");
}
//*********************show records
void dshow()
{
	ifstream fin("doctor.dat", ios::binary);
	q = 0;
	while (fin.read((char*)&d, sizeof(d)))
	{
		d.dput();cout << endl; q++;
	}
	cout << "\n total doctor records= " << q;
	fin.close();
}
//////////////////////////////////
void pshow()
{
	ifstream fin("patient.dat", ios::binary);
	w = 0;
	while (fin.read((char*)&p, sizeof(p)))
	{
		p.pput();cout << endl;w++;
	}
	cout << "\n total patient records= " << w;
	fin.close();
}
///////////////////////// assign doctor and cal fees
void pdoc()
{
	int n;char prob[30];
	ifstream f1("doctor.dat", ios::binary);
	ifstream f2("patient.dat", ios::binary);
	cout << "\n enter patient id:";cin >> n;
	while (!f2.eof())
	{
		f2.read((char*)&p, sizeof(p));
		if (n == p.pcheck())
		{
			strcpy_s(prob, p.gcheck());break;
		}
	}
	f2.close();float fees;
	while (!f1.eof())
	{
		f1.read((char*)&d, sizeof(d));
		if (strcmp(d.fcheck(), prob) == 0)
		{
			cout << "\nhere is the required doctor details\n\n";
			d.dput();
			fees = d.fee();
			break;
		}
	}
	f1.close();
	cout << "\n\n\n";
	cout << "\nsrdkvv hospital";
	cout << "\npatient fees\n\n";
	cout << "general hospital fee=100\n";
	cout << "doctor consulting fee=" << fees;
	cout << "\ntotal fees=" << fees + 100;
	cout << "\n\n stay healthy";
}
//*********************choices*********************
void welcome()
{
	system("cls");
	cout << "\t\t|||******** WELCOME TO SN HOSPITAL ********|||\n\n";
	cout << "**********************************************************************";
	cout << "\n\n1.main menu ";
	cout << "\n2.shut down";
	cout << "\n\n******************************************************************";
	cout << "\n enter your choice: ";
}
//////////////////////////////////
void mainmenu()
{
	system("cls");
	cout << "**********************************************************************";
	cout << "\n\n1.doctor database";
	cout << "\n2.patient database";
	cout << "\n3.back";
	cout << "\n\n********************************************************************";
	cout << "\n enter your choice: ";
}
//////////////////////////////////
void doctordatabase()
{
	system("cls");
	cout << "***********************************************************************";
	cout << "\n\n1.add new doctor details ";
	cout << "\n2.search doctors details";
	cout << "\n3.delete doctor details";
	cout << "\n4.modify doctor details";
	cout << "\n5.show all details";
	cout << "\n6.back to main menu";
	cout << "\n\n********************************************************************";
	cout << "\n NOTE: special in should be given in keywords like heart,ent,skin,...";
	cout << "\n\aenter your choice: ";
}
/////////////////////////////
void patientdatabase()
{
	system("cls");
	cout << "***********************************************************************";
	cout << "\n\n1.add patient details ";
	cout << "\n2.search patient details";
	cout << "\n3.delete patient details";
	cout << "\n4.modify patient details";
	cout << "\n5.show all details";
	cout << "\n6.doctor required and total fees";
	cout << "\n7.back to main menu";
	cout << "\n\n********************************************************************";
	cout << "\n NOTE: problems should be given in keywords like heart,ent,skin,...with respect to doctorspecial in";
	cout << "\n\aenter your choice: ";
}
int main()
{
	system("cls");
	int a, b, c, d;
wel:
	welcome();
	cin >> a;
	switch (a)  //main menu
	{
	case 1:
	{mm:
		mainmenu();
		cin >> b;
		switch (b)             //doctor and patient database
		{
		case 1:
		{ddb:
			doctordatabase();
			cin >> c;
			system("cls");
			switch (c)                          //ddb list
			{
			case 1: {dappend();_getch();goto ddb;}
			case 2: {dsearch();_getch();goto ddb;}
			case 3: {ddelete();_getch();goto ddb;}
			case 4: {dmodify();_getch();goto ddb;}
			case 5: {dshow();_getch();goto ddb;}
			case 6:goto mm;   default:cout << "\n wrong choice"; goto ddb;
			}
		}
		case 2:
		{
		pdb:
			patientdatabase();
			cin >> d;
			system("cls");
			switch (d)                               //pdb list
			{

			case 1: {pappend();_getch();goto pdb;}
			case 2: {psearch();_getch();goto pdb;}
			case 3: {pdelete();_getch();goto pdb;}
			case 4: {pmodify();_getch();goto pdb;}
			case 5: {pshow();_getch();goto pdb;}
			case 6: {pdoc();_getch();goto pdb;}
			case 7:goto mm;  default:cout << "\n wrong choice"; goto pdb;
			}
		}
		case 3:goto wel; default:cout << "\n wrong choice"; goto mm;
		}
	}
	case 2:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Shutting Down.........\n\t\t\t\t    SN Hospitals\n\t\t\t\t";
	}  break;
	default:cout << "\n wrong choice"; goto wel;
	}
	return 0;
}
