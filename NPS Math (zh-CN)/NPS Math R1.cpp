#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
char Ope='#', Op='#';
long double Ans=0;
long double N1=55.5, N2=316.001;
int Err=0;
void Errors (){
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
bool InputCheck (){
    if (Op=='#' && N1==55.5){
		Err=7;
		return false;
	}
	if (N1==55.5 || N2==316.001 || Op=='#'){
	    Err=3;
		return false;
	}
	if (Op!='+' && Op!='-' && Op!='*' && Op!='/' && Op!='^' && Op!='q' && Op!='i' && Op!='o' && Op!='c' && Op!='s' && Op!='a'){
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
void Input (){
    cout << "�����һ������";
	cin >> N1;
	cout << "�����������";
	cin >> Op;
	cout << "����ڶ�������";
	cin >> N2;
}
void Calculate (){
	switch (Op){
        case '+': Ans=N1+N2; break;
        case '-': Ans=N1-N2; break;
        case '*': Ans=N1*N2; break;
        case '/': Ans=N1/N2; break;
        case '^': Ans=pow (N1, N2); break;
        case 'q': Ans=sqrt (N1); break;
        case 'i': Ans=sin (N1); break;
		case 'o': Ans=cos (N1); break;
        case 'c': Ans=acos (N1); break;
        case 's': Ans=asin (N1); break;
        case 'a': Ans=tan (N1);
    }
}
void Operate (){					
    Err=0;
    cout << "������壺\n";
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
		cout << "+ - * / ^(�� �� �� �� ��)\n";
		cout << "q i o c s a(���� ���� ���� ������ ������ ����)\n";
		Ope='m';
	case '#':
        Err=6;
    default:
		Err=5;
	}
    if (Err!=0) Errors ();
	if (Ope=='m') Operate ();
}
int main (){
    cout << "NPS Math\n��ʽ�� 1.3\n���ߣ�Lang\n����Դ����������κ���;�����������Դ������\n\n";
	do {
		Input();
		if (InputCheck()){
		    Calculate ();
			cout << "����: " << Ans << "\n\n";
		}
		else Errors ();
		Operate();
	} while (Ope=='u');
}
