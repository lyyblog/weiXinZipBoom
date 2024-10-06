#include"unzip_w.h"
#include<iostream>
#include<thread>
#include<vector>
#include<conio.h>
#include <time.h>

#pragma GCC optimize(3)

using namespace std;

void add(string& str, int bit = 0) {
	if (str[bit] == '9') {
		str[bit] = '0';
		add(str, bit + 1);
	}
	else {
		str[bit]++;
	}
}

int bb = 0;
bool flag = true;
unsigned long long tick;
char path[MAX_PATH];

void threadFind(string str) {
	while (flag) {
		bb++;
		int out = 0;
		HZIP hz = OpenZip(path, str.c_str());
		string l = "";
		int v = UnzipItem(hz, 0, "", l);
		if (v != ZR_OK) {
			goto END;
		}
		if (l.substr(0, 4) != "%PDF") {
			goto END;
		}
		flag = false;
		tick = time(0) - tick;
		Sleep(100);
		cout << "\n\n\n\n\x1b[0m$ The Password Is Ok!\n";
		cout << "$ \x1b[1mtime\x1b[0m:" << tick << " \x1b[1mPDF HEAD\x1b[0m:\x1b[2m\"";
		while (l.size()<=out|| l[out] != '\n') {
			cout << l[out];
			out++;
		}
		cout << " ...\"\x1b[0m \x1b[1mpwd\x1b[0m:\x1b[38;2;200;200;50m" << str << endl;
		CloseZip(hz);
		return;
	END:CloseZip(hz);
		add(str);
	}
}

int main() {
	cout << "input zip path:\x1b[2m";
	cin >> path;
	cout << "\x1b[0m\x1b[?25l\x1b[s";
	tick = time(0);
	// 20 THREAD
	thread thread01(threadFind, string("000000")); thread thread02(threadFind, string("000050"));
	thread thread03(threadFind, string("000001")); thread thread04(threadFind, string("000051"));
	thread thread05(threadFind, string("000002")); thread thread06(threadFind, string("000052"));
	thread thread07(threadFind, string("000003")); thread thread08(threadFind, string("000053"));
	thread thread09(threadFind, string("000004")); thread thread10(threadFind, string("000054"));
	thread thread11(threadFind, string("000005")); thread thread12(threadFind, string("000055"));
	thread thread13(threadFind, string("000006")); thread thread14(threadFind, string("000056"));
	thread thread15(threadFind, string("000007")); thread thread16(threadFind, string("000057"));
	thread thread17(threadFind, string("000008")); thread thread18(threadFind, string("000058"));
	thread thread19(threadFind, string("000009")); thread thread20(threadFind, string("000059"));
#ifdef THREAD40
	thread _thread01(threadFind, string("000500")); thread _thread02(threadFind, string("000550"));
	thread _thread03(threadFind, string("000501")); thread _thread04(threadFind, string("000551"));
	thread _thread05(threadFind, string("000502")); thread _thread06(threadFind, string("000552"));
	thread _thread07(threadFind, string("000503")); thread _thread08(threadFind, string("000553"));
	thread _thread09(threadFind, string("000504")); thread _thread10(threadFind, string("000554"));
	thread _thread11(threadFind, string("000505")); thread _thread12(threadFind, string("000555"));
	thread _thread13(threadFind, string("000506")); thread _thread14(threadFind, string("000556"));
	thread _thread15(threadFind, string("000507")); thread _thread16(threadFind, string("000557"));
	thread _thread17(threadFind, string("000508")); thread _thread18(threadFind, string("000558"));
	thread _thread19(threadFind, string("000509")); thread _thread20(threadFind, string("000559"));
#endif
	string block[10] = { " ","▏","▎","▍","▌","▋","▊","▉","█"};
	while (flag) {
		cout << "\x1b[u\x1b[0m\x1b[38;2;200;50;50m" << bb << "\x1b[0m/\x1b[0m\x1b[38;2;50;50;200m1010000\x1b[0m\n\x1b[38;2;255;255;255m\x1b[48;2;50;50;50m";
		for (int i = 0; i < 50; i++) {
			if (i * 20200 <= bb) {
				cout << block[8];
			}
			else if((i-1)*20200 >= bb){
				cout << block[0];
			}
			else {
				cout << block[bb%20200*8/20200];
			}
		}
		Sleep(1);
	}
	cout << "\x1b[u\x1b[0m\x1b[38;2;200;50;50m" << 1010000 << "\x1b[0m/\x1b[0m\x1b[38;2;50;50;200m1010000\x1b[0m\n\x1b[38;2;255;255;255m\x1b[48;2;50;50;50m";
	cout << "██████████████████████████████████████████████████";
	thread01.join(); thread02.join(); thread03.join(); thread04.join();
	thread05.join(); thread06.join(); thread07.join(); thread08.join();
	thread09.join(); thread10.join(); thread11.join(); thread12.join();
	thread13.join(); thread14.join(); thread15.join(); thread16.join();
	thread17.join(); thread18.join(); thread19.join(); thread20.join();
#ifdef THREAD40
	_thread01.join(); _thread02.join(); _thread03.join(); _thread04.join();
	_thread05.join(); _thread06.join(); _thread07.join(); _thread08.join();
	_thread09.join(); _thread10.join(); _thread11.join(); _thread12.join();
	_thread13.join(); _thread14.join(); _thread15.join(); _thread16.join();
	_thread17.join(); _thread18.join(); _thread19.join(); _thread20.join();
#endif
	_getch();
	return 0;
}