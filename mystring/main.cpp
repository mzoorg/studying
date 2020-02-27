#include <iostream>
//#include <string>
#define DEBUG
using namespace std;

class mystring
{

	char *str; // îïðåäåëåíèå êîíñòàíòíîãî óêàçàòåëÿ òèïà char. (èíêàïñóëèðóåì â private)
	int length;
	
public:
	mystring()
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ êîíñòðóêòîð êëàññà ïî óìîë÷àíèþ" << this << endl;
#endif // DEBUG
		str = nullptr;
		length = 0;
	}

	mystring(const char *word) //êîíñòðóêòîð. êîíñòàí
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ êîíñòðóêòîð êëàññà " << this << endl;
#endif // DEBUG
		
		length = strlen(word);
		this->str = new char [length+1]; //âûäåëåíèå äèíàìè÷åñêîé ïàìÿòè ïîä êîë-âî ñèìîâîëîâ ñëîâà + 1 ñèìâîë äëÿ òåðìèíèðóþùåãî 0
		for (int i = 0; i < length; i++)
		{
			this->str[i] = word[i]; //êîïèðîâàíèå âñåõ ñèìâîëîâ ìàññèâà word âêëþ÷àÿ /0 èäóùèé 4ì ýëåìåíòîì
		}
		this->str[length] = '\0';
			   	
	}
	
	// ïåðåãðóæåííûé îïåðàòîð ïðèñâàèâàíèÿ
	mystring & operator = (const mystring &word) //âîçâðàùàåò ññûëêó íà òèï íàøåãî êëàññà
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ îïåðàòîð ïðèñâàèâàíèÿ = " << this << endl;
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
		return *this; // ðàçûìåíîâûâàåì óêàçàòåëü íà îáúåêò (str1) ò.î ïîëó÷àåì àäðåñ õðàíÿùåéñÿ â óêàçàòåëå this èëè ïðÿìóþ ññûëêó íà str1.
	}
		
	//êîíñòðóêòîð êîïèðîâàíèÿ
	mystring(const mystring &word) 
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ êîíñòðóêòîð êîïèðîâàíèÿ" << this << endl;
#endif // DEBUG

		length = strlen(word.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = word.str[i];
		}
		this->str[length] = '\0';
	}

	//ïåðåãðóæåííûé îïåðàòîð ñëîæåíèÿ. íåîáõîäèì äëÿ êîíêàòåíàöèè ñòðîê êëàññà string
	mystring operator + (const mystring &other)
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ îïåðàòîð + " << this << endl;
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

	char & operator[](int index) //âîçâðàùåíèå çíà÷åíèÿ òèïà char îñóùåñòâëÿåòñÿ ïî ññûëêå!
//åñëè ññûëêà îòñòóòñâóåò òî âîçâðàùàåòñÿ íîâàÿ ïåðåìåííàÿ ñîçäàííàÿ â ïåðåãðóçêå îïåðàòîðà òèïà char
	{
		return this->str[index];
	}

	//êîíñòðóêòîð ïåðåìåùåíèÿ
	mystring(mystring &&second)
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ êîíñòðóêòîð ïåðåìåùåíèÿ " << this << endl;
#endif // DEBUG
		this->length = second.length;
		this->str = second.str;
		second.str = nullptr;
		
	}


	~mystring()
	{
#ifdef DEBUG
		cout << "Âûçâàëñÿ äåñòðóêòîð êëàññà " << this << endl;
#endif // DEBUG

		delete[] this->str;
	}
	
	void print() //ìåòîä âûâîäà
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
