#include <iostream>
//#include <string>
//#define DEBUG
using namespace std;

class mystring
{

	char *str; // ����������� ������������ ��������� ���� char. (������������� � private)
	int length;
	
public:
	mystring()
	{
#ifdef DEBUG
		cout << "�������� ����������� ������ �� ���������" << this << endl;
#endif // DEBUG
		str = nullptr;
		length = 0;
	}

	mystring(const char *word) //�����������. �������
	{
#ifdef DEBUG
		cout << "�������� ����������� ������ " << this << endl;
#endif // DEBUG
		
		length = strlen(word);
		this->str = new char [length+1]; //��������� ������������ ������ ��� ���-�� ��������� ����� + 1 ������ ��� �������������� 0
		for (int i = 0; i < length; i++)
		{
			this->str[i] = word[i]; //����������� ���� �������� ������� word ������� /0 ������ 4� ���������
		}
		this->str[length] = '\0';
			   	
	}
	
	// ������������� �������� ������������
	mystring & operator = (const mystring &word) //���������� ������ �� ��� ������ ������
	{
#ifdef DEBUG
		cout << "�������� �������� ������������ = " << this << endl;
#endif // DEBUG

		if (this->str != nullptr)
			delete[] this->str;

		length = strlen(word.str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = word.str[i];
		}
		this->str[length] = '\0';
		return *this; // �������������� ��������� �� ������ (str1) �.� �������� ����� ���������� � ��������� this ��� ������ ������ �� str1.
	}
		
	//����������� �����������
	mystring(const mystring &word) 
	{
#ifdef DEBUG
		cout << "�������� ����������� �����������" << this << endl;
#endif // DEBUG

		length = strlen(word.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = word.str[i];
		}
		this->str[length] = '\0';
	}

	//������������� �������� ��������. ��������� ��� ������������ ����� ������ string
	mystring operator + (const mystring &other)
	{
#ifdef DEBUG
		cout << "�������� �������� + " << this << endl;
#endif // DEBUG

		mystring newstr;
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newstr.length = thisLength + otherLength;
		
		newstr.str = new char[thisLength + otherLength +1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			newstr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++)
		{
			newstr.str[i + j] = other.str[j];
		}
		newstr.str[thisLength + otherLength] = '\0';

		return newstr; 
	}

	bool operator ==(const mystring &second)
	{
		if (this->length != second.length) return false;
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i]!= second.str[i]) return false;
		}
		return true;
	}

	bool operator !=(const mystring &second)
	{
		if (this->length != second.length) return true;
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != second.str[i]) return true;
		}
		return false;
	}

	char & operator[](int index) //����������� �������� ���� char �������������� �� ������!
//���� ������ ����������� �� ������������ ����� ���������� ��������� � ���������� ��������� ���� char
	{
		return this->str[index];
	}

	//����������� �����������
	mystring(mystring &&second)
	{
#ifdef DEBUG
		cout << "�������� ����������� ����������� " << this << endl;
#endif // DEBUG
		this->length = second.length;
		this->str = second.str;
		second.str = nullptr;
		
	}


	~mystring()
	{
#ifdef DEBUG
		cout << "�������� ���������� ������ " << this << endl;
#endif // DEBUG

		delete[] this->str;
	}
	
	void print() //����� ������
	{
		cout << this->str << endl;
	}

	int Length()
	{
		return length;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	mystring str1 = "mega";
	mystring str2 = "zorg";

	mystring result;
	result = str1 + str2;
	result.print();
	
	str2[3] = 'G';
	str2.print();



	return 0;
}
