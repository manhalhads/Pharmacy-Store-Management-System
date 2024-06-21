#include <cstdio>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int count_lines()
{
  int count = 0;
  fstream fin;
  string a;
  fin.open ("Pharmacy.txt",ios::in);
  while (getline(fin,a))
    {
      count++;
    }
    return count;
  
}
int find_medicine(string name)
{
  int line_no = 0;
  string line;
  fstream fin;
  int j = 0;
  fin.open ("Pharmacy.txt",ios::in);
    while(j<count_lines())
      {
        getline(fin,line);
        line_no++;
        int first_comma = line.find(',');
        if (name == line.substr(0,first_comma))
          return line_no;
        j++;
      }
  return -1;
}
int invalid_medicine(string name)
{
  int line_no = find_medicine(name);
  
  if (line_no == -1)
  {
    cout << name << " not found" << endl;
    return line_no;
  }
  return line_no;
}
void updateqty(string data, string qty, int line_no, string arr[])
{
  int total_lines = count_lines();
  int index = data.rfind(",");
  string b = data.substr(0, index+1);
  b = b + " " + qty;

  fstream fout;
  fout.open ("Pharmacy.txt",ios::out);
   for (int i=0;i<line_no-1;i++)
     fout << arr[i] << endl;

  fout << b << endl;

  for (int i =line_no+1;i<total_lines;i++)
     fout << arr[i] << endl;
     fout.close();

  cout << "Quantity updated successfully."<< endl << endl;
}
void updateprice(string data, string price, int line_no, string arr[])
{
  int total_lines = count_lines();
  string qty = data.substr(data.rfind(","));
  string c = data.substr(0,data.rfind(","));
  int index = c.rfind(",");
  string b = c.substr(0, index+1);
  b = b + " " + price + qty;

  fstream fout;
  fout.open ("Pharmacy.txt",ios::out);
   for (int i=0;i<line_no-1;i++)
     fout << arr[i] << endl;

  fout << b << endl;

  for (int i =line_no+1;i<total_lines;i++)
     fout << arr[i] << endl;
     fout.close();

  cout << "Price updated successfully."<< endl << endl;
}
void updatedates(string data, string dates, int line_no, string arr[])
{
   int total_lines = count_lines();
  string newstring = data;
  int j;
      j = newstring.rfind(",");
 string v =  newstring.substr(0,(newstring.substr(0,(newstring.substr(0,(newstring.substr(0,j)).rfind(","))).rfind(",")).rfind (",")+2));
   
  string d = data.substr(j, data.size());
  d = d.substr(d.find(","), d.size());
 
  fstream fout;
  fout.open ("Pharmacy.txt",ios::out);
   for (int i=0;i<line_no-1;i++)
     fout << arr[i] << endl;
  fout << v + dates + d << endl;
  for (int i =line_no+1;i<total_lines;i++)
     fout << arr[i] << endl;
     fout.close();

  cout << "Mfg and Exp dates updated successfully."<< endl << endl;
}
void update(string name, string qty, string price, string mfg, string exp )
{

  if (invalid_medicine(name) == -1)
    return;
  int line_no = find_medicine(name);
  string arr[count_lines()];
  fstream fin;
  string data, a;
  int i = 0;

  fin.open ("Pharmacy.txt",ios::in);
   while (i<count_lines())
     {
       getline(fin,a);
       arr[i] = a;
       i++;
       
       if (i == line_no)
       {
          data = a;
       }
        
     }
  fin.close();

  if (qty!= "-1")
   updateqty(data, qty, line_no, arr);
  else if (price != "-1")
  updateprice(data, price, line_no, arr);
  else
  {
    string dates = mfg + ", " + exp;
    updatedates(data, dates, line_no, arr);
  }
  
  
}
void add_item (string data[])
{
  string new_item = data[0] +", "+ data[1] + ", "+ data[2] + ", "+ data[3]+ ", " + data[4] + ", " + data[5] + ", " + data[6];

  string a;
  string arr[count_lines()];
  int i = 0;
  fstream fin;
  int lines = count_lines();
  fin.open ("Pharmacy.txt",ios::in);
   while (i<lines)
     {
       getline(fin,a);
       arr[i] = a;
       i++;
     }
  fin.close();

  fstream fout;
   fout.open ("Pharmacy.txt",ios::out);
   for (int i=0;i<lines;i++)
     fout << arr[i] << endl;
  
  fout << new_item << endl;
  fout.close();
}
void delete_item (string name)
{
  if (invalid_medicine(name) == -1)
    return;

  int line_no = find_medicine(name);
  int lines = count_lines();
  string arr[lines];
  fstream fin;
  string a;
  int i = 0;

  fin.open ("Pharmacy.txt",ios::in);
   while (getline(fin,a))
     {
       arr[i] = a;
       i++;
     }
  fin.close();
  
  fstream fout;
   fout.open ("Pharmacy.txt",ios::out);
   for (int i=0;i<line_no-1;i++)
     fout << arr[i] << endl;

  for (int i = line_no;i<lines;i++)
    fout << arr[i] << endl;
    
     fout.close();
}
void display_item (string arr[])
{
    int linesize = 0;
   for (int i=0;i<7;i++)
       linesize = linesize + arr[i].length();

    linesize = linesize + 28;

    for (int i=0;i< linesize;i++ )
      cout << "-";
  cout << endl;

  cout << setw(arr[0].size() + 4) << left << "Name";
  cout << setw(arr[1].size() + 2) << left << "Formula";
  cout << setw(arr[2].size() + 4) << left << "Dosage";
  cout << setw(arr[3].size() + 2) << left << "MFG";
  cout << setw(arr[4].size() + 2) << left << "Exp";
  cout << setw(arr[4].size() + 7) << left << "Price";
  cout << setw(arr[4].size() + 2) << left << "Quantity" << endl;

  for (int i=0;i< linesize;i++ )
    cout << "-";
  cout << endl;
  for (int i=0;i< linesize;i++ )
    cout << "-";
cout << endl;
  cout << setw(arr[0].size() + 4) << left << arr[0];
  cout << setw(arr[1].size() + 2) << left << arr[1];
  cout << setw(arr[2].size() + 4) << left << arr[2];
  cout << setw(arr[3].size() + 2) << left << arr[3];
  cout << setw(arr[4].size() + 2) << left << arr[4];
  cout << setw(arr[4].size() + 7) << left << arr[5];
  cout << setw(arr[4].size() + 2) << left << arr[6] << endl;


    for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;


}
void display_price (string arr[])
{
  int linesize = arr[0].size() + arr[5].size() + 6;
  for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;
  cout << setw(arr[0].size() + 4) << left << "Name";
  cout << setw(arr[5].size() + 6) << left << "Price" << endl;
  for (int i=0;i< linesize;i++ )
      cout << "-";
    cout << endl;
  for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;
  cout << setw(arr[0].size() + 4) << left << arr[0];
  cout << setw(arr[5].size() + 6) << left << arr[5] << endl;
  
  for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;
  cout << endl;
}
void display_quantity (string arr[])
{
  int linesize = arr[0].size() + arr[6].size() + 7;
  for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;
  cout << setw(arr[0].size() + 4) << left << "Name";
  cout << setw(arr[1].size() + 7) << left << "Quantity"<< endl;
  for (int i=0;i< linesize;i++)
    cout << "-";
  cout << endl;
  for (int i=0;i< linesize;i++)
    cout << "-";
  cout << endl;
  cout << setw(arr[0].size() + 4) << left << arr[0];
  cout << setw(arr[5].size() + 7) << left << arr[6] << endl;
  for (int i=0;i< linesize;i++ )
      cout << "-";
   cout << endl;
  cout << endl;
}
void search (string name, bool item, bool price, bool quantity)
{
  if (invalid_medicine(name) == -1)
    return;

  int line_no = find_medicine(name);
  fstream fin;
  string a;
  int i = 0;

  fin.open ("Pharmacy.txt",ios::in);
   while (i<line_no)
     {
       getline(fin,a);
       i++;
     }
  fin.close();

  
  string data[7];
  int j = 0;
  int starting_point = 0;

  while (j<7)
    {
      int index = a.find(",");
      if (index == -1)
      {
        index = a.find("\n");
      }
      int length = index - starting_point;
      data[j] = a.substr(starting_point,length);
      a = a.substr(index+2);
      j++;
    }
  
  if (item == true)
    display_item (data);
  else if (price == true)
    display_price(data);
  else
    display_quantity(data);
}
int menu()
{
  int option;
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
  cin >> option;
  return option;
}
void del ()
  {
   string n;
   cout << "Enter name of item to be deleted:\n";
   getline (cin, n);
   delete_item (n);
   cout << "Item deleted successfully."<< endl;
  }
void add()
{
  string item[7];
   cout << "Enter name of item to be added:\n";
   getline (cin, item[0]);
  cout << "Enter formula of item to be added:\n";
   getline (cin, item[1]);
  cout << "Enter dosage of item to be added:\n";
   getline (cin, item[2]);
  cout << "Enter mfg date of item to be added:\n";
   getline (cin, item[3]);
  cout << "Enter exp date of item to be added:\n";
   getline (cin, item[4]);
  cout << "Enter price of item to be added:\n";
   getline (cin, item[5]);
  cout << "Enter quantity of item to be added:\n";
   getline (cin, item[5]);
  add_item (item);
  cout << "Item added successfully."<< endl;
}
void search_i()
{
  string name;
  cout << "Enter the name of item to search: \n";
  getline(cin, name);
  search(name, true, false, false);
  cout << endl;
}
void search_p()
{
  string name;
  cout << "Enter the name of item to search price of: ";
  getline(cin, name);
  search(name, false, true, false);
  cout << endl;
}
void search_qty()
{
  string name;
  cout << "Enter the name of item to search quantity of: ";
  getline(cin, name);
  search(name, false, false, true);
  cout << endl;
}
void update_p()
{
  string name, price;
  string na = "-1";
  cout << "Enter the name of item to update price of: ";
  getline(cin, name);
  cout << "Enter the new price of " << name << endl;
  getline(cin, price);
  update(name, na, price, na, na);
  cout << endl;
}
void update_q()
{
  string name, qty;
  string na = "-1";
  cout << "Enter the name of item to update quantity of: ";
  getline(cin, name);
  cout << "Enter the new quantity of " << name << endl;
  getline(cin, qty);
  update(name,  qty , na, na, na);
}
void update_dates()
{
  string name, mfg, exp;
  string na = "-1";
  cout << "Enter the name of item to update quantity of: ";
  getline(cin, name);
  cout << "Enter manufacturing date of " << name << endl;
  getline(cin, mfg);
  cout << "Enter expiry date of " << name << endl;
  getline(cin, mfg);
  update(name,  na , na, mfg, exp);
}
int main() {
int option = 5;
   while (option!= 0)
    {
      option = menu ();
      cin.get();
      if (option == 1)
      {
        search_i();
      }         
      else if (option == 2)
      {
        //cout << "hi"<< endl;
        search_p();
      }
      else if (option == 3)
      {
        search_qty();
      }
      else if (option == 4)
      {
        update_p();
      }
      else if (option == 5)
      {
        update_q();
      }
      else if (option == 6)
      {
        update_dates();
      }
      else if (option == 7)
      {
        add();
      }   
      else if (option == 8)
      {
        del();
      }
      else
      {
        cout << "Inalid option. Try again." << endl;
      }
    }
  

return 0;
}
