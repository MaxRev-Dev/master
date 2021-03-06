#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <tchar.h>
#include <thread>
#include <atomic>

using namespace std;
#include "writer.h"
#include "SimpleIni.h"
#include "dirent.h"


	class connectFiles
	{
	private:
		char buffer[256];
		char chr1[15];
		char chr2[15];
		char chr3[15];
		char chr4[15];
		DIR *dir;
		struct dirent *ent;
		int *fullsz = new int;
		string	str;
		

	public:
		void mkstr(int);
		connectFiles(string &);
		int IO(string&, string), e;
		int init(string &);
		int hell();
		bool CreateDir(TCHAR *);
		string der();
		void cpst(char *, char *);

		int defaultConf(string &);
		string defdir;
		const string defconf = "config.ini";
		char *c_full = new char[100];
		char *c_defconf = new char[50];
		char *c_defdir = new char[50];
		char *c_full1 = new char[100];
		char *c_full2 = new char[100];
		char *c_full3 = new char[100];
	};
	class textGen {
	private:
		vector<char>vec_sup;
		vector<char>ctr;
		vector<char>mirror;
		string mark = "";
		bool clicker = false;
		string itr = "";
		int c = 1, i = 1;
		long long x = 0, tx = 0, curTP = 0;
		char cr = 0;
		
	public:
		bool animateThis;
		thread th2;
		atomic<bool> tick;
		vector<char>vcr;
		textGen(string &);
		void nextChr(vector<char> &);
		void nextMark(ifstream &);
		void vecTF(ofstream &);
		void getTitle(ifstream &);
		void getQues(ifstream &);
		void getCartPos(long long&, int);
		void startThreadAnim();
		void stopThreadAnim();
		void animate();
		void inTime(ofstream&);
	};
