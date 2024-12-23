#include <iostream>
#include<math.h>
#include <vector>

using namespace std;

class Student
{
private:
	int rollno;
	string name;
public:
	Student(int rollno, const string& name) : rollno(rollno), name(name) {}
	~Student() {}

	void studentInfo()
	{
		cout << "Rollno: " << rollno << " Name: " << name << endl;
	}
};
class Result : public Student
{
public:
	int marks1;
	int marks2;
	int marks3;

	Result(int rollno, const string& name, int marks1, int marks2, int marks3):
		Student(rollno, name),marks1(marks1), marks2(marks2), marks3(marks3) {}
	~Result() {}

	void calcResult()
	{
		cout << "Total marks: " << (marks1 + marks2 + marks3) << endl;
		cout << "Percentage: " << (marks1 + marks2 + marks3) / 3 << endl;
	}

};

class Shape
{
public:
	virtual double area() = 0;
};
class Circle : Shape
{
public:
	int radius;
	Circle(int radius) :radius(radius) {};
	double area() override
	{
		return 3.14 * radius * radius;
	}
};
class Rectangle : Shape
{
public:
	int length, breadth;
	Rectangle(int length, int breadth) : length(length), breadth(breadth) {};
	double area() override
	{
		return length * breadth;
	}
};
class Triangle : Shape
{
public:
	int base, height;
	Triangle(int base, int height) :base(base), height(height) {};
	double area () override
	{
		return 0.5 * base * height;
	}
};

int naturalSum(int n)
{
	return (n * (n + 1)) / 2;
}

int numberLength(int n)
{
	int digCount = 0;
	while (n != 0)
	{
		n /= 10;
		digCount++;
	}
	return digCount;
}

int area(int radius)
{
	return 3.14 * radius * radius;
}

int area(int length, int breadth)
{
	return length * breadth;
}

double area(int a, int b, int c)
{
	int s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void table(int n) 
{
	for (int i = 1; i <= 10; i++)
	{
		cout << n << " x " << i << " = " << n * i << endl;
	}
}

int reversedNum(int n)
{
	int revNum = 0;
	while (n != 0) {
		int dig = n % 10;
		revNum = revNum * 10 + dig;
		n /= 10;
	}
	return revNum;
}

int calcSalary(int basicStipend)
{
	return basicStipend;
}
int calcSalary(int basicStipend, int bonuses)
{
	return basicStipend + bonuses;
}
int calcSalary(int basicStipend, int bonuses, int performanceBonuses)
{
	return basicStipend + bonuses + performanceBonuses;
}

void addAndPrintMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
	if (mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size()) {
		cerr << "Error: Matrix dimensions must match for addition." << endl;
		return;
	}

	int rows = mat1.size();
	int cols = mat1[0].size();

	cout << "Resultant Matrix:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << mat1[i][j] + mat2[i][j] << " ";
		}
		cout << endl;
	}
}

class Account {
protected:
	int balance;
public:
	Account(int bal) : balance(bal) {}
	virtual void calculateInterest() const = 0;
	virtual ~Account() {}
};

class SavingsAccount : public Account {
	double rate;
	int time;
public:
	SavingsAccount(int bal, double r, int t) : Account(bal), rate(r), time(t) {}
	void calculateInterest() const override {
		double interest = balance * (rate / 100) * time;
		cout << fixed;
		cout << "Savings Account Interest: " << interest << endl;
	}
};

class CurrentAccount : public Account {
	int maintenanceFee;
public:
	CurrentAccount(int bal, int fee) : Account(bal), maintenanceFee(fee) {}
	void calculateInterest() const override {
		cout << "Current Account Maintenance Fee Deducted: " << maintenanceFee << endl;
		cout << "Final Balance after Fee Deduction: " << (balance - maintenanceFee) << endl;
	}
};

void handleAccount() {
	int accountType;
	cout << "Enter Account Type (1 for Savings, 2 for Current): ";
	cin >> accountType;

	int balance;
	cout << "Enter Account Balance: ";
	cin >> balance;

	if (accountType == 1) {
		double rate;
		int time;
		cout << "Enter Interest Rate (as percentage): ";
		cin >> rate;
		cout << "Enter Time (in years): ";
		cin >> time;

		if (balance < 1000 || balance > 1000000 || rate < 1 || rate > 15 || time < 1 || time > 10) {
			cout << "Invalid input values." << endl;
			return;
		}

		SavingsAccount sa(balance, rate, time);
		sa.calculateInterest();
	}
	else if (accountType == 2) {
		int fee;
		cout << "Enter Monthly Maintenance Fee: ";
		cin >> fee;

		if (balance < 1000 || balance > 1000000 || fee < 50 || fee > 500) {
			cout << "Invalid input values." << endl;
			return;
		}

		CurrentAccount ca(balance, fee);
		ca.calculateInterest();
	}
	else {
		cout << "Invalid account type." << endl;
	}
}



int main()
{
	//1st
	int n;
	cout << "Sum of numbers upto: ";
	cin >> n;

	cout << "\nSum: " << naturalSum(n);
	n = 0;

	//2nd
	cout << "\nEnter number to find length: ";
	cin >> n;

	cout << "\nLength: " << numberLength(n);

	//3rd
	cout << "\nEnter radius: ";
	cin >> n;
	cout << "\n" << area(n) << endl;

	int length, breadth;
	cout << "Enter length and breadth: ";
	cin >> length >> breadth;

	cout << "\n"<< area(length, breadth) << endl;

	int a, b, c;
	cout << "Enter sides of triangle: ";
	cin >> a >> b >> c;

	cout << "\n" << area(a, b, c)<<endl;

	//4th
	cout << "Enter the number of which you want the table of: ";
	cin >> n;
	table(n);


	//5th
	cout << "Enter the number you want to reverse: ";
	cin >> n;
	cout<<reversedNum(n);

	//6th
	cout << "Salary of intern: " << calcSalary(5000)<<endl;
	cout << "Salary of Employee: " << calcSalary(5000, 2000)<<endl;
	cout << "Salary of Manager: " << calcSalary(5000, 2000, 8000)<<endl;

	//7th
	int rollno, marks1, marks2, marks3;
	string name;
	cout << "Enter rollno and name: ";
	cin >> rollno >> name;
	cout << "Enter marks: ";
	cin >> marks1 >> marks2 >> marks3;
	Result r(rollno, name, marks1, marks2, marks3);
	cout << endl;
	r.studentInfo();
	r.calcResult();

	//8th
	int rad, len, brd, base, height;

	cout << "Enter radius: ";
	cin >> rad;

	Circle cir(rad);
	cout << cir.area() << endl;

	cout << "Enter length and breadth: ";
	cin >> len >> brd;

	Rectangle rec(len, brd);
	cout << rec.area() << endl;

	cout << "Enter base and height: ";
	cin >> base >> height;

	Triangle t(base, height);

	cout << t.area() << endl;

	//9th
	vector<vector<int>> mat1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	vector<vector<int>> mat2 = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

	addAndPrintMatrices(mat1, mat2);
	
	//10th
	handleAccount();

	return 0;
}


