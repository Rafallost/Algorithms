#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

struct Node {

	string Contractor, Authors, name;
	int number, yearOfExodus;
	Node* next;

	Node(int number, string Contractor, string name, int yearOfExodus, string Authors, Node* next = nullptr)
	{
		this->number = number;
		this->Contractor = Contractor;
		this->name = name;
		this->yearOfExodus = yearOfExodus;
		this->Authors = Authors;
		this->next = next;
	}
};

void PushFront(Node*& head, Node* data)
{
	data->next = head;
	head = data;
}

void ShowList(Node*& head)
{
	Node* curr = head;
	while (curr)
	{
		cout << curr->number << ", " << curr->Contractor << ", " << curr->name << ", " << curr->yearOfExodus << "," << curr->Authors << "\n";
		curr = curr->next;
	}
}

Node* ReturnContractors(Node* head)
{
	Node* curr = head;

	vector<pair<string, int>> temp;
	Node* newHead = nullptr;
	while (curr)
	{
		bool unique = true;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i].first == curr->Contractor)
			{
				unique = false;
				temp[i].second++;

				if (temp[i].second == 2)
				{
					Node* newNode = new Node(curr->number, curr->Contractor, curr->name, curr->yearOfExodus, curr->Authors);
					PushFront(newHead, newNode);
				}

				break;
			}
		}

		if (unique)
			temp.push_back(make_pair(curr->Contractor, 1));

		curr = curr->next;

	}
	return newHead;
}

int CountSpaceBars(string name) {

	int temp = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == 32)
			temp++;
	}

	return temp - 1;
}

string GetLastName(string name)
{
	int amount = CountSpaceBars(name);

	stringstream ss(name);
	string temp;

	for (int i = 0; i < amount + 1; i++)
	{
		getline(ss, temp, ' ');
	}
	getline(ss, temp);

	return temp;
}

bool Whether(Node* head, int number)
{
	Node* curr = head;

	while (curr)
	{
		if (curr->number == number)
		{
			stringstream sss(curr->Authors);
			string temp;

			while (getline(sss, temp, ','))
			{
				if ((' ' + curr->Contractor) == temp)
				{
					return true;
				}
			}
		}
		curr = curr->next;
	}
	return false;
}

Node* ReturnTracks(Node* head, int rok)
{
	Node* curr = head;

	Node* newHead = nullptr;

	while (curr)
	{
		if (curr->yearOfExodus == rok)
		{
			Node* newNode = new Node(curr->number, curr->Contractor, curr->name, curr->yearOfExodus, curr->Authors);
			PushFront(newHead, newNode);
		}

		curr = curr->next;
	}

	return newHead;
}


int main()
{

	fstream file("Grupa3.txt", ios::in);

	Node* head = nullptr;

	string line;
	while (getline(file, line))
	{
		string Contractor, Authors, name, tempnumber, tempyearOfExodus;
		int number, yearOfExodus;
		stringstream ss(line);
		getline(ss, tempnumber, ',');
		ss.ignore();
		getline(ss, Contractor, ',');
		ss.ignore();
		getline(ss, name, '1');
		getline(ss, tempyearOfExodus, ',');
		getline(ss, Authors);
		name.pop_back();
		name.pop_back();

		number = stoi(tempnumber);
		yearOfExodus = stoi(tempyearOfExodus);
		yearOfExodus += 1000;

		Node* newNode = new Node(number, Contractor, name, yearOfExodus, Authors);
		PushFront(head, newNode);
	}
	file.close();
	//ShowList(head);
	//3.1
	std::cout << "1:\n\n";
	Node* temp1 = ReturnContractors(head);
	ShowList(temp1);
	//3.2
	std::cout << "\n2:\n\n";
	Node* temp2 = ReturnTracks(head, 1968);
	ShowList(temp2);
	//3.3
	std::cout << "\n3:\n\n";
	cout << Whether(head, 14) << "\n";

	return 0;
}