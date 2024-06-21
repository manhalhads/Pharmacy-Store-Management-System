#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void search() {
  string name;
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;
  string a;
  ifstream fin;
  fin.open("Pharmacy.txt");

  cout << "Enter the name of the item to search." << endl;
  getline(cin, name);

  while (fin.peek() != EOF) {
    getline(fin, a);
    if (name == a)

    {
      name = a;
      getline(fin, a);
      formula = a;
      fin >> a;
      dosage = a;
      fin.get();
      getline(fin, a);
      dosage_unit = a;
      fin >> a;
      mfg_month = a;
      fin.get();
      getline(fin, a);
      mfg_year = a;
      fin >> a;
      exp_month = a;
      fin.get();
      getline(fin, a);
      exp_year = a;
      getline(fin, a);
      price = a;
      getline(fin, a);
      quantity = a;
      fin.get();
      cout << "--------------------------- " << endl;
      cout << " Name: " << name << endl;
      cout << " Formula: " << formula << endl;
      cout << " Dosage: " << dosage + " " + dosage_unit << endl;
      cout << " Mfg date: " << mfg_month + "/" + mfg_year << endl;
      cout << " Exp date: " << exp_month + "/" + exp_year << endl;
      cout << " Price(per tablet/per bottle): " << price << endl;
      cout << " Quantity: " << quantity;
      cout << endl;
      cout << "---------------------------- " << endl;
      return;
    }
  }
}
int count_lines() {
  string a;
  int count = 0;
  ifstream fin("Pharmacy.txt");
  while (fin.peek() != EOF) {
    getline(fin, a);
    count++;
  }

  return count;
}
void searchprice() {
  string name;
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;
  string a;
  ifstream fin;
  fin.open("Pharmacy.txt");

  cout << "Enter the name of the item to search price." << endl;

  getline(cin, name);

  while (fin.peek() != EOF) {
    getline(fin, a);
    if (name == a) {
      name = a;
      getline(fin, a);
      formula = a;
      fin >> a;
      dosage = a;
      fin.get();
      getline(fin, a);
      dosage_unit = a;
      fin >> a;
      mfg_month = a;
      fin.get();
      getline(fin, a);
      mfg_year = a;
      fin >> a;
      exp_month = a;
      fin.get();
      getline(fin, a);
      exp_year = a;
      getline(fin, a);
      price = a;
      getline(fin, a);
      quantity = a;
      fin.get();
      cout << "Price(per tablet/per bottle): " << price << endl;
    }
  }
}
void display() {
  ifstream fin;
  fin.open("Pharmacy.txt");

  string name;
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;
  string a;
  string line;
  int count = 0;

  for (int i = 0; i < 399; i++) {

    getline(fin, a);
    name = a;
    getline(fin, a);
    formula = a;
    fin >> a;
    dosage = a;
    fin.get();
    getline(fin, a);
    dosage_unit = a;
    fin >> a;
    mfg_month = a;
    fin.get();
    getline(fin, a);
    mfg_year = a;
    fin >> a;
    exp_month = a;
    fin.get();
    getline(fin, a);
    exp_year = a;
    getline(fin, a);
    price = a;
    getline(fin, a);
    quantity = a;
    fin.get();
    cout << "--------------------------- " << endl;
    cout << " Name: " << name << endl;
    cout << " Formula: " << formula << endl;
    cout << " Dosage: " << dosage + " " + dosage_unit << endl;
    cout << " Mfg date: " << mfg_month + "/" + mfg_year << endl;
    cout << " Exp date: " << exp_month + "/" + exp_year << endl;
    cout << " Price(per tablet/per bottle): " << price << endl;
    cout << " Quantity: " << quantity;
    cout << endl;
    cout << "---------------------------- " << endl;
  }
  fin.close();
}

void searchquantity() {
  string name;
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;
  string a;
  ifstream fin;
  fin.open("Pharmacy.txt");

  cout << "Enter the name of the item to search quantity." << endl;
  getline(cin, name);

  while (fin.peek() != EOF) {
    getline(fin, a);
    if (name == a) {
      name = a;
      getline(fin, a);
      formula = a;
      fin >> a;
      dosage = a;
      fin.get();
      getline(fin, a);
      dosage_unit = a;
      fin >> a;
      mfg_month = a;
      fin.get();
      getline(fin, a);
      mfg_year = a;
      fin >> a;
      exp_month = a;
      fin.get();
      getline(fin, a);
      exp_year = a;
      getline(fin, a);
      price = a;
      getline(fin, a);
      quantity = a;
      fin.get();
      cout << "Remaining quantity: " << quantity << endl;
    }
  }
}

void updateprice() {
  ifstream fin("Pharmacy.txt");
  vector<string> file;
  int start;
  string a;
  string name;
  string price;
  int count = 0;
  cout << "Enter the name of item whose price you want to update." << endl;
  getline(cin, name);
  cout << "Enter new price." << endl;
  cin >> price;
  while (fin.peek() != EOF) {
    getline(fin, a);
    count++;
    file.push_back(a);
    if (a == name) {
      start = count;
    }
  }
  fin.close();

  ofstream out;
  out.open("Pharmacy.txt");

  for (int i = 0; i < (start + 4); i++) {
    out << file[i] << endl;
  }
  out << price << endl;
  for (int i = (start + 5); i < 400; i++)
    out << file[i] << endl;
  out.close();
  cout << "The price of " << name << " has been updated successfully." << endl;
}

void updatequantity() {
  ifstream fin("Pharmacy.txt");
  vector<string> file;
  int start;
  string a;
  string name;
  string quantity;
  int count = 0;
  cout << "Enter the name of item whose quantity you want to update." << endl;
  getline(cin, name);
  cout << "Enter new quantity." << endl;
  getline(cin, quantity);
  while (fin.peek() != EOF) {
    getline(fin, a);
    count++;
    file.push_back(a);
    if (a == name) {
      start = count;
    }
  }
  fin.close();
  ofstream out;
  out.open("Pharmacy.txt");

  for (int i = 0; i < (start + 5); i++) {
    out << file[i] << endl;
  }
  out << quantity << endl;
  for (int i = (start + 6); i < 400; i++)
    out << file[i] << endl;
  out.close();
  cout << "The quantity of " << name << " has been updated successfully. "
       << endl;
}

void updatedates() {
  ifstream fin("Pharmacy.txt");
  vector<string> file;
  int start;
  string a;
  string name;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  int count = 0;
  cout << "Enter the name of item whose manufacturing or expiry dates you want "
          "to update."
       << endl;
  getline(cin, name);
  cout << "Enter the month this item was manufactured in(1 to 12)." << endl;
  getline(cin, mfg_month);
  cout << "Enter the year this item was manufactured in." << endl;
  getline(cin, mfg_year);
  cout << "Enter the month this item expires in(1 to 12)." << endl;
  getline(cin, exp_month);
  cout << "Enter the year this item expires in." << endl;
  getline(cin, exp_year);
  while (fin.peek() != EOF) {
    getline(fin, a);
    count++;
    file.push_back(a);
    if (a == name) {
      start = count;
    }
  }
  fin.close();
  ofstream out;
  out.open("Pharmacy.txt");

  for (int i = 0; i < (start + 2); i++) {
    out << file[i] << endl;
  }
  out << mfg_month << " " << mfg_year << endl;
  out << exp_month << " " << exp_year << endl;

  for (int i = (start + 4); i < 400; i++)
    out << file[i] << endl;
  out.close();
  cout << "The manufacturing and expiry dates of " << name
       << " have been updated successfully. " << endl;
}
void deleteitem() {
  ifstream fin("Pharmacy.txt");

  vector<string> v;
  int start;
  string a;
  string name;
  int count = 0;
  cout << "Enter the name of the item to be delated." << endl;
  getline(cin, name);
  while (fin.peek() != EOF) {
    getline(fin, a);
    count++;
    v.push_back(a);
    if (a == name) {
      start = count;
    }
  }
  fin.close();
  ofstream out;
  out.open("Pharmacy.txt");

  for (int i = 0; i < start - 1; i++) {
    out << v[i] << endl;
  }

  for (int i = (start + 7); i < 399; i++)
    out << v[i] << endl;
  out.close();
  cout << name << " has been deleted successfully. " << endl;
}

void Insertnewitem() {
  string name;
  string formula;
  string dosage;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;

  ofstream out;
  out.open("Pharmacy.txt", ios::app);

  cout << "Enter the name of the item." << endl;
  getline(cin, name);
  cout << "Enter the formula of the item." << endl;
  getline(cin, formula);
  cout << "Enter the dosage of the item." << endl;
  getline(cin, dosage);
  cout << "Manufacturing date." << endl;
  cout << "Enter the month (1 to 12) the item was manufactured in." << endl;
  getline(cin, mfg_month);
  cout << "Enter the year the item was manufactured in." << endl;
  getline(cin, mfg_year);
  cout << "Expiry date." << endl;
  cout << "Enter the month (1 to 12) the item expires in." << endl;
  getline(cin, exp_month);
  cout << "Enter the year the item expires in." << endl;
  getline(cin, exp_year);
  cout << "Enter the price of the item." << endl;
  getline(cin, price);
  cout << "Enter the quantity of the item." << endl;
  getline(cin, quantity);

  out << endl;
  out << endl;
  out << name << endl;
  out << formula << endl;
  out << dosage << endl;
  out << mfg_month + " " + mfg_year << endl;
  out << exp_month + " " + exp_year << endl;
  out << price << endl;
  out << quantity;
  out.close();
  cout << "New item has successfully been added." << endl;
}

void bills() {
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string qty;
  string a;
  ifstream fin;
  fin.open("Pharmacy.txt");
  ofstream out;
  out.open("Receipt.txt");

  char option = 'o';
  string name;
  string quantity;
  for (int i = 1; i < 2; i++) {
    cout << "Enter the name of item purchased." << endl;
    cin >> name;
    cout << "Enter the quantity of item purchased." << endl;
    cin >> qty;

    for (i = 0; i < 399; i++) {

      getline(fin, a);

      if (name == a) {
        name = a;
        getline(fin, a);
        formula = a;
        fin >> a;
        dosage = a;
        fin.get();
        getline(fin, a);
        dosage_unit = a;
        fin >> a;
        mfg_month = a;
        fin.get();
        getline(fin, a);
        mfg_year = a;
        fin >> a;
        exp_month = a;
        fin.get();
        getline(fin, a);
        exp_year = a;
        getline(fin, a);
        price = a;
        getline(fin, a);
        quantity = a;
        fin.get();

        int q = stoi(qty);
        float p = stof(price);
        out << "Invoice" << endl;
        out << "Item name"
            << "     "
            << "Quantity"
            << "     "
            << "Unit Price"
            << "     "
            << "Total price" << endl;
        out << name << " \t    " << q << "             \t  " << p
            << "  \t         " << p * q << endl;
        cout << "Your bill has been made in a file by the name of 'Receipt'."
             << endl;

      } else {
        continue;
      }
    }
  }
}

int main() {
  ifstream fin;
  fin.open("Pharmacy.txt");

  string name;
  string formula;
  string dosage;
  string dosage_unit;
  string mfg_month;
  string mfg_year;
  string exp_month;
  string exp_year;
  string price;
  string quantity;
  char option;

  cout << "PHARMACY MAIN MENU" << endl;
  cout << "Press [1] to search an item." << endl;
  cout << "Press [2] to search price of an item." << endl;
  cout << "Press [3] to search remaining quantity of an item." << endl;
  cout << "Press [4] to update price." << endl;
  cout << "Press [5] to update quantity of an item." << endl;
  cout << "Press [6] to update mfg and exp dates." << endl;
  cout << "Press [7] to add new item." << endl;
  cout << "Press [8] to delete an item." << endl;
  cout << "Press [9] to generate bills." << endl;

  option = cin.get();
  cin.get();

  switch (option) {
  case '1':
    search();
    break;

  case '2':

    searchprice();

    break;
  case '3':
    searchquantity();
    break;

  case '4':
    updateprice();
    break;
  case '5':

    updatequantity();

    break;
  case '6':
    updatedates();
    break;

  case '7':
    Insertnewitem();
    break;
  case '8':

    deleteitem();
    break;
  case '9':
    bills();
    break;

  default:
    break;
  }

  return 0;
}
