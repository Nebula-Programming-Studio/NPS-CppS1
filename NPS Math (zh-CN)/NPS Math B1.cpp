/*  NPS Math
    Beta 1.0
	Build 20240812
	Lang

	����Beta�汾��
	�������뷽ʽ����������������
	��ĺ�����Errors; InputCheck; Calculate; main
	����������Input
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

char Ope='#', Op='#';					//״̬,�����
long double Ans=0;						//����
long double N1=66, N2=666;				//����
int Err=0;								//������롢
string Inp;								//����

void Errors (){							//���󱨸�
	cout << "\n���ִ���: ���������";
	
	if (Err>=1 && Err<=3){
	    cout << "��ʽ��";
		switch (Err){
	        case 1:
				cout << "����";
				break;
	        case 2:
				cout << "�����";
				break;
	        case 3:
				cout << "��ʽ";
	    }
		cout << "�Ƿ�������";
	}
	if (Err==4){
	    cout << "��ʽ�ĳ����Ƿ�������";
	}
	if (Err==5){
	    cout << "�����Ƿ���ȷ��";
	}
	if (Err==6){
	    cout << "�����Ƿ�Ϊ�ա�";
	}
	if (Err==7){
		cout << "��ʽ�Ƿ�Ϊ�ա�";
	}
	if (Err==8){
	    cout << "��ʽ��";
	}
	
	cout << "\n";
	Ope='m';
	Err=0;
}

bool InputCheck (){						//������
    if (Op=='#' && N1==66){
		Err=7;
		return false;
	}
	if (N1==66 || N2==666 || Op=='#'){
	    Err=3;
		return false;
	}
	if (Op!='+' && Op!='-' && Op!='*' && Op!='/'){
	    Err=2;
		return false;
	}
	if (Op=='/' && N2==0){
	    Err=4;
		return false;
	}
	
	Err=0;
	return true;
}

void Input (){							//����
    cout << "�����һ������";
	cin >> N1;
	cout << "�����������";
	cin >> Op;
	cout << "����ڶ�������";
	cin >> N2;

	std::string n1 = std::to_string(N1);
    std::string op = std::to_string(Op);
    std::string n2 = std::to_string(N2);
	Inp = n1 + op + n2;
}

void Calculate (){						//����
	switch (Op){
	case '+': 
		Ans=N1+N2;
		break;
	case '-':
		Ans=N1-N2;
		break;
	case '*':
		Ans=N1*N2;
		break;
	case '/':
		Ans=N1/N2;
	}
}

void Operate (){						//����
    cout << "\n������壺\n";
	cout << "[c] �������  [e] �˳�����  [u] ����ʹ��  [i] ʹ��ָ��\n";
	cin >> Ope;

	switch (Ope){
	case 'c':
		system("cls");
		Ope='m';
		break;
	case 'e':
		exit(0);
	case 'u':
		break;
	case 'i':
		cout << "\nʹ��ָ�ϣ�\n";
		cout << "����֧��+ - * /(�� �� �� ��)\n";
		Ope='m';
	default:
		if (Ope=='#') Err=6; break;
		Err=5;
		Errors ();
	}

	if (Ope=='m'){
	Operate ();
	}
}

int main (){							//������
    cout << "*NPS Math  Beta1.0\n";
	cout << "*����: Lang\n";
	cout << "*����Դ���������ѧϰ������Ҳ��������ҵ��;\n\n";

	do {
		Input();

		if ( InputCheck() ){
		    Calculate ();
			cout << "����: " << Ans << "\n";
		}
		else {
			Errors ();
		}

		Operate();
	} while (Ope=='u');
}
