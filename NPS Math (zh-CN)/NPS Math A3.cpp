/*	NPS Math
	Version Alpha3.0
	Build 20240724
	Lang
	*��������ʽ�ĳ�����󣬵��³����޷���������
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>
#include <windows.h>
using namespace std;

bool Err=false;					//�����־��[true]�д��� [false]�޴���
char Ope='m';					//״̬��־(������)��[m]�˵� [c]��� [e]�˳� [u]����ʹ��
string Inp="0";					//������ַ�������


void Errors (int err){								//���󱨸�
	cout << "\n����";
	
	switch (err){
		case 0:cout << "�쳣������������ʹ�ó���"; break;
		case 1:cout << "���벻��Ϊ��";				break;
		case 2:cout << "��ʽ��ʽ����";				break;
		case 3:cout << "δ֪�����";				break;
		case 4:cout << "��������Ϊ��";       	  	break;
		case 5:cout << "�����ʽ����";				break;
	}
	cout << "\n";
	Ope='m';
	Err=false;
}

bool InputRight (const string& inp=Inp){						//������; const����Inp��ֹ�޸�
	if (inp == "0")										Errors (1);return false;
	
	if (inp.size () != 3) 								Errors (2);return false;

	char op=inp[1];
	if (op!='+' && op!='-' && op!='*' && op!='/') 		Errors (3);return false;

	long double num2=inp[2];
	if (num2==0 && op=='/') 							Errors (4);return false;

	return true;
}

void Operate (){										//�����˵�
	cout << "��ǰ��ִ�в�����\n";
	cout << "[c] �������   [e] �˳�����   [u] ����ʹ��\n";
	cout << "��Ҫִ�еĲ�����";
	cin >> Ope;
	cout << "\n";

	switch (Ope){
		case 'c': system("cls"); Ope='m';		break;
		case 'e': 								break;
		case 'u': 								break;
		default: Errors (5);					break;
	}
	getchar ();
}

void Calculate (string inp){							//����
	long double num1=inp[0];
	long double num2=inp[2];
	char op=inp[1];

	switch (op){
		case '+': cout << num1 << " + " << num2 << " = " << num1+num2 << "\n"; break;
		case '-': cout << num1 << " - " << num2 << " = " << num1-num2 << "\n"; break;
		case '*': cout << num1 << " * " << num2 << " = " << num1*num2 << "\n"; break;
		case '/': cout << num1 << " / " << num2 << " = " << num1/num2 << "\n"; break;
	}
}

int main (){											//������
    cout << "*NPS Math#Alpha3.0\n";
	cout << "*���ߣ�Lang\n";
	cout << "*�����������ѧϰ��������ֹ������ҵ��;��\n\n";

	do {
		Err=false;
		cout << "��������ʽ(ֻ֧�ֽ�һ�����������ʽ)��";

		getline (cin, Inp);
		if (InputRight (Inp)) Calculate (Inp);
		Operate;
		
		while (Ope == 'm') Operate;
		if (Ope == 'e') exit (0);
	} while (Ope=='u' || Ope!='m');
}
