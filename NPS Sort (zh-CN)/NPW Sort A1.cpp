/*  NPW Sort
    Alpha 1.7
    Build 20240814
    Lang
*/

#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

char Ope = 'm'; //������
char OpA = '!'; //Aѡ��
int N = 0; //����Ԫ������
vector<int> A; //����
int Err = 0; //�����ʶ

void Errors () { //���󱨸�
	Ope = 'm';
	cout << "\n";
	cout << "���󱨸棺";

	switch ( Err ) {
		case 2:
			cout << "�����ѡ���ȷ";
			break;
		case 3:
			cout << "�������";
			break;
		case 1:
			cout << "���벻��Ϊ��";
			break;
	}

	Err = 0;
	cout << "\n";
}

bool Check () { //���
	Err = 0;

	if ( OpA == '!' ) {
		Err = 1;
		return false;
	}

	if ( OpA != 'z' && OpA != 'x' ) {
		Err = 2;
		return false;
	}

	if ( N < 2 ) {
		Err = 3;
		return false;
	}

	return true;
}

void zA () { //�Զ����A
	A.clear ();
	int x;

	srand ( time ( 0 ) );
	for ( int i = 0; i <= N; i++ ) {
		x = rand ();
		A.push_back ( x );
	}
}

void xA () { //�ֶ�����A
	A.clear ();
	int x;

	cout << "\n�������1λ��ʼ����������(�ÿո����)��";
	for ( int i = 0; i <= N; i++ ) {
		cin >> x;
		A.push_back ( x );
	}
}

void Input () { //��ʼ�Զ���
	cout << "\n[z]�����������";
	cout << "\n[x]�Զ�������";
	cout << "\nѡ�";
	cin >> OpA;
	cout << "\n����������������";
	cin >> N;
	N -= 1; //У��
}

void Output () { //���
	for ( int i = 0; i <= N; i++ ) {
		cout << A[i] << " ";
	}
	cout << "\b";
}

int main () { //������
	cout << "*NPW Sort\n*Alpha1.7\n";
	cout << "*����: Lang\n";
	cout << "*����Դ���������ѧϰ������Ҳ��������ҵ��; :)\n\n";

	do {
		Input ();
		if ( !Check () ) {
			Errors ();
		} else {
			if ( OpA == 'z' ) {
				zA ();
				Output ();
			} else {
				xA ();
				Output ();
			}
		}
	} while ( Ope == 'u' );
	return 0;
}
